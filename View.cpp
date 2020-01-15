

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> FileRead(vector<vector <int>> grid){
    fstream inFile("begin_game.txt", ios::in);
    if (!inFile){
        cout << "File not found";
        throw "ios_base::failure";
    }
    int x;
    for (int i = 0; i < 10; i++){ 
        vector<int> temp;
        for (int j = 0; j < 10; j++) {
            inFile>> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    inFile.close();
    return grid;
}

void WriteToFile(const char *filename, vector<vector <int>> grid){
    fstream inFile;
    inFile.open(filename, ios::app);
    if(inFile.is_open()){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(grid[i][j] == 0){
                    inFile<< " 0";
                }
                else{
                    inFile<<" 1";
                }
            }
            inFile << "\n";
        }

        inFile << "\n";
        inFile << "\n";
        inFile.close();
    }
}

void View(vector<vector <int>> grid){
    int i;
    int j;
    for (i = 0; i < 10; i++){
            for (j = 0; j < 10; j++){
                if (grid[i][j] == 0){
                    cout << ".";
                }
                else{
                    cout << "*";
                }
                
        }
        cout << "\n";
    }
}
