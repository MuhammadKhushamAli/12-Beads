#include<iostream>
#include<fstream>
#include"myHeader.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void StartButton(RenderWindow& window, int size, int ScoreP1, int ScoreP2, int turn, int size_arr, int board[][5])
{
	// Reseting 

	ScoreP1 = 0;
	ScoreP2 = 0;

	// Reading From Backup Files

	// Board Position

	ifstream BackupBoard("boardposition(Backup).txt");
	if (!BackupBoard.is_open())
	{
		cout << "Unable to Open Board(Backup).txt" << endl;
		return;
	}
	for (int i = 0;i < size_arr;i++)
	{
		for (int j = 0;j < size_arr;j++)
		{
			BackupBoard >> board[i][j];
		}
	}
	BackupBoard.close();

	// Writing on Under Use Files


	// Score P1

	FileWriteScoreP1(ScoreP1);

	// Score P2

	FileWriteScoreP2(ScoreP2);

	// Turn

	FileWriteturn(turn);

	// Board Position

	boardWriting(board, size_arr);
	mainGraphics(window, size, ScoreP1, ScoreP2, turn, board);
}