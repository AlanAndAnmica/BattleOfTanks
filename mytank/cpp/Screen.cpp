/*
 * Screen.cpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */
#include "Screen.hpp"
#include "ScreenObj.hpp"

using std::cout;
using std::endl;
using std::string;

void Screen::print() const {
		cout << '|' + string(weight, '-') + '|' << endl;//最上面
		for (const auto &y : id_map){ // 先x，后高
//			int x_yi = 0;
			cout << '|';//每行左边
			for (const auto &x : y){// 对x的每一个y，竖线！

				if (x == 0){
					cout << ' ';
				}
				else {
					// ok
					cout << contents.at(x)->get_figure();

					/*{
							cout << time_now()
							<< "id:" << contents.at(x)->id
							<< "x:" << contents.at(x)->x
							<< "y:" << contents.at(x)->y
							<< "has_moved:"
							<< contents.at(x)->get_has_moved();
//					}*/
							contents.at(x)->reset_has_moved();//打印后唤醒
				}
			}// inner one char end
			cout << "|\n";//每行右边
		}// outer
		cout << '|' + string(weight, '-') + '|' << endl;//最下面

//		is_ready = false;//打印一次后变为false,放在 cv那里更ok
}

// 2 - 1
void Screen::add_obj(shared_ptr<ScreenObj> obj) {

	if (!is_in_screen(obj)) {
		std::cerr << "out of range!\n";
		return;
	}
	else if (id_map.at(obj->y).at(obj->x) != 0){
		std::cerr << "this point has been used\n";
		return;
	}
	// 添加信息
	contents.insert({obj->id, obj});
	id_map.at(obj->y).at(obj->x) = obj->id;
}
// 2 - 2
void Screen::remove_obj(int id_) {
	auto obj = contents[id_];
	id_map.at(obj->y).at(obj->x) = 0;
	contents.erase(id_);
}
bool Screen::is_in_screen(shared_ptr<ScreenObj> obj) const {
	return (obj->x >= 0 && obj->x < weight)
			&& (obj->y >= 0 && obj-> y < height);
}
shared_ptr<ScreenObj> Screen::get_obj(int id_){
		if (contents.at(id_) == 0){
			std::cerr << "null obj!\n";
			return nullptr;
		}
		return contents.at(id_);
	}
