/*
 * Game.h
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef GAME_H_
#define GAME_H_

#include "Screen.hpp"
#include "ScreenObj.hpp"

#include <chrono>
#include <condition_variable>
#include <mutex>
using std::condition_variable;
using std::mutex;

class Game {
	condition_variable cv;// 一对多管理流
	mutex cv_m;// lock用

	Screen stage;

public:
	// 启动一个游戏
	//
//	virtual void run(std::chrono::duration time)
	// 计时器
	void end_game() {

	}
	// 刷新器
	void buffer();

public:
	Game();
	virtual ~Game();
private:

};

#endif /* GAME_H_ */
