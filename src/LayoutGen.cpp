/*
 * LayoutGen.cpp
 * Source file for LayoutGen.hpp
 * A class that will create the layout for the maze, can return the layout in the form of rooms
 *  Created on: Nov 8, 2014
 *      Author: Tony
 */

#include "LayoutGen.hpp"

// LayoutGen constructor
LayoutGen::LayoutGen(int AdditionalRooms) {
	HeadRoom = new Room();
	extendRooms(HeadRoom);
	//HeadRoom->North;
}

// member function to set up rooms with directions to other rooms
void LayoutGen::extendRooms(Room* Head) {

}

// returns a Room*. pointer that points to first room, has references to other rooms if any
Room* LayoutGen::getHeadRoom(){
	return HeadRoom;
}
