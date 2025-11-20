#pragma once

#include <vector>
#include <random>


namespace Line {
    /**
     * @brief Generates a random line sample.
     * @param length The length of the line sample.
     * @param max The maximum value for the random numbers.
     * @return A vector of random integers.
     */
    std::vector<int> generateRandomLineSample(int length, int max);
}


