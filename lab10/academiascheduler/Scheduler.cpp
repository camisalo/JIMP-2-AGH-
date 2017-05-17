//
// Created by konrad on 13.05.17.
//

#include "Scheduler.h"

namespace academia{

    Schedule Schedule::OfTeacher(int teacher_id) const{
        std::vector<SchedulingItem> teacher_classes;
        for (const auto &current_item : schedule_item) {
            if (current_item.TeacherId() == teacher_id) {
                teacher_classes.emplace_back(current_item);
            }
        }
        return Schedule(teacher_classes);
    }

    Schedule Schedule::OfRoom(int room_id) const {
        std::vector<SchedulingItem> room_classes;
        for (const auto &current_item : schedule_item) {
            if (current_item.RoomId() == room_id) {
                room_classes.emplace_back(current_item);
            }
        }
        return Schedule(room_classes);
    }

    Schedule Schedule::OfYear(int year_id) const {
        std::vector<SchedulingItem> year_classes;
        for (const auto &current_item : schedule_item) {
            if (current_item.Year() == year_id) {
                year_classes.emplace_back(current_item);
            }
        }
        return Schedule(year_classes);
    }


    std::vector<int> Schedule::AvailableTimeSlots(int time) const {
        std::vector<int> avaliable; bool ok;
        for (int i=1;i<=time;i++) {
            ok = true;
            for (auto current_item:schedule_item) {
                if (current_item.TimeSlot() == i)
                    ok = false;
            }
            if (ok)
                avaliable.emplace_back(i);
        }
        return avaliable;
    }




    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        std::map<int, std::set<int>> avaiable_rooms_int_time;
        //  connect rooms with time slots
        std::set<int> avaiable_slots;   FillTimeSlots(avaiable_rooms_int_time, rooms, n_time_slots);

        Schedule new_schedule;
        int course_id, teacher_id, room_id, time_id, year;
        int ile;




        for (auto &teacher : teacher_courses_assignment){
            teacher_id = teacher.first;
            for (auto course_teacher : teacher.second){
                course_id = course_teacher;


                const Schedule &teacher = new_schedule.OfTeacher(teacher_id);
                ile = 0;
                for (int i=0;i<teacher.Size();++i){
                    if (course_id == teacher[i].CourseId()){
                        ile++;
                    }
                }

                year = GetYear(courses_of_year, course_id, ile);

                bool ok, error = true;


                for (auto room : rooms){

                    for (auto avaiable_time : new_schedule.OfRoom(room).AvailableTimeSlots(n_time_slots)){
                        ok = true;
                        for (int i=0;i<teacher.Size();++i){
                            if (teacher[i].TimeSlot() == avaiable_time){
                                ok = false;
                            }
                        }
                        if (ok && error){
                            time_id = avaiable_time;
                            room_id = room;
                            error = false;
                        }
                    }
                }
                if (error) {
                    throw NoViableSolutionFound();
                }


                new_schedule.InsertScheduleItem({course_id,teacher_id,room_id,time_id,year});
            }
        }
        for (auto checked_year : courses_of_year) {
            for (int i = 0; i < new_schedule.OfYear(checked_year.first).Size(); ++i) {
                for (int j = 0; j < new_schedule.OfYear(checked_year.first).Size(); ++j) {
                    if (i != j && new_schedule.OfYear(checked_year.first)[i].RoomId() !=
                                  new_schedule.OfYear(checked_year.first)[j].RoomId() &&
                        new_schedule.OfYear(checked_year.first)[i].TimeSlot() ==
                        new_schedule.OfYear(checked_year.first)[j].TimeSlot()) {
                        throw NoViableSolutionFound();
                    }
                }
            }
        }

        return new_schedule;
    }




    void GreedyScheduler::FillTimeSlots(std::map<int,std::set<int>> &avaiable_rooms_in_time,
                       const std::vector<int> &rooms,int n_time_slots) const {
        std::set<int> time;
        for (int i=1;i<=n_time_slots;++i) {time.emplace(i);}

        for (auto v:rooms){
            avaiable_rooms_in_time.emplace(v,time);
        }
    }


    int GreedyScheduler::GetYear(const std::map<int, std::set<int>> &courses_of_year, int course, int ile) const {
        int count = 0;
        for (auto year : courses_of_year){
            for (auto course_on_year : year.second){
                if (course_on_year == course){
                    return year.first;
                }
            }
        }
        throw NoViableSolutionFound();
    }

}