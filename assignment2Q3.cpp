#include <iostream>
using namespace std;

namespace std
{
    int rollNo;
    string name;
    int marks;
}

class student
{
public:
    void initStudent()
    {
        std::rollNo = 1;
        std::name = "mayur";
        std::marks = 99;
    }

    void acceptStudent()
    {

        cout << "Enter the choice" << endl;
        cout << "Enter the name of student :" << endl;
        cin >> name;
        cout << "Enter the rollno of student :" << endl;
        cin >> rollNo;
        cout << "Enter the marks of the student :" << endl;
        cin >> marks;
    }
    void displayStudent()
    {
        cout << "Name :" << name << endl;
        cout << "rollNo :" << rollNo << endl;
        cout << "marks :" << marks << endl;
    }
};
int menu()
{
    int choice;

    cout << "Enter your choice" << endl;
    cout << "1 Accept the student " << endl;
    cout << "2 display the student " << endl;
    cout << "3 Exit " << endl;
    cin >> choice;
    return choice;
}
int main()
{
    student st;
    // st.acceptStudent();
    // st.displayStudent();

    int choice;
    do

    {
        choice = menu();
        switch (choice)
        {
        case 1:
            st.acceptStudent();
            break;
        case 2:
            st.displayStudent();
            break;
        case 3:
            cout << "Exiting.....";
            break;
        default:
            cout << "Wrong Choice..." << endl;
            break;
        }
    } while (choice != 3);
}