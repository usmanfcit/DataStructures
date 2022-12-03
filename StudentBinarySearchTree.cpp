#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Student
{
friend class StudentBST;
private:
int stdId; //student identifier (unique)
string name; //student name
float fee; //student fee
Student* left; //left subtree of a node
Student* right; //right subtree of a node

public:
    Student(int stdId, string name, float fee, Student* left, Student* right)
    {
        this->stdId = stdId;
        this->name = name;
        this->fee = fee;
        this->left = left;
        this->right = right;
    }

    void show()
    {
        cout << stdId << "\t" << name  << "\t" << fee << endl;
    }
};
class StudentBST
{
private:
Student* root; //root of the tree


    // Working Horses

 void inOrder(Student *stree)
    {
        if (stree != NULL)
        {
         //   cout << endl;
            inOrder(stree->left);
            stree->show();
            inOrder(stree->right);
        }
    }

    void preOrder(Student *stree)
    {
        if (stree != NULL)
        {
        //    cout << endl;
            stree->show();
            preOrder(stree->left);
            preOrder(stree->right);
        }
    }

    void postOrder(Student *stree)
    {
        if (stree != NULL)
        {
          //  cout << endl;
            postOrder(stree->left);
            postOrder(stree->right);
            stree->show();
        }
    }

    // Post-Order Traversal and deletion

    void destroy(Student *stree)        
    {
        if (stree != NULL)
        {
            destroy(stree->left);
            destroy(stree->right);
            delete stree;
        }
    }
public:
StudentBST()
{
    root = NULL;
} //constructor
~StudentBST()
{
    destroy(root);
    root = NULL;
} //destructor

bool insert (int stdId, string name, float balance)
{
        Student *newNode = new Student(stdId, name, balance, NULL, NULL);
        Student *curr = root;
        Student *pre = NULL;
        while (curr != NULL)
        {
            pre = curr;
            if (newNode->stdId == curr->stdId)
                return false;
            else if (newNode->stdId < curr->stdId)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (pre == NULL)
        {
            root = newNode;
            return true;
        }
        else if (pre->stdId < newNode->stdId)
        {
            pre->right = newNode;
            return true;
        }
        else
        {
            pre->left = newNode;
            return true;
        }
}

bool search (int stdId)
{
      Student *temp = root;

        while (temp != NULL)
        {
            if (temp->stdId == stdId)
            {
                temp->show();
                return true;
            }

            else if (temp->stdId < stdId)
                temp = temp->left;

            else
                temp = temp->right;
        }
            cout << "Not FOund" << endl;
            return false;
}

    //Calling Function

    void inOrder()      
    {
        inOrder(root);
        cout << endl;
    }

    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    void postOrder()
    {
        postOrder(root);
        cout << endl;
    }
};


int main()
{
    fstream myfile;
    myfile.open("input2.txt", ios::in);
		int stdId;
        string name;
        float fee;
        StudentBST obj2;
		while (!myfile.eof()) {
			myfile >> stdId >> name >> fee;
            obj2.insert(stdId, name, fee);        
}
    myfile.close();
    obj2.postOrder();
    return 0;
}