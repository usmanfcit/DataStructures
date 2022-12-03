#include <iostream>
using namespace std;
class Collection
{
private:
    int* data;
    int size;
public:
    Collection(int size_2)
    {
        data = new int[size_2];
        size = size_2;
        for (int i = 0; i < size_2; i++)
        {
            data[i] = 0;
        }
    }
    Collection(int ar[], int size_3)
    {
        data = new int[size_3];
        size = size_3;
        for (int i = 0; i < size_3; i++)
        {
           data[i] = ar[i];
        }
    }
    Collection(const Collection &obj)
    {
        data = new int[obj.size];
        this->size = obj.size;
        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i];
        }
    }

    ~Collection()
    {
        delete[] data;
    }

    int getSize()
    {
        return size;
    }
    void printCollection()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << "\t";
        }
        cout << endl;
    }
    void getCollection()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
        cout << endl;
    }
    void insertElement(int k, int i)
    {
        if(i<size && i>=0)
        {
            data[i] = k;
        }
        else
        {
            cout << "Invalid Index" << endl;
            exit(0);
        }
    }
    bool findElement(int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == key)
            {
                return true;
            }
        }
        return false;
    }
    Collection operator=(const Collection &obj)
    {
        if(this != &obj)
        {
            if(size != obj.size)
            {
                delete[] data;
                this->size = obj.size;
                data = new int[size];
                for (int i = 0; i < size; i++)
                {
                    data[i] = obj.data[i];
                }
            }
        }
        return *this;
    }
    Collection operator+(const Collection &obj)
    {
        Collection temp(size);
        if(this->size == obj.size)
        {   
            for (int i = 0; i < size; i++)
            {
                temp.data[i] = this->data[i] + obj.data[i];
            }
            return temp;
        }
        else
        {
            cout << "Object Sizes diffrent, can't perform addition" << endl;
            temp.size = -1;
            temp.data = NULL;

            return temp;
        }
    }

    bool operator==(const Collection &obj)
    {
        if (this->size == obj.size)
        {
            for (int i = 0; i < size; i++)
            {
                if( data[i] != obj.data[i] )
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            cout << "Object Sizes Diffrent, returning false" << endl;
            return false;
        }
    }

};
int main()
{
    Collection obj(5);
    int arr[] = {5, 6, 7, 9, 10};
    Collection obj2(arr, 5);
    Collection obj3 = obj;

    Collection obj4 = obj2 + obj2;

    obj.printCollection();
    obj2.printCollection();
    obj3.printCollection();
    obj4.printCollection();

    return EXIT_SUCCESS;

}