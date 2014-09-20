/** @file */

#ifndef __HASHMAP_H
#define __HASHMAP_H

#include "Utility.h"
#include "TreeMap.h"

/**
 * HashMap is a map implemented by hashing. Also, the 'capacity' here means the
 * number of buckets in your inner implemention, not the current number of the
 * elements.
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
 *      HashMap<int, int, Hashint> hash;
 * @endcode
 *
 * We don't require an order in the iteration, but you should
 * guarantee all elements will be iterated.
 */
template <class K, class V, class H>
class HashMap
{
private:
	int cap;
	TreeMap<K, V>* table;
	int hashSize;
public:
    class ConstIterator
    {
	private:
		const HashMap* map;
		int n;
		typename TreeMap<K, V>::ConstIterator it;
    public:
		ConstIterator(const HashMap* m)
		{
			map = m;
			n = 0;
			it = m->table[0].constIterator();
		}

        /**
         * Returns true if the iteration has more elements.
         * O(n) for iterating through the container.
         */
        bool hasNext()
		{
			if (it.hasNext()) return true;
			for (int i = n + 1; i < map->cap; ++i)
			{
				if (!map->table[i].isEmpty()) return true;
			}
			return false;
		}

        /**
         * Returns the next element in the iteration.
         * O(n) for iterating through the container.
         * @throw ElementNotExist
         */
        const Entry<K, V>& next()
		{
			if (!hasNext()) throw ElementNotExist();
			if (it.hasNext()) return it.next();
			for (n = n + 1; n < map->cap; ++n)
			{
				if (!map->table[n].isEmpty())
				{
					it = map->table[n].constIterator();
					return it.next();
				}
			}
		}
    };

    class Iterator
    {
	private:
		HashMap* map;
		int n;
		typename TreeMap<K, V>::Iterator it;
    public:
		Iterator(HashMap* m)
		{
			map = m;
			n = 0;
			it = m->table[0].iterator();
		}

        /**
         * Returns true if the iteration has more elements.
         * O(n) for iterating through the container.
         */
        bool hasNext()
		{
			if (it.hasNext()) return true;
			for (int i = n + 1; i < map->cap; ++i)
			{
				if (!map->table[i].isEmpty()) return true;
			}
			return false;
		}

        /**
         * Returns a const reference the next element in the iteration.
         * O(n) for iterating through the container.
         * @throw ElementNotExist
         */
        Entry<K, V>& next()
		{
			if (!hasNext()) throw ElementNotExist();
			if (it.hasNext()) return it.next();
			for (n = n + 1; n < map->cap; ++n)
			{
				if (!map->table[n].isEmpty())
				{
					it = map->table[n].iterator();
					return it.next();
				}
			}
		}

        /**
         * Removes from the underlying collection the last element returned by the iterator (optional operation).
         * O(1)
         * @throw ElementNotExist
         */
        void remove()
		{
			if (it.Removed()) throw ElementNotExist();
			it.remove();
			map->hashSize--;
		}
    };

    /**
     * Constructs an empty list with an initial capacity.
     * You can construct it with your own initial capacity.
     */
    HashMap()
	{
		hashSize = 0;
		cap = 10000;
		table = new TreeMap<K, V>[cap];
	}

    /**
     * Copy-constructor
     */
    HashMap(const HashMap& x)
	{
		hashSize = 0;
		cap = x.cap;
		table = new TreeMap<K, V>[cap];
		addAll(*this, x);
	}

    /**
     * Constructs an empty HashMap with the specified initial capacity
     */
    HashMap(int initialCapacity)
	{
		hashSize = 0;
		cap = initialCapacity;
		table = new TreeMap<K, V>[cap];
	}

    /**
     * Constructs a new HashMap with the same mappings as the specified Map.
     */
    template <class E2>
    explicit HashMap(const E2 &m)
	{
		hashSize = 0;
		cap = m.cap;
		table = new TreeMap<K, V>[cap];
		addAll(*this, m);
	}

    /**
     * assignment operator
     */
    HashMap& operator=(const HashMap& x)
	{
		clear();
		cap = x.cap;
		table = new TreeMap<K, V>[cap];
		addAll(*this, x);
		return *this;
	}

    /**
     * destructor
     */
    ~HashMap()
	{
		clear();
	}

    /**
     * Returns an iterator over the elements in this map in proper sequence.
     */
    Iterator iterator()
	{
		return Iterator(this);
	}

    /**
     * Returns an CONST iterator over the elements in this map in proper sequence.
     */
    ConstIterator constIterator() const
	{
		return ConstIterator(this);
	}

    /**
     * Removes all of the mappings from this map.
     */
    void clear()
	{
		hashSize = 0;
		for (int i = 0; i < cap; ++i)
			table[i].clear();
	}
    /**
     * Returns true if this map contains a mapping for the specified key.
     * O(1) for average
     */
	bool containsKey(const K& key) const 
	{
		return table[H::hashcode(key) % cap].containsKey(key);
	}

    /**
     * Returns true if this map maps one or more keys to the specified value.
     * O(n)
     */
    bool containsValue(const V& value) const
	{
		for (int i = 0; i < cap; ++i)
		if (table[i].containsValue(value)) return true;
		return false;
	}

    /**
     * Returns a reference to the value to which the specified key is mapped.
     * O(1) for average
     * @throw ElementNotExist
     */
    V& get(const K& key) 
	{
		return table[H::hashcode(key) % cap].get(key);
	}

    /**
     * Returns a const reference to the value to which the specified key is mapped.
     * O(1) for average
     * @throw ElementNotExist
     */
    const V& get(const K& key) const
	{
		return table[H::hashcode(key) % cap].get(key); 
	}

    /**
     * Returns true if this map contains no key-value mappings.
     * O(1)
     */
    bool isEmpty() const 
	{
		if (hashSize) return false;
		return true;
	}

    /**
     * Associates the specified value with the specified key in this map.
     * Returns the previous value, if not exist, a value returned by the default-constructor.
     * O(1)
     */
	V put(const K& key, const V& value)
	{
		if (!table[H::hashcode(key) % cap].containsValue(value)) hashSize++;
		return table[H::hashcode(key) % cap].put(key, value);
 	}

	void add(Entry<K, V> entry)
	{
		table[H::hashcode(entry.key) % cap].add(entry);
		hashSize++;
	}

    /**
     * Removes the mapping for the specified key from this map if present.
     * Returns the previous value.
     * O(1) for average
     * @throw ElementNotExist
     */
    V remove(const K& key)
	{
		hashSize--;
		return table[H::hashcode(key) % cap].remove(key);
	}

    /**
     * Returns the number of key-value mappings in this map.
     * O(1)
     */
    int size() const 
	{
		return hashSize;
	}
};
#endif
