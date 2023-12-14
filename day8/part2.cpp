#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <map>
#include <numeric>

std::ifstream datafile;

std::map<std::string, std::array<std::string, 2>> network;
std::vector<int> directions;

std::vector<std::string> locations;
std::vector<uint64_t> loopcounts;
std::vector<uint64_t> loopstarts;
uint64_t result = 1;

int main() {
    datafile.open("data.txt");

    if(datafile.is_open()) {

        std::string dline;
        getline(datafile, dline);
        for(int i = 0; i < dline.length(); i++) {
            if(dline[i] == *"L") {
                directions.push_back(0);
            }
            else if(dline[i] == *"R") {
                directions.push_back(1);
            }
            else {
                std::cout << "Error: invalid direction: " << dline[i] << std::endl;
                continue;
            }
        }
        
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            if(line == "") {
                continue;
            }

            std::string location = line.substr(0, 3);
            if(line[2] == *"A") {
                //starting location
                std::cout << "added starting location: " << location << std::endl;
                locations.push_back(location);
            }
            std::string leftlocation, rightlocation = "";
            for(int i = 4; i < line.length(); i++) {
                if(line[i] == *"(") {
                    leftlocation = line.substr(i+1, 3);
                    rightlocation = line.substr(i+6, 3);
                    break;
                }
            }
            //std::cout << "location: " << location << std::endl;
            //std::cout << "leftlocation: " << leftlocation << std::endl;
            //std::cout << "rightlocation: " << rightlocation << std::endl;
            std::array<std::string, 2> temparray = {leftlocation, rightlocation};
            network[location] = temparray;
            
        }
    }

    for(int i = 0; i < locations.size(); i++) {
        std::string startlocation = locations[i];
        std::string location = startlocation;
        std::vector<std::string> visited;
        visited.push_back(location);
        bool found = false;
        int ident = 0;
        int loopcount = 0;
        while(!found) {
            if(ident >= directions.size()) {
                ident = 0;
            }
            loopcount++;
            location = network[location][directions[ident]];
            if(location[2] == *"Z") {
                std::cout << "found finish location" << std::endl;
                loopcounts.push_back(loopcount);
                loopstarts.push_back(0);
                found = true;
                break;
            }
            ident++;
        }
        
    }
    std::cout << "result: " << result << std::endl;
    bool looping = true;
    uint64_t ident = std::lcm(loopcounts[0], std::lcm(loopcounts[1], std::lcm(loopcounts[2], std::lcm(loopcounts[3], std::lcm(loopcounts[4], loopcounts[5])))));
    std::cout << "ident: " << ident << std::endl;
    return 0;
}