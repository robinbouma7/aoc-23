#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <map>

std::ifstream datafile;

std::map<std::string, std::array<std::string, 2>> network;
std::vector<int> directions;

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
            std::string leftlocation, rightlocation = "";
            for(int i = 4; i < line.length(); i++) {
                if(line[i] == *"(") {
                    leftlocation = line.substr(i+1, 3);
                    rightlocation = line.substr(i+6, 3); 
                    break;
                }
            }
            std::cout << "location: " << location << std::endl;
            std::cout << "leftlocation: " << leftlocation << std::endl;
            std::cout << "rightlocation: " << rightlocation << std::endl;
            std::array<std::string, 2> temparray = {leftlocation, rightlocation};
            network[location] = temparray;
            
        }
    }
    bool ZZZfound = false;
    int i = 0;
    int instructions = 0;
    std::string currentlocation = "AAA";
    while(!ZZZfound) {
        if(i >= directions.size()) {
            std::cout << "looping back at " << i << std::endl;
            i = 0;
        }
        std::cout << currentlocation << " > " << network[currentlocation][directions[i]] << std::endl;
        currentlocation = network[currentlocation][directions[i]];
        instructions++;
        if(currentlocation == "ZZZ") {
            std::cout << "arrived at ZZZ!!" << std::endl;
            ZZZfound = true;
        }
        i++;

    }
    std::cout << "Instructions: " << instructions << std::endl;
    return 0;
}