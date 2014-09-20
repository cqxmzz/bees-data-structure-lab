/** @file */
#ifndef __ARRAYLIST_H
#define __ARRAYLIST_H

#include "Utility.h"

/**
 * The ArrayList is just like vector in C++.
 * You should know that "capacity" here doesn't mean how many elements are now in this list, it means
 * the length of the array of your inner implemention
 * For example, even if the capacity is 10, the method "isEmpty()" may still return true.
 *
 * The iterator iterates in the order of the elements being loaded into this list
 */
template <class E>
class ArrayList
{
private:
	E* arr;
	int length, capacity;
	void doubleSpace()
	{
		E *arr2 = new E[capacity * 2];
		for (int i = 0;i < length;i++) arr2[i] = arr[i];
		delete []arr;
		arr = arr2;
		capacity = capacity * 2;
	}
public:
    class ConstIterator
    {
	private:
		int p;
		const ArrayList* list;
	public:
		ConstIterator(const ArrayList* x)
		{
			p = 0;
			list = x;
		}

        /**
         * Returns true if the iteration has more elements.
         * O(1)
         */
        bool hasNext() 
		{
			if (p < list->length) return true;
			return false;
		}

        /**
         * Returns the next element in the iteration.
         * O(1)
         * @throw ElementNotExist
         */
        const E& next() 
		{
			if (p >= list->length) throw ElementNotExist();
			return list->arr[p++];
		}
    };

    class Iterator
    {
	private:
		int p;
		ArrayList* list;
		bool removed;
    public:
		Iterator(ArrayList* x)
		{
			p = 0;
			list = x;
			removed = true;
		}

        /**
         * Returns true if the iteration has more elements.
         * O(1)
         */
		bool hasNext() 
		{
			if (p < list->length) return true;
			return false;
		}

        /**
         * Returns the next element in the iteration.
         * O(1)
         * @throw ElementNotExist
         */
        E& next() 
		{
			if (p >= list->length) throw ElementNotExist();
			removed = false;
			return list->arr[p++];
		}

        /**
         * Removes from the underlying collection the last element returned by the iterator (optional operation).
         * O(1)
         * @throw ElementNotExist
         */
        void remove() 
		{
			if (p == 0 || p > list->length || removed) throw ElementNotExist();
			for (int i = p - 1; i < list->length - 1;i++)
				list->arr[i] = list->arr[i + 1];
			p--;
			list->length--;
			removed = true;
		}
    };

    /**
     * Constructs an empty list with an initial capacity of ten.
     */
	ArrayList() 
	{
		arr = new E[10];
		length = 0;
		capacity = 10;
	}

    /**
     * Constructs a list containing the elements of the specified collection, in
     * the order they are returned by the collection's iterator.
     */
    template <class E2>
    explicit ArrayList(const E2& x) 
	{
		cap = 10;
		length = 0;
		a = new E[10];
		addAll(*this, x);
	}

    /**
     * Constructs an empty list with the specified initial capacity.
     */
	ArrayList(int initialCapacity) 
	{
		if (initialCapacity <= 0) throw IndexOutOfBound();
		arr = new E[initialCapacity];
		length = 0;
		capacity = initialCapacity;
	}

    /**
     * Destructor
     */
    ~ArrayList() 
	{
		delete []arr;
	}

    /**
     * Assignment operator
     */
    ArrayList& operator=(const ArrayList& x) 
	{
		clear();
		addAll(*this, x);
		return *this;
	}

    /**
     * Copy-constructor
     */
    ArrayList(const ArrayList& x) 
	{
		capacity = 10;
		length = 0;
		arr = new E[10];
		addAll(*this, x);
	}

    /**
     * Returns an iterator over the elements in this list in proper sequence.
     */
    Iterator iterator() 
	{
		return Iterator(this);
	}

    /**
     * Returns an CONST iterator over the elements in this list in proper sequence.
     */
	ConstIterator constIterator() const 
	{
		return ConstIterator(this);
	}

    /**
     * Appends the specified element to the end of this list.
     * O(1)
     */
    bool add(const E& e) 
	{
		if (length == capacity) doubleSpace();
		arr[length++] = e;
		return true;
	}

    /**
     * Inserts the specified element at the specified position in this list.
     * The range of index is [0, size].
     * O(n)
     * @throw IndexOutOfBound
     */
    void add(int index, const E& element) 
	{
		if (index < 0 || index > length) throw IndexOutOfBound();
		if (length == capacity) doubleSpace();
		length++;
		for (int i = length; i > index; --i)
		{
			arr[i] = arr[i-1];
		}
		arr[index] = element;
	}

    /**
     * Removes all of the elements from this list.
     */
    void clear() 
	{
		length = 0;
	}

    /**
     * Returns true if this list contains the specified element.
     * O(n)
     */
    bool contains(const E& e) const 
	{
		for (int i = 0; i < length; ++i)
		{
			if (arr[i] == e) return true;
		}
		return false;
	}

    /**
     * Increases the capacity of this ArrayList instance, if necessary, to ensure that it can hold at least the number of elements specified by the minimum capacity argument.
     */
    void ensureCapacity(int minCapacity) 
	{
		while(capacity <= minCapacity)
			doubleSpace();
	}

    /**
     * Returns a reference to the element at the specified position in this list.
     * O(1)
     * @throw IndexOutOfBound
     */
    E& get(int index)
	{
		if (index < 0 || index >= length) throw IndexOutOfBound();
		return arr[index];
	}

    /**
     * Returns a const reference to the element at the specified position in this list.
     * O(1)
     * @throw IndexOutOfBound
     */
    const E& get(int index) const 
	{
		if (index < 0 || index >= length) throw IndexOutOfBound();
		return arr[index];
	}

    /**
     * Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
     * O(n)
     */
    int indexOf(const E& e) const
	{
		for (int i = 0; i < length; ++i)
		{
			if (arr[i] == e) return i;
		}
		return -1;
	}

    /**
     * Returns true if this list contains no elements.
     * O(1)
     */
    bool isEmpty() const 
	{
		if (length == 0) return true;
		return false;
	}

    /**
     * Returns the index of the last occurrence of the specified element in this list, or -1 if this list does not contain the element.
     * O(n)
     */
    int lastIndexOf(const E& e) const 
	{
		for (int i = length - 1; i >= 0; --i)
		{
			if (arr[i] == e) return i;
		}
		return -1;
	}

    /**
     * Removes the element at the specified position in this list.
     * Returns the element that was removed from the list.
     * O(n)
     * @throw IndexOutOfBound
     */
    E removeIndex(int index) 
	{
		if (index < 0 || index >= length) throw IndexOutOfBound();
		E e = arr[index];
		for (int i = index; i < length - 1; ++i)
		{
			arr[i] = arr[i+1];
		}
		length--;
		return e;
	}

    /**
     * Removes the first occurrence of the specified element from this list, if it is present.
     * O(n)
     */
	bool remove(const E& e) 
	{
		int tmp = indexOf(e);
		if (e >= 0)
		{
			removeIndex(tmp);
			return true;
		}
		return false;
	}

    /**
     * Removes from this list all of the elements whose index is between fromIndex, inclusive, and toIndex, exclusive.
     * O(n)
     * @throw IndexOutOfBound
     */
    void removeRange(int fromIndex, int toIndex) 
	{
		if (fromIndex < 0 || toIndex > length || fromIndex >= toIndex) throw IndexOutOfBound();
		for (int i = fromIndex; i < length - toIndex + fromIndex; i++) 
			arr[i] = arr[i + toIndex - fromIndex];
		length -= (toIndex - fromIndex);
	}

    /**
     * Replaces the element at the specified position in this list with the specified element.
     * Returns the element previously at the specified position.
     * O(1)
     * @throw IndexOutOfBound
     */
    E set(int index, const E& element) 
	{
		if (index < 0 || index >= length) throw IndexOutOfBound();
		E tmp = arr[index];
		arr[index] = element;
		return tmp;
	}

    /**
     * Returns the number of elements in this list.
     * O(1)
     */
    int size() const 
	{
		return length;
	}

    /**
     * Returns a view of the portion of this list between the specified fromIndex, inclusive, and toIndex, exclusive.
     * O(n)
     * @throw IndexOutOfBound
     */
    ArrayList subList(int fromIndex, int toIndex) const 
	{
		if (fromIndex < 0 || toIndex > length || fromIndex >= toIndex) throw IndexOutOfBound();
		ArrayList sub;
		for (int i = fromIndex;i < toIndex;i++)
			sub.add(arr[i]);
		return sub;
	}
};
#endif

