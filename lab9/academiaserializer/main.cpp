//
// Created by konrad on 04.05.17.
//
#include "Serialization.h"

using academia::Building;
using academia::XmlSerializer;
using academia::Room;
using academia::JsonSerializer;

int main(void) {
    std::stringstream out;
    JsonSerializer serializer{&out};
    
    
    Room room {117, "218", Room::Type::COMPUTER_LAB};
    Building building {11, "A0", {room}};
    room.Serialize(&serializer);



    std::cout << out.str() << std::endl;



    return 1;
}