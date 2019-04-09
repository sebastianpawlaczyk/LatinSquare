//
// Created by seba on 10.04.19.
//

#include "AlgorithmHelper.hpp"

namespace latinSquare
{
namespace latin
{

int AlgorithmHelper::getRow(int index, int sideOfWholeSquare)
{
	return index / (sideOfWholeSquare - 1) + 1; // how many number is in the row
}

int AlgorithmHelper::getColumn(int index, int sideOfWholeSquare)
{
	return index % (sideOfWholeSquare - 1) + 1; // how many number is in the row
}

int AlgorithmHelper::getIndex(int row, int column, int sideOfSquare)
{
	return (row - 1) * (sideOfSquare - 1) + column - 1;
}

}  // namespace latin
}  // namespace latinSquare
