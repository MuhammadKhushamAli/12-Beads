#include<iostream>
#include<fstream>
#include"myHeader.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void Winner(RenderWindow& window, int size, int ScoreP1, int turn, int ScoreP2, int board[][5])
{
	// Texture 
	Texture win;
	win.loadFromFile("Win.png");
	Sprite Winner(win);
	Winner.setPosition(Vector2f(160.0f, 200.0f));


	Texture Home;
	Home.loadFromFile("home.png");
	Sprite home(Home);
	home.setPosition(Vector2f(450.0f, 650.0f));
	// Text
	Font font;
	font.loadFromFile("Oswald-Bold.ttf");
	Text Player1("Player1 Won the Game", font, 60);
	Text Player2("Player2 Won the Game", font, 60);
	Player1.setPosition(Vector2f(220.0f, 450.0f));
	Player1.setFillColor(Color(255, 0, 0));
	Player2.setPosition(Vector2f(220.0f, 450.0f));
	Player2.setFillColor(Color(0, 128, 0));
	// Game Loop
	while (window.isOpen())
	{
		Event occasion;
		while (window.pollEvent(occasion))
		{
			if (occasion.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear(Color(147, 209, 255));
		// Drawing
		window.draw(Winner);
		if (ScoreP1 == 12)
		{
			window.draw(Player1);
			window.draw(home);
			if (occasion.MouseEntered)
			{
				Vector2i mousePos = Mouse::getPosition(window);
				if (mousePos.x >= 440.0f && mousePos.x <= 585.0f && mousePos.y >= 640.0f && mousePos.y <= 740.0f)
				{
					home.setScale(Vector2f(1.1f, 1.1f));
					Home.setSmooth(true);
				}
				if (mousePos.x < 440.0f || mousePos.x > 585.0f || mousePos.y < 640.0f || mousePos.y > 740.0f)
				{
					home.setScale(Vector2f(1.0f, 1.0f));
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousepos = Mouse::getPosition(window);
				if (mousepos.x >= 440.0f && mousepos.x <= 585.0f && mousepos.y >= 640.0f && mousepos.y <= 740.0f)
				{
					ScoreP1 = 0;
					FileWriteScoreP1(ScoreP1);
					ScoreP2 = 0;
					FileWriteScoreP2(ScoreP2);
					StartWindow(window, size, ScoreP1, ScoreP2, turn, board);
				}
			}
		}
		if (ScoreP2 == 12)
		{
			window.draw(Player2);
			window.draw(home);
			if (occasion.MouseEntered)
			{
				Vector2i mousePos = Mouse::getPosition(window);
				if (mousePos.x >= 440.0f && mousePos.x <= 585.0f && mousePos.y >= 640.0f && mousePos.y <= 740.0f)
				{
					home.setScale(Vector2f(1.1f, 1.1f));
					Home.setSmooth(true);
				}
				if (mousePos.x < 440.0f || mousePos.x > 585.0f || mousePos.y < 640.0f || mousePos.y > 740.0f)
				{
					home.setScale(Vector2f(1.0f, 1.0f));
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousepos = Mouse::getPosition(window);
				if (mousepos.x >= 440.0f && mousepos.x <= 585.0f && mousepos.y >= 640.0f && mousepos.y <= 740.0f)
				{
					ScoreP1 = 0;
					FileWriteScoreP1(ScoreP1);
					ScoreP2 = 0;
					FileWriteScoreP2(ScoreP2);
					StartWindow(window, size, ScoreP1, ScoreP2, turn, board);
				}
			}
		}
		// Display
		window.display();
	}
}