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
    int getSalary()
    {
        return salary;
    }

    void accept()
    {
        cout << "Enter the id :" << endl;
        cin >> id;
        cout << "Enter the salary :" << endl;
        cin >> salary;
    }

    void display()
    {
        cout << "id :" << id << endl;
        cout << "salary :" << salary << endl;
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
    Manager() {}
    Manager(int id, double salary, double bonus) : Employee(id, salary)
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
    void displaySalesMan()
    {
        cout << "Commision :" << commision << endl;
    }

public:
    Salesman() {}

    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commision = commision;
    };

    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesMan();
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager() {}

    SalesManager(int id, double salary, double commision, double bonus) : Employee(id, salary)
    {
        // this->setBonus(bonus);
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display()
    {
        Employee::accept();
        acceptSalesman();
        acceptManager();
    }
};

int main()
{
    Employee *e = new SalesManager();
    e->accept();
    e->display();
}