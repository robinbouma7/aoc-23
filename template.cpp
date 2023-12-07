#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ifstream datafile;

int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            
        }
    }
    return 0;
}