/*
 * GameMg.h
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef GAMEMG_H_
#define GAMEMG_H_

#include "src.hpp"
#include "Screen.hpp"
#include "screenObj/MoveScreenObj.hpp"
void run_print_base(GameMg & mg);
void deal_quest(GameMg & mg);

class GameMg {// 直接对一个Screen以及其中的 Objs进行管理
	friend void run_print_base(GameMg & mg);
	friend void deal_quest(GameMg & mg);

	std::shared_ptr<Screen> stage;
	// 1 放弃，选择虚操作，动态绑定
//	std::vector<std::shared_ptr<MoveScreenObj>> moves;//对move进行限定

	// 1 还是放回stage
//	vector<int> quest_id;//待处理的quest；
//	bool is_ended = false;

public:// run的操作

	// 2. future的第二个
	void run_print_base();// 重复进行deal_quest, 需要设置为 后台流
	void deal_quest();//如果有，便操作;
	void end_this_game() {//给信号以结束游戏 并打印结果
		stage->is_ended = true;
	}
//	void add_moveObj(shared_ptr<MoveScreenObj> mv);

public:



public:
	GameMg() = delete;
	GameMg(std::shared_ptr<Screen> stage_) : stage(stage_) {}
	virtual ~GameMg();
};

#endif /* GAMEMG_H_ */
