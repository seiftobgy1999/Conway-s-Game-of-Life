#include "GameBoard.h"
#include "View.cpp"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

Board::Board(){
    vector<vector <int> > grid;
    this->grid = FileRead(grid);
}



vector<vector <int>> Board::getGrid(){
    return this->grid;
}




void Board::nextGeneration(){
    int counter=0;
    vector<vector<int>> temp = this->grid;
    for (int row=0; row<10; row++){
        for(int col=0; col<10; col++){           
            if (0<=(row-1) && (row-1)<10 && 0<=(col) && (col)<10 && (temp[row-1][col]==1)){  // check top
                counter++;
            }

            if (0<=(row+1) && (row+1)<10 && 0<=(col) && (col)<10 && temp[row+1][col]==1){    //check bottom
                counter++;
            }
            
            if ( 0<=(row) && (row)<10 && 0<=(col+1) && (col+1)<10 && temp[row][col+1]==1){  // check right
                counter++;
            }
            
            if (0<=(row) && (row)<10 && 0<=(col-1) && (col-1)<10 && temp[row][col-1]==1){  //   check left
                counter++;
            }


            if (0<=(row-1) && (row-1)<10 && 0<=(col+1) && (col+1)<10 && temp[row-1][col+1]==1){  // check top right diag
                counter++;
            }


            if (0<=(row+1) && (row+1)<10 && 0<=(col-1) && (col-1)<10 && temp[row+1][col-1]==1){  //check bottom left diag
                counter++;
            }   
            

            if (0<=(row+1) && (row+1)<10 && 0<=(col+1) && (col+1)<10 && temp[row+1][col+1]==1){ // check bottom right diag
                counter++;
            }
            

            if (0<=(row-1) && (row-1)<10 && 0<=(col-1) && (col-1)<10 && temp[row-1][col-1]==1){  // check top left diag
                counter++;
            }
            

            if (counter<=1){    //0 or 1 neighbours = dies
                this->grid[row][col] = 0;
            }

            if (counter>=4){    //4 or more neighbours = dies
                this->grid[row][col] = 0;
            }

            if (counter==3){
                this->grid[row][col] = 1; //3 neighbours = populate
            }

            counter = 0;
        }
    }
}

/**int main(){
    Board x = Board();
    vector<vector<int>> z = x.getGrid();
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << z[i][j];
        }
        cout<<"\n";
    }
}*/