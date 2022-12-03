#include <iostream>
using namespace std;

class Student
{
friend class StudentMaxHeap;
private:
double cgpa; //Student’s CGPA
int rollNo; //Student’s roll number
};
class StudentMaxHeap
{
private:
Student* arr; //Array of students which, arranged like a Max Heap
int curSize; //Current number of students present in the heap
int maxSize; //Maximum number of students that can be present in heap
public:
StudentMaxHeap (int size)
{
    this->maxSize = size;
    arr = new Student[size];
    curSize = 0;
} 
~StudentMaxHeap()
{
    delete[] arr;
} 
bool isEmpty()
{
    return curSize == 0;
} //Checks whether the heap is empty or not
bool isFull()
{
    return curSize == maxSize;
} //Checks whether the heap is full or not

void heapify(int i)
{
    int max = i; 
    int li = 2 * i + 1; 
    int ri = 2 * i + 2;
 

    if (li < curSize && arr[li].cgpa > arr[max].cgpa)
        max= li;
 

    if (ri < curSize && arr[ri].cgpa > arr[max].cgpa)
        max = ri;

    if (max != i) {
        swap(arr[max].cgpa, arr[i].cgpa);
        heapify(max);
    }
}

bool insert (int rollNo, double cgpa)
{
    if(!this->isFull())
    {
    curSize = curSize + 1;
    arr[curSize - 1].rollNo = rollNo;
    arr[curSize - 1].cgpa = cgpa;
    heapify(curSize -1);

    return true;
    }
    else if (this->isFull())
    {
        cout << "Array Full, cannot insert" << endl;
        return false;
    }
    else
    {
        cout << "Insertion Failed" << endl;
        return false;
    }
    
}

void levelOrder()
{
    if(!isEmpty())
    {
        for (int i = 0; i < curSize; ++i)
            cout << arr[i].rollNo << " " << arr[i].cgpa << endl;
    }
    else
    {
        cout << "Heap Empty, Cannot diplsay" << endl;
    }
}

};


int main()
{
    StudentMaxHeap obj(3);
    obj.insert(1, 3.55);
    obj.insert(2, 3.65);
    obj.insert(3, 3.75);
    obj.insert(4, 3.05); 
    obj.levelOrder(); 
    return 0;
}