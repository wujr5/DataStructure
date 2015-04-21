#include <iostream>
#include <stdlib.h>
using namespace std;

const int maxqueue = 10; //  small value for testing

enum Error_code {
	success, overflow, underflow
}; 

template<typename Queue_entry>
class Queue {
	public:
	   Queue();
	   bool empty() const;
	   Error_code serve();
	   Error_code append(const Queue_entry &item);
	   Error_code retrieve(Queue_entry &item) const;
	   bool full() const;
	   int size() const;
	   void clear();
	   Error_code serve_and_retrieve(Queue_entry &item);
	protected:
	   int count;
	   int front, rear;
	   Queue_entry entry[maxqueue];
};

template<typename Queue_entry>
Queue<Queue_entry>::Queue()
/*   
Post: The Queue is initialized to be empty.
 */
{
   count = 0;
   rear = maxqueue - 1;
   front = 0;
}

template<typename Queue_entry>
bool Queue<Queue_entry>::empty() const
/*   
Post: Return true if the Queue is empty, otherwise
return false.
 */
{
   return count == 0;
}

template<typename Queue_entry>
Error_code Queue<Queue_entry>::append(const Queue_entry &item)
/*   
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
 */
{
   if (count >= maxqueue) return overflow;
   count++;
   rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
   entry[rear] = item;
   return success;
}

template<typename Queue_entry>
Error_code Queue<Queue_entry>::serve()
/*   
Post: The front of the Queue is removed. If the Queue 
is empty return an Error_code of underflow.
 */
{
   if (count <= 0) return underflow;
   count--;
   front = ((front + 1) == maxqueue) ? 0 : (front + 1);
   return success;
}

template<typename Queue_entry>
Error_code Queue<Queue_entry>::retrieve(Queue_entry &item) const
/*   
Post: The front of the Queue retrieved to the output
parameter item. If the Queue 
is empty return an Error_code of underflow.
 */
{
   if (count <= 0) return underflow;
   item = entry[front];
   return success;
}

template<typename Queue_entry>
bool Queue<Queue_entry>::full() const
/*   
Post:  Return true if the Extended_queue is full;
return false otherwise.
 */
{
   return count == maxqueue;
}

template<typename Queue_entry>
void Queue<Queue_entry>::clear()
/*   
Post:   All entries in the Extended_queue have
been deleted; the Extended_queue is empty.
 */
{
   count = 0;
   front = 0;
   rear = maxqueue - 1;
}

template<typename Queue_entry>
int Queue<Queue_entry>::size() const
/*   
Post:   Return the number of entries in the Extended_queue.
 */
{
   return count;
}

template<typename Queue_entry>
Error_code Queue<Queue_entry>::serve_and_retrieve(Queue_entry &item)
/*   
Post: Return underflow if the Extended_queue is empty. Otherwise
remove and copy
the item at the front of the Extended_queue to item.
 */
{
   if (count == 0) return underflow;
   else {
      count--;
      item = entry[front];
      front = ((front + 1) == maxqueue) ? 0 : (front + 1);
   }
   return success;
}

int main() {
	
}
