#include<fstream>
#include<iostream>
using namespace std;

void FileWriteturn(int turn)
{
    // Open the file for reading positions
    ofstream outturn("turn.txt");

    // Check if the file is open successfully
    if (!outturn.is_open())
    {
        cout << "Error in opening the file turn.txt" << endl;
        return;
    }
    outturn << turn;
    outturn.close();
}