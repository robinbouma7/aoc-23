#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

std::ifstream datafile;
std::vector<std::vector<std::string>> grids;

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
                std::vector<std::string> tempvec;
                grids.push_back(tempvec);
                tempvec.clear();
            }
        }
        if(tempvec.size() > 0) {
            std::cout << "added last grid\n";
            grids.push_back(tempvec);
        }
    }
    return 0;
}