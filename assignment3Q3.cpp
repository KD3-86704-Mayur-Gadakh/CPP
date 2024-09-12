#include <iostream>
using namespace std;

class Address
{
    string building;
    string street;
    string city;
    int pin;

public:
    Address()
    {
        building = "Sunbeam";
        street = "Shanivar Peth";
        city = "karad";
        pin = 411045;
    };

    Address(string b, string s, string c, int p)
    {
        this->building = b;
        this->street = s;
        this->city = c;
        this->pin = p;
    }

    void accept()
    {

        cout << "Enter the building :" << endl;
        getline(cin, building);
        cout << "Enter the street :" << endl;
        getline(cin, street);
        cout << "Enter the city :" << endl;
        getline(cin, city);
        cout << "Enter the pin :" << endl;
        cin >> pin;
    };
    void display()
    {
        cout << "bulding :" << building << endl;
        cout << "street :" << street << endl;
        cout << "city :" << city << endl;
        cout << "pin :" << pin << endl;
    }

    void setBuilding(string s1)
    {
        this->building = s1;
    }
    string getBuilding()
    {
        return building;
    }
    void setStreet(string s2)
    {
        this->street = s2;
    }
    string getStreet()
    {
        return street;
    }
    void setCity(string s3)
    {
        this->city = s3;
    }
    string getCity()
    {
        return city;
    }
    void setPin(int p1)
    {
        this->pin = p1;
    }
    int getPin()
    {
        return pin;
    }
};

int main()
{
    Address a1;

    a1.accept();
    a1.display();
    Address a2;
    a2.setBuilding("Sunbeam");
    cout << a2.getBuilding() << endl;
    a2.setStreet("hinjewadi");
    cout << a2.getStreet() << endl;
    a2.setCity("Pune");
    cout << a2.getCity() << endl;
    a2.setPin(411045);
    cout << a2.getPin() << endl;
    Address a3("Sunbeam", "Shanivar Peth", "karad", 411045);
}
