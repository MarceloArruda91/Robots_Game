// Project 1 - Robots Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

using namespace std;


#define fp 1 //Eletrical fence or post
#define e 0 //Empyt 
#define H 2 //Player
#define R 3 //Robots
#define r 4 //Dead Robots
#define h 5 //Dead Player

int linha = 1, coluna = 1;

int maze[8][8] =
{
1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1
};

void build_maze()
{
    int l, c;
    for (l = 0; l < 8; l++) {
        for (c = 0; c < 8; c++) 
        {
            if (maze[l][c] == e) printf("   ");
            if (maze[l][c] == fp) printf("*  ");
            /*if (maze[l][c] == H) printf(" H ");
            if (maze[l][c] == h) printf(" h ");
            if (maze[l][c] == R) printf(" R ");
            if (maze[l][c] == r) printf(" r ");*/
        }
        printf("\n");

    }
    printf("\n\n");
}


void el() // Empyt Line
{
    cout << endl;
}

void Exit()
{
    cout << "Game Over!" << endl;
    exit(0);
}

void Game()
{  
    build_maze();
}


void Rules()
{
    int chose;
    cout << "The player is placed in a maze made up of high-voltage fences and posts." << endl;
    cout << "There are also some interceptor robots that  will try to destroy the player." << endl;
    cout << "If the player touches the maze or any of these robots, that is the end of the game (and the player!)." << endl;
    cout << "The robots are also destroyed when they touch the fences/posts or when they collide with each other." << endl;
    cout << "Every time the player moves in any direction (horizontally, vertically, or diagonally) to a contiguous cell, each robot ";
    cout << "moves one cell closer to the new player's location, in whichever direction is the shortest path." << endl;
    cout << "The robots have no vision sensors but they have an accurate odour sensor that allows them to follow the player!" << endl;
    cout << "There is one hope: make the robots hit the maze or each other. If all of them are destroyed, the player wins." << endl;
    el();
    cout << "HOW TO PLAY?" << endl;
    cout << "Use the following comands to play:" << endl;
    cout << "Q -> up left diagonally" << endl;
    cout << "W -> up" << endl;
    cout << "E -> up right diagonally" << endl;
    cout << "A -> left" << endl;
    cout << "D -> right" << endl;
    cout << "Z -> down left diagonally" << endl;
    cout << "X -> down" << endl;
    cout << "C -> down right diagonally" << endl;
    cout << "S -> stay in the same place" << endl;
    cout << "Hint: If you can't remember the comands, look to your keyboard, imagine that you are in the letter S and the neighbors" << endl;
    cout << "keys are the steps that you can go!" << endl; 
    el();
    el();
    cout << "1) Back to Menu" << endl;
    cout << "0) Exit" << endl;
   
}



void Menu()
{
    int chose;
    cout << "1) Rules" << endl;
    el();
    cout << "2) Play" << endl;
    el();
    cout << "0) Exit" << endl;
    el();
    cin >> chose;
    el();
    if (chose < 0 or chose > 2) 
    {
        cout << "Invalid Option! Try Again!" << endl;
        Menu();
    }
    
    else
    {
        switch (chose) {
        case 1: 
            Rules();
            el();
            int op;
            cin >> op;
            el();
            switch (op) {
            case 1: 
                Menu();
                break;
            case 0: 
                Exit();
                break;
            }
            break;
        case 2: 
            Game();
            break;
        case 0:
            Exit();
            break;
        }
    }

}


int main()
{
    Menu();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
