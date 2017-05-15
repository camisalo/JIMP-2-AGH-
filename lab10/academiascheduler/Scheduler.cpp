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

    std::vector<int> Schedule::AvailableTimeSlots(int room) {
        std::vector<int> i;

        return i;
    }


}