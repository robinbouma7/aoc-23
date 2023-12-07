#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ifstream datafile;
int maxred = 12;
int maxgreen = 13;
int maxblue = 14;

std::vector<int> possible_games;
int result = 0;

int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);

            //get matchid
            int matchid = line[5] - '0';
            bool looping = true;
            int tempid = 6;
            while(looping) {
                if(isdigit(line[tempid])) {
                    matchid = matchid * 10 + (line[tempid] - '0');
                    tempid++;
                }
                else {
                    looping = false;
                }
            }
            std::cout << "matchid: " << matchid << std::endl;
            //check if match is impossible
            bool possible = true;
            tempid += 2;
            int biggestred = 0;
            int biggestgreen = 0;
            int biggestblue = 0;

            while(possible) {
                int amount = 0;
                
                if(isdigit(line[tempid])) {
                    amount = line[tempid] - '0';
                    tempid++;
                    bool endofnumber = false;
                    while(!endofnumber) {
                        if(isdigit(line[tempid])) {
                            amount = amount * 10 + (line[tempid] - '0');
                            tempid++;
                        }
                        else {
                            endofnumber = true;
                        }
                    
                    }
                    tempid++;
                    if(line[tempid] == *"r") {
                        if(amount > biggestred) {
                            biggestred = amount;
                        }
                    }
                    else if(line[tempid] == *"g") {
                        if(amount > biggestgreen) {
                            biggestgreen = amount;
                        }
                    }
                    else if(line[tempid] == *"b") {
                        if(amount > biggestblue) {
                            biggestblue = amount;
                        }
                    }
            
                    
                }
                tempid++;
                if(tempid >= line.length()) {
                    //end of line
                    std::cout << "got result!!" << std::endl;
                    result += biggestred * biggestblue * biggestgreen;
                    possible = false;
                }
            }
            
        }
        std::cout << "result: " << result << std::endl;
    }

    return 0;
}