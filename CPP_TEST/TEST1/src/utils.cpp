
#include <vector>
#include <random>
#include "utils.h"


namespace Line {
    std::vector<int> generateRandomLineSample(int length, int max) {
        std::vector<int> sample;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, max);

        for (int i = 0; i < length; ++i) {
            sample.push_back(dis(gen));
        }

        return sample;
    }
}
