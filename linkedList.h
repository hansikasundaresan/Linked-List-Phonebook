/*
 * linkedList.h
 *
 * Implementation of a double linked list.
 *
 * We have the ability to get the first and last entries and navigate
 * through the entries in the linked list.
 *
 * There are actually three classes here:
 *
 * listNode<DataType>
 *
 * listNodeIterator<DataType>
 
 * and
 *
 * linkedList<DataType>
 *
 * The listNodeIterator is the iterator for the new linked list class. 
 * 
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//#include "memoryLeak.h"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <iterator>

// forward declaration of the template class linkedList
template<class DataType>
class linkedList;
// forward declaration of iterator
template<class DataType>
class linkedListIterator;

// listNode class
template<class DataType>
class listNode
{
	// make DoubleLinkedList<DataType> a friend class
	friend class linkedList<DataType>;
	friend class linkedListIterator<DataType>;
	private:
		// contains the actual data
		DataType dataType;
		// pointer to the next item in the list or nullptr 
		// if at the end
		listNode<DataType>* pNext;
		// pointer to the previous item in the list or nullptr 
		// if at the start
		listNode<DataType>* pPrevious;
	public:
		// default constructor
		listNode();
		
		// constructor with data
		listNode(const DataType& newItem);
	protected:
		// get the next node
		listNode* next() const
		{
			return pNext;
		}

		// get the previous node
		listNode* previous() const
		{
			return pPrevious;
		}

		// return the data stored in the node as a const
		const DataType& data() const
		{
			return dataType;
		}
		// return the data stored in the node
		DataType& data()
		{
			return dataType;
		}
		// update the next node
		void next(listNode *nextNode)
		{
			pNext = nextNode;
		}
		// update the previous node
		void previous(listNode *previousNode)
		{
			pPrevious = previousNode;
		}
	
};

// the linkedListIterator is the iterator for class linkedList.
//
// most of this code has been provided for you. 
// the exceptions are the operator--() operator--(int) member fuctions and
// and the operator== and operator!= member functions. 
template<class DataType>
class linkedListIterator
{
	typedef DataType 								   value_type;
	typedef DataType& 								reference;
	typedef const DataType& 						const_reference;
	typedef DataType* 								pointer;
	typedef const DataType* 						const_pointer;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t 							difference_type;
	typedef std::size_t								size_type;
	typedef linkedListIterator						iterator;
	typedef const linkedListIterator	  			const_iterator;

	friend class linkedList<DataType>;
	private:
		listNode<DataType> *current;
	public:
		linkedListIterator(listNode<DataType> *current)
			: current(current)
		{
		}

		virtual ~linkedListIterator()
		{
		}

		reference operator*()
		{
		   assert(current != nullptr);
			return current->data();
		}

		//Returns constant data method
		const_reference operator*() const
		{
		   assert(current != nullptr);
			return current->data();
		}

		//Returns memory address of data method current
		pointer operator->()
		{
		   assert(current != nullptr);
			return &(current->data());
		}

		const_pointer operator->() const
		{
		   assert(current != nullptr);
			return &(current->data());
		}

		iterator operator++()
		{
			if (current != nullptr)
			{
				current = current->next();
			}
			return *this;
		}

		iterator operator++(int)
		{
			iterator it = *this;
			if (current != nullptr)
			{
				current = current->next();
			}
			return it;
		}

      // you need to implement the following - they can be inlined if you want
		iterator operator--()
		{
			if (current != nullptr)
			{
				current = current->previous();
			}
			return *this;
		}
		iterator operator--(int)
		{
			iterator it = *this;
			if (current != nullptr)
			{
				current = current->previous();
			}
			return it;
		}
		bool operator==(const_iterator &other) const
		{
			//if null pointer then doens't compare data correctly
			//
			return current == other.current;
		}
		bool operator!=(const_iterator& other)
		{
			//compare node pointers to see if memory allocation is the same
			//therefore curren == other.current
			return current != other.current;
		}

};
		
// linkedList class
template<class DataType>
class linkedList
{
	public:
 		typedef DataType 								   value_type;
 		typedef DataType& 								reference;
 		typedef const DataType& 						const_reference;
 		typedef DataType* 								pointer;
 		typedef const DataType* 						const_pointer;
 		typedef std::bidirectional_iterator_tag	iterator_category;
 		typedef std::ptrdiff_t 							difference_type;
 		typedef std::size_t								size_type;
		typedef linkedListIterator<DataType>		iterator;
		typedef const linkedListIterator<DataType> const_iterator;

	private:
		// your instance data goes here. Things like the pointers to the first and last nodes 
		//  as well as the count of nodes
		listNode<DataType>* firstNode;
		listNode<DataType>* lastNode;
		size_t count=0;
	public:
		// default constructor
		linkedList()
		{
			firstNode = nullptr;
			lastNode = nullptr;
		}
		// copy constructor
		linkedList(const linkedList &other)
		{
			firstNode = nullptr;
			lastNode = nullptr;
			count = 0;

			for (iterator it = other.begin(); it != other.end(); it++)
			{
				push_back(it.current->data());
			}

		}
		// assignment operator
		const linkedList& operator=(const linkedList& other)
		{
			listNode<DataType>* tempNode = nullptr;
			listNode<DataType>* currNode = nullptr;
			if (!firstNode)
				return *this;

	
			currNode = firstNode;
			while (currNode != nullptr)
			{
				tempNode = currNode->next();
				delete currNode;
				currNode = tempNode;
			}
			delete tempNode;			
		
			//how to copy elements of list using iterator
			firstNode = nullptr;
			lastNode = nullptr;
			count = 0;

			for (iterator it = other.begin(); it != other.end(); it++)
			{
				push_back(it.current->data());
			}

			return *this;
		}
		// destructor
		virtual ~linkedList()
		{
			listNode<DataType>* tempNode = nullptr;
			listNode<DataType>* currNode = nullptr;
			if (!firstNode)
				return;
			
			currNode = firstNode;
			while (currNode != nullptr)
			{
				tempNode = currNode->next();
				delete currNode;
				currNode = tempNode;
			}
			firstNode = nullptr;
			lastNode = nullptr;
			delete tempNode;
		}
		// return the number of nodes in the list
		std::size_t size() const
		{
			/*listNode<DataType>* currNode = firstNode;
			while (currNode != nullptr)
			{
				count++;
				currNode = currNode->next();
			}*/
			return count;
		}
		// return true if the list is empty
		bool empty() const
		{
			if (!firstNode)
				return true;
			return false;
		}
		// display the contents of the list to std::cout
		void print() const
		{
			print(std::cout);
		}
		// display the contents of the list to the ostream&
		void print(std::ostream& out) const
		{
			for (iterator it = begin(); it != end(); it++)
			{
				out << it.current->data();
			}
		}

		// iterators
		iterator begin()
		{
			return iterator(firstNode);
		}

		const_iterator begin() const
		{
			return iterator(firstNode);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		const_iterator end() const
		{
			return iterator(nullptr);
		}

		// dump the contends in debug format to passed in 
		// ostream - usage to cout would be:
		//   list.debug(std::cout);
		void debug(std::ostream& out) const;


	public:
		// add an item to the front of the list
		virtual void push_front(const DataType& newItem)
		{

			listNode<DataType>* tempNode = nullptr;
			tempNode = new listNode<DataType>(newItem);
			
			if(!firstNode)
			{
				firstNode = tempNode;
				lastNode = tempNode;
			}
			else
			{
				tempNode->next(firstNode);
				firstNode->previous(tempNode); 
				firstNode = tempNode;
			}
			
			
			count++;
		}
		// add an item to the back of the list
		virtual void push_back(const DataType& newItem)
		{
			listNode<DataType>* tempNode = nullptr;
			tempNode = new listNode<DataType>(newItem);
			if (!lastNode)
			{
				firstNode = tempNode;
				lastNode = tempNode;
			}
			else
			{
				lastNode->next(tempNode);
				tempNode->previous(lastNode);
				lastNode = tempNode;
				
			}
			count++;
		}
		// remove an item from the front of the list
		virtual void pop_front()
		{
			if (size() == 1)
			{
				delete firstNode;
				delete lastNode;
				count--;
			}
			else if (firstNode)
			{
				listNode<DataType>* tempNode = nullptr;
				tempNode = firstNode->next();
				delete firstNode;
				firstNode = tempNode;
				count--;
			}
			
			
		}
		// remove an item from the back of the list
		virtual void pop_back()
		{
			if (size() == 1)
			{
				delete lastNode;
				delete firstNode;
				count--;
			}
			else if (lastNode)
			{
				listNode<DataType>* tempNode = nullptr;
				tempNode = lastNode->previous();
				tempNode->next(nullptr);
				delete lastNode;
				lastNode = tempNode;
				count--;
			}
			
			
		}
		// insert newItem before the node specified by the iterator
		virtual void insert_before(iterator iter, const DataType& newItem)
		{
			if (empty()) {
				push_back(newItem);
				return;
			}

			if (iter == end())
				return;
			else if (iter == begin())
			{
				push_front(newItem);
			}
			else if (iter.current)
			{
				listNode<DataType>* tempNode = nullptr;
				tempNode = iter.current;
				listNode<DataType>* currNode = nullptr;
				currNode=new listNode<DataType>(newItem);
				currNode->previous(tempNode->previous());
				currNode->next(tempNode);
				tempNode->previous()->next(currNode);
				tempNode->previous(currNode);
				
				count++;
			}
			
			
		}
		// insert newItem after the node specified by the iterator
		virtual void insert_after(iterator iter, const DataType& newItem)
		{

			if (empty()) {
				push_back(newItem);
				return;
			}

			if (iter == end())
				return;
			else if (iter == back())
			{
				push_back(newItem);
			}
			else if (iter.current)
			{
				listNode<DataType>* tempNode = nullptr;
				tempNode = iter.current;
				listNode<DataType>* currNode = nullptr;
				currNode = new listNode<DataType>(newItem);
				currNode->next(tempNode->next());
				currNode->previous(tempNode);
				tempNode->next()->previous(currNode);
				tempNode->next(currNode);
				count++;
			}

		}
		// find the node and return the iterator for that element.
		// Return end() if not found
		virtual iterator find(const DataType& existingItem);

		// remove the node equal to currentItem
		virtual bool erase(const DataType& currentItem);
		
		// remove the node by address existingNode
		virtual iterator erase(iterator iter);
		
		// return the iterator for the last node
		virtual iterator back()
		{
			return linkedListIterator<DataType>(lastNode);
		}
		virtual const_iterator back() const
		{
			return linkedListIterator<DataType>(lastNode);
		}
	protected:
	private:
	   // any helper functions you need should eithee be protected or private
};

// the constructors for the listNode class are included here
// default constructor
template <class DataType>
listNode<DataType>::listNode()
	: dataType(), pNext(nullptr), pPrevious(nullptr)
{
}

// constructor with data
template <class DataType>
listNode<DataType>::listNode(const DataType &newItem)
	: dataType(newItem), pNext(nullptr), pPrevious(nullptr)
{
}

// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void linkedList<DataType>::debug(std::ostream &out) const
{
	const unsigned int ADDRWIDTH = 10;
	out << "START DEBUG" << std::endl;
	out << "first  =" << std::setw(ADDRWIDTH) << firstNode;
	out << ", last=" << std::setw(ADDRWIDTH) << lastNode;
	out << ", # nodes=" << size() << std::endl;
	unsigned int count = 1;

	for (auto current=firstNode; current!= nullptr; current=current->next())
	{
		out << "node " << std::setw(2) << count;
		out << "=" << std::setw(ADDRWIDTH) << current;
		out << ", next=" << std::setw(ADDRWIDTH)
			<< current->next();
		out << ", previous=" << std::setw(ADDRWIDTH)
			<< current->previous();
		out << ", value=" << current->data() << std::endl;
		count++;
	}
	out << "END DEBUG" << std::endl;
}

// I have included a few function headers and bodies here where the syntax is odd
// Your implementation of non-inlined member funcctions needs to go there. 
// default constructor


// this is one where the C++ stynax gets very odd. Since we are returning back an interator we
// need to qualify it with the class it is in (linkedList<DataType>::iterator and we 
// have ot include the typename so the C++ comiler knows this is a typename and not some other
// template class usage. 
// find the node and return the address to the node. Return
// nullptr if not found



template<class DataType>
typename linkedList<DataType>::iterator linkedList<DataType>::find(const DataType& existingItem)
{
	for (iterator iter = begin(); iter != end(); iter++)
	{
		if (*iter == existingItem)
		{
			return iter;
		}
	}

	return end();
}

// remove the node equal to currentItem
template<class DataType>
bool linkedList<DataType>::erase(const DataType& currentItem)
{

	listNode<DataType>* tempNode = nullptr;
	tempNode = firstNode;

	if (firstNode->data() == currentItem)
	{
		pop_front();
		return true;
	}

	if (lastNode->data() == currentItem)
	{
		pop_back();
		return true;
	}

	tempNode = tempNode->next();
	
	while (tempNode != nullptr)
	{
		if (tempNode->data() == currentItem)
		{
			tempNode->next()->previous(tempNode->previous());
			tempNode->previous()->next(tempNode->next());
			delete tempNode;
			count--;
			return true;
		}
		else
			tempNode= tempNode->next();
	}

	return false;
}


// remove the node by iterator
template<class DataType>
typename linkedList<DataType>::iterator  linkedList<DataType>::erase(linkedList<DataType>::iterator iter)
{

	listNode<DataType>* tempNode = nullptr;
	
	if (iter == back())
	{
		pop_back();
		return end();
	}
	else if (iter == begin())
	{
		iterator it( iter.current->next());
		pop_front();
		return it;
		
	}


	else if (iter.current)
	{
		tempNode = iter.current;
		iterator it(iter.current->next());
		tempNode->previous()->next(tempNode->next());
		tempNode->next()->previous(tempNode->previous());
		delete tempNode;
		count--;
		return it; 
	}
	return iter;


}


// other member functions go here. 

// all of your member function need to be before the #endif
#endif /* DOUBLELINKEDLIST_H_ */
