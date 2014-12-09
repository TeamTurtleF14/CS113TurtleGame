/*
 * Room.hpp
 * Contains the header data for the Room class
 *
 *  Created on: Nov 8, 2014
 *      Author: Tony
 */

#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>

class Room{
private:

	std::map<const char, int> RoomDir;

public:

	Room* North;
	Room* South;
	Room* West;
	Room* East;
	bool isEnd;
	bool visited;

	Room(bool end=false)
	:North(NULL), South(NULL), West(NULL), East(NULL), isEnd(end)
	{
		RoomDir.insert(std::pair<const char, int>('N', 0));
		RoomDir.insert(std::pair<const char, int>('W', 1));
		RoomDir.insert(std::pair<const char, int>('S', 2));
		RoomDir.insert(std::pair<const char, int>('E', 3));
		visited = false;
	}

	// sets the next room
	void setNext(Room* newRoom, char Direction) {
		switch (Direction)
		{
		case 'N':
			North = newRoom;
			break;
		case 'E':
			East = newRoom;
			break;
		case 'S':
			South = newRoom;
			break;
		case 'W':
			West = newRoom;
			break;
		default:
			std::cout << "Error: Direction "<<  Direction <<" Cannot Be Used" << std::endl;
			break;
		}
	}

	// Checks to see if there are any available rooms
	bool checkAvailable(){
		if ((North!=NULL) && (East!=NULL) && (South!=NULL) && (West!=NULL))
			return false;
		return true;
	}


	std::vector<Room*> AvailableRoomVector(){
		std::vector<Room*> result;
		if (!North)
			result.push_back(North);
		if (!East)
			result.push_back(East);
		if (!South)
			result.push_back(South);
		if (!West)
			result.push_back(West);
		return result;
	}

	// Returns a string where each char represents an available room
	//std::vector<Room*> AvailableRoomList(){
	std::string AvailableRoomString() {
		std::string result = "";
		//std::vector<Room*> Available;
		if (North==NULL)
			result.push_back('N');
			//Available.push_back(North);
		if (East==NULL)
			result.push_back('E');
			//Available.push_back(West);
		if (South==NULL)
			result.push_back('S');
			//Available.push_back(South);
		if (West==NULL)
			result.push_back('W');
			//Available.push_back(East);
		//return Available;
		return result;
	}

	// returns a vector containing all the available rooms
	std::vector<Room*> OccupiedRoomVector(){
		std::vector<Room*> result;
		if (North!=NULL)
			result.push_back(North);
		if (East!=NULL)
			result.push_back(East);
		if (South!=NULL)
			result.push_back(South);
		if (West!=NULL)
			result.push_back(West);
		return result;
	}
	// Returns a string where each character represents an occupied room
	std::string OccupiedRoomString(){
		std::string result = "";
		if (North!=NULL)
			result.push_back('N');
		if (East!=NULL)
			result.push_back('E');
		if (South!=NULL)
			result.push_back('S');
		if (West!=NULL)
			result.push_back('W');
		return result;
	}

	// A get function based on chars
	Room* getFromChar(char direction){
		switch (direction){
		case 'N':
			return North;
		case 'E':
			return East;
		case 'S':
			return South;
		case 'W':
			return West;
		default:
			throw std::invalid_argument("Invalid Direction Received");
		}
	}

	// Returns the direction that the second is related to first by
	// Returns '' if the two rooms are not related
	char getRoomDirection(Room* second){
		if (North == second)
			return 'N';
		if (East == second)
			return 'E';
		if (South == second)
			return 'S';
		if (West == second)
			return 'W';
		return ' ';
	}

	char OppositeDirection(char direction){
		switch (direction){
		case 'N':
			return 'S';
		case 'E':
			return 'W';
		case 'S':
			return 'N';
		case 'W':
			return 'E';
//		default:
//			return '';
		}
	}

	// Returns a true is the direction is adjacent to the direction and open
	std::string AdjacentDirections(char direction){
		switch (direction){
		case 'N':
			return "WE";
		case 'E':
			return "NS";
		case 'S':
			return "EW";
		case 'W':
			return "NS";
		default:
			return "";
		}
	}

	// Checks char representation for room, sees if available
	bool isAvailable(char room){
		if (getFromChar(room)==NULL)
			return true;
		else
			return false;
	}


};


#endif /* SRC_ROOM_HPP_ */
