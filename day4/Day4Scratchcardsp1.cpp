#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

int main()
{
    std::vector<std::vector<std::string>> winning_numbers;
    std::vector<std::vector<std::string>> have_numbers;
    std::string input;

    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return 0;
    }

    while (getline(inputFile, input))
    {
        auto semicolon = input.find(':');
        auto divider = input.find('|');

        std::string winning = input.substr(semicolon + 2, divider - 9);
        std::string have = input.substr(divider + 2);

        std::vector<std::string> winning_vector;
        std::istringstream iss(winning);

        do
        {
            std::string word;
            iss >> word;
            winning_vector.push_back(word);
        } while (iss);

        std::vector<std::string> have_vector;
        std::istringstream iss2(have);

        do
        {
            std::string word;
            iss2 >> word; 
            have_vector.push_back(word);
        } while (iss2);

        winning_numbers.push_back(winning_vector);
        have_numbers.push_back(have_vector);
    }

    inputFile.close(); 

    int total_points = 0;

    for (size_t i = 0; i < winning_numbers.size(); i++) {
        int curr_points_num = 0;
        int points = 0;
        for (const auto& elem: have_numbers[i]) {
            
            if ((std::find(winning_numbers[i].begin(), winning_numbers[i].end(), elem) != winning_numbers[i].end()) && (!empty(elem))) {
                
                curr_points_num < 1 ? points++ : points*=2;
                curr_points_num++;
            }
            
        }
        total_points += points;
    }

    std::cout << "total points: " << total_points << std::endl;
}
