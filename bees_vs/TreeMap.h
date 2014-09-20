/** @file */
#ifndef __TREEMAP_H
#define __TREEMAP_H

#include "Utility.h"

/**
 * A map is a sequence of (key, value) entries that provides fast retrieval
 * based on the key. At most one value is held for each key.
 *
 * TreeMap is the balanced-tree implementation of map. The iterators must
 * iterate through the map in the natural order (operator<) of the key.
 */
template<class K, class V> class TreeMap 
{
public:
	class Node
	{
	public:
		Entry<K, V> entry;
		int prior;
		Node* left;
		Node* right;
		Node* father;

		Node(K k, V v, int pri):entry(k, v)
		{
			prior = pri;
			left = NULL;
			right = NULL;
			father = NULL;
		}
	};

private:
	Node* root;
	int treeSize;
	int INFINITY;

public:
	Node* firstNode() const
	{
		if (root == NULL) return NULL;
		Node* t = root;
		while(t->left != NULL) t = t->left;
		return t;
	}

	Node* lastNode() const
	{
		if (root == NULL) return NULL;
		Node* t = root;
		while(t->right != NULL) t = t->right;
		return t;
	}

	Node* nextNode(Node* t) const
	{
		if (t == NULL) return NULL;
		if (t->right != NULL)
		{
			t = t->right;
			while (t->left != NULL) t = t->left;
			return t;
		}
		if (t->father == NULL) return NULL;
		while (t->father && t->father->right == t)
		{
			t = t->father;
		}
		return t->father;

	}

	Node* preNode(Node* t) const
	{
		if (t == NULL) return NULL;
		if (t->left != NULL)
		{
			t = t->left;
			while (t->right != NULL) t = t->right;
			return t;
		}
		if (t->father == NULL) return NULL;
		while (t->father && t->father->left == t)
		{
			t = t->father;
		}
		return t->father;
	}

	Node* leftRotate(Node* &t)
	{
		Node *re = t->left;
		re->father = t->father;
		if (re->right != NULL) re->right->father = t;
		t->father = re;
		t->left = re->right;
		re->right = t;
		return re;

	}

	Node* rightRotate(Node* &t) 
	{
		Node *re = t->right;
		re->father = t->father;
		if (re->left != NULL) re->left->father = t;
		t->father = re;
		t->right = re->left;
		re->left = t;
		return re;
	}

	Node *treeDelete(const K& e, Node *t)
	{
		if (t == NULL) return NULL;
		if (t->entry.key > e)
		{
			t->left = treeDelete(e, t->left);
			if (t->left != NULL) t->left->father = t;
			return t;
		}else
			if (t->entry.key < e)
			{
				t->right = treeDelete(e, t->right);
				if (t->right != NULL) t->right->father = t;
				return t;
			}
			else
			{
				if (t->left == NULL && t->right == NULL)
				{
					delete t;
					return NULL;
				}
				if ((t->left != NULL && t->right != NULL && t->left->prior <= t->right->prior) || (t->right == NULL))
					t = leftRotate(t); else
					t = rightRotate(t);
				t = treeDelete(e, t);
				return t;
			}
	}

	void insertNode(Node* &t,K key, V value)
	{
		if (t == NULL)
		{
			t = new Node(key, value, rand() % INFINITY);
			treeSize++;
			return;
		}
		if (key <= t->entry.key)
		{
			insertNode(t->left, key, value);
			t->left->father = t;
			if (t->left->prior < t->prior)
				t = leftRotate(t);
		}else
		{
			insertNode(t->right, key, value);
			t->right->father = t;
			if (t->right->prior < t->prior)
				t = rightRotate(t);
		}
	}

	Node* treeFind(const K& e, Node *t) const
	{
		if (t == NULL) return NULL;
		if (e == t->entry.key) return t;
		if (e <= t->entry.key) return treeFind(e, t->left); else
			return treeFind(e, t->right);
	}
    
	class ConstIterator 
	{
	private:
		Node* p;
		const TreeMap* tree;
	public:
		ConstIterator()
		{
			tree = NULL;
			p = NULL;
		}

		ConstIterator(const TreeMap* x)
		{
			tree = x;
			p = tree->firstNode();
		}

        /**
         * Returns true if the iteration has more elements.
         * Amortized O(1).
         */
        bool hasNext() 
		{
			if (p == NULL) return false;
			return true;
		}

        /**
         * Returns a const reference to the next element in the iteration.
         * Amortized O(1).
         * @throw ElementNotExist
         */
        const Entry<K, V>& next() 
		{
			if (!hasNext()) throw ElementNotExist();
			Entry<K, V>& tmp = p->entry;
			p = tree->nextNode(p);
			return tmp;
		}
    };

    class Iterator 
	{
	private:
		Node* p;
		TreeMap* tree;
		bool removed;
	
	public:
		bool Removed()
		{
			return removed;
		}

		Iterator()
		{
			tree = NULL;
			p = NULL;
			removed = true;
		}

		Iterator(TreeMap* x)
		{
			tree = x;
			p = tree->firstNode();
			removed = true;
		}

        /**
         * Returns true if the iteration has more elements.
         * Amortized O(1).
         */
        bool hasNext() 
		{
			if (p == NULL) return false;
			return true;
		}

        /**
         * Returns a reference to the next element in the iteration.
         * Amortized O(1).
         * @throw ElementNotExist
         */
        Entry<K, V>& next()
		{
			if (!hasNext()) throw ElementNotExist();
			Entry<K, V>& tmp = p->entry;
			p = tree->nextNode(p);
			removed = false;
			return tmp;
		}

        /**
         * Removes from the underlying collection the last element
         * returned by the iterator
         * Amortized O(1).
         * @throw ElementNotExist
         */
        void remove() 
		{
			if (removed) throw ElementNotExist();
			if (p)
				tree->root = tree->treeDelete(tree->preNode(p)->entry.key, tree->root);
			else
				tree->root = tree->treeDelete(tree->lastNode()->entry.key, tree->root);
			removed = true;
			tree->treeSize--;
		}
    };

    /**
     * Constructs an empty map
     */
    TreeMap() 
	{
		root = NULL;
		treeSize = 0;
		INFINITY  = 1000000;
	}

    /**
     * Copy constructor
     */
    TreeMap(const TreeMap &c)
	{
		root = NULL;
		treeSize = 0;
		INFINITY  = 1000000;
		addAll(*this, c);
	}

    /**
     * Destructor
     */
    ~TreeMap() 
	{
		clear();
	}

    /**
     * Assignment operator
     */
    TreeMap& operator=(const TreeMap &c) 
	{
		clear();
		addAll(*this, c);
		return *this;
	}

    /**
     * Constructs a new tree map containing the same mappings as the
     * given map
     */
    template <class C> TreeMap(const C& c) 
	{
		root = NULL;
		treeSize = 0;
		INFINITY  = 1000000;
		addAll(*this, c);
	}

    /**
     * Returns an iterator over the elements in this map.
     * O(1).
     */
    Iterator iterator() 
	{
		return Iterator(this);
	}

    /**
     * Returns an const iterator over the elements in this map.
     * O(1).
     */
    ConstIterator constIterator() const 
	{
		return ConstIterator(this);
	}

    /**
     * Removes all of the mappings from this map.
     * O(n).
     */
    void clear() 
	{
		while (root != NULL) root = treeDelete(root->entry.key, root);
		treeSize = 0;
	}

    /**
     * Returns true if this map contains a mapping for the specified key.
     * O(logn).
     */
    bool containsKey(const K& key) const 
	{
		return (treeFind(key, root) != NULL);
	}

    /**
     * Returns true if this map contains a mapping for the specified value.
     * O(n).
     */
    bool containsValue(const V& value) const 
	{
		for (Node* i = firstNode(); i != NULL; i = nextNode(i))
		{
			if (i->entry.value == value) return true;
		}
		return false;
	}

    /**
	* Returns a key-value mapping associated with the least key in
	* this map.
	* O(logn).
	* @throw ElementNotExist
	*/
    const Entry<K, V>& firstEntry() const
	{
		if (root == NULL) throw ElementNotExist();
		return firstNode()->entry;
	}

    /**
     * Returns the first (lowest) key currently in this map.
     * O(logn).
     * @throw ElementNotExist
     */
    const K& firstKey() const 
	{
		if (root == NULL) throw ElementNotExist();
		return firstNode()->entry.key;
	}

    /**
     * Returns a reference to the value which the specified key is mapped
     * O(logn).
     * @throw ElementNotExist
     */
    V& get(const K& key) 
	{
		Node* tmp = treeFind(key, root);
		if (tmp == NULL) throw ElementNotExist();
		return tmp->entry.value;
	}

    /**
     * Returns a reference to the value which the specified key is mapped
     * O(logn).
     * @throw ElementNotExist
     */
    const V& get(const K& key) const 
	{
		Node* tmp = treeFind(key);
		if (tmp == NULL) throw ElementNotExist();
		return tmp->entry.value;
	}

    /**
     * Returns a key-value mapping associated with the greatest key
     * in this map.
     * O(logn).
     * @throw ElementNotExist
     */
    const Entry<K, V>& lastEntry() const 
	{
		if (root == NULL) throw ElementNotExist();
		return  lastNode()->entry;
	}

    /**
     * Returns the last (highest) key currently in this map.
     * O(logn).
     * @throw ElementNotExist
     */
    const K& lastKey() const 
	{
		if (root == NULL) throw ElementNotExist();
		return lastNode()->entry.key;
	}

    /**
     * Associates the specified value with the specified key in this map.
     * Returns the previous value, if not exist, a value returned by the
     * default-constructor.
     * O(logn).
     */
    V put(const K& key, const V& value) 
	{
		V v;
		Node* tmp = treeFind(key, root);
		if (tmp != NULL) v = tmp->entry.value;
		insertNode(root, key, value);
		return v;
	}

	void add(Entry<K, V> entry)
	{
		insertNode(root, entry.key, entry.value);
	}

    /**
     * Removes the mapping for this key from this TreeMap if present.
     * O(logn).
     * @throw ElementNotExist
     */
	V remove(const K& key) 
	{
		if (treeFind(key, root) == NULL) throw ElementNotExist();
		V v = get(key);
		root = treeDelete(key, root);
		treeSize--;
		return v;
	}

    /**
     * Returns the number of key-value mappings in this map.
     * O(logn).
     */
    int size() const 
	{
		return treeSize;
	}

	bool isEmpty()
	{
		return (treeSize == 0);
	}
};

#endif

