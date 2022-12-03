#include <iostream>
using namespace std;

struct Point3D
{
float x, y, z;
};

class PointList
{
private:
    Point3D *p;
    int maxSize;
    int curSize;
    int cursor;

public:
    PointList(int mxSize)
    {
        maxSize = mxSize;
        curSize = 0;
        cursor = -1;

        p = new Point3D[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
           p[i].x = 0;
           p[i].y = 0;
           p[i].z = 0;
        }
    }
    ~PointList()
    {
        delete[] p;
    }

    bool isEmpty()
    {
        if (curSize <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (curSize != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(Point3D newPoint)
    {
        cursor++;

        p[cursor].x = newPoint.x;
        p[cursor].y = newPoint.y;
        p[cursor].z = newPoint.z; 

        curSize++;
    }

    void showStructure()
    {
        if (curSize == 0)
        {
            cout << "Empty List" << endl;
        }
        else
        {
            for (int i = 0; i < curSize; i++)
            {
                cout << i << ": \t" << p[i].x << "\t" << p[i].y << "\t" << p[i].z << endl;
            }
        }
    }

    Point3D getCursor()
    {
        Point3D temp;
        if(curSize != 0)
        {
           temp.x = p[cursor].x;
           temp.y = p[cursor].y;
           temp.z = p[cursor].z;
        }
        else
        {
           temp.x = -1;
           temp.y = -1;
           temp.z = -1;
        }
        return temp;
    }

    void gotoBeginning()
    {
        if (curSize != 0)
        {
            cursor = 0;
        }
    }

    void gotoEnd()
    {
        if (curSize != 0)
        {
            cursor = curSize - 1;
        }
    }

    bool gotoNext()
    {
        if (cursor != curSize - 1)
        {
           cursor++;
           return true;
        }
        else
        {
            return false;
        }
    }

    bool gotoPrior()
    {
        if (cursor != 0)
        {
            cursor--;
            return true;
        }
        else
        {
            return false;
        }
    }

    void clear()
    {
        for (int i = 0; i < maxSize; i++)
        {
            p[i].x = 0;
            p[i].y = 0;
            p[i].z = 0;
        }

        curSize = 0;
        cursor = -1;
    }

    bool replace(Point3D newpoint)
    {
        if(curSize != 0)
        {
            p[cursor].x = newpoint.x;
            p[cursor].y = newpoint.y;
            p[cursor].z = newpoint.z;
            return true;
        }
        else
        {
            return false;
        }
    }

    void remove()
    {
        if (curSize != 0)
        {
            if (cursor == curSize - 1)
            {
                p[cursor].x = 0;
                p[cursor].y = 0;
                p[cursor].z = 0;
                curSize--;
                cursor = 0;
            }
            else
            {
                p[cursor].x = p[curSize-1].x;
                p[cursor].y = p[curSize-1].y;
                p[cursor].z = p[curSize-1].z;
                curSize--;
            }
        }
    }
};

int main()
{
    Point3D temp;
    temp.x = 99;
    temp.y = 88;
    temp.z = 77;

    Point3D temp2;
    temp2.x = 1000;
    temp2.y = 1111;
    temp2.z = 2222;

    PointList obj(10);

    obj.insert(temp);
    obj.insert(temp);
    obj.insert(temp2);

    obj.showStructure();

    cout << "NEW" << endl;
    obj.gotoBeginning();
    obj.remove();
    obj.showStructure();
 
    return EXIT_SUCCESS;
}