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
                        if(amount > maxred) {
                            //impossible
                            possible = false;
                            std::cout << "impossible" << std::endl;
                            std::cout << "amount: " << amount << " red" << std::endl;
                        }
                    }
                    else if(line[tempid] == *"g") {
                        if(amount > maxgreen) {
                            //impossible
                            possible = false;
                            std::cout << "impossible" << std::endl;
                            std::cout << "amount: " << amount << " green" << std::endl;
                        }
                    }
                    else if(line[tempid] == *"b") {
                        if(amount > maxblue) {
                            //impossible
                            possible = false;
                            std::cout << "impossible" << std::endl;
                            std::cout << "amount: " << amount << " blue" << std::endl;
                        }
                    }
            
                    
                }
                tempid++;
                if(tempid >= line.length()) {
                    //end of line
                    std::cout << "possible!!" << std::endl;
                    possible_games.push_back(matchid);
                    result += matchid;
                    possible = false;
                }
            }
            
        }
        std::cout << "result: " << result << std::endl;
    }

    return 0;
}