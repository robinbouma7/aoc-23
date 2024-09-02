#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

std::ifstream datafile;
std::vector<std::vector<std::string>> grids;

//kijken op welke plekken er 2 naast elkaar zijn,
//alle andere rijen kijken of op dezelfde plakken 2 naast elkaar zijn
//als er 1 uit komt dan is het een spiegelpunt hopelijk

//dit werkt maar je kan meerdere spiegelpunten hebben
//hiervoor moet je de 2 rijen er naast ook checken, dit word wel moeilijker 

int main(int argc, char *argv[]) {
    if(argc > 1 && (std::strcmp(argv[1], "-t") == 0 || std::strcmp(argv[1], "--test") == 0)) {
        std::cout << "TEST DATA\n\n";
        datafile.open("testdata.txt");
    }
    else {
        datafile.open("data.txt");
    }
    

    if (datafile.is_open()) {
        std::vector<std::string> tempvec;
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            if(line.length() > 0) {
                tempvec.push_back(line);
                std::cout << line << "\n";
            }
            else {
                std::cout << "new grid\n";
                grids.push_back(tempvec);
                tempvec.clear();
            }
        }
        if(tempvec.size() > 0) {
            std::cout << "added last grid\n";
            grids.push_back(tempvec);
        }
    }
   
    for(int i = 0; i < grids.size(); i++) {
        std::vector<int> mirrorpoints;
        for(int j = 0; j < grids[i].size(); j++) {
            char lastchar = grids[i][j][0];
            std::vector<int> tempmirror;
            for(int k = 1; k < grids[i][j].length(); k++) {
                
                if(lastchar == grids[i][j][k]) {
                    if(j == 0) {
                        std::cout << "mirror point found at " << k << "\n";
                        
                        mirrorpoints.push_back(k);
                    }
                    else {
                        
                        bool testval = false;
                        for(int l = 0; l < mirrorpoints.size(); l++) {
                            if(mirrorpoints[l] == k) {
                                tempmirror.push_back(k);
                                l = mirrorpoints.size();
                                testval = true;
                            }
                        }
                    }
                }
                lastchar = grids[i][j][k];
            }
            
            if(j > 0) {
                /*std::cout << "new tempmirror after " << j << ":\n";
                for(int l = 0; l < tempmirror.size(); l++) {
                    std::cout << "tempmirror: " << tempmirror[l] << "\n";
                }
                std::cout << "\n";*/
                mirrorpoints = tempmirror;
            }
            
           
        }
        if(mirrorpoints.size() == 1) {
            std::cout << "Mirrorpoint found in grid " << i << " at " << mirrorpoints[0] << "\n";
        }
        else {
            std::cout << "multiple or no mirrorpoints found in grid " << i  << " (" << mirrorpoints.size() <<  ")\n";
            for(int j = 0; j < grids[i].size(); j++) {
                std::cout << grids[i][j] << "\n";
            }
        }
    }
    return 0;
}