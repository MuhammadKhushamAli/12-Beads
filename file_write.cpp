#include<SFML/Graphics.hpp>
#include<fstream>
#include<iostream>
using namespace std;
using namespace sf;

void FileWrite(Vector2f array1[][5],const int size_arr)
{
    // Open the file for reading positions
    ofstream out("beadsposition.txt");

    // Check if the file is open successfully
    if (!out.is_open())
    {
        cout << "Error in opening the file beadsposition.txt" << endl;
        return;
    }
    for (int i = 0;i < size_arr;i++)
    {
        for (int j = 0;j < size_arr;j++)
        {
            //if (array1[i][j].x == 0 && array1[i][j].y == 0)
            //{
            //    continue;
            //}
            //else
            //{
                out << array1[i][j].x << " " << array1[i][j].y << endl;
            //}
        }
    }
    out.close();
}