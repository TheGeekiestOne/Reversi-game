// Reversi-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
////////////////////////////////////////////////////////////////////////////////
// Created By Ayran Olckers
// 
// 
// Reversi
////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include <iostream>


using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main Menu
int mainMenu();

// Checks if the player's move is valid; 0 = Valid; 1 = Not Valid
int badMove(char reversiBoard[][8], int xCoord, int yCoord, int playersTurn);

// Returns who won 1 = Black; 2 = White; 3 = Tie
int gameOver();

// Clears and intializes the board at the beginning of the game
void intializeBoard(char reversiBoard[][8]);

// Gets each player's move
void play(int& xCoord, int& yCoord, int playersTurn);

// Checks for discs to flip and updates the board; Switches turns
void updateBoard(char reversiBoard[][8], int xCoord, int yCoord, int& playersTurn);

// Displays the board
void displayBoard(char reversiBoard[][8]);

// Directions on how to play the game
void howToPlay();

////////////////////////////////////////////////////////////////////////////////

int main()
{
	// Holds menu choice
	int choice = 0;

	// Holds winner of game
	int intGameOver = 0;

	// Coordinates user selects
	int xCoord;
	int yCoord;

	// Black = 1; White = 2 - Black always starts
	int playersTurn = 1;

	// Holds individual squares for the Reversi board
	char reversiBoard[8][8];

	do
	{
		// Main Menu choice
		choice = mainMenu();

		switch (choice)
		{
			// Play Game
		case 1: intializeBoard(reversiBoard);
			do
			{
				// Displays the board
				displayBoard(reversiBoard);

				// Gets the coordinate of the player's move
				play(xCoord, yCoord, playersTurn);

				// Checks if the move is valid; Start turn over if true
				if (badMove(reversiBoard, xCoord, yCoord, playersTurn) == 1)
				{
					continue;
				}

				// Checks for / Flips appropriate disks
				updateBoard(reversiBoard, xCoord, yCoord, playersTurn);

				// Checks to see if the game is over and who won
				intGameOver = gameOver();

			} while (1);
			break;

			// How to Play        
		case 2: howToPlay();
			break;

			// Exit
		case 0: break;

			// Error
		default: cout << "Error! int main()" << endl;
			cout << "Choice = " << choice << endl;
			break;
		}

		// Displays winner's message if the user didn't exit
		if (choice != 0)
		{
			switch (intGameOver)
			{
			case 1: cout << "Black is the winner!" << endl;
				break;
			case 2: cout << "White is the winner!" << endl;
				break;
			case 3: cout << "It is a draw!" << endl;
				break;
			default: cout << "Error! int main() gameOver" << endl;
				cout << "intGameOver = " << intGameOver << endl;
				break;
			}
		}

		// Exit
		if (choice == 0 || (intGameOver >= 1 && intGameOver <= 3))
		{
			break;
		}

	} while (1);

	cout << "Please press enter to continue...";
	cin.ignore(99, '\n');
	getchar();

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Main Menu

int mainMenu()
{
	int choice = 0;

	cout << "Reversi" << endl << endl;

	do
	{
		// Main Menu
		cout << "Please choose an option" << endl;
		cout << "1 - Play Game!" << endl;
		cout << "2 - How to Play?" << endl;
		cout << "0 - Exit." << endl;
		cout << ": ";
		cin >> choice;

		// Checks if a valid value was entered
		if ((choice < 0) || (choice > 2) || (!cin.good()))
		{
			system("CLS");
			cout << "Reversi" << endl << endl;
			cout << "Invalid Option!" << endl << endl;

			// Clears and resets the buffer if not
			cin.clear();
			cin.ignore(99, '\n');

			choice = 0;

			continue;
		}

		break;

	} while (1);

	return choice;
}

////////////////////////////////////////////////////////////////////////////////
// Clears and intializes the board at the beginning of the game

void intializeBoard(char reversiBoard[][8])
{
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			switch (x)
			{
				// Column 1
			case 0: reversiBoard[y][x] = ' ';
				break;
				// Column 2
			case 1: reversiBoard[y][x] = ' ';
				break;
				// Column 3
			case 2: reversiBoard[y][x] = ' ';
				break;
				// Column 4
			case 3: reversiBoard[y][x] = ' ';
				break;
				// Column 5
			case 4: reversiBoard[y][x] = ' ';
				break;
				// Column 6
			case 5: reversiBoard[y][x] = ' ';
				break;
				// Column 7
			case 6: reversiBoard[y][x] = ' ';
				break;
				// Column 8
			case 7: reversiBoard[y][x] = ' ';
				break;
				// Error
			default: cout << endl << "Error! intializeBoard()" << endl;
				break;
			}
		}
	}

	// Sets the starting positions
	reversiBoard[3][3] = 'O';
	reversiBoard[3][4] = 'X';
	reversiBoard[4][3] = 'X';
	reversiBoard[4][4] = 'O';

}

////////////////////////////////////////////////////////////////////////////////
// Gets each player's move

void play(int& xCoord, int& yCoord, int playersTurn)
{
	// Black = 1; White = 2
	switch (playersTurn)
	{
	case 1: cin.ignore(99, '\n');
		cout << "[Black] Enter a coordinate [X Y]: ";
		cin >> xCoord >> yCoord;
		break;

	case 2: cin.ignore(99, '\n');
		cout << "[White] Enter a coordinate [X Y]: ";
		cin >> xCoord >> yCoord;
		break;

	default: cout << "Error! int play()" << endl;
		cout << "Please press enter to continue...";
		cin.ignore(99, '\n');
		getchar();
		break;
	}

}

////////////////////////////////////////////////////////////////////////////////
// Checks if the player's move is valid; 0 = Valid, 1 = Not Valid

int badMove(char reversiBoard[][8], int xCoord, int yCoord, int playersTurn)
{
	// Coordinate out of bounce or not numeric
	if (xCoord < 1 || xCoord > 8 || yCoord < 1 || yCoord > 8 || !cin.good())
	{
		cout << "Bad Move, out of bounce.";
		cin.ignore(99, '\n');
		getchar();
		return 1;

	}

	if (reversiBoard[yCoord - 1][xCoord - 1] != ' ')
	{
		cout << "Bad Move, Don't Leave Blank.";
		cin.ignore(99, '\n');
		getchar();
		return 1;
	}

	// Good Move
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Checks for player pieces to flip and updates the board; swaps turns

void updateBoard(char reversiBoard[][8], int xCoord, int yCoord, int& playersTurn)
{
	switch (playersTurn)
	{
	case 1: reversiBoard[yCoord - 1][xCoord - 1] = 'X';
		playersTurn = 2;
		break;

	case 2: reversiBoard[yCoord - 1][xCoord - 1] = 'O';
		playersTurn = 1;
		break;
	}

}

////////////////////////////////////////////////////////////////////////////////
// Displays the board

void displayBoard(char reversiBoard[][8])
{
	system("CLS");

	cout << "               Reversi            " << endl;
	cout << "     Created by: Ayran Olckers     " << endl;
	cout << "   -------------------------------" << endl;


	for (int r = 0; r < 8; ++r)
	{
		cout << r + 1 << " ";
		cout << "| ";

		for (int c = 0; c < 8; ++c)
		{
			cout << reversiBoard[r][c] << " | ";
		}

		cout << endl << "   -------------------------------" << endl;

	}

	cout << "    A   B   C   D   E   F   G   H   " << endl << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Returns who won 1 = Black; 2 = White; 3 = Tie

int gameOver()
{

	return -1;
}

////////////////////////////////////////////////////////////////////////////////
// Directions on how to play the game

void howToPlay()
{
	system("CLS");

	cout << "How to play Reversi" << endl;
	cout << "Directions..." << endl;

	cout << "Please press enter to continue...";
	cin.ignore(99, '\n');
	getchar();

	system("CLS");
}

////////////////////////////////////////////////////////////////////////////////