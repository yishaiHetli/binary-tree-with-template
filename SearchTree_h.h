#pragma once
#include "Tree.h"

template <class T>
class SearchTree : public Tree<T>
{
public:
	// protocol for search trees
	void add(T value);
	bool search(T value)
	{
		return search(this->root, value);
	}
	void remove(T value);
	void ser(T value) { return ser(this->root, value); }
	int level(T value) { return level(this->root, value); }

private:
	void add(Node<T>* current, T val);
	bool search(Node<T>* current, T val);
	void ser(Node<T>* current, T val);
	int level(Node<T>* current, T val);
};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!this->root)
	{
		this->root = new Node<T>(val);

		return;
	}
	add(this->root, val);
}
template <class T>
bool SearchTree<T>::search(Node<T>* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}
template <class T>
void SearchTree<T>::add(Node<T>* current, T val)
{
	if (current->value < val)
	{  // add to right subtree
		if (!current->right)// if it is null
		{
			current->right = new Node<T>(val);
			Node<T>* Z = current->right;
			Z->parent = current;
			return;
		}
		else
			add(current->right, val);
	}
	else
	{	// add to left subtree
		if (!current->left)
		{
			current->left = new Node<T>(val);
			Node<T>* Z = current->left;
			Z->parent = current;
			return;
		}
		else
			add(current->left, val);
	}
}

template <class T>
void SearchTree<T>::remove(T value)
{
	ser(this->root, value);
}

template <class T>
void SearchTree<T>::ser(Node<T>* current, T val)//realizing of the remove
{
	if (search(val))
	{
		if (current->value == val)
		{
			Node<T>* help2 = NULL;
			Node<T>* help = NULL;
			Node<T>* z1 = NULL;
			Node<T>* z = NULL;
			Node<T>*px = current;//pointer to value
			Node<T>*pa = current->parent;
			if (px->left == NULL || px->right == NULL)
				z = px;
			else
			{
				z1 = px->right;
				while (z1->left != NULL)
					z1 = z1->left;
				z = z1;
			}
			px->value = z->value;

			if (z->left != NULL)
				help = z->left;
			else
				help = z->right;
			if (help != NULL)
				help->parent = z->parent;
			if (z != this->root)
			{
				help2 = z->parent;
				if (z == help2->left)
					help2->left = help;
				else
					help2->right = help;
				delete z;
			}
			else
			{
				delete z;
				this->root = NULL;

			}
			return;
		}
		if (current->value < val)
			ser(current->right, val);
		else
			ser(current->left, val);
	}
}

template <class T>
int SearchTree<T>::level(Node<T>* current_node, T val)
{
	if (search(val))
	{
		if (current_node->value == val)
		{
			int sum1 = 0;
			Node<T>*px = current_node;
			if (px == this->root)
				return 0;
			while (px->parent != NULL)
			{
				sum1++;
				px = px->parent;
			}
			return sum1;
		}
		if (current_node->value < val)
			level(current_node->right, val);
		else
			level(current_node->left, val);
	}
	else
		return -1;
}