#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::ifstream input_f("src/Day 2/input");

enum Shape {
    ROCK,
    PAPER,
    SCISSORS
};

int main(int argc, char** argv) {
    int score = 0;

    for (std::string line; std::getline(input_f, line); ) {
        std::istringstream stream(line);
        char opponent_move_c, your_move;
        stream >> opponent_move >> your_move;
        switch (your_move) {
            case 'X':

        }
    }
    std::cout << "The total score is " << score << std::endl;
    return 0;
}
