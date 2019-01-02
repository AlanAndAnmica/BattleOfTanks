//============================================================================
// Name        : mytank.cpp
// Author      : anmica
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "src.hpp"
//#include "Screen.hpp"
#include "screenObj/moveScreenObj/onePC/Player.hpp"

#include "ScreenObj.hpp"
#include "Screen.hpp"
//#include ""
#include "GameMg.h"

using namespace std;

int main() {
	cout << "new files!" << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	// test:
	//auto p_screen = make_shared<Screen>(Screen());
	shared_ptr<Screen> s(new Screen());
	shared_ptr<Player> mytank(new Player(s.get()));// 这真是不方便
//	p_screen->print();
	GameMg gamemg(s);

	s->add_obj(mytank);
//	gamemg.add_moveObj(mytank);
	thread t1 = thread(bind(run_print_base, gamemg));
	thread t2 = thread(bind(ready_for_move, mytank));
	t1.detach();
	t2.detach();
//	auto f1 = std::async(std::launch::async,
//			[&] {gamemg.run_print_base;});
//	auto f2 = std::async(std::launch::async,
//			[&] {mytank->ready_for_move;});
//	s.print();
//	cout << mytank.get_figure();

//	f1.wait_for(chrono::seconds(10));

	this_thread::sleep_for(chrono::seconds(50));
	gamemg.end_this_game();

	return 0;
}
