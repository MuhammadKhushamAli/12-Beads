#include<SFML/Graphics.hpp>
using namespace sf;

void bordLines(RenderWindow& window, const int size)
{
	// Making Lines
		// Upper Vertical Line
	VertexArray upperverticalline(Lines, 2);
	upperverticalline[0].position = Vector2f(100.0f, 100.0f);
	upperverticalline[1].position = Vector2f(size - 100.0f, 100.0f);
	// Lower Vertical Line
	VertexArray lowerverticalline(Lines, 2);
	lowerverticalline[0].position = Vector2f(100.0f, size - 100.0f);
	lowerverticalline[1].position = Vector2f(size - 100.0f, size - 100.0f);
	// Left Horizontal Line
	VertexArray lefthorizontalline(Lines, 2);
	lefthorizontalline[0].position = Vector2f(100.0f, 100.0f);
	lefthorizontalline[1].position = Vector2f(100.0f, size - 100.0f);
	// Right Horizontal Line
	VertexArray righthorizontalline(Lines, 2);
	righthorizontalline[0].position = Vector2f(size - 100.0f, 100.0f);
	righthorizontalline[1].position = Vector2f(size - 100.0f, size - 100.0f);
	// Main Diagonal
	VertexArray mainDiagonal(Lines, 2);
	mainDiagonal[0].position = Vector2f(100.0f, 100.0f);
	mainDiagonal[1].position = Vector2f((size - 100.0f), (size - 100.0f));
	// Secondary Diagonal
	VertexArray secondaryDiagonal(Lines, 2);
	secondaryDiagonal[0].position = Vector2f((size - 100.0f), 100.0f);
	secondaryDiagonal[1].position = Vector2f(100.0f, (size - 100.0f));
	// Mid Vertical Line
	VertexArray midVerticalline(Lines, 2);
	midVerticalline[0].position = Vector2f(size / 2, 100.0f);
	midVerticalline[1].position = Vector2f(size / 2, (size - 100.0f));
	// Mid of Mid Vertical Line
	VertexArray mid2Verticalline(Lines, 2);
	mid2Verticalline[0].position = Vector2f((size + 200.0f) / 4, 100.0f);
	mid2Verticalline[1].position = Vector2f((size + 200.0f) / 4, (size - 100.0f));
	// Mid of Mid 2 Vertical Line
	VertexArray mid3Verticalline(Lines, 2);
	mid3Verticalline[0].position = Vector2f((3 * size - 200.0f) / 4, 100.0f);
	mid3Verticalline[1].position = Vector2f((3 * size - 200.0f) / 4, (size - 100.0f));
	// Mid Horizontal Line
	VertexArray midHorizontalline(Lines, 2);
	midHorizontalline[0].position = Vector2f(100.0f, size / 2);
	midHorizontalline[1].position = Vector2f((size - 100.0f), size / 2);
	// Mid of Mid Horizontal Line
	VertexArray mid2Horizontalline(Lines, 2);
	mid2Horizontalline[0].position = Vector2f(100.0f, (size + 200.0f) / 4);
	mid2Horizontalline[1].position = Vector2f((size - 100.0f), (size + 200.0f) / 4);
	// Mid of Mid 2 Horizontal Line
	VertexArray mid3Horizontalline(Lines, 2);
	mid3Horizontalline[0].position = Vector2f(100.0f, (3 * size - 200.0f) / 4);
	mid3Horizontalline[1].position = Vector2f((size - 100.0f), (3 * size - 200.0f) / 4);
	// Upper Mid of X-axis to Mid of y-axis
	VertexArray uppermidtomid(Lines, 2);
	uppermidtomid[0].position = Vector2f(size / 2, 100.0f);
	uppermidtomid[1].position = Vector2f(100.0f, size / 2);
	// Upper Mid of x-axis to Mid of y-axis 2
	VertexArray uppermidtomid2(Lines, 2);
	uppermidtomid2[0].position = Vector2f(size / 2, 100.0f);
	uppermidtomid2[1].position = Vector2f((size - 100.0f), size / 2);
	// Lower Mid of x-axis to Mid of y-axis
	VertexArray lowermidtomid(Lines, 2);
	lowermidtomid[0].position = Vector2f(100.0f, size / 2);
	lowermidtomid[1].position = Vector2f(size / 2, (size - 100.0f));
	// Lower Mid of x-axis to Mid of y-axis 2
	VertexArray lowermidtomid2(Lines, 2);
	lowermidtomid2[0].position = Vector2f(size / 2, (size - 100.0f));
	lowermidtomid2[1].position = Vector2f((size - 100.0f), size / 2);
	// Color
	// Lines
	for (int i = 0;i < 2;i++)
	{
		upperverticalline[i].color = Color(12, 7, 58);
		lowerverticalline[i].color = Color(12, 7, 58);
		lefthorizontalline[i].color = Color(12, 7, 58);
		righthorizontalline[i].color = Color(12, 7, 58);
		mainDiagonal[i].color = Color(12, 7, 58);
		secondaryDiagonal[i].color = Color(12, 7, 58);
		midVerticalline[i].color = Color(12, 7, 58);
		midHorizontalline[i].color = Color(12, 7, 58);
		mid2Verticalline[i].color = Color(12, 7, 58);
		mid3Verticalline[i].color = Color(12, 7, 58);
		mid2Horizontalline[i].color = Color(12, 7, 58);
		mid3Horizontalline[i].color = Color(12, 7, 58);
		uppermidtomid[i].color = Color(12, 7, 58);
		uppermidtomid2[i].color = Color(12, 7, 58);
		lowermidtomid[i].color = Color(12, 7, 58);
		lowermidtomid2[i].color = Color(12, 7, 58);

		// Drawing
		window.draw(upperverticalline);
		window.draw(lowerverticalline);
		window.draw(righthorizontalline);
		window.draw(lefthorizontalline);
		window.draw(mainDiagonal);
		window.draw(secondaryDiagonal);
		window.draw(midVerticalline);
		window.draw(midHorizontalline);
		window.draw(mid2Verticalline);
		window.draw(mid3Verticalline);
		window.draw(mid2Horizontalline);
		window.draw(mid3Horizontalline);
		window.draw(uppermidtomid);
		window.draw(uppermidtomid2);
		window.draw(lowermidtomid);
		window.draw(lowermidtomid2);
	}
}