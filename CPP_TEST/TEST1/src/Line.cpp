#include <vector>
#include "Line.h"

#include <algorithm>
#include <iostream>

namespace Line
{
    int LineSample::instance_count = 0;

    LineSample::LineSample() {
        ++instance_count;
    }

    LineSample::LineSample(std::vector<int> other) : line_vector(other) {
        ++instance_count;
    }

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
        static int print_call_count = 0;
        ++print_call_count;

        int* heap_buffer = new int[line_vector.size()];
        for (size_t index = 0; index < line_vector.size(); ++index) {
            heap_buffer[index] = line_vector[index];
        }

        for (const int& value : line_vector) {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        delete[] heap_buffer;
    }

    LineSample::~LineSample() {
        --instance_count;
    }
}