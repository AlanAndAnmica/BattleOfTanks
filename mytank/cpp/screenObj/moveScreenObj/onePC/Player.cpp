/*
 * Player.cpp
 *
 *  Created on: Dec 31, 2018
 *      Author: zhaoyunpeng
 */
#include "Player.hpp"

/*
void Player::ready_for_move() {//这个也需要后台运行
		char c;
		while (	!stage->is_ended &&
				std::cin >> c){
			switch (c) {
			case 'w':
				set_figure('^');
				set_direction(MoveDire::UP);
							break;
			case 's':
				set_figure('v');
				set_direction(MoveDire::DOWN);
							break;
			case 'a':
				set_figure('<');
				set_direction(MoveDire::LEFT);
							break;
			case 'd':
				set_figure('>');
				set_direction(MoveDire::RIGHT);
							break;
			default:
				continue;//为防止中断，请重新读入
				break;
			}//end switch
			if (!if_change_d) {
				move();
			}
		}//end while
	}
*/

void ready_for_move(shared_ptr<Player> pl) {//这个也需要后台运行
		std::string c;
		while (	!pl->stage->is_ended //这里如果判断失败，就退出输入了。。
//				!pl->has_moved &&//还没有移动// 如果失败，就退出了，
				//然而需要的是暂停
//				&& std::cin >> c//也许是这里的原因
				){
			//has_moved的暂停：
			if (!pl->has_moved) {
				std::unique_lock<std::mutex> lk(pl->stage->cv_m);
				pl->stage->cv.wait(lk, [&]{return !pl->get_has_moved();});
			}//完成暂停？：OK ->遇到新问题：无法处理一次打印间连续的两次输入
			// 这里没有
			std::cin >> c;

			switch (c[0]) {
			case 'w':
				pl->set_figure('^');
				pl->set_direction(MoveDire::DOWN);
							break;
			case 's':
				pl->set_figure('v');
				pl->set_direction(MoveDire::UP);
							break;
			case 'a':
				pl->set_figure('<');
				pl->set_direction(MoveDire::LEFT);
							break;
			case 'd':
				pl->set_figure('>');
				pl->set_direction(MoveDire::RIGHT);
							break;
			default:
				continue;//为防止中断，请重新读入
				break;
			}//end switch
			// 测试：
				/*{
				{
					std::cout << time_now()
							<< "id:" << pl->id
							<< "x:" << pl->x
							<< "y:" << pl->y
							<< "figure:" << pl->get_figure()
							<< "has_moved:" << pl->has_moved
							<< std::endl;
//				}*/
//			pl->has_moved = true;//已经移动了，然后由manage改为false
			if (!pl->if_change_d) {
				pl->move();
			}//放里面？！已经是里面了.
			std::this_thread::sleep_for(chrono::milliseconds(500));
			// 测试：
							/*{
//							{
//								std::this_thread::sleep_for(chrono::seconds(1));
								std::cout << time_now()
										<< "id:" << pl->id
										<< "x:" << pl->x
										<< "y:" << pl->y
										<< "figure:" << pl->get_figure()
										<< "has_moved:" << pl->has_moved
										<< std::endl;
//							}*/

		}//end while
	}

