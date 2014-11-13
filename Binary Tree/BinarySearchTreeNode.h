#pragma once

template<typename T>
struct BinarySearchTreeNode
{
	T data;
	BinarySearchTreeNode<T>* left;
	BinarySearchTreeNode<T>* right;

	bool hasChildren()
	{
		return right != nullptr || left != nullptr;
	}

	BinarySearchTreeNode()
	{
		left = nullptr;
		right = nullptr;
	}
};