#include<iostream>
#include<fstream>
#include"myHeader.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void ContinueButton(RenderWindow& window, int size, int ScoreP1, int ScoreP2, int turn, int size_arr, int board[][5])
{

	// Score P1

	ifstream scoreP1("scorep1.txt");
	if (!scoreP1.is_open())
	{
		cout << "Unable to Open scorep1.txt" << endl;
		return;
	}
	scoreP1 >> ScoreP1;
	scoreP1.close();

	// Score P2

	ifstream scoreP2("scorep2.txt");
	if (!scoreP2.is_open())
	{
		cout << "Unable to Open scorep2.txt" << endl;
		return;
	}
	scoreP2 >> ScoreP2;
	scoreP2.close();

	// Board Position

	ifstream Board("boardposition.txt");
	if (!Board.is_open())
	{
		cout << "Unable to Open Board.txt" << endl;
		return;
	}
	for (int i = 0;i < size_arr;i++)
	{
		for (int j = 0;j < size_arr;j++)
		{
			Board >> board[i][j];
		}
	}
	Board.close();

	// Turn

	ifstream inturn("turn.txt");
	if (!inturn.is_open())
	{
		cout << "Error in Opening turn.txt" << endl;
		return;
	}
	inturn >> turn;
	inturn.close();


	mainGraphics(window, size, ScoreP1, ScoreP2, turn, board);
}