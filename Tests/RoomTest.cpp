//#include "cute.h"
//#include "RoomTest.h"
//#include "Room.hpp"
//
//bool setNextHelp() {
//	Room* center = new Room();
//	Room* next;
//	std::string directions = "NESW";
//	for (int i = 0; i < 4; i++){
//		next = new Room();
//		center->setNext(next, directions[i]);
//		if (center->getFromChar(directions[i])==next){
//			delete next;
//		} else{
//			delete next;
//			delete center;
//			return true;
//		}
//	}
//	delete center;
//	return true;
//}
//
//bool AvailableRoomHelp(){
//	Room* test = new Room();
//	std::vector<Room*> testlist = test->AvailableRoomVector();
//	bool check = true;
//	for (int i = 0; i < testlist.size(); i++){
//		if (testlist[i]!=NULL)
//			check = false;
//	}
//	delete test;
//	return check;
//}
//
//bool isAvailableHelp() {
//	std::string directions = "NESW";
//	Room* hello = new Room();
//	for (int i = 0; i < 4; i++){
//		if (hello->isAvailable(directions[i])){
//			;
//		} else{
//			delete hello;
//			return false;
//		}
//	}
//	return true;
//}
//
//
//void ConstructTest() {
//	Room* room = new Room();
//	bool construct;
//	if (room != NULL)
//		construct = true;
//	else
//		construct = false;
//	delete room;
//	ASSERTM("Construct Test", construct);
//}
//
//
//void initDirectionTest() {
//	Room* room = new Room();
//	bool dirNulls = false;
//	if (room->North==NULL && room->East==NULL && room->South==NULL && room->West==NULL)
//		dirNulls = true;
//	else
//		dirNulls = false;
//	delete room;
//	ASSERTM("Initial Directions are NULL", dirNulls);
//}
//
//void twoEqualTest() {
//	Room* one = new Room();
//	Room* two = new Room();
//	bool check = false;
//	if (one == two)
//		check = false;
//	else
//		check = true;
//	delete one;
//	delete two;
//	ASSERTM("Two rooms are not the same when initialized", check);
//}
//
//void setNextTest() {
//	ASSERTM("Sets Next Properly. Shouldn't matter is twoEqual Fails", setNextHelp());
//}
//
//void AvailableRoomTest(){
//	ASSERTM("Checks to see that all in returned Vector are unoccupied", AvailableRoomHelp());
//}
//
//void StringTest(){
//	Room* test = new Room();
//	Room* next = new Room();
//	bool check = true;
//	if (test->AvailableRoomString()!="NESW")
//		check = false;
//	if (check){
//		test->setNext(next, 'N');
//		if (test->AvailableRoomString()!="ESW")
//			check = false;
//	}
//	delete next;
//	delete test;
//	ASSERTM("Checks to see that return room string changes correctly", check);
//}
//
//void OccupiedRoomTest(){
//	Room* test = new Room();
//	Room* next = new Room();
//	std::vector<Room*> testvector = test->OccupiedRoomVector();
//	bool check = true;
//	if (testvector.size()!=0){
//		std::cout << "Size was not 0" << std::endl;
//		check = false;
//	}
//	test->setNext(next, 'N');
//	testvector = test->OccupiedRoomVector();
//	if (check){
//		std::cout << testvector.size() << std::endl;
//		if (testvector.size()!=1)
//			check = false;
//	}
//	testvector.clear();
//	delete next;
//	delete test;
//	ASSERTM("Should give appriopriate number of rooms Occupied", check);
//}
//
//void getFromCharTest(){
//	Room* test = new Room();
//	Room* next = new Room();
//	bool check = true;
//	test->setNext(next, 'N');
//	if (test->getFromChar('S')!=next)
//		if (test->getFromChar('N')==next)
//			check = true;
//		else
//			check = false;
//	else
//		check = false;
//	delete next;
//	delete test;
//	ASSERTM("Test that getting from char actually returns the room", check);
//}
//
//void isAvailableTest() {
//	ASSERTM("Bool from isAvailable: Checking functionality", isAvailableHelp());
//}
//
//cute::suite make_suite_RoomTest(){
//	cute::suite s;
//	s.push_back(CUTE(ConstructTest));
//	s.push_back(CUTE(initDirectionTest));
//	s.push_back(CUTE(twoEqualTest));
//	s.push_back(CUTE(setNextTest));
//	s.push_back(CUTE(isAvailableTest));
//	s.push_back(CUTE(AvailableRoomTest));
//	s.push_back(CUTE(StringTest));
//	s.push_back(CUTE(OccupiedRoomTest));
//	s.push_back(CUTE(getFromCharTest));
//
//	return s;
//}
