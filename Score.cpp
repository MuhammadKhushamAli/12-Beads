#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

void Score(RenderWindow& window, const int size, int ScoreP1, int ScoreP2)
{
    String ScorePlayer1, ScorePlayer2;
    ScorePlayer1 = "Player 1 Score = " + to_string(ScoreP1);
    ScorePlayer2 = "Player 2 Score = " + to_string(ScoreP2);
        // Score
    // Player 1
        Font font;
    font.loadFromFile("Oswald-Bold.ttf");
    Text ScorePl1(ScorePlayer1, font, 40);
    ScorePl1.setPosition(Vector2f(size / 2 + 100.0f, 10.0f));
    ScorePl1.setFillColor(Color(255, 0, 0));

    // Player 2

    Text ScorePl2(ScorePlayer2, font, 40);
    ScorePl2.setPosition(Vector2f(size / 2 - 400.0f, size - 60.0f));
    ScorePl2.setFillColor(Color(0, 128, 0));

    window.draw(ScorePl1);
    window.draw(ScorePl2);

}