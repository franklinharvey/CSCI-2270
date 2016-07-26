/*Franklin Harvey
Class: Samantha Molnar
Assignment 3*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "CommunicationNetwork.h"

using namespace std;

void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Quit" << endl;
    cout << "6. Delete Network" << endl;
    return;
}

int main(int argc, char* argv[])
{
    // indicates the user is ready to leave the program
    bool quit = false;
    int input;
    CommunicationNetwork cn;

    // loop until the user quits
    while (quit != true)
    {
        displayMenu();
        cin >> input; // You can also use getline function to do this

        // used for user input
        string cityNew;
        string cityPrevious;
        string message;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input)
        {
            case 1:
                cn.buildNetwork();
                cn.printNetwork();
                break;
            case 2:
                cn.printNetwork();
                break;
            case 3:
                cn.transmitMsg("messageIn.txt");
                break;
            case 4:
                cout << "Enter a city name: " << endl;
                getline(cin,cityNew);
                cout << "Enter a previous city name: " << endl;
                getline(cin,cityPrevious);

                cn.addCity(cityPrevious, cityNew);
                break;

            case 5:
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            case 6: //not graded in this assignment

                cn.deleteEntireNetwork();
                cout << "Deleted network" << endl;
                break;
            // quit
            // invalid input
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }

    return 0;

}