#include <iostream>
using namespace std;

struct DateStruct
{
    int day;
    int month;
    int year;

    void initDate()
    {
        day = 1;
        month = 1;
        year = 1900;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    void printDateOnConsole()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    bool isLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

void menuForStructure(DateStruct &date)
{
    int choice;

    cout << "\nMenu for Structure:\n";
    cout << "1. Initialize Date\n";
    cout << "2. Accept Date\n";
    cout << "3. Print Date\n";
    cout << "4. Check Leap Year\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        date.initDate();
        cout << "Date initialized to 01/01/1900.\n";
        break;
    case 2:
        date.acceptDateFromConsole();
        break;
    case 3:
        date.printDateOnConsole();
        break;
    case 4:
        if (date.isLeapYear())
        {
            cout << date.year << " is a leap year.\n";
        }
        else
        {
            cout << date.year << " is not a leap year.\n";
        }
        break;
    case 5:
        cout << "Exiting...\n";
        break;
    default:
        cout << "Invalid choice! Please try again.\n";
    }
}

int main()
{
    DateStruct date;
    menuForStructure(date);
    return 0;
}
