#include <iostream>
using namespace std;

class Time
{

    int minuts;
    int hours;
    int seconds;

public:
    Time()
    {

        int h = 12;
        int m = 12;
        int s = 12;
    }

    Time(int h, int m, int s)
    {
        this->hours = h;
        this->minuts = m;
        this->seconds = s;
    }

    void setHours(int h)
    {
        this->hours = h;
    }
    int getHours()
    {
        return hours;
    }
    void setMinuts(int m)
    {
        this->minuts = m;
    }
    int getMinuts()
    {
        return minuts;
    }
    void setSecond(int s)
    {
        this->seconds = s;
    }
    int getSecond()
    {
        return seconds;
    }

    void printTime()
    {
        cout << "Hours :" << hours << endl;
        cout << "Minuts :" << minuts << endl;
        cout << "Seconds :" << seconds << endl;
    }

    void acceptTime()
    {
        cout << "Enter the Hours :" << endl;
        cin >> hours;
        cout << "Enter the Minuts :" << endl;
        cin >> minuts;
        cout << "Enter the seconds :" << endl;
        cin >> seconds;
    }

    void display()
    {
        cout << "Hours :" << hours << endl;
        cout << "minutes :" << minuts << endl;
        cout << "seconds :" << seconds << endl;
    }
};

int main()
{

    Time **ptr = new Time *[5];

    for (int i = 0; i < 5; i++)
    {
        ptr[i] = new Time();
        ptr[i]->acceptTime();
    }
    for (int i = 0; i < 5; i++)
    {
        ptr[i]->display();
    }

    for (int i = 0; i < 5; i++)
    {
        delete ptr[i];
        ptr[i] = NULL;
    }

    delete ptr;
    ptr = NULL;
    // Time t1;

    //   t1.setHours(12);
    //    t1.setMinuts(34);
    //   t1.setSecond(55);
    //   t1.printTime();
}