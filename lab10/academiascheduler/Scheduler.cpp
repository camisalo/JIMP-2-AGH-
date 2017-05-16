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




        for (auto &courses_year : courses_of_year){
            year = courses_year.first;
            for (auto course : courses_year.second){
                course_id = course;
                teacher_id = GetTeacher(teacher_courses_assignment,course);

                bool ok, error = true;

                const Schedule &teacher = new_schedule.OfTeacher(teacher_id);
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


    int GreedyScheduler::GetTeacher(const std::map<int, std::vector<int>> teacher_courses_assignment, int course) const {
        for (auto teacher : teacher_courses_assignment){
            for (auto search_course : teacher.second){
                if (search_course == course)
                    return teacher.first;
            }
        }
        throw NoViableSolutionFound();
    }

}