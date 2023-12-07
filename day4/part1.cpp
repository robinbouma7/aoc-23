#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ifstream datafile;
int points = 0;

int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
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
                                if(temppoints == 0) {
                                   temppoints = 1;
                                }
                                else {
                                    temppoints *= 2;
                                }
                            }
                            else {
                                //std::cout << "loser: " << tempnum << std::endl;
                            }
                        }
                        tempnum = 0;
                    }
                    
                }
            }
            std::cout << "points: " << temppoints << std::endl;
            points += temppoints;
            
        }
        std::cout << "total points: " << points << std::endl;
    }
    return 0;
}