#include <iostream>
#include <string>
#include <vector>
#include <array>

std::vector<std::vector<int>> testvalues = {
    {7, 9}, 
    {15, 40}, 
    {30, 200},
};
std::vector<std::vector<int>> values = {
    {53, 250}, 
    {91, 1330}, 
    {67, 1081},
    {68, 1025}
};
std::vector<std::vector<int>> results;
std::vector<int> wins;

int result = 1;
int main() {
    //values = testvalues;
    std::cout << "wins: " << std::endl;
    for(int i = 0; i < values.size(); i++) {
        std::vector<int> temp;
        int tempwin = 0;
        for(int j = 0; j < values[i][0]; j++) {
            int distance = j * (values[i][0] - j);
            temp.push_back(distance);
            if(distance > values[i][1]) {
                tempwin++;
            }
            
        }
        wins.push_back(tempwin);
        results.push_back(temp);
        std::cout << i << ": " << tempwin << std::endl;
        result *= tempwin;
    }
    std::cout << "result: " << result << std::endl;
    return 0;
}