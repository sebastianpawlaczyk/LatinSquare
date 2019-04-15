// Created by seba on 10.04.19.

#include "LifeStarter.hpp"

#include <iostream>
#include <ctime>

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

	auto a = latinAlgorithm.initOccupiedPlaces(sideOfSquare);

	clock_t begin = clock();
	latinAlgorithm.computeBacktracking(-1, latinSquare, sideOfSquare, a);
	clock_t end = clock();
	double elapsed_secs_1 = double(end - begin) / CLOCKS_PER_SEC;

	latinSquare::latin::LatingSquareAlgorithm::found = false;

	begin = clock();
	latinAlgorithm.computeForwardChecking(-1, latinSquare, sideOfSquare, a);
	end = clock();
	double elapsed_secs_2 = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "backtracking - forwardChecking = " << elapsed_secs_1 - elapsed_secs_2;
}

}  // namespace sdk
}  // namespace latinSquare
