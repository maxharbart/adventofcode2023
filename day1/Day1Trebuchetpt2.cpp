#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>

int main() {

    std::vector<std::string> numbers{
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

    std::vector<std::string> values;
    std::string input;

    std::ifstream inputFile("adventofcode.com_2023_day_1_input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 0;
    }

        while (getline(inputFile, input)) {
        values.push_back(input);
    }

        inputFile.close();


    int result = 0;

    auto findFirst = [&numbers](std::string& str) -> char {
        for (size_t i = 0; i < str.size(); i++) {
            if (isdigit(str[i])) {
                return str[i] - '0';
            }

            for (size_t j = 0; j < numbers.size(); j++) {
                if (str.size() - i >= numbers[j].size() && !memcmp(&str[i], numbers[j].data(), numbers[j].size())) {
                    return j+1;
                }
            }
        }
    };

    auto findLast = [&numbers](std::string& str) -> char {
        for (size_t i = str.size() - 1; i >= 0; i--) {
            if (isdigit(str[i])) {
                return str[i] - '0';
            }

            for (size_t j = 0; j < numbers.size(); ++j) {
                if (str.size() - i >= numbers[j].size() && !memcmp(&str[i], numbers[j].data(), numbers[j].size())) {
                    return j+1;
                }
            }
        }
    };

    for (auto line: values) {
        result += std::stoi(std::string {char('0' + findFirst(line)), char('0' + findLast(line))});
    }


    std::cout << "Result: " << result << std::endl;

    return 0;
}
