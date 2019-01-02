/*
 * Screen.hpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include "src.hpp"
//#include "ScreenObj.hpp"

using namespace std;

class ScreenObj;
class Screen {
	friend class ScreenObj;
	friend class GameMg;
public:
	// cv 与lock
	std::condition_variable cv;
	std::mutex cv_m;
	bool is_ready = false;
	bool is_ended = false;// 结束async的flag
	// 1 还是放回stage
	set<int> quest_id;//待处理的quest；
private:
	// 屏幕的高宽
	unsigned int height;
	unsigned int weight;

	// tank 等obj的位置, 以及信息
	// id 与 obj
	std::map<int, std::shared_ptr<ScreenObj>> contents;
	vector<vector<int>> id_map;

public:
//	Screen() = delete;
	Screen(unsigned int h = 20, unsigned int w = 20) :
		height(h), weight(w),
		id_map(vector<vector<int>>(h,
				vector<int>(w, 0)))// 空的一定数量的
//				quest_id()
		{}

public:
	// 1 打印
	void print() const;
	// 1 - 2 刷新：
	// !! 这个还是交给 GameMg来 管理流操作 批量
	// 2 添加Obj 两种，1、直接添加。不，还是直接由Screen或者Game创建对象
							// 这种使得 Obj不需要指向Screen的指针，
							// 直接交给 Screen或者Game类(wrap Screen)亲自管理
	void add_obj(shared_ptr<ScreenObj> obj);//需要New 或者make_shared
	// 2 - 2 交由obj自己调用remove：
	void remove_obj(int id_);// 对标记有flag对进行移除, 也可以自动进行
	// 3 位置判断 交给Screen ,双版本吧.
	bool is_in_screen(shared_ptr<ScreenObj> obj) const;
	// 4 获得obj，以改变：
	shared_ptr<ScreenObj> get_obj(int id_);
	// 5 对contents的派生操作,那还是ScreenObj的事情


};




#endif /* SCREEN_HPP_ */
