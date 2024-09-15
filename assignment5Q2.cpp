#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    char gender;
    int rollNumber;
    int marks[3];
    static int generate_rollNumber;

public:
    Student() : rollNumber(++generate_rollNumber) {}

    void accept()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Enter marks for 3 subjects:" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    double getPercentage()
    {
        int totalMarks = 0;
        for (int i = 0; i < 3; i++)
        {
            totalMarks += marks[i];
        }
        return (totalMarks / 3.0);
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Gender: " << gender << endl;
        cout << "Percentage: " << getPercentage() << "%" << endl;
    }

    int getRollNumber()
    {
        return rollNumber;
    }

    string getName()
    {
        return name;
    }
};

int Student::generate_rollNumber = 1000;

int searchStudent(Student *arr[], int count, string name)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i]->getName() == name)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Student *arr[5];
    int count = 0;
    int choice;

    do
    {
        cout << "\n---- Student Management Menu ----" << endl;
        cout << "1. Accept Student Details" << endl;
        cout << "2. Print All Students" << endl;
        cout << "3. Search Student by Name" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < 5)
            {
                arr[count] = new Student();
                arr[count]->accept();
                count++;
            }
            else
            {
                cout << "Maximum number of students reached!" << endl;
            }
            break;

        case 2:
            if (count == 0)
            {
                cout << "No students available." << endl;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "\nStudent " << i + 1 << ":" << endl;
                    arr[i]->display();
                }
            }
            break;

        case 3:
            if (count == 0)
            {
                cout << "No students available to search." << endl;
            }
            else
            {
                string name;
                cout << "Enter student name to search: ";
                cin >> name;
                int index = searchStudent(arr, count, name);
                if (index != -1)
                {
                    cout << "\nStudent found at index " << index << ":" << endl;
                    arr[index]->display();
                }
                else
                {
                    cout << "Student not found." << endl;
                }
            }
            break;

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    for (int i = 0; i < count; i++)
    {
        delete arr[i];
    }

    return 0;
}
