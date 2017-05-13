//
// Created by konrad on 13.05.17.
//

#include "Scheduler.h"

namespace academia{

    const Schedule Schedule::OfTeacher(int teacherid){
        Schedule teacher;
        for (auto v:Item){
            if (v.TeacherId() == teacherid){
                teacher.InsertScheduleItem(v);
            }
        }
        return teacher;
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