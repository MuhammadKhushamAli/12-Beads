#include<iostream>
#include<fstream>
#include"myHeader.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void StartWindow(RenderWindow& window, const int size, int ScoreP1, int ScoreP2, int turn, int board[][5])
{
	const int size_arr = 5;

	 // File Reading
	 
	 // Open the file and reading ScoreP1
	ifstream inscorep1("scorep1.txt");

	// Check if the file is open successfully
	if (!inscorep1.is_open())
	{
		cout << "Error in opening the file scorep1.txt" << endl;
		return;
	}
	inscorep1 >> ScoreP1;
	inscorep1.close();

	// Open the file and reading ScoreP2
	ifstream inscorep2("scorep2.txt");

	// Check if the file is open successfully
	if (!inscorep2.is_open())
	{
		cout << "Error in opening the file scorep2.txt" << endl;
		return;
	}
	inscorep2 >> ScoreP2;
	inscorep2.close();

	//-------------------------------------------------------------------------------------------------------------------------
	//  Pics
	// Start Window
	// 12 Beads Logo

	Texture Logo;
	Logo.loadFromFile("12BEADSLOGO.png");
	Sprite Logo12(Logo);
	Logo12.setPosition(Vector2f(200.0f, 200.0f));

	// Button
	// Start

	Texture Start;
	Start.loadFromFile("start.png");
	Sprite Start12(Start);
	
	// End

	Texture End;
	End.loadFromFile("exit.png");
	Sprite End12(End);

	// Continue

	Texture Continue;
	Continue.loadFromFile("continue.png");
	Sprite Continue12(Continue);

	// Calling Different Screens For Different Conditions

	if ((ScoreP1==0 && ScoreP2==0))
	{
		// Start

		Start12.setPosition(Vector2f(460.0f, 400.0f));

		// End

		End12.setPosition(Vector2f(463.0f, 650.0f));
	}
	else
	{
		// Start
		Start12.setPosition(Vector2f(460.0f, 400.0f));

		
		// Continue
		Continue12.setPosition(Vector2f(460.0f, 625.0f));


		// End
		End12.setPosition(Vector2f(460.0f, 850.0f));

	}

	//---------------------------------------------------------------------------------------------------------------

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

			//-------------------------------------------------------------------------------------------------------
			// Mouse Move
			if (occasion.MouseEntered)
			{
				Vector2i mouseMovepos = Mouse::getPosition(window);
				if (mouseMovepos.x <= 580.0f && mouseMovepos.x >= 440.0f && mouseMovepos.y <= 470.0f && mouseMovepos.y >= 390.0f)
				{
					Continue12.setScale(Vector2f(1.0f, 1.0f));
					End12.setScale(Vector2f(1.0f, 1.0f));
					Start12.setScale(Vector2f(1.1f, 1.1f));
					Start.setSmooth(true);
				}
				if ((ScoreP1 != 0) || (ScoreP2 != 0))
				{
					if (mouseMovepos.x <= 580.0f && mouseMovepos.x >= 440.0f && mouseMovepos.y <= 720.0f && mouseMovepos.y >= 680.0f)
					{
						Start12.setScale(Vector2f(1.0f, 1.0f));
						End12.setScale(Vector2f(1.0f, 1.0f));
						Continue12.setScale(Vector2f(1.1f, 1.1f));
						Continue.setSmooth(true);
					}
					if (mouseMovepos.x >= 440.0f && mouseMovepos.x <= 580.0f && mouseMovepos.y >= 825.0f && mouseMovepos.y <= 950.0f)
					{
						Start12.setScale(Vector2f(1.0f, 1.0f));
						Continue12.setScale(Vector2f(1.0f, 1.0f));
						End12.setScale(Vector2f(1.1f, 1.1f));
						End.setSmooth(true);
					}
					if (mouseMovepos.x > 580.0f || mouseMovepos.x < 440.0f || mouseMovepos.y < 390.0f || mouseMovepos.y>950.0f)
					{
						Start12.setScale(Vector2f(1.0f, 1.0f));
						Continue12.setScale(Vector2f(1.0f, 1.0f));
						End12.setScale(Vector2f(1.0f, 1.0f));
					}
				}
				else
				{
					if (mouseMovepos.x >= 440.0f && mouseMovepos.x <= 580.0f && mouseMovepos.y >= 645.0f && mouseMovepos.y <= 750.0f)
					{
						Start12.setScale(Vector2f(1.0f, 1.0f));
						Continue12.setScale(Vector2f(1.0f, 1.0f));
						End12.setScale(Vector2f(1.1f, 1.1f));
						End.setSmooth(true);
					}
					if (mouseMovepos.x > 580.0f || mouseMovepos.x < 440.0f || mouseMovepos.y < 390.0f || mouseMovepos.y>950.0f)
					{
						Start12.setScale(Vector2f(1.0f, 1.0f));
						Continue12.setScale(Vector2f(1.0f, 1.0f));
						End12.setScale(Vector2f(1.0f, 1.0f));
					}
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousePos = Mouse::getPosition(window);
				//----------------------------------------------------------------------------------------------------
				// Start Button
				if (mousePos.x <= 575.0f && mousePos.x >= 440.0f && mousePos.y <= 500.0f && mousePos.y >= 390.0f)
				{
					Toss(window, size, ScoreP1, ScoreP2, turn, size_arr, board);
				}

				//---------------------------------------------------------------------------------------------------------------
				// Continue Button
				if ((ScoreP1 != 12 && ScoreP1 != 0) || (ScoreP2 != 12 && ScoreP2 != 0))
				{
					if (mousePos.x <= 570.0f && mousePos.x >= 440.0f && mousePos.y <= 720.0f && mousePos.y >= 620.0f)
					{
						ContinueButton(window, size, ScoreP1, ScoreP2, turn, size_arr, board);
					}
					if (mousePos.x >= 440.0f && mousePos.x <= 580.0f && mousePos.y >= 845.0f && mousePos.y <= 950.0f)
					{
						window.close();
					}
				}
				//------------------------------------------------------------------------------------------------------------------
				// Exit Button

				if (mousePos.x >= 440.0f && mousePos.x <= 580.0f && mousePos.y >= 645.0f && mousePos.y <= 750.0f)
				{
					window.close();
				}
			}

			// Clear Window
			window.clear(Color(147, 209, 255));
			// Drawing
			window.draw(Logo12);
			window.draw(Start12);
			if ((ScoreP1 != 12 && ScoreP1 != 0) || (ScoreP2 != 0 && ScoreP2 != 12))
			{
				window.draw(Continue12);
			}
			window.draw(End12);
			// Display
			window.display();
		}
	}
}