//
// Created by konrad on 01.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <iostream>
#include <initializer_list>

namespace academia {

    class TeacherId{
    public:
        TeacherId(int id) : id_{id} {}
        int GetId() const {return id_;}
        bool operator!=(const TeacherId &teacher) const{
            return teacher.id_!=id_;
        }

        operator int() const {
            return id_;
        }

    private:
        int id_;
    };



    class Teacher {
    public:
        Teacher(TeacherId id, std::string name, std::string department) : id_{id}, name_{name}, department_{department}  {        }
        TeacherId Id() const {return id_;}
        std::string Name() const {return name_;}
        std::string Department() const {return department_;}

        bool operator!=(const Teacher &teacher) const {
            if (this->name_ != teacher.name_) {return true;}
            if (this->department_ != teacher.department_) {return true; }
            if (this->id_ != teacher.id_) {return true;}
            return false;
        }
        bool operator==(const Teacher &teacher) const {
            if (this->name_ != teacher.name_) {return false;}
            if (this->department_ != teacher.department_) {return false; }
            if (this->id_ != teacher.id_) {return false;}
            return true;
        }


    private:
        TeacherId id_;
        std::string name_;
        std::string department_;
    };



    class TeacherHash{
    public:
        TeacherHash(){}
        size_t operator()(const Teacher &teacher) const {
            return std::hash<int>{}(teacher.Id())^std::hash<std::string>{}(teacher.Name())^std::hash<std::string>{}(teacher.Department());
        }


    private:
        size_t size_;
    };


}




#endif //JIMP_EXERCISES_TEACHERHASH_H
