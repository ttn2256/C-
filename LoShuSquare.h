/******************************************************************
 CIS 22B
 Lab 6: Initialize a square, and get input from Player.h file. It uses the
 the input to calculate the sums of rows, columns and diagonals and compare
 to conclude if it's a Lo Shu Square or not
 Author: Tuan Nguyen
 Date: 06/21/2018
 *******************************************************************/

#ifndef LoShuSquare_h
#define LoShuSquare_h

#include <iostream>
using namespace std;

class LoShuSquare
{
private:
    int square[3][3];
public:
    //Constructor
    LoShuSquare() {
        //initialize square = 0
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                square[i][j] = 0;
            }
        }
    }
    
    //Destructor
    ~LoShuSquare() {
    }
    
    //print square function
    void printBoard() {
        for(int row=0; row<3; row++) {
            for(int col=0; col<3; col++) {
                cout << square[row][col] << " ";
            }
            cout << endl;
        }
    }
    
    //fill square function
    void fillSquare(int row, int col, int value) {
        square[row][col] = value;
        //print Board
        printBoard();
    }

    //check if square is LoShu Square
    void checkSquare()
    {
        // declare variables
        int sumDiag[2], rowSub[3], colSub[3];
        int  sumCol = 0, sumRow = 0;
        
        // adding the sum of each row
        for (int row = 0; row < 3; row++) {
            sumRow = 0;
            for (int col = 0; col < 3; col++) {
                sumRow += square[row][col];
                rowSub[row] = sumRow;
            }
        }
        
        // adding the sum of each column
        for (int col = 0; col < 3; col++) {
            sumCol = 0;
            for (int row = 0; row < 3; row++) {
                sumCol += square[row][col];
                colSub[col] = sumCol;
            }
        }
        
        //intialize diagonal sum 0
        sumDiag[0] = 0;
        
        // adding the sum of diagonal left to right
        
        for (int row = 0; row < 3; row++) {
            sumDiag[0] += square[row][row];
        }
        
        //initialize diagonal sum 1
        sumDiag[1] = 0;
        
        // adding the sum of diagonal right to left
        for (int row = 0; row < 3; row++) {
            sumDiag[1] += square[row][3 - 1 - row];
        }
        
        //checking if the sum of row, column and diagonal
        //are equal. If it's equal, it's LoShuSquare
        
        bool flag = true;
        int sum = rowSub[0];
        
        //check if each row's sum equals the sum of row 1
        for (int i = 1; i < 3; i++) {
            flag = flag && (sum == rowSub[i]);
        }
        //check if each column's sum equals the sum of row 1
        for (int j = 0; j < 3; j++) {
            flag = flag && (sum == colSub[j]);
        }
        //check if each diagonal's sum equals the sum of row 1
        for (int g = 0; g < 2; g++) {
            flag = flag && (sum == sumDiag[g]);
        }
        
        if (flag) {
            cout << "It is the Lo Shu Square" << endl;
        } else {
            cout << "It is NOT the Lo Shu Square" << endl;
        }
    }
};

#endif /* LoShuSquare_h */
