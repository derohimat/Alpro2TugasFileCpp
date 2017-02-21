#include <iostream>
#include <iomanip>
#include "Utils.h"

void choiceMenu();

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    choiceMenu();
    return 0;
}

//Menu Function
void showMenu() {
    cout << "Please choose a menu" << endl << endl
         << "1. Menu First" << endl
         << "2. Menu Second" << endl
         << "3. Quit" << endl << endl;
}

void choiceMenu() {

    Utils utils;
    int choice;     //menu choice

    //constants for menu choices
    const int FIRST_CHOICE = 1,
            SECOND_CHOICE = 2,
            QUIT_CHOICE = 3;

    cout << fixed << showpoint << setprecision(1); //sets to 1 decimal place

    do {
        showMenu();

        choice = utils.inputInt("Please Select Menu : ");

        //Validate menu selection
        while (choice < FIRST_CHOICE || choice > QUIT_CHOICE) {
            choice = utils.inputInt("Please enter a valid menu choice");
        }

        //If user does not want to quit, proceed.
        if (choice != QUIT_CHOICE) {
            switch (choice) {
                case FIRST_CHOICE:
                    utils.print("Menu 1");
                    break;
                case SECOND_CHOICE:
                    utils.print("Menu 2");
                    break;
                default:
                    utils.print("Menu 1");
                    break;
            }
        }
    } while (choice != QUIT_CHOICE);
}