/*
 * ScreenObj.cpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#include "ScreenObj.hpp"
#include "Screen.hpp"

int id_get()
{// 唯一值
	static int id_s = 1;
	return id_s++;
}
ScreenObj::ScreenObj(Screen* ptr_s,
			int x_ = 1, int y_ = 1, char figure_ = ' ',
			const KindObj &k = KindObj::MAPOBJ)
	: stage(ptr_s),
	  x(x_), y(y_),
	  figure(figure_), kind(k), id(id_get()) {
		// 添加进Screen的map中

}
void ScreenObj::gameover() {
		// 从stage中移除
		// 这里需要 screen ptr
		stage->remove_obj(id);

	}
void ScreenObj::reset_position(int x_, int y_) {
	if (is_in_screen(x_, y_)){
		using std::swap;
		//交换id_map中的位置信息
		swap(stage->id_map.at(y).at(x),
				stage->id_map.at(y_).at(x_));
		x = x_;
		y = y_;
	}
}
bool ScreenObj::is_in_screen(int x_, int y_) {
	return (0 <= x_ && 0 <= y_)
			 &&
					(x_ < stage->weight &&
					y_ < stage->height);
}

/*
bool ScreenObj::is_in_screen() const {
		return (0 <= x && 0 <= y
		 &&
				x <= screen->weight &&
				y <= screen->height);
	}
*/
