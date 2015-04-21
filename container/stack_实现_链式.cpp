#include <iostream>
#include <stdlib.h>
using namespace std;

enum Error_code {
	success, overflow, underflow
}; 


template<typename Stack_entry>
struct Node {
	Stack_entry entry;
	Node* next;
	Node(Stack_entry item = 0, Node* n = NULL) {
		entry = item;
		next = n;
	}
};

template<typename Stack_entry>
class Stack {
	public:
		//  Standard Stack methods
		Stack();
		bool empty() const;
		Error_code push(const Stack_entry &item);
		Error_code pop();
		Error_code top(Stack_entry &item) const;
		//  Safety features for linked structures
		~Stack();
		Stack(const Stack &original);
		void operator =(const Stack &original);
		
		void clear();
		bool full() const;
		int size() const;
		Error_code pop_and_top(Stack_entry &item);
	protected:
		Node<Stack_entry> *top_node;
};

template<typename Stack_entry>
bool Stack<Stack_entry>::empty() const
/*
Post: Return true if the Stack is empty,
otherwise return false.
 */
{
   return top_node == NULL;
}

template<typename Stack_entry>
Stack<Stack_entry>::Stack()
/*
Post: The Stack is initialized to be empty.
 */
{
   top_node = NULL;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::push(const Stack_entry &item)
/*
Post: Stack_entry item is added to the top of
the Stack; returns success or returns a code
of overflow if dynamic memory is exhausted.
 */

{
   Node<Stack_entry> *new_top = new Node<Stack_entry>(item, top_node);
   if (new_top == NULL) return overflow;
   top_node = new_top;
   return success;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::top(Stack_entry &item) const
/*
Post: The top of the Stack is reported in item. If the Stack
is empty the method returns underflow; otherwise it returns success.
 */

{
   if (top_node == NULL) return underflow;
   item = top_node->entry;
   return success;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::pop()
/*
Post: The top of the Stack is removed.  If the Stack
is empty the method returns underflow; otherwise it returns success.
 */

{
   Node<Stack_entry> *old_top = top_node;
   if (top_node == NULL) return underflow;
   top_node = old_top->next;
   delete old_top;
   return success;
}

template<typename Stack_entry>
Stack<Stack_entry>::Stack(const Stack &original) //  copy constructor
/*
Post: The Stack is initialized as a copy of Stack original.
 */
{
   Node<Stack_entry> *new_copy, *original_node = original.top_node;
   if (original_node == NULL) top_node = NULL;
   else {								 //  Duplicate the linked nodes.
		top_node = new_copy = new Node<Stack_entry>(original_node->entry);
		while (original_node->next != NULL) {
		   original_node = original_node->next;
		   new_copy->next = new Node<Stack_entry>(original_node->entry);
		   new_copy = new_copy->next;
		}
   }
}

template<typename Stack_entry>
void Stack<Stack_entry>::operator = (const Stack &original) //  Overload assignment
/*
Post: The Stack is reset as a copy of Stack original.
 */
{
   Node<Stack_entry> *new_top, *new_copy, *original_node = original.top_node;
   if (original_node == NULL) new_top = NULL;
   else {								 //  Duplicate the linked nodes
		new_copy = new_top = new Node<Stack_entry>(original_node->entry);
		while (original_node->next != NULL) {
		   original_node = original_node->next;
		   new_copy->next = new Node<Stack_entry>(original_node->entry);
		   new_copy = new_copy->next;
		}
   }
   while (!empty())				   //  Clean out old Stack entries
		pop();
   top_node = new_top;				     //  and replace them with new entries.
}

template<typename Stack_entry>
Stack<Stack_entry>::~Stack() //  Destructor
/*
Post: The Stack is cleared.
 */
{
   while (!empty())
		pop();
}

template<typename Stack_entry>
void Stack<Stack_entry>::clear() {

	//Post: deletes all items in the stack, nothing returned

	while (top_node != NULL) {
		Node<Stack_entry> *temp_node = top_node;
		top_node = top_node->next;
		delete temp_node;

	}

}

template<typename Stack_entry>
bool Stack<Stack_entry>::full() const {

	//Post: returns true/false if the stack is full, stack not changed

	Node<Stack_entry> *test_node = new Node<Stack_entry>();
	if (test_node == NULL) return true;
	delete test_node;
	return false;

}

template<typename Stack_entry>
int Stack<Stack_entry>::size() const {

	//Post: returns the number of items in the stack, stack not changed

	Node<Stack_entry> *new_copy = top_node;
	int count = 0;
	
	while (new_copy != NULL) {
		count++;
		new_copy = new_copy->next;
	}

	return count;
	
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::pop_and_top(Stack_entry &item) {

/*   
Post: The top of the Stack is removed.  If the Stack 
is empty the method returns underflow; otherwise it continues to top

Post: The top of the Stack is reported in item. If the Stack 
is empty the method returns underflow; otherwise it returns success.
 */

	//pop
	Node<Stack_entry> *old_top = top_node;
	if (top_node == NULL) return underflow;
	top_node = old_top->next;
	delete old_top;

	//top
	if (top_node == NULL) return underflow;
	item = top_node->entry;
	return success;

}

int main() {
	
}
