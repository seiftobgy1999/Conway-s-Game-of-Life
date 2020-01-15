/**
 * \file GameBoard.h
 * \author Seif El Tobgy
 * \brief This header file is for the GameBoard ADT module
 */
#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_
#include <vector>

using namespace std;

class Board{
    private:
        vector<vector <int>> grid;

    public:
        /**
         * \brief This is the Board constructor
         * \details This constructs a Board object which creates the grid
         */
        Board();
        /**
         * \brief This is a method for the Board object
         * \details This method is a mutator that goes through a Board objects grid and checks how many alive cells each has and then applies the rule on the Board and mutates it.
         */
        void nextGeneration();
        /**
         * \brief This is a method for the Board object
         * \details This method is a accessor that gets the grid of the board object
         * \return This returns the grid of the board object.
         */
        vector<vector <int>> getGrid();
};

#endif