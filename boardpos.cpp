#include<fstream>
#include<iostream>
using namespace std;
void boardWriting(int board[][5], const int size)
{
    ofstream inb("boardposition.txt");

    // Check if the file is open successfully
    if (!inb.is_open())
    {
        cout << "Error in opening the file boardsposition.txt" << endl;
        return;
    }
    // Read bead positions from the file and store them in the array

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            inb << board[i][j] << endl;
            //cout << board[i][j] << endl;
        }
    }
    inb.close();
}