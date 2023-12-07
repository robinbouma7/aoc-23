#include <iostream>
#include <string>
#include <vector>
#include <array>

int64_t testvalue[2] = {71530, 940200};
int64_t value[2] = {53916768, 250133010811025};

int first = -1;
int last = -1;

int main() {
    //uncomment to use the test values
    //value[0] = testvalue[0];
    //value[1] = testvalue[1];
    

    int tempwin = 0;
    for(int j = 0; j < value[0]; j++) {
        int64_t distance = j * (value[0] - j);
        if(distance > value[1]) {
            tempwin++;
            if(first == -1) {
                first = j;
            }
            last = j;
        }
        
    }
    std::cout << "fake wins: " << tempwin << std::endl;
    std::cout << "first: " << first << std::endl;
    std::cout << "last: " << last << std::endl;
    std::cout << "real wins: " << (last - first) + 1 << std::endl;
    return 0;
}