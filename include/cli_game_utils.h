#ifndef CLI_GAME_UTILS_H
#define CLI_GAME_UTILS_H

#include <string>
#include <map>
#include <iostream>
#include <vector>

enum class Color { GREEN, RED, BLUE, DEFAULT };

void printColored(const std::string& text, Color color);
void printStat(const std::string& label, int value, Color color);
void clearInput();
int cliSelect(const std::vector<std::string>& options);

#endif
