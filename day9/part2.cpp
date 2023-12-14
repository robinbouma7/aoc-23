#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ifstream datafile;
int64_t result = 0;
std::vector<int> nextnums;

int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            line += " ";
            std::vector<std::vector<int>> grid;
            std::vector<int> numbers;
            bool isnegative = false;
            int tempnum = 0;
            for(int i = 0; i < line.length(); i++) {
                if(line[i] == '-') {

                    isnegative = true;
                }
                else if(isdigit(line[i])) {
                    tempnum = (tempnum * 10) + (line[i] - '0');
                }
                else if(line[i] == ' ' && tempnum != -1) {
                    if(isnegative) {
                        tempnum *= -1;
                        isnegative = false;
                    }
                    //std::cout << "added number: " << tempnum << std::endl;
                    numbers.push_back(tempnum);
                    tempnum = 0;
                }
            }
            grid.push_back(numbers);

            bool looping = true;
            int ident = 0;
            while(looping) {
                std::vector<int> numbers;
                int prevnum = grid[ident][0];
                for(int i = 1; i < grid[ident].size(); i++) {
                    //std::cout << "added num: " << grid[ident][i] - prevnum << std::endl;
                    numbers.push_back(grid[ident][i] - prevnum);
                    prevnum = grid[ident][i];
                }
                bool allzero = true;
                for(int i = 0; i < numbers.size(); i++) {
                    if(numbers[i] != 0) {
                        //std::cout << "not all 0" << std::endl;
                        allzero = false;
                        break;
                    }
                }
                if(allzero) {
                    //std::cout << "found all zeroes." << std::endl;
                    looping = false;
                    grid.push_back(numbers);
                    break;
                }
                grid.push_back(numbers);
                ident++;
            }
            grid[grid.size() - 1].insert(grid[grid.size() - 1].begin(), 0);
            for(int i = grid.size() - 1; i > 0; i--) {
                int num1 = grid[i][0];
                int num2 = grid[i - 1][0];
                grid[i - 1].push_back(num2 - num1);
                grid[i - 1].insert(grid[i - 1].begin(), num2 - num1);
                //std::cout << "num1: " << num1 << std::endl;
                //std::cout << "num2: " << num2 << std::endl;
                //std::cout << "added num: " << num2 - num1 << std::endl;
            }
            std::cout << "final number: " << grid[0][0] << std::endl;	 
            nextnums.push_back(grid[0][0]); 
            result += grid[0][0];

        }
        std::cout << "result: " << result << std::endl;
    }
    return 0;
}