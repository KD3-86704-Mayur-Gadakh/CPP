#include <iostream>

using namespace std;

class student
{
    int rollNo;
    int marks;
    string name = "";

public:
    void initStudent()
    {
        rollNo = 0;
        marks = 0;
        name = "";
    }

    void acceptStudent()
    {
        cout << "Enter the name of student :" << endl;
        cin >> name;
        cout << "Enter the rollNo of student :" << endl;
        cin >> rollNo;
        cout << "Enter the marks of student :" << endl;
        cin >> marks;
    }
    void displayStudent()
    {
        cout << "Name :" << name << endl;
        cout << "rollNo :" << rollNo << endl;
        cout << "marks :" << marks;
    }
};

int menu()
{
    int choice;
    cout << "1 accept student" << endl;
    cout << "2 display student" << endl;
    cout << "3 exit" << endl;
    cout << "Enter the choice" << endl;
    cin >> choice;
    return choice;
}

int main()

{
    student st;

    int choice;

    while ((choice = menu()) != 0)
    {
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
    }
    //    st.acceptStudent();
    //   st.displayStudent();
}