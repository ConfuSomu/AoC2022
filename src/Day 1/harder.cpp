#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>

// very undescriptive class and member names, sorry (i haven't done any coding in ages) :ppone:
class CaloriesContainer {
    std::vector<int> calorie_sums;

    void remove_smallest() {
        // Remove the smallest sum stored
        struct {
            std::vector<int>::iterator element;
            int value = 0;
        } smallest;

        for (std::vector<int>::iterator it = calorie_sums.begin(); it != calorie_sums.end(); ) {
            if (smallest.value > *it) {
                smallest.value = *it;
                smallest.element = it++;
            }
        }
        calorie_sums.erase(smallest.element);

        //if (calorie_sums.size() >= 3)
        //    throw;
    }

public:
    void add_sum(int input_sum) {
        if (calorie_sums.size() < 3) {
            calorie_sums.push_back(input_sum);
            return;
        }

        // Add the input sum if it's any bigger than the current stored ones (i guess i could also use std::for_each?)
        for (int stored_sum : calorie_sums) {
            if (input_sum >= stored_sum) {
                calorie_sums.push_back(input_sum);
            }
        }

        if (calorie_sums.size() <= 3)
            return;

        remove_smallest();
    }

    int get_sum() {
        return std::accumulate(calorie_sums.begin(), calorie_sums.end(), 0);
    }
};

std::ifstream input_f("src/Day 1/input");

int main(int argc, char** argv) {
    CaloriesContainer biggest_calories;

    for (std::string line; std::getline(input_f, line); ) {
        static int current_addition = 0;

        if (not line.empty()) {
            std::istringstream line_strm(line);
            int number;
            line_strm >> number;
            current_addition += number;
        } else {
            biggest_calories.add_sum(current_addition);
            current_addition = 0;
        }
    }
    std::cout << "The 3 elves with the most Calories have " << biggest_calories.get_sum() << " Calories in total" << std::endl;
    return 0;
}
