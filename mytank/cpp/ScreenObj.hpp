/*
 * ScreenObj.hpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef SCREENOBJ_HPP_
#define SCREENOBJ_HPP_

#include "src.hpp"
#include "Screen.hpp"
#include <memory>

//enum struct KindObj {Enemy, Friend, Player, MapObj};


class Screen;//声明
int id_get();


class ScreenObj {
	friend class Screen;
protected:
	// 共享的地图Screen
	Screen* stage;
	// position
	int x;
	int y;
	char figure;
	KindObj kind;// 是什么类型
	int id;// 希望构造这个 的函数，不被覆盖，且有static id成员

public:
	ScreenObj() = delete;
	// 1
	ScreenObj(Screen* ptr_s,
			int,// x_ = 1,
			int,// y_ = 1,
			char,// figure_ = ' ',
			const KindObj &k);// = KindObj::MAPOBJ);

	virtual ~ScreenObj() = default;

public:
	// 1 符号
	char get_figure() const {
		return figure;
	}
	void set_figure(char c) {
		if (c != figure)
			figure = c;
	}
	// 2 add
	// 由Screen被动add
	// 2 - 2 remove
	virtual void gameover();
	void reset_position( int x_, int y_);
	bool is_in_screen(int x_, int y_);
	// 5 派生类的成员获得：
	virtual bool get_has_moved() { return false; }
	virtual void reset_has_moved() {}//交给派生类定义操作
};




#endif /* SCREENOBJ_HPP_ */
