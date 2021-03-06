// Daily_Summer_Mod2_HW.cpp : Defines the entry point for the console application.
// Author: Summer Daily
// Date last updated: 8/31/2018
// Purpose: Play Frisbee Golf

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class golferType
{
public:
	golferType();
	golferType(string, string, int, int);
	void getName();
	void getID();
	void getNumOfTosses();
	void getNumOfGames();
	void getAvgTosses();
	void changeName(string);
	void changeID(string);
	void newScore(int);
private:
	string name;
	string ID;
	int numOfTosses;
	int numOfGames;
	int average;
};

golferType player[5];

int main()
{
	char newPlayer = 'y';
	char endLine;
	int i = 0;
	while (newPlayer == 'y' || newPlayer == 'Y')
	{
		string name;
		string username;
		int tosses;
		int games;
		cout << "Enter Player " << i + 1 << "'s first and last name: ";
		getline(cin, name);
		username = name[0];
		char nextChar = name[1];
		int n = 0;
		for (n; nextChar != ' '; n++)
			nextChar = name[n];
		for (n; nextChar != name.back(); n++)
		{
			username = username + nextChar;
			nextChar = name[n];
		}
		username = username + name.back();
		cout << "Enter total number of tosses for all games: ";
		cin >> tosses;
		while (tosses <= 0)
		{
			cout << "Score must be 1 or higher. Try again: ";
			cin >> tosses;
		}
		cout << "Enter number of games you have played: ";
		cin >> games;
		while (games <= 0)
		{
			cout << "Number of games must be 1 or higher. Try again: ";
			cin >> games;
		}
		player[i] = golferType(name, username, tosses, games);
		cout << "Would you like to add another player? Enter 'y' or 'n': ";
		cin >> newPlayer;
		cin.get(endLine);
		i++;
		if (i == 5)
		{
			cout << "I'm sorry. You've entered the maximum of five players." << endl;
			newPlayer = 'n';
		}
	}
	i -= 1;
	char newGame = 'y';
	while (newGame == 'y' || newGame == 'Y')
	{
		cout << "Congrats on another game!" << endl;
		for (int x = 0; x <= i; x++)
		{
			player[x].newScore(x);
		}
		cout << "Play another game? Enter 'y' or 'n': ";
		cin >> newGame;
	}
	cout << "Thanks for playing!" << endl << endl;
	cout << "Final Scores" << endl;
	for (int x = 0; x <= i; x++)
	{
		player[x].getName();
		player[x].getID();
		player[x].getAvgTosses();
		cout << endl;
	}
	
	system("pause");
    return 0;
}

golferType::golferType()
{
	name = " ";
	ID = " ";
	numOfTosses = 0;
	numOfGames = 0;
};
golferType::golferType(string playerName, string username, int tosses, int games)
{
	name = playerName;
	ID = username;
	numOfTosses = tosses;
	numOfGames = games;
};
void golferType::getName()
{
	cout << "Name: " << name << endl;
};
void golferType::getID()
{
	cout << "ID: " << ID << endl;
};
void golferType::getNumOfTosses()
{
	cout << "Total Tosses: " << numOfTosses << endl;
};
void golferType::getNumOfGames()
{
	cout << "Total Games: " << numOfGames << endl;
};
void golferType::getAvgTosses()
{
	cout << "Average Tosses: " << numOfTosses / numOfGames << endl;
};
void golferType::changeName(string newName)
{
	name = newName;
};
void golferType::changeID(string newID)
{
	ID = newID;
};
void golferType::newScore(int playerNumber)
{
	int x = playerNumber;
	int newScore;
	cout << "Enter score for " << player[x].ID << ": ";
	cin >> newScore;
	while (newScore < 1)
	{
		cout << "Score must be 1 or higher. Try again: ";
		cin >> newScore;
	}
	player[x].numOfTosses = player[x].numOfTosses + newScore;
	player[x].numOfGames += 1;
};
