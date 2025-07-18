#include<SFML/Graphics.hpp>
using namespace sf;
// Function Prototype

void mainGraphics(RenderWindow&, const int, int, int, int, int[][5]);
void StartWindow(RenderWindow&, const int, int, int, int, int[][5]);

// Shapes
void bordLines(RenderWindow&, const int);
void PlayerBox(RenderWindow&, const int, int);

// Button Function
void StartButton(RenderWindow&, int, int, int, int, int, int[][5]);
void ContinueButton(RenderWindow&, int, int, int, int, int, int[][5]);
void Toss(RenderWindow&, int, int, int, int, int, int[][5]);

void Winner(RenderWindow&, int, int, int, int, int[][5]);
void Score(RenderWindow&, const int, int, int);
// File Handling

void FileWrite(Vector2f[][5], const int);
void FileWriteturn(int);
void FileWriteScoreP1(int);
void FileWriteScoreP2(int);
void boardWriting(int[][5], const int);