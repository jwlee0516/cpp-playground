#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "login.h"
using namespace std;

void login::Login()
{
    string count;
    string userName, password, id, recordPass, recordSecurity;
    system("cls");
    cout << "\n\t\t\t Please enter the username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> username;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    string loginHash = password;
    hash<string> mystdhash;
    int loginHashPassword = mystdhash(loginHash);

    ifstream input("data.txt");

    while (input >> id >> recordPass >> recordSecurity)
    {
        if (id == userName && stoi(recordPass) == loginHashPassword)
        {
            count = "1";
            system("cls");
        }
    }
    input.close();
    if (count == "1")
    {
        cout << username << "\nLogin successful!\n";
        string choice = "1";
        while (choice != "2")
        {
            cout << "\t\t\t_____________________________________________\n\n\n";
            cout << "\t\t\t         Welcome to the NEMO 2023 Login!         \n\n";
            cout << "\t\t\t_______ Currently Logged In: " << username << " ________\n\n";
            cout << "\t\t\t_________           Menu           __________\n\n";
            cout << "\t | Press 1 to PLAY GAME                              |" << endl;
            cout << "\t | Press 2 to LOGOUT                                 |" << endl;
            cout << "\n\t\t\t Please Enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == "1")
            {
                system("cls");
                DrunkGame();
            }
            else if (choice == "2")
            {
                system("cls");
                cout << "Logging Out" << endl;
            }
        }
    }


}
