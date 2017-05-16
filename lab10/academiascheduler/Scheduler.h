//
// Created by konrad on 13.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <list>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <iostream>



namespace academia {


    class SchedulingItem {
    public:
        SchedulingItem(int course, int teacher, int room, int time, int year):
                course_id_{course}, teacher_id_{teacher}, room_id_{room},
                time_id_{time}, year_{year}   {    }

        int CourseId() const { return  course_id_;}
        int TeacherId() const { return teacher_id_;}
        int RoomId() const { return room_id_;}
        int TimeSlot() const { return time_id_;}
        int Year() const { return year_;}

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_id_;
        int year_;
    };


    class Schedule {
    public:
        Schedule() {}

        Schedule(std::vector<SchedulingItem> init) : schedule_item{init}{}

        void InsertScheduleItem(const SchedulingItem &k) {schedule_item.emplace_back(k);}
        Schedule OfTeacher(int teacherid) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year_id) const;
        std::vector<int> AvailableTimeSlots(int time) const;
        size_t Size() const {return schedule_item.size();}

        SchedulingItem operator[](const int &number) const { return schedule_item[number]; }

    private:
        std::vector<SchedulingItem> schedule_item;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) = 0;
    };

    class GreedyScheduler : public Scheduler {
    public:
        GreedyScheduler() {}

        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) override;

        void FillTimeSlots(std::map<int,std::set<int>> &avaiable_rooms_in_time,
                           const std::vector<int> &rooms,int n_time_slots) const;


        int GetTeacher(const std::map<int, std::vector<int>> teacher_courses_assignment, int course) const;

    };

    class NoViableSolutionFound {
    public:
        NoViableSolutionFound() {}
    };
}
#endif //JIMP_EXERCISES_SCHEDULER_H
