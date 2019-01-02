/*
 * LiveObj.hpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef LIVEOBJ_HPP_
#define LIVEOBJ_HPP_

class LiveObj {
protected:
	int live;//生命值

public:
//	LiveObj() = default;
	explicit LiveObj(int live_ = 1) : live(live_) {}
	virtual ~LiveObj() = default;
public:
	// 1 生命值
	bool is_live() { return live > 0; }
	int get_live() {return live;}
	void set_live(int live_) {live = live_;}
};




#endif /* LIVEOBJ_HPP_ */
