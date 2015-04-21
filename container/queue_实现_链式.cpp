#include <iostream>
#include<stdlib.h> 
using namespace std;

enum Error_code {
	success, overflow, underflow
};

template<typename Queue_entry>
struct Node {
	Node* next;
	Queue_entry entry;
	Node(int item = 0, Node* n = NULL) {
		entry = item;
		next = n;
	}
};

template<typename Queue_entry>
class Queue {
	public:
	//  standard Queue methods
	   Queue();
	   bool empty() const;
	   Error_code append(const Queue_entry &item);
	   Error_code serve();
	   Error_code retrieve(Queue_entry &item) const;
	//  safety features for linked structures
	   ~Queue();
	   Queue(const Queue &original);
	   void operator =(const Queue &original);
	
	   bool full() const;
	   int size() const;
	   void clear();
	   Error_code serve_and_retrieve(Queue_entry &item);
	protected:
	   Node<Queue_entry> *front, *rear;
};

template<typename Queue_entry>
bool Queue<Queue_entry>::empty() const
/*   
Post: Return true if the Queue is empty,
otherwise return false.
 */
{
   return front == NULL;
}


template<typename Queue_entry>
Queue<Queue_entry>::Queue()
/*   
Post: The Queue is initialized to be empty.
 */
{
   front = rear = NULL;
}


template<typename Queue_entry>
Error_code Queue<Queue_entry>::append(const Queue_entry &item)
/*   
Post: Add item to the rear of the Queue and
return a code of success 
or return a code
of overflow if dynamic memory is exhausted.
 */
{
   Node<Queue_entry> *new_rear = new Node<Queue_entry>(item);
   if (new_rear == NULL) return overflow;
   if (rear == NULL) front = rear = new_rear;
   else {
      rear->next = new_rear;
      rear = new_rear;
   }
   return success;
}

template<typename Queue_entry>
Error_code Queue<Queue_entry>::retrieve(Queue_entry &item) const
/*   
Post: The front of the Queue is reported
in item. If the Queue 
is empty return an Error_code
of underflow and leave the Queue unchanged.
 */
{
   if (front == NULL) return underflow;
   item = front->entry;
   return success;
}

template<typename Queue_entry>
Error_code Queue<Queue_entry>::serve()
/*   
Post: The front of the Queue is removed.  If the Queue 
is empty, return an Error_code of underflow.
 */
{
   if (front == NULL) return underflow;
   Node<Queue_entry> *old_front = front;
   front = old_front->next;
   if (front == NULL) rear = NULL;
   delete old_front;
   return success;
}

template<typename Queue_entry>
Queue<Queue_entry>::~Queue()
{
   while (!empty())
      serve();
}

template<typename Queue_entry>
Queue<Queue_entry>::Queue(const Queue &copy)
{
   Node<Queue_entry> *copy_node = copy.front;
   front = rear = NULL;
   while (copy_node != NULL) {
      append(copy_node->entry);
      copy_node = copy_node->next;
   }
}

template<typename Queue_entry>
void Queue<Queue_entry>::operator =(const Queue &copy)
{
   while (!empty())
      serve();
   Node<Queue_entry> *copy_node = copy.front;
   while (copy_node != NULL) {
      append(copy_node->entry);
      copy_node = copy_node->next;
   }
}

template<typename Queue_entry>
Error_code Queue<Queue_entry>::serve_and_retrieve(Queue_entry &item)
/*   
Post: The front of the Queue is removed and reported
in item. If the Queue 
is empty return an Error_code
of underflow and leave the Queue unchanged.
 */
{
   if (front == NULL) return underflow;
   Node<Queue_entry> *old_front = front;
   item = old_front->entry;
   front = old_front->next;
   if (front == NULL) rear = NULL;
   delete old_front;
   return success;
}

template<typename Queue_entry>
bool Queue<Queue_entry>::full() const
{
   return false;
}

template<typename Queue_entry>
void Queue<Queue_entry>::clear()
{
   while (!empty())
      serve();
}

template<typename Queue_entry>
int Queue<Queue_entry>::size() const
/*   
Post:   Return the number of entries in the Extended_queue.
 */
{
   Node<Queue_entry> *window = front;
   int count = 0;
   while (window != NULL) {
      window = window->next;
      count++;
   }
   return count;
}

int main() {
	
}
