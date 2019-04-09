// Created by seba on 10.04.19.

#include "LifeStarter.hpp"

#include <iostream>

#include "../latin/LatingSquareAlgorithm.hpp"
#include "../fwd.hpp"

namespace latinSquare
{
namespace sdk
{

LifeStarter::LifeStarter()
{}

void LifeStarter::setUpEnvAndStart(int sideOfSquare)
{
	if (sideOfSquare <= 1)
	{
		std::cout << "OAM_ASSERT" << std::endl;
		return;
	}

	int size = (sideOfSquare - 1) * (sideOfSquare - 1);
	src::latin_square latinSquare(size);
	latinSquare::latin::LatingSquareAlgorithm latinAlgorithm;
	latinAlgorithm.compute(-1, latinSquare, sideOfSquare);
}

}  // namespace sdk
}  // namespace latinSquare
