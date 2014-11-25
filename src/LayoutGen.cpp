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
#include <algorithm>

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


bool LayoutGen::isinCriticalPath(Room* current){
	return false;
}

// This function assumes the layout is still in the critical path phase, so
// 2 doors, 1 goes towards start, 1 goes towards end
// NEEDS a DIRECTION
bool LayoutGen::roomForwardCheck(Room* start, Room* next, int forward){
	Room* current = next;
	Room* prev = start;
	for (int i = 1; i < forward; i++){
		std::vector<Room*> tempContainer = current->OccupiedRoomVector();
		if (current->isEnd)
			return false;
		for (int j = 0; j < (int)(tempContainer.size())-1; j++){
			if (tempContainer[j]==prev){
				;
			}
			else{
				prev = current;
				current = tempContainer[j];
			}
		}
	}
	return true;
}


bool LayoutGen::isinCoords(std::pair<int, int> pair){
	for (unsigned int i = 0; i < RoomCoords.size(); i++){
		if (RoomCoords[i].first==pair.first && RoomCoords[i].second==pair.second){
			return true;
		}
	}
	return false;
}

bool LayoutGen::isinCoords(int x, int y){
	for (unsigned int i = 0; i < RoomCoords.size(); i++){
		if (RoomCoords[i].first==x && RoomCoords[i].second==y){
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
	current->isEnd = true;
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
	current->isEnd = true;		// Gives the last Room a signal that says it is the end room
}



void LayoutGen::generateSidePaths(){
	bool assigned = false;		// serves as a flag
	Room* addRoom;				// initialize new rooms
	Room* addRoomNext;
	Room* current;
	int random;					// random int, goes into RoomContainer randomly to add rooms
	for (int i = 0; i < SidePathRooms; i++){
		addRoom = new Room();
		random = rand()%(RoomContainer.size())-1;
		current = RoomContainer[random];
		if (current->isEnd){
			i--;
		} else if (!(current->checkAvailable())){
			i--;
		} else{
			std::string available = current->AvailableRoomString();
			std::random_shuffle(available.begin(), available.end());
			current->setNext(addRoom, available[0]);
			addRoom->setNext(current, OppositeDirection(available[0]));
			random = rand()% 2;
			while (random){
				available = addRoom->AvailableRoomString();
				std::random_shuffle(available.begin(), available.end());
				addRoomNext = new Room();
				addRoom->setNext(addRoomNext, available[0]);
				addRoomNext->setNext(addRoom, OppositeDirection(available[0]));
				i++;
				if (i>=SidePathRooms)
					break;
				else
					random = rand()%2;
			}
		}
	}
	return;
}

void LayoutGen::generateCircularPaths(){
	int start = rand()%((RoomContainer.size()- 4) + 1);	// - 4 to make far from end, +1 to avoid start
	Room* mainPath;
	Room* addPathPrev;
	Room* addPathNext;
	std::vector<Room*> AvailableRooms;
	int random;
	int CircularLimit = CircularPathRooms/2;

	while (true){
		if (roomForwardCheck(RoomContainer[start], RoomContainer[start+1], CircularPathRooms/2)){
			mainPath = RoomContainer[start];
			AvailableRooms = mainPath->AvailableRoomVector();
			random = rand() %(AvailableRooms.size());
			addPathPrev = new Room();

			std::string available = mainPath->AdjacentDirections(mainPath->getRoomDirection(RoomContainer[start+1]));
			std::random_shuffle(available.begin(), available.end());
			mainPath->setNext(addPathPrev, available[0]);		// Here, add one to side, adjacent to path towards end
			RoomContainer.push_back(addPathPrev);

			for (int i = 0; i < CircularLimit; i++){
				// Follows the main paths' directions
				mainPath = RoomContainer[start + i];
				addPathNext = new Room();
				addPathPrev->setNext(addPathNext, mainPath->getRoomDirection(RoomContainer[start+i+1]));
				addPathNext->setNext(addPathPrev, RoomContainer[start+i+1]->getRoomDirection(mainPath));
				RoomContainer.push_back(addPathNext);
				addPathPrev = addPathNext;

			}
			// Section below to connect the end of the add path back to main
			while (true){
				mainPath = RoomContainer[start + CircularLimit];
				if (mainPath->isAvailable(available[0])&addPathPrev->isAvailable(OppositeDirection(available[0]))){
					addPathPrev->setNext(mainPath, OppositeDirection(available[0]));
					mainPath->setNext(addPathPrev, available[0]);
					break;
				} else {
					std::string main = mainPath->AvailableRoomString();
					bool roomSet = false;
					for (int i = 0; i < main.size(); i++){
						if (addPathPrev->isAvailable(OppositeDirection(main[i]))){
							addPathPrev->setNext(mainPath, OppositeDirection(main[i]));
							mainPath->setNext(addPathPrev, main[i]);
							roomSet = true;
						}
						if (roomSet)
							break;
					}
					if (roomSet)
						break;
				}
			}

		} else{
			start = rand()%((RoomContainer.size() - 4) + 1);
		}
	}
	return;
}

char LayoutGen::OppositeDirection(char direction){
	switch (direction){
	case 'N':
		return 'S';
	case 'E':
		return 'W';
	case 'S':
		return 'N';
	case 'W':
		return 'E';
//	default:
//		return ' ';
	}
}
// will find the start of a viable circular path, searches through coordinates list
//Room* LayoutGen::findCircularPathStart(){

//	unsigned int counter = 0;
//	while (counter != CircularPathRooms){
//		int index = rand()%(RoomCoords.size()-1)+1;
//		std::pair<int, int> current = RoomCoords[index];
//		counter++;
//		for (unsigned int i = 1; i < CircularPathRooms; i++){
//			if (RoomCoords[index+i].first==RoomCoords[index + i - 1].first){
//
//			}
//		}
//	}
//}


// returns a Room*. pointer that points to first room, has references to other rooms if any
Room* LayoutGen::getHeadRoom(){
	return HeadRoom;
}


// Returns the Room list vector, makes it easy to delete later
std::vector<Room*> LayoutGen::getRoomList(){
	return RoomContainer;
}
