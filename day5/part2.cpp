#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <map>
#include <limits>

std::ifstream datafile;

std::vector<std::array<int64_t, 2>> seeds;

std::vector<std::array<int, 3>> seed_to_soil;
std::vector<std::array<int, 3>> soil_to_fertilizer;
std::vector<std::array<int, 3>> fertilizer_to_water;
std::vector<std::array<int, 3>> water_to_light;
std::vector<std::array<int, 3>> light_to_temperature;
std::vector<std::array<int, 3>> temparature_to_humidity;
std::vector<std::array<int, 3>> humidity_to_location;
std::vector<int> locations;



int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        std::string seedline;
        getline(datafile, seedline);
        seedline += " ";
        int64_t tempint = 0;
        int64_t tempint1 = -1;
        int64_t tempint2 = -1;
        bool firstval = true;
        for(int i = 7; i < seedline.length(); i++) {
            if(isdigit(seedline[i])) {
                tempint = (tempint * 10) + (seedline[i] - '0');
            }
            else {
                if(tempint != 0) {
                    std::cout << "found seed: " << tempint << std::endl;
                    if(tempint1 == -1) {
                        tempint1 = tempint;
                    }
                    else {
                        tempint2 = tempint;
                        std::cout << "found range: " << tempint1 << " to " << tempint1 + tempint2 << std::endl;
                        
                        seeds.push_back({tempint1, tempint2});
                        
                        tempint1 = -1;
                        tempint2 = -1;
                    }
                    tempint = 0;
                }
            }
        }
        int state = -1;
        std::vector<bool> seedchanged;
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            line += " ";
            if(state == -1) {
                if(line.find("seed-to-soil") != std::string::npos) {
                    std::cout << "sound start of seed-to-soil" << std::endl;
                    seedchanged.resize(seeds.size(), false);
                    state = 0;
                }
                
            }
            else if(state == 0) {
                //soil
                if(line.find("soil-to-fertilizer") != std::string::npos) {
                    std::cout << "soil-to-fertilizer" << std::endl;
                    for(int i = 0; i < seedchanged.size(); i++) {
                        seedchanged[i] = false;
                    }
                    state = 1;
                }
                else if(isdigit(line[0])) {
                    std::array<int, 3> temparr;
                    int count = 0;
                    bool addedvalue = false;
                    for(int i = 0; i < line.length(); i++) {
                        if(isdigit(line[i])) {
                            tempint = (tempint * 10) + (line[i] - '0');
                            addedvalue = true;
                        }
                        else {
                            if(addedvalue) {
                                //std::cout << "found value: " << tempint << std::endl;
                                temparr[count] = tempint;
                                count++;
                                tempint = 0;
                                addedvalue = false;
                            }
                        }
                    }
                    seed_to_soil.push_back(temparr);
                }
                
            }
            else if(state == 1) {
                //fertilizer
                if(line.find("fertilizer-to-water") != std::string::npos) {
                    std::cout << "fertilizer-to-water" << std::endl;
                    for(int i = 0; i < seedchanged.size(); i++) {
                        seedchanged[i] = false;
                    }
                    state = 2;
                }
                else if(isdigit(line[0])) {
                    std::array<int, 3> temparr;
                    int count = 0;
                    bool addedvalue = false;
                    for(int i = 0; i < line.length(); i++) {
                        if(isdigit(line[i])) {
                            tempint = (tempint * 10) + (line[i] - '0');
                            addedvalue = true;
                        }
                        else {
                            if(addedvalue) {
                                //std::cout << "found value: " << tempint << std::endl;
                                temparr[count] = tempint;
                                count++;
                                tempint = 0;
                                addedvalue = false;
                            }
                        }
                    }
                    
                    soil_to_fertilizer.push_back(temparr);
                }
                
            }
            else if(state == 2) {
                //water
                if(line.find("water-to-light") != std::string::npos) {
                    std::cout << "water-to-light" << std::endl;
                    for(int i = 0; i < seedchanged.size(); i++) {
                        seedchanged[i] = false;
                    }
                    state = 3;
                }
                else if(isdigit(line[0])) {
                    std::array<int, 3> temparr;
                    int count = 0;
                    bool addedvalue = false;
                    for(int i = 0; i < line.length(); i++) {
                        if(isdigit(line[i])) {
                            tempint = (tempint * 10) + (line[i] - '0');
                            addedvalue = true;
                        }
                        else {
                            if(addedvalue) {
                                //std::cout << "found value: " << tempint << std::endl;
                                temparr[count] = tempint;
                                count++;
                                tempint = 0;
                                addedvalue = false;
                            }
                        }
                    }
                    
                    fertilizer_to_water.push_back(temparr);
                }
                
            }
            else if(state == 3) {
                //light
                if(line.find("light-to-temperature") != std::string::npos) {
                    std::cout << "light-to-temperature" << std::endl;
                    for(int i = 0; i < seedchanged.size(); i++) {
                        seedchanged[i] = false;
                    }
                    state = 4;
                }
                else if(isdigit(line[0])) {
                    std::array<int, 3> temparr;
                    int count = 0;
                    bool addedvalue = false;
                    for(int i = 0; i < line.length(); i++) {
                        if(isdigit(line[i])) {
                            tempint = (tempint * 10) + (line[i] - '0');
                            addedvalue = true;
                        }
                        else {
                            if(addedvalue) {
                                //std::cout << "found value: " << tempint << std::endl;
                                temparr[count] = tempint;
                                count++;
                                tempint = 0;
                                addedvalue = false;
                            }
                        }
                    }
                    
                    water_to_light.push_back(temparr);
                }
                
            }
            else if(state == 4) {
                //temperature
                if(line.find("temperature-to-humidity") != std::string::npos) {
                    std::cout << "temperature-to-humidity" << std::endl;
                    for(int i = 0; i < seedchanged.size(); i++) {
                        seedchanged[i] = false;
                    }
                    state = 5;
                }
                else if(isdigit(line[0])) {
                    std::array<int, 3> temparr;
                    int count = 0;
                    bool addedvalue = false;
                    for(int i = 0; i < line.length(); i++) {
                        if(isdigit(line[i])) {
                            tempint = (tempint * 10) + (line[i] - '0');
                            addedvalue = true;
                        }
                        else {
                            if(addedvalue) {
                                //std::cout << "found value: " << tempint << std::endl;
                                temparr[count] = tempint;
                                count++;
                                tempint = 0;
                                addedvalue = false;
                            }
                        }
                    }
                   
                    light_to_temperature.push_back(temparr);
                }
                
            }
            else if(state == 5) {
                //humidity
                if(line.find("humidity-to-location") != std::string::npos) {
                    std::cout << "humidity-to-location" << std::endl;
                    for(int i = 0; i < seedchanged.size(); i++) {
                        seedchanged[i] = false;
                    }
                    state = 6;
                }
                else if(isdigit(line[0])) {
                    std::array<int, 3> temparr;
                    int count = 0;
                    bool addedvalue = false;
                    for(int i = 0; i < line.length(); i++) {
                        if(isdigit(line[i])) {
                            tempint = (tempint * 10) + (line[i] - '0');
                            addedvalue = true;
                        }
                        else {
                            if(addedvalue) {
                                //std::cout << "found value: " << tempint << std::endl;
                                temparr[count] = tempint;
                                count++;
                                tempint = 0;
                                addedvalue = false;
                            }
                        }
                    }
                    
                    temparature_to_humidity.push_back(temparr);
                }
                
            }
            else if(state == 6) {
                if(isdigit(line[0])) {
                    std::array<int, 3> temparr;
                    int count = 0;
                    bool addedvalue = false;
                    for(int i = 0; i < line.length(); i++) {
                        if(isdigit(line[i])) {
                            tempint = (tempint * 10) + (line[i] - '0');
                            addedvalue = true;
                        }
                        else {
                            if(addedvalue) {
                                //std::cout << "found value: " << tempint << std::endl;
                                temparr[count] = tempint;
                                count++;
                                tempint = 0;
                                addedvalue = false;
                            }
                        }
                    }
                    std::cout << "found 3 values (" << temparr[2] << ")" << std::endl;
                    humidity_to_location.push_back(temparr);
                }
            }
            else {
                //invalid state
                std::cout << "invalid state" << std::endl;
            }
        }
        std::cout << "done parsing file" << std::endl;
        int64_t id = 0;
        int64_t location = 0;
        int64_t result = 0;
        bool running = true;
        while(running) {
            //back to front
            result = id;
            location = id;
            for(int i = 0; i < humidity_to_location.size(); i++) {
                if(result >= humidity_to_location[i][0] && result <= humidity_to_location[i][0] + humidity_to_location[i][2]) {
                    result = result + humidity_to_location[i][1] - humidity_to_location[i][0];
                    i = humidity_to_location.size();
                }
            }
            for(int i = 0; i < temparature_to_humidity.size(); i++) {
                if(result >= temparature_to_humidity[i][0] && result <= temparature_to_humidity[i][0] + temparature_to_humidity[i][2]) {
                    result = result + temparature_to_humidity[i][1] - temparature_to_humidity[i][0];
                    i = temparature_to_humidity.size();
                }
            }
            for(int i = 0; i < light_to_temperature.size(); i++) {
                if(result >= light_to_temperature[i][0] && result <= light_to_temperature[i][0] + light_to_temperature[i][2]) {
                    result = result + light_to_temperature[i][1] - light_to_temperature[i][0];
                    i = light_to_temperature.size();
                }
            }
            for(int i = 0; i < water_to_light.size(); i++) {
                if(result >= water_to_light[i][0] && result <= water_to_light[i][0] + water_to_light[i][2]) {
                    result = result + water_to_light[i][1] - water_to_light[i][0];
                    i = water_to_light.size();
                }
            }
            for(int i = 0; i < fertilizer_to_water.size(); i++) {
                if(result >= fertilizer_to_water[i][0] && result <= fertilizer_to_water[i][0] + fertilizer_to_water[i][2]) {
                    result = result + fertilizer_to_water[i][1] - fertilizer_to_water[i][0];
                    i = fertilizer_to_water.size();
                }
            }
            for(int i = 0; i < soil_to_fertilizer.size(); i++) {
                if(result >= soil_to_fertilizer[i][0] && result <= soil_to_fertilizer[i][0] + soil_to_fertilizer[i][2]) {
                    result = result + soil_to_fertilizer[i][1] - soil_to_fertilizer[i][0];
                    i = soil_to_fertilizer.size();
                }
            }
            for(int i = 0; i < seed_to_soil.size(); i++) {
                if(result >= seed_to_soil[i][0] && result <= seed_to_soil[i][0] + seed_to_soil[i][2]) {
                    result = result + seed_to_soil[i][1] - seed_to_soil[i][0];
                    i = seed_to_soil.size();
                }
            }
            for(int i = 0; i < seeds.size(); i++) {
                if(result >= seeds[i][0] && result <= seeds[i][0] + seeds[i][1]) {
                    std::cout << "found result!!!" << std::endl;
                    running = false;
                }
            }
            id++;
        }
        std::cout << "result: " << result << std::endl;
        std::cout << "location: " << location << std::endl;
        /*
        if(seeds[i] >= temparr[1] && seeds[i] < temparr[1] + temparr[2] && !seedchanged[i]) {
            seeds[i] = seeds[i] + temparr[0] - temparr[1];
            std::cout << "changed seed " << i << " to " << seeds[i] << std::endl;
            seedchanged[i] = true;
        }
        */
    }
    return 0;
}