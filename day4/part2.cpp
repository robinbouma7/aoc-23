#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ifstream datafile;
int points = 0;
std::vector<int> repeats;
std::vector<int> winnums;

int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        int lastcard = 0;
        while(datafile.good() ) {
            std::string line;
            std::getline(datafile, line);
            line += "  ";
            
            //get card number
            int cardnumber = 0;
            bool looping = true;
            int tempid = 5;
            while(looping) {
                if(isdigit(line[tempid])) {
                    cardnumber = (cardnumber * 10) + (line[tempid] - '0');
                }
                else if(line[tempid] == *":") {
                    looping = false;
                }
                tempid++;
            }
            std::cout << cardnumber << ":";
            //get winning numbers
            std::vector<int> winningnumbers;
            looping = true;
            int tempnum = 0;
            while(looping) {
                if(isdigit(line[tempid])) {
                    tempnum = (tempnum * 10) + (line[tempid] - '0');
                }
                else if(line[tempid] == *"|") {
                    looping = false;
                }
                else {
                    if(tempnum != 0) {
                        std::cout << tempnum << " ";
                        winningnumbers.push_back(tempnum);
                        tempnum = 0;
                    }
                    
                }
                tempid++;
            }
            std::cout << std::endl;
            //get ticket numbers
            tempnum = 0;
            int temppoints = 0;
            for(int i = tempid; i < line.length() - 1; i++) {
                if(isdigit(line[i])) {
                    tempnum = (tempnum * 10) + (line[i] - '0');
                }
                else {
                    if(tempnum != 0) {
                        for(int j = 0; j < winningnumbers.size(); j++) {
                            if(tempnum == winningnumbers[j]) {
                                std::cout << "winner: " << tempnum << std::endl;
                                temppoints++;
                            }
                            else {
                                //std::cout << "loser: " << tempnum << std::endl;
                            }
                        }
                        tempnum = 0;
                    }
                    
                }
            }
            winnums.push_back(temppoints);
            
        }
        repeats.resize(winnums.size(), 1);
        for(int i = 0; i < winnums.size(); i++) {
            if(winnums[i] > 0) {
                for(int j = 0; j < winnums[i]; j++) {
                    if(i + j + 1 >= winnums.size()) {
                        repeats[winnums.size() - 1] += repeats[i];
                        std::cout << "add " << repeats[i] << " to " << winnums.size() - 1 << std::endl;
                    }
                    else {
                        std::cout << "add " << repeats[i] << " to " << i + j + 1 << std::endl;
                        repeats[i + j + 1] += repeats[i];
                    }
                }
            }
            std::cout << "points(" << i << "): " << repeats[i] << std::endl;
            points += repeats[i];
        }
        
        std::cout << "total points: " << points << std::endl;
    }
    return 0;
}