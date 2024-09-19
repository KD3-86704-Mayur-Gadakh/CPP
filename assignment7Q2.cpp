#include <iostream>

using namespace std;

class Employee
{

    int id;
    double salary;

public:
    Employee()
    {

        this->id = 1;
        this->salary = 10000;
    }

    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return salary;
    }

    virtual void accept()
    {
        cout << "Enter the id :" << endl;
        cin >> id;
        cout << "Enter the salary :" << endl;
        cin >> salary;
    }

    virtual void display()
    {
        cout << "id :" << id << endl;
        cout << "Salary :" << salary << endl;
    }
};

class Manager : virtual public Employee
{

    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus :" << endl;
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "Bonus :" << bonus << endl;
    }

public:
    Manager()
    {
    }
    Manager(double bonus, int id, double salary) : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
    }
    void display()
    {
        Employee::display();
        displayManager();
    }
};

class Salesman : virtual public Employee
{

    double commision;

protected:
    void acceptSalesman()
    {
        cout << "Enter the commision :" << endl;
        cin >> commision;
    }
    void displaySalesman()
    {
        cout << "commision :" << commision << endl;
    }

public:
    Salesman() {}

    Salesman(double commision, int id, double salary) : Employee(id, salary)
    {
        this->commision = commision;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
};

class salesManager : public Manager, public Salesman
{

public:
    salesManager() {}

    salesManager(double salary, int id, double bonus, double commision) : Employee(id, salary)
    {
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int menu()
{
    int choice;
    cout << "0. EXIT" << endl;
    cout << "1. Accept the employee" << endl;
    cout << "2. DISPLAY count of empoloyee" << endl;
    cout << "3.Display all managers " << endl;
    cout << "4.Display all salesman " << endl;
    cout << "5.Display all salesmanager" << endl;

    cin >> choice;
    return choice;
}

int main()
{

    // Employee *e = new salesManager();
    // // salesManager *s;
    // e->accept();
    // e->display();

    // Salesman *s = new Salesman();
    // s->accept();
    // s->display();

    //   cout << "Type of d: " << typeid(s).name() << endl;
    int count = 0;
    int length = 5;
    Employee *e[length];

    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:

            int num;
            for (int i = 0; i < length; i++)
            {
                count++;
                cout << "1-> Employee 2->manager 3->salesman 4->salesmanager" << endl;
                cin >> num;

                switch (num)
                {
                    count++;

                case 1:
                    e[i] = new Employee();
                    break;

                case 2:
                    e[i] = new Manager();
                    break;

                case 3:
                    e[i] = new Salesman();
                    break;

                case 4:
                    e[i] = new salesManager();
                    break;

                default:
                    cout << "Invalid choice.." << endl;
                    break;
                }

                e[i]->accept();
            }
            break;

        case 2:
            cout << "All employees :" << endl;
            for (int i = 0; i < length; i++)
            {

                e[i]->display();
            }

            break;

        case 3:
            cout << " manager List" << endl;

            for (int i = 0; i < length; i++)
            {
                Manager *m = dynamic_cast<Manager *>(e[i]);
                if (m)
                {
                    e[i]->display();
                }
            }
            break;
        case 4:
            cout << "SalesMan List :" << endl;

            for (int i = 0; i < length; i++)
            {
                Salesman *s = dynamic_cast<Salesman *>(e[i]);
                if (s)
                {
                    e[i]->display();
                }
            }
            break;

        case 5:
            cout << "SalesManager List" << endl;

            for (int i = 0; i < length; i++)
            {
                salesManager *sm = dynamic_cast<salesManager *>(e[i]);
                if (sm)
                {
                    e[i]->display();
                }
            }

            break;

        default:
            cout << "Invalid choice..." << endl;
            break;
        }
    };

    //   cout << "Type of d: " << typeid(s).name() << endl;

    return 0;
}