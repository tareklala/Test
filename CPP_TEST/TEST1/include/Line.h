#pragma once

#include <stdexcept>
#include <vector>

namespace Line
{   
    /**
     * @class LineSample
     * @brief A class to represent a sample line with various operations.
     * 
     * The LineSample class provides functionalities to manage a vector of integers,
     * including splitting the vector, retrieving the top 10 percent of values, 
     * inserting values, and printing the line.
     */
    class LineSample{
        public:

            /**
             * @brief Default constructor for LineSample.
             */
            LineSample();

            /**
             * @brief Parameterized constructor for LineSample.
             * @param other A vector of integers to initialize the line_vector.
             */
            LineSample(std::vector<int> other);

            /**
             * @brief Splits the line_vector into two vectors.
             * @return A pair of vectors, where the first vector contains the first half 
             *         and the second vector contains the second half of the original vector.
             */
            std::pair<std::vector<int>, std::vector<int>> SplitVector() const;

            /**
             * @brief Retrieves the top 10 percent of values from the line_vector.
             * @return A vector containing the top 10 percent of values.
             */
            std::vector<int> GetTop10Percent() const;

            /**
             * @brief Assignment operator for LineSample.
             * @param other The LineSample object to be assigned.
             * @return A reference to the assigned LineSample object.
             */
            LineSample& operator=(const LineSample& other);

            /**
             * @brief Inserts a value into the line_vector.
             * @param value The integer value to be inserted.
             */
            void InsertValue(int value);

            /**
             * @brief Prints the contents of the line_vector.
             */
            void PrintLine();

            /**
             * @brief Destructor for LineSample.
             */
            ~LineSample();

        private:
            std::vector<int> line_vector;
            static int instance_count;
    };    

    template <typename T>
    T GetLastValue(const std::vector<T>& values) {
        if (values.empty()) {
            throw std::out_of_range("Line::GetLastValue received an empty container");
        }
        return values.back();
    }
}