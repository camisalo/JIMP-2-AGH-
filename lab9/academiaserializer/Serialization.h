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
#include <functional>

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

        void Separate() override {(*out_) << ", ";};

    };

    class Serializable {
    public:
        virtual void Serialize(Serializer *a) const = 0;
    };



    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int id, std::string name, Room::Type ty) : id{id}, name{name}, type{ty} {}

        void Serialize(Serializer *out) const override ;


    private:
        std::string name;
        int id;
        Type type;
    };

    class Building : public Serializable {
    public:
        Building(const int &id,const std::string &names,
                 std::initializer_list<std::reference_wrapper<const Serializable>> room)
                : id_(id), name_(names) {
            for (auto v:room){
                rooms_.emplace_back(std::ref(v));
            }
        };

        void Serialize(Serializer *out) const override;

    private:
        int id_;
        std::string name_;
        std::vector<std::reference_wrapper<const Serializable>> rooms_;
    };


    class BuildingRepository {
    public:
        BuildingRepository() {}

        BuildingRepository(std::initializer_list<std::reference_wrapper<const Serialzer building){
            build_.emplace_back(std::ref(building));
        }

        void StoreAll(Serializer *out) {

        }

        void Add(Building build){

        }

    private:
        std::vector<std::reference_wrapper<const Serializable>> build_;
    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
