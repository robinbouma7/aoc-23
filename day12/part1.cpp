#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ifstream datafile;

std::vector<std::vector<char>> grid;
std::vector<std::string> springs;
std::vector<std::vector<int>> values;
std::vector<int> unknowns;

int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            line += " ";

            bool looping = true;
            std::vector<char> tempvec;
            int ident = 0;
            std::string tempstr = "";
            int tempint = 0;
            while(looping) {
                if(line[ident] == *" ") {
                    looping = false;
                    break;
                }
                if(line[ident] == *"?") {
                    tempint++;
                    break;
                }
                tempvec.push_back(line[ident]);
                tempstr += line[ident];
            }
            grid.push_back(tempvec);
            springs.push_back(tempstr);
            unknowns.push_back(tempint);

            std::vector<int> tempvec2;
            int tempnum = 0;
            for(int i = ident; i < line.length(); i++) {
                if(isdigit(line[i])) {
                    tempnum = (tempnum * 10) + (line[i] - '0');
                }
                else if(tempnum != 0) {
                    tempvec2.push_back(tempnum);
                    tempnum = 0;
                }
            }
            values.push_back(tempvec2);
        }
        for(int i = 0; i < grid.size(); i++) {
            //do something with springs[i]
            
        }

    }
    return 0;
}