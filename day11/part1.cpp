#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>

std::ifstream datafile;

std::vector<std::vector<bool>> space;
std::vector<std::array<int, 2>> galaxypos;
std::vector<std::array<int, 3>> galaxydistances;

int result = 0;

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
            if(!containsgalaxy) {
                space.push_back(tempvec);
            }
            
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
            if(!containsgalaxy) {
                //std::cout << "does not contain galaxy " << ident << std::endl;
                for(int j = 0; j < space.size(); j++) {
                    space[j].insert(space[j].begin() + ident, false);
                }
                ident++;
            }
            ident++;
            if(ident >= space[ident].size()) {
                looping = false;
            }
        }
        std::cout << "parsed columns" << std::endl;
        
        for(int i = 0; i < space.size(); i++) {
            for(int j = 0; j < space[i].size(); j++) {
                std::cout << space[i][j];
                if(space[i][j]) {
                    std::array<int, 2> temparr = {i, j};
                    galaxypos.push_back(temparr);
                }
            }
            std::cout << std::endl;
        }
        for(int i = 0; i < galaxypos.size(); i++) {
            for(int j = i; j < galaxypos.size(); j++) {
                if(i != j) {
                    int xdist = galaxypos[i][0] - galaxypos[j][0];
                    int ydist = galaxypos[i][1] - galaxypos[j][1];
                    if(xdist < 0) {
                        xdist = -xdist;
                    }
                    if(ydist < 0) {
                        ydist = -ydist;
                    }
                    int distance = xdist + ydist;
                    std::array<int, 3> temparr = {i, j, distance};
                    galaxydistances.push_back(temparr);
                    result += distance;
                }
               
            }
        }
        std::cout << "result: " << result << std::endl;
    }
    return 0;
}