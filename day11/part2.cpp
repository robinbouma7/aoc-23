#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>

std::ifstream datafile;

std::vector<std::vector<bool>> space;
std::vector<std::array<int, 2>> galaxypos;
std::vector<std::array<int, 3>> galaxydistances;
std::vector<bool> rowisempty;
std::vector<bool> columnisempty;

std::vector<std::array<int, 2>> prevcombos;

int64_t result = 0;

int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        while(datafile.good() ) {
            
            std::string line;
            getline(datafile, line);
            bool containsgalaxy = false;
            std::vector<bool> tempvec;
            for(int i = 0; i < line.length(); i++) {
                if(line[i] == '#') {
                    containsgalaxy = true;
                    tempvec.push_back(true);
                    continue;
                }
                tempvec.push_back(false);
            }
            space.push_back(tempvec);
            rowisempty.push_back(!containsgalaxy);
            
        }

        std::cout << "parsed rows" << std::endl;
        std::cout << space[0].size() << std::endl;

        bool looping = true;
        int ident = 0;
        while(looping) {
            bool containsgalaxy = false;
            for(int j = 0; j < space.size(); j++) {
                if(space[j][ident]) {
                    containsgalaxy = true;
                    //std::cout << "contains galaxy" << std::endl;
                    break;
                }
            }
            columnisempty.push_back(!containsgalaxy);
            ident++;
            if(ident >= space[ident].size()) {
                looping = false;
            }
        }
        std::cout << "parsed columns" << std::endl;
        for(int i = 0; i < space.size(); i++) {
            for(int j = 0; j < space[i].size(); j++) {
                
                if(space[i][j]) {
                    std::array<int, 2> temparr = {j, i};
                    galaxypos.push_back(temparr);
                    //std::cout << galaxypos.size();
                }
                else {
                    //std::cout << ".";
                }
            }
            //std::cout << std::endl;
        }
        for(int i = 0; i < galaxypos.size(); i++) {
            for(int j = i; j < galaxypos.size(); j++) {
                int64_t xdist = 0;
                int64_t ydist = 0;
                if(galaxypos[i][0] <= galaxypos[j][0]) {
                    for(int k = galaxypos[i][0]; k < galaxypos[j][0]; k++) {
                        if(columnisempty[k]) {
                            xdist += 1000000;
                        }
                        else {
                            xdist++;
                        }
                    }
                }
                else {
                    for(int k = galaxypos[j][0]; k < galaxypos[i][0]; k++) {
                        if(columnisempty[k]) {
                            xdist += 1000000;
                        }
                        else {
                            xdist++;
                        }
                    }
                }
                if(galaxypos[i][1] <= galaxypos[j][1]) {
                    for(int k = galaxypos[i][1]; k < galaxypos[j][1]; k++) {
                        if(rowisempty[k]) {
                            ydist += 1000000;
                        }
                        else {
                            ydist++;
                        }
                    }
                }
                else {
                    for(int k = galaxypos[j][1]; k < galaxypos[i][1]; k++) {
                        if(rowisempty[k]) {
                            ydist += 1000000;
                        }
                        else {
                            ydist++;
                        }
                    }
                }
                int64_t distance = xdist + ydist;
                result += distance;
                
                std::array<int, 3> temparr = {i, j, distance};
                galaxydistances.push_back(temparr);
            }
               
            
        }
        std::cout << "result: " << result << std::endl;
    }
    return 0;
}