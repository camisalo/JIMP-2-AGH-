//
// Created by konrad on 04.05.17.
//

#include "Serialization.h"


namespace academia {

    void Building::Serialize(Serializer *in) const {
        in->Header("building");
        in->IntegerField("id", id_);
        in->StringField("name", name_);
        in->ArrayField("rooms", rooms_);
        in->Footer("building");
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

    }

    void XmlSerializer::Footer(const std::string &object_name) {

    }

    /////////////////   JSON   ////////////////////////

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {

    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {

    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

    }

    void JsonSerializer::Header(const std::string &object_name) {

    }

    void JsonSerializer::Footer(const std::string &object_name) {

    }


}