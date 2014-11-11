/*
 * Room.hpp
 * Contains the header data for the Room class
 *
 *  Created on: Nov 8, 2014
 *      Author: Tony
 */

#ifndef SRC_ROOM_HPP_
#define SRC_ROOM_HPP_

#include <iostream>
#include <vector>
#include <map>

enum Type{EmptyRoom, isRoom};	// declare enumeration for checking rooms

class Room{
private:

//	Room* North;
//	Room* South;
//	Room* West;
//	Room* East;
	std::map<const char, int> RoomDir;

public:

	Room* North;
	Room* South;
	Room* West;
	Room* East;

	Room()
	:North(NULL), South(NULL), West(NULL), East(NULL)
	{
		RoomDir.insert(std::pair<const char, int>('N', 0));
		RoomDir.insert(std::pair<const char, int>('W', 1));
		RoomDir.insert(std::pair<const char, int>('S', 2));
		RoomDir.insert(std::pair<const char, int>('E', 3));
	}

	// sets the next room
	void setNext(Room* newRoom, char Direction) {
		switch (RoomDir[Direction])
		{
		case 0:
			North = newRoom;
			break;
		case 1:
			West = newRoom;
			break;
		case 2:
			South = newRoom;
			break;
		case 3:
			East = newRoom;
			break;
		default:
			std::cout << "Error: Did not set Next Correctly" << std::endl;
			break;
		}
	}

	// Checks to see if there are any available rooms
	bool checkAvailable(){
		if ((North!=NULL) && (West!=NULL) && (South!=NULL) && (East!=NULL))
			return false;
		return true;
	}

	// Returns a string where
	//std::vector<Room*> AvailableRoomList(){
	std::string AvailableRoomString() {
		std::string result = "";
		//std::vector<Room*> Available;
		if (!North)
			result.push_back('N');
			//Available.push_back(North);
		if (!West)
			result.push_back('W');
			//Available.push_back(West);
		if (!South)
			result.push_back('S');
			//Available.push_back(South);
		if (!East)
			result.push_back('E');
			//Available.push_back(East);
		//return Available;
		return result;
	}

};


#endif /* SRC_ROOM_HPP_ */
