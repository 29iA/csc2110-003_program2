#if !defined NULL
#define NULL 0
#endif

#if !defined _DEQUEARRAY_H
#define _DEQUEARRAY_H

template < class T >
class DequeArray
{
	private:
		int max_queue;
		T** items;
		int front;
		int back;
		int sz;
		
		void arrayResize();
	
	public:
		DequeArray(); //constructor
		~DequeArray(); //destructor

		bool isEmpty();
		int size();
		void dequeueAll(); //delete and reconstruct array
		
		T* peek(); //see front item
		void enqueue(T* item); //add item to front of array
		T* dequeue(); //remove item front of array and returns it
		
		T* peekDeque(); //see back item
		void enqueueDeque(T* item); //add item to back of array
		T* dequeueDeque(); //remove item front of array and returns it
};

template < class T >
DequeArray<T>::DequeArray() 
{
   max_queue = 2;
   items = new T*[max_queue];  
   front = 0;
   back = max_queue - 1;
   sz = 0;
}  

template < class T >
DequeArray<T>::~DequeArray() 
{
   delete[] items;
} 

template < class T >
bool DequeArray<T>::isEmpty() 
{
   return sz == 0;
}  

template < class T >
int DequeArray<T>::size()
{
   return sz;
}

template < class T >
T* DequeArray<T>::peek()
{
   T* item = NULL;
   if (!isEmpty()) 
   {  
      item = items[front];
   }
   return item; 
} 

template < class T >
void DequeArray<T>::enqueue(T* item)
{
	if (item == NULL) return;
	
   if (sz == max_queue)
		arrayResize();

	back++;
   if (back == max_queue) back = 0;
   items[back] = item;
   sz++;
} 

template < class T >
T* DequeArray<T>::dequeue() 
{
   T* item = NULL;

   if (!isEmpty()) 
   {
      item = items[front];
      items[front] = NULL;

      front++;
      if (front == max_queue) 
		{
			front = 0;
      }
		sz--;
   }

   return item; 
}

template < class T >
void DequeArray<T>::arrayResize()
{
	int new_size = max_queue * 2;
   T** temp = new T*[new_size];
   int j = front;

   for (int i = 0; i < sz; i++)
   {
      temp[i] = items[j];
      j++;
      if (j == max_queue) j = 0;
   }

   front = 0;
   back = sz - 1;
   max_queue = new_size;

   delete[] items;
   items = temp;
}

template < class T >
void DequeArray<T>::dequeueAll() 
{
   delete[] items;

   max_queue = 2;
   items = new T*[max_queue];  
   front = 0;
   back = max_queue - 1;
   sz = 0;
}

template < class T >
void DequeArray<T>::enqueueDeque(T* item)
{
	if (item == NULL) return;
	
	if (sz == max_queue)
		arrayResize();

	front--;

	if (front == -1)
		front = max_queue - 1;
	
	items[front] = item;
	sz++;
}

template < class T >
T* DequeArray<T>::dequeueDeque()
{
	T* item = NULL;
	
	if (!isEmpty())
	{
		item = items[back];
		items[back] = NULL;
		
		back--;
		if (back == -1)
		{
			back = max_queue - 1;
		}
		sz--;
	}
	
	return item;
}

template < class T >
T* DequeArray<T>::peekDeque()
{
	T* item = NULL;

	if (!isEmpty())
		item = items[back];

	return item;
}

#endif