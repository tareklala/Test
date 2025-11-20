#include <vector>
#include "Line.h"

#include <algorithm>
#include <iostream>

namespace Line
{
    LineSample::LineSample() {}

    LineSample::LineSample(std::vector<int> other) : line_vector(other) {}

    std::pair<std::vector<int>, std::vector<int>> LineSample::SplitVector() const {
        size_t const half_size = line_vector.size() / 2;
        std::vector<int> first_half(line_vector.begin(), line_vector.begin() + half_size);
        std::vector<int> second_half(line_vector.begin() + half_size, line_vector.end());
        return std::make_pair(first_half, second_half);
    }

    std::vector<int> LineSample::GetTop10Percent() const {
        std::vector<int> sorted_vector = line_vector;
        std::sort(sorted_vector.begin(), sorted_vector.end(), std::greater<int>());
        size_t top_10_percent_size = sorted_vector.size() / 10;
        return std::vector<int>(sorted_vector.begin(), sorted_vector.begin() + top_10_percent_size);
    }

    LineSample& LineSample::operator=(const LineSample& other) {
        if (this != &other) {
            line_vector = other.line_vector;
        }
        return *this;
    }

    void LineSample::InsertValue(int value) {
        line_vector.push_back(value);
    }

    void LineSample::PrintLine() {
        for (const int& value : line_vector) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    LineSample::~LineSample() {}
}