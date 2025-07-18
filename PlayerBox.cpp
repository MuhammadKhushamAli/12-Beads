#include<SFML/Graphics.hpp>
using namespace sf;

void PlayerBox(RenderWindow& window, const int size, int turn)
{
    // Player Name Boxes
    // Player1 Box
    RectangleShape Player1Box(Vector2f(size / 2 - 200.0f, 60.0f));
    Player1Box.setPosition(Vector2f(0.0f, 0.0f));
    Player1Box.setFillColor(Color(255, 0, 0));
    // Player2 Box
    RectangleShape Player2Box(Vector2f(size / 2 - 200.0f, 60.0f));
    Player2Box.setPosition(Vector2f(size / 2 + 200.0f, size - 60.0f));
    Player2Box.setFillColor(Color(0, 128, 0));

    // Boarder
    if (turn == 1)
    {
        Player2Box.setOutlineThickness(0.0f);
        Player1Box.setOutlineThickness(3.0f);
        Player1Box.setOutlineColor(Color(255, 255, 255));
    }
    else if (turn == 2)
    {
        Player1Box.setOutlineThickness(0.0f);
        Player2Box.setOutlineThickness(3.0f);
        Player2Box.setOutlineColor(Color(255, 225, 255));
    }
    // Text
    // Player 1
    Font font;
    font.loadFromFile("Smooch-Regular.ttf");
    Text Player1Name("Player 1", font, 40);
    Player1Name.setPosition(Vector2f(50.0f, 0.0f));
    Player1Name.setFillColor(Color(255, 255, 255));

    // Player 2
    Text Player2Name("Player 2", font, 40);
    Player2Name.setPosition(Vector2f(size / 2 + 250.0f, size - 60.0f));
    Player2Name.setFillColor(Color(255, 255, 255));

    // Image
    Texture img;
    img.loadFromFile("pp.png");
    Sprite image;
    image.setTexture(img);
    image.setPosition(Vector2f(0.0f, 0.5f));
    image.setScale(Vector2f(0.1f, 0.1f));

    // Player 2
    img.loadFromFile("pp.png");
    Sprite image1;
    image1.setTexture(img);
    image1.setPosition(Vector2f(size - 300.0f, size - 60.0f));
    image1.setScale(Vector2f(0.1f, 0.1f));

    window.draw(Player1Box);
    window.draw(Player2Box);
    window.draw(Player1Name);
    window.draw(Player2Name);
    window.draw(image);
    window.draw(image1);
}