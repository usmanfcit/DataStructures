#include<iostream>
#include<fstream>

using namespace std;

class Student
{
friend class StudentList;

private:
    int id; //id of a student.
    string name; //name of a student.
    float cpga; //cgpa of a student.
    Student* next; //address of the next available object.

public:
    Student(int id, string name, float cgpa, Student *next)
    {
        this->id = id;
        this->name = name;
        this->cpga = cgpa;
        this->next = next;
    } 

    void studentDetails()
    {
        cout << id << endl << name << endl << cpga << endl << endl;
    } //displays the student informaton
};

class StudentList
{
private:
Student* head; //start of the list
Student* cursor; //current item of the list
public:
StudentList()
{
    head = NULL;
    cursor = NULL;
}

~StudentList()
{
        if(head != NULL)
        {
            Student* temp = head->next;
            while (head != NULL)
            {
                delete head;
                head = temp;
                if(temp != NULL)
                    temp = temp->next;   
            }
        }
}

void insert(const Student& newStd)
{
    if(head == NULL)
    {
        
        cursor  = new Student(newStd.id, newStd.name, newStd.cpga, newStd.next);
        head =  cursor;
    }
    else
    {
        Student *temp;
        temp = new Student(newStd.id, newStd.name, newStd.cpga, newStd.next);
        cursor->next = temp;
        cursor = cursor->next;
    }
}

void showStructure () const
{
    if(head != NULL)
    {
        Student *temp = head;
        while (temp != NULL)
        {
            temp->studentDetails();
            temp = temp->next;
        }
    }
    else{ cout << "List is Empty" << endl; }
}

void delAtStart()
    {
        if(head == NULL)
        {
            cout << "List empty, cannot delete at start" << endl;
        }
        else
        {
            Student *temp = head->next;
            delete head;
            head = temp;
            if(temp != NULL)
            {
                temp = temp->next;
            }
        }
    }

    void delAtEnd()
    {
        if(head != NULL)
        {
            Student *temp = head;
            Student *temp2 = temp->next;
            if(temp2 == NULL)
            {
                delete temp;
                temp = NULL;
                head = temp;
            }
            else
            {
                while (temp != NULL)
                {
                    if(temp2->next == NULL)
                    {
                        delete temp2;
                        temp->next = NULL;
                    }
                    else
                    {
                        temp = temp->next;
                        temp2 = temp2->next;
                    }
                }
            }
        }
        else
        {
            cout << "Cannot Delete at end, list is empty" << endl;
        }   
    }

    void remove(int key)
    {
        if(head != NULL)
        {
            Student *temp = head;
            Student *tempPrev = NULL;
            while (temp != NULL)
            {
                if((temp->id == key) && (temp == head))
                {
                    this->delAtStart();
                    break;
                }
                else if (((temp->id == key) && (temp->next == NULL)))
                {
                    this->delAtEnd();
                    break;
                }
                else if (temp->id == key)
                {
                    tempPrev->next = temp->next;
                    delete temp;
                    break;
                }
                tempPrev = temp;
                temp = temp->next;
                if(temp == NULL)
                {
                    cout << "Search complete, cannot delete node" << endl;
                    break;
                }
            } 
        }
        else
            { cout << "List empty, cannot delet node" << endl; } 
    }

void search (float cgpa) const
{
    if(head != NULL)
    {
    Student *temp = head;
    
        while (temp != NULL)
        {
            if(temp->cpga == cgpa)
            {
                temp->studentDetails();
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "List Empty" << endl;
    }
}

void insertAtEnd(const Student& newStd)
    {
        Student* newNode = new Student(newStd.id, newStd.name, newStd.cpga, NULL);
        if( head == NULL)
        {
            head = newNode;
        }
        else
        {
            Student *cur = head;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = newNode;
        }
    }

    void replace (const Student& newStd)
    {
        if(head != NULL)
        {
            Student *temp = head;
            while (temp != NULL)
            {
                if(temp->id == newStd.id)
                {
                    temp->name = newStd.name;
                    temp->cpga = newStd.cpga; 
                }
                temp = temp->next;
            }
        }
        else
        {
            cout << "List Empty" << endl;
        }

    }

    


};


int main()
{
   /* Student obj(1, "Usman", 3.00, NULL);
    Student obj11(122, "111Usman111", 3.00, NULL);
    Student obj22(1, "222Usman222", 3.00, NULL);
    Student obj5(1, "NEWW", 3.05, NULL);
    

    StudentList obj2;
    obj2.insert(obj);
    obj2.insert(obj11);
    obj2.insert(obj22);
    obj2.replace(obj5);
    
    obj2.showStructure(); */

    fstream myfile;
    myfile.open("input.txt", ios::in);
    if(!myfile)
    {
        cout << "Error" << endl;
        exit(0);
    }
    else {
        int id;
        string name;
        float cgpa;

        while (1) {
            myfile >> ch;
            if (my_file.eof())
                break;

            cout << ch;
        }
    

    myfile.close();
    return EXIT_SUCCESS;
}