#include <iostream>
#include <time.h>
using namespace std;

#define MAX 52

int main()
{
	int Cards[MAX] = { 0, };

	srand((unsigned int)time(0));

	for (int i = 0; i < MAX; i++)
	{
		Cards[i] = i + 1;
	}

	for (int i = 0; i < MAX * 2; i++)
	{
		int FirstNumber = rand() % MAX;
		int SecondNumber = rand() % MAX;

		int temp = Cards[FirstNumber];
		Cards[FirstNumber] = Cards[SecondNumber];
		Cards[SecondNumber] = temp;
	}

	string sign;
	string number;

	int Player[3] = {};
	int AI[3] = {};

	for (int i = 0; i < MAX; ++i)
	{
		switch (Cards[i] / 13)
		{
		case 0:
			sign = "¢¾";
			switch (Cards[i] % 13)
			{
			case 0:
				number = "A";
				break;
			case 10:
				number = "J";
				break;
			case 11:
				number = "Q";
				break;
			case 12:
				number = "K";
				break;
			default:
				number = (Cards[i] % 13);
				break;
			}
			break;
		case 1:
			sign = "¢¼";
			switch (Cards[i] % 13)
			{
			case 0:
				number = "A";
				break;
			case 10:
				number = "J";
				break;
			case 11:
				number = "Q";
				break;
			case 12:
				number = "K";
				break;
			default:
				number = (Cards[i] % 13);
				break;
			}
			break;
		case 2:
			sign = "¢À";
			switch (Cards[i] % 13)
			{
			case 0:
				number = "A";
				break;
			case 10:
				number = "J";
				break;
			case 11:
				number = "Q";
				break;
			case 12:
				number = "K";
				break;
			default:
				number = (Cards[i] % 13);
				break;
			}
			break;
		case 3:
			sign = "¢Â";
			switch (Cards[i] % 13)
			{
			case 0:
				number = "A";
				break;
			case 10:
				number = "J";
				break;
			case 11:
				number = "Q";
				break;
			case 12:
				number = "K";
				break;
			default:
				number = (Cards[i] % 13);
				break;
			}
			break;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		Player[i] = Cards[rand() % MAX];
		AI[i] = Cards[rand() % MAX];
	}

	int PlayerSum = 0;
	int AISum = 0;

	for (int i = 0; i < 3; i++)
	{
		PlayerSum += Player[i];
		AISum += AI[i];
	}

	if (PlayerSum > 21 && AISum > 21)
	{
		cout << "Player Win: both players passed sum of 21" << endl;
		cout << "Player: " << PlayerSum << endl;
		cout << "AI: " << AISum << endl;
		cout << Player[0] << " " << Player[1] << " " << Player[2] << endl;
		cout << AI[0] << " " << AI[1] << " " << AI[2] << endl;
		return -1;
	}
	else if (PlayerSum > 21)
	{
		cout << "Player Lost: greater than 21" << endl;
		cout << "Player: " << PlayerSum << endl;
		cout << "Player's numbers: " << Player[0] << " " << Player[1] << " " << Player[2] << endl;
		cout << "AI's numbers: " << AI[0] << " " << AI[1] << " " << AI[2] << endl;
		return -1;
	}
	else if (AISum > 21)
	{
		cout << "AI Lost: greater than 21" << endl;
		cout << "AI: " << AISum << endl;
		cout << "Player's numbers: " << Player[0] << " " << Player[1] << " " << Player[2] << endl;
		cout << "AI's numbers: " << AI[0] << " " << AI[1] << " " << AI[2] << endl;
		return -1;
	}
	
	else if (PlayerSum == AISum)
	{
		cout << "Player Win: Got same number of - Player: " << PlayerSum << " & AI - " << AISum << endl;
		cout << "Player's numbers: " << Player[0] << " " << Player[1] << " " << Player[2] << endl;
		cout << "AI's numbers: " << AI[0] << " " << AI[1] << " " << AI[2] << endl;
	}
	else if (PlayerSum > AISum)
	{
		cout << "Winner: Player  - " << PlayerSum << endl;
		cout << "AI: " << AISum << endl;
		cout << "Player's numbers: " << Player[0] << " " << Player[1] << " " << Player[2] << endl;
		cout << "AI's numbers: " << AI[0] << " " << AI[1] << " " << AI[2] << endl;
	}
	else
	{
		cout << "Winner: AI  - " << AISum << endl;
		cout << "Player: " << PlayerSum << endl;
		cout << "Player's numbers: " << Player[0] << " " << Player[1] << " " << Player[2] << endl;
		cout << "AI's numbers: " << AI[0] << " " << AI[1] << " " << AI[2] << endl;
	}

	return 0;
}