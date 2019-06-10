/******************************************************************
 CIS 22B
 Lab 6: User can select whatever rows and columns to input their guesses
 Player constructor get fillSquare and checkSquare methods from LoShu
 Square.h to calculate if the numbers input of the square make it a
 Lo Shu Square or not.
 Author: Tuan Nguyen
 Date: 06/21/2018
 *******************************************************************/

#ifndef Player_h
#define Player_h

#include <iostream>
#include "LoShuSquare.h"
using namespace std;

class Player
{
    private:
        //declare variables
        int row, col, value;
        char action;
    public:
        Player(LoShuSquare g)
        {
            do {
                //getting input for rows, columns and values of the square
                cout << "Input row (0-2): ";
                cin >> row;
                cout << "Input column (0-2): ";
                cin >> col;
                cout << "Input number (1-9): ";
                cin >> value;
                //only let user input from 1-9 for numbers and 0-2 for rows and columns
                if (value < 1 || value > 9 || row < 0 || row > 2 || col < 0 || col > 2) {
                    cout << "Invalid input" << endl;
                    continue;
                } else {
                    //fill square
                    g.fillSquare(row, col, value);
                }
                cout << "Do you want to continue to input (y/n)? : ";
                cin >> action;
            } while (action == 'y' || action == 'Y');
            
            //check square from LoShuSquare.h
            g.checkSquare();
        }
};

#endif /* Player_h */
