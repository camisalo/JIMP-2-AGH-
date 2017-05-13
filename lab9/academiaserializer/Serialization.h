//
// Created by konrad on 04.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <iostream>
#include <vector>


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
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
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
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };

    class Serializable {
    public:
        Serializable() {}

        virtual void Serialize(Serializer *a) = 0;

    };

    class Building : public Serializable {
    public:
        Building(const int &id, const std::string &names,const std::vector<std::reference_wrapper<const Serializable>> room)
                :
                id_(id), name_(names) {
            std::copy(room.begin(), room.end(), rooms_.begin());
        };

        void Serialize(Serializer *item) const;

    private:
        const int id_;
        const std::string name_;
        const std::vector<std::reference_wrapper<const Serializable>> rooms_;
    };


    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int id, std::string name, Type ty) : id{id}, name{name}, type{ty} {}

        void Serialize(Serializer *out) override {
            out->Header("room");
            out->IntegerField("room", 1);
            out->StringField("room", name);
            out->StringField("type", "a");
            out->Footer("room");
        }

    private:
        std::string name;
        int id;
        Type type;
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H