#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <map>
#include <limits>

std::ifstream datafile;

std::vector<int64_t> seeds;
std::vector<int64_t> origseeds;

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
        for(int i = 7; i < seedline.length(); i++) {
            if(isdigit(seedline[i])) {
                tempint = (tempint * 10) + (seedline[i] - '0');
            }
            else {
                if(tempint != 0) {
                    std::cout << "found seed: " << tempint << std::endl;
                    seeds.push_back(tempint);
                    tempint = 0;
                }
            }
        }
        origseeds = seeds;
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
                    std::cout << "found 3 values (" << temparr[2] << ")" << std::endl;
                    for(int i = 0; i < seeds.size(); i++) {
                        if(seeds[i] >= temparr[1] && seeds[i] < temparr[1] + temparr[2] && !seedchanged[i]) {
                            seeds[i] = seeds[i] + temparr[0] - temparr[1];
                            std::cout << "changed seed " << i << " to " << seeds[i] << std::endl;
                            seedchanged[i] = true;
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
                    std::cout << "found 3 values (" << temparr[2] << ")" << std::endl;
                    for(int i = 0; i < seeds.size(); i++) {
                        if(seeds[i] >= temparr[1] && seeds[i] < temparr[1] + temparr[2] && !seedchanged[i]) {
                            seeds[i] = seeds[i] + temparr[0] - temparr[1];
                            std::cout << "changed seed " << i << " to " << seeds[i] << std::endl;
                            seedchanged[i] = true;
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
                    std::cout << "found 3 values (" << temparr[2] << ")" << std::endl;
                    for(int i = 0; i < seeds.size(); i++) {
                        if(seeds[i] >= temparr[1] && seeds[i] < temparr[1] + temparr[2] && !seedchanged[i]) {
                            seeds[i] = seeds[i] + temparr[0] - temparr[1];
                            std::cout << "changed seed " << i << " to " << seeds[i] << std::endl;
                            seedchanged[i] = true;
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
                    std::cout << "found 3 values (" << temparr[2] << ")" << std::endl;
                    for(int i = 0; i < seeds.size(); i++) {
                        if(seeds[i] >= temparr[1] && seeds[i] < temparr[1] + temparr[2] && !seedchanged[i]) {
                            seeds[i] = seeds[i] + temparr[0] - temparr[1];
                            std::cout << "changed seed " << i << " to " << seeds[i] << std::endl;
                            seedchanged[i] = true;
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
                    std::cout << "found 3 values (" << temparr[2] << ")" << std::endl;
                    for(int i = 0; i < seeds.size(); i++) {
                        if(seeds[i] >= temparr[1] && seeds[i] < temparr[1] + temparr[2] && !seedchanged[i]) {
                            seeds[i] = seeds[i] + temparr[0] - temparr[1];
                            std::cout << "changed seed " << i << " to " << seeds[i] << std::endl;
                            seedchanged[i] = true;
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
                    std::cout << "found 3 values (" << temparr[2] << ")" << std::endl;
                    for(int i = 0; i < seeds.size(); i++) {
                        if(seeds[i] >= temparr[1] && seeds[i] < temparr[1] + temparr[2] && !seedchanged[i]) {
                            seeds[i] = seeds[i] + temparr[0] - temparr[1];
                            std::cout << "changed seed " << i << " to " << seeds[i] << std::endl;
                            seedchanged[i] = true;
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
                    for(int i = 0; i < seeds.size(); i++) {
                        if(seeds[i] >= temparr[1] && seeds[i] < temparr[1] + temparr[2] && !seedchanged[i]) {
                            seeds[i] = seeds[i] + temparr[0] - temparr[1];
                            std::cout << "changed seed " << i << " to " << seeds[i] << std::endl;
                            seedchanged[i] = true;
                        }
                    }
                    humidity_to_location.push_back(temparr);
                }
            }
            else {
                //invalid state
                std::cout << "invalid state" << std::endl;
            }
        }
        std::cout << "done parsing file" << std::endl;
    
        std::cout << "locations are: " << std::endl;
        int64_t smallest = std::numeric_limits<int64_t>::max();
        for(int i = 0; i < seeds.size(); i++) {
            std::cout << seeds[i] << std::endl;
            if(seeds[i] < smallest && seeds[i] > 0) {
                smallest = seeds[i];
            }
        }
        std::cout << "smallest is: " << smallest << std::endl;
        

    }
    return 0;
}