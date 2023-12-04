#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>

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



    int total_cards = 0;

    std::vector<int> counts_for_cards;

    

    for (size_t i = 0; i < winning_numbers.size(); i++) {
        int count_for_card = 0;
        for (const auto& elem: have_numbers[i]) {
            
            if ((std::find(winning_numbers[i].begin(), winning_numbers[i].end(), elem) != winning_numbers[i].end()) && (!empty(elem))) {
                
                count_for_card++;

            }
            
           
        }
        // total_points += points;
        counts_for_cards.push_back(count_for_card);
    }


    int result = 0;

    std::vector<int> count_results(counts_for_cards.size(), 1);
    

    for (int i = 0; i < count_results.size(); i++) {
        for (int j = 1; j <= counts_for_cards[i]; j++) {
            count_results[i+j] += count_results[i];
            
        }
    }

    int sum = 0;

    for (auto x: count_results) {
        sum += x;
    }

    std::cout << sum << std::endl;
}
