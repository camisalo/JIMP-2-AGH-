//
// Created by konrad on 04.05.17.
//

#include "Serialization.h"


namespace academia {

    void Room::Serialize(Serializer *out) {
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

    void Building::Serialize(Serializer *out) {
        out->Header("building");
        out->IntegerField("id", id_);
        out->Separate();
        out->StringField("name", name_);
        out->Separate();
        out->Header("rooms");
        out->ArrayField("rooms",rooms_);
        
        out->Footer("rooms");
        out->Footer("building");
    }

    /////////////////   XML    ////////////////////////

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << std::to_string(value) << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "<" << field_name << ">" << std::to_string(value) << "<\\" << field_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {

    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }

    /////////////////   JSON   ////////////////////////

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "\"" << field_name << "\": \"" << value << "\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                            const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        
    }

    void JsonSerializer::Header(const std::string &object_name) {
        if(object_name == "building" or object_name == "room")
            (*out_) << "{";
        if(object_name == "rooms")
            (*out_) << "\"rooms\": [";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        if(object_name == "building" or object_name == "room")
            (*out_) << "}";
        if(object_name == "rooms")
            (*out_) << "]";
    }
}