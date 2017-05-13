//
// Created by konrad on 13.05.17.
//

#include "Scheduler.h"

namespace academia{

    Schedule &Schedule::OfTeacher(int teacherid) {
        Schedule teacher;
        for (int i = 0; i < schedules.size(); ++i) {
            if (schedules[i].TeacherId() == teacherid) {
                teacher.InsertScheduleItem(schedules[i]);
            }
        }
        return this;
    }

    const Schedule Schedule::OfRoom(int room) {
        return Schedule();
    }

    const Schedule Schedule::OfYear(int room) {

        return Schedule();
    }

    std::vector<int> Schedule::AvailableTimeSlots(int room) {
        std::vector<int> i;

        return i;
    }


}