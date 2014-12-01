/*
 * LayoutGen.hpp
 * Header file for the Layout Generator
 * Creates room objects, attaches rooms properly when directed.
 */

#ifndef LAYOUTGEN_HPP_
#define LAYOUTGEN_HPP_

#include "Room.hpp"
#include <vector>
#include <utility>	// std::pair, std::make_pair

class LayoutGen {
	int NumRooms;	// # of rooms for entire level
	int CriticalPathRooms;	// # of rooms from from start to end, including entrance/exit
	int AdditionalRooms;	// # of rooms outside of Crit Path
	int SidePathRooms;		// # of rooms are on the sides, leads to dead ends
	int CircularPathRooms;	// # of rooms that are part of a circle, leads back to self
	std::vector< std::pair<int, int> > RoomCoords;	// coordinates for layout generation
	Room* HeadRoom;
	std::vector<Room*> RoomContainer; 		// Used to hold references to all Room* for deletion

public:

	LayoutGen();	// Creates total rooms, will add to NumRooms here

	~LayoutGen();	// Destructor

	// Creates the critical path, in a set of coords
	std::vector<std::pair<int, int> > CriticalPathGen();

	// Checks to see if there are 'forward' rooms ahead, without reaching end
	bool roomForwardCheck(Room* start, Room* next, int forward);

	// Helper function, translates directions where previous room was in relation to current
	// EX: go North into a new room, you came into new room from South
	char incomingDirection(Room* prev, Room* current);

//	// returns true, if a room is within the critical path
//	bool isinCriticalPath(Room* current);

	// helper function, checks to see if a pair is already in the Coordinate list
	bool isinCoords(std::pair<int, int>);

	// This versions takes in integer inputs
	bool isinCoords(int x, int y);

	void extendRooms(Room* Head);	// Attaches rooms, starting at first room

	// creates the CriticalPath()
	void generateCriticalPath();

	// adds on the SidePaths
	void generateSidePaths();

	// adds on more rooms that will become a circular path
	void generateCircularPaths();

	// Helper function to help simplify getting directions from string
	char OppositeDirection(char direction);


	// Functions below are for outside calls

	Room* getHeadRoom();	// Returns room pointer to starting room

	std::vector<Room*> getRoomList();	//Returns room list, makes for easy deletion


};



#endif /* SRC_LAYOUTGEN_HPP_ */
