/*
 * src.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: zhaoyunpeng
 */

#include "src.hpp"

std::string time_now() {
	static auto start = std::chrono::steady_clock::now();
	std::chrono::duration<double> d =
			std::chrono::steady_clock::now() - start;
	return "[" + std::to_string(d.count()) + "s]";

}

