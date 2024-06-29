#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>
using namespace std;

class GroceryTracker {
public:
    // Load data from the input file
    void loadDataFromFile(const string& filename);

    // Create a backup frequency file
    void createFrequencyFile(const string& filename) const;

    // Get the frequency of a specific item
    int getItemFrequency(const string& item) const;

    // Display the frequency of all items
    void displayAllFrequencies() const;

    // Display a histogram of item frequencies
    void displayHistogram() const;

private:
    // Map to store item names and their frequencies
    map<string, int> itemFrequencies;
};

#endif // GROCERYTRACKER_H
