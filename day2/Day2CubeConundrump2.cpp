#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

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

    for (auto x : results)
    {
        int max_green = *(std::max_element(x.second["green"].begin(), x.second["green"].end()));
        int max_red = *(std::max_element(x.second["red"].begin(), x.second["red"].end()));
        int max_blue = *(std::max_element(x.second["blue"].begin(), x.second["blue"].end()));

        result += max_green * max_blue * max_red;
    }

    std::cout << "result is: " << result << std::endl;
}
