#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

int main()
{
    std::vector<std::string> seeds;
    std::vector<std::vector<std::string>> seed_to_soil;
    std::vector<std::vector<std::string>> soil_to_fertilizer;
    std::vector<std::vector<std::string>> fertilizer_to_water;
    std::vector<std::vector<std::string>> water_to_light;
    std::vector<std::vector<std::string>> light_to_temperature;
    std::vector<std::vector<std::string>> temperature_to_humidity;
    std::vector<std::vector<std::string>> humidity_to_location;

    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        inputFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line) && !line.empty())
    {
        std::istringstream seedsStream(line);
        std::string seedValue;
        while (seedsStream >> seedValue)
        {
            seeds.push_back(seedValue);
        }
    }
    seeds.erase(seeds.begin());

    std::vector<std::string> seed_to_soil_temp;
    while (std::getline(inputFile, line) && !line.empty())
    {
        std::istringstream mapStream(line);
        std::string mapValue;
        while (mapStream >> mapValue)
        {
            seed_to_soil_temp.push_back(mapValue);
        }
    }

    seed_to_soil_temp.erase(seed_to_soil_temp.begin(), seed_to_soil_temp.begin() + 2);

    for (size_t i = 0; i < seed_to_soil_temp.size(); i += 3)
    {
        std::vector<std::string> temp;
        temp.push_back(seed_to_soil_temp[i]);
        temp.push_back(seed_to_soil_temp[i + 1]);
        temp.push_back(seed_to_soil_temp[i + 2]);

        seed_to_soil.push_back(temp);
    }

    std::vector<std::string> soil_to_fertilizer_temp;
    while (std::getline(inputFile, line) && !line.empty())
    {
        std::istringstream mapStream(line);
        std::string mapValue;
        while (mapStream >> mapValue)
        {
            soil_to_fertilizer_temp.push_back(mapValue);
        }
    }

    soil_to_fertilizer_temp.erase(soil_to_fertilizer_temp.begin());
    soil_to_fertilizer_temp.erase(soil_to_fertilizer_temp.begin());

    for (size_t i = 0; i < soil_to_fertilizer_temp.size(); i += 3)
    {

        std::vector<std::string> temp;
        temp.push_back(soil_to_fertilizer_temp[i]);
        temp.push_back(soil_to_fertilizer_temp[i + 1]);
        temp.push_back(soil_to_fertilizer_temp[i + 2]);

        soil_to_fertilizer.push_back(temp);
    }

    std::vector<std::string> fertilizer_to_water_temp;
    while (std::getline(inputFile, line) && !line.empty())
    {
        std::istringstream mapStream(line);
        std::string mapValue;
        while (mapStream >> mapValue)
        {
            fertilizer_to_water_temp.push_back(mapValue);
        }
    }

    fertilizer_to_water_temp.erase(fertilizer_to_water_temp.begin());
    fertilizer_to_water_temp.erase(fertilizer_to_water_temp.begin());

    for (size_t i = 0; i < fertilizer_to_water_temp.size(); i += 3)
    {

        std::vector<std::string> temp;
        temp.push_back(fertilizer_to_water_temp[i]);
        temp.push_back(fertilizer_to_water_temp[i + 1]);
        temp.push_back(fertilizer_to_water_temp[i + 2]);

        fertilizer_to_water.push_back(temp);
    }

    std::vector<std::string> water_to_light_temp;
    while (std::getline(inputFile, line) && !line.empty())
    {
        std::istringstream mapStream(line);
        std::string mapValue;
        while (mapStream >> mapValue)
        {
            water_to_light_temp.push_back(mapValue);
        }
    }

    water_to_light_temp.erase(water_to_light_temp.begin());
    water_to_light_temp.erase(water_to_light_temp.begin());

    for (size_t i = 0; i < water_to_light_temp.size(); i += 3)
    {

        std::vector<std::string> temp;
        temp.push_back(water_to_light_temp[i]);
        temp.push_back(water_to_light_temp[i + 1]);
        temp.push_back(water_to_light_temp[i + 2]);

        water_to_light.push_back(temp);
    }

    std::vector<std::string> light_to_temperature_temp;
    while (std::getline(inputFile, line) && !line.empty())
    {
        std::istringstream mapStream(line);
        std::string mapValue;
        while (mapStream >> mapValue)
        {
            light_to_temperature_temp.push_back(mapValue);
        }
    }

    light_to_temperature_temp.erase(light_to_temperature_temp.begin());
    light_to_temperature_temp.erase(light_to_temperature_temp.begin());

    for (size_t i = 0; i < light_to_temperature_temp.size(); i += 3)
    {

        std::vector<std::string> temp;
        temp.push_back(light_to_temperature_temp[i]);
        temp.push_back(light_to_temperature_temp[i + 1]);
        temp.push_back(light_to_temperature_temp[i + 2]);

        light_to_temperature.push_back(temp);
    }

    std::vector<std::string> temperature_to_humidity_temp;
    while (std::getline(inputFile, line) && !line.empty())
    {
        std::istringstream mapStream(line);
        std::string mapValue;
        while (mapStream >> mapValue)
        {
            temperature_to_humidity_temp.push_back(mapValue);
        }
    }

    temperature_to_humidity_temp.erase(temperature_to_humidity_temp.begin());
    temperature_to_humidity_temp.erase(temperature_to_humidity_temp.begin());

    for (size_t i = 0; i < temperature_to_humidity_temp.size(); i += 3)
    {

        std::vector<std::string> temp;
        temp.push_back(temperature_to_humidity_temp[i]);
        temp.push_back(temperature_to_humidity_temp[i + 1]);
        temp.push_back(temperature_to_humidity_temp[i + 2]);

        temperature_to_humidity.push_back(temp);
    }

    std::vector<std::string> humidity_to_location_temp;
    while (std::getline(inputFile, line) && !line.empty())
    {
        std::istringstream mapStream(line);
        std::string mapValue;
        while (mapStream >> mapValue)
        {
            humidity_to_location_temp.push_back(mapValue);
        }
    }

    humidity_to_location_temp.erase(humidity_to_location_temp.begin());
    humidity_to_location_temp.erase(humidity_to_location_temp.begin());

    for (size_t i = 0; i < humidity_to_location_temp.size(); i += 3)
    {

        std::vector<std::string> temp;
        temp.push_back(humidity_to_location_temp[i]);
        temp.push_back(humidity_to_location_temp[i + 1]);
        temp.push_back(humidity_to_location_temp[i + 2]);

        humidity_to_location.push_back(temp);
    }

    inputFile.close();

    std::vector<std::vector<std::vector<std::string>>> all_vectors;
    all_vectors.push_back(seed_to_soil);
    all_vectors.push_back(soil_to_fertilizer);
    all_vectors.push_back(fertilizer_to_water);
    all_vectors.push_back(water_to_light);
    all_vectors.push_back(light_to_temperature);
    all_vectors.push_back(temperature_to_humidity);
    all_vectors.push_back(humidity_to_location);

    int64_t curr_num;
    std::vector<int64_t> locations;

    for (auto &seed : seeds)
    {
        int64_t curr_num = std::stoll(seed);
        for (auto &vector : all_vectors)
        {
            for (auto &x : vector)
            {

                if (std::stoll(x[1]) == curr_num)
                {
                    curr_num = std::stoll(x[0]);
                    break;
                }

                else
                {
                    if ((curr_num > (std::stoll(x[1]))) && (curr_num <= (std::stoll(x[1]) + std::stoll(x[2]))))
                    {
                        curr_num += std::stoll(x[0]);
                        curr_num -= std::stoll(x[1]);
                        break;
                    }
                }
            }
        }
        locations.push_back(curr_num);
    }

    std::cout << *(std::min_element(locations.begin(), locations.end())) << std::endl;
}