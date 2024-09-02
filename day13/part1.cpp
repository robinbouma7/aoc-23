#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

std::ifstream datafile;
std::vector<std::vector<std::vector<char>>> grids;

//kijken op welke plekken er 2 naast elkaar zijn,
//alle andere rijen kijken of op dezelfde plakken 2 naast elkaar zijn
//als er 1 uit komt dan is het een spiegelpunt hopelijk

//dit werkt maar je kan meerdere spiegelpunten hebben
//hiervoor moet je de 2 rijen er naast ook checken, dit word wel moeilijker 

//volgende manier:
//draai de vector om zodat je makkelijk 2 vectors kan vergelijken
//misschien kan dit bij het parsen al gedaan worden

int main(int argc, char *argv[]) {
    if(argc > 1 && (std::strcmp(argv[1], "-t") == 0 || std::strcmp(argv[1], "--test") == 0)) {
        std::cout << "TEST DATA\n\n";
        datafile.open("testdata.txt");
    }
    else {
        datafile.open("data.txt");
    }
   
    if (datafile.is_open()) {
         
        std::vector<std::vector<char>> tempvec;
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            if(line.length() > 0) {
                if(tempvec.size() == 0) {
                    for(int i = 0; i < line.length(); i++) {
                        std::vector<char> temp;
                        temp.push_back(line[i]);
                        tempvec.push_back(temp);
                    }
                }
                for(int i = 0; i < line.length(); i++) {
                    tempvec[i].push_back(line[i]);
                }
            }
            else {
                std::cout << "new grid\n";
                grids.push_back(tempvec);
                tempvec.clear();
            }
        }
        if(tempvec.size() > 0) {
            std::cout << "added last grid\n";
            grids.push_back(tempvec);
        }
    }
    for(int i = 0; i < grids.size(); i++) {
        for(int j = 0; j < grids[i].size(); j++) {
            for(int k = 0; k < grids[i][j].size(); k++) {
                std::cout << grids[i][j][k];
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        //find mirror point in grid
        //check if there are 2 rows that are the same next to each other
        //check the 2 next to those

        //eerst hetzelfde als ik in de vorige had gedaan
        //als er meerdere punten zijn dan moet je al die punten checken met de rijen er naast
        //als er nog meer 1 over is dan is het gelukt
        //wel voorzichtig zijn met out of bounds
    }
    std::cout << "done\n";
    return 0;
}