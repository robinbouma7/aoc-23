#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <array>
#include <algorithm>

std::ifstream datafile;

std::vector<std::array<int, 2>> five_of_a_kind;
std::vector<std::array<int, 2>> four_of_a_kind;
std::vector<std::array<int, 2>> full_house;
std::vector<std::array<int, 2>> three_of_a_kind;
std::vector<std::array<int, 2>> two_pair;
std::vector<std::array<int, 2>> one_pair;
std::vector<std::array<int, 2>> high_card;

int result = 0;

bool compare(std::array<int, 2> &a, std::array<int, 2> &b) {
    return a[0] < b[0];
}

int main() {
    datafile.open("data.txt");

    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            std::string cards = line.substr(0, 5);
            std::vector<std::array<int, 2>> card_values;
            std::string cardnums = "";
            for(int i = 0; i < cards.length(); i++) {
                int tempdigit = 0;
                std::string tempstr = "";
                if(isdigit(cards[i])) {
                    tempdigit = cards[i] - '0';
                    tempstr = "0" + std::to_string(tempdigit);
                }
                else if(cards[i] == 'T') {
                    tempstr = "10";
                    tempdigit = 10;
                }
                else if(cards[i] == 'J') {
                    tempstr = "11";
                    tempdigit = 11;
                }
                else if(cards[i] == 'Q') {
                    tempstr = "12";
                    tempdigit = 12;
                }
                else if(cards[i] == 'K') {
                    tempstr = "13";
                    tempdigit = 13;
                }
                else if(cards[i] == 'A') {
                    tempstr = "14";
                    tempdigit = 14;
                }
                else {
                    std::cout << "Error: invalid card value" << std::endl;
                    break;  
                }
                //std::cout << cards[i] << " > " << tempstr << std::endl;
                cardnums += tempstr;
                bool gotvalue = false;
                for(int j = 0; j < card_values.size(); j++) {
                    if(card_values[j][0] == tempdigit) {
                        card_values[j][1]++;
                        gotvalue = true;
                        break;
                    }
                }
                if(!gotvalue) {
                    std::array<int, 2> temparray = {tempdigit, 1};
                    card_values.push_back(temparray);
                }
                
            }
            int cardnumber = 0;
            for(int i = 0; i < cardnums.length(); i++) {
                cardnumber = (cardnumber * 10) + (cardnums[i] - '0');
            }
            std::cout << cardnumber << std::endl;
            //calculate bid
            int bid = 0;
            for(int i = 5; i < line.length(); i++) {
                if(isdigit(line[i])) {
                    bid = (bid * 10) + (line[i] - '0');
                }
            }
            std::array<int, 2> valarr = {cardnumber, bid};
            //calculate hand
            if(card_values.size() == 1) {
                five_of_a_kind.push_back(valarr);
                
            }
            else if(card_values.size() == 2) {
                if(card_values[0][1] == 4 || card_values[1][1] == 4) {
                    four_of_a_kind.push_back(valarr);
                    
                }
                else if(card_values[0][1] == 3 || card_values[1][1] == 3) {
                    full_house.push_back(valarr);
                    
                }
                else if(card_values[0][1] == 2 || card_values[1][1] == 2) {
                    three_of_a_kind.push_back(valarr);
                   
                }
            }
            else if(card_values.size() == 3) {
                if(card_values[0][1] == 3 || card_values[1][1] == 3 || card_values[2][1] == 3) {
                    three_of_a_kind.push_back(valarr);
                    
                }
                else if(card_values[0][1] == 2 || card_values[1][1] == 2 || card_values[2][1] == 2) {
                    two_pair.push_back(valarr);
                    
                }
            }
            else if(card_values.size() == 4) {
                one_pair.push_back(valarr);
            }
            else {
                high_card.push_back(valarr);
            }
        }
    }
    std::sort(five_of_a_kind.begin(), five_of_a_kind.end(), compare);
    std::sort(four_of_a_kind.begin(), four_of_a_kind.end(), compare);
    std::sort(full_house.begin(), full_house.end(), compare);
    std::sort(three_of_a_kind.begin(), three_of_a_kind.end(), compare);
    std::sort(two_pair.begin(), two_pair.end(), compare);
    std::sort(one_pair.begin(), one_pair.end(), compare);
    std::sort(high_card.begin(), high_card.end(), compare);

    int rank = 1;
    for(int i = 0; i < high_card.size(); i++) {
        //std::cout << "rank " << rank << ": " << high_card[i][0] << " " << high_card[i][1] << std::endl;
        result += rank * high_card[i][1];
        rank++;
    }
    for(int i = 0; i < one_pair.size(); i++) {
        //std::cout << "rank " << rank << ": " << one_pair[i][0] << " " << one_pair[i][1] << std::endl;
        result += rank * one_pair[i][1];
        rank++;
    }
    for(int i = 0; i < two_pair.size(); i++) {
        //std::cout << "rank " << rank << ": " << two_pair[i][0] << " " << two_pair[i][1] << std::endl;
        result += rank * two_pair[i][1];
        rank++;
    }
    for(int i = 0; i < three_of_a_kind.size(); i++) {
        //std::cout << "rank " << rank << ": " << three_of_a_kind[i][0] << " " << three_of_a_kind[i][1] << std::endl;
        result += rank * three_of_a_kind[i][1];
        rank++;
    }
    for(int i = 0; i < full_house.size(); i++) {
        //std::cout << "rank " << rank << ": " << full_house[i][0] << " " << full_house[i][1] << std::endl;
        result += rank * full_house[i][1];
        rank++;
    }
    for(int i = 0; i < four_of_a_kind.size(); i++) {
        //std::cout << "rank " << rank << ": " << four_of_a_kind[i][0] << " " << four_of_a_kind[i][1] << std::endl;
        result += rank * four_of_a_kind[i][1];
        rank++;
    }
    for(int i = 0; i < five_of_a_kind.size(); i++) {
        //std::cout << "rank " << rank << ": " << five_of_a_kind[i][0] << " " << five_of_a_kind[i][1] << std::endl;
        result += rank * five_of_a_kind[i][1];
        rank++;
    }
    std::cout << "result: " << result << std::endl;
    /*std::cout << "values: " << std::endl;
    std::cout << "five of a kind: " << five_of_a_kind.size() << std::endl;
    std::cout << "four of a kind: " << four_of_a_kind.size() << std::endl;
    std::cout << "full house: " << full_house.size() << std::endl;
    std::cout << "three of a kind: " << three_of_a_kind.size() << std::endl;
    std::cout << "two pair: " << two_pair.size() << std::endl;
    std::cout << "one pair: " << one_pair.size() << std::endl;
    std::cout << "high card: " << high_card.size() << std::endl;
    std::cout << "total: " << five_of_a_kind.size() + four_of_a_kind.size() + full_house.size() + three_of_a_kind.size() + two_pair.size() + one_pair.size() + high_card.size() << std::endl;
    */
    return 0;
}