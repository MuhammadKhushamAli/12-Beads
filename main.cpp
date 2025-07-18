#include<iostream>
#include<SFML/Graphics.hpp>
#include"myHeader.h"
using namespace sf;
using namespace std;

int main()
{
	const float size = 1000.0;
	const int size_arr = 5;
	int board[size_arr][size_arr];
	int ScoreP1 = 0, ScoreP2 = 0;
	int turn = 0;
	RenderWindow window(VideoMode(size, size), "12-Beads Game", Style::Default);
	window.setFramerateLimit(60);
	StartWindow(window, size, ScoreP1, ScoreP2, turn,  board);
	return 0;
}