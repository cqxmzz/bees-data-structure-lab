/** @file Utility.h
 * This file declares an Entry class and 2 exception classes (IndexOutOfBound, ElementNotExist).
 * Some useful functions are also provided in this file.
 */
#include <string>

#ifndef __UTILITY_H
#define __UTILITY_H

/**
 * Adds all elements of container b into container a
 */
template<class C1, class C2>
inline void addAll(C1 &a, const C2 &b) {
    typename C2::ConstIterator iter = b.constIterator();
    while (iter.hasNext()) {
        a.add(iter.next());
    }
}

/**
 * Tests if container a contains all elements of container b
 */
template<class C1, class C2>
inline bool containsAll(const C1 &a, const C2 &b) {
    typename C2::ConstIterator iter = b.constIterator();
    while (iter.hasNext()) {
        if (!a.contains(iter.next())) {
            return false;
        }
    }
    return true;
}

/**
 * Compares lexicographical order.
 * Utilizing this function, you can easily overload the `<' operator
 * for your containers, so TreeSet< ArrayList<int> > can be defined.
 */
template<class C1, class C2>
inline int compareTo(const C1 &a, const C2 &b) {
    typename C1::ConstIterator iter1 = a.constIterator();
    typename C2::ConstIterator iter2 = a.constIterator();
    while (iter1.hasNext() && iter2.hasNext()) {
        int x = a.next(), y = b.next();
        if (x != y) {
            return x < y ? -1 : 1;
        }
    }
    if (iter2.hasNext()) return -1;
    if (iter1.hasNext()) return 1;
    return 0;
}

/**
 * Thrown when an index is out of range
 * For example, list.get(10); while list.size() == 5 raises this exception.
 */
class IndexOutOfBound {
public:
    IndexOutOfBound() {}
    IndexOutOfBound(std::string msg) : msg(msg) {}
    std::string getMessage() const { return msg; }
private:
    std::string msg;
};

/**
 * Thrown when an required element does not exist
 * For example, iter.next(); while iter.hasNext() == false
 */
class ElementNotExist {
public: ElementNotExist() {}
    ElementNotExist(std::string msg) : msg(msg) {}
    std::string getMessage() const { return msg; }
private:
    std::string msg;
};

/**
 * Map.Entry, a key-value pair.
 */
template <class K, class V> class Entry {
public:
	const K key;
	V value;

    /**
     * Constructor
     */
    Entry(const K& k, const V& v) : key(k), value(v) {}
	
	bool operator==(const Entry<K, V> &entry) const 
	{
		if (key == entry.key && value == entry.value) return true;
		else return false;
	}
};
#endif

