#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class skynetGame
{
public:
	skynetGame()
	{
		srand(static_cast<unsigned int>(time(0)));
		int generatedNumber = rand() % 64 + 1;
		int attempt = 0;
		int guess;
		int lowNumber = 1;
		int highNumber = 64;

		do {
			cout << "Time to find the enemy, guess a square between: " << lowNumber << " and " << highNumber << endl;
			cout << "Type 0 to take a guess at a random square " << endl;
			cin >> guess;
			cout << endl;
			if (guess == 0) {
				guess = ((highNumber - lowNumber) / 2 + lowNumber);
			}
			if (guess >= 1 && guess <= 64) {
				if (guess < generatedNumber) {
					cout << "Too Low!\n\n";
					lowNumber = guess + 1;
					cout << "Your new low coordinate is \n" << lowNumber << endl;
					attempt = attempt + 1;
				}
				else if (guess > generatedNumber) {
					cout << "Too High!\n\n";
					highNumber = guess - 1;
					cout << "Your new high coordinate is \n" << highNumber << endl;
					attempt = attempt + 1;
				}
				else {
					cout << "Your target was located in " << attempt << " attempts, good job!" << endl;
				}
			}
			else {
				cout << "Please guess a number between 1-64" << endl;
			}
		} while (guess != generatedNumber);
	}
};

class aiPlayer
{
public:
	aiPlayer()
	{
		srand(static_cast<unsigned int>(time(0)));
		int generatedNumber = rand() % 64 + 1;
		int attempt = 0;
		int guess;
		
		for(int i=1; i<=64; ++i)
		{
			if(i != generatedNumber)
			{
				attempt = attempt + 1;
			}
			else
			{
				cout << "The ai guessed: " << generatedNumber << " in " << attempt << " attempts.";
			}
		}
	}
};

int main(){
	bool requestPlay = false;
	int acceptStart;

	do
	{
		cout << "Would you like to play the game?" << endl << endl;
		cout << "Press 1 for Yes, 2 for No, 3 to let the AI play" << endl << endl;
		cin >> acceptStart;
		if (acceptStart == 1)
		{
			skynetGame();
			requestPlay = true;
			system("pause");
			cout << endl;
		}
		if (acceptStart == 2)
		{
			!requestPlay;
			return 0;
		}
		else if (acceptStart == 3)
		{
			aiPlayer();
			requestPlay = true;
			system("pause");
			cout << endl;
		}
	} while (requestPlay);
}
