// Created by seba on 10.04.19.

#ifndef SRC_LATIN_LATINGSQUAREALGORITHM_HPP
#define SRC_LATIN_LATINGSQUAREALGORITHM_HPP

#include <memory>

#include "AlgorithmHelper.hpp"
#include "../fwd.hpp"

namespace latinSquare
{
namespace latin
{

class LatingSquareAlgorithm
{
public:
	LatingSquareAlgorithm();

	void computeBacktracking(int index, src::latin_square latinSquare, int sideOfSquare, std::vector<std::vector<int>> occupiedPlaces);
	void computeForwardChecking(int index, src::latin_square latinSquare, int sideOfSquare, std::vector<std::vector<int>> occupiedPlaces);

	std::string toString(src::latin_square latinSquare, int sideOfWholeSquare);

	// only for forward checking
	std::vector<std::vector<int>> initOccupiedPlaces(int sideOfSquare);

	static bool found;

private:
	bool isLatinSquareValid(int index, const src::latin_square& latinSquare, int sideOfWholeSquare);

	std::shared_ptr<AlgorithmHelper> helper_;
};

}  // namespace latin
}  // namespace latinSquare

#endif //SRC_LATIN_LATINGSQUAREALGORITHM_HPP
