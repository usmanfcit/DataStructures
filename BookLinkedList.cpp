#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Book
{
friend class BookList;
private:
int id; //id of a book.
string title; //name of a book.
float price; //price of a book.
Book *next; //address of the next available object.
Book *pre; //address of the previous available object.
public:
Book(int id, string title, float price, Book* next, Book* pre)
{
    this->id = id;
    this->title = title;
    this->price = price;
    this->next = next;
    this->pre = pre;
}//parameterized constructor
void bookDetails()
{
    cout << id << endl << title << endl << price << endl;
} //displays the book informaton
};

class BookList
{
private:
Book* head; //start of the list
Book* cursor; //current item of the list
Book* last; //last item of the list
public:
BookList()
{
    head  = NULL;
    cursor = NULL;
    last = NULL;
} //default constructor
~BookList()
{
        if(head != NULL)
        {
            cursor = head->next;
            while (head != NULL)
            {
                delete head;
                head = cursor;
                if(cursor != NULL)
                    cursor = cursor->next;   
            }
        }
} //destructor

    void insert (const Book &newItem)
    {
        Book *newNode = new Book(newItem.id, newItem.title, newItem.price, newItem.next, newItem.pre);
        if(head == NULL)
        {
            head  = newNode;
            last = newNode;
            cursor = newNode;
        }
        else
        {
            newNode->pre = cursor;
            cursor->next = newNode;
            cursor = cursor->next;
            last = cursor;
        }
    }

    void showStructureForward ()
    {
            cursor = head;
            if (head == NULL)
            {
                cout << "Cannot display,List is Empty" << endl;
            }
            else
            {
                while (cursor != NULL)
                {
                    cursor->bookDetails();
                    cursor  = cursor->next;
                }
            }    
    }

    void showStructureReverse ()
    {
        cursor = last;
            if (head == NULL)
            {
                cout << "Cannot display,List is Empty" << endl;
            }
            else
            {
                while (cursor != NULL)
                {
                    cursor->bookDetails();
                    cursor = cursor->pre;
                }
            }
    }
};

int main()
{
    fstream myfile;
    myfile.open("input1.txt", ios::in);
        int id;
        string title;
        float price;
        BookList obj2;
        while (!myfile.eof()) {
            myfile >> id >> title >> price;
            Book obj(id, title, price, NULL, NULL);
            obj2.insert(obj);        
}
    myfile.close();
    obj2.showStructureForward();
    cout << endl << endl;
    obj2.showStructureReverse();
    return 0;
}