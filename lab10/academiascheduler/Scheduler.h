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

namespace academia {


    class SchedulingItem {
    public:
        SchedulingItem(int course, int teacher, int room, int time, int year):
                course_id_{course}, teacher_id_{teacher}, room_id_{room},
                time_id_{time}, year_{year}   {    }



        unsigned long CourseId() const { return  course_id_;}
        unsigned long TeacherId() const { return teacher_id_;}
        unsigned long RoomId() const { return room_id_;}
        unsigned long TimeSlot() const { return time_id_;}
        unsigned long Year() const { return year_;}

    private:
        unsigned long course_id_;
        unsigned long teacher_id_;
        unsigned long room_id_;
        unsigned long time_id_;
        unsigned long year_;
    };


    class Schedule {
    public:
        Schedule() {}

        Schedule(std::vector<SchedulingItem> init) : schedule_item{init}{}

        void InsertScheduleItem(SchedulingItem k) {schedule_item.emplace_back(k);}

        Schedule OfTeacher(int teacherid) const;

        Schedule OfRoom(int room) const;

        Schedule OfYear(int room) const;

        std::vector<int> AvailableTimeSlots(int room);

        size_t Size() const {return schedule_item.size();}


        SchedulingItem operator[](const int &number) const {
            return schedule_item[number];
        }

    private:
        std::vector<SchedulingItem> schedule_item;
    };
}
#endif //JIMP_EXERCISES_SCHEDULER_H
