/*
 * LayoutGen.cpp
 * Source file for LayoutGen.hpp
 * A class that will create the layout for the maze, can return the layout in the form of rooms
 *  Created on: Nov 8, 2014
 *      Author: Tony
 */

#include "LayoutGen.hpp"
#include <vector>
#include <stdlib.h>

// LayoutGen constructor
LayoutGen::LayoutGen(int AdditionalRooms) {
	HeadRoom = new Room();	// This will become the entrance room
	NumRooms = 20;	// # of rooms for entire level
	CriticalPathRooms = 10;	// # of rooms from from start to end, including entrance/exit
	AdditionalRooms = NumRooms - CriticalPathRooms;	// # of rooms outside of Crit Path
	SidePathRooms = 6;		// # of rooms are on the sides, leads to dead ends
	CircularPathRooms = 4;	// # of rooms that are part of a circle, leads back to self
	RoomCoords = CriticalPathGen();
	extendRooms(HeadRoom);
	//HeadRoom->North;
}

std::vector<std::pair<int, int> > LayoutGen::CriticalPathGen() {
	std::vector<std::pair<int, int> > Coordinates;
	Coordinates.push_back(std::make_pair<int, int>(0,0));	//inserts initial space, entrance
	std::pair<int, int> addCoord;	//placeholder for the coordinates to be added in
	int selector;
	bool Contains = 0;				// Used for the checking of new coords in vector

	while (Coordinates.size() < CriticalPathRooms - 1) {
		selector = rand() % 4;	// selects the direction for the next room

		switch (selector) {
		case 0:
			addCoord = std::make_pair(Coordinates.back().first, Coordinates.back().second + 1);
			break;
		case 1:
			addCoord = std::make_pair(Coordinates.back().first, Coordinates.back().second - 1);
			break;
		case 2:
			addCoord = std::make_pair(Coordinates.back().first + 1, Coordinates.back().second);
			break;
		case 3:
			addCoord = std::make_pair(Coordinates.back().first - 1, Coordinates.back().second);
			break;
		default:
			break;
		}

		for (unsigned int i = 0; i < Coordinates.size(); i++) {
			Contains = 0;
			if (Coordinates[0].first==addCoord.first && Coordinates[1].second==addCoord.second){
				Contains = 1;
				break;
			}
		}
		if (Contains){}	// Do nothing, let the loop start over
		else
			Coordinates.push_back(addCoord);	// addCoord was not in vector, add to back
	}

	return Coordinates;
}

// member function to set up rooms with directions to other rooms
// current = room to be added to
void LayoutGen::extendRooms(Room* current) {
	if (!(current->checkAvailable()))
		return;
	std::string available = current->AvailableRoomString();


}

// returns a Room*. pointer that points to first room, has references to other rooms if any
Room* LayoutGen::getHeadRoom(){
	return HeadRoom;
}
