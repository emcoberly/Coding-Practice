#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    // Introduction to activity
    cout << "In this activity, you will find the rule that gets you from your number to mine." << endl;
    cout << "Your answer must provide coefficients, constants, and exponents as necessary as they relate to variable 'x'." << endl;
    cout << "You will keep guessing until either you type 'quit' or you guess correctly." << endl;
    cout << "You will earn one point per correct guess, and your final score will be calculated when you quit." << endl;
    cout << "So, without further ado, please begin.\n" << endl;
    cout << "**********LEVEL ONE**********\n" << endl;
    int userScore = 0;  // User must have a score


    while(true) {                                       // Loop guesses until correct
        int userNum;                                    // Declare User number variable
        string userRule;                                // Declare User rule input
        cout << "Enter a number:\t\t";                  // Ask for number
        cin >> userNum;                                 // User assigns value to variable
        int myNum = 4 * userNum;                        // First 'y =' statement
        cout << "-> My number:\t\t" << myNum << endl;   // First 'y = x'
        cout << "\nWhat is the rule?\t";                // User asked to guess
        cin >> userRule;                                // User's guess
        if(userRule == "4x") {                                      // Determine if User's guess is correct
            cout << "Correct. Score increased by 1." << endl;       // Declare victory
            userScore += 1;                                         // More points, more happy
            cout << "Score: " << userScore << endl;                 // Give the mouse a cookie
            break;
        } else if(userRule == "quit") {                             // Determine if User wants to quit 
            cout << "\nWhat a chump. See you around...\n" << endl;  // Insults User for quitting. Because why not...
            break;
        } else {                                                    // Everything else is wrong
            cout << "Wrong. Please have another look.\n" << endl;   // Gives User a chance to see rule applied again
        }
    }

    cout << "\n**********LEVEL TWO**********\n" << endl;

    while(true) {                                       // Loop guesses until correct
        double userNum;                                 // Declare User number variable
        string userRule;                                // Declare User rule input
        cout << "Enter a number:\t\t";                  // Ask for number
        cin >> userNum;                                 // User assigns value to variable
        double myNum = (3 + userNum) / 2;               // Second 'y =' statement
        cout << "-> My number:\t\t" << myNum << endl;   // Second 'y = x'
        cout << "\nWhat is the rule?\t";                // User asked to guess
        cin >> userRule;                                // User's guess
        if(userRule == "(3+x)/2") {                                 // Determine if User's guess is correct
            cout << "Correct. Score increased by 2." << endl;       // Declare victory
            userScore += 2;                                         // More points, more happy
            cout << "Score: " << userScore << endl;
            break;
        } else if(userRule == "quit") {                             // Determine if User wants to quit 
            cout << "\nWhat a chump. See you around...\n" << endl;  // Insults User for quitting. Because why not...
            break;
        } else {                                                    // Everything else is wrong
            cout << "Wrong. Please have another look.\n" << endl;   // Gives User a chance to see rule applied again
        }
    }

    cout << "\n**********LEVEL THREE**********\n" << endl;

    while(true) {                                       // Loop guesses until correct
        double userNum;                                 // Declare User number variable
        string userRule;                                // Declare User rule input
        cout << "Enter a number:\t\t";                  // Ask for number
        cin >> userNum;                                 // User assigns value to variable
        double myNum = userNum * userNum - userNum;     // Third 'y =' statement
        cout << "-> My number:\t\t" << myNum << endl;   // Third 'y = x'
        cout << "\nWhat is the rule?\t";                // User asked to guess
        cin >> userRule;                                // User's guess
        if(userRule == "x^2-x") {                                   // Determine if User's guess is correct
            cout << "Correct. Score increased by 3." << endl;       // Declare victory
            userScore += 3;                                         // More points, more happy
            cout << "Final score: " << userScore << endl;
            break;
        } else if(userRule == "quit") {                             // Determine if User wants to quit 
            cout << "\nWhat a chump. See you around...\n" << endl;  // Insults User for quitting. Because why not...
            break;
        } else {                                                    // Everything else is wrong
            cout << "Wrong. Please have another look.\n" << endl;   // Gives User a chance to see rule applied again
        }
    }

    return 0;

}