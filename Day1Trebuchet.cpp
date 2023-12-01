#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::string> values;
    int result = 0;
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

        for (auto i : values) {
        std::string str_number;

        for (auto ch : i) {
            if (isdigit(ch)) {
                str_number.push_back(ch);
                break;
            }
        }

        std::reverse(i.begin(), i.end());
        for (auto ch : i) {
            if (isdigit(ch)) {
                str_number.push_back(ch);
                break;
            }
        }


        result += !str_number.empty() ? std::stoi(str_number) : 0;
        std::cout << "number is " << result << std::endl;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
