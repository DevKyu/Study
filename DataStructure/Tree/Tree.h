#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class Tree
{
private:
	Node* RootNode;
	Node* ParentNode;
public:
	Tree();
	~Tree();
	void InsertNode(Node** root, int data);
	void InsertNode_(Node** root, int data);
	void DeleteNode(Node** root, int data);
	void DeleteNode_(Node** root, int data);
	void DeleteAll(Node** root);
	void PrintNode(Node* root);
};