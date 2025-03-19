/*
* Programmer: PANGAN, NELA RYNE C.
* Date Submitted: 07/23/2023
* Program: BSIT-O
* Course / Section: FOPIO1
*/

#include <iostream>
#include <cstdlib>
#include <string>

// Avoided using namespace std to avoid std naming collisions
using std::cout;
using std::cin;
using std::string;
using std::endl;

// Declare menu and choice related functions
void clear_screen(void);
void display_menu(void);
void choice_menu(void);
void ask_to_reset(void);
int check_input_valid(void (*currentProgram)(void));

// Declare program related functions
void prime_number(void);
void right_triangle(void);

int main()
{
    clear_screen();
    display_menu();
    return 0;
}

void clear_screen(void)
{
    #ifdef WINDOWS
        std::system("cls");
    #else
        // Assume POSIX
        std::system ("clear");
    #endif
}

void display_menu(void)
{
    cout << "**************MENU**************" << endl;
    cout << "[1] PRIME NUMBER" << endl;
    cout << "[2] RIGHT TRIANGLE" << endl;
    cout << "[3] EXIT" << endl;
    cout << "********************************" << endl;   
    choice_menu(); 
}

void choice_menu(void)
{
    int choice;

    cout << "ENTER YOUR CHOICE: ";

    // Checks if not an integer
    if (!(cin >> choice) || cin.peek() != '\n')
    {
        clear_screen();
        cout << "Invalid choice. Choose 1-3 only." << endl;
        cin.clear();
        while (cin.get() != '\n')
            continue;
        display_menu();
    }
    // continues to switch statement if an integer
    else
    {
        switch (choice)
        {
        case 1: 
            clear_screen();
            prime_number();
            break;
        case 2: 
            clear_screen();
            right_triangle();
            break;
        case 3: 
            clear_screen();
            cout << "Exiting Program";
            exit(0);
        default:
            clear_screen();
            cout << "Invalid choice. Choose 1-3 only." << endl;
            display_menu();
        }
    }
}

void ask_to_reset(void)
{
    char choice;
    cout << "Return to Main Menu? [Y/N]: ";

    if (!(cin >> choice) || cin.peek() != '\n') // !(cin >> choice) evaluates true if cin fails, cin.peek checks if there is a 2nd character in input stream
    {
        cout << "Invalid input. Try again." << endl;
        ask_to_reset();
    }
    else
    {
        switch(choice)
        {
        case 'Y':
        case 'y':
            clear_screen();
            display_menu();
            break;
        case 'N':
        case 'n':
            clear_screen();
            cout << "Exiting Program";
            exit(0);
            break;
        default:
            clear_screen();
            cout << "Invalid choice. Try again." << endl << endl;
            ask_to_reset();
            break;
        }
    }
}

void prime_number(void)
{  
    cout << "**************************************" << endl << endl;
    cout << "             PRIME NUMBER             " << endl << endl;
    cout << "**************************************" << endl << endl;

    cout << "Enter a NUMBER to determine if it's PRIME: ";
    int number = check_input_valid(prime_number);
    int i;


// PROCESS
    if(number == 1 || number < 1)   // 1 is not a Prime Number
    {
        cout << number << " is not a Prime Number" << endl << endl;
        ask_to_reset();
    }         
    else if(number > 1)     // checks all other numbers
    {
        for(i = 2; i <= number; i++)
        {
            if(number % i == 0 && number != i)  // no remainder means i is a factor of the number, and number is not prime
            {
                cout << number << " is not a Prime Number" << endl << endl;
                ask_to_reset();
                break;
            }
            else if(number % i != 0)    // continue checking if i is not a factor of the number
                continue;
            else if(number == i)        // when the last i is reached, and none were factors, the number is a prime number
                cout << number << " is a Prime Number" << endl << endl; 
                ask_to_reset();
        }  
    }
}

void right_triangle(void)
{
    cout << "**************************************" << endl << endl;
    cout << "            RIGHT TRIANGLE            " << endl << endl;
    cout << "**************************************" << endl << endl;

    cout << "Enter the SIZE of the TRIANGLE: ";
    int triangle_size = check_input_valid(right_triangle);
    

// PROCESS
    for (int i = 1; i <= triangle_size; i++) 
    {
        for (int j = 1; j <= i; j++) // will only print with range in i
        {
            cout << j << "  ";
        }
        cout << endl << endl;
    }
    ask_to_reset();
}

// Checks if user inputted a valid number
int check_input_valid(void (*currentProgram)())
{
    string inputString = "";
    cin >> inputString;

    // Iterates through each character
    for (string::size_type i = 0; i < inputString.length(); i++) // string::size_type ensures the counter can handle the size of the string
    {
        if (!isdigit(inputString[i])) // checks if input is NOT a digit
        {
            clear_screen();
            cout << endl << "You did not enter a valid number. Try again." << endl << endl;
            currentProgram();
        }
    }
    int input = stoi(inputString); // parses the string and converts string to integer
    if (input <= 0) // checks if integer is negative
    {
        clear_screen();
        cout << endl << "You did not enter a valid number. Try again." << endl << endl;
        currentProgram();
    }
    return input;
}