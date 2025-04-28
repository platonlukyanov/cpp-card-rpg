#include <string>
#include <map>
#include <iostream>
#include "cli_game_utils.h"
#include <limits>
#include <vector>

void printColored(const std::string& text, Color color) {
    static const std::map<Color, std::string> codes {
        {Color::GREEN, "\033[32m"},
        {Color::RED, "\033[31m"},
        {Color::BLUE, "\033[34m"},
        {Color::DEFAULT, "\033[0m"}
    };
    std::cout << codes.at(color) << text << codes.at(Color::DEFAULT);
}

void printStat(const std::string& label, int value, Color color) {
    std::cout << " " << label << ": ";
    printColored(std::to_string(value), color);
    std::cout << std::endl;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int cliSelect(const std::vector<std::string>& options) {
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << " " << i + 1 << ") " << options[i] << std::endl;
    }

    while (true) {
        std::cout << "Enter number: ";
        size_t number;
        if (std::cin >> number && number >= 1 && number <= options.size()) {
            clearInput();
            return static_cast<int>(number) - 1;
        }
        clearInput();
        std::cout << "Invalid input, try again." << std::endl;
    }
}

