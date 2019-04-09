// Created by seba on 10.04.19.

#ifndef LATINSQUARE_ALGORITHMHELPER_HPP
#define LATINSQUARE_ALGORITHMHELPER_HPP

namespace latinSquare
{
namespace latin
{

class AlgorithmHelper
{
public:
	AlgorithmHelper() = default;

	int getRow(int index, int sideOfWholeSquare);
	int getColumn(int index, int sideOfWholeSquare);
	int getIndex(int row, int column, int sideOfSquare);
};

}  // namespace latin
}  // namespace latinSquare

#endif //LATINSQUARE_ALGORITHMHELPER_HPP
