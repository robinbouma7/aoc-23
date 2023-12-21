#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>

std::ifstream datafile;
std::vector<std::vector<char>> map;
std::vector<std::vector<bool>> isloop;
std::vector<std::vector<bool>> isoutside;
std::vector<std::array<int, 2>> insidelocations;

int startx = -1;
int starty = -1;

int result = 0;
int result2 = 0;



int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        bool startfound = false;
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            std::vector<char> tempvec;
            std::vector<bool> tempboolvec;
            for(int i = 0; i < line.length(); i++) {
                if(!startfound && line[i] == 'S') {
                    startx = i ;
                    starty = map.size();
                    startfound = true;
                }
                tempboolvec.push_back(false);
                tempvec.push_back(line[i]);
            }
            isloop.push_back(tempboolvec);
            isoutside.push_back(tempboolvec);
            map.push_back(tempvec);
        }
        bool looping = true;
        int x = startx;
        int y = starty;
        int direction = 0;
        
        isloop[starty][startx] = true;
        //1 = north
        //2 = west
        //3 = east
        //4 = south

        //check up
        if(map[y - 1][x] == '|') {
            direction = 1;
            y--;
            result++;
            std::cout << "up" << std::endl;
        }
        else if(map[y - 1][x] == '7') {
            direction = 2;
            y--;
            result++;
            std::cout << "up" << std::endl;
        }
        else if(map[y - 1][x] == 'F') {
            direction = 3;
            y--;
            result++;
            std::cout << "up" << std::endl;
        }

        //check left
        else if(map[y][x - 1] == '-') {
            direction = 2;
            x--;
            result++;
            std::cout << "left" << std::endl;
        }
        else if(map[y][x - 1] == 'F') {
            direction = 4;
            x--;
            result++;
            std::cout << "left" << std::endl;
        }
        else if(map[y][x - 1] == 'L') {
            direction =  1;
            x--;
            result++;
            std::cout << "left" << std::endl;
        }

        //check right
        else if(map[y][x + 1] == '-') {
            direction = 3;
            x++;
            result++;
            std::cout << "right" << std::endl;
        }
        else if(map[y][x + 1] == 'J') {
            direction = 1;
            x++;
            result++;
            std::cout << "right" << std::endl;
        }
        else if(map[y][x + 1] == '7') {
            direction = 4;
            x++;
            result++;
            std::cout << "right" << std::endl;
        }

        //check down
        else if(map[y + 1][x] == '|') {
            direction = 4;
            y++;
            result++;
            std::cout << "down" << std::endl;
        }
        else if(map[y + 1][x] == 'J') {
            direction = 2;
            y++;
            result++;
            std::cout << "down" << std::endl;
        }
        else if(map[y + 1][x] == 'L') {
            direction = 3;
            y++;
            result++;
            std::cout << "down" << std::endl;
        }

        //moving
        while(looping) {
            isloop[y][x] = true;
            if(direction == 1) {
                //move up
                if(map[y - 1][x] == '|') {
                    direction = 1;
                    y--;
                    result++;
                }
                else if(map[y - 1][x] == '7') {
                    direction = 2;
                    y--;
                    result++;
                }
                else if(map[y - 1][x] == 'F') {
                    direction = 3;
                    y--;
                    result++;
                }
                else if(map[y - 1][x] == 'S') {
                    std::cout << "looped back to start" << std::endl;
                    looping = false;
                    result++;
                    break;
                }
            }
            else if(direction == 2) {
                //move left
                if(map[y][x - 1] == '-') {
                    direction = 2;
                    x--;
                    result++;
                }
                else if(map[y][x - 1] == 'F') {
                    direction = 4;
                    x--;
                    result++;
                }
                else if(map[y][x - 1] == 'L') {
                    direction =  1;
                    x--;
                    result++;
                }
                else if(map[y][x - 1] == 'S') {
                    std::cout << "looped back to start" << std::endl;
                    looping = false;
                    result++;
                    break;
                }
            }
            else if(direction == 3) {
                //move right
                if(map[y][x + 1] == '-') {
                    direction = 3;
                    x++;
                    result++;
                }
                else if(map[y][x + 1] == 'J') {
                    direction = 1;
                    x++;
                    result++;
                }
                else if(map[y][x + 1] == '7') {
                    direction = 4;
                    x++;
                    result++;
                }
                else if(map[y][x + 1] == 'S') {
                    std::cout << "looped back to start" << std::endl;
                    looping = false;
                    result++;
                    break;
                }
            }
            else if(direction == 4) {
                //move down
                if(map[y + 1][x] == '|') {
                    direction = 4;
                    y++;
                    result++;
                }
                else if(map[y + 1][x] == 'J') {
                    direction = 2;
                    y++;
                    result++;
                }
                else if(map[y + 1][x] == 'L') {
                    direction = 3;
                    y++;
                    result++;
                }
                else if(map[y + 1][x] == 'S') {
                    std::cout << "looped back to start" << std::endl;
                    looping = false;
                    result++;
                    break;
                }
            }
        }
        //everything on the right side of the loop is inside
        std::cout << "path length: " << result << std::endl;
        std::cout << "result: " << (float)result / 2 << std::endl;
        
        for(int i = 0; i < map.size(); i++) {
            bool inside = false;
            bool onroute = false;
            bool directionup = false;
            for(int j = 0; j < map[i].size(); j++) {
                if(isloop[i][j] && !onroute) {
                    if(map[i][j] == '|' || map[i][j] == 'S') {
                        inside = !inside;
                    }
                    else if(map[i][j] == 'L') {
                        directionup = true;
                        onroute = true;
                    }
                    else if(map[i][j] == 'F') {
                        directionup = false;
                        onroute = true;
                    }
                    else {
                        onroute = true;
                    }
                }
                else if(isloop[i][j] ) {
                    if(map[i][j] == *"7") {
                        if(directionup) {
                            inside = !inside;
                        }
                        onroute = false;
                    }
                    else if(map[i][j] == *"J") {
                        if(!directionup) {
                            inside = !inside;
                        }
                        onroute = false;
                    }
                }
                isoutside[i][j] = !inside;

                
            }
        }
        /*for(int i = 0; i < map[0].size(); i++) {
            bool inside = false;
            bool onroute = false;
            bool directionleft = false;
            for(int j = 0; j < map.size(); j++) {
                if(isloop[i][j] && !onroute) {
                    if(map[i][j] == '-') {
                        inside = !inside;
                    }
                    else if(map[i][j] == 'F') {
                        directionleft = false;
                        onroute = true;
                    }
                    else if(map[i][j] == '7') {
                        directionleft = true;
                        onroute = true;
                    }
                    else {
                        onroute = true;
                    }
                }
                else if(isloop[i][j] ) {
                    if(map[i][j] == *"L") {
                        if(directionleft) {
                            inside = !inside;
                        }
                        onroute = false;
                    }
                    else if(map[i][j] == *"J") {
                        if(!directionleft) {
                            inside = !inside;
                        }
                        onroute = false;
                    }
                }
                isoutside[i][j] = !inside;
            }
        }*/
        for(int i = 0; i < map.size(); i++) {
            for(int j = 0; j < map[i].size(); j++) {
                if(isoutside[i][j] || isloop[i][j]) {
                    if(isloop[i][j]) {
                        std::cout << ".";
                    }
                    else {
                        std::cout << " ";
                    }
                }
                else {
                    std::cout << "#";
                    result2++;
                }
            }
            std::cout << std::endl;
        }
        std::cout << "result 2: " << result2 << std::endl;
    }
    return 0;
}