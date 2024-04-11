#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayRun(int values[], int size) {
    int i;
    int inRun = 0; // Flag to indicate if we're currently in a run

    for (i = 0; i < size; i++) {
        // Check if the current value is the same as the next value
        if (i < size - 1 && values[i] == values[i + 1]) {
            // If not already in a run, start the run
            if (!inRun) {
                inRun = 1;
                cout << "(" << values[i] << " ";
            }
            // If already in a run, just print the value without space
            else {
                cout << values[i] << " ";
            }
        }
        // If not in a run and the current value is different from the next one
        else if (!inRun) {
            cout << values[i] << " ";
        }
        // If we're in a run and the current value is different from the next one
        else {
            inRun = 0;
            cout << values[i] << ") ";
        }
    }
}

bool hasRun(int values[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (values[i] == values[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int i;
    int dieValues[20];

    // Seed the random number generator
    srand(time(NULL));

    // Generate 20 random six-sided die tosses
    for (i = 0; i < 20; i++) {
        dieValues[i] = rand() % 6 + 1;
    }

    // Print the die values
    cout << "Die Values: ";
    for (i = 0; i < 20; i++) {
        cout << dieValues[i] << " ";
    }
    cout << endl;

    // Print the die values with runs
    cout << "With Runs: ";
    displayRun(dieValues, 20);
    cout << endl;

    return 0;
}
