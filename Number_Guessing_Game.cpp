#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(0)); 

    int targetNumber = rand() % 200 + 1; 
    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I've picked a number between 1 and 200. Try to guess it!" << endl;

    do {
        cout << "Your guess: ";
        if (!(cin >> guess)) { 
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; 
        }
        attempts++;

        if (guess < targetNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > targetNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number " << targetNumber << " correctly!" << endl;
            cout << "It took you " << attempts << " attempts." << endl;
        }
    } while (guess != targetNumber);

    return 0;
}
