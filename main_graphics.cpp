#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "myHeader.h"

using namespace sf;
using namespace std;

void mainGraphics(RenderWindow& window, const int size, int ScoreP1, int ScoreP2, int turn, int board[][5])
{
    string ScorePlayer1;
    const int size_arr = 5;
    int count1 = 0;
    Vector2f array[size_arr][size_arr];
    CircleShape bead_p1[size_arr][size_arr];
    int a = 0, b = 0;


    

    // File Handling

    // Open the file for reading Board positions
    ifstream inboard("boardposition.txt");

    // Check if the file is open successfully
    if (!inboard.is_open())
    {
        cout << "Error in opening the file boardposition.txt" << endl;
        return;
    }
    // Read bead positions from the file and store them in the array

    for (int i = 0; i < size_arr; i++)
    {
        for (int j = 0; j < size_arr; j++)
        {
            inboard >> board[i][j];
        }
    }
    inboard.close();


    // Game Loop
    while (window.isOpen())
    {
        // Open the file and reading Turn
        ifstream inturn("turn.txt");

        // Check if the file is open successfully
        if (!inturn.is_open())
        {
            cout << "Error in opening the file turn.txt" << endl;
            return;
        }
        inturn >> turn;
        inturn.close();

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
        // Open the file for reading positions
        ifstream in("beadsposition.txt");

        // Check if the file is open successfully
        if (!in.is_open())
        {
            cout << "Error in opening the file beadsposition.txt" << endl;
            return;
        }
        // Read bead positions from the file and store them in the array


        for (int i = 0; i < size_arr; i++)
        {
            for (int j = 0; j < size_arr; j++)
            {

                if (board[i][j] == 0)
                {
                    in >> array[i][j].x >> array[i][j].y;
                }
                if (board[i][j] == 1)
                {
                    bead_p1[i][j].setRadius(20.0f);
                    in >> array[i][j].x >> array[i][j].y;
                    bead_p1[i][j].setPosition(array[i][j]);
                    bead_p1[i][j].setFillColor(Color(255, 0, 0));
                }
                else if (board[i][j] == 2)
                {
                    bead_p1[i][j].setRadius(20.0f);
                    in >> array[i][j].x >> array[i][j].y;
                    bead_p1[i][j].setPosition(array[i][j]);
                    bead_p1[i][j].setFillColor(Color(0, 128, 0));
                }
            }
        }
        in.close();
        Event occasion;
        while (window.pollEvent(occasion))
        {
            if (occasion.type == Event::Closed)
            {
                window.close();
            }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i mousePos = Mouse::getPosition(window);

                for (int i = 0; i < size_arr; i++)
                {
                    for (int j = 0; j < size_arr; j++)
                    {
                        if (mousePos.x >= array[i][j].x && mousePos.x <= array[i][j].x + 40
                            && mousePos.y >= array[i][j].y && mousePos.y <= array[i][j].y + 40)
                        {

                            if (board[i][j] != 0)
                            {
                                if (board[i][j] == turn)
                                {
                                    bead_p1[a][b].setOutlineColor(Color::Transparent);
                                    bead_p1[a][b].setOutlineThickness(0.0f);
                                    bead_p1[i][j].setOutlineThickness(5.0f);
                                    bead_p1[i][j].setOutlineColor(Color::Black);
                                    count1 = 1;
                                    a = i;
                                    b = j;
                                    break;
                                }
                                else
                                {
                                    cout << "Not your Turn" << endl;
                                }
                            }
                            else
                            {
                                cout << "no";
                            }
                        }
                    }
                    if (count1 == 1)
                    {
                        count1 = 0;
                        break;
                    }
                }
            }

            // Player 1

            if (Mouse::isButtonPressed(Mouse::Right))
            {
                Vector2i mousePosN = Mouse::getPosition(window);
                if ((mousePosN.x >= 70 && mousePosN.x <= 930) && (mousePosN.y >= 70 && mousePosN.y <= 930))
                {
                    bead_p1[a][b].setOutlineThickness(0.0f);
                    if (turn == 1)
                    {
                        for (int i = 0;i < size_arr;i++)
                        {
                            for (int j = 0;j < size_arr;j++)
                            {


                                if (mousePosN.x >= array[i][j].x && mousePosN.x <= array[i][j].x + 40
                                    && mousePosN.y >= array[i][j].y && mousePosN.y <= array[i][j].y + 40)
                                {



                                    // Diagonals & Upper and Lower Diagonal Diamond Lines



                                    if ((((i - a == 2) && (j - b == 2)) || ((i - a == -2) && (j - b == -2)) || ((i - a == 1) && (j - b == 1)) || ((i - a == -1) && (j - b == -1))) && (((a + b) % 2 == 0) && (i + j) % 2 == 0))
                                    {
                                        if (board[a][b] == 1)
                                        {
                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
                                            {
                                                if (board[a + 1][b + 1] == 0 || board[a - 1][b - 1] == 0)
                                                {
                                                    if ((board[i][j] == 0) && ((i > a && j > b) || (i < a && j < b)))
                                                    {
                                                        turn = 2;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 1;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        break;
                                                    }
                                                }
                                            }
                                            else if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450) || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450) || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) || (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
                                            {
                                                if ((board[a + 1][b + 1] == 2 || board[a - 1][b - 1] == 2) && (board[i][j] == 0))
                                                {
                                                    if ((board[i][j] == 0) && ((i > a && j > b) || (i < a && j < b)))
                                                    {
                                                        turn = 2;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 1;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        if (i < a && j < b)
                                                        {
                                                            bead_p1[i + 1][j + 1].setFillColor(Color::Transparent);
                                                            board[i + 1][j + 1] = 0;
                                                            boardWriting(board, size_arr);
                                                            ScoreP1++;
                                                            FileWriteScoreP1(ScoreP1);
                                                        }
                                                        else if (i > a && j > b)
                                                        {
                                                            bead_p1[i - 1][j - 1].setFillColor(Color::Transparent);
                                                            board[i - 1][j - 1] = 0;
                                                            boardWriting(board, size_arr);
                                                            ScoreP1++;
                                                            FileWriteScoreP1(ScoreP1);

                                                        }
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Error";
                                                    }
                                                }
                                            }
                                        }

                                    }

                                    // Anti-Diagonals and Anti Diaginal Diamond Lines

                                    else if ((((i - a == 2) && (j - b == -2)) || ((i - a == -2) && (j - b == 2)) || ((i - a == 1) && (j - b == -1)) || ((i - a == -1) && (j - b == 1))) && (((a + b) % 2 == 0) && (i + j) % 2 == 0))
                                    {
                                        if (board[a][b] == 1)
                                        {

                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
                                            {

                                                if (board[a + 1][b - 1] == 0 || board[a - 1][b + 1] == 0)
                                                {
                                                    if ((board[i][j] == 0) && ((i > a && j < b) || (i < a && j > b)))
                                                    {
                                                        turn = 2;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 1;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        break;
                                                    }
                                                }
                                            }
                                            else if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450) || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450) || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) || (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
                                            {
                                                if ((board[a + 1][b - 1] == 2 || board[a - 1][b + 1] == 2) && (board[i][j] == 0))
                                                {
                                                    if ((board[i][j] == 0) && ((i > a && j < b) || (i < a && j > b)))
                                                    {
                                                        turn = 2;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 1;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        if (i < a && j > b)
                                                        {
                                                            bead_p1[i + 1][j - 1].setFillColor(Color::Transparent);
                                                            board[i + 1][j - 1] = 0;
                                                            boardWriting(board, size_arr);
                                                            ScoreP1++;
                                                            FileWriteScoreP1(ScoreP1);
                                                        }
                                                        else if (i > a && j < b)
                                                        {
                                                            bead_p1[i - 1][j + 1].setFillColor(Color::Transparent);
                                                            board[i - 1][j + 1] = 0;
                                                            boardWriting(board, size_arr);
                                                            ScoreP1++;
                                                            FileWriteScoreP1(ScoreP1);

                                                        }
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Error";
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    // Other
                                    else
                                    {
                                        if (board[a][b] == 1)
                                        {
                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
                                            {
                                                if (board[a + 1][b] == 0 || board[a][b + 1] == 0 || board[a - 1][b] == 0 || board[a][b - 1] == 0)
                                                {
                                                    if ((board[i][j] == 0) && (i == a || j == b))
                                                    {
                                                        turn = 2;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 1;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        break;
                                                    }
                                                }
                                            }
                                            else if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450) || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450) || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) || (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
                                            {
                                                if (a == i && b != j)
                                                {
                                                    if ((board[a][b + 1] == 2 || board[a][b - 1] == 2)
                                                        && (board[i][j] == 0))
                                                    {
                                                        if ((board[i][j] == 0) && (i == a))
                                                        {
                                                            turn = 2;
                                                            FileWriteturn(turn);
                                                            count1 = 1;
                                                            board[a][b] = 0;
                                                            board[i][j] = 1;
                                                            FileWrite(array, size_arr);
                                                            boardWriting(board, size_arr);
                                                            bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                            bead_p1[a][b].setFillColor(Color::Transparent);
                                                            if (i > a && j == b)
                                                            {
                                                                bead_p1[i - 1][b].setFillColor(Color::Transparent);
                                                                board[i - 1][b] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP1++;
                                                                FileWriteScoreP1(ScoreP1);
                                                            }
                                                            else if (i == a && j > b)
                                                            {
                                                                bead_p1[a][j - 1].setFillColor(Color::Transparent);
                                                                board[a][j - 1] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP1++;
                                                                FileWriteScoreP1(ScoreP1);
                                                            }
                                                            else if (i < a && j == b)
                                                            {
                                                                bead_p1[i + 1][b].setFillColor(Color::Transparent);
                                                                board[i + 1][b] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP1++;
                                                                FileWriteScoreP1(ScoreP1);
                                                            }
                                                            else if (i == a && j < b)
                                                            {
                                                                bead_p1[a][j + 1].setFillColor(Color::Transparent);
                                                                board[a][j + 1] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP1++;
                                                                FileWriteScoreP1(ScoreP1);
                                                            }
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            cout << "Error";
                                                        }
                                                    }
                                                }
                                                else if (a != i && b == j)
                                                {
                                                    if ((board[a + 1][b] == 2 || board[a - 1][b] == 2)
                                                        && (board[i][j] == 0))
                                                    {
                                                        if ((board[i][j] == 0) && (j == b))
                                                        {
                                                            turn = 2;
                                                            FileWriteturn(turn);
                                                            count1 = 1;
                                                            board[a][b] = 0;
                                                            board[i][j] = 1;
                                                            FileWrite(array, size_arr);
                                                            boardWriting(board, size_arr);
                                                            bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                            bead_p1[a][b].setFillColor(Color::Transparent);
                                                            if (i > a && j == b)
                                                            {
                                                                bead_p1[i - 1][b].setFillColor(Color::Transparent);
                                                                board[i - 1][b] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP1++;
                                                                FileWriteScoreP1(ScoreP1);
                                                            }
                                                            else if (i == a && j > b)
                                                            {
                                                                bead_p1[a][j - 1].setFillColor(Color::Transparent);
                                                                board[a][j - 1] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP1++;
                                                                FileWriteScoreP1(ScoreP1);
                                                            }
                                                            else if (i < a && j == b)
                                                            {
                                                                bead_p1[i + 1][b].setFillColor(Color::Transparent);
                                                                board[i + 1][b] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP1++;
                                                                FileWriteScoreP1(ScoreP1);
                                                            }
                                                            else if (i == a && j < b)
                                                            {
                                                                bead_p1[a][j + 1].setFillColor(Color::Transparent);
                                                                board[a][j + 1] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP1++;
                                                                FileWriteScoreP1(ScoreP1);
                                                            }
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            cout << "Error";
                                                        }
                                                    }
                                                }

                                            }
                                        }

                                    }
                                }

                            }
                            if (count1 == 1)
                            {
                                count1 = 0;
                                break;
                            }

                        }
                    }



                    //Player 2

                    else if (turn == 2)
                    {
                        for (int i = 0;i < size_arr;i++)
                        {
                            for (int j = 0;j < size_arr;j++)
                            {


                                if (mousePosN.x >= array[i][j].x && mousePosN.x <= array[i][j].x + 40
                                    && mousePosN.y >= array[i][j].y && mousePosN.y <= array[i][j].y + 40)
                                {



                                    // Diagonals & Upper and Lower Diagonal Diamond Lines



                                    if ((((i - a == 2) && (j - b == 2)) || ((i - a == -2) && (j - b == -2)) || ((i - a == 1) && (j - b == 1)) || ((i - a == -1) && (j - b == -1))) && (((a + b) % 2 == 0) && (i + j) % 2 == 0))
                                    {
                                        if (board[a][b] == 2)
                                        {
                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
                                            {
                                                if (board[a + 1][b + 1] == 0 || board[a - 1][b - 1] == 0)
                                                {
                                                    if ((board[i][j] == 0) && ((i > a && j > b) || (i < a && j < b)))
                                                    {
                                                        turn = 1;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 2;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        break;
                                                    }
                                                }
                                            }
                                            else if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450) || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450) || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) || (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
                                            {
                                                if ((board[a + 1][b + 1] == 1 || board[a - 1][b - 1] == 1) && (board[i][j] == 0))
                                                {
                                                    if ((board[i][j] == 0) && ((i > a && j > b) || (i < a && j < b)))
                                                    {
                                                        turn = 1;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 2;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        if (i < a && j < b)
                                                        {
                                                            bead_p1[i + 1][j + 1].setFillColor(Color::Transparent);
                                                            board[i + 1][j + 1] = 0;
                                                            boardWriting(board, size_arr);
                                                            ScoreP2++;
                                                            FileWriteScoreP2(ScoreP2);
                                                        }
                                                        else if (i > a && j > b)
                                                        {
                                                            bead_p1[i - 1][j - 1].setFillColor(Color::Transparent);
                                                            board[i - 1][j - 1] = 0;
                                                            boardWriting(board, size_arr);
                                                            ScoreP2++;
                                                            FileWriteScoreP2(ScoreP2);

                                                        }
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Error";
                                                    }

                                                }
                                            }
                                        }

                                    }

                                    // Anti-Diagonals and Anti Diaginal Diamond Lines

                                    else if ((((i - a == 2) && (j - b == -2)) || ((i - a == -2) && (j - b == 2)) || ((i - a == 1) && (j - b == -1)) || ((i - a == -1) && (j - b == 1))) && (((a + b) % 2 == 0) && (i + j) % 2 == 0))
                                    {
                                        if (board[a][b] == 2)
                                        {
                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
                                            {
                                                if (board[a - 1][b + 1] == 0 || board[a + 1][b - 1] == 0)
                                                {
                                                    if ((board[i][j] == 0) && ((i > a && j < b) || (i < a && j > b)))
                                                    {
                                                        turn = 1;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 2;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        break;
                                                    }
                                                }
                                            }
                                            else if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450) || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450) || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) || (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
                                            {
                                                if ((board[a - 1][b + 1] == 1 || board[a + 1][b - 1] == 1) && (board[i][j] == 0))
                                                {
                                                    if ((board[i][j] == 0) && ((i > a && j < b) || (i < a && j > b)))
                                                    {
                                                        turn = 1;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 2;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        if (i < a && j > b)
                                                        {
                                                            bead_p1[i + 1][j - 1].setFillColor(Color::Transparent);
                                                            board[i + 1][j - 1] = 0;
                                                            boardWriting(board, size_arr);
                                                            ScoreP2++;
                                                            FileWriteScoreP2(ScoreP2);
                                                        }
                                                        else if (i > a && j < b)
                                                        {
                                                            bead_p1[i - 1][j + 1].setFillColor(Color::Transparent);
                                                            board[i - 1][j + 1] = 0;
                                                            boardWriting(board, size_arr);
                                                            ScoreP2++;
                                                            FileWriteScoreP2(ScoreP2);

                                                        }
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Error";
                                                    }

                                                }
                                            }
                                        }
                                    }
                                    // Other
                                    else
                                    {
                                        if (board[a][b] == 2)
                                        {
                                            if ((mousePosN.x - array[a][b].x >= 150 && mousePosN.x - array[a][b].x <= 250)
                                                || (mousePosN.y - array[a][b].y >= 150 && mousePosN.y - array[a][b].y <= 250)
                                                || (array[a][b].x - mousePosN.x >= 150 && array[a][b].x - mousePosN.x <= 250) ||
                                                (array[a][b].y - mousePosN.y >= 150 && array[a][b].y - mousePosN.y <= 250))
                                            {
                                                if (board[a + 1][b] == 0 || board[a][b + 1] == 0 || board[a - 1][b] == 0 || board[a][b - 1] == 0)
                                                {
                                                    if ((board[i][j] == 0) && (i == a || j == b))
                                                    {
                                                        turn = 1;
                                                        FileWriteturn(turn);
                                                        count1 = 1;
                                                        board[a][b] = 0;
                                                        board[i][j] = 2;
                                                        FileWrite(array, size_arr);
                                                        boardWriting(board, size_arr);
                                                        bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                        bead_p1[a][b].setFillColor(Color::Transparent);
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Error";
                                                    }
                                                }
                                            }
                                            else if ((mousePosN.x - array[a][b].x >= 350 && mousePosN.x - array[a][b].x <= 450) || (mousePosN.y - array[a][b].y >= 350 && mousePosN.y - array[a][b].y <= 450) || (array[a][b].x - mousePosN.x >= 350 && array[a][b].x - mousePosN.x <= 450) || (array[a][b].y - mousePosN.y >= 350 && array[a][b].y - mousePosN.y <= 450))
                                            {
                                                if (a == i && b!=j)
                                                {
                                                    if ((board[a][b + 1] == 1 ||
                                                        board[a][b - 1] == 1) && (board[i][j] == 0))
                                                    {
                                                        if ((board[i][j] == 0) && (i == a))
                                                        {
                                                            turn = 1;
                                                            FileWriteturn(turn);
                                                            count1 = 1;
                                                            board[a][b] = 0;
                                                            board[i][j] = 2;
                                                            FileWrite(array, size_arr);
                                                            boardWriting(board, size_arr);
                                                            bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                            bead_p1[a][b].setFillColor(Color::Transparent);
                                                            if (i > a && j == b)
                                                            {
                                                                bead_p1[i - 1][b].setFillColor(Color::Transparent);
                                                                board[i - 1][b] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP2++;
                                                                FileWriteScoreP2(ScoreP2);
                                                            }
                                                            else if (i == a && j > b)
                                                            {
                                                                bead_p1[a][j - 1].setFillColor(Color::Transparent);
                                                                board[a][j - 1] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP2++;
                                                                FileWriteScoreP2(ScoreP2);
                                                            }
                                                            else if (i < a && j == b)
                                                            {
                                                                bead_p1[i + 1][b].setFillColor(Color::Transparent);
                                                                board[i + 1][b] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP2++;
                                                                FileWriteScoreP2(ScoreP2);
                                                            }
                                                            else if (i == a && j < b)
                                                            {
                                                                bead_p1[a][j + 1].setFillColor(Color::Transparent);
                                                                board[a][j + 1] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP2++;
                                                                FileWriteScoreP2(ScoreP2);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        cout << "Error";
                                                    }
                                                }
                                                else if (b == j && a!=i)
                                                {
                                                    if ((board[a + 1][b] == 1 || board[a - 1][b] == 1)
                                                        && (board[i][j] == 0))
                                                    {
                                                        if ((board[i][j] == 0) && (j == b))
                                                        {
                                                            turn = 1;
                                                            FileWriteturn(turn);
                                                            count1 = 1;
                                                            board[a][b] = 0;
                                                            board[i][j] = 2;
                                                            FileWrite(array, size_arr);
                                                            boardWriting(board, size_arr);
                                                            bead_p1[i][j].setFillColor(bead_p1[a][b].getFillColor());
                                                            bead_p1[a][b].setFillColor(Color::Transparent);
                                                            if (i > a && j == b)
                                                            {
                                                                bead_p1[i - 1][b].setFillColor(Color::Transparent);
                                                                board[i - 1][b] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP2++;
                                                                FileWriteScoreP2(ScoreP2);
                                                            }
                                                            else if (i == a && j > b)
                                                            {
                                                                bead_p1[a][j - 1].setFillColor(Color::Transparent);
                                                                board[a][j - 1] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP2++;
                                                                FileWriteScoreP2(ScoreP2);
                                                            }
                                                            else if (i < a && j == b)
                                                            {
                                                                bead_p1[i + 1][b].setFillColor(Color::Transparent);
                                                                board[i + 1][b] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP2++;
                                                                FileWriteScoreP2(ScoreP2);
                                                            }
                                                            else if (i == a && j < b)
                                                            {
                                                                bead_p1[a][j + 1].setFillColor(Color::Transparent);
                                                                board[a][j + 1] = 0;
                                                                boardWriting(board, size_arr);
                                                                ScoreP2++;
                                                                FileWriteScoreP2(ScoreP2);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        cout << "Error";
                                                    }
                                                }
                                                
                                            }
                                        }
                                    }





                                }

                            }
                            if (count1 == 1)
                            {
                                count1 = 0;
                                break;
                            }

                        }
                    }
                }
                else
                {
                    cout << "Out of Range!";
                }

            }
        }
        if (ScoreP1 == 12)
        {
            Winner(window, size, ScoreP1, turn, ScoreP2, board);

        }
        else if (ScoreP2 == 12)
        {
             Winner(window, size, ScoreP1, turn, ScoreP2, board);
        }
    
        // Updating
        // Clear Window Every Time
        window.clear(Color(147, 209, 255));
        // Draw Objects Every Time
        bordLines(window, size);
        PlayerBox(window, size, turn);
        Score(window, size, ScoreP1, ScoreP2);
        for (int i = 0; i < size_arr; i++)
        {
            for (int j = 0; j < size_arr; j++)
            {
                window.draw(bead_p1[i][j]);
            }
        }
        // Display New Objects Every Time
        window.display();
    }
}
