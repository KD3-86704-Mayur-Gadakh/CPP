#include <iostream>
using namespace std;

class Stack
{
    int size;
    int top;
    int *ptr;

public:
    Stack(int size = 5)
    {
        this->size = size;
        top = -1;
        ptr = new int[size];
    }

    bool isFull()
    {
        return top == size;
    };

    void push(int element)
    {
        if (!isFull())
        {
            top++;
            ptr[top] = element;
        }
    }

    void pop()
    {

        cout << "elemtnts :" << ptr[top] << endl;
        top--;
        // 12345
    }

    bool isEmpty()

    {
        return (top == -1);
    }
    int peek()
    {
        return ptr[top];
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << ptr[i] << " " << endl;
        }
    }
};

int main()
{

    Stack s1;
    cout << s1.isEmpty() << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout << "peek :" << s1.peek() << endl;
    cout << s1.isEmpty() << endl;
    s1.pop();
    cout << "peek :" << s1.peek() << endl;
}