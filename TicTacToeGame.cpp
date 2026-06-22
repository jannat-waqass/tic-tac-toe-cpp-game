// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<time.h> // provides access to time manipulation or formatting
#include<cstdlib> // used to declare general purpose functions
char board[4][4] = { {' ','1','2','3'},{'1','?','?','?'},{'2','?','?','?'},{'3','?','?','?'} }; // Declare the board as a 2D array
char PlayerX = 'X'; // Player 1 will always be X
char PlayerO = 'O'; // Player 2 will always be O
int p1 = 1;
int p2 = 2;
void menu();
void Display_Board();
void Player_Choice(int);
void PlayerX_Choice();
void PlayerO_Choice();
void Human_Vs_Human();
bool Check_Winner();
bool defend(int, int, int);
bool attack();
void Computer_Choice(int);
void Human_Vs_Computer();
using namespace std;
int b[4][4] = { 0 }; // additional array for efficient computer Vs Human Game.
int main()
{
	menu();
	system("pause>0");
	return 0;
}
//Main Menu Function
void menu()
{ // This function is the main display of the game where the player chooses the game mode they want to play.
	system("cls");
	int choice; 
	cout << "\n\t\t\t\t\tTic Tac Toe Game";
	cout << "\n\n\t\t\t\t1.Human VS Human";
	cout << "\n\t\t\t\t2.Human VS Computer";
	cout << "\n\t\t\t\t3.Exit\n";
	cin >> choice;
	switch (choice) // switch statment used for selecting game mode based on users input.
	{
	case 1:
		Display_Board();
		Human_Vs_Human();
		break;
	case 2:
		Human_Vs_Computer();
		break;
	case 3:
		exit(1);
	default:
		cout << "Please Enter a Valid Choice(1, 2 or 3)\n";
		system("pause>0");
		menu();
	}
}
//Function for display board
void Display_Board()
{
	system("cls");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << " " << board[i][j] << " ";
		}
		cout << endl;
	}
}

//Input Function
void Player_Choice(int turn) // Take the input of the player's choice based on who will play first.
{
	int row, col;
	cout << "Please Enter Row Number:\t";
	cin >> row;
	cout << "Please Enter Column Number:\t";
	cin >> col;
	if (row < 4 && row > 0 && col < 4 && col > 0) // The row and column entered must be between 1 and 3
	{
		if (board[row][col] == '?')
		{
			if (turn == 1) // Turn = 1 means Player 1 goes first.
			{
				board[row][col] = PlayerX;
				b[row][col] = p1; // This additional array will fill this element in the array so that the computer does not choose this row & col in its turn.
			}
			else
			{
				board[row][col] = PlayerO;
				b[row][col] = p2;
			}
		}
		else
		{
			cout << "This Cell Is Already Full\n";
			Player_Choice(turn);
		}
	}
	else
	{
		cout << "Please Enter A Valid Cell Number\n";
		Player_Choice(turn);
	}
}

//Player1 Turn Function
void PlayerX_Choice()
{
	system("cls"); // clears the screen after every game
	Display_Board();
	cout << "Player 1 [X] : Your Turn\n";
	Player_Choice(1);
}
//Player2 Function
void PlayerO_Choice()
{
	system("cls");
	Display_Board();
	cout << "Player 2 [O] : Your Turn\n";
	Player_Choice(2);
}
//Player VS Player Game Funcation
void Human_Vs_Human()
{
	for (int i = 1; i < 4; i++)
	{
		PlayerX_Choice();
		if (i > 2) // If player X got more than 2 chances
		{
			if (Check_Winner()) // Checks if Player X won
			{
				system("cls");
				Display_Board();
				cout << "\n\t\t\t\tCongrats!! Player 1 Won The Game!!\n";
				cout << "\n\t\t\t\t";
				system("pause>0");
				menu();
			}
		}
		if (i == 3) // If chances are equal
		{
			system("cls");
			Display_Board();
			cout << "\n\t\t\t\tOopss!! Game Drawn!!\n";
			system("pause>0");
			menu();
		}
		PlayerO_Choice();
		if (i > 2) // If Player O got more than 2 chances
		{
			if (Check_Winner()) // Check if player 2 won
			{
				system("cls");
				Display_Board();
				cout << "\n\t\t\t\tCongrats!! Player 2 Won The Game!!\n";
				cout << "\n\t\t\t\t";
				system("pause>0");
				menu();
			}
		}

	}
}
//Check the Status Of Game
bool Check_Winner()
{// lists all possibilites for the player to win : Horizontally , Vertically and Diagonally
	for (int i = 1; i < 4; i++)
	{
		if ((board[i][1] != '?') && (board[i][1] == board[i][2]) && (board[i][2] == board[i][3]) || (board[1][i] != '?') && (board[1][i] == board[2][i]) && (board[2][i] == board[3][i]))
		{
			return true;
		}
	}
	if ((board[1][1] != '?') && (board[1][1] == board[2][2]) && (board[2][2] == board[3][3]))
	{
		return true;
	}
	else if ((board[1][3] != '?') && (board[1][3] == board[2][2]) && (board[2][2] == board[3][1]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool defend(int comp, int player, int brd) // takes 3 integer arguments .
	// Functions returns a boolean value based on whether the computer can made a move to defend itself from the human player.
{
	if (brd < 3) // indicates that less than 3 moves have been made on the board
	{
			return false; // no need for computer to defend.
	}
	// the function checks if the human player has two in a row or diagnol on the board. 
	// If so, then the function searches for an empty space in that row and places the computer's symbol in that space
	else if (b[1][1] + b[2][2] + b[3][3] == 3 * comp && b[1][1] != player && b[2][2] != player && b[3][3] != player)
	{
			for (int i = 1; i < 4; i++)
			{
				if (b[i][i] == 0)
				{
					b[i][i] = p2;
					board[i][i] = PlayerO;
					return true;
				}
			}
		}
	else if (b[1][3] + b[2][2] + b[3][1] == 3 * comp &&  b[1][3] != player && b[2][2] != player && b[3][1] != player)
	{
		for (int i = 1; i < 4; i++)
		{
			if (b[i][3 - i] == 0)
			{
				b[i][3 - i] = p2;
				board[i][3 - i] = PlayerO;
				return true;
			}
		}
	}
	else
	{
		for (int i = 1; i < 4; i++)
		{
			if (b[i][1] + b[i][2] + b[i][3] == 3 * comp &&  b[i][1] != player && b[i][2] != player && b[i][3] != player)
			{
				for (int j = 1; j < 4; j++)
				{
					if (b[i][j] == 0)
					{
						b[i][j] = p2;
						board[i][j] = PlayerO;
						return true;
					}
				}
			}
			else if (b[1][i] + b[2][i] + b[3][i] == 3 * comp && b[1][i] != player && b[2][i] != player && b[3][i] != player)
			{
				for (int j = 1; j < 4; j++)
				{
					if (b[j][i] == 0)
					{
						b[j][i] = p2;
						board[j][i] = PlayerO;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool attack() // implements an attacking strategy for the computer 
{
	// checks if all corners of the board are X or O
	if (b[1][1] + b[1][3] + b[3][1] + b[3][3] == p1 || b[1][1] + b[1][3] + b[3][1] + b[3][3] == 4 * p1)
	{
		for (int i = 1; i < 4; i++)
		{
			// Checks if the computer can win in the next move.
			// It does this by checking all rows and diagnols where the computer has already placed two of its moves.
			if (b[i][1] + b[i][2] + b[i][3] == p2 && b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2 || b[i][3] == p2)
			{
				if (i == 3)
				{
					for (int j = 1; j < 4; j++)
					{
						// The computer places its symbol in the next empty position available.
						if (b[i][j] == 0)
						{
							b[i][j] = p2;
							board[i][j] = PlayerO;
							return true;
						}
					}
				}
				else
				{
					for (int j = 3; j >= 1; j--)
					{
						if (b[i][j] == 0)
						{
							b[i][j] = p2;
							board[i][j] = PlayerO;
							return true;
						}
					}
				}
			}
			if (b[1][i] + b[2][i] + b[3][i] == p2 && b[1][i] == p2 || b[2][i] == p2 || b[3][i] == p2)
			{
				if (i == 3)
				{
					for (int j = 1; j < 4; j++)
					{
						if (b[j][i] == 0)
						{
							b[j][i] = p2;
							board[j][i] = PlayerO;
							return true;
						}
					}
				}
				else
				{
					for (int j = 3; j >= 1; j--)
					{
						if (b[j][i] == 0)
						{
							b[j][i] = p2;
							board[j][i] = PlayerO;
							return true;
						}
					}
				}
			} 
		}
		if (b[1][1] + b[1][1] + b[3][3] == p2 && b[1][1] == p2 || b[2][2] == p2 || b[3][3] == p2)
		{
			for (int i = 3; i >= 1; i--)
			{
				if ((b[i][i] == 0) && ((b[i][1] + b[i][2] + b[i][3] == p2 && (b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2)) || ((b[1][i] + b[2][i] + b[3][i] == p2) && (b[1][i] == p2 || b[2][i] == p2 || b[3][i] == p2))))
				{
					b[i][i] = p2;
					board[i][i] = PlayerO;
					return true;
				}
			}
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][i] == 0)
				{
					if (((b[i][1] + b[i][2] + b[i][3] == p1 && (b[i][1] == p1 || b[i][2] == p1 || b[i][3] == p1)) || ((b[1][i] + b[2][i] + b[3][i] == p1) && (b[1][i] == p1 || b[2][i] == p1 || b[3][i] == p1))))
					{
						b[i][i] = p2;
						board[i][i] = PlayerO;
						return true;
					}
				}
			}
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][i] == 0)
				{
					b[i][i] = p2;
					board[i][i] = PlayerO;
					return true;
				}
			}
		}
		else if (b[1][3] + b[2][2] + b[3][1] == p2 && b[1][3] == p2 || b[2][2] == p2 || b[3][1] == p2)
		{
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][3 - i] == 0 && ((b[i][1] + b[i][2] + b[i][3] == p2 && (b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2)) || ((b[1][3 - i] + b[2][3 - i] + b[3][3 - i]) && (b[1][3 - i] == p2 || b[2][3 - i] == p2 || b[3][3 - i] == p2))))
				{
					b[i][3 - i] = p2;
					board[i][3 - i] = PlayerO;
					return true;
				}
			}
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][3 - i] == 0)
				{
					if (((b[i][1] + b[i][2] + b[i][3] == p1 && (b[i][1] == p1 || b[i][2] == p1 || b[i][3] == p1)) || ((b[1][3 - i] + b[2][3 - i] + b[3][3 - i] == p1) && (b[1][3 - i] == p1 || b[2][3 - i] == p1 || b[3][3 - i] == p1))))
					{
						b[i][3 - i] = p2;
						board[i][3 - i] = PlayerO;
						return true;
					}
				}
			}
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][3 - i] == 0)
				{
					b[i][3 - i] = p2;
					board[i][3 - i] = PlayerO;
					return true;
				}
			}
		}
	}
	else
	{
		if (b[1][1] + b[2][2] + b[3][3] == p2 && (b[1][1] == p2 || b[2][2] == p2 || b[3][3] == p2))
		{
			for (int i = 3; i >= 1; i--)
			{
				if ((b[i][i] == 0) && ((b[i][1] + b[i][2] + b[i][3] == p2 && (b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2)) || ((b[1][i] + b[2][i] + b[3][i] == p2) && (b[1][i] == p2 || b[2][i] == p2 || b[3][i] == p2))))
				{
					b[i][i] = p2;
					board[i][i] = PlayerO;
					return true;
				}
			}
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][i] == 0)
				{
					if (((b[i][1] + b[i][2] + b[i][3] == p1 && (b[i][1] == p1 || b[i][2] == p1 || b[i][3] == p1)) || ((b[1][i] + b[2][i] + b[3][i] == p1) && (b[1][i] == p1 || b[2][i] == p1 || b[3][i] == p1))))
					{
						b[i][i] = p2;
						board[i][i] = PlayerO;
						return true;
					}
				}
			}
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][i] == 0)
				{
					b[i][i] = p2;
					board[i][i] = PlayerO;
					return true;
				}
			}
		}
		else if (b[1][3] + b[2][2] + b[3][1] == p2 && b[1][3] == p2 || b[2][2] == p2 || b[3][1] == p2)
		{
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][3 - i] == 0 && ((b[i][1] + b[i][2] + b[i][3] && (b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2)) || ((b[1][3 - i] + b[2][3 - i] + b[3][3 - i] == p2) && (b[1][3 - i] == p2 || b[2][3 - i] == p2 || b[3][3 - i] == p2))))
				{
					b[i][3 - i] = p2;
					board[i][3 - i] = PlayerO;
					return true;
				}
			}
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][3 - i] == 0)
				{
					if (((b[i][1] + b[i][2] + b[i][3] == p1 && (b[i][1] == p1 || b[i][2] == p1 || b[i][3] == p1)) || ((b[1][3 - i] + b[2][3 - i] + b[3][3 - i] == p1) && (b[1][3 - i] == p1 || b[2][3 - i] == p1 || b[3][3 - i] == p1))))
					{
						b[i][3 - i] = p2;
						board[i][3 - i] = PlayerO;
						return true;
					}
				}
			}
			for (int i = 3; i >= 1; i--)
			{
				if (b[i][3 - i] == 0)
				{
					b[i][3 - i] = p2;
					board[i][3 - i] = PlayerO;
					return true;
				}
			}
		}
		else
		{
			for (int i = 1; i < 4; i++)
			{
				if (b[i][1] + b[i][2] + b[i][3] == p2 && b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2)
				{
					if (i == 3)
					{
						for (int j = 1; j < 4; j++)
						{
							if (b[i][j] == 0)
							{
								b[i][j] = p2;
								board[i][j] = PlayerO;
								return true;
							}
						}
					}
					else
					{
						for (int j = 3; j >= 1; j--)
						{
							if (b[i][j] == 0)
							{
								b[i][j] = p2;
								board[i][j] = PlayerO;
								return true;
							}
						}
					}
				}
				else if (b[1][i] + b[2][i] + b[3][i] == p2 && b[1][i] == p2 || b[2][i] == p2 || b[3][i] == p2)
				{
					if (i == 3)
					{
						for (int j = 1; j < 4; j++)
						{
							if (b[j][i] == 0)
							{
								b[j][i] = p2;
								board[j][i] = PlayerO;
								return true;
							}
						}
					}
					else
					{
						for (int j = 3; j >= 1; j--)
						{
							if (b[j][i] == 0)
							{
								b[j][i] = p2;
								board[j][i] = PlayerO;
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

void Computer_Choice(int x) // This function takes an integer value as an argument and determines the computers move in the game using the attack and defend function.
{
	if (!defend(p2, p1, x)) // checks whether there is a need to defend. If yes, then the computer makes a defensive move to block the human player from winning
	{
		if (!defend(p1, p2, x)) // if there is no need to defend , it checks if there is an opportunity to win by calling the defend function
		{
			if ((b[1][1] + b[1][3] + b[3][1] + b[3][3] == p1 + p2 || b[1][1] + b[1][3] + b[3][1] + b[3][3] == p1 + 2 * p2) && b[2][2] == 0)
			{
				for (int i = 1; i < 4; i++)
				{
					for (int j = 1; j < 4; j++)
					{
						if (b[i][j] == 0)
						{
							b[i][j] = p2;
							board[i][j] = PlayerO;
							break;
						}
					}
				}
			}
			else if (x == 2 && b[2][2] == 0) // if no other option, computer checks if there is a chance to play at the centre square
			{
				b[2][2] = p2;
				board[2][2] = PlayerO;
				goto end;
			}
			if (!attack()) // if there is no chance to play on the centre square, computer calls the attack function to try and find a way to win
			{
				if (x == 0) // x = 0 means the first move of the game
				{
					time_t seconds; 
					time(&seconds);
					srand((unsigned int)seconds);
					int i, j;
					i = 1 + ((rand() % 2) * 2); // At first the computer chooses a random square at the corner
					j = 1 + ((rand() % 2) * 2);
					b[i][j] = p2;
					board[i][j] = PlayerO;
				}
				else if (b[2][2] == 0)
				{
					b[2][2] = p2;
					board[2][2] = PlayerO;
				}
				else  // Otherwise it chooses a random square within the board
				{
					for (int i = 1; i < 4; i++)
					{
						for (int j = 1; j < 4; j++)
						{
							if (b[i][j] == 0)
							{
								b[i][j] = p2;
								board[i][j] = PlayerO;
								break;
							}
						}
					}
				}
				
			}
		}
	
	}
end:
	cout << endl;
}

void Human_Vs_Computer()
{
	system("cls");
	cout << "\n\n\n\t\t\t\tYou Wanna Go 1st or 2nd(1 or 2)\n";
	int choice;
	cin >> choice;
	switch (choice)
		// If player wants to go first, game begins with player making the first move.
		// Otherwise the computer makes the first move
	{
	case 1:
		cout << "\t\t\t\tYour Symbol Is X And Computer's Symbol Is O\n";
		cout << "\t\t\t\t";
		system("pause>0");
		// Loop runs for 9 times which is the total spaces available in the board
		for (int i = 0; i < 9;)
		{
			system("cls");
			Display_Board(); // To display the current status of the board
			Player_Choice(p1); // Either the player or computer make a move depending on whose turn it is
			system("cls");
			Display_Board();
			i++;
			if (i > 3)
			{
				if (Check_Winner()) // After each move, the function checks if the game has been won or if it has ended in a draw.
				{
					system("cls");
					Display_Board();
					cout << "\n\t\t\t\tCongrats!! You Won The Game!!\n";
					cout << "\n\t\t\t\t";
					system("pause");
					menu();
				}
			}
			if (i >= 8)
			{
				system("cls");
				Display_Board();
				cout << "\n\t\t\t\tOopss!! Game Drawn!!\n";
				system("pause");
				menu();
			}
			Computer_Choice(i);
			system("cls");
			Display_Board();
			i++;
			if (i > 4)
			{
				if (Check_Winner())
				{
					system("cls");
					Display_Board();
					cout << "\n\t\t\t\Oopss!! Computer Won The Game!!\n";
					cout << "\n\t\t\t\t";
					system("pause>0");
					menu();
				}
			}
		}
		break;
	case 2:
	{
		p2 = 1;
		p1 = choice;
		PlayerX = 'O';
		PlayerO = 'X';

		cout << "\t\t\t\tYour Symbol Is O And Computer's Symbol Is X\n";
		cout << "\t\t\t\t";
		system("pause>0");
		for (int i = 0; i < 9;)
		{
			system("cls");
			Display_Board();
			Computer_Choice(i);
			system("cls");
			Display_Board();
			i++;
			if (i > 3)
			{
				if (Check_Winner())
				{
					system("cls");
					Display_Board();
					cout << "\n\t\t\t\Oopss!! Computer Won The Game!!\n";
					cout << "\n\t\t\t\t";
					system("pause>0");
					menu();
				}
			}
			if (i >= 8)
			{
				system("cls");
				Display_Board();
				cout << "\n\t\t\t\tOopss!! Game Drawn!!\n";
				system("pause>0");
				menu();
			}
			Player_Choice(p2);
			system("cls");
			Display_Board();
			i++;
			if (i > 4)
			{
				if (Check_Winner())
				{
					system("cls");
					Display_Board();
					cout << "\n\t\t\t\tCongrats!! You Won The Game!!\n";
					cout << "\n\t\t\t\t";
					system("pause>0");
					menu();
				}
			}
		}
		break;

	}
	default:
		cout << "Invalid Input..!!\n ";
		system("pause");
		Human_Vs_Computer();
		break;
	}
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
