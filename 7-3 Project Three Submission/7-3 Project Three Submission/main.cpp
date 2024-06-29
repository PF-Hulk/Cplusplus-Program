// Christopher Davidson
// 6/22/24
// CS-210 Project 3 

#include <iostream>
#include "GroceryTracker.h"
using namespace std;

// Display the main menu and return the user's choice
int displayMenu() {
    int choice;
    cout << "\nWelcome to the Corner Grocer Item Tracker!\n";
    cout << "Please select an option from the menu below:\n";
    cout << "\nGrocery Tracker Menu:\n";
    cout << "1. Display the frequency of a specific item\n";
    cout << "2. Display the frequency of all items\n";
    cout << "3. Display a histogram of item frequencies\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Check for input failure
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        choice = -1; // Set choice to an invalid number
    }

    return choice;
}

// Ask the user whether to try again or go back to the main menu
bool tryAgainPrompt() {
    int choice;
    cout << "Would you like to try again (1) or go back to the main menu (2)? Enter your choice: ";
    cin >> choice;

    // Check for input failure
    if (cin.fail() || (choice != 1 && choice != 2)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid choice. Please try again." << endl;
        return tryAgainPrompt();
    }

    return (choice == 1);
}

// Function to handle displaying the frequency of a specific item
void handleDisplayItemFrequency(GroceryTracker& tracker) {
    do {
        string item;
        cout << "Please enter the name of the item you wish to search for: ";
        cin >> item;
        int frequency = tracker.getItemFrequency(item);
        if (frequency > 0) {
            cout << item << " appears " << frequency << " times." << endl;
        }
        else {
            cout << "Item not found." << endl;
        }
    } while (tryAgainPrompt());
}

// Function to handle displaying the frequency of all items
void handleDisplayAllFrequencies(GroceryTracker& tracker) {
    do {
        tracker.displayAllFrequencies();
    } while (tryAgainPrompt());
}

// Function to handle displaying the histogram of item frequencies
void handleDisplayHistogram(GroceryTracker& tracker) {
    do {
        tracker.displayHistogram();
    } while (tryAgainPrompt());
}

// Ask the user for confirmation before exiting
bool confirmExit() {
    char choice;
    cout << "Are you sure you want to exit? (y/n): ";
    cin >> choice;

    // Check for input failure
    if (cin.fail() || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid choice. Please try again." << endl;
        return confirmExit();
    }

    return (choice == 'y' || choice == 'Y');
}

int main() {
    GroceryTracker tracker;
    string inputFileName = "CS210_Project_Three_Input_File.txt";
    string outputFileName = "frequency.dat";

    // Load data from the input file
    tracker.loadDataFromFile(inputFileName);

    // Create the frequency data file for backup
    tracker.createFrequencyFile(outputFileName);

    int choice;
    do {
        choice = displayMenu();
        switch (choice) {
        case 1:
            handleDisplayItemFrequency(tracker);
            break;
        case 2:
            handleDisplayAllFrequencies(tracker);
            break;
        case 3:
            handleDisplayHistogram(tracker);
            break;
        case 4:
            if (confirmExit()) {
                cout << "Exiting the program. Thank you for using the Corner Grocer Item Tracker!\n";
                choice = 4; // Set choice to 4 to exit the loop
            }
            else {
                choice = 0; // Set choice to 0 to go back to the main menu
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}

