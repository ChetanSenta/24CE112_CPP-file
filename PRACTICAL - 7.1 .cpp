#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

struct WordEntry {
    char* word;
    int count;
};

void toLowerCase(string& str) {
    for (char& ch : str) {
        ch = tolower(ch);
    }
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; ++i) {
        str[i] = tolower(str[i]);
    }
}

void cleanWord(string& word) {
    word.erase(remove_if(word.begin(), word.end(), [](unsigned char ch) { return ispunct(ch); }), word.end());
}

bool compareWords(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

void addWord(WordEntry*& words, int& size, const char* newWord) {
    for (int i = 0; i < size; ++i) {
        if (compareWords(words[i].word, newWord)) {
            words[i].count++;
            return;
        }
    }

    WordEntry* temp = new WordEntry[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = words[i];
    }

    temp[size].word = new char[strlen(newWord) + 1];
    strcpy(temp[size].word, newWord);
    temp[size].count = 1;

    delete[] words;
    words = temp;
    size++;
}

void freeMemory(WordEntry* words, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] words[i].word;
    }
    delete[] words;
}

// STL-Based Word Frequency Counter
void wordFrequencySTL() {
    cout << "Enter a paragraph :\n";
    string paragraph;
    getline(cin, paragraph);

    toLowerCase(paragraph);
    
    unordered_map<string, int> wordCount;
    stringstream ss(paragraph);
    string word;

    while (ss >> word) {
        cleanWord(word);
        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    cout << "\nWord Frequencies (STL Approach) :\n";
    for (const auto& entry : wordCount) {
        cout << entry.first << ": " << entry.second << "\n";
    }
}

// Non-STL-Based Word Frequency Counter
void wordFrequencyNonSTL() {
    cout << "Enter a paragraph :\n";
    char paragraph[1000];
    cin.getline(paragraph, 1000);

    toLowerCase(paragraph);

    WordEntry* words = nullptr;
    int wordCount = 0;

    char* token = strtok(paragraph, " ,.?!;");
    while (token != nullptr) {
        addWord(words, wordCount, token);
        token = strtok(nullptr, " ,.?!;");
    }

    cout << "\nWord Frequencies (Non-STL Approach) :\n";
    for (int i = 0; i < wordCount; ++i) {
        cout << words[i].word << " : " << words[i].count << "\n";
    }

    freeMemory(words, wordCount);
}

int main() {
    int choice;
    cout << "Choose an approach :\n";
    cout << "1. Using STL \n";
    cout << "2. Using Non-STL \n";
    cout << "Enter your choice : ";
    cin >> choice;
    cin.ignore(); // To consume newline

    switch (choice) {
        case 1:
            wordFrequencySTL();
            break;
        case 2:
            wordFrequencyNonSTL();
            break;
        default:
            cout << "Invalid choice!\n";
    }

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
