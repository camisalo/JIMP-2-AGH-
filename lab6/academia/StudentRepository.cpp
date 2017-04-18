//
// Created by konrad on 06.04.17.
//

#include "StudentRepository.h"


namespace academia {

    StudyYear::StudyYear() {
        year = 1;
    }


    int StudyYear::operator++() {
        year++;
        return year - 1;
    }

    int StudyYear::operator--() {
        year--;
        return year + 1;
    }

    StudyYear::StudyYear(int year) : year(year) {}


    Student::Student() {

    }

    void Student::ChangeLastName(std::string new_name) {
        last_name = new_name;

    }


}