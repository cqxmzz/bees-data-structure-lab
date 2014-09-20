/** @file */
#ifndef __HASHSET_H
#define __HASHSET_H

#include "Utility.h"
#include "LinkedList.h"
#include "TreeSet.h"
/**
 * A HashSet holds elements using a hash table, providing facilities
 * to insert, remove an element into the container and search an
 * element within the container efficiently.
 *
 * We don't require an order in the iteration, but you should
 * guarantee all elements will be iterated.
 *
 * Template argument H are used to specify the hash function.
 * H should be a class with a static function named ``hashcode'',
 * which takes a parameter of type T and returns a value of type int.
 * For example, the following class
 * @code
 *      class Hashint {
 *      public:
 *          static int hashcode(int obj) {
 *              return obj;
 *          }
 *      };
 * @endcode
 * specifies an hash function for integers. Then we can define:
 * @code
 *      HashSet<int, Hashint> hash;
 * @endcode
 */

template <class T, class H> class HashSet 
{
private:
	int cap;
	TreeSet<T>* table;
	int hashSize;

public:
	class ConstIterator 
	{
	private:
		const HashSet* set;
		int n;
		typename TreeSet<T>::ConstIterator it;
	public:
		ConstIterator(const HashSet* s)
		{
			set = s;
			n = 0;
			it = s->table[0].constIterator();
		}

        /**
         * Returns true if the iteration has more elements.
         * O(n) for iterating through the container
         */
        bool hasNext() 
		{
			if (it.hasNext()) return true;
			for (int i = n + 1; i < set->cap; ++i)
			{
				if (!set->table[i].isEmpty()) return true;
			}
			return false;
		}

        /**
         * Returns the next element in the iteration.
         * O(n) for iterating through the container.
         * @throw ElementNotExist
         */
        const T& next() 
		{
			if (!hasNext()) throw ElementNotExist();
			if (it.hasNext()) return it.next();
			for (n = n + 1; n < set->cap; ++n)
			{
				if (!set->table[n].isEmpty())
				{
					it = set->table[n].constIterator();
					return it.next();
				}
			}
		}		
    };
	
    class Iterator 
	{
	private:
		HashSet* set;
		int n;
		typename TreeSet<T>::Iterator it;
	public:
		Iterator(HashSet* s)
		{
			set = s;
			n = 0;
			it = s->table[0].iterator();
		}

        /**
         * Returns true if the iteration has more elements.
         * O(n) for iterating through the container.
         */
        bool hasNext() 
		{
			if (it.hasNext()) return true;
			for (int i = n + 1; i < set->cap; ++i)
			{
				if (!set->table[i].isEmpty()) return true;
			}
			return false;
		}

        /**
         * Returns the next element in the iteration.
         * O(n) for iterating through the container
         * @throw ElementNotExist
         */
        const T& next() 
		{
			if (!hasNext()) throw ElementNotExist();
			if (it.hasNext()) return it.next();
			for (n = n + 1; n < set->cap; ++n)
			{
				if (!set->table[n].isEmpty())
				{
					it = set->table[n].iterator();
					return it.next();
				}
			}
		}

        /**
         * Removes from the underlying collection the last element
         * returned by the iterator.
         * O(1)
         * @throw ElementNotExist
         */
        void remove() 
		{
			if (it.Removed()) throw ElementNotExist();
			it.remove();
			set->hashSize--;
		}
    };

    /**
     * Constructs a empty set with your own default capacity
     */
    HashSet() 
	{
		hashSize = 0;
		cap = 1000;
		table = new TreeSet<T>[cap];
	}

    /**
     * Destructor
     */
    ~HashSet() 
	{
		clear();
	}

    /**
     * Copy constructor
     */
    HashSet(const HashSet &c) 
	{
		hashSize = 0;
		cap = c.cap;
		table = new TreeSet<T>[cap];
		addAll(*this, c);
	}

    /**
     * Assignment operator
     */
    HashSet& operator=(const HashSet &c) 
	{
		clear();
		cap = c.cap;
		table = new TreeSet<T>[cap];
		addAll(*this, c);
		return *this;
	}

    /**
     * Constructs a new set containing the elements in the specified
     * collection.
     */
    template<class C> explicit
	HashSet(const C& c)
	{
		hashSize = 0;
		cap = c.cap;
		table = new TreeSet<T>[cap];
		addAll(*this, c);
	}

    /**
     * Constructs a new, empty set; the backing HashMap instance has the
     * specified capacity
     */
    HashSet(int capacity)
	{
		hashSize = 0;
		cap = capacity;
		table = new TreeSet<T>[cap];
	}

    /**
     * Adds the specified element to this set if it is not already present.
     * Returns false if element is previously in the set.
     * O(1) for average
     */
    bool add(const T& elem) 
	{
		hashSize++;
		return table[H::hashcode(elem) % cap].add(elem);
	}

    /**
     * Removes all of the elements from this set.
	 */
	void clear()
	{
		hashSize = 0;
		for (int i = 0; i < cap; ++i)
			table[i].clear();
	}

    /**
     * Returns true if this set contains the specified element.
     * O(1) for average
     */
    bool contains(const T& elem) const 
	{
		return table[H::hashcode(elem) % cap].contains(elem);
	}

    /**
     * Returns true if this set contains no elements.
     * O(1)
     */
    bool isEmpty() const 
	{
		if (hashSize) return false;
		return true;
	}

    /**
     * Returns an iterator over the elements in this set.
     */
    Iterator iterator()
	{
		return Iterator(this);
	}

    /**
     * Returns an const iterator over the elements in this set.
     */
    ConstIterator constIterator() const
	{
		return ConstIterator(this);
	}

    /**
     * Removes the specified element from this set if it is present.
     * O(1) for average
     */
    bool remove(const T& elem)
	{
		hashSize--;
		return table[H::hashcode(elem) % cap].remove(elem);
	}

    /**
     * Returns the number of elements in this set (its cardinality).
     * O(1)
     */
    int size() const
	{
		return hashSize;
	}
};

#endif

