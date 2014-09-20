/** @file */

#ifndef __TREESET_H
#define __TREESET_H

#include "Utility.h"

/**
 * A set implemented by balanced tree,
 * the elements being putted must guarantee operator'<'
 *
 * The iterator must iterates in the order defined by the operator'<' (from the smallest to the biggest)
 */

template <class E>
class TreeSet
{
private:
	class Node
	{
	public:
		E data;
		int prior;
		Node* left;
		Node* right;
		Node* father;
	public:
		Node(E dat, int pri)
		{
			data = dat;
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
			while (t->right) 
				t = t->right;
			return t;
		}
		if (t->father == NULL) return NULL;
		while (t->father && t->father->left == t)
		{
			t = t->father;
		}
		return t->father;
	}

	Node* leftRotate(Node* t)
	{ 
		Node *re = t->left;
		re->father = t->father;
		if (re->right != NULL) re->right->father = t;
		t->father = re;
		t->left = re->right;
		re->right = t;
		return re;
	}

	Node* rightRotate(Node* t) 
	{
		Node *re = t->right;
		re->father = t->father;
		if (re->left != NULL) re->left->father = t;
		t->father = re;
		t->right = re->left;
		re->left = t;
		return re;
	}

	Node *treeDelete(const E& e, Node *t)
	{
		if (t == NULL) return NULL;
		if (t->data > e)
		{
			t->left = treeDelete(e, t->left);
			if (t->left != NULL) t->left->father = t;
			return t;
		}else
			if (t->data < e)
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



	void insertNode(Node* &t,E e)
	{
		if (t == NULL)
		{
			t = new Node(e, rand() % INFINITY);
			treeSize++;
			return;
		}
		if (e <= t->data)
		{
			insertNode(t->left, e);
			t->left->father = t;
			if (t->left->prior < t->prior)
				t = leftRotate(t);
		}else
		{
			insertNode(t->right, e);
			t->right->father = t;
			if (t->right->prior < t->prior)
				t = rightRotate(t);
		}
	}

	Node* treeFind(const E& e, Node *t) const
	{
		if (t == NULL) return NULL;
		if (e == t->data) return t;
		if (e <= t->data) return treeFind(e, t->left); else
			return treeFind(e, t->right);
	}


    class ConstIterator
    {
	private:
		Node* p;
		const TreeSet* tree;
	public:
		ConstIterator()
		{
			tree = NULL;
			p = NULL;
		}

		ConstIterator(const TreeSet* x):tree(x)
		{
			p = tree->firstNode();
		}

        /**
         * Returns true if the iteration has more elements.
         * O(logn)
         */
        bool hasNext() 
		{
			if (p == NULL) return false;
			return true;
		}

        /**
         * Returns a const reference to the next element in the iteration.
         * O(logn)
         * @throw ElementNotExist
         */
		const E& next() 
		{
			if (!hasNext()) throw ElementNotExist();
			const E& d = p->data;
			p = tree->nextNode(p);
			return d;
		}
    };

    class Iterator
    {
	private:
		Node* p;
		TreeSet* tree;
		bool removed;
	public:
		Iterator()
		{
			tree = NULL;
			p = NULL;
			removed = true;
		}

		Iterator(TreeSet* x)
		{
			tree = x;
			p = tree->firstNode();
			removed = true;
		}

		bool Removed()
		{
			return removed;
		}

        /**
         * Returns true if the iteration has more elements.
         * O(logn)
         */
        bool hasNext()
		{
			if (p == NULL) return false;
			return true;
		}

        /**
         * Returns a const reference the next element in the iteration.
         * O(logn)
         * @throw ElementNotExist
		 */
		const E& next() 
		{
			if (!hasNext()) throw ElementNotExist();
			E& d = p->data;
			p = tree->nextNode(p);
			removed = false;
			return d;
		}

        /**
         * Removes from the underlying collection the last element returned by the iterator (optional operation).
         * O(logn)
         * @throw ElementNotExist
         */
		void remove() 
		{
			if (removed) throw ElementNotExist();
			if (p)
				tree->root = tree->treeDelete(tree->preNode(p)->data, tree->root);
			else
				tree->root = tree->treeDelete(tree->lastNode()->data, tree->root);
			removed = true;
			tree->treeSize--;
		}
    };

	/**
	* Constructs a new, empty tree set, sorted according to the natural ordering of its elements.
	*/
    TreeSet() 
	{
		root = NULL;
		treeSize = 0;
		INFINITY  = 1000000;
	}

    /**
     * Constructs a set containing the elements of the specified collection, in
     * the order they are returned by the collection's iterator.
     */
    template <class E2>
    explicit TreeSet(const E2& x) 
	{
		root = NULL;
		treeSize = 0;
		INFINITY  = 1000000;
		addAll(*this, x);
	}

    /**
     * Destructor
     */
    ~TreeSet() 
	{
		clear();
	}

    /**
     * Assignment operator
     */
    TreeSet& operator=(const TreeSet& x) 
	{
		clear();
		addAll(*this, x);
		return *this;
	}

    /**
     * Copy-constructor
     */
    TreeSet(const TreeSet& x) 
	{
		root = NULL;
		treeSize = 0;
		INFINITY  = 1000000;
		addAll(*this, x);
	}

    /**
     * Returns an iterator over the elements in this set in proper sequence.
     */
    Iterator iterator() 
	{
		return Iterator(this);
	}

    /**
     * Returns an CONST iterator over the elements in this set in proper sequence.
     */
	ConstIterator constIterator() const 
	{
		return ConstIterator(this);
	}

    /**
     * Adds the specified element to this set if it is not already present.
     * Returns true if this set did not already contain the specified element.
     * O(logn)
     */
    bool add(const E& e) 
	{
		if (contains(e)) return false;
		insertNode(root, e);
		return true;
	}

    /**
     * Removes all of the elements from this set.
     */
    void clear() 
	{
		while (root != NULL) root = treeDelete(root->data, root);
		treeSize = 0;
	}

    /**
     * Returns true if this set contains the specified element.
     * O(logn)
     */
    bool contains(const E& e) const 
	{
		return (treeFind(e, root) != NULL);
	}

    /**
     * Returns a const reference to the first (lowest) element currently in this set.
     * O(logn)
     * @throw ElementNotExist
     */
    const E& first() const 
	{
		if (root == NULL) throw ElementNotExist();
		Node* t = root;
		while(t->left != NULL) t = t->left;
		return t->data;
	}

    /**
     * Returns true if this set contains no elements.
     * O(1)
     */
    bool isEmpty() const 
	{
		return (treeSize == 0);
	}

    /**
     * Returns a const reference to the last (highest) element currently in this set.
     * O(logn)
     * @throw ElementNotExist
     */
    const E& last() const 
	{
		if (root == NULL) throw ElementNotExist();
		Node* t = root;
		while(t->right != NULL) t = t->right;
		return t->data;
	}

    /**
     * Removes the specified element from this set if it is present.
     * O(logn)
     */
    bool remove(const E& e) 
	{
		if (!treeFind(e, root)) return false;
		root = treeDelete(e, root);
		return true;
	}

    /**
     * Returns the number of elements in this set (its cardinality).
     * O(1)
     */
	int size() const 
	{
		return treeSize;
	}
};
#endif
