#if !defined _STACK_DEQUE_H
#define _STACK_DEQUE_H

#include "DequeArray.h"

template < class T >
class StackDeque
{
	private:
		DequeArray<T>* stack_array;
	
	public:
		StackDeque(); //constructor
		~StackDeque(); //destructor
		
		bool isEmpty();
		int size();
		void popAll(); //calls dequeueAll
		
		T* peek(); //calls peekDeque
		void push(T* item); //calls enqueue
		T* pop(); //calls dequeueDeque
};

template < class T >
StackDeque<T>::StackDeque()
{
	stack_array = new DequeArray<T>();
}

template < class T >
StackDeque<T>::~StackDeque()
{
	delete stack_array;
}

template < class T >
bool StackDeque<T>::isEmpty()
{
	return stack_array->isEmpty();
}

template < class T >
int StackDeque<T>::size()
{
	return stack_array->size();
}

template < class T >
void StackDeque<T>::popAll()
{
	stack_array->dequeueAll();
}

template < class T >
T* StackDeque<T>::peek()
{
	return stack_array->peekDeque();
}

template < class T >
void StackDeque<T>::push(T* item)
{
	stack_array->enqueue(item);
}

template < class T >
T* StackDeque<T>::pop()
{
	return stack_array->dequeueDeque();
}

#endif