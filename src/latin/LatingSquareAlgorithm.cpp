//
// Created by seba on 10.04.19.
//

#include <iostream>
#include <sstream>
#include <memory>

#include "LatingSquareAlgorithm.hpp"

namespace latinSquare
{
namespace latin
{

LatingSquareAlgorithm::LatingSquareAlgorithm()
{
	helper_ = std::make_shared<AlgorithmHelper>();
}

bool LatingSquareAlgorithm::isLatinSquareValid(int index, src::latin_square latinSquare, int sideOfWholeSquare)
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

void LatingSquareAlgorithm::compute(int index, src::latin_square latinSquare, int sideOfSquare)
{
	if (index < 0 || isLatinSquareValid(index, latinSquare, sideOfSquare))
	{
		if (index == latinSquare.size() - 1)
		{
			std::cout << toString(latinSquare, sideOfSquare);
		}

		else
		{
			for (int i = 1; i <= sideOfSquare; i++)
			{
				latinSquare[index + 1] = i;
				compute(index + 1, latinSquare, sideOfSquare);
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

}  // namespace latin
}  // namespace latinSquare
