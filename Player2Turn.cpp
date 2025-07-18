//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <fstream>
//#include "myHeader.h"
//
//using namespace sf;
//using namespace std;
//
//void mainGraphics(RenderWindow& window, const int size)
//{
//    int count1 = 0;
//    const int size_arr = 5;
//    Vector2f array[size_arr][size_arr];
//    CircleShape bead_p1[size_arr][size_arr];
//    int board[size_arr][size_arr];
//    int a = 0, b = 0, nextrow = 0, nextcol = 0, next2row = 0, next2col = 0, prevrow = 0, prevcol = 0, prev2row = 0, prev2col = 0;
//    // Open the file for reading positions
//    ifstream inb("boardposition.txt");
//
//    // Check if the file is open successfully
//    if (!inb.is_open())
//    {
//        cout << "Error in opening the file boardposition.txt" << endl;
//        return;
//    }
//    // Read bead positions from the file and store them in the array
//
//    for (int i = 0; i < size_arr; i++)
//    {
//        for (int j = 0; j < size_arr; j++)
//        {
//            inb >> board[i][j];
//        }
//    }
//    inb.close();
//
//    //for (int i = 0;i < size_arr;i++)
//    //{
//    //    for (int j = 0;j < size_arr;j++)
//    //    {
//    //        cout << array[i][j].x << " " << array[i][j].y << endl;
//    //    }
//    //}
//    // Game Loop
//    while (window.isOpen())
//    {
//        // Open the file for reading positions
//        ifstream in("beadsposition.txt");
//
//        // Check if the file is open successfully
//        if (!in.is_open())
//        {
//            cout << "Error in opening the file beadsposition.txt" << endl;
//            return;
//        }
//        // Read bead positions from the file and store them in the array
//
//        for (int i = 0; i < size_arr; i++)
//        {
//            for (int j = 0; j < size_arr; j++)
//            {
//
//                if (board[i][j] == 0)
//                {
//                    in >> array[i][j].x >> array[i][j].y;
//                }
//                if (board[i][j] == 1)
//                {
//                    bead_p1[i][j].setRadius(20.0f);
//                    in >> array[i][j].x >> array[i][j].y;
//                    bead_p1[i][j].setPosition(array[i][j]);
//                    bead_p1[i][j].setFillColor(Color(255, 0, 0));
//                }
//                else if (board[i][j] == 2)
//                {
//                    bead_p1[i][j].setRadius(20.0f);
//                    in >> array[i][j].x >> array[i][j].y;
//                    bead_p1[i][j].setPosition(array[i][j]);
//                    bead_p1[i][j].setFillColor(Color(0, 128, 0));
//                }
//            }
//        }
//        in.close();
//        Event occasion;
//        while (window.pollEvent(occasion))
//        {
//            if (occasion.type == Event::Closed)
//            {
//                window.close();
//            }
//            if (Mouse::isButtonPressed(Mouse::Left))
//            {
//                Vector2i mousePos = Mouse::getPosition(window);
//
//                for (int i = 0; i < size_arr; i++)
//                {
//                    for (int j = 0; j < size_arr; j++)
//                    {
//                        if (mousePos.x >= array[i][j].x && mousePos.x <= array[i][j].x + 40
//                            && mousePos.y >= array[i][j].y && mousePos.y <= array[i][j].y + 40)
//                        {
//                            if (board[i][j] != 0)
//                            {
//                                cout << "Mouse clicked on bead at position: " << i << ", " << j << endl;
//                                count1 = 1;
//                                a = i;
//                                b = j;
//                                break;
//                            }
//                            else
//                            {
//                                cout << "no";
//                            }
//                        }
//                    }
//                    if (count1 == 1)
//                    {
//                        count1 = 0;
//                        break;
//                    }
//                }
//            }
//            if (Mouse::isButtonPressed(Mouse::Right))
//            {
//                Vector2i mousePosN = Mouse::getPosition(window);
//                if ((mousePosN.x >= 70 && mousePosN.x <= 930) && (mousePosN.y >= 70 && mousePosN.y <= 930))
//                {
//                    for (int i = 0;i < size_arr;i++)
//                    {
//                        for (int j = 0;j < size_arr;j++)
//                        {
//                            nextrow = a + 1;
//                            next2row = a + 2;
//                            nextcol = b + 1;
//                            next2col = b + 2;
//                            if (a == 0)
//                            {
//                                prevrow = a;
//                            }
//                            if (b == 0)
//                            {
//                                prevcol = 0;
//                            }
//                            if (a > 0)
//                            {
//                                prevrow = a - 1;
//                            }
//                            if (b > 0)
//                            {
//                                prevcol = b - 1;
//                            }
//                            if (a > 1)
//                            {
//                                prev2row = a - 2;
//                            }
//                            if (b > 1)
//                            {
//                                prev2col = b - 2;
//                            }
//
//                            if (mousePosN.x >= array[i][j].x && mousePosN.x <= array[i][j].x + 40
//                                && mousePosN.y >= array[i][j].y && mousePosN.y <= array[i][j].y + 40)
//                            {
//
//
//
//                                // Diagonals & Upper and Lower Diagonal Diamond Lines
//
//
//
//                                if (((a == b) && (i == j)) || (((a == 2 && b == 0) || (a == 3 && b == 1) || (a == 4 && b == 2) || (a == 0 && b == 2) || (a == 1 && b == 3) || (a == 2 && b == 4)) && ((i == 2 && j == 0) || (i == 3 && j == 1) || (i == 4 && j == 2) || (i == 0 && j == 2) || (i == 1 && j == 3) || (i == 2 && j == 4))))
//                                {
//                                    cout << "1";
//                                    if (board[a][b] == 1)
//                                    {
//                                        if (board[nextrow][nextcol] == 0 || board[prevrow][prevcol] == 0)
//                                        {
//                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
//                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
//                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
//                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
//                                            {
//                                                if (board[i][j] == 0)
//                                                {
//                                                    count1 = 1;
//                                                    board[a][b] = 0;
//                                                    board[i][j] = 1;
//                                                    FileWrite(array, size_arr);
//                                                    boardWriting(board, size_arr);
//                                                    cout << array[i][j].x << " " << array[i][j].y;
//                                                    bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                    bead_p1[a][b].setFillColor(Color::Transparent);
//                                                    break;
//                                                }
//                                            }
//                                        }
//                                        else if ((board[nextrow][nextcol] == 2 || board[prevrow][prevcol] == 2) && (board[i][j] == 0))
//                                        {
//                                            if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450)
//                                                || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450)
//                                                || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) ||
//                                                (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
//                                            {
//
//                                                if (board[i][j] == 0)
//                                                {
//                                                    count1 = 1;
//                                                    board[a][b] = 0;
//                                                    board[i][j] = 1;
//                                                    FileWrite(array, size_arr);
//                                                    boardWriting(board, size_arr);
//                                                    cout << array[i][j].x << " " << array[i][j].y;
//                                                    bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                    bead_p1[a][b].setFillColor(Color::Transparent);
//                                                    if (i < a && j < b)
//                                                    {
//                                                        bead_p1[i + 1][j + 1].setFillColor(Color::Transparent);
//                                                        board[i + 1][j + 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i > a && j > b)
//                                                    {
//                                                        bead_p1[i - 1][j - 1].setFillColor(Color::Transparent);
//                                                        board[i - 1][j - 1] = 0;
//                                                        boardWriting(board, size_arr);
//
//                                                    }
//                                                    break;
//                                                }
//                                                else
//                                                {
//                                                    cout << "Error";
//                                                }
//                                            }
//                                        }
//                                        if (board[a][b] == 2)
//                                        {
//                                            if (board[nextrow][nextcol] == 0 || board[prevrow][prevcol] == 0)
//                                            {
//                                                if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
//                                                    || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
//                                                    || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
//                                                    (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
//                                                {
//                                                    if (board[i][j] == 0)
//                                                    {
//                                                        count1 = 1;
//                                                        board[a][b] = 0;
//                                                        board[i][j] = 2;
//                                                        FileWrite(array, size_arr);
//                                                        boardWriting(board, size_arr);
//                                                        cout << array[i][j].x << " " << array[i][j].y;
//                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                        bead_p1[a][b].setFillColor(Color::Transparent);
//                                                        break;
//                                                    }
//                                                }
//                                            }
//                                            else if ((board[nextrow][nextcol] == 1 || board[prevrow][prevcol] == 1) && (board[i][j] == 0))
//                                            {
//                                                if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450)
//                                                    || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450)
//                                                    || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) ||
//                                                    (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
//                                                {
//
//                                                    if (board[i][j] == 0)
//                                                    {
//                                                        count1 = 1;
//                                                        board[a][b] = 0;
//                                                        board[i][j] = 2;
//                                                        FileWrite(array, size_arr);
//                                                        boardWriting(board, size_arr);
//                                                        cout << array[i][j].x << " " << array[i][j].y;
//                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                        bead_p1[a][b].setFillColor(Color::Transparent);
//                                                        if (i < a && j < b)
//                                                        {
//                                                            bead_p1[i + 1][j + 1].setFillColor(Color::Transparent);
//                                                            board[i + 1][j + 1] = 0;
//                                                            boardWriting(board, size_arr);
//                                                        }
//                                                        else if (i > a && j > b)
//                                                        {
//                                                            bead_p1[i - 1][j - 1].setFillColor(Color::Transparent);
//                                                            board[i - 1][j - 1] = 0;
//                                                            boardWriting(board, size_arr);
//
//                                                        }
//                                                        break;
//                                                    }
//                                                    else
//                                                    {
//                                                        cout << "Error";
//                                                    }
//
//                                                }
//                                            }
//                                        }
//                                    }
//                                }
//
//                                // Anti-Diagonals and Anti Diaginal Diamond Lines
//
//                                else if (((a == 0 && b == 4) || (a == 0 && b == 2) || (a == 1 && b == 3) || (a == 1 && b == 1) || (a == 2 && b == 0) || (a == 2 && b == 2) || (a == 2 && b == 4) || (a == 3 && b == 1) || (a == 3 && b == 3) || (a == 4 && b == 2) || (a == 4 && b == 0)) && ((i == 0 && j == 4) || (i == 0 && j == 2) || (i == 1 && j == 3) || (i == 1 && j == 1) || (i == 2 && j == 0) || (i == 2 && j == 2) || (i == 2 && j == 4) || (i == 3 && j == 1) || (i == 3 && j == 3) || (i == 4 && j == 2) || (i == 4 && j == 0)))
//                                {
//                                    cout << "2";
//
//                                    if (board[a][b] == 1)
//                                    {
//
//                                        if (board[a + 1][b - 1] == 0 || board[a - 1][b + 1] == 0)
//                                        {
//                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
//                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
//                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
//                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
//                                            {
//                                                if (board[i][j] == 0)
//                                                {
//                                                    count1 = 1;
//                                                    board[a][b] = 0;
//                                                    board[i][j] = 1;
//                                                    FileWrite(array, size_arr);
//                                                    boardWriting(board, size_arr);
//                                                    cout << array[i][j].x << " " << array[i][j].y;
//                                                    bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                    bead_p1[a][b].setFillColor(Color::Transparent);
//                                                    break;
//                                                }
//                                            }
//                                        }
//                                        else if ((board[nextrow][nextcol] == 2 || board[prevrow][prevcol] == 2) && (board[i][j] == 0))
//                                        {
//                                            if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450)
//                                                || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450)
//                                                || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) ||
//                                                (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
//                                            {
//
//                                                if (board[i][j] == 0)
//                                                {
//                                                    count1 = 1;
//                                                    board[a][b] = 0;
//                                                    board[i][j] = 1;
//                                                    FileWrite(array, size_arr);
//                                                    boardWriting(board, size_arr);
//                                                    cout << array[i][j].x << " " << array[i][j].y;
//                                                    bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                    bead_p1[a][b].setFillColor(Color::Transparent);
//                                                    if (i < a && j < b)
//                                                    {
//                                                        bead_p1[i + 1][j + 1].setFillColor(Color::Transparent);
//                                                        board[i + 1][j + 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i > a && j > b)
//                                                    {
//                                                        bead_p1[i - 1][j - 1].setFillColor(Color::Transparent);
//                                                        board[i - 1][j - 1] = 0;
//                                                        boardWriting(board, size_arr);
//
//                                                    }
//                                                    break;
//                                                }
//                                                else
//                                                {
//                                                    cout << "Error";
//                                                }
//                                            }
//                                        }
//                                        if (board[a][b] == 2)
//                                        {
//                                            if (board[nextrow][nextcol] == 0 || board[prevrow][prevcol] == 0)
//                                            {
//                                                if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
//                                                    || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
//                                                    || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
//                                                    (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
//                                                {
//                                                    if (board[i][j] == 0)
//                                                    {
//                                                        count1 = 1;
//                                                        board[a][b] = 0;
//                                                        board[i][j] = 2;
//                                                        FileWrite(array, size_arr);
//                                                        boardWriting(board, size_arr);
//                                                        cout << array[i][j].x << " " << array[i][j].y;
//                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                        bead_p1[a][b].setFillColor(Color::Transparent);
//                                                        break;
//                                                    }
//                                                }
//                                            }
//                                            else if ((board[nextrow][nextcol] == 1 || board[prevrow][prevcol] == 1) && (board[i][j] == 0))
//                                            {
//                                                if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450)
//                                                    || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450)
//                                                    || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) ||
//                                                    (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
//                                                {
//
//                                                    if (board[i][j] == 0)
//                                                    {
//                                                        count1 = 1;
//                                                        board[a][b] = 0;
//                                                        board[i][j] = 2;
//                                                        FileWrite(array, size_arr);
//                                                        boardWriting(board, size_arr);
//                                                        cout << array[i][j].x << " " << array[i][j].y;
//                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                        bead_p1[a][b].setFillColor(Color::Transparent);
//                                                        if (i < a && j < b)
//                                                        {
//                                                            bead_p1[i + 1][j + 1].setFillColor(Color::Transparent);
//                                                            board[i + 1][j + 1] = 0;
//                                                            boardWriting(board, size_arr);
//                                                        }
//                                                        else if (i > a && j > b)
//                                                        {
//                                                            bead_p1[i - 1][j - 1].setFillColor(Color::Transparent);
//                                                            board[i - 1][j - 1] = 0;
//                                                            boardWriting(board, size_arr);
//
//                                                        }
//                                                        break;
//                                                    }
//                                                    else
//                                                    {
//                                                        cout << "Error";
//                                                    }
//
//                                                }
//                                            }
//                                        }
//                                    }
//                                }
//                                // Other
//                                else
//                                {
//                                    cout << "3";
//                                    if (board[a][b] == 1)
//                                    {
//                                        if (board[nextrow][b] == 0 || board[a][nextcol] == 0 || board[prevrow][b] == 0 || board[a][prevcol] == 0)
//                                        {
//                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
//                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
//                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
//                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
//                                            {
//                                                if (board[i][j] == 0)
//                                                {
//                                                    count1 = 1;
//                                                    board[a][b] = 0;
//                                                    board[i][j] = 1;
//                                                    FileWrite(array, size_arr);
//                                                    boardWriting(board, size_arr);
//                                                    cout << array[i][j].x << " " << array[i][j].y;
//                                                    bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                    bead_p1[a][b].setFillColor(Color::Transparent);
//                                                    break;
//                                                }
//                                            }
//                                        }
//                                        else if ((board[nextrow][b] == 2 || board[a][nextcol] == 2 || board[prevrow][b] == 2 || board[a][prevcol] == 2 || board[prevrow][prevcol] == 2 || board[nextrow][nextcol] == 2)
//                                            && (board[i][j] == 0/* || board[a][next2col] == 0 || board[prev2row][b] == 0 || board[a][prev2col] == 0 || board[prev2row][prev2col] == 0 || board[next2row][next2col] == 0*/))
//                                        {
//                                            if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450)
//                                                || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450)
//                                                || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) ||
//                                                (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
//                                            {
//
//                                                if (board[i][j] == 0)
//                                                {
//                                                    count1 = 1;
//                                                    board[a][b] = 0;
//                                                    board[i][j] = 1;
//                                                    FileWrite(array, size_arr);
//                                                    boardWriting(board, size_arr);
//                                                    cout << array[i][j].x << " " << array[i][j].y;
//                                                    bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                    bead_p1[a][b].setFillColor(Color::Transparent);
//                                                    if (i > a && j == b)
//                                                    {
//                                                        bead_p1[i - 1][b].setFillColor(Color::Transparent);
//                                                        board[i - 1][b] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i == a && j > b)
//                                                    {
//                                                        bead_p1[a][j - 1].setFillColor(Color::Transparent);
//                                                        board[a][j - 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i < a && j == b)
//                                                    {
//                                                        bead_p1[i + 1][b].setFillColor(Color::Transparent);
//                                                        board[i + 1][b] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i == a && j < b)
//                                                    {
//                                                        bead_p1[a][j + 1].setFillColor(Color::Transparent);
//                                                        board[a][j + 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i < a && j < b)
//                                                    {
//                                                        bead_p1[i + 1][j + 1].setFillColor(Color::Transparent);
//                                                        board[i + 1][j + 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i > a && j > b)
//                                                    {
//                                                        bead_p1[i - 1][j - 1].setFillColor(Color::Transparent);
//                                                        board[i - 1][j - 1] = 0;
//                                                        boardWriting(board, size_arr);
//
//                                                    }
//                                                    break;
//                                                }
//                                                else
//                                                {
//                                                    cout << "Error";
//                                                }
//                                            }
//
//                                        }
//                                    }
//                                    if (board[a][b] == 2)
//                                    {
//                                        /*  nextrow = a + 1;
//                                          next2row = a + 2;
//                                          nextcol = b + 1;
//                                          next2col = b + 2;
//                                          if (a == 0)
//                                          {
//                                              prevrow = a;
//                                          }
//                                          if (b == 0)
//                                          {
//                                              prevcol = 0;
//                                          }
//                                          if (a > 0)
//                                          {
//                                              prevrow = a - 1;
//                                          }
//                                          if (b > 0)
//                                          {
//                                              prevcol = b - 1;
//                                          }
//                                          if (a > 1)
//                                          {
//                                              prev2row = a - 2;
//                                          }
//                                          if (b > 1)
//                                          {
//                                              prev2col = b - 2;
//                                          }*/
//                                        if (board[nextrow][b] == 0 || board[a][nextcol] == 0 || board[prevrow][b] == 0 || board[a][prevcol] == 0 || board[nextrow][nextcol] == 0 || board[prevrow][prevcol] == 0)
//                                        {
//                                            cout << "prevrow= " << prevrow << "\nprevcol =  " << prevcol << endl;
//                                            cout << "i = " << i << "\nj = " << j << endl;
//                                            cout << "a = " << a << "\nb =  " << b << endl;
//                                            cout << "bo = " << board[prevrow][b];
//                                            cout << "bo = " << board[i][j];
//                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
//                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
//                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
//                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
//                                            {
//                                                if (board[i][j] == 0)
//                                                {
//                                                    count1 = 1;
//                                                    board[a][b] = 0;
//                                                    board[i][j] = 2;
//                                                    FileWrite(array, size_arr);
//                                                    boardWriting(board, size_arr);
//                                                    cout << array[i][j].x << " " << array[i][j].y;
//                                                    bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                    bead_p1[a][b].setFillColor(Color::Transparent);
//                                                    break;
//                                                }
//                                                else
//                                                {
//                                                    cout << "Error";
//                                                }
//                                            }
//                                        }
//                                        else if ((board[nextrow][b] == 1 || board[a][nextcol] == 1 || board[prevrow][b] == 1 ||
//                                            board[a][prevcol] == 1 || board[prevrow][prevcol] == 1 ||
//                                            board[nextrow][nextcol] == 1)
//                                            && (board[i][j] == 0/* || board[a][next2col] == 0 || board[prev2row][b] == 0 ||
//                                                board[a][prev2col] == 0 || board[prev2row][prev2col] == 0 ||
//                                                board[next2row][next2col] == 0*/))
//                                        {
//                                            cout << "aa" << endl;
//                                            if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450)
//                                                || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450)
//                                                || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) ||
//                                                (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
//                                            {
//                                                if (board[i][j] == 0)
//                                                {
//                                                    count1 = 1;
//                                                    board[a][b] = 0;
//                                                    board[i][j] = 2;
//                                                    FileWrite(array, size_arr);
//                                                    boardWriting(board, size_arr);
//                                                    cout << array[i][j].x << " " << array[i][j].y;
//                                                    bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
//                                                    bead_p1[a][b].setFillColor(Color::Transparent);
//                                                    if (i > a && j == b)
//                                                    {
//                                                        bead_p1[i - 1][b].setFillColor(Color::Transparent);
//                                                        board[i - 1][b] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i == a && j > b)
//                                                    {
//                                                        bead_p1[a][j - 1].setFillColor(Color::Transparent);
//                                                        board[a][j - 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i < a && j == b)
//                                                    {
//                                                        bead_p1[i + 1][b].setFillColor(Color::Transparent);
//                                                        board[i + 1][b] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i == a && j < b)
//                                                    {
//                                                        bead_p1[a][j + 1].setFillColor(Color::Transparent);
//                                                        board[a][j + 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i < a && j < b)
//                                                    {
//                                                        bead_p1[i + 1][j + 1].setFillColor(Color::Transparent);
//                                                        board[i + 1][j + 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    else if (i > a && j > b)
//                                                    {
//                                                        bead_p1[i - 1][j - 1].setFillColor(Color::Transparent);
//                                                        board[i - 1][j - 1] = 0;
//                                                        boardWriting(board, size_arr);
//                                                    }
//                                                    break;
//                                                }
//                                            }
//                                            else
//                                            {
//                                                cout << "Error";
//                                            }
//                                        }
//                                    }
//                                }
//
//
//
//
//
//                            }
//                            if (count1 == 1)
//                            {
//                                count1 = 0;
//                                break;
//                            }
//
//                        }
//
//                    }
//                }
//                else
//                {
//                    cout << "Out of Range!";
//                }
//
//            }
//        }
//        // Updating
//        // Clear Window Every Time
//        window.clear(Color(147, 209, 255));
//        // Draw Objects Every Time
//        bordLines(window, size);
//        for (int i = 0; i < size_arr; i++)
//        {
//            for (int j = 0; j < size_arr; j++)
//            {
//                window.draw(bead_p1[i][j]);
//            }
//        }
//        // Display New Objects Every Time
//        window.display();
//    }
//}
