#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Function to convert a string to lowercase
string to_lowercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

// Function to count the words in a file and store them in a map
map<string, int> count_words(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    map<string, int> word_counts;
    string word;
    while (file >> word) {
        word = to_lowercase(word);
        word_counts[word]++;
    }

    file.close();

    return word_counts;
}

// Function to sort the words in descending order of frequency
vector<pair<string, int>> sort_words(map<string, int> word_counts) {
    vector<pair<string, int>> sorted_words;
    for (auto it = word_counts.begin(); it != word_counts.end(); it++) {
        sorted_words.push_back(make_pair(it->first, it->second));
    }

    sort(sorted_words.begin(), sorted_words.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    });

    return sorted_words;
}

// Function to print the top 10 most frequently occurring words
void print_top_10_words(vector<pair<string, int>> sorted_words) {
    cout << "Top 10 Most Frequently Occurring Words:" << endl;
    for (int i = 0; i < 10 && i < sorted_words.size(); i++) {
        cout << sorted_words[i].first << ": " << sorted_words[i].second << endl;
    }
}

int main() {
    // Get the input filename from the user
    string filename = "sample.txt";
    //cout << "Enter the filename: ";
    //cin >> filename;

    // Count the words in the file
    map<string, int> word_counts = count_words(filename);

    // Sort the words in descending order of frequency
    vector<pair<string, int>> sorted_words = sort_words(word_counts);

    // Print the top 10 most frequently occurring words
    print_top_10_words(sorted_words);

    return 0;
}