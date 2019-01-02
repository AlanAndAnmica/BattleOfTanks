/*
 * MoveScreenObj.hpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef MOVESCREENOBJ_HPP_
#define MOVESCREENOBJ_HPP_

#include <memory>
//#include ""
#include "../ScreenObj.hpp"

//enum MoveDire {Up, Down, Left, Right};
//enum struct KindObj;
class Screen;
class ScreenObj;
class MoveScreenObj : public ScreenObj {
protected:
	MoveDire direction;
	int speed = 1;//可考虑换作几档速度enum
	bool if_change_d = true;
	bool has_moved = false;//限制每次仅移动一次,即使是瞬间的开放

public:
	MoveScreenObj(
			Screen* ptr_s,
			int x_, int y_, char figure_ = ' ',
			const KindObj &k = KindObj::MAPOBJ,
					const MoveDire &md = MoveDire::UP) :// new
				ScreenObj(ptr_s, x_, y_, figure_, k),// old
				direction(md) {}

public:
	// only move able Obj才有
	void move();// 已经定义ok～
	virtual void ready_for_move() = 0; // 按照现在的方向
	virtual void set_direction(const MoveDire& m ) {
		if_change_d = (direction == m) ? false : true;
		if (if_change_d)
			direction = m;
	}
	MoveDire get_direction() {return direction;}

	// 承接基类 5:
	bool get_has_moved() override {return has_moved;}
	void reset_has_moved() override {
		if(has_moved) has_moved = false;}//交给派生类定义操作

};




#endif /* MOVESCREENOBJ_HPP_ */
