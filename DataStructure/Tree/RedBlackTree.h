#pragma once
#include <iostream>
using namespace std;

enum Color {BLACK, RED, DOUBLE_BLACK};
struct Node
{
	Node* parent;
	Node* left;
	Node* right;
	Color color;
	int data;
};

class RBTree
{
private:
	Node* nil;
	void InsertRuleCheck(Node** root, Node* node);
	void DeleteRuleCheck(Node** root, Node* node);
	void RotateLeft(Node** root, Node* node);
	void RotateRight(Node** root, Node* node);
public:
	RBTree();
	~RBTree();
	void InsertNode(Node** root, int data);
	void DeleteNode(Node** root, int data);
	void PrintNode(Node* node);
	Node* SearchNode(Node* root, int data);
};