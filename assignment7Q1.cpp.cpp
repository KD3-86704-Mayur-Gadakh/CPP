#include <bits/stdc++.h>
using namespace std;

class product
{
    int id;
    string title;
    double price;

public:
    product()
    {
    }

    product(int id, string title, double price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    virtual double getprice()
    {
        return this->price;
    }

    virtual void accept()
    {
        cout << "Enter id  ";
        cin >> id;
        cout << "Enter title : ";
        cin >> title;
        cout << "Enter price :";
        cin >> price;
    }

    virtual void display()
    {
        cout << "id : " << id << " ";
        cout << "title : " << title << " ";
        cout << "price : " << price << " ";
    }
};

class Book : public product
{

    string author;

public:
    Book()
    {
    }

    Book(int id, string title, string author, double price) : product(id, title, price)
    {
        this->author = author;
    }

    void accept()
    {
        cout << "Enter the details of book :  \n";
        product::accept();
        cin.ignore();
        cout << "Enter author : ";
        getline(cin, author);
        cout << "\n";
    }

    void display()
    {
        cout << "details of book :  \n";
        product::display();
        cout << "author : " << author << "\n";
    }
};

class Tape : public product
{

    string artist;

public:
    Tape()
    {
    }

    Tape(int id, string title, string artist, double price) : product(id, title, price)
    {
        this->artist = artist;
    }

    void accept()
    {
        cout << "Enter the details of Tape :  \n";
        product::accept();
        cin.ignore();
        cout << "Enter artist : ";
        getline(cin, artist);
    }

    void display()
    {
        cout << "details of tape :  \n";
        product::display();
        cout << "artist : " << artist << "\n";
    }
};

enum Emenu
{
    EXIT,
    BUY_BOOK,
    BUY_TAPE

};

int menu()
{

    int choice;

    cout << "*MENU\n";
    cout << "0) Exit \n";
    cout << "1) BOOK \n";
    cout << "2) TAPE \n";
    cout << "enter your choice \n";

    cin >> choice;

    return choice;
}

// function  to print final bill

void printFinalBill(product **arr)
{

    double totalprice;

    cout << "this is final bill function\n";

    for (int i = 0; i < 3; i++)
    {

        arr[i]->display();
        double orignalprice = arr[i]->getprice();

        double discountedprice;

        if (dynamic_cast<Book *>(arr[i]))
        {
            // product is book for sure so we used dynamic cast here
            // on purchasing book discount is 10%

            discountedprice = orignalprice * 0.90;
            totalprice = totalprice + discountedprice;
            cout << "Discounted price is : " << discountedprice << "\n";
        }

        else if (dynamic_cast<Tape *>(arr[i]))
        {

            // product is tape
            discountedprice = orignalprice * 0.95;
            totalprice = totalprice + discountedprice;
            cout << "Discounted price is : " << discountedprice << "\n";
        }
    }

    cout << "Total bill Price : " << totalprice << "\n";
}

int main()
{

    product *arr[3];

    int choice;
    int index = 0;
    while (((choice = menu()) != Emenu::EXIT))
    {

        switch (choice)
        {
        case BUY_BOOK:
            if (index < 3)
            {
                arr[index] = new Book;
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "user has already purchased three products \n";
            }
            break;

        case BUY_TAPE:

            if (index < 3)
            {
                arr[index] = new Tape;
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "user has already purchased three products \n";
            }
            break;
        }

        if (index > 2)
        {

            cout << " user buyed three products \n ";
            break;
        }
    }

    for (int i = 0; i < 3; i++) // deleting heap memory
    {
        delete arr[i];
    }

    return 0;
}