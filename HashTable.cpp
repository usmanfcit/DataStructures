#include<iostream>
#include<string.h>
using namespace std;

class HashTable
{
private:
string *table; //Dynamic array of strings to hold names
int size; //Total number of slots in the table
int curSize; //Current number of elements present in the table

public:
HashTable (int size)
{
    this->size = size;
    table = new string[size];
    this->curSize = 0;
    for (int i = 0; i < size; i++)
    {
        table[i] = "EMPTY";
    }
    
} //Constructor, store “EMPTY” to indicate free //location in the HashTable

~HashTable ()
{
    delete[] table;
}

bool isEmpty ()
{
    return curSize == 0;
} //Checks whether hash table is empty or not
bool isFull ()
{
    return curSize == size;
} //Checks whether hash table is full or not
double loadFactor()
{
    return curSize/size;
} //Calculates & returns the load factor of the //hash table (curSize/size)

int hash(string name)
{
    return value(name) % size;
}

int getCur()
{
    return curSize;
}

int getSize()
{
    return size;
}

int value(string name)
{
    int temp = 0;
    for (int i=0; i < name.length(); i++)
    {
        temp = temp + name[i];
    }
    return temp;
}

bool insert(string name)
{
    if(!isFull())
    {
        int h = hash(name);
        for (int i = 0; i < size; i++)
        {
            if(table[h] == "EMPTY")
            {
            table[h] = name;
            curSize++;
            return true;
            }
            else
            {
                h = (h+1) % size;
            }
        }
        cout << "Not Inserted" << endl;
        return false;
    }
    else
    {
        cout << "Table Full, Not inserted" << endl;
        return false;
    }
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        cout << i << ":" << table[i] << endl;
    }
    
}

bool search (string name)
{
    if(!isEmpty())
    {
        int h = hash(name);
        for (int i = 0; i < size; i++)
        {
            if(table[h] == name)
            {
            cout << "Name Found in Search" << endl;
            return true;
            }
            else
            {
                h = (h+1) % size;
            }
        }
        cout << "Name NOT Found in Search" << endl;
        return false;
    }
    else
    {
        cout << "Table Empty, Not Searching" << endl;
        return false;
    }   
}

bool remove (string name)
{
   if(!isEmpty())
    {
        int h = hash(name);
        for (int i = 0; i < size; i++)
        {
            if(table[h] == name)
            {
            cout << "Name Found in Search, Removing Item" << endl;
            curSize--;
            table[h] = "EMPTY";
            return true;
            }
            else
            {
                h = (h+1) % size;
            }
        }
        cout << "Name NOT Found in Search, Not Removed" << endl;
        return false;
    }
    else
    {
        cout << "Table Empty, Cannot remove" << endl;
        return false;
    }   
}

};


int main()
{
    int size = 0;
    cout << "Enter size of the hash table : ";
    cin >> size;
    HashTable obj(size);

    while (1)
    {
        int c;
        cout << "1: Insert a name" << endl << "2: Search for a name" << endl << "3: Remove a name" << endl << "4: Display the table" << endl << "5: Display the load factor of the table" << endl << "6: Exit";
        cout << endl << "Enter Your Choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            {
                string name;
                cout << "Enter Name, you want to insert" << endl;
                cin >> name;
                obj.insert(name);
            }
            break;
        case 2:
            {
                string name;
                cout << "Enter Name, you want to Search" << endl;
                cin >> name;
                obj.search(name);
            }
            break;

        case 3:
            {
                string name;
                cout << "Enter Name, you want to remove" << endl;
                cin >> name;
                obj.remove(name);
            }
            break;

        case 4:
            obj.display();
            break;

        case 5:
            cout << "Load factor of the table : " << obj.loadFactor() << endl;
            break;
        case 6:
            exit(0);
            break;
        
        default:
            cout << "Invalid Input" << endl;
            break;
        }

    cout << endl;
    }

    

    return EXIT_SUCCESS;
}