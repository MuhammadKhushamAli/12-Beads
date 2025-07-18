#include<fstream>
#include<iostream>
using namespace std;

void FileWriteScoreP1(int ScoreP1)
{
    // Open the file for reading positions
    ofstream outscorep1("scorep1.txt");

    // Check if the file is open successfully
    if (!outscorep1.is_open())
    {
        cout << "Error in opening the file scorep1.txt" << endl;
        return;
    }
    outscorep1 << ScoreP1;
    outscorep1.close();
    return;
}