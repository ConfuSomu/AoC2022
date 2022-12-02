#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// very undescriptive class and member names, sorry (i haven't done any coding in ages) :ppone:
class TopCaloriesContainer {
    int calorie_sums[3] = {0,0,0}; // easier without an std::vector

public:
    void add_sum(int input_sum) {
        // Add the input sum if it's any bigger than the current stored ones (i guess i could also use std::for_each?)
        struct {
            int index = 0;
            int value = 0;
        } smallest;

        for (int i = 0; i < sizeof(calorie_sums)/sizeof(calorie_sums[0]); ++i) {
            if (i == 0 or smallest.value >= calorie_sums[i]) {
                smallest.value = calorie_sums[i];
                smallest.index = i;
            }
        }
        if (smallest.value < input_sum)
            calorie_sums[smallest.index] = input_sum;
    }

    int get_sum() {
        return calorie_sums[0] + calorie_sums[1] + calorie_sums[2];
    }
};

std::ifstream input_f("src/Day 1/input");

int main(int argc, char** argv) {
    TopCaloriesContainer biggest_calories;

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
