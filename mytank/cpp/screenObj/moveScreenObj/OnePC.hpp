/*
 * OnePC.hpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef SCREENOBJ_MOVESCREENOBJ_ONEPC_HPP_
#define SCREENOBJ_MOVESCREENOBJ_ONEPC_HPP_

//#include "src.hpp"
#include "../MoveScreenObj.hpp"
#include "../LiveObj.hpp"
//class MoveScreenObj
class OnePC : public MoveScreenObj, public LiveObj {

public:
	OnePC(
			Screen* ptr_s,
			int x_ = 1, int y_ = 1, char figure_ = '^',
			const KindObj &k = KindObj::MAPOBJ,
			const MoveDire &md = MoveDire::UP,
			int live_ = 1) :
				MoveScreenObj(ptr_s,
			x_, y_, figure_, k, md),
				LiveObj(live_) {}


};



#endif /* SCREENOBJ_MOVESCREENOBJ_ONEPC_HPP_ */
