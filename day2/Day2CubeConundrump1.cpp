#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

// only 12 red cubes, 13 green cubes, and 14 blue cubes

int main()
{
    std::vector<std::string> values;
    std::string input;

    std::ifstream inputFile("adventofcode.com_2023_day_2_input.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return 0;
    }

    while (getline(inputFile, input))
    {
        values.push_back(input);
    }

    inputFile.close();

    int result = 0;

    std::vector<std::pair<int, std::map<std::string, std::vector<int>>>> results;

    for (auto item : values)
    {

        auto semicolon = item.find(':');
        auto whitespace = item.find(' ');

        std::map<std::string, std::vector<int>> res;

        int id = std::stoi(item.substr(whitespace, semicolon - 4));

        std::string cubes = item.substr(semicolon + 2);

        std::istringstream iss(cubes);

        std::string section;

        while (std::getline(iss, section, ';'))
        {
            std::istringstream sectionStream(section);
            std::string quantity;
            std::string color;

            while (sectionStream >> quantity >> color)
            {
                if (color[color.size() - 1] == ',')
                {
                    color.pop_back();
                }
                res[color].push_back(std::stoi(quantity));
            }
        }
        results.push_back(std::make_pair(id, res));
    }

    for (auto i : results)
    {
        bool is_game_valid = true;
        for (auto value : i.second["green"])
        {
            if (value > 13)
            {
                is_game_valid = false;
            }
        }

        if (is_game_valid)
        {
            for (auto value : i.second["blue"])
            {
                if (value > 14)
                {
                    is_game_valid = false;
                }
            }

            if (is_game_valid)
            {
                for (auto value : i.second["red"])
                {
                    if (value > 12)
                    {
                        is_game_valid = false;
                    }
                }

                if (is_game_valid)
                {
                    result += i.first;
                }
            }
        }

        std::cout << "sum of ids of possible games: " << result << std::endl;
    }
}
