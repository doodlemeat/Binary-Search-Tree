#pragma once

#include "BinarySearchTreeNode.h"

template<typename T>
class BinarySearchTree
{
	BinarySearchTreeNode<T>* m_root;
	std::size_t m_size;

	bool insertRecursive(const T& value, BinarySearchTreeNode<T>* parent)
	{
		if (value == parent->data)
			return false;

		if (value < parent->data)
		{
			if (parent->left != nullptr)
			{
				return insertRecursive(value, parent->left);
			}
			else
				parent->left = createNode(value);
		}
		else if (value > parent->data)
		{
			if (parent->right != nullptr)
			{
				return insertRecursive(value, parent->right);
			}
			else
				parent->right = createNode(value);
		}
		++m_size;
		return true;
	}

	/*
	Node N
	No children  - Delete N, set N큦 parent to nullptr
	One child    - Replace N with N큦 child and remove N
	Two children - Select either N큦 left child or right child
	For the left child, select the rightmost node and replace it in N큦 place
	For the right child, select the leftmost node and replace it in N큦 place

	We know that node->data can not be equal to the data parameter
	*/
	bool eraseRecursive(BinarySearchTreeNode<T>* parent, BinarySearchTreeNode<T>* node, const T &data)
	{
		if (!node)
			return false;

		if (data < node->data)
			return eraseRecursive(node, node->left, data);

		if (data > node->data)
			return eraseRecursive(node, node->right, data);

		// We found the value
		if (node->hasChildren())
		{
			if (node->left == nullptr) // One child: right
			{
				if (parent != nullptr)
				{
					if (parent->right == node)
						parent->right = node->right;
					else
						parent->left = node->right;
				}
				else
				{
					m_root = node->right;
				}
				delete node;
				node = nullptr;
			}
			else if (node->right == nullptr) // One child: left
			{

				if (parent != nullptr)
				{
					if (parent->right == node)
						parent->right = node->left;
					else
						parent->left = node->left;
				}
				else
				{
					m_root = node->left;
				}
				delete node;
				node = nullptr;
			}
			else // Both childs
			{
				// Find the lowest node in the right branch
				BinarySearchTreeNode<T>* replacement = node->right;
				BinarySearchTreeNode<T>* p_replace = node; // parent to replacement
				while (replacement->left != nullptr)
				{
					p_replace = replacement;
					replacement = replacement->left;
				}

				// find out to which reference(left or right) the node is to its parent
				if (p_replace != nullptr)
				{
					// We must set the replacements parent to nullptr because it is leaving the tree
					if (p_replace->right == replacement)
						p_replace->right = nullptr;
					else
					{
						if (replacement->right != nullptr)
						{
							p_replace->left = replacement->right;
						}
						else
						{
							p_replace->left = nullptr;
						}
						replacement->right = node->right;
					}

					if (parent != nullptr)
					{
						// set nodeToBeDeleted parent to replacement
						if (parent->left == node)
							parent->left = replacement;
						else
							parent->right = replacement;
					}
					
					replacement->left = node->left;
				}
				if (node == m_root)
					m_root = replacement;
				delete node;
				node = nullptr;
			}
		}
		else // Is a leaf
		{
			if (parent)
			{
				if (node == parent->left)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			else
				m_root = nullptr;
			delete node;
			node = nullptr;
		}
		--m_size;
		return true;
	}

	bool searchRecursive(const T &data, BinarySearchTreeNode<T>* node)
	{
		if (node->data == data)
			return true;
		if (data < node->data)
		{
			if (node->left == nullptr)
				return false;
			return searchRecursive(data, node->left);
		}

		if (data > node->data)
		{
			if (node->right == nullptr)
				return false;
			return searchRecursive(data, node->right);
		}
	}

	BinarySearchTreeNode<T>* createNode(const T& value)
	{
		BinarySearchTreeNode<T>* node = new BinarySearchTreeNode<T>();
		node->data = value;
		return node;
	}

	void traverseInOrderRecursive(BinarySearchTreeNode<T>* node)
	{
		if (node != nullptr)
		{
			if (node->left != nullptr)
			{
				traverseInOrderRecursive(node->left);
			}

			std::cout << node->data << " ";

			if (node->right != nullptr)
			{
				traverseInOrderRecursive(node->right);
			}
		}
	}

	void traversePreOrderRecursive(BinarySearchTreeNode<T>* node)
	{
		if (node != nullptr)
		{
			std::cout << node->data << " ";

			if (node->left != nullptr)
			{
				traversePreOrderRecursive(node->left);
			}

			if (node->right != nullptr)
			{
				traversePreOrderRecursive(node->right);
			}
		}
	}

	void traversePostOrderRecursive(BinarySearchTreeNode<T>* node)
	{
		if (node != nullptr)
		{
			if (node->left != nullptr)
			{
				traversePostOrderRecursive(node->left);
			}

			if (node->right != nullptr)
			{
				traversePostOrderRecursive(node->right);
			}

			std::cout << node->data << " ";
		}
	}

public:
	BinarySearchTree()
		: m_root(nullptr),
		m_size(0)
	{

	}

	BinarySearchTree(const std::initializer_list<T> &list)
		: m_root(nullptr),
		m_size(0)
	{
		for (std::initializer_list<T>::iterator it = list.begin(); it != list.end(); ++it)
		{
			insert(*it);
		}
	}

	bool insert(const T& value)
	{
		if (m_root == nullptr)
		{
			m_root = createNode(value);
			++m_size;
			return true;
		}
		return insertRecursive(value, m_root);
	}
	bool erase(const T& value)
	{
		return eraseRecursive(nullptr, m_root, value);
	}
	bool search(const T& value)
	{
		return searchRecursive(value, m_root);
	}

	std::size_t size() const
	{
		return m_size;
	}

	bool traversal_pre_order()
	{
		if (m_root)
		{
			traversePreOrderRecursive(m_root);
			return true;
		}
		return false;
	}
	
	bool traversal_in_order()
	{
		if (m_root)
		{
			traverseInOrderRecursive(m_root);
			return true;
		}
		return false;
	}

	bool traversal_post_order()
	{
		if (m_root)
		{
			traversePostOrderRecursive(m_root);
			return true;
		}
		return false;
	}
};