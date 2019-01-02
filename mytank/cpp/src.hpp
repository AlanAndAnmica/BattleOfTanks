/*
 * src.hpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaoyunpeng
 */

#ifndef SRC_HPP_
#define SRC_HPP_

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <memory>


#include <condition_variable>
#include <mutex>
#include <chrono>
#include <future>

class Screen;

class ScreenObj;
class MoveScreenObj;
class LiveObj;
class OnePC;
class Player;
class Friend;
class Enemy;

class Game;
class GameMg;

enum class KindObj {ENEMY, FRIEND, PLAYER, MAPOBJ};
enum class MoveDire {UP, DOWN, LEFT, RIGHT};

std::string time_now();

/*
#include "Screen.hpp"
#include "ScreenObj.hpp"
#include "LiveObj.hpp"
#include "screenObj/MoveScreenObj.hpp"
#include "screenObj/moveScreenObj/OnePC.hpp"
#include "screenObj/moveScreenObj/onePC/Enemy.hpp"
#include "screenObj/moveScreenObj/onePC/Friend.hpp"
#include "screenObj/moveScreenObj/onePC/Player.hpp"
*/



#endif /* SRC_HPP_ */
