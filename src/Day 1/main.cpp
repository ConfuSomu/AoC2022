#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::ifstream input_f("src/Day 1/input");

int main(int argc, char** argv) {
    int biggest_addition = 0;

    // All of these line reading routine is from https://stackoverflow.com/a/7868998
    for (std::string line; std::getline(input_f, line); ) {
        int current_addition;

        if (not line.empty()) {
            std::istringstream stream(line);
            int number;
            stream >> number; // wtf C++'s >> operator makes no sense
            current_addition += number;
        } else {
            if (current_addition > biggest_addition)
                biggest_addition = current_addition;

            current_addition = 0;
        }
    }
    std::cout << "The elf with the most Calories has " << biggest_addition << " Calories" << std::endl;
    return 0;
}
