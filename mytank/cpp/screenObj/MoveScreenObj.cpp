/*
 * MoveScreenObj.cpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#include "MoveScreenObj.hpp"

void MoveScreenObj::move() {
		// 调用即传一个quest
		stage->quest_id.insert(id);// 最后还要移除
		std::unique_lock<std::mutex> lk(stage->cv_m);
		stage->cv.wait(lk, [&]
							{return !has_moved &&//等待一次刷新结束
									stage->is_ready;
									});
		has_moved = true;//已经移动了，然后由manage改为false
		// 等待cv发信号， 然后下一步移动
//		move_next();
//		auto obj = stage->get_obj(id);//没必要
		switch (direction) {
		case MoveDire::UP:
			reset_position(x, y + speed);
//			obj->reset_position(x, y + )
					break;
		case MoveDire::DOWN:
			reset_position(x, y - speed);
					break;
		case MoveDire::LEFT:
			reset_position(x - speed, y);
					break;
		case MoveDire::RIGHT:
			reset_position(x + speed, y);
					break;
		}
		stage->quest_id.erase(id);// 移除OK

}// end

