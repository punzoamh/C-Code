/**
	CS219_HW4
	inkisthw8__punzo.h
	Purpose: Header File for linked list
	@author Antonio M.H. Punzo
	@version 1.0 5/5/2015
	Compiled using g++ -o hw9 -Wall -Wextra CS219_Punzo/hw9/inkisthw8_punzo.h
*/

/**
 * This header file will create the struct node, 
 * ->and class inkist for the program 
 * inkist will contain a method for the following:
 * add to front, add to rear, boolean empty,
 * size, clear, display, delete from front and delete from rear
 * @author Tony
 *
 */
/**
 * This Application will Use pointers to add nodes to a linked list 
 * It will use template class to add any type required.
 * Nodes will be added or deleted
 * based on the manipulation of the pointers.
 * @author Tony
 *
 */

#ifndef inkisthw8_punzo_h
#define inkisthw8_punzo_h
#include <iostream>

using namespace std;
/**
 * struct node used to create new instances of node
 * each node will have a prev pointer and a next pointer
 * and contain variable-data.
*/

template<class T>
struct node 
{
	T data;
	node<T>* prev;
	node<T>* next;
};

/**
 * Creates class inkist 
 * contains methods for manipulating the pointers 
 * and nodes of the linked list
 *
*/

template<class T>
class inkist
{
public:
	/**
	 * Default Constructor
	 * Set pointers next and prev to head 
	 * for null/empty list 
	*/
	inkist() :head(new node<T>)
	{head->next = head; head->prev = head;}
	
	/**
	 *  Copy Constructor
	 *
	*/
	inkist(const inkist& source);
	
	/**
	 *  Operator overload Function
	 *
	*/
	inkist &operator =(const inkist& source);
	
	/**
	 *  Destructor
	 *
	*/
	virtual ~inkist(void); //{clear(); delete head;}
	/**
	 * test if linked list is empty
	 *
	*/
	bool empty() const;
	
	/**
	 * Method for inserting an integer at front 
	 * 
	*/
	void push_front(const T value);
	
	/**
	 * Method for inserting an integer at rear
	 *
	*/
	void push_back(const T value);
	
	/**
	 * Method for displaying items in list
	 *
	*/
	//void display() const;
	
	/**
	 * Method for deleting all items in list
	 *
	*/
	void clear();
	
	/**
	 * Method for returning size of list
	 *
	*/
	
	int size() const;
	
	
	/**
	 * Method for deleting an integer at front
	 *
	*/
	void pop_front();
	
	/**
	 * Method for deleting an integer at rear
	 *
	*/
	void pop_back();
	
	/**
	 * Method for finding an address of a particular value
	 *
	*/
	node<T>* find(const T& val) const;
	
	/**
	 *  Method for inserting a node before a node 
	 *  with a particular value
	 *
	*/
	node<T>* insert(node<T>* pos, const T& val);
	
	/**
	 *  Method for erasing a node
	 *
	*/
	node<T>* erase(node<T>* pos);
	/**
	 *  Class creating Iterator
	 *  
	*/

	
	class Iterator
	{
		public:
		typedef bidirectional_iterator_tag
				iterator_category;
				typedef ptrdiff_t difference_type;
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				
		Iterator() {}
		Iterator(node<T>* new_iter){iter=new_iter;}
		Iterator& operator++(){iter=iter->next; return *this;}
		Iterator& operator--(){iter=iter->prev; return *this;}
		T& operator*() const{return iter->data;}
		Iterator& operator++(int)
		{
			Iterator tmp= *this;
			++(*this);
			return tmp;
		}
		
		Iterator& operator--(int)
		{
			Iterator tmp= *this;
			--(*this);
			return tmp;
		}
		
		bool operator==(const Iterator& x) const
		{
			return iter == x.iter;
		}
		bool operator!=(const Iterator& x) const
		{
			return iter != x.iter;
		}
		
		
		
		
		
		
		private:
		node<T>* iter;
		
	};
	
	/**
	 *	Iterator begining 
	 *
	 */
	Iterator begin(){return Iterator(head->next);}
	/**
	 *	Iterator end 
	 *
	 */
	Iterator end(){return Iterator(head);}
	/**
	 * private member variables
	 * creates node head
	*/
	private: node<T>* head; 
};

	


/**
  * Function for adding element to front of list
  * Creates new node push_F
  * Stores data from value into push_F
  * Stores address of the pointer head
  * transfers address of push_F to head
  *
 */
template<class T>
void inkist<T>::push_front(const T value)
	{	
		node<T>* push_F = new node<T>; 
		
		push_F->data = value;  
		push_F->next = head->next;
		push_F->prev = head; 
		head->next->prev = push_F;
		head->next = push_F;
		
	}
	
/**
  * Function for adding element to rear of list
  * Creates new node push_B
  * stores push_B in head prev
  * Uses loop to go to last node
  * transfers address of push_B->next to push_B
  * Creates new node push_B2
  * Stores data from value into push_B
  * Stores address of the head->next to push_B
  * transfers address of push_B to head
 */
 template<class T>
 void inkist<T>::push_back(const T value)
{
		node<T>* push_B = new node<T>;
		push_B->data = value;
		push_B->prev = head->prev;
		push_B->next = head;
		head->prev->next = push_B;
		head->prev = push_B;
}


/**
  * Function for displaying list
  * If list is empty displays a message
  * If not empty list is displayed
 */
/**template<class T>
void inkist<T>::display() const{
		 node<T>* list=head->next;
		while(list != head)
		{cout << list->data << "-->"; list = list->next;}
			cout << endl;
	}*/
	
/**
  * Function for clearing list
  * Uses loop to go through each element in list
  * Deletes all elements in list
 */
template<class T>
void inkist<T>::clear()
	{
		
		while(head != head->next) pop_front();
		
		
	}	
template<class T>
bool inkist<T>::empty() const
{
	return(head->next == head);
}
	
/**
  * Function for displaying size of list
  * Uses a counter and transverses the list
  * Each element increments the counter
  * Displays total number of elements in list
 */
template<class T>
int inkist<T>::size() const
	{	
		node<T>* counter = head->next; int size = 0;
		while (counter != head)
		{counter = counter->next; size++;}
		return (size);
	}
	
	
/**
  * Function for deleting element from front of list
 */
template<class T>
void inkist<T>::pop_front()
	{
		head->next = head->next->next;
		delete head->next->prev;
		head->next->prev = head;
	}
	
/**
  * Function for deleting element from rear of list
 */
 
template<class T>
void inkist<T>::pop_back()
	{
		node<T>* pop_B = head->prev;
		pop_B->prev->next = head;
		head->prev = pop_B->prev;
		delete pop_B;
		/**
		head->prev = head->prev->prev;
		delete head->prev->next;
		head->prev->next = head;*/
	
	}
/**
 * Function for finding element in list
 */
 
template<class T>
node<T>* inkist<T>::find(const T& val) const
	{	
		node<T>* pos = head->next;
		while(pos != head)
		{
		
		if(pos->data==val)
		{
			return pos;
		}
		pos = pos->next;
		}
	}	
	
/**
  * Function for inserting a node before a certain node
  */
  
template<class T>
node<T>* inkist<T>::insert(node<T>* pos, const T& val)
	{	
		node<T>* temp = new (struct node<T>);
		temp->data = val;
		temp->next = pos;
		pos->prev->next = temp;
		temp->prev = pos->prev;
		pos->prev = temp;
		return 0;
	}
/**
 * Function for erasing a paticular node
 */
 
template<class T>
node<T>* inkist<T>::erase(node<T>* pos)
	{	
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		return 0;
	}

/**
 * Copy Constructor definition
 * 
 */		
 
template<class T>
inkist<T>::inkist (const inkist& source)
:head(new node<T>)
{
	head->next = head;
	head->prev = head;
	node<T>* temp = source.head->next;
	while(temp != source.head)
	{
		 
		push_back(temp->data);
		temp = temp->next;
	}
	
	
}

/**
 * = Operator Function definition
 * 
 */
template<class T>
inkist<T>& inkist<T>::operator =(const inkist& source)
{
	clear();
	node<T>* temp = source.head->next;
	while(temp != source.head)
	{
		
		push_back(temp ->data);
		temp = temp->next;
	}
	return* this;
}

/**
 * Destructor definition
 * 
 */
template<class T>	
inkist<T>::~inkist()
{
	
	
	clear();
	erase(head);
	cout<< "List Destroyed" <<  endl;
	
}


#endif 
