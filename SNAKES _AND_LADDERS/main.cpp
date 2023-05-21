#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>


int curPlayerOnePos = 0;
int curPlayerTwoPos = 0;
int bordPos = 0;
int curDiceRoll = 0;
int playerTurnCounter = 1;
std::string fiveSpaces = "     ";
std::vector<int>gameBoard(100, 0);
std::vector<int>::iterator gbIter;

void setup();
void displayBoard();
void snakesNLaddders(int& curPlayerPos);
bool PlayerInput();
bool gameOver();
int diceRoll();
void updateGameInternals();
int count = 0;
int main() {
	setup();

	do
	{
		std::cout << "We have looped"<<++count<<"\n\n";
		std::cout << "Playersig is " << playerTurnCounter << "\n";
		displayBoard();
		updateGameInternals();
		system("pause");
		system("cls");
	} while (gameOver() != true);


	return EXIT_SUCCESS;
}

void setup()
{

	//initialise GameBaord;
	for (gbIter = gameBoard.begin(); gbIter != gameBoard.end(); gbIter++)
	{
		*gbIter = ++bordPos;
	}

	//initialise snakes 


	//initialise Ladders



	std::cout << "Player Instructions \n";
}

void displayBoard()
{

	std::cout << "Snakes_and_Ladders_Board\n";
	std::cout << fiveSpaces << " __________________________________________________________________\n";
	std::cout << fiveSpaces << "|  " << gameBoard[99] << "|  " << gameBoard[98] << "  |  " << gameBoard[97] << "  |  " << gameBoard[96] << " |  " << gameBoard[95] << "  |  " << gameBoard[94] << "  |  " << gameBoard[93] << "  |  " << gameBoard[92] << "  |  " << gameBoard[91] << "  |  " << gameBoard[90] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[80] << " |  " << gameBoard[81] << "  |  " << gameBoard[82] << "  |  " << gameBoard[83] << " |  " << gameBoard[84] << "  |  " << gameBoard[85] << "  |  " << gameBoard[86] << "  |  " << gameBoard[87] << "  |  " << gameBoard[88] << "  |  " << gameBoard[89] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[79] << " |  " << gameBoard[78] << "  |  " << gameBoard[77] << "  |  " << gameBoard[76] << " |  " << gameBoard[75] << "  |  " << gameBoard[74] << "  |  " << gameBoard[73] << "  |  " << gameBoard[72] << "  |  " << gameBoard[71] << "  |  " << gameBoard[70] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[60] << " |  " << gameBoard[61] << "  |  " << gameBoard[62] << "  |  " << gameBoard[63] << " |  " << gameBoard[64] << "  |  " << gameBoard[65] << "  |  " << gameBoard[66] << "  |  " << gameBoard[67] << "  |  " << gameBoard[68] << "  |  " << gameBoard[69] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[59] << " |  " << gameBoard[58] << "  |  " << gameBoard[57] << "  |  " << gameBoard[56] << " |  " << gameBoard[55] << "  |  " << gameBoard[54] << "  |  " << gameBoard[53] << "  |  " << gameBoard[52] << "  |  " << gameBoard[51] << "  |  " << gameBoard[50] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[40] << " |  " << gameBoard[41] << "  |  " << gameBoard[42] << "  |  " << gameBoard[43] << " |  " << gameBoard[44] << "  |  " << gameBoard[45] << "  |  " << gameBoard[46] << "  |  " << gameBoard[47] << "  |  " << gameBoard[48] << "  |  " << gameBoard[49] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[39] << " |  " << gameBoard[38] << "  |  " << gameBoard[37] << "  |  " << gameBoard[36] << " |  " << gameBoard[35] << "  |  " << gameBoard[34] << "  |  " << gameBoard[33] << "  |  " << gameBoard[32] << "  |  " << gameBoard[31] << "  |  " << gameBoard[30] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[20] << " |  " << gameBoard[21] << "  |  " << gameBoard[22] << "  |  " << gameBoard[23] << " |  " << gameBoard[24] << "  |  " << gameBoard[25] << "  |  " << gameBoard[26] << "  |  " << gameBoard[27] << "  |  " << gameBoard[28] << "  |  " << gameBoard[29] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[19] << " |  " << gameBoard[18] << "  |  " << gameBoard[17] << "  |  " << gameBoard[16] << " |  " << gameBoard[15] << "  |  " << gameBoard[14] << "  |  " << gameBoard[13] << "  |  " << gameBoard[12] << "  |  " << gameBoard[11] << "  |  " << gameBoard[10] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n";
	std::cout << fiveSpaces << "|  " << gameBoard[0] << "  |  " << gameBoard[1] << "   |  " << gameBoard[2] << "   |  " << gameBoard[3] << "  |  " << gameBoard[4] << "   |  " << gameBoard[5] << "   |  " << gameBoard[6] << "   |  " << gameBoard[07] << "   |  " << gameBoard[8] << "   |  " << gameBoard[9] << " |\n";
	std::cout << fiveSpaces << "|_____|______|______|_____|______|______|______|______|______|_____|\n\n\n";

	std::cout << "Player Ones current pos:" << curPlayerOnePos << "\n";
	std::cout << "Player Twos current pos" << curPlayerTwoPos << "\n\n";

	std::cout << "Ladders\n";
	std::cout << "-----------\n";
	std::cout << "From 2  TO 28\n";
	std::cout << "From 28 TO 88\n";
	std::cout << "From 34 TO 46\n";
	std::cout << "From 10 TO 50\n";
	std::cout << "From 47 TO 68\n\n\n";

	std::cout << "Snakes\n";
	std::cout << "-----------\n";
	std::cout << "From 26 TO 6\n";
	std::cout << "From 88 TO 77\n";
	std::cout << "From 98 TO 1 \n";
	std::cout << "From 94 TO 90\n";
	std::cout << "From 70 TO 51\n\n\n";

}

void snakesNLaddders(int& curPlayerPos)
{

	//check to see if player has stumbled upon a snake 
	switch (curPlayerPos)
	{
		//Snake 26 To 6
	case 26:
		std::cout << "You have landed on snakeHead 26 back to 6 you go :P\n";
		curPlayerPos = 6;
		break;

		//Snake 88 To 77
	case 88:
		std::cout << "You have landed on snakeHead 88 back to 77 you go :P\n";
		curPlayerPos = 77;
		break;


		//Snake 98 To 1
	case 98:
		std::cout << "You have landed on snakeHead 98 back to 1 Super unlucky you are :(\n";
		curPlayerPos = 1;
		break;

		//Snake 94 To 90
	case 94:
		std::cout << "You have landed on snakeHead 94 back to 90 you go :P\n";
		curPlayerPos = 90;
		break;

		//Snake 70 To 51
	case 70:
		std::cout << "You have landed on snakeHead 70 back to 51 you go :P\n";
		curPlayerPos = 51;
		break;

	default:
		break;
	}


	//check to see if player has stumbled upon a Ladder
	switch (curPlayerPos)
	{
		//Ladder 2 To 28
	case 2:
		std::cout << "you hit a ladder Wohray !!!! \n up to 28 you go :)!! \n";
		curPlayerPos = 28;
		break;

		//Ladder 28 To 88
	case 28:
		std::cout << "you hit a ladder Wohray !!!! \n up to 88 you go , Almost there :D!! \n";
		curPlayerPos = 88;
		break;


		//Ladder 34 To 46
	case 34:
		std::cout << "you hit a ladder Wohray !!!! \n up to 46 you go :)!! \n";
		curPlayerPos = 46;
		break;

		//Ladder 10 To 50
	case 10:
		std::cout << "you hit a ladder Wohray !!!! \n up to 50 you go the journey half done :)!! \n";
		curPlayerPos = 50;
		break;

		//Ladder 47 To 68
	case 47:
		std::cout << "you hit a ladder Wohray !!!! \n up to 68 you go :)!! \n";
		curPlayerPos = 68;
		break;

	default:
		break;
	}

}

bool PlayerInput()
{
	char playerInput;
	std::cout << "Pres R to roll the Dice \n";
	std::cin >> playerInput;
	std::cout << "\n";

	while (::toupper(playerInput) != 'R')
	{
		std::cin.ignore(1, ' ');
		std::cout << "Invalid Input Press R to roll the dice \n";
		std::cin >> playerInput;
		std::cout << "\n";
	}
	return true;
}

bool gameOver()
{
	if (curPlayerOnePos == 100 || curPlayerTwoPos == 100)
	{
		if (curPlayerOnePos > curPlayerTwoPos)
		{
			std::cout << "Game Over Welldone Player One \n";
		}

		else
		{
			std::cout << "Game Over Welldone Player Two \n";
		}

		system("pause");
		return true;
	}

}

int diceRoll()
{
	std::srand(static_cast<unsigned int>(time(0)));
	int dice = rand() % 6 + 1;
	return dice;
}

void updateGameInternals()
{
	int diceVal = 0;

	switch (playerTurnCounter)
	{
	case 1:
		if (PlayerInput() == true)
		{
			diceVal = diceRoll();
			std::cout << "Player One: has rolled a" << diceVal << "\n";
			curPlayerOnePos = curPlayerOnePos + diceVal;
			std::cout << "Player One: current pos is" << curPlayerOnePos << "\n\n";

			if (curPlayerOnePos > 100)
			{
				int excessMoves =    curPlayerOnePos - 100 ;
				curPlayerOnePos = 100;
				curPlayerOnePos = curPlayerOnePos - excessMoves;
				std::cout << "Player One: current pos is" << curPlayerOnePos << "\n\n";
			}
			snakesNLaddders(curPlayerOnePos);

			while (diceVal == 6)
			{   
				std::cout << "Nice One playerOne you rolled a Six time for a second roll !!! :D\n";
				PlayerInput();
				diceVal = rand() % 6 + 1;
				curPlayerOnePos = curPlayerOnePos + diceVal;

				if (curPlayerOnePos > 100)
				{
					int excessMoves = curPlayerOnePos - 100;
					curPlayerOnePos = 100;
					curPlayerOnePos = curPlayerOnePos - excessMoves;
					std::cout << "Player One: current pos is" << curPlayerOnePos << "\n\n";
				}

				std::cout << "Player One: has rolled a" << diceVal << "\n";
				std::cout << "Player One: current pos is" << curPlayerOnePos << "\n\n";
			}
			snakesNLaddders(curPlayerTwoPos);
		}

		
		diceVal = 0;
		break;

	case 2:
		if (PlayerInput() == true)
		{
			diceVal = diceRoll();
			std::cout << "Player Two: has rolled a" << diceVal << "\n";
			curPlayerTwoPos = curPlayerTwoPos + diceVal;

			if (curPlayerTwoPos > 100)
			{
				int excessMoves =  curPlayerTwoPos - 100 ;
				curPlayerTwoPos = 100;
				curPlayerTwoPos = curPlayerTwoPos - excessMoves;
				std::cout << "Player Two: current pos is" << curPlayerTwoPos << "\n\n";

			}
			snakesNLaddders(curPlayerTwoPos);

			while (diceVal == 6)
			{
				std::cout << "Nice One playerTwo you rolled a Six time for a second roll !!! :D\n";
				PlayerInput();
				diceVal = rand() % 6 + 1;
				curPlayerTwoPos = curPlayerTwoPos + diceVal;

				if (curPlayerTwoPos > 100)
				{
					int excessMoves = curPlayerTwoPos - 100;
					curPlayerTwoPos = 100;
					curPlayerTwoPos = curPlayerTwoPos - excessMoves;
					std::cout << "Player Two: current pos is" << curPlayerTwoPos << "\n\n";

				}

				std::cout << "Player Two: has rolled a" << diceVal << "\n";
				std::cout << "Player Two: current pos is" << curPlayerTwoPos << "\n\n";
			}
			snakesNLaddders(curPlayerTwoPos);
		}

		
		break;


	default:
		break;
	}

	/*This code switches turns by determing who just had the last turn if
	the value is 2 that means player 2 had last turn and true value 
	of the statemeant sets it to playerOnes turn */
	if (playerTurnCounter > 1)
	{
		playerTurnCounter = 1;
	}
	else
	{
		playerTurnCounter++;
	}

}
