//
// Created by konrad on 04.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <sstream>

namespace academia {

    class Serializable;

    class Serializer {
    public:
        Serializer(std::ostream *out) : out_{out} {}

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

        virtual void Separate(){(*out_)<<"";};

    protected:
        std::ostream *out_;
    };

    class XmlSerializer : public Serializer {
    public:
        XmlSerializer(std::ostream *out) : Serializer(out) {};

        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name,
                               const Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value)  {}
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };


    class JsonSerializer : public Serializer {
    public:
        JsonSerializer(std::ostream *out) : Serializer(out) {};

        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {}
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;

        void Separate() override {(*out_) << ", ";};

    };

    class Serializable {
    public:
        virtual void Serialize(Serializer *a) = 0;
    };



    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int id, std::string name, Room::Type ty) : id{id}, name{name}, type{ty} {}

        void Serialize(Serializer *out) override {
            out->Header("room");
            out->IntegerField("id", id);
            out->Separate();
            out->StringField("name", name);
            out->Separate();
            if (type == Type::COMPUTER_LAB)
                out->StringField("type", "COMPUTER_LAB");
            else if (type == Type::LECTURE_HALL)
                out->StringField("type", "LECTURE_HALL");
            else if (type == Type::CLASSROOM)
                out->StringField("type", "CLASSROOM");

            out->Footer("room");
        }

    private:
        std::string name;
        int id;
        Type type;
    };

    class Building : public Serializable {
    public:
        Building(const int &id,const std::string &names, std::vector<Room> room)
                : id_(id), name_(names), rooms_{room} {
        };

        void Serialize(Serializer *out) override;

    private:
        int id_;
        std::string name_;
        std::vector<Room> rooms_;
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H
