#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ifstream datafile;
std::vector<std::vector<char>> map;

int startx = -1;
int starty = -1;

int result = 0;



int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        bool startfound = false;
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            std::vector<char> tempvec;
            for(int i = 0; i < line.length(); i++) {
                if(!startfound && line[i] == 'S') {
                    startx = i;
                    starty = map.size();
                    startfound = true;
                }
                tempvec.push_back(line[i]);
            }
            map.push_back(tempvec);
        }
        bool looping = true;
        int x = startx;
        int y = starty;
        int direction = 0;
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
        std::cout << "path length: " << result << std::endl;
        std::cout << "result: " << (float)result / 2 << std::endl;
    }
    return 0;
}