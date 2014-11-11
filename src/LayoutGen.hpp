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

public:

	LayoutGen();	// Creates total rooms, will add to NumRooms here

	// Creates the critical path, in a set of coords
	std::vector<std::pair<int, int> > CriticalPathGen();

	// helper function, checks to see if a pair is already in the Coordinate list
	bool isinCoords(std::pair<int, int>);

	void extendRooms(Room* Head);	// Attaches rooms, starting at first room

	// creates the CriticalPath()
	void generateCriticalPath();

	Room* getHeadRoom();	// Returns room pointer to starting room


};



#endif /* SRC_LAYOUTGEN_HPP_ */
