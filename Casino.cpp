// Casino number guessing game
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    cout << "Welcome to Lootnewale Casino" << endl;
    sleep(3);
    cout << R"(
       *     *    *     *
   *     *   *     *   *     *
 *   🎲   *  *   🎰   *   *  💰   *
   *     *   *     *   *     *
       *     *    *     *

  /$$$$$$  /$$                                         /$$          
 /$$__  $$| $$                                        | $$          
| $$  \__/| $$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$| $$$$$$$       
| $$      | $$__  $$ |____  $$ /$$__  $$|  $$ | $$| $$__  $$      
| $$      | $$  \ $$  /$$$$$$$| $$  \ $$|  $$ | $$| $$  \ $$      
| $$    $$| $$  | $$ /$$__  $$| $$  | $$|  $$ | $$| $$  | $$      
|  $$$$$$/| $$$$$$$/|  $$$$$$$| $$$$$$$/|  $$$$$$/| $$$$$$$/      
 \______/ |_______/  \_______/ | $$____/  \______/ |_______/       
                                     | $$                           
                                     | $$                           
                                     |__/                           
    )" <<endl;
    sleep(5);
    cout << "We are going to play a game" << endl << "Guess the number" << endl;
    cout << "Here are the rules..." << endl;
    cout << "1. If you choose the correct number you will win $10000." << endl;
    sleep(1);
    cout << "2. $1000 will be charged to play a game." << endl;
    sleep(1);
    cout << "3. If you enter the wrong number, you will lose." << endl;
    sleep(1);
    cout << "4. Enter the number of turns you want to play." << endl;
    cout << "Let's begin then 3...." << endl;
    sleep(1);
    cout << "2...." << endl;
    sleep(1);
    cout << "1...." << endl;
    sleep(1);

    int turns;
    cout << "Enter the number of turns you want to play: ";
    cin >> turns;

    // Input validation
    if (turns <= 0) {
        cout << "Please enter a positive number of turns." << endl;
        return 1;
    }

    vector<int> computerchoice(turns);
    vector<int> playerchoice(turns);
    cout << "$" << turns * 1000 << " will be charged." << endl;
    sleep(3);
    cout << "Careful, number should be between 1-100." << endl;

    for (int i = 0; i < turns; i++) {
        cout << "Enter your option " << i + 1 << ": ";
        cin >> playerchoice[i];

        // Validate player choice
        if (playerchoice[i] < 1 || playerchoice[i] > 100) {
            cout << "Invalid choice. Please choose a number between 1 and 100." << endl;
            i--; // Repeat this turn
            continue;
        }
    }

    for (int i = 0; i < turns; i++) {
        computerchoice[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < turns; i++) {
        if (playerchoice[i] == computerchoice[i]) {
            cout << "Option " << i + 1 << " matches the correct option, you won!" << endl;
        } else {
            cout << "Your option " << i + 1 << " didn't match the correct option, sorry for your loss." << endl;
        }
        sleep(1);
    }

    for (int i = 0; i < turns; i++) {
        cout << "Player chose: " << playerchoice[i] << endl;
        cout << "Correct option " << i + 1 << ": " << computerchoice[i] << endl;
    }

    return 0;
}
