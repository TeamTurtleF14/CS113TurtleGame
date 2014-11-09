/*
 * LayoutGen.hpp
 * Header file for the Layout Generator
 * Creates room objects, attaches rooms properly when directed.
 */

#ifndef LAYOUTGEN_HPP_
#define LAYOUTGEN_HPP_

#include "Room.hpp"

class LayoutGen {
	int NumRooms;	// # of rooms for entire level
	int CriticalPathRooms;	// # of rooms from from start to end, including entrance/exit
	int AdditionalRooms;	// # of rooms outside of Crit Path
	int SidePathRooms;		// # of rooms are on the sides, leads to dead ends
	int CircularPathRooms;	// # of rooms that are part of a circle, leads back to self
	Room* HeadRoom;

public:

	LayoutGen(int AdditionalRooms);	// Creates total rooms, will add to NumRooms here

	void extendRooms(Room* Head);	// Attaches rooms, starting at first room

	Room* getHeadRoom();	// Returns room pointer to starting room




};



#endif /* SRC_LAYOUTGEN_HPP_ */
