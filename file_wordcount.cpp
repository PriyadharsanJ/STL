#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main()
{
    // Check if the file exists and can be opened
    ifstream inputFile("stl_sample.txt");
    if (!inputFile.is_open())
    {
        cout << "Unable to Open File!" << endl;
        return 1; // Exit the program with an error code
    }

    // Use a map to store word occurrences as key-value pairs
    map<string, int> wordCounts;

    string line;
    while (getline(inputFile, line))
    {
        stringstream lineStream(line);
        string word;
        while (lineStream >> word)
        {
            // Convert the words into lowercase
            for (char &c : word)
            {
                c = tolower(c);
            }
            ++wordCounts[word]; // Increment the word counter
        }
    }

    inputFile.close();

    // Display word counts
    cout << "Word Counts:" << endl;
    for (auto &pair : wordCounts)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
