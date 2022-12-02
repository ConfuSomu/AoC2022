#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::ifstream input_f("src/Day 2/input");

int calculate_score(char opponent_move, char your_strat) {
    // Choose what you have to do
    int your_move;
    switch (your_strat) {
        case 'X': // Lose
            switch (opponent_move) {
                case 'A': // Rock
                    your_move = 'Z'; break;
                case 'B': // Paper
                    your_move = 'X'; break;
                case 'C': // Scissors
                    your_move = 'Y'; break;
            } break;
        case 'Y': // Draw
            your_move = (opponent_move - 'A') + 'X'; break;
        case 'Z': // Win
            switch (opponent_move) {
                case 'A': // Rock
                    your_move = 'Y'; break;
                case 'B': // Paper
                    your_move = 'Z'; break;
                case 'C': // Scissors
                    your_move = 'X'; break;
            } break;
    }

    // Points for outcome of round
    int outcome_points;
    signed int outcome = (opponent_move - 'A' + 1) - (your_move - 'X' + 1);
    if (outcome == 0) { //Draw
        outcome_points = 3;
    } else {
        if (opponent_move == 'A' and your_move == 'Y' or // Rock vs paper
            opponent_move == 'B' and your_move == 'Z' or // Paper vs Scissors
            opponent_move == 'C' and your_move == 'X'    // Scissors vs Rock
        ) // Win
            outcome_points = 6;
        else // Lose
            outcome_points = 0;
    }

    return outcome_points + (your_move - 'X' + 1);
}

int main(int argc, char** argv) {
    int score = 0;

    for (std::string line; std::getline(input_f, line); ) {
        std::istringstream stream(line);
        char opponent_move, your_strat;
        stream >> opponent_move >> your_strat;
        score += calculate_score(opponent_move, your_strat);
    }
    std::cout << "Your total score is " << score << std::endl;
    return 0;
}
