#include<fstream>
#include<iostream>
using namespace std;

void FileWriteScoreP2(int ScoreP2)
{
    // Open the file for reading positions
    ofstream outscorep2("scorep2.txt");

    // Check if the file is open successfully
    if (!outscorep2.is_open())
    {
        cout << "Error in opening the file scorep2.txt" << endl;
        return;
    }
    outscorep2 << ScoreP2;
    outscorep2.close();
    return;
}