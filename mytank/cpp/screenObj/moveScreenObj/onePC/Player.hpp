/*
 * Player.hpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef SCREENOBJ_OnePC_PLAYER_HPP_
#define SCREENOBJ_OnePC_PLAYER_HPP_

//#include "src.hpp"

//#include <string>

#include "../OnePC.hpp"
//#include "."
void ready_for_move(shared_ptr<Player> pl);

class OnePC;
class Player : public OnePC {
	friend void ready_for_move(shared_ptr<Player> pl);

private:
	std::string name;

protected:


public:
	using OnePC::OnePC;

	// 1、 需要被future给包含的函数
	void ready_for_move() override {}// OK 包括检验

};



#endif /* SCREENOBJ_OnePC_PLAYER_HPP_ */
