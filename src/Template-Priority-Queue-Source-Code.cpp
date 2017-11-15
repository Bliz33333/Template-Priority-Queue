//============================================================================
// Name        : Template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <class T>
class QueueUnit
{
	T value;

public:
	QueueUnit* prevNode;
	QueueUnit* nextNode;
	QueueUnit(T val)
	{
		value = val;
		prevNode = 0;
		nextNode = 0;
	}

	QueueUnit()
	{
		prevNode = 0;
		nextNode = 0;
	}

	~QueueUnit(){}

	void remove()
	{
		prevNode->nextNode = nextNode;
		nextNode->prevNode = prevNode;
	}

	T getValue()
	{
		return value;
	}
};

template<class T>
class TemplateQueue
{
	QueueUnit<T>* root;
	int size;

public:
	TemplateQueue()
	{
		root = new QueueUnit<T>();
		size = 0;
	}

	T pop()
	{
		T value1 = root->nextNode->getValue();
		root->nextNode->remove();
		size--;
		return value1;
	}

	bool add(T val)
	{
		QueueUnit<T>* u = new QueueUnit<T>(val);
		QueueUnit<T>* p = root;

		if(size == 0)
		{
			size ++;
			p->nextNode = u;
			p->prevNode = u;
			u->nextNode = p;
			u->prevNode = p;
			return false;
		}
		for(int i = 0; i < size; i++)
		{
			if(val <= p->nextNode->getValue())
			{
				u->prevNode = p;
				u->nextNode = p->nextNode;
				p->nextNode->prevNode = u;
				p->nextNode = u;

				size++;
				return true;
			}
			p = p->nextNode;
		}
		p->nextNode = u;
		root->prevNode = u;
		u->nextNode = root;
		u->prevNode = p;
		size++;
		return true;
	}

	int getSize()
	{
		return size;
	}

	~TemplateQueue()
	{
		for(int i = 0; i < size; i++)
		{
			root->nextNode->~QueueUnit();
		}

		delete root;
	}


};

int main()
{
	TemplateQueue<int> ints = TemplateQueue<int>();

	ints.add(4);
	ints.add(5);
	ints.add(1);
	ints.add(3);
	ints.add(7);
	ints.add(4);
	ints.add(0);
	ints.add(-234);
	ints.add(45);
	ints.add(1235);

	int num = ints.getSize();
	for(int i = 0; i < num; i++)
	{
		cout << ints.pop() << endl;
	}

	TemplateQueue<string> strings = TemplateQueue<string>();

	strings.add("");
	strings.add("sad");
	strings.add("xczv");
	strings.add("Ba*fs*");
	strings.add("(*adb");
	strings.add("QRWAEQTEFB");
	strings.add("cxzvse");
	strings.add("a");
	strings.add("b");
	strings.add("c");
	strings.add("d");

	int num2 = strings.getSize();
	for(int i = 0; i < num2; i++)
	{
		cout << strings.pop() << endl;
	}

	return 0;
}
