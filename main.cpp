#include "GameBoard.cpp"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    int generations;
    cout << "Enter The number of generations you would like to generate" << "\n";
    cin >> generations;

    Board test = Board();
    vector<vector<int>> grid1 = test.getGrid();
    cout << "Beginning Generation \n";
    cout << "+---------------------+\n";
    for (int i = 0; i < 10; i++) 
    { 
        cout << "|";
        for (int j = 0; j < 10; j++) 
        {
            if(grid1[i][j] == 0){
                cout << " .";
            }
            else{
                cout << " *";
            }
        } 
        cout << " |\n";
    } 
    cout << "+---------------------+\n";

    for(int count = 1; count <= generations; count++){
        test.nextGeneration();
        grid1 = test.getGrid();
        cout << "\n";
        cout << "\n";
        cout << "Generation " << count << "\n";
        cout << "+---------------------+\n";
        for (int i = 0; i < 10; i++) 
        { 
            cout << "|";
            for (int j = 0; j < 10; j++) 
            {
                if(grid1[i][j] == 0){
                    cout << " .";
                }
                else{
                    cout << " *";
                }
        } 
            cout << " |\n";
    } 
        cout << "+---------------------+\n";
    }

    for(int i = 0; i <=3; i++){
        cout << "\n";
    }

    cout << "Current Generation" << "\n";

    View(test.getGrid());
    WriteToFile("write.txt", test.getGrid());
    return 0;
}
