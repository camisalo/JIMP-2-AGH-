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
        SchedulingItem(std::initializer_list<unsigned long> it) {
            std::copy(it.begin(),it.end(),item.begin());
        }

        unsigned long CourseId() const { return  item[0];}
        unsigned long TeacherId() const { return item[1];}
        unsigned long RoomId() const { return item[2];}
        unsigned long TimeSlot() const { return item[3];}
        unsigned long Year() const { return item[4];}

    private:
        std::vector<unsigned long> item;
    };


    class Schedule {
    public:
        Schedule() {}

        void InsertScheduleItem(SchedulingItem k) {Item.emplace_back(k);}

        const Schedule OfTeacher(int teacherid);

        const Schedule OfRoom(int room);

        const Schedule OfYear(int room);

        std::vector<int> AvailableTimeSlots(int room);


        unsigned long Size() const { return Item.size();}
        unsigned long CourseId() const { return  Item[0].CourseId();}
        unsigned long TeacherId() const { return Item[0].TeacherId();}
        unsigned long RoomId() const { return Item[0].RoomId();}
        unsigned long TimeSlot() const { return Item[0].TimeSlot();}
        unsigned long Year() const { return Item[0].Year();}



        SchedulingItem * operator[](const int &i) {
            SchedulingItem *POINTER = &Item[i];
            return POINTER;
        }

    private:
        std::vector<SchedulingItem> Item;
    };
}
#endif //JIMP_EXERCISES_SCHEDULER_H
