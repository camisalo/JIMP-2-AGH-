//
// Created by konrad on 06.04.17.
//

#ifndef JIMP_EXERCISES_ACADEMIA_H
#define JIMP_EXERCISES_ACADEMIA_H

#include <iostream>
#include <string>

namespace academia {

    class StudyYear {
    public:
        StudyYear();


        int operator++();

        int operator--();

    private:
        int year;
    public:
        StudyYear(int year);

    };


    class Student {

    public:
        Student();

        void ChangeLastName(std::string new_name);

    private:
        std::string id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear year;
    };
}

#endif //JIMP_EXERCISES_ACADEMIA_H
