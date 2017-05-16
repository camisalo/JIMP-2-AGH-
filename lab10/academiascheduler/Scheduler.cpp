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


    std::vector<int> Schedule::AvailableTimeSlots(int room) const {
        std::vector<int> avaliable; bool ok;
        for (int i=1;i<=room;i++) {
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
        CreateBusyTeacher(teacher_courses_assignment,n_time_slots);

        Schedule new_schedule;
        int course_id, teacher_id, room_id, time_id, year;

        for (auto &courses_year : courses_of_year){
            year = courses_year.first;
            for (auto course : courses_year.second){
                course_id = course;
                teacher_id = GetTeacher(teacher_courses_assignment, course);
                std::pair<int,int> room_time = FindRoomAndTimeSlot(avaiable_rooms_int_time, teacher_id);




                if (avaiable_slots.empty())
                    throw NoViableSolutionFound();




                new_schedule.InsertScheduleItem ({course_id,teacher_id,room_id,time_id,year});
            }






        }


        return Schedule();
    }




    void GreedyScheduler::FillTimeSlots(std::map<int,std::set<int>> &avaiable_rooms_in_time,
                       const std::vector<int> &rooms,int n_time_slots) const {
        std::set<int> time;
        for (int i=1;i<=n_time_slots;++i) {time.emplace(i);}

        for (auto v:rooms){
            avaiable_rooms_in_time.emplace(v,time);
        }
    }

    void GreedyScheduler::CreateBusyTeacher(const std::map<int, std::vector<int>> teacher_courses_assignment,int n_time_slots){
        std::vector<bool> v_bool; std::fill_n(v_bool.begin(),n_time_slots,true);
        for (auto teacher : teacher_courses_assignment) {
            busy_teacher.emplace(teacher.first, v_bool);
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

    std::pair<int,int> GreedyScheduler::FindRoomAndTimeSlot( std::map<int, std::set<int>> avaiable_rooms_int_time,
                                            int teacher_id) const{
        int found_time, found_room;
        for (auto room : avaiable_rooms_int_time){
            for (auto time : room.second){
                if (CheckIsTeacherFree(teacher_id,time)) {

                }
                room.second.erase(time);
            }
        }
        return std::make_pair(found_room, found_time) ;
    };

    bool GreedyScheduler::CheckIsTeacherFree(int teacher_id, int time){
        busy_teacher.find(teacher_id);
    }


}