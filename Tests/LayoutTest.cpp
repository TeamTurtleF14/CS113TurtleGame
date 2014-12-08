//#include "cute.h"
//#include "LayoutTest.h"
//
//#include "LayoutGenCopy.hpp"
//
//void LayoutConstructTest() {
//	LayoutGen* L = new LayoutGen();
//	bool check = true;
//	if (L==NULL)
//		check = false;
//	delete L;
//	ASSERTM("LayoutGen did not properly construct", check);
//}
//
//void LayoutRecursiveRoomTest(Room* node, int& visits){
//	std::string occupied = node->OccupiedRoomString();
//	node->visited = true;
//	visits++;
//	for (std::string::iterator letter = occupied.begin(); letter != occupied.end(); letter++){
//		if (!(node->getFromChar(*letter)->visited)){
//			LayoutRecursiveRoomTest(node->getFromChar(*letter), visits);
//		}
//	}
//	return;
//}
//
//void LayoutRoomHeadTest(){
//	LayoutGen* L = new LayoutGen();
//	Room* head = L->getHeadRoom();
//	bool check = true;
//	if (head->OccupiedRoomString().size()==0)
//		check = true;
//	head = NULL;
//	delete L;
//	ASSERTM("Headroom did not return correctly", check);
//}
//
//void LayoutRoomListSizeTest(){
//	LayoutGen* L = new LayoutGen();
//	bool check = true;
//	std::vector<Room*> RoomList = L->getRoomList();
//	if (L==NULL){
//		check = false;
//		std::cout << "L was NULL" << std::endl;
//	}
//	if (check){
//		if (RoomList.size()<5){
//			check = false;
//		}
//	}
//	delete L;
//	RoomList.clear();
//	ASSERTM("Contents of RoomList was not good", check);
//}
//
//void LayoutDirectionsTest() {
//	LayoutGen *L = new LayoutGen();
//	std::vector<Room*> RoomList = L->getRoomList();
////	std::cout << RoomList.size() << " aaaaaaaa" << std::endl;
////	for (std::vector<Room*>::iterator room = RoomList.begin(); room != RoomList.end();
////			room++){
////		std::cout << (*room)->OccupiedRoomString() << " +++++++++" << std::endl;
////	}
//	bool check = true;
//	int N = 0;
//	int S = 0;
//	int E = 0;
//	int W = 0;
//	for (std::vector<Room*>::iterator room = RoomList.begin(); room != RoomList.end(); room++){
//		std::string occupied = (*room)->OccupiedRoomString();
////		std::cout << occupied << "----------------" << std::endl;
//		for (std::string::iterator letter = occupied.begin(); letter != occupied.end(); letter++){
//			if (*letter=='N')
//				N++;
//			if (*letter=='S')
//				S++;
//			if (*letter=='E')
//				E++;
//			if (*letter=='W')
//				W++;
//		}
//
//	}
//	if (N!=S){
//		std::cout << "N:" << N << " S:" << S << std::endl;
//		check = false;
//	}
//	if (E!=W){
//		std::cout << "E:" << E << " W:" << W << std::endl;
//		check = false;
//	}
//	std::cout << N <<" " << S << " " << E << " " << W << std::endl;
//	delete L;
//	RoomList.clear();
//	ASSERTM("Letters did not add up", check);
//}
//
//void LayoutConnectiveTest() {
//	LayoutGen* L = new LayoutGen();
//	Room* Head = L->getHeadRoom();
//	int visits = 0;
//	LayoutRecursiveRoomTest(Head, visits);
//	bool check = false;
//	std::vector<Room*> RoomList = L->getRoomList();
//	if (visits==(RoomList.size())){
//		check = true;
//	} else {
//		std::cout << "Visited: " << visits << std::endl;
//		check = false;
//	}
//
//	delete L;
//	std::cout << "Visited: " << visits << std::endl;
//	ASSERTM("All need to be connected", check);
//}
//
//cute::suite make_suite_LayoutTest(){
//	cute::suite s;
//	s.push_back(CUTE(LayoutConstructTest));
//	s.push_back(CUTE(LayoutRoomHeadTest));
//	s.push_back(CUTE(LayoutRoomListSizeTest));
//	s.push_back(CUTE(LayoutConnectiveTest));
////	s.push_back(CUTE(LayoutDirectionsTest));
//	return s;
//}
//
//
//
