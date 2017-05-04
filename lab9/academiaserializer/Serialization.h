//
// Created by konrad on 04.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>


namespace academia {


    class Serializable;

    class Serializer {
    public:
        Serializer(std::ostream *out) {

        }

        virtual void IntegerField(const std::string &field_name, int value) = 0;

        virtual void DoubleField(const std::string &field_name, double value) = 0;

        virtual void StringField(const std::string &field_name, const std::string &value) = 0;

        virtual void BooleanField(const std::string &field_name, bool value) = 0;

        virtual void SerializableField(const std::string &field_name,
                                       const academia::Serializable &value) = 0;

        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) = 0;

        virtual void Header(const std::string &object_name) = 0;

        virtual void Footer(const std::string &object_name) = 0;


    };

    class Serializable {
    public:
        Serializable() {}

        virtual void Serialize(Serializer *a) = 0;

    };


    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int id, std::string name, Type ty) : id{id}, name{name}, type{ty} {

        }

        void Serialize(Serializer *a) override {
            a->Header("room");
            a->IntegerField("room", 1);
            a->StringField("room", name;
            a->StringField("type", "a");
            a->Footer("room");
        }

    private:
        std::string name;
        int id;
        Type type;
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H
