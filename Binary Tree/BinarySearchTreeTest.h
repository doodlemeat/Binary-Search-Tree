#pragma once
#include <iostream>
#include <string>

template<typename T>
void search(BinarySearchTree<T> bst, T data, bool expected, const std::string& message)
{
	std::cout << message << " - ";
	bool got = bst.search(data);
	if (got != expected)
	{
		std::cout << "Fail! ";
	}
	else
	{
		std::cout << "Success! ";
	}
	std::cout << "Got " << got << ", expected " << expected << std::endl;
}

template<typename T>
void insert(BinarySearchTree<T>& bst, T data, bool expected, const std::string& message)
{
	std::cout << message << " - ";
	bool got = bst.insert(data);
	if (got != expected)
		std::cout << "Fail! ";
	else
		std::cout << "Success! ";
	std::cout << "Got " << got << ", expected " << expected << std::endl;
}

template<typename T>
void erase(BinarySearchTree<T>& bst, T data, bool expected, const std::string& message)
{
	std::cout << message << " - ";
	bool got = bst.erase(data);
	if (got != expected)
	{
		std::cout << "Fail! ";
	}
	else
	{
		std::cout << "Success! ";
	}
	std::cout << "Got " << got << ", expected " << expected << std::endl;
}

template<typename T>
void traverseInOrder(BinarySearchTree<T>& bst, const std::string& message)
{
	std::cout << message << " - ";
	bst.traversal_in_order();
	std::cout << std::endl;
}

template<typename T>
void traversePreOrder(BinarySearchTree<T>& bst, const std::string& message)
{
	std::cout << message << " - ";
	bst.traversal_pre_order();
	std::cout << std::endl;
}

template<typename T>
void traversePostOrder(BinarySearchTree<T>& bst, const std::string& message)
{
	std::cout << message << " - ";
	bst.traversal_post_order();
	std::cout << std::endl;
}

template<typename T>
void size_equal_to(int expected, BinarySearchTree<T>& bst)
{
	std::cout << "Testing size - ";
	int got = bst.size();
	if (got != expected)
	{
		std::cout << "Fail! ";
	}
	else
	{
		std::cout << "Success! ";
	}
	std::cout << "Got " << got << ", expected " << expected << std::endl;
}