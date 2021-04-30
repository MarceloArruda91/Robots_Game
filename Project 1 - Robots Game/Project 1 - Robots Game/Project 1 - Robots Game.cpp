// Project 1 - Robots Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void el() // Empyt Line
{
    cout << endl;
}


void Exit()
{
    cout << "Game Over!" << endl;
    exit(0);
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


void open_maze(string maze_n){ // Open and build selected maze
    ifstream in(maze_n);
    vector<vector<char> > v;
    
    if (in) {
        string line;
        
        while (getline(in, line)) {
            v.push_back(vector<char>());
            
            // Break down the row into column values
            stringstream split(line);
            char value;
            
            while (split >> value)
                v.back().push_back(value);
        }
    }
    
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j];	
            
        cout << '\n';
    }

}


void movement()
{
    char move;
    cout << "Move";
    el();
    cin >> move;

    if (move != "Q" or move != "W" or move != "E" or move != "A" or move != "S" or move != "D" or move != "Z" or move != "X" or move != "C") 
    {
        cout << "Invalid Option! Try Again!" << endl;
        choose_maze();
    }
}


void choose_maze()
{
    int choose;
    cout << "Choose a maze";
    el();
    cout << "1) Maze 1";
    el();
    cout << "2) Maze 2";
    el();
    cout << "3) Maze 3";
    el();

    cin >> choose;

    if (choose < 1 or choose > 3) 
    {
        cout << "Invalid Option! Try Again!" << endl;
        choose_maze();
    }
    
    else
    {
        switch (choose) {
        case 1: 
            open_maze("MAZE_01.txt");
            el();
            break;
        case 2: 
            open_maze("MAZE_02.txt");
            el();
            break;
        case 3:
            open_maze("MAZE_03.txt");
            el();
            break;
        }
    }
    
  
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
            choose_maze();
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
