//
// Created by seba on 10.04.19.
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include <memory>

#include "LatingSquareAlgorithm.hpp"

namespace latinSquare
{
namespace latin
{

bool LatingSquareAlgorithm::found = false;

LatingSquareAlgorithm::LatingSquareAlgorithm()
{
	helper_ = std::make_shared<AlgorithmHelper>();
}

bool LatingSquareAlgorithm::isLatinSquareValid(int index, const src::latin_square& latinSquare, int sideOfWholeSquare)
{
	//check with initial rows
	if (latinSquare[index] == helper_->getRow(index,sideOfWholeSquare) + 1)
	{
		return false;
	}

	//check with initial columns
	if (latinSquare[index] == helper_->getColumn(index,sideOfWholeSquare) + 1)
	{
		return false;
	}

	int nextIndex = 0;
	int rowToCompare;
	int columnToCompere;
	for (const auto& i : latinSquare)
	{
		rowToCompare = helper_->getRow(nextIndex, sideOfWholeSquare);
		columnToCompere = helper_->getColumn(nextIndex, sideOfWholeSquare);

		if (helper_->getRow(index, sideOfWholeSquare) == rowToCompare ||
			helper_->getColumn(index, sideOfWholeSquare) == helper_->getColumn(nextIndex, sideOfWholeSquare))
		{
			if (latinSquare[index] == latinSquare[helper_->getIndex(rowToCompare, columnToCompere, sideOfWholeSquare)] && index != nextIndex)
			{
				return false;
			}
		}
		nextIndex++;
	}
	return true;

}

void LatingSquareAlgorithm::computeBacktracking(int index, src::latin_square latinSquare, int sideOfSquare, std::vector<std::vector<int>> occupiedPlaces)
{
	if(found){return;}
	if (index < 0 || isLatinSquareValid(index, latinSquare, sideOfSquare))
	{
		if (index == latinSquare.size() - 1)
		{
			std::cout << toString(latinSquare, sideOfSquare);
			found = true;
		}

		else
		{
			for (int i = 1; i <= sideOfSquare; i++)
			{
				latinSquare[index + 1] = i;
				computeBacktracking(index + 1, latinSquare, sideOfSquare, occupiedPlaces);
			}
		}
	}
}

std::string LatingSquareAlgorithm::toString(src::latin_square latinSquare, int sideOfWholeSquare)
{
	std::ostringstream stream;
	int index = 0;

	//first row
	for (int row = 1; row <= sideOfWholeSquare; row++)
	{
		stream << row << " ";
	}
	stream << std::endl;

	//next rows
	for (int row = 2; row <= sideOfWholeSquare; row++)
	{
		stream << row << " ";
		for(int i = 1; i < sideOfWholeSquare; i++)
		{
			stream << latinSquare[index] << " ";
			index++;
		}
		stream << std::endl;
	}
	stream << std::endl;
	return stream.str();
}

std::vector<std::vector<int>> LatingSquareAlgorithm::initOccupiedPlaces(int sideOfSquare)
{
	int size = (sideOfSquare - 1) * (sideOfSquare - 1);
	std::vector<std::vector<int>> occupiedPlaces(size);

	for (int i = 0; i < size; i++)
	{
		std::vector<int> pom;
		for (int j = 1; j <= sideOfSquare; ++j)
		{
			if (j == helper_->getRow(i, sideOfSquare) + 1) continue;
			if (j == helper_->getColumn(i, sideOfSquare) + 1) continue;
			pom.push_back(j);
		}
		occupiedPlaces[i] = pom;
	}
	return occupiedPlaces;
}

void LatingSquareAlgorithm::computeForwardChecking(int index, src::latin_square latinSquare, int sideOfSquare, std::vector<std::vector<int>> occupiedPlaces)
{
	if(found){return;}
	if (index < 0 || isLatinSquareValid(index, latinSquare, sideOfSquare))
	{
		if (index == latinSquare.size() - 1)
		{
			std::cout << toString(latinSquare, sideOfSquare);
			found = true;
		}

		else
		{
			for (int i = 1; i <= sideOfSquare; i++)
			{
				for (int j = 0; j < occupiedPlaces.size(); j++)
				{
					auto& vec = occupiedPlaces[j];
					if (helper_->getRow(index + 1, sideOfSquare) == helper_->getRow(j, sideOfSquare) ||
						helper_->getColumn(index + 1, sideOfSquare) == helper_->getColumn(j, sideOfSquare))
					{
						vec.push_back(latinSquare[index + 1]);
					}
				}

				auto vec = occupiedPlaces[index + 1];
				if (std::find(vec.begin(), vec.end(), i) == vec.end())
				{
					continue;
				}

				for (int j = 0; j < occupiedPlaces.size(); j++)
				{
					auto& vec = occupiedPlaces[j];
					if (helper_->getRow(index + 1, sideOfSquare) == helper_->getRow(j, sideOfSquare) ||
						helper_->getColumn(index + 1, sideOfSquare) == helper_->getColumn(j, sideOfSquare))
					{
						vec.erase(std::remove(vec.begin(), vec.end(), i), vec.end());
					}
				}

				latinSquare[index + 1] = i;
				computeForwardChecking(index + 1, latinSquare, sideOfSquare, occupiedPlaces);
			}
		}
	}
}

}  // namespace latin
}  // namespace latinSquare
