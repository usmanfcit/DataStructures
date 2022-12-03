#include<iostream>
#include<string.h>

using namespace std;

template <class T>
class Queue
{
private:

	//data members
	T* data; //array of items to be allocated dynamically as per MAX_SIZE
	int front; //front index
	int rear; //rear index
	const int MAX_SIZE; //size of queue

public:

	//constructor
	Queue(const int a = 5) : MAX_SIZE(a)
	{
		data = new T[MAX_SIZE];
		front = -1;
		rear = -1;
	}
	//destructor

	~Queue()
	{
		delete[] data;
	}
	//queue manipulation operations

	void enQueue(const T newItem)
	{
		if (!isFull()) 
		{
			if (front == -1)
				front = 0;
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = newItem;
		}
		else
		{
			cerr << "Queue is Full" << endl;
		}
	}//add an element to the rear of queue

	void deQueue()
	{
		if (!isEmpty())
		{
			if (rear == front)
			{
				rear = front = -1;
			}
			else
			{
				front = (front + 1) % MAX_SIZE;
			}
		}
		else
		{
			cerr << "Queue IS Empty" << endl;
		}
	}

	void clear()
	{
		front = rear = -1;
	}//clear the queue
	//queue accessors
	T getFront() const
	{
		if (!isEmpty())
		{
			return data[front];
		}
		else
		{
			cerr << "Queue IS Empty" << endl;
		}
	}//return element at the front

	T getRear() const
	{
		if(!isEmpty())
		{
			return data[rear];
		}
		else
		{
		cerr << "Queue IS Empty" << endl;
		}
	}//return element at the rear

	//queue status operations
	bool isEmpty() const
	{
		return front == -1;
	}//is queue empty?

	bool isFull() const
	{
		return (rear+1)%MAX_SIZE == front;
	}//is queue full?

	//outputs the data in queue. If the queue is empty, outputs “Empty Queue”.

	void showStructure() const
	{
		if (!isEmpty())
		{
			for (int i = front; i <= rear; i++)
			{
				if (i == front)
				{
					cout << "front -->\t" << data[i] << endl;
				}
				else if (i == rear)
				{
					cout <<"         \t" << data[i] << "\t <-- rear" << endl;
				}
				else
					cout << "         \t" << data[i] << endl;
			}
		}
	}
};

int main()
{
	Queue<int> obj;
	obj.enQueue(10);
	obj.enQueue(2);
	obj.enQueue(30);
	obj.deQueue();
	obj.enQueue(1000);
	obj.showStructure();

	return EXIT_SUCCESS;
}