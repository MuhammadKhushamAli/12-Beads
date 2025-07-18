#include<iostream>
#include"myHeader.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void Toss(RenderWindow& window, int size, int ScoreP1, int ScoreP2, int turn, int size_arr, int board[][5])
{
	bool player1Won = false, player2Won = false;
	// Picture
	Texture Toss;
	Toss.loadFromFile("Toss.png");
	Sprite Toss1(Toss);
	Toss1.setPosition(Vector2f(300.0f, 100.0f));

	Texture Heads;
	Heads.loadFromFile("heads.png");
	Sprite heads(Heads);
	heads.setPosition(Vector2f(50.0f, 450.0f));
	heads.setScale(Vector2f(0.5f, 0.5f));

	Texture Tails;
	Tails.loadFromFile("tails.png");
	Sprite tails(Tails);
	tails.setPosition(Vector2f(550.0f, 450.0f));
	tails.setScale(Vector2f(0.5f, 0.5f));


	Texture FRWD;
	FRWD.loadFromFile("next.png");
	Sprite next(FRWD);
	next.setPosition(Vector2f(450.0f, 900.0f));
	next.setScale(Vector2f(0.2f, 0.2f));
	// Text

	Font font;
	font.loadFromFile("Oswald-Bold.ttf");
	Text Inst("Player 1 Choose Your Side : ", font, 40);
	Inst.setPosition(Vector2f(100.0f, 350.0f));
	Inst.setFillColor(Color(0, 0, 0));

	Text P1Won("Player 1 Won The Toss!", font, 40);
	P1Won.setPosition(Vector2f(300.0f, 850.0f));
	P1Won.setFillColor(Color(255, 0, 0));

	Text P2Won("Player 2 Won The Toss! ", font, 40);
	P2Won.setPosition(Vector2f(300.0f, 850.0f));
	P2Won.setFillColor(Color(0, 128, 0));

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
			if (occasion.MouseEntered)
			{
				Vector2i mousemove = Mouse::getPosition(window);
				if (mousemove.x >= 55.0f && mousemove.x <= 420.0f && mousemove.y >= 415.0f && mousemove.y <= 800.0f)
				{
					tails.setScale(Vector2f(0.5f, 0.5f));
					heads.setScale(Vector2f(0.6f, 0.6f));
					Heads.setSmooth(true);
				}
				if (mousemove.x >= 550.0f && mousemove.x <= 950.0f && mousemove.y >= 415.0f && mousemove.y <= 800.0f)
				{
					heads.setScale(Vector2f(0.5f, 0.5f));
					tails.setScale(Vector2f(0.6f, 0.6f));
					Tails.setSmooth(true);
				}
				if (mousemove.x < 55.0f || mousemove.x>950.0f || mousemove.y < 415.0f || mousemove.y>800.0f)
				{
					heads.setScale(Vector2f(0.5f, 0.5f));
					tails.setScale(Vector2f(0.5f, 0.5f));
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousepos = Mouse::getPosition(window);;
				if ((mousepos.x >= 55.0f && mousepos.x <= 420.0f && mousepos.y >= 415.0f && mousepos.y <= 745.0f)||(mousepos.x >= 550.0f && mousepos.x <= 950.0f && mousepos.y >= 415.0f && mousepos.y <= 800.0f))
				{
					srand(time(0));
					turn = (rand() % 2) + 1;
					if (turn == 1)
					{
						player1Won = true;
					}
					else if (turn == 2)
					{
						player2Won = true;
					}
				}
			}
		}
		window.clear(Color(147, 209, 255));
		window.draw(Toss1);
		window.draw(Inst);
		window.draw(heads);
		window.draw(tails);

		if (player1Won)
		{
			window.draw(P1Won);
			window.draw(next);
			if (occasion.MouseMoved)
			{
				Vector2i mouseposN = Mouse::getPosition(window);
				if (mouseposN.x >= 390.0f && mouseposN.x <= 630.0f && mouseposN.y >= 900.0f && mouseposN.y <= 1000.0f)
				{
					next.setScale(Vector2f(0.21f, 0.21f));
					FRWD.setSmooth(true);
				}
				if (mouseposN.x < 390.0f || mouseposN.x > 630.0f || mouseposN.y < 900.0f || mouseposN.y > 1000.0f)
				{
					next.setScale(Vector2f(0.2f, 0.2f));
					FRWD.setSmooth(true);
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousepos = Mouse::getPosition(window);
				if (mousepos.x >= 390.0f && mousepos.x <= 630.0f && mousepos.y >= 900.0f && mousepos.y <= 1000.0f)
				{
					StartButton(window, size, ScoreP1, ScoreP2, turn, size_arr, board);
				}
			}
		}
		else if (player2Won)
		{
			window.draw(P2Won);
			window.draw(next);
			if (occasion.MouseMoved)
			{
				Vector2i mouseposN = Mouse::getPosition(window);
				if (mouseposN.x >= 390.0f && mouseposN.x <= 630.0f && mouseposN.y >= 900.0f && mouseposN.y <= 1000.0f)
				{
					next.setScale(Vector2f(0.21f, 0.21f));
					FRWD.setSmooth(true);
				}
				if (mouseposN.x < 390.0f || mouseposN.x > 630.0f || mouseposN.y < 900.0f || mouseposN.y > 1000.0f)
				{
					next.setScale(Vector2f(0.2f, 0.2f));
					FRWD.setSmooth(true);
				}

			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousepos = Mouse::getPosition(window);
				if (mousepos.x >= 390.0f && mousepos.x <= 630.0f && mousepos.y >= 900.0f && mousepos.y <= 1000.0f)
				{
					StartButton(window, size, ScoreP1, ScoreP2, turn, size_arr, board);
				}
			}
		}
		window.display();
	}

}

