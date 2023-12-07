#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::vector<char>> data;
std::ifstream datafile;

int result;
std::vector<int> resultcheck;

int main() {
    datafile.open("testdata.txt");

    //read data to 2d vector
    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            std::vector<char> temp;
            temp.push_back('.');
            for(int i = 0; i < line.length(); i++) {
                temp.push_back(line[i]);
            }
            temp.push_back('.');
            data.push_back(temp);
        }
    }
    //parse data
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].size(); j++) {
            if(data[i][j] == *"*") {
                int num = 0;
                int starti = i;
                int startj = j;
                std::vector<int> tempnums;
                if(isdigit(data[i - 1][j - 1])) {
                    starti = i - 1;
                    startj = j - 1;
                    bool looking = true;
                    int tempid = 0;
                    while(looking) {
                        if(isdigit(data[starti][startj + tempid])) {
                            tempid--;
                        }
                        else {
                            tempid++;
                            looking = false;
                        }
                    }
                    bool looping = true;
                    while(looping) {
                        if(isdigit(data[starti][startj + tempid])) {
                            num = (num * 10) + data[starti][startj + tempid] - '0';
                            data[starti][startj + tempid] = *".";
                            tempid++;
                        }
                        else {
                            looping = false;
                        }
                    }
                    tempnums.push_back(num);
                    num = 0;
                }
                if(isdigit(data[i - 1][j])) {
                    starti = i - 1;
                    startj = j;
                    bool looking = true;
                    int tempid = 0;
                    while(looking) {
                        if(isdigit(data[starti][startj + tempid])) {
                            tempid--;
                        }
                        else {
                            tempid++;
                            looking = false;
                        }
                    }
                    bool looping = true;
                    while(looping) {
                        if(isdigit(data[starti][startj + tempid])) {
                            num = (num * 10) + data[starti][startj + tempid] - '0';
                            data[starti][startj + tempid] = *".";
                            tempid++;
                        }
                        else {
                            looping = false;
                        }
                    }
                    tempnums.push_back(num);
                    num = 0;
                }
                if(isdigit(data[i - 1][j + 1])) {
                    starti = i - 1;
                    startj = j + 1;
                    bool looking = true;
                    int tempid = 0;
                    while(looking) {
                        if(isdigit(data[starti][startj + tempid])) {
                            tempid--;
                        }
                        else {
                            tempid++;
                            looking = false;
                        }
                    }
                    bool looping = true;
                    while(looping) {
                        if(isdigit(data[starti][startj + tempid])) {
                            num = (num * 10) + data[starti][startj + tempid] - '0';
                            data[starti][startj + tempid] = *".";
                            tempid++;
                        }
                        else {
                            looping = false;
                        }
                    }
                    tempnums.push_back(num);
                    num = 0;
                }

                
                
                if(isdigit(data[i][j - 1])) {
                    starti = i;
                    startj = j - 1;
                    bool looking = true;
                    int tempid = 0;
                    while(looking) {
                        if(isdigit(data[starti][startj + tempid])) {
                            tempid--;
                        }
                        else {
                            tempid++;
                            looking = false;
                        }
                    }
                    bool looping = true;
                    while(looping) {
                        if(isdigit(data[starti][startj + tempid])) {
                            num = (num * 10) + data[starti][startj + tempid] - '0';
                            data[starti][startj + tempid] = *".";
                            tempid++;
                        }
                        else {
                            looping = false;
                        }
                    }
                    tempnums.push_back(num);
                    num = 0;
                }
                if(isdigit(data[i][j + 1])) {
                    starti = i;
                    startj = j + 1;
                    int tempid = 0;
                    bool looping = true;
                    while(looping) {
                        if(isdigit(data[starti][startj + tempid])) {
                            num = (num * 10) + data[starti][startj + tempid] - '0';
                            data[starti][startj + tempid] = *".";
                            tempid++;
                        }
                        else {
                            looping = false;
                        }
                    }
                    tempnums.push_back(num);
                    num = 0;
                }
                if(isdigit(data[i + 1][j - 1])) {
                    starti = i + 1;
                    startj = j - 1;
                    bool looking = true;
                    int tempid = 0;
                    while(looking) {
                        if(isdigit(data[starti][startj + tempid])) {
                            tempid--;
                        }
                        else {
                            tempid++;
                            looking = false;
                        }
                    }
                    bool looping = true;
                    while(looping) {
                        if(isdigit(data[starti][startj + tempid])) {
                            num = (num * 10) + data[starti][startj + tempid] - '0';
                            data[starti][startj + tempid] = *".";
                            tempid++;
                        }
                        else {
                            looping = false;
                        }
                    }
                    tempnums.push_back(num);
                    num = 0;
                }
                if(isdigit(data[i + 1][j])) {
                    starti = i + 1;
                    startj = j;
                    bool looking = true;
                    int tempid = 0;
                    while(looking) {
                        if(isdigit(data[starti][startj + tempid])) {
                            tempid--;
                        }
                        else {
                            tempid++;
                            looking = false;
                        }
                    }
                    bool looping = true;
                    while(looping) {
                        if(isdigit(data[starti][startj + tempid])) {
                            num = (num * 10) + data[starti][startj + tempid] - '0';
                            data[starti][startj + tempid] = *".";
                            tempid++;
                        }
                        else {
                            
                            looping = false;
                        }
                    }
                    tempnums.push_back(num);
                    num = 0;
                }
                if(isdigit(data[i + 1][j + 1])) {
                    starti = i + 1;
                    startj = j + 1;
                    bool looking = true;
                    int tempid = 0;
                    while(looking) {
                        if(isdigit(data[starti][startj + tempid])) {
                            tempid--;
                        }
                        else {
                            tempid++;
                            looking = false;
                        }
                    }
                    bool looping = true;
                    while(looping) {
                        if(isdigit(data[starti][startj + tempid])) {
                            num = (num * 10) + data[starti][startj + tempid] - '0';
                            data[starti][startj + tempid] = *".";
                            tempid++;
                        }
                        else {
                            looping = false;
                        }
                    }
                    tempnums.push_back(num);
                    num = 0;
                }
                if(tempnums.size() == 2) {
                    resultcheck.push_back(tempnums[0] * tempnums[1]);
                    result += tempnums[0] * tempnums[1];
                }
            }
        }
    }
    
    for(int i = 0; i < resultcheck.size(); i++) {
        std::cout << resultcheck[i] << std::endl;
    }
    std::cout << "result: " << result << std::endl;
    
    return 0;
}