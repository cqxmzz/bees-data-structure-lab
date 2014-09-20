/** @file */
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include "Utility.h"

/**
 * A linked list.
 *
 * The iterator iterates in the order of the elements being loaded into this list.
 */
template <class T> 
class LinkedList 
{
public:
	class Node
	{
	public:
		Node* pre;
		Node* next;
		T data;
	public:
		Node(T d)
		{
			pre = NULL;
			next = NULL;
			data = d;
		}
	};
private:
	Node* front;
	Node* back;
	int listsize;
public:
    class ConstIterator 
	{
	private:
		Node* p;
		const LinkedList* list;
    public:
		ConstIterator()
		{
			p = NULL; 
			list = NULL;
		}

		ConstIterator(const LinkedList* x)
		{
			list = x;
			p = x->front;
		}

        /**
         * Returns true if the iteration has more elements.
         * O(1).
         */
        bool hasNext()
		{
			if (p == NULL) return false;
			return true;
		}

        /**
         * Returns the next element in the iteration.
         * O(1).
         * @throw ElementNotExist exception when hasNext() == false
         */
        const T& next()
		{
			if (p == NULL) throw ElementNotExist();
			const T& d = p->data;
			p = p->next;
			return d;
		}
    };

    class Iterator {
	private:
		Node* p;
		LinkedList* list;
		bool removed;
    public:
		Iterator()
		{
			p = NULL; 
			list = NULL;
			removed = true;
		}

		Iterator(LinkedList* x)
		{
			list = x;
			p = x->front;
			removed = true;
		}

        /**
         * Returns true if the iteration has more elements.
         * O(1).
         */
        bool hasNext()
		{
			if (p == NULL) return false;
			return true;
		}
        /**
         * Returns the next element in the iteration.
         * O(1).
         * @throw ElementNotExist exception when hasNext() == false
         */
		const T& next()
		{
			if (p == NULL) throw ElementNotExist();
			T& d = p->data;
			p = p->next;
			removed = false;
			return d;
		}

		bool Removed()
		{
			return removed;
		}

        /**
         * Removes from the underlying collection the last element
         * returned by the iterator
         * O(1).
         */
        void remove() 
		{
			if (removed) throw ElementNotExist();
			if (p == list->front) throw ElementNotExist();
			if (p)
			{
				list->remove_node(p->pre);
			}
			else
			{
				list->remove_node(list->back);
			}
			removed = true;
		}
    };

	/**
	/* Remove a node 
	**/                 
	void remove_node(Node* x)
	{
		if (x == front) front = x->next;
		if (x == back) back = x->pre;
		if (x->pre) x->pre->next = x->next;
		if (x->next) x->next->pre = x->pre;
		delete x;
		listsize--;
	}

    /**
     * Constructs an empty list
     */
    LinkedList()
	{
		listsize = 0;
		front = back = NULL;
	}

	/**
     * Copy constructor
     * You may utilize the ``addAll'' function from Utility.h
     */
    LinkedList(const LinkedList<T> &c)
	{
		listsize = 0;
		front = back = NULL;
		addAll(*this, c);
	}
	
    /**
     * Assignment operator
     * You may utilize the ``addAll'' function from Utility.h
     */
    LinkedList<T>& operator=(const LinkedList<T> &c) 
	{
		clear();
		addAll(*this, c);
		return *this;
	}

    /**
     * Constructs a list containing the elements of the specified
     * collection, in the order they are returned by the collection's
     * const iterator.
     * You may utilize the ``addAll'' function from Utility.h
     */
    template <class C> LinkedList(const C& c)
	{
		listsize = 0;
		front = back = NULL;
		addAll(*this, c);
	}
		
    /**
     * Destructor
     */
    ~LinkedList()
	{
		clear();
	}

    /**
     * Inserts the specified element at the specified position in
     * this list.
     * O(n)
     * @throw IndexOutOfBound exception when index is out of bound
     */
	void add(int index, const T& elem)
	{
		if (index < 0 || index > listsize) throw IndexOutOfBound();
		if (index == 0) addFirst(elem);
		else
		{
			Node* x = front;
			Node* t = new Node(elem);
			for (int i = 0; i < index-1; ++i)
			{
				x = x->next;
			}
			t->pre = x;
			t->next = x->next;
			if(x->next) x->next->pre = t;
			x->next = t;
			++listsize;
		}
	}

    /**
     * Appends the specified element to the end of this list.
     * O(1).
     * Always returns true;
     */
    bool add(const T& elem) 
	{
		if (!back)
		{
			front = back = new Node(elem);
		}
		else
		{
			Node* t = new Node(elem);
			t->pre = back;
 			back->next= t;
			back = t;
		}
		++listsize;
		return true;
	}

    /**
	* Inserts the specified element at the beginning of this list.
	* O(1).
	*/
	void addFirst(const T& elem) 
	{
		if (back == NULL)
		{
			front = back = new Node(elem);
		}
		else
		{
			Node* t = new Node(elem);
			t->next = front;
			front->pre = t;
			front = t;
		}
		++listsize;
	}

    /**
     * Removes all of the elements from this list.
     * O(n).
     */
	void clear()
	{
		int size = listsize;
		for (int i = 0; i < size; ++i)
		{
			Node* t = front;
			front = t->next;
			remove_node(t);
		}
		listsize = 0;
		front = back = NULL;
	}

    /**
     * Returns true if this list contains the specified element.
     * O(n).
     */
    bool contains(const T& elem) const
	{
		for (Node * t = front; t; t = t->next)
		{
			if (t->data == elem) return true;
		}
		return false;
	}

    /**
     * Returns a reference to the element at the specified position.
     * O(n).
     * @throw IndexOutOfBound exception when index is out of bound
     */
    T& get(int index)
	{
		if (index < 0 || index >= listsize) throw IndexOutOfBound();
		Node* t = front;
		for (int i = 0; i < index; ++i)
		{
			t = t->next;
		}
		return t->data;
	}

    /**
     * Returns a const reference to the element at the specified position.
     * O(n).
     * @throw IndexOutOfBound
     */
	const T& get(int index) const
	{
		if (index < 0 || index >= listsize) throw IndexOutOfBound();
		Node* t = front;
		for (int i = 0; i < index; ++i)
		{
			t = t->next;
		}
		return t->data;
	}

    /**
     * Returns a reference to the first element.
     * O(1).
     * @throw ElementNotExist
     */
    T& getFirst()
	{
		if (front == NULL) throw ElementNotExist();
		return front->data;
	}

    /**
     * Returns a const reference to the first element.
     * O(1).
     * @throw ElementNotExist
     */
    const T& getFirst() const
	{
		if (front == NULL) throw ElementNotExist();
		return front->data;
	}

    /**
     * Returns a reference to the last element.
     * O(1).
     * @throw ElementNotExist
     */
    T& getLast()
	{
		if (back == NULL) throw ElementNotExist();
		return back->data;
	}

    /**
     * Returns a const reference to the last element.
     * O(1).
     * @throw ElementNotExist
     */
    const T& getLast() const
	{
		if (back == NULL) throw ElementNotExist();
		return back->data;
	}	

    /**
     * Returns the index of the first occurrence of the specified element
     * O(1).
     * in this list, or -1 if this list does not contain the element.
     */
    int indexOf(const T& elem) const
	{
		Node* t = front;
		for (int i = 0; i < listsize; ++i)
		{
			if (t->data == elem) return i;
			t = t->next;
		}
		return -1;
	}

    /**
     * Returns true if this list contains no elements.
     * O(1).
     */
	bool isEmpty() const
	{
		if (front == NULL) return true;
		return false;
	}

    /**
     * Returns an iterator
     * O(1).
     */
    Iterator iterator()
	{
		return Iterator(this);
	}

    /**
     * Returns an const iterator
     * O(1).
     */
    ConstIterator constIterator() const
	{
		return ConstIterator(this);
	}

    /**
     * Removes the element at the specified position in this list.
     * O(n).
     * @throw IndexOutOfBound exception when index is out of bound
     */
    T removeIndex(int index)
	{
		if (index < 0 || index >= listsize) throw IndexOutOfBound();
		Node* t = front;
		for (int i = 0; i < index; ++i)
		{
			t = t->next;
		}
		remove_node(t);
	}

    /**
     * Removes the first occurrence of the specified element from this
     * O(n).
     * list, if it is present.
     */
    bool remove(const T& elem) 
	{
		for (Node * t = front; t; t = t->next)
		{
			if (t->data == elem)
			{
				remove_node(t);
				return true;
			}
		}
		return false;
	}

    /**
     * Removes and returns the first element from this list.
     * O(n).
     * @throw ElementNotExist
     */
    T removeFirst()
	{
		if (front == NULL) throw ElementNotExist();
		T d = front->data;
		remove_node(front);
		return d;
	}

    /**
     * Removes and returns the last element from this list.
     * O(n).
     * @throw ElementNotExist
     */
    T removeLast()
	{
		if (back == NULL) throw ElementNotExist();
		T d = back->data;
		remove_node(back);
		return d;
	}

    /**
     * Replaces the element at the specified position in this list with
     * the specified element.
     * O(n).
     * @throw IndexOutOfBound exception when index is out of bound
     */
    T set(int index, const T& elem)
	{
		if (index < 0 || index >= listsize) throw IndexOutOfBound();
		Node* t = front;
		for (int i = 0; i < index; ++i)
		{
			t = t->next;
		}
		return t->data = elem;
	}

    /**
     * Returns the number of elements in this list.
     */
    int size() const
	{
		return listsize;
	}

    /**
     * Returns a view of the portion of this list between the specified
     * fromIndex, inclusive, and toIndex, exclusive.
     * O(n).
     */
    LinkedList<T> subList(int fromIndex, int toIndex)
	{
		if (fromIndex < 0 || toIndex > listsize || fromIndex >= toIndex) throw IndexOutOfBound();
		LinkedList list;
		Node* t = front;
		for (int i = 0; i < fromIndex; ++i) t = t->next;
		for (int i = fromIndex; i < toIndex; ++i) list.add(t->data);
		return list;
	}
};
#endif

