#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<string> wordList;

void clearScreen() {
    system("cls");
}

void loadWordList(const char* fileName) {
    ifstream file(fileName);

    if (!file) {
        cerr << "Error: Unable to open the word list file." << endl;
        exit(1);
    }

    string word;
    while (file >> word) {
        wordList.push_back(word);
    }

    file.close();
}

pair<string, string> selectRandomWords() {
    int index1 = rand() % wordList.size();
    int index2 = rand() % wordList.size();

    while (index2 == index1) {
        index2 = rand() % wordList.size();
    }

    string word1 = wordList[index1];
    string word2 = wordList[index2];

    return make_pair(word1, word2);
}

int main() {
    srand(time(0));

    loadWordList("data.txt");

    int score = 0;
    int questionNumber = 1;

    while (true) {
        clearScreen();

        pair<string, string> randomWords = selectRandomWords();
        string word1 = randomWords.first;
        string word2 = randomWords.second;

        cout << "Score: " << score << endl << endl;

        cout << "Question " << questionNumber << endl;
        cout << "Word 1: " << word1 << endl;
        cout << "Word 2: " << word2 << endl << endl;

        string choice;
        cout << "Select the word that comes first alphabetically\n(1 or 2), Enter 0 to exit:  ";
        cin >> choice;

        if (choice == "0") {
            break;
        } else if (choice == "1" && word1 < word2) {
            score++;
        } else if (choice == "2" && word2 < word1) {
            score++;
        }

        questionNumber++;
    }

    cout << "Game Over! Score: " << score << endl;

    return 0;
}

