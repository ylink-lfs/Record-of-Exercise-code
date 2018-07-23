#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;
using std::vector;
const int NUM = 26;

vector<string> wordlist;

void read_src_word(vector<string>& wlist, const char* filename);

int main(void)
{
	using std::cin;
	using std::cout;
	using std::tolower;
	using std::endl;

	read_src_word(wordlist, "datasrc.txt");

	std::srand(std::time(0));
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % NUM];
		int length = target.size();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my sercet word. It has " << length << " letters, and you gusss\n";
		cout << "one letter at a time. You get " << guesses << " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "you already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.size() > 0)
				{
					cout << "Bad choices: " << badchars << endl;
				}
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
		{
			cout << "Sorry the word is " << target << ".\n";
			cout << "Will you play another? <y/n>";
			cin >> play;
			play = tolower(play);
		}
	}
	cout << "Bye\n";
	system("pause");
	return 0;
}

void read_src_word(vector<string>& wlist, const char* filename)
{
	using std::ifstream;
	ifstream ist(filename, std::ios_base::in);
	string tmp;
	while (ist >> tmp)
	{
		wlist.push_back(tmp);
	}
	ist.close();
}