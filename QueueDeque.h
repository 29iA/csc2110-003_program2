#if !defined _QUEUE_DEQUE_H
#define _QUEUE_DEQUE_H

#include "DequeArray.h"

template < class T >
class QueueDeque
{
	private:
		DequeArray<T>* deque_array;
	
	public:
		QueueDeque(); //constructor
		~QueueDeque(); //destructor
		
		bool isEmpty();
		int size();
		void dequeueAll(); //calls dequeueAll
		
		T* peek();
		void enqueue(T* item);
		T* dequeue();
};

template < class T >
QueueDeque<T>::QueueDeque()
{
	deque_array = new DequeArray<T>();
}

template < class T >
QueueDeque<T>::~QueueDeque()
{
	delete deque_array;
}

template < class T >
bool QueueDeque<T>::isEmpty()
{
	return deque_array->isEmpty();
}

template < class T >
int QueueDeque<T>::size()
{
	return deque_array->size();
}

template < class T >
void QueueDeque<T>::dequeueAll()
{
	deque_array->dequeueAll();
}

template < class T >
T* QueueDeque<T>::peek()
{
	return deque_array->peek();
}

template < class T >
void QueueDeque<T>::enqueue(T* item)
{
	deque_array->enqueue(item);
}

template < class T >
T* QueueDeque<T>::dequeue()
{
	return deque_array->dequeue();
}

#endif