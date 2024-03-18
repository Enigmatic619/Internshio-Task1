#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool guess_number(int a, int random_number) {
    if (a == random_number) {
        cout << "Congratulations!! You have guessed the correct number!" << endl;
        return true;
    }
    else {
        cout << "Sorry, you have not made the right guess." << endl;
        return false;
    }
}

void tryagain(int x, int random_number) {
    cout << "Do you want to try again? Press Y for yes and N for no " << endl;
    char choice;
    cin >> choice;

    if (choice == 'N' || choice == 'n') {
        cout << "Thanks for playing!" << endl;
    }
    else if (choice == 'Y' || choice == 'y') {
        int difference = random_number - x;

        if (abs(difference) > 200) {
            cout << "You are more than 200 numbers away from the actual number. Here are two numbers 100 away: ";
            cout << random_number + 100 << " and " << random_number - 100 << endl;
        }
        else if (abs(difference) >= 100) {
            cout << "You are more than a century away from the actual number." << endl;
        }
        else if (abs(difference) >= 50) {
            cout << "You are getting there, but still quite far from the actual number." << endl;
        }
        else if (abs(difference) >= 40) {
            cout << "You are close to a century away from the actual number." << endl;
        }
        else if (abs(difference) >= 30) {
            cout << "You are close, but still some way off from the actual number." << endl;
        }
        else if (abs(difference) >= 20) {
            cout << "You are getting close!" << endl;
        }
        else if (abs(difference) >= 10) {
            cout << "You are very close now!" << endl;
        }
        else if (abs(difference) >= 5) {
            cout << "You are extremely close!" << endl;
        }
        else {
            cout << "You are practically on top of the actual number!" << endl;
        }

        cout << "Enter your guess!" << endl;
        int g;
        cin >> g;
        bool b = guess_number(g, random_number);
        if (!b) {
            tryagain(g, random_number);
        }
    }
}

int main() {
    srand(time(NULL));
    int random_number;
    char play_again = 'Y';
    cout << "                       WELCOME TO THE NUMBER GUESSING GAME!!!!" << endl;
    while (play_again == 'Y' || play_again == 'y') {
        random_number = rand();
      

        cout << "Enter the number you want to guess with:";
        int x;
        cin >> x;

        bool b = guess_number(x, random_number);

        if (!b) {
            tryagain(x, random_number);
        }

        cout << "Do you want to play again? Press Y for yes and N for no " << endl;
        cin >> play_again;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
