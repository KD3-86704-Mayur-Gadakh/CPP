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

        this->day = 1;
        this->month = 2;
        this->year = 2000;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout << "Enter the Day :" << endl;
        cin >> day;
        cout << "Enter the Month :" << endl;
        cin >> month;
        cout << "Enter the Year :" << endl;
        cin >> year;
    }

    void dispalyDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
    string name;
    string address;
    Date dob; // pointer aggrigation
    //   Date doj;//object composition

public:
    Person()
    {
        this->name = "Mayur";
        this->address = "Pune";
    }

    Person(string name, string address, Date dob)
    {
        this->name = name;
        this->address = address;
    }

    void acceptPerson()
    {
        cout << "Enter the name :" << endl;
        cin >> name;
        cout << "Enter the address :" << endl;
        cin >> address;
        dob.acceptDate();
    }
    void displayPerson()
    {
        cout << "Name :" << name << endl;
        cout << "addres :" << address << endl;
        cout << "Date of birth :";
        dob.dispalyDate();
    }
};

class Employee : public Person
{
    int id;
    int sal;
    string dept;
    Date doj;

public:
    Employee()
    {
        this->id = 1;
        this->sal = 10000;
        this->dept = "Development";
    }
    Employee(int id, int sal, string dept)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
    }
    void acceptEmployee()
    {

        // p.acceptPerson();
        Person::acceptPerson();

        // dob.acceptDate();
        cout << "Enter the id:" << endl;
        cin >> id;
        cout << "Enter the sal :" << endl;
        cin >> sal;
        cout << "Enter the dept :" << endl;
        cin >> dept;
        cout << "Enter the DOJ :";
        doj.acceptDate();
        // doj.acceptDate();
    }
    void displayEmployee()
    {
        Person::displayPerson();
        // p.displayPerson();
        cout << "id :" << id << endl;
        cout << "sal :" << sal << endl;
        cout << "Dept :" << dept << endl;
        cout << "Date of joining :";
        // doj.dispalyDate();
        doj.dispalyDate();
    }
};

int main()
{

    Employee e;

    e.acceptEmployee();
    e.displayEmployee();
}