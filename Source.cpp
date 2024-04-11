#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateSequence(int values[], int size) {
    // Generate 20 random six-sided die tosses
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        values[i] = rand() % 6 + 1; // Generate random number between 1 and 6
    }
}

void displayRun(int values[], int size) {
    bool inRun = false;
    for (int i = 0; i < size; ++i) {
        // Check if the current value is the same as the previous one
        if (i > 0 && values[i] == values[i - 1]) {
            if (!inRun) {
                cout << "(" << values[i - 1]; // Start of run
                inRun = true;
            }
            cout << " " << values[i]; // Add value to run
        }
        else {
            if (inRun) {
                cout << ")"; // End of run
                inRun = false;
            }
            cout << " " << values[i]; // Print value
        }
    }
    if (inRun) {
        cout << ")"; // End of run for the last run
    }
    cout << endl;
}

bool hasRun(int values[], int size) {
    for (int i = 1; i < size; ++i) {
        // Check if the current value is the same as the previous one
        if (values[i] == values[i - 1]) {
            return true; // Found a run
        }
    }
    return false; // No run found
}

int main() {
    const int size = 20;
    int values[size];

    bool foundRun = false;
    while (!foundRun) {
        generateSequence(values, size);
        foundRun = hasRun(values, size);
    }

    cout << "Sequence with a run:";
    displayRun(values, size);

    return 0;
}
