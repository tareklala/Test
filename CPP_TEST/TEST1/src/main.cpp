#include <iostream>
#include "Line.h"
#include "utils.h"


int main() {
    int length = 20;
    int max = 100;
    std::vector<int> randomVector = Line::generateRandomLineSample(length, max);

    Line::LineSample lineSample(randomVector);

    std::pair<std::vector<int>, std::vector<int>> splitVector = lineSample.SplitVector();
    std::vector<int> top10Percent = lineSample.GetTop10Percent();
    splitVector.first = top10Percent;

    std::cout << "Random Vector: ";
    for (int num : randomVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "SampleLine vector object: ";
    lineSample.PrintLine();

    std::cout << "First part of the pair: ";
    for (int num : splitVector.first) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Second part of the pair: ";
    for (int num : splitVector.second) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}