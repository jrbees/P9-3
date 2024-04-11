// initilized git commit
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

int main() {
    const int size = 20;
    int values[size];
    generateSequence(values, size);

    cout << "Generated sequence:";
    for (int i = 0; i < size; ++i) {
        cout << " " << values[i];
    }
    cout << endl;

    cout << "Sequence with runs marked:";
    displayRun(values, size);

    return 0;
}
