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
LayoutGen::LayoutGen() {
	int NumRooms = 20;	// # of rooms for entire level
	int CriticalPathRooms = 10;	// # of rooms from from start to end, including entrance/exit
	int AdditionalRooms = NumRooms - CriticalPathRooms;	// # of rooms outside of Crit Path
	int SidePathRooms = 6;		// # of rooms are on the sides, leads to dead ends
	int CircularPathRooms = 4;	// # of rooms that are part of a circle, leads back to self
	std::vector<std::pair<int, int> > RoomCoords = CriticalPathGen();
	std::vector<Room*> RoomContainer;

	Room* HeadRoom = new Room();	// This will become the entrance room
	//HeadRoom->North;
}


// creates a vector of coordinates that represents where each room will be
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

		// Performs a check to make sure that the Coordinates are not already set as a room
		for (unsigned int i = 0; i < Coordinates.size(); i++) {
			Contains = 0;
			if (Coordinates[i].first==addCoord.first && Coordinates[i].second==addCoord.second){
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
///////////////////////////////////// END CriticalPathGen



bool LayoutGen::isinCoords(std::pair<int, int> pair){
	for (unsigned int i = 0; i < RoomCoords.size(); i++){
		if (RoomCoords[i].first==pair.first && RoomCoords[i].second==pair.second){
			return true;
		}
	}
	return false;
}


// member function to set up rooms with directions to other rooms
// current = room to be added to
void LayoutGen::extendRooms(Room* current) {
	if (!(current->checkAvailable()))
		return;
	generateCriticalPath();
	//generateCircularPaths(); // first, as it will be easier to create this first
	//generateSidePaths();		// second, will extend wherever possible

}


// Will add Rooms based on Coordinates
// the coords will be x and y, (1,0) will be a room to the west
// and (-1, 0) will be a room to the east
void LayoutGen::generateCriticalPath(){
	Room* current = HeadRoom;
	RoomContainer.push_back(current);
	Room* next;
	for (unsigned int i = 1; i < RoomCoords.size(); i++){

		// First creates a new room, for the next room
		if (i == RoomCoords.size()-1)
			next = new Room(true);	// signals that the room is the last, or the end
		else
			next = new Room();
		RoomContainer.push_back(next);
		if (RoomCoords[i].first - RoomCoords[i-1].first == 0){
			if (RoomCoords[i].second > RoomCoords[i-1].second){
				// Add a room to the north
				current->North = next;		// make current's north to be next
				next->South = current;		// make next's south to be current
			} else{
				// Add a room to the south
				current->South = next;
				next->North = current;
			}
		} else if (RoomCoords[i].second - RoomCoords[i-1].second == 0) {
			if (RoomCoords[i].first > RoomCoords[i-1].first) {
				// Add a room to the West
				current->West = next;
				next->East = current;
			} else{
				// Add a room to the East
				current->East = next;
				next->West = current;
			}
		}
		current = next;	// set current pointer to next
	}

}



void LayoutGen::generateSidePaths(){
	for (unsigned int i = 0; i < SidePathRooms; i++){
		Room* current = HeadRoom;
		bool assigned = false;
		while (!assigned){
			;// until another room is added on, assigned == false
		}
	}
	return;
}

void LayoutGen::generateCircularPaths(){
	// it'd be easiest if circular path rooms variable was always an even number
	// go through headroom node
	// stop, randomly, on one of the nodes
	// determine how far forward from there the circular path will extend forward,
	// only go forward (circular path rooms)/2, then just choose a side that is also free
	// for (circular path rooms)/2



	return;
}


// will find the start of a viable circular path, searches through coordinates list
Room* LayoutGen::findCircularPathStart(){

}


// returns a Room*. pointer that points to first room, has references to other rooms if any
Room* LayoutGen::getHeadRoom(){
	return HeadRoom;
}


// Returns the Room list vector, makes it easy to delete later
std::vector<Room*> LayoutGen::getRoomList(){
	return RoomContainer;
}
