#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

 // Load data from the input file
void GroceryTracker::loadDataFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open input file: " << filename << endl;
        return;
    }

    string item;
    while (inFile >> item) {
        itemFrequencies[item]++;
    }
    inFile.close();
}

// Create a backup frequency file
void GroceryTracker::createFrequencyFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to create output file: " << filename << endl;
        return;
    }

    for (const auto& entry : itemFrequencies) {
        outFile << entry.first << " " << entry.second << endl;
    }
    outFile.close();
}

// Get the frequency of a specific item
int GroceryTracker::getItemFrequency(const string& item) const {
    auto it = itemFrequencies.find(item);
    if (it != itemFrequencies.end()) {
        return it->second;
    }
    return 0;
}

// Display the frequency of all items
void GroceryTracker::displayAllFrequencies() const {
    for (const auto& entry : itemFrequencies) {
        cout << entry.first << " " << entry.second << endl;
    }
}

// Display a histogram of item frequencies
void GroceryTracker::displayHistogram() const {
    for (const auto& entry : itemFrequencies) {
        cout << entry.first << " ";
        for (int i = 0; i < entry.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}