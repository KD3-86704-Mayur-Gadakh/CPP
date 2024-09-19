#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Product
{
    int id;
    string title;
    int price;

public:
    Product() {}
    Product(int id, string title, int price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    void accept()
    {

        cout << "Enter the id :" << endl;
        cin >> id;
        cout << "Enter the title :" << endl;
        cin >> title;
        cout << "Enter the price :" << endl;
        cin >> price;
    }

    void display()
    {
        cout << "id :" << id << endl;
        cout << "title :" << title << endl;
        cout << "price :" << price << endl;
    }
};

class Book : public Product
{

    string author;

public:
    Book()
    {
    }

    Book(int id, string title, int price, string author) : Product(id, title, price)
    {
        this->author = author;
    }

    void acceptAuther()
    {
        cout << "Enter the name of Author :" << endl;
        cin >> author;
        Product::accept();
    }

    void displayAuthor()
    {
        Product::display();
        cout << "Author :" << author << endl;
    }
};

class Tape : public Product
{
    string artist;

public:
    Tape() {}

    Tape(int id, int price, string title, string artist) : Product(id, title, price)
    {
        this->artist = artist;
    }

    void acceptArtist()
    {
        cout << "Enter the Artist :" << endl;
        cin >> artist;
        Product::accept();
    }

    void displayArtist()
    {
        Product::display();
        cout << "Artist :" << artist << endl;
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
};

int menu()
{

    Product *arr[3];

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