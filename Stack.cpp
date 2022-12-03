#include<iostream>
#include<string.h>

using namespace std;

template <class T>
class Stack
{
private:
	//Data members
	T* data; //array of items to be allocated dynamically as per MAX_SIZE
	int top; //top of the stack
	const int MAX_SIZE; //maximum capacity of the stack

public:
	//constructor
	Stack(const int a = 5) : MAX_SIZE(a)
	{
		data = new T[MAX_SIZE];
		this->top = -1;
	}
	//destructor

	~Stack()
	{
		delete[] data;
	}

	//stack manipulation operations
	void push(const T newItem)
	{
		if (top != MAX_SIZE - 1)
		{
			data[++top] = newItem;

		}
		else
		{
			cerr << "Stack Full" << endl;
		}
	}//push a new item

	void pop()
	{
		if (!isEmpty())
		{
			top--;
		}
		else
		{
			cerr << "Stack Empty" << endl;
		}
	}//pop an item

	void clear()	//clear the stack
	{
		top = -1;
	}

	//stack accessor
	T getTop() const
	{
		return data[top];
	}//return item at the top

	//stack status operations
	bool isEmpty() const
	{
		return top == -1;
	}//is stack empty?

	bool isFull() const
	{
		return top == MAX_SIZE - 1;
	}//is stack full?

	//outputs the data in stack. If the stack is empty, outputs “Empty Stack”.
	void showStructure() const
	{
		if (!isEmpty())
		{
			for (int i = top; i > -1; i--)
			{
				if (i == top)
				{
					cout << "top --> \t" << data[i] << endl;
				}
				else if (i == 0)
				{
					cout << "        \t" << data[i] << endl;
					cout << "\t_____________________" << endl;
				}
				else
				{
					cout << "        \t" << data[i] << endl;
				}
			}
		}
	}
};

int main()
{
	Stack<int> obj;
	obj.push(100);
	obj.push(200);
	obj.push(300);
	obj.pop();
	obj.push(400);
	obj.showStructure();

	cout << endl << "Float" << endl;

	Stack<float> obj1;
	obj1.push(100.55);
	obj1.push(200.7554);
	obj1.pop();
	obj1.push(300.232);
	obj1.push(400.455);
	obj1.push(5.5);
	obj1.push(665.5);
	obj1.showStructure();

	cout << endl << "String" << endl;
	Stack<string> obj2;
	obj2.push("ABC");
	obj2.push("123");
	obj2.pop();
	obj2.push("345");
	obj2.push("400.455");
	obj2.showStructure();

	return EXIT_SUCCESS;
}