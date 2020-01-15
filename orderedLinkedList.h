/*
 * orderedLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *f
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include <cstddef>

#include "linkedList.h"

template<class DataType>
class orderedLinkedList
{
public:
	typedef linkedList<DataType>              unorderedLinkedList;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t 					      difference_type;
	typedef std::size_t						      size_type;
	typedef typename unorderedLinkedList::iterator  iterator;
	typedef const iterator	  	               const_iterator;
private:
	// we are making use of the DoubleLinkedList class
	unorderedLinkedList list;
	
public:
	// default constructor
	orderedLinkedList()
	{
		list = linkedList<DataType>();
	}
	// copy constructor
	orderedLinkedList(const orderedLinkedList& other)
	{
		list = other.list;
		
	}
	// assignment operator
	const orderedLinkedList& operator=(const orderedLinkedList& other)
	{
		list = other.list;
		return other;
	}
	// destructor
	virtual ~orderedLinkedList()
	{
		list.~linkedList();
	}
	// iterators
	iterator begin()
	{
		return list.begin();
	}

	iterator end()
	{
		return list.end(); 
	}

	const_iterator begin() const
	{
		return list.begin();
	}

	const_iterator end() const
	{
		return list.end();
	}

	// number of items in the list
	virtual std::size_t size() const
	{
		return list.size();
	}
	// is the list empty (true) or does it have entries (false)
	virtual bool empty() const
	{
		return list.empty();
	}
	// print the items in the list
	virtual void print() const
	{
		list.print();
	}
	// display the contents of the list to the ostream&
	virtual void print(std::ostream& out) const
	{
		list.print(out);
	}
	// display debug information on the passed in ostream
	virtual void debug(std::ostream& out) const
	{
		list.debug(out);
	}
	// find the element and return an interator for it
	virtual iterator find(const DataType& existingItem)
	{
		return list.find(existingItem);
	}
	// remove the node equal to currentItem
	virtual bool erase(const DataType& currentItem)
	{
		return list.erase(currentItem);
	}
	// remove the node by address existingNode
	virtual iterator erase(iterator iter)
	{
		return list.erase(iter);
	}
	// insert the new item into the list (in sorted order)
	// a duplicate entry will be ignored
	virtual void insert(const DataType& newItem)
	{
		if (list.empty())
		{
			list.push_front(newItem);
			return;
		}
		 else if (find(newItem) != nullptr)
		{
			return;
		}
		for (iterator iter = list.begin(); iter != list.end(); iter++)
		{
			if(newItem < (*iter))
			{
				list.insert_before(iter, newItem);
				return;
			
			}
		}
		list.push_back(newItem);
	}
	// get the last entry
	iterator back()
	{
		return list.back();
	}

	const_iterator back() const
	{
		return list.back();
	}
};

// Your implementation code goes here

#endif /* ORDEREDLINKEDLIST_H_ */