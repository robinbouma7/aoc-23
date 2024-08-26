#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ifstream datafile;

std::vector<std::vector<char>> grid;
std::vector<std::string> springs;
std::vector<std::vector<int>> combinations;
std::vector<int> unknowns;
int result;
int temptot = 0;
int tempcount = 0;

bool isvalid(std::string input, std::vector<int> combination)  {
    std::vector<int> tempvec;
    int comblen = 0;
    for(int i = 0; i < input.length(); i++) {

        if(input[i] == *"#") {
            comblen++;
        }
        else if(comblen > 0) {
            tempvec.push_back(comblen);
            comblen = 0;
        }
    }
    if(comblen > 0) {
        tempvec.push_back(comblen);
    }
    if(tempvec.size() != combination.size()) {
        return false;
    }
    for(int i = 0; i < tempvec.size(); i++) {
        if(tempvec[i] != combination[i]) {
            return false;
        }
    }
    std::cout << tempcount  << "\t" << input << "\n";
    tempcount++;
    return true;
}
void tryallposibilities(std::string input, std::vector<int> combinations) {
    //recursion or some shit
    int varpos = input.find(*"?");
    if(varpos == -1) {
        //std::cout << "no more question marks\n";
        //std::cout << input << "\n";
        if(isvalid(input, combinations)) {
            temptot++;
        }
    }
    else {
        std::string tempstr = input;
        //std::cout << tempstr << "\n";

        tempstr[varpos] = (char)*"#";
        
        tryallposibilities(tempstr, combinations);
        tempstr[varpos] = (char)*".";
        tryallposibilities(tempstr, combinations);
    }
}

int main() {
    datafile.open("testdata.txt");

    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            line += " ";

            bool looping = true;
            std::vector<char> tempvec;
            int ident = 0;
            std::string tempstr = "";
            int tempint = 0;
            while(looping) {
                if(line[ident] == *" ") {
                    std::cout << "done after " << ident << "\n";
                    std::cout << "tempstr: " << tempstr << "\n";
                    looping = false;
                    break;
                }
                if(line[ident] == *"?") {
                    tempint++;
                }
                tempvec.push_back(line[ident]);
                tempstr += line[ident];
                ident++;
            }
            for(int i = 0; i < 4; i++) {
                tempstr = tempstr + "?" + tempstr;
            }
            grid.push_back(tempvec);
            springs.push_back(tempstr);
            unknowns.push_back(tempint);
            std::cout << "test\n";
            std::vector<int> tempvec2;
            int tempnum = 0;
            for(int i = ident; i < line.length(); i++) {
                if(isdigit(line[i])) {
                    tempnum = (tempnum * 10) + (line[i] - '0');
                }
                else if(tempnum != 0) {
                    for(int i = 0; i < 4; i++) {
                        tempvec2.push_back(tempnum);
                    }
                    tempnum = 0;
                }
            }
            combinations.push_back(tempvec2);
        }
        std::cout << "done parsing\n";
        for(int i = 0; i < grid.size(); i++) {
            temptot = 0;
            std::cout << "springlist: " << springs[i] << "\n";
            tryallposibilities(springs[i], combinations[i]);
            std::cout << "possibilities: " << temptot << "\n";
            result += temptot;
            tempcount = 0;
        }
        std::cout << "result: " << result << "\n";
    }
    return 0;
}