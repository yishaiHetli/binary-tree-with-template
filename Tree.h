#pragma	once
#include <iostream>
#include <string>
using namespace std;
template <class T>
class Node
{
public:
	Node() {};
	Node* left;
	Node* right;
	Node* parent;
	T value;
	Node(T val) : value(val), left(NULL), right(NULL), parent(NULL) {}
	Node(T val, Node<T>* l, Node<T>* r)
		: value(val), left(l), right(r), parent(NULL) {}
}; //end class node


template <class T>
class Tree :public Node<T>
{
protected:


	Node<T>* root;
public:
	int count1, count2, count3;
	Tree(int j = 0, int k = 0, int i = 0) :count1(j), count2(k), count3(i) { this->root = NULL; }
	~Tree();
	int isEmpty() const;
	void clear() { clear(this->root); this->root = NULL; }
	void preOrder() { preOrder(this->root); }
	void inOrder() { inOrder(this->root); }
	void postOrder() { postOrder(this->root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

	int sumEvens(int);
	int leaves() {

		return leaves(this->root);
	}
	void reflect() { reflect(this->root); }
	int height() {
		return height(this->root);
	}
	int onlyLeftSon() {
		return onlyLeftSon(this->root);
	}
private:
	int   sum(Node<int>* root, int level, int max);
	void  clear(Node<T>* current);
	void  preOrder(Node<T>* current);
	void  inOrder(Node<T>* current);
	void  postOrder(Node<T>* current);
	int leaves(Node<T>* current);
	void reflect(Node<T>* current);
	int height(Node<T>* current);
	int onlyLeftSon(Node<T>* current);
};

//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
int Tree<T>::sumEvens(int max)
{
	return sum(root, 0, max);
}

template <class T>
int Tree<T>::sum(Node<int>* root, int level, int max)
{
	if (root)
	{
		level++;  // increment level
		if (level <= max)
		{
			int even = (root->value % 2) ? 0 : root->value;
			return even + sum(root->left, level, max)
				+ sum(root->right, level, max);
		}
		else
			return 0;
	}
	else
		return 0;
}

template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}

template <class T>
void Tree<T>::clear(Node<T>* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// PreOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node<T>* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// InOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node<T>* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// PostOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node<T> * current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);

	}
}
template <class T>
int Tree<T>::leaves(Node<T> * current_node)
{
	if (current_node)
	{
		if (current_node->left == NULL && current_node->right == NULL)
		{
			count1++;
		}
		leaves(current_node->left);
		leaves(current_node->right);
	}
	return count1;
}
template <class T>
void Tree<T>::reflect(Node<T> * current_node)
{
	if (current_node)
	{
		reflect(current_node->left);
		reflect(current_node->right);
		if (current_node->left != NULL || current_node->right != NULL)
		{
			Node<T> * temp_n = current_node->right;
			current_node->right = current_node->left;
			current_node->left = temp_n;
		}
	}
}
template <class T>
int Tree<T>::height(Node<T> * current_node)
{
	if (current_node == NULL)
		return 0;

	int l = height(current_node->left);
	int r = height(current_node->right);
	if (l >= r)
		return l + 1;
	else
		return r + 1;
}
template <class T>
int Tree<T>::onlyLeftSon(Node<T> * current_node)
{
	if (current_node)
	{
		onlyLeftSon(current_node->left);
		onlyLeftSon(current_node->right);
		if (current_node->parent != NULL && current_node->parent->right == NULL)
		{
			count2++;
		}
	}
	return count2;
}