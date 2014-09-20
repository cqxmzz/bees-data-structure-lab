#include <hash_set>
#include <hash_map>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <list>
#include <set>
#include <map>
#include "ArrayList.h"
#include "LinkedList.h"
#include "TreeSet.h"
#include "TreeMap.h"
#include "HashSet.h"
#include "HashMap.h"

using namespace std;

void testArrayList(int n)
{
	cout << "[[...testing ArrayList...]]" << endl << endl;

	/****************/
	cout << "ArrayList()" << endl;
	ArrayList<int> * arr1 = new ArrayList<int>;
	if (arr1 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "add(const E & elem)" << endl;
	for (int i = 0; i < n; ++i)
		arr1->add(i);
	if (arr1->size() == n)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "size()" << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "ArrayList(const ArrayList &)" << endl;
	ArrayList<int> * arr2 = new ArrayList<int>(*arr1);
	if (arr2 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "get(int index)" << endl;
	for (int i = 0; i < n; ++i)
		if (arr1->get(i) != i)
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "indexOf(const E &)" << endl;
	for (int i = 0; i < n; ++i)
		if (arr1->indexOf(i) != i)
			cout << "[[Fail]]" << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "contains(const E& e)" << endl;
	if (arr1->contains(n - 1) && !arr1->contains(n))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "remove(const E &)" << endl;
	arr1->remove(n - 1);
	if (arr1->size() == n - 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "add(int index, const E &)" << endl;
	arr1->add(n - 1, n - 1);
	if (arr1->size() == n)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "set(int index, const E &)" << endl;
	arr1->set(n - 1, 0);
	if (arr1->get(n - 1) == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "removeIndex(int index)" << endl;
	arr1->removeIndex(n - 1);
	if (arr1->size() == n - 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "removeRange(int fromIndex, int toIndex)" << endl;
	arr1->removeRange(1, n - 1);
	if (arr1->size() == 1 && arr1->get(0) == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "clear()" << endl;
	arr1->clear();
	if (arr1->size() == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "isEmpty()" << endl;
	if (arr1->isEmpty())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "iterator()" << endl;
	ArrayList<int>::Iterator iter = arr2->iterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "Iterator::hasNext()" << endl;
	if (iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "Iterator::Next()" << endl;
	if (iter.next() == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "Iterator::remove()" << endl;
	iter.remove();
	if (arr2->size() == n - 1 && iter.next() == 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "constiterator()" << endl;
	ArrayList<int>::ConstIterator const_iter = arr2->constIterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "ConstIterator::hasNext()" << endl;
	if (const_iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "ConstIterator::Next()" << endl;
	if (const_iter.next() == 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "arrayList(int initialCapacity)" << endl;
	ArrayList<int> * arr3 = new ArrayList<int>(n);
	if (arr3 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "ensureCapacity(int cap)" << endl;
	arr3->ensureCapacity(2 * n);
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "add(int index, const E& e)" << endl;
	for (int i = 0; i < n; ++i) arr3->add(i, i);
	if (arr3->size() == n) cout << "[[OK]]" << endl << endl;
	else cout << "**Fail**" << endl << endl;

	/****************/
	cout << "subList(int fromIndex, int toIndex)" << endl;
	ArrayList<int>  arr4 = arr3->subList(1, n-1);
	if (arr4.size() != n-2)
		cout << "**Fail**" << endl << endl;
	else
		cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "operator=(const ArrayList<E> &c)" << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "lastIndexOf(const E& e)" << endl;
	if (arr4.lastIndexOf(1) == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;
}

void testLinkedList(int n)
{
	cout << "[[...testing LinkedList...]]" << endl << endl;

	/****************/
	cout << "LinkedList()" << endl;
	LinkedList<int> * list1 = new LinkedList<int>;
	if (list1 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "add(const E & elem)" << endl;
	for (int i = 0; i < n; ++i)
		list1->add(i);
	if (list1->size() == n)
		if (list1->size() == n)
		{
			cout << "[[OK]]" << endl << endl;
			cout << "size()" << endl;
			cout << "[[OK]]" << endl << endl;
		}
	else cout << "**Fail**" << endl << endl;

	/****************/
	cout << "LinkedList(const LinkedList &)" << endl;
	LinkedList<int> * list2 = new LinkedList<int>(*list1);
	if (list2 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "get(int index)" << endl;
	for (int i = 0; i < n; ++i)
		if (list1->get(i) != i)
		{
			cout << "**Fail**" << endl << endl;
			break;
		}
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "getFirst()" << endl;
	if (list1->getFirst() == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "getLast()" << endl;
	if (list1->getLast() == n - 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "indexOf(const E &)" << endl;
	for (int i = 0; i < n; ++i)
		if (list1->indexOf(i) != i)
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "contains(const E& e)" << endl;
	if (list1->contains(n - 1) && !list1->contains(n))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "remove(const E &)" << endl;
	list1->remove(n / 2);
	if (list1->size() == n - 1 && list1->get(n / 2) == n / 2 + 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "add(int index, const E &)" << endl;
	list1->add(n / 2, n / 2);
	if (list1->size() == n && list1->get(n / 2) == n / 2)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "set(int index, const E &)" << endl;
	list1->set(n - 1, 0);
	if (list1->get(n - 1) == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "removeIndex(int index)" << endl;
	list1->removeIndex(n - 1);
	if (list1->size() == n - 1 && list1->getLast() == n - 2)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "removeFirst()" << endl;
	list1->removeFirst();
	if (list1->size() == n - 2 && list1->getFirst() == 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "removeLast()" << endl;
	list1->removeLast();
	if (list1->size() == n - 3 && list1->getLast() == n - 3)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "clear()" << endl;
	list1->clear();
	if (list1->size() == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "isEmpty()" << endl;
	if (list1->isEmpty())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "iterator()" << endl;
	LinkedList<int>::Iterator iter = list2->iterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "Iterator::hasNext()" << endl;
	if (iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	cout << "Iterator::Next()" << endl;
	if (iter.next() == 0) cout << "[[OK]]" << endl << endl;
	else cout << "**Fail**" << endl << endl;

	/****************/
	cout << "Iterator::remove()" << endl;
	iter.remove();
	if (list2->size() == n - 1 && iter.next() == 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "constiterator()" << endl;
	LinkedList<int>::ConstIterator const_iter = list2->constIterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "ConstIterator::hasNext()" << endl;
	if (const_iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "ConstIterator::Next()" << endl;
	if (const_iter.next() == 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "add(int index, const E& e)" << endl;
	for (int i = 0; i < n; ++i)
		list1->add(i, i);
	if (list1->size() == n)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "subList(int fromIndex, int toIndex)" << endl;
	LinkedList<int>  list3 = list1->subList(1, n-1);
	if (list3.size() != n-2)
		cout << "**Fail**" << endl << endl;
	else
		cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "operator=(const ArrayList<E> &c)" << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "addFirst(const E& e)" << endl;
	list3.addFirst(0);
	if (list3.size() != n-1 || list3.getFirst() != 0)
		cout << "**Fail**" << endl << endl;
	else
		cout << "[[OK]]" << endl << endl;
}

void testTreeSet(int n)
{
	cout << "[[...testing TreeSet...]]" << endl << endl;

	/****************/
	cout << "TreeSet()" << endl;
	TreeSet<int> * set1 = new TreeSet<int>;
	if (set1 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "add(const E & elem)" << endl;
	for (int i = 0; i < n; ++i) set1->add(i);
	if (set1->size() == n)
	{
		cout << "[[OK]]" << endl << endl;
		cout << "size()" << endl;
		cout << "[[OK]]" << endl << endl;
	}
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "TreeSet(const LinkedList &)" << endl;
	TreeSet<int> * set2 = new TreeSet<int>(*set1);
	if (set2 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "contains(const E& e)" << endl;
	for (int i = 0; i < n; ++i)
		if (!set1->contains(i))
			cout << "**Fail**" << endl << endl;
	if (set1->contains(n))
		cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "first()" << endl;
	if (set1->first() == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "last()" << endl;
	if (set1->last() == n - 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "remove(const E&)" << endl;
	for (int i = 0; i < n; ++i)
	{
		set1->remove(i);
		if (set1->contains(i))
			cout << "**Fail**" << endl << endl;
	}
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "operator=(const TreeSet& x)" << endl;
	*set1 = *set2;
	for (int i = 0; i < n; ++i)
		if (!set1->contains(i))
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "clear()" << endl;
	set1->clear();
	if (set1->size() != 0)
		cout << "**Fail**" << endl << endl;
	for (int i = 0; i < n; ++i)
		if (set1->contains(i))
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "isEmpty()" << endl;
	if (set1->isEmpty())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	cout << "iterator()" << endl;
	TreeSet<int>::Iterator iter = set2->iterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "Iterator::hasNext()" << endl;
	if (iter.hasNext()) cout << "[[OK]]" << endl << endl;
	else cout << "**Fail**" << endl << endl;

	/****************/
	cout << "Iterator::Next()" << endl;
	for (int i = 0; i < n; ++i)
		if (iter.next() != i)
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "Iterator::remove()" << endl;
	iter = set2->iterator();
	iter.next();
	iter.remove();
	if (set2->size() == n - 1 && iter.next() == 1 && !set2->contains(0))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "constiterator()" << endl;
	TreeSet<int>::ConstIterator const_iter = set2->constIterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "ConstIterator::hasNext()" << endl;
	if (const_iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "ConstIterator::Next()" << endl;
	if (const_iter.next() == 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

}

void testTreeMap(int n)
{
	cout << "[...testing TreeMap...]" << endl << endl;

	/****************/
	cout << "TreeMap()" << endl;
	TreeMap<int, int> * map1 = new TreeMap<int, int>;
	if (map1 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "put(const K& key, const V& value)" << endl;
	for (int i = 0; i < n; ++i)
		map1->put(i, i * 2);
	if (map1->size() == n)
	{
		cout << "[[OK]]" << endl << endl;
		cout << "size()" << endl;
		cout << "[[OK]]" << endl << endl;
	}
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "TreeMap(const LinkedList &)" << endl;
	TreeMap<int, int> * map2 = new TreeMap<int, int>(*map1);
	if (map2 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "containsKey(const K& key)" << endl;
	for (int i = 0; i < n; ++i)
		if (!map1->containsKey(i))
			cout << "**Fail**" << endl << endl;
	if (map1->containsKey(n))
		cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "containsValue(const V& value)" << endl;
	for (int i = 0; i < n; ++i)
		if (!map1->containsValue(2 * i))
			cout << "**Fail**" << endl << endl;
	if (map1->containsKey(2 * n))
		cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "firstKey()" << endl;
	if (map1->firstKey() == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "lastKey()" << endl;
	if (map1->lastKey() == n - 1)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "firstEntry()" << endl;
	if (map1->firstEntry() == Entry<int, int>(0, 0))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "lastEntry()" << endl;
	if (map1->lastEntry() == Entry<int, int>(n - 1, 2 * n - 2))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "remove(const E&)" << endl;
	for (int i = 0; i < n; ++i)
		map1->remove(i);
	for (int i = 0; i < n; ++i)
		if (map1->containsKey(i)) cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "operator=(const TreeMap &)" << endl;
	*map1 = *map2;
	for (int i = 0; i < n; ++i)
		if (!map1->containsKey(i))
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "clear()" << endl;
	map1->clear();
	if (map1->size() != 0)
		cout << "**Fail**" << endl << endl;
	for (int i = 0; i < n; ++i)
		if (map1->containsKey(i))
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "iterator()" << endl;
	TreeMap<int, int>::Iterator iter = map2->iterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "Iterator::hasNext()" << endl;
	if (iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	cout << "Iterator::Next()" << endl;
	if (iter.next() == Entry<int, int>(0, 0)) cout << "[[OK]]" << endl << endl;
	else cout << "**Fail**" << endl << endl;

	/****************/
	cout << "Iterator::remove()" << endl;
	iter.remove();
	if (map2->size() == n - 1 && iter.next() == Entry<int, int>(1, 2) && !map2->containsKey(0))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "constiterator()" << endl;
	TreeMap<int, int>::ConstIterator const_iter = map2->constIterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "ConstIterator::hasNext()" << endl;
	if (const_iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "ConstIterator::Next()" << endl;
	if (const_iter.next() == Entry<int, int>(1, 2))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

}

void testHashSet(int n)
{
	cout << "[...testing HashSet...]" << endl << endl;

	class Hashint
	{
	public:
		static int hashcode(int obj)
		{
			return obj;
		}
	};

	/****************/
	cout << "HashSet()" << endl;
	HashSet<int, Hashint> * set1 = new HashSet<int, Hashint>;
	if (set1 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "add(const E & elem)" << endl;
	for (int i = 0; i < n; ++i)
		set1->add(i);
	if (set1->size() == n)
	{
		cout << "[[OK]]" << endl << endl;
		cout << "size()" << endl;
		cout << "[[OK]]" << endl << endl;
	}
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "HashSet(const HashSet &)" << endl;
	HashSet<int, Hashint> * set2 = new HashSet<int, Hashint>(*set1);
	if (set2 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "contains(const E& e)" << endl;
	for (int i = 0; i < n; ++i)
		if (!set1->contains(i))
			cout << "**Fail**" << endl << endl;
	if (set1->contains(n))
		cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "remove(const E&)" << endl;
	for (int i = 0; i < n; ++i)
	{
		set1->remove(i);
		if (set1->contains(i))
			cout << "**Fail**" << endl << endl;
	}
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "operator=(const HashSet& x)" << endl;
	*set1 = *set2;
	for (int i = 0; i < n; ++i)
		if (!set1->contains(i))
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "clear()" << endl;
	set1->clear();
	if (set1->size() != 0)
		cout << "**Fail**" << endl << endl;
	for (int i = 0; i < n; ++i)
		if (set1->contains(i))
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "isEmpty()" << endl;
	if (set1->isEmpty())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "iterator()" << endl;
	HashSet<int, Hashint>::Iterator iter = set2->iterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "Iterator::hasNext()" << endl;
	if (iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "Iterator::Next()" << endl;
	for (int i = 0; i < n; ++i)
		iter.next();
	if (iter.hasNext())
		cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "Iterator::remove()" << endl;
	iter = set2->iterator();
	int tmp = iter.next();
	iter.remove();
	if (set2->size() == n - 1 && !set2->contains(tmp))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "constiterator()" << endl;
	HashSet<int, Hashint>::ConstIterator const_iter = set2->constIterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "ConstIterator::hasNext()" << endl;
	if (const_iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "ConstIterator::Next()" << endl;
	for (int i = 0; i < n-1; ++i)
		const_iter.next();
	if (const_iter.hasNext())
		cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;
}

void testHashMap(int n)
{
	cout << "[...testing HashMap...]" << endl;

	class Hashint
	{
	public:
		static int hashcode(int obj)
		{
			return obj;
		}
	};

	/****************/
	cout << "HashMap()" << endl;
	HashMap<int, int, Hashint> * map1 = new HashMap<int, int, Hashint>;
	if(map1 != NULL)
		cout << "[[OK]]" << endl << endl;
	else cout << "**Fail**" << endl << endl;

	/****************/
	cout << "put(const K& key, const V& value)" << endl;
	for(int i = 0; i < n; ++i)
		map1->put(i, i * 2);
	if(map1->size() == n)
	{
		cout << "[[OK]]" << endl << endl;
		cout << "size()" << endl;
		cout << "[[OK]]" << endl << endl;
	}
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "HashMap(const HashMap &)" << endl;
	HashMap<int, int, Hashint> * map2 = new HashMap<int, int, Hashint>(*map1);
	if(map2 != NULL)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "containsKey(const K& key)" << endl;
	for(int i = 0; i < n; ++i)
		if(!map1->containsKey(i))
			cout << "**Fail**" << endl << endl;
	if(map1->containsKey(n))
		cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "containsValue(const V& value)" << endl;
	for(int i = 0; i < n; ++i)
		if(!map1->containsValue(2 * i))
			cout << "**Fail**" << endl << endl;
	if(map1->containsKey(2 * n))
		cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "remove(const K& key)" << endl;
	for (int i = 0; i < n; ++i)
	{
		map1->remove(i);
		if (map1->containsKey(i))
			cout << "**Fail**" << endl << endl;
	}
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "operator=(const HashMap &)" << endl;
	*map1 = *map2;
	for(int i = 0; i < n; ++i)
		if(!map1->containsKey(i))
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "clear()" << endl;
	map1->clear();
	if(map1->size() != 0)
		cout << "**Fail**" << endl << endl;
	for(int i = 0; i < n; ++i)
		if(map1->containsKey(i))
			cout << "**Fail**" << endl << endl;
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "isEmpty()" << endl;
	if (map1->isEmpty())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "iterator()" << endl;
	HashMap<int, int, Hashint>::Iterator iter = map2->iterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "Iterator::hasNext()" << endl;
	if(iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "Iterator::Next()" << endl;
	for (int i = 0; i < n; ++i)
		iter.next();
	if(!iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "Iterator::remove()" << endl;
	iter = map2->iterator();
	int tmp = iter.next().key;
	iter.remove();
	if (map2->size() == n - 1 && !map2->containsKey(tmp))
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "constiterator()" << endl;
	HashMap<int, int, Hashint>::ConstIterator const_iter = map2->constIterator();
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "ConstIterator::hasNext()" << endl;
	if(const_iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "ConstIterator::Next()" << endl;
	for (int i = 0; i < n - 1; ++i)
		const_iter.next();
	if(!const_iter.hasNext())
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;

	/****************/
	cout << "HashMap(int initialCapacity)" << endl;
	HashMap<int, int, Hashint>* map3 = new HashMap<int, int, Hashint>(100);
	cout << "[[OK]]" << endl << endl;

	/****************/
	cout << "get(const K& k)" << endl;
	map3->put(0, 0);
	map3->put(1, 1);
	if (map3->get(0) == 0)
		cout << "[[OK]]" << endl << endl;
	else
		cout << "**Fail**" << endl << endl;
}

void performanceTestArrayList_1(int n)
{
	cout << endl << "[...testing ArrayList...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	ArrayList<int> arr;
	int time0 = clock();
	for (int i = 0; i < n; ++i)
		arr.add(i);
	int time1 = clock();
	cout << "add()\t\t\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	ArrayList<int> arr1 = arr;
	int time2 = clock();
	cout << "operator=\t\t\to(n)" << endl << "[" << time2 - time1 << "]ms" << endl;

	ArrayList<int>* arr2 = new ArrayList<int>(arr);
	int time3 = clock();
	cout << "ArrayList(const ArrayList& x)\to(n)" << endl << "[" << time3 - time2 << "]ms" << endl;

	ArrayList<int> arr3 = arr.subList(0, n);
	int time4 = clock();
	cout << "subList(0, n)\t\t\to(n)" << endl << "[" << time4 - time3 << "]ms" << endl;

	arr.indexOf(n-1);
	int time5 = clock();
	cout << "indexOf(n-1)\t\t\to(n)"<< endl << "[" << time5 - time4 << "]ms" << endl;

	arr.lastIndexOf(0);
	int time6 = clock();
	cout << "lastIndexOf(0)\t\t\to(n)"<< endl << "[" << time6 - time5 << "]ms" << endl;

	arr.contains(n-1);
	int time7 = clock();
	cout << "contains()\t\t\to(n)"<< endl << "[" << time7 - time6 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		arr.get(i);
	int time8 = clock();
	cout << "get()\t\t\t\to(n) (traverse)"<< endl << "[" << time8 - time7 << "]ms" << endl;

	ArrayList<int>::Iterator it = arr.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time9 = clock();
	cout << "Iterator::next()\t\to(n) (traverse)" << endl << "[" << time9 - time8 << "]ms" << endl;

	ArrayList<int>::Iterator it1 = arr.iterator();
	it1.next();
	it1.remove();
	int time10 = clock();
	cout << "Iterator::remove() (front)\to(n)" << endl << "[" << time10 - time9 << "]ms" << endl;

	arr1.remove(0);
	int time11 = clock();
	cout << "remove() (front)\t\to(n)" << endl << "[" << time11 - time10 << "]ms" << endl;

	arr2->remove(n - 1);
	int time12 = clock();
	cout << "remove() (back)\t\t\to(n)" << endl << "[" << time12 - time11 << "]ms" << endl;
}

void performanceTestArrayList_2(int n)
{
	cout << endl << "[...testing ArrayList...]" << endl;
	cout << "For n = " << n << "." << endl << endl;
	ArrayList<int> arr;
	for (int i = 0; i < n; ++i)
		arr.add(i);
	int time0 = clock();
	for (int i = 0; i < n; ++i)
		arr.indexOf(i);
	int time1 = clock();
	cout << "indexOf()\t\t\to(n^2) (traverse)"<< endl << "[" << time1 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		arr.lastIndexOf(i);
	int time2 = clock();
	cout << "lastIndexOf()\t\t\to(n^2) (traverse)"<< endl << "[" << time2 - time1 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		arr.contains(i);
	int time3 = clock();
	cout << "contains()\t\t\to(n^2) (traverse)"<< endl << "[" << time3 - time2 << "]ms" << endl;

	ArrayList<int>::Iterator it = arr.iterator();
	while(it.hasNext())
	{
		it.next();
		it.remove();
	}
	int time4 = clock();
	cout << "Iterator::remove() (front)\to(n^2) (traverse)" << endl << "[" << time4 - time3 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		arr.add(i);
	time0 = clock();

	for (int i = 0; i < n; ++i)
	arr.remove(i);
	int time5 = clock();
	cout << "remove()\t\t\to(n^2) (front to back)" << endl << "[" << time5 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		arr.add(i);
	time0 = clock();

	for (int i = n - 1; i >= 0; --i)
		arr.remove(i);
	int time6 = clock();
	cout << "remove()\t\t\to(n^2) (back to front)" << endl << "[" << time6 - time0 << "]ms" << endl;
}

void performanceTestLinkedList_1(int n)
{
	cout << endl << "[...testing LinkedList...]"  << endl;
	cout << "For n = " << n << "." << endl << endl;
	LinkedList<int> lin;
	int time0 = clock();
	for (int i = 0; i < n; ++i)
		lin.add(i);
	int time1 = clock();
	cout << "add()\t\t\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	LinkedList<int> lin1 = lin;
	int time2 = clock();
	cout << "operator=\t\t\to(n)" << endl << "[" << time2 - time1 << "]ms" << endl;

	LinkedList<int>* lin2 = new LinkedList<int>(lin);
	int time3 = clock();
	cout << "LinkedList(const LinkedList& x)\to(n)" << endl << "[" << time3 - time2 << "]ms" << endl;

	LinkedList<int> lin3 = lin.subList(0, n);
	int time4 = clock();
	cout << "subList(0, n)\t\t\to(n)" << endl << "[" << time4 - time3 << "]ms" << endl;

	lin.indexOf(n-1);
	int time5 = clock();
	cout << "indexOf(n-1)\t\t\to(n)"<< endl << "[" << time5 - time4 << "]ms" << endl;

	lin.contains(n-1);
	int time7 = clock();
	cout << "contains()\t\t\to(n)"<< endl << "[" << time7 - time5 << "]ms" << endl;

	lin.get(n - 1);
	int time8 = clock();
	cout << "get(n-1)\t\t\to(n)"<< endl << "[" << time8 - time7 << "]ms" << endl;

	LinkedList<int>::Iterator it = lin.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time9 = clock();
	cout << "Iterator::next()\t\to(n) (traverse)" << endl << "[" << time9 - time8 << "]ms" << endl;

	LinkedList<int>::Iterator it1 = lin.iterator();
	while (it1.hasNext())
	{
		it1.next();
		it1.remove();
	}
	int time10 = clock();
	cout << "Iterator::remove()\t\to(n) (traverse)" << endl << "[" << time10 - time9 << "]ms" << endl;

	lin2->clear();
	int time11 = clock();
	cout << "clear()\t\t\t\to(n)" << endl << "[" << time11 - time10 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		lin3.removeFirst();
	int time12 = clock();
	cout << "Iterator::removeFirst()\t\to(n) (traverse)" << endl << "[" << time12 - time11 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		lin1.removeLast();
	int time13 = clock();
	cout << "Iterator::removeLast()\t\to(n) (traverse)" << endl << "[" << time13 - time12 << "]ms" << endl;
}

void performanceTestLinkedList_2(int n)
{
	cout << endl << "[...testing LinkedList...]" << endl;
	cout << "For n = " << n << "." << endl << endl;
	LinkedList<int> lin;
	for (int i = 0; i < n; ++i)
		lin.add(i);
	int time0 = clock();
	for (int i = 0; i < n; ++i)
		lin.indexOf(i);
	int time1 = clock();
	cout << "indexOf()\t\t\to(n^2) (traverse)"<< endl << "[" << time1 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		lin.contains(i);
	int time3 = clock();
	cout << "contains()\t\t\to(n^2) (traverse)"<< endl << "[" << time3 - time1 << "]ms" << endl;
}

void performanceTestTreeSet(int n)
{
	cout << endl << "[...testing TreeSet...]" << endl;
	cout << "For n = " << n << "." << endl << endl;
	TreeSet<int> set;
	int time0 = clock();
	for (int i = 0; i < n; ++i)
		set.add(i);
	int time1 = clock();
	cout << "add()\t\t\t\to(nlogn) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	TreeSet<int> set1 = set;
	int time2 = clock();
	cout << "operator=\t\t\to(n)" << endl << "[" << time2 - time1 << "]ms" << endl;

	TreeSet<int>* set2 = new TreeSet<int>(set);
	int time3 = clock();
	cout << "TreeSet(const TreeSet& x)\to(n)" << endl << "[" << time3 - time2 << "]ms" << endl;

	TreeSet<int>::Iterator it = set.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time9 = clock();
	cout << "Iterator::next()\t\to(nlogn) (traverse)" << endl << "[" << time9 - time3 << "]ms" << endl;

	TreeSet<int>::Iterator it1 = set.iterator();
	while (it1.hasNext())
	{
		it1.next();
		it1.remove();
	}
	int time10 = clock();
	cout << "Iterator::remove()\t\to(nlogn) (traverse)" << endl << "[" << time10 - time9 << "]ms" << endl;

	set1.clear();
	int time11 = clock();
	cout << "clear()\t\t\t\to(nlogn)" << endl << "[" << time11 - time10 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		set2->remove(i);
	int time12 = clock();
	cout << "remove()\t\t\to(nlogn) (traverse)" << endl << "[" << time12 - time11 << "]ms" << endl;
}

void performanceTestTreeMap(int n)
{
	cout << endl << "[...testing TreeMap...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	TreeMap<int, int> map;
	int time0 = clock();
	for (int i = 0; i < n; ++i)
		map.put(i, i);
	int time1 = clock();
	cout << "put()\t\t\t\to(nlogn) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	TreeMap<int, int> map1 = map;
	int time2 = clock();
	cout << "operator=\t\t\to(n)" << endl << "[" << time2 - time1 << "]ms" << endl;

	TreeMap<int, int>* map2 = new TreeMap<int, int>(map);
	int time3 = clock();
	cout << "TreeMap(const TreeMap& x)\to(n)" << endl << "[" << time3 - time2 << "]ms" << endl;

	TreeMap<int, int>::Iterator it = map.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time9 = clock();
	cout << "Iterator::next()\t\to(nlogn) (traverse)" << endl << "[" << time9 - time3 << "]ms" << endl;

	TreeMap<int, int>::Iterator it1 = map.iterator();
	while (it1.hasNext())
	{
		it1.next();
		it1.remove();
	}
	int time10 = clock();
	cout << "Iterator::remove()\t\to(nlogn) (traverse)" << endl << "[" << time10 - time9 << "]ms" << endl;

	map1.clear();
	int time11 = clock();
	cout << "clear()\t\t\t\to(nlogn)" << endl << "[" << time11 - time10 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		map2->remove(i);
	int time12 = clock();
	cout << "remove()\t\t\to(nlogn) (traverse)" << endl << "[" << time12 - time11 << "]ms" << endl;
}

void performanceTestHashSet(int n)
{
	cout << endl << "[...testing HashSet...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	class Hashint
	{
	public:
		static int hashcode(int obj)
		{
			return obj;
		}
	};

	HashSet<int, Hashint> set;
	int time0 = clock();
	for (int i = 0; i < n; ++i)
		set.add(i);
	int time1 = clock();
	cout << "add()\t\t\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	HashSet<int, Hashint> set1 = set;
	int time2 = clock();
	cout << "operator=\t\t\to(n)" << endl << "[" << time2 - time1 << "]ms" << endl;

	HashSet<int, Hashint>* set2 = new HashSet<int, Hashint>(set);
	int time3 = clock();
	cout << "HashSet(const HashSet& x)\to(n)" << endl << "[" << time3 - time2 << "]ms" << endl;

	HashSet<int, Hashint>::Iterator it = set.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time9 = clock();
	cout << "Iterator::next()\t\to(n) (traverse)" << endl << "[" << time9 - time3 << "]ms" << endl;

	HashSet<int, Hashint>::Iterator it1 = set.iterator();
	while (it1.hasNext())
	{
		it1.next();
		it1.remove();
	}
	int time10 = clock();
	cout << "Iterator::remove()\t\to(n) (traverse)" << endl << "[" << time10 - time9 << "]ms" << endl;

	set1.clear();
	int time11 = clock();
	cout << "clear()\t\t\t\to(n)" << endl << "[" << time11 - time10 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		set2->remove(i);
	int time12 = clock();
	cout << "remove()\t\t\to(n) (traverse)" << endl << "[" << time12 - time11 << "]ms" << endl;
}

void performanceTestHashMap(int n)
{
	cout << endl << "[...testing HashMap...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	class Hashint
	{
	public:
		static int hashcode(int obj)
		{
			return obj;
		}
	};

	HashMap<int, int, Hashint> map;
	int time0 = clock();
	for (int i = 0; i < n; ++i)
		map.put(i, i);
	int time1 = clock();
	cout << "put()\t\t\t\to(nlogn) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	HashMap<int, int, Hashint> map1 = map;
	int time2 = clock();
	cout << "operator=\t\t\to(n)" << endl << "[" << time2 - time1 << "]ms" << endl;

	HashMap<int, int, Hashint>* map2 = new HashMap<int, int, Hashint>(map);
	int time3 = clock();
	cout << "TreeMap(const TreeMap& x)\to(n)" << endl << "[" << time3 - time2 << "]ms" << endl;

	HashMap<int, int, Hashint>::Iterator it = map.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time9 = clock();
	cout << "Iterator::next()\t\to(nlogn) (traverse)" << endl << "[" << time9 - time3 << "]ms" << endl;

	HashMap<int, int, Hashint>::Iterator it1 = map.iterator();
	while (it1.hasNext())
	{
		it1.next();
		it1.remove();
	}
	int time10 = clock();
	cout << "Iterator::remove()\t\to(nlogn) (traverse)" << endl << "[" << time10 - time9 << "]ms" << endl;

	map1.clear();
	int time11 = clock();
	cout << "clear()\t\t\t\to(nlogn)" << endl << "[" << time11 - time10 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		map2->remove(i);
	int time12 = clock();
	cout << "remove()\t\t\to(nlogn) (traverse)" << endl << "[" << time12 - time11 << "]ms" << endl;
}

void performanceCompareArrayList(int n)
{
	cout << endl << "[...testing ArrayList...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	ArrayList<int> arr;
	vector<int> vec;

	int time0 = clock();
	for (int i = 0; i < n; ++i)
		arr.add(i);
	int time1 = clock();
	cout << "ArrayList::add()\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		vec.push_back(i);
	int time2 = clock();
	cout << "vector::push_back()\t\to(n) (0 to n-1)" << endl << "[" << time2 - time1 << "]ms" << endl;

	ArrayList<int> arr1 = arr;
	int time2_2 = clock();
	cout << "ArrayList::operator=\t\to(n)" << endl << "[" << time2_2 - time2 << "]ms" << endl;

	vector<int> vec2 = vec;
	int time2_4 = clock();
	cout << "vector::operator=\t\to(n)" << endl << "[" << time2_4 - time2_2 << "]ms" << endl;

	ArrayList<int>::Iterator it = arr.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time3 = clock();
	cout << "ArrayList::Iterator::next()\to(n) (traverse)" << endl << "[" << time3 - time2_4 << "]ms" << endl;

	vector<int>::iterator it1 = vec.begin();
	while (it1 != vec.end())
	{
		it1++;
	}
	int time4 = clock();
	cout << "vector::iterator::next()\to(n) (traverse)" << endl << "[" << time4 - time3 << "]ms" << endl;

	arr.clear();
	int time5 = clock();
	cout << "ArrayList::clear()\t\to(n) " << endl << "[" << time5 - time4 << "]ms" << endl;

	vec.clear();
	int time6 = clock();
	cout << "vector::clear()\t\t\to(n) " << endl << "[" << time6 - time5 << "]ms" << endl;
}

void performanceCompareLinkedList(int n)
{
	cout << endl << "[...testing LinkedList...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	LinkedList<int> arr;
	list<int> vec;

	int time0 = clock();
	for (int i = 0; i < n; ++i)
		arr.add(i);
	int time1 = clock();
	cout << "LinkedList::add()\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		vec.push_back(i);
	int time2 = clock();
	cout << "list::push_back()\t\to(n) (0 to n-1)" << endl << "[" << time2 - time1 << "]ms" << endl;

	LinkedList<int>::Iterator it = arr.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time3 = clock();
	cout << "LinkedList::Iterator::next()\to(n) (traverse)" << endl << "[" << time3 - time2 << "]ms" << endl;

	list<int>::iterator it1 = vec.begin();
	while (it1 != vec.end())
	{
		it1++;
	}
	int time4 = clock();
	cout << "list::iterator::next()\t\to(n) (traverse)" << endl << "[" << time4 - time3 << "]ms" << endl;

	arr.clear();
	int time5 = clock();
	cout << "LinkedList::clear()\t\to(n) " << endl << "[" << time5 - time4 << "]ms" << endl;

	vec.clear();
	int time6 = clock();
	cout << "list::clear()\t\t\to(n) " << endl << "[" << time6 - time5 << "]ms" << endl;
}

void performanceCompareTreeSet(int n)
{
	cout << endl << "[...testing TreeSet...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	TreeSet<int> arr;
	set<int> vec;

	int time0 = clock();
	for (int i = 0; i < n; ++i)
		arr.add(i);
	int time1 = clock();
	cout << "TreeSet::add()\t\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		vec.insert(i);
	int time2 = clock();
	cout << "set::insert()\t\t\to(n) (0 to n-1)" << endl << "[" << time2 - time1 << "]ms" << endl;

	TreeSet<int>::Iterator it = arr.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time3 = clock();
	cout << "TreeSet::Iterator::next()\to(n) (traverse)" << endl << "[" << time3 - time2 << "]ms" << endl;

	set<int>::iterator it1 = vec.begin();
	while (it1 != vec.end())
	{
		it1++;
	}
	int time4 = clock();
	cout << "set::iterator::next()\t\to(n) (traverse)" << endl << "[" << time4 - time3 << "]ms" << endl;

	arr.clear();
	int time5 = clock();
	cout << "TreeSet::clear()\t\to(n) " << endl << "[" << time5 - time4 << "]ms" << endl;

	vec.clear();
	int time6 = clock();
	cout << "set::clear()\t\t\to(n) " << endl << "[" << time6 - time5 << "]ms" << endl;
}

void performanceCompareTreeMap(int n)
{
	cout << endl << "[...testing TreeMap...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	TreeMap<int, int> arr;
	map<int, int> vec;

	int time0 = clock();
	for (int i = 0; i < n; ++i)
		arr.add(Entry<int, int>(i, i));
	int time1 = clock();
	cout << "TreeMap::add()\t\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		vec.insert(pair<int, int>(i, i));
	int time2 = clock();
	cout << "map::insert()\t\t\to(n) (0 to n-1)" << endl << "[" << time2 - time1 << "]ms" << endl;

	TreeMap<int, int>::Iterator it = arr.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time3 = clock();
	cout << "TreeMap::Iterator::next()\to(n) (traverse)" << endl << "[" << time3 - time2 << "]ms" << endl;

	map<int, int>::iterator it1 = vec.begin();
	while (it1 != vec.end())
	{
		it1++;
	}
	int time4 = clock();
	cout << "map::iterator::next()\t\to(n) (traverse)" << endl << "[" << time4 - time3 << "]ms" << endl;

	arr.clear();
	int time5 = clock();
	cout << "TreeMap::clear()\t\to(n) " << endl << "[" << time5 - time4 << "]ms" << endl;

	vec.clear();
	int time6 = clock();
	cout << "map::clear()\t\t\to(n) " << endl << "[" << time6 - time5 << "]ms" << endl;
}

void performanceCompareHashSet(int n)
{
	cout << endl << "[...testing HashSet...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	class Hashint_
	{
	public:
		static int hashcode(int obj)
		{
			return obj;
		}
	};

	HashSet<int, Hashint_> arr;
	hash_set<int> vec;

	int time0 = clock();
	for (int i = 0; i < n; ++i)
		arr.add(i);
	int time1 = clock();
	cout << "HashSet::add()\t\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		vec.insert(i);
	int time2 = clock();
	cout << "hash_set::insert()\t\to(n) (0 to n-1)" << endl << "[" << time2 - time1 << "]ms" << endl;

	HashSet<int, Hashint_>::Iterator it = arr.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time3 = clock();
	cout << "HashSet::Iterator::next()\to(n) (traverse)" << endl << "[" << time3 - time2 << "]ms" << endl;

	hash_set<int>::iterator it1 = vec.begin();
	while (it1 != vec.end())
	{
		it1++;
	}
	int time4 = clock();
	cout << "hash_set::iterator::next()\to(n) (traverse)" << endl << "[" << time4 - time3 << "]ms" << endl;

	arr.clear();
	int time5 = clock();
	cout << "HashSet::clear()\t\to(n) " << endl << "[" << time5 - time4 << "]ms" << endl;

	vec.clear();
	int time6 = clock();
	cout << "hash_set::clear()\t\to(n) " << endl << "[" << time6 - time5 << "]ms" << endl;
}

void performanceCompareHashMap(int n)
{
	cout << endl << "[...testing HashMap...]" << endl;
	cout << "For n = " << n << "." << endl << endl;

	class Hashint_
	{
	public:
		static int hashcode(int obj)
		{
			return obj;
		}
	};

	HashMap<int, int, Hashint_> arr;
	hash_map<int, int> vec;

	int time0 = clock();
	for (int i = 0; i < n; ++i)
		arr.add(Entry<int, int>(i, i));
	int time1 = clock();
	cout << "HashMap::add()\t\t\to(n) (0 to n-1)" << endl << "[" << time1 - time0 << "]ms" << endl;

	for (int i = 0; i < n; ++i)
		vec.insert(pair<int, int>(i, i));
	int time2 = clock();
	cout << "hash_map::insert()\t\to(n) (0 to n-1)" << endl << "[" << time2 - time1 << "]ms" << endl;

	HashMap<int, int, Hashint_>::Iterator it = arr.iterator();
	while (it.hasNext())
	{
		it.next();
	}
	int time3 = clock();
	cout << "HashMap::Iterator::next()\to(n) (traverse)" << endl << "[" << time3 - time2 << "]ms" << endl;

	hash_map<int, int>::iterator it1 = vec.begin();
	while (it1 != vec.end())
	{
		it1++;
	}
	int time4 = clock();
	cout << "hash_map::iterator::next()\to(n) (traverse)" << endl << "[" << time4 - time3 << "]ms" << endl;

	arr.clear();
	int time5 = clock();
	cout << "HashMap::clear()\t\to(n) " << endl << "[" << time5 - time4 << "]ms" << endl;

	vec.clear();
	int time6 = clock();
	cout << "hash_map::clear()\t\to(n) " << endl << "[" << time6 - time5 << "]ms" << endl;
}

void functionalTest()
{
	system("pause");
	testArrayList(2000);
	system("pause");
	testLinkedList(2000);
	system("pause");
	testTreeSet(2000);
	system("pause");
	testTreeMap(2000);
	system("pause");
	testHashSet(2000);
	system("pause");
	testHashMap(2000);
	system("pause");
}

void performanceTest()
{
	system("pause");
	performanceTestArrayList_1(5000000);
	system("pause");
	performanceTestArrayList_2(50000);
	system("pause");
	performanceTestLinkedList_1(10000);
	system("pause");
	performanceTestLinkedList_2(100000);
	system("pause");
	performanceTestTreeSet(10000);
	system("pause");
	performanceTestTreeMap(10000);
	system("pause");
	performanceTestHashSet(10000);
	system("pause");
	performanceTestHashMap(10000);
	system("pause");
}

void compareTest()
{
	system("pause");
	performanceCompareArrayList(5000000);
	system("pause");
	performanceCompareLinkedList(10000);
	system("pause");
	performanceCompareTreeSet(10000);
	system("pause");
	performanceCompareTreeMap(10000);
	system("pause");
	performanceCompareHashSet(10000);
	system("pause");
	performanceCompareHashMap(10000);
	system("pause");
}

void menu()
{
	cout << "BEES TEST" << endl;
	cout << "BY CQM" << endl << endl;
	cout << "1. functional test" << endl;
	cout << "2. performance test" << endl;
	cout << "3. compare to STL" << endl;
	cout << "4. QUIT" << endl;
}

int main()
{
	menu();
	char ch;
	while (cin >> ch)
	{
		if (ch == '1') functionalTest();
		if (ch == '2') performanceTest();
		if (ch == '3') compareTest();
		if (ch == '4') break;
		else
			menu();
	}
	system("pause");
	return 0;
}

