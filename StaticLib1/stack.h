#pragma once
#include <cassert>

namespace Algo
{
	
	template<class T>
	class stack
	{
		public:
			void push(T* E);
			void pop();
			bool empty() const;
			T* top() const;
			static stack* creator();
			static void garbage(stack* S);
		private:
			class Node* head;
			stack();
			~stack();
	};

	template<class T>
	class Node
	{
	private:
		T* data;
		Node* next;
		/*public:
			T* getData() const
			{
				return this->data;
			}
			void setData(T* s)
			{
				this->data = s;
			}*/
		friend class stack;//to access private variables could be only a method not always a whole class
	};
}
using namespace Algo;

template<class T>
Algo::stack<T>::stack()
{
	this->head = 0;
}

template<class T>
void Algo::stack<T>::push(T* E)
{
	Node* newNode = new Node();
	assert(newNode != 0);//null === 0 assert in mode debug (developper) checks the condition if not it breaks the execution
	//try catch in mode release (client)
	//newNode->setData(E);
	newNode->data = E;
	newNode->next = this->head;
	this->head = newNode;
}

template<class T>
void Algo::stack<T>::pop()
{
	assert(!this->empty());
	Node* supp = this->head;
	this->head = this->head->next;
	delete supp;
	supp = 0;
}

template<class T>
bool Algo::stack<T>::empty() const
{
	bool res = (this->head == 0);
	return res;
}

template<class T>
T* Algo::stack<T>::top() const
{
	assert(!this->empty());
	return this->head->data;
}

template<class T>
stack<T>* Algo::stack<T>::creator()
{
	stack<T>* S = new stack<T>();
	assert(S);
	return S;
}

template<class T>
void Algo::stack<T>::garbage(stack* S)
{
	assert(S);
	delete S;
}

template<class T>
Algo::stack<T>::~stack()
{
	while (this->head) this->pop();
	//delete this->head;
	//this->head = 0;
}


