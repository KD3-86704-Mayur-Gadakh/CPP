#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        int day = 0;
        int month = 0;
        int year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }

    void Desplay()
    {
        cout << day << "/" << month << "/" << year << "/" << endl;
    }

    void acceptDate()
    {
        cout << "Enter the Day :" << endl;
        cin >> day;
        cout << "Enter the Month :" << endl;
        cin >> month;
        cout << "Enter the year :" << endl;
        cin >> year;
    }
};

class Person
{
    string name;
    string addres;
    Date birthDate;

public:
    Person()
    {
        string name = "";
        string addres = "";
    }

    Person(string name, string addres, int day, int month, int year) : birthDate(day, month, year)
    {
        this->name = name;
        this->addres = addres;
        this->birthDate.setDay(day);
        this->birthDate.setMonth(month);
        this->birthDate.setYear(year);
    }

    void acceptPerson()
    {
        cout << "Enter the name :" << endl;
        cin >> name;
        cout << "Enter the address :" << endl;
        cin >> addres;
        birthDate.acceptDate();
    };

    void displayPerson()
    {
        cout << "Name :" << name << endl;
        cout << "Address :" << addres << endl;
        birthDate.Desplay();
    }
};

int main()
{
    Date d;

    Person p;
    p.acceptPerson();
    p.displayPerson();
}
