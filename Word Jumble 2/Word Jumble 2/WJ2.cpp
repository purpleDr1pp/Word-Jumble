#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "This is what surrounds you"},
		{"jumble","It's what the game is all about."},
		{"mirror", "This is where you see yourself"},
		{"carpet", "Its may be under you"},
		{"chair", "You can sit on this"}
	};
	srand(static_cast <unsigned int> (time(0)));
	string guess;
	cout << "\t\t\t\t\t Word Jumble!\n";
	cout << "\t\t\t  Unscramble the letters to make a word! \n";
	cout << " Enter 'hint' for a hint. \n";
	cout << " Enter 'quit' to quit the game. \n\n";
	int uPoints = 0; //общие очки игрока
	int cnt = -1; //счетчик запусков игры
	do
	{
		cnt++;
		int choice = rand() % NUM_WORDS;
		string theWord = WORDS[choice][WORD];
		string theHint = WORDS[choice][HINT];
		string jumble = theWord;
		int lenght = jumble.size();
		for (int i = 0; i < lenght; i++)
		{
			int index1 = rand() % lenght;
			int index2 = rand() % lenght;
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		int points = theWord.size();
		int rPoints = points; //очки игрока за раунд
		cout << " The jumble is: " << jumble;
		cout << "\n\n Your guess:";
		cin >> guess;
		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << " " << theHint << "\n What do you think now?: ";
				cin >> guess;
				rPoints = rPoints / 2;
			}
			else
			{
				cout << " No! Try again: ";
				cin >> guess;
				rPoints = rPoints - 1;
			}
		}
		if (guess == theWord)
		{
			uPoints += rPoints;
			cout << "\n Thats it! You guessed it!\n You earn " << rPoints << " points now and you have " << uPoints << " at all!\n";
		}
	} while (guess != "quit");
	if ((uPoints >= NUM_WORDS * cnt) && (uPoints != 0))
	{
		cout << " You have " << uPoints << ". Amazing!!!";
	}
	else if ((uPoints >= (NUM_WORDS * cnt) / 2) && (uPoints != 0))
	{
		cout << " You have " << uPoints << ". Its good result!";
	}
	else if (uPoints == 0)
	{
		cout << " You have " << uPoints << ". Ohh... anything happens. Don't be upset.";
	}
	else
	{
		cout << " You have " << uPoints << ". At least you didnt score 0.";
	}
	cout << "\n Thanks for your playing, bye!";
	return 0;

}