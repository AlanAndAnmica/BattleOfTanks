/*
 * GameMg.cpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#include "GameMg.h"

GameMg::~GameMg() {
	// TODO Auto-generated destructor stub
}
/*
void GameMg::deal_quest() {
	stage->is_ready = true;// 与cv相配合
	do {
		stage->cv.notify_all();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	} while (!stage->quest_id.empty());//为空了，就可以打印了
	stage->is_ready = false;// 与cv相配合
	stage->print();
//	return true;//?
}
*/
void deal_quest(GameMg & mg) {
	mg.stage->is_ready = true;// 与cv相配合
	do {
		mg.stage->cv.notify_all();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	} while (!mg.stage->quest_id.empty());//为空了，就可以打印了
	mg.stage->is_ready = false;// 与cv相配合
//	for (auto &a : mg.stage->) {
//		a->reset_has_moved();//现在可以再移动了
//	}
	//交给print统一唤醒？0102
	mg.stage->print();
//	return true;//?
}
//据说切换为友元函数即可？ 来试试
/*
void GameMg::run_print_base() { //交给主界面来 设为独立流
	while (!stage->is_ended){
		deal_quest();
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
	}
}
*/
void run_print_base(GameMg & mg) { //交给主界面来 设为独立流
	while (!mg.stage->is_ended){
		deal_quest(mg);
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}
}
