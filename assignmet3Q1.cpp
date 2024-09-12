#include <iostream>
using namespace std;

class student
{

public:
    student()
    {
        int length = 10;
        int bredth = 10;
        int height = 10;

        int volumn = length * bredth * height;
        cout << "the volumn of the box :" << volumn << endl;
    };
};

class student2
{
    int length;
    int bredth;
    int height;

public:
    student2(int n)
    {
        this->bredth = n;
        this->height = n;
        this->length = n;
        int volume = length * bredth * height;
        cout << "volume of the box :" << volume << endl;
    };
};

class student3
{
    int length;
    int bredth;
    int height;

public:
    student3(int n1, int n2, int n3)
    {

        this->length = n1;
        this->bredth = n2;
        this->height = n3;
        int volume = length * bredth * height;
        cout << "volume of the box :" << volume << endl;
    }
};

main()
{

    student s1;
    student2 s2(5);
    student3 s3(10, 20, 30);
}