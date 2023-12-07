#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <array>

std::ifstream datafile;
std::string data;
int result = 0;

int main() {
    datafile.open("data.txt");
    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            //parse data
            if(line.empty()) {
                std::cout << "empty line" << std::endl;
            }
            else {

                //get numbers
                std::vector<int> numbers;

                for(int i = 0; i < line.length(); i++) {
                    
                    if(isdigit(line[i])) {
                        int tempint = line[i] - '0';
                        numbers.push_back(tempint);
                    }
                    else {
                        if(line.length() - i >= 4) {
                            //three, seven, eight
                            if(line[i] == *"t" && line[i + 1] == *"h" && line[i + 2] == *"r" && line[i + 3] == *"e" && line[i + 4] == *"e") {
                                //std::cout << "found three" << std::endl;
                                numbers.push_back(3);
                               
                            }
                            else if(line[i] == *"s" && line[i + 1] == *"e" && line[i + 2] == *"v" && line[i + 3] == *"e" && line[i + 4] == *"n") {
                                //std::cout << "found seven" << std::endl;
                                numbers.push_back(7);
                                
                            }
                            else if(line[i] == *"e" && line[i + 1] == *"i" && line[i + 2] == *"g" && line[i + 3] == *"h" && line[i + 4] == *"t") {\
                                //std::cout << "found eight" << std::endl;
                                numbers.push_back(8);
                                
                            }
                           
                            
                           
                        }
                        if(line.length() - i >= 3) {
                            //four, five, nine
                            if(line[i] == *"f" && line[i + 1] == *"o" && line[i + 2] == *"u" && line[i + 3] == *"r") {
                                //std::cout << "found four" << std::endl;
                                numbers.push_back(4);
                                
                            }
                            else if(line[i] == *"f" && line[i + 1] == *"i" && line[i + 2] == *"v" && line[i + 3] == *"e") {
                                //std::cout << "found five" << std::endl;
                                numbers.push_back(5);
                                
                            }
                            else if(line[i] == *"n" && line[i + 1] == *"i" && line[i + 2] == *"n" && line[i + 3] == *"e") {
                                //std::cout << "found nine" << std::endl;
                                numbers.push_back(9);

                            }
                            else if(line[i] == *"z" && line[i + 1] == *"e" && line[i + 2] == *"r" && line[i + 3] == *"o") {
                                std::cout << "found zero" << std::endl;
                                numbers.push_back(0);

                            }

                            
                        }
                        if(line.length() - i >= 2) {
                            //one, two, six
                            if(line[i] == *"o" && line[i + 1] == *"n" && line[i + 2] == *"e") {
                                //std::cout << "found one" << std::endl;
                                numbers.push_back(1);
                            }
                            else if(line[i] == *"t" && line[i + 1] == *"w" && line[i + 2] == *"o") {
                                //std::cout << "found two" << std::endl;
                                numbers.push_back(2);
                            }
                            else if(line[i] == *"s" && line[i + 1] == *"i" && line[i + 2] == *"x") {
                                //std::cout << "found six" << std::endl;
                                numbers.push_back(6);
                            }
                        }
                       
                       
                    }
                }
                if(numbers.size() != 0) {
                    int val1 = numbers[0];
                    int val2 = numbers[numbers.size() - 1];
                    std::cout << val1 << "\t" << val2  << "\t=" << (val1 * 10) + val2 << std::endl;
                    result += (val1 * 10) + val2;
                }
                else {
                    std::cout << "no numbers found" << std::endl;
                }
            }
            
        }
    }

    std::cout << "final value: " << result << std::endl;



    return 0;
}