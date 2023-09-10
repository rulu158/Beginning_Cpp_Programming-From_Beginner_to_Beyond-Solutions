// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void get_words(std::ifstream &file, std::vector<std::string> &dictionary);
int find_word_in_words(const std::string &word, const std::vector<std::string> &dictionary);

int main() {
    std::ifstream input_file;
    input_file.open("romeoandjuliet.txt");
    if (!input_file) {
        std::cerr << "Error opening file.";
        return 1;
    }

    std::vector<std::string> words;
    get_words(input_file, words);
    input_file.close();

    while (true) {
        std::string word;
        std::cout << "Enter the substring to search or CTRL+C to exit: ";
        std::cin >> word;
        std::cout << words.size() << " words are being searched..." << std::endl;
        int nwords {find_word_in_words(word, words)};
        std::cout << "The substring " << word << " was found " << nwords << " times." << std::endl;
    }
    
    cout << endl;
    return 0;
}

void get_words(std::ifstream &file, std::vector<std::string> &dictionary) {
    while (!file.eof()) {
        std::string word;
        file >> word;
        dictionary.push_back(word);
    }
}

int find_word_in_words(const std::string &word, const std::vector<std::string> &dictionary){
    int counter {0};
    for (const auto &w : dictionary) {
        if (w.find(word) != std::string::npos) {
            counter++;
        }
    }
    return counter;
}