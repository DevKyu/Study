#include "RedBlackTree.h"

RBTree::RBTree()
{
	root = nil =  NULL;
	nil = new Node();
}

RBTree::~RBTree()
{
	delete root;
	root = NULL;
}

void RBTree::InsertNode(Node** root, int data)
{
	Node* node = *root;
	Node* ParentNode = NULL;

	while (node != nil && node != NULL)
	{
		ParentNode = node;
		if (node->data < data)
			node = node->right;
		else if (node->data > data)
			node = node->left;
	}

	node = new Node();
	node->data = data;
	node->left = nil;
	node->right = nil;
	node->color = RED;
	node->parent = ParentNode;

	if (ParentNode)
	{
		if (node->data < ParentNode->data)
			ParentNode->left = node;
		else if (node->data > ParentNode->data)
			ParentNode->right = node;
	}
	else
	{
		*root = node;
		(*root)->left = nil;
		(*root)->right = nil;
		(*root)->color = BLACK;
	}

	InsertRuleCheck(root, node);
}

void RBTree::InsertRuleCheck(Node** root, Node* node)
{
	while (node->parent != NULL && node->parent->color == RED)
	{
		Node* gParent = node->parent->parent;
		if (node->parent == gParent->left)
		{
			Node* sibling = gParent->right;
			if (sibling->color == RED)
			{
				node->parent->color = BLACK;
				sibling->color = BLACK;
				gParent->color = RED;
				node = gParent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					RotateLeft(root, node);
				}

				node->parent->color = BLACK;
				gParent->color = RED;
				RotateRight(root, gParent);
			}
		}
		else
		{
			Node* sibling = gParent->left;
			if (sibling->color == RED)
			{
				node->parent->color = BLACK;
				sibling->color = BLACK;
				gParent->color = RED;
				node = gParent;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					RotateRight(root, node);
				}

				node->parent->color = BLACK;
				gParent->color = RED;
				RotateLeft(root, gParent);
			}
		}
	}
	(*root)->color = BLACK;
}

void RBTree::RotateLeft(Node** root, Node* node)
{
	Node* rightNode = node->right;
	node->right = rightNode->left;

	if (node->right != nil)
		node->right->parent = rightNode;

	rightNode->left = node;
	rightNode->parent = node->parent;
	node->parent = rightNode;

	if (rightNode->parent == NULL)
		*root = rightNode;
	else
	{
		if (node == rightNode->parent->left)
			rightNode->parent->left = rightNode;
		else
			rightNode->parent->right = rightNode;
	}
}

void RBTree::RotateRight(Node** root, Node* node)
{
	Node* leftNode = node->left;
	node->left = leftNode->right;

	if (node->left != nil)
		node->left->parent = leftNode;

	leftNode->right = node;
	leftNode->parent = node->parent;
	node->parent = leftNode;

	if (leftNode->parent == NULL)
		*root = leftNode;
	else
	{
		if (node == leftNode->parent->left)
			leftNode->parent->left = leftNode;
		else
			leftNode->parent->right = leftNode;
	}
}

void RBTree::DeleteNode(Node** root, int data)
{
	Node* node = SearchNode(*root, data);

	if (node->left != nil && node->right != nil)
	{
		Node* temp = node;
		node = node->left;
		while (node->right != nil)
			node = node->right;
		temp->data = node->data;
	}

	DeleteRuleCheck(root, node);
}


void RBTree::DeleteRuleCheck(Node** root, Node* node)
{
	while (node != NULL && (*root)->color != DOUBLE_BLACK)
	{
		Node** parentPos = NULL;
		node == node->parent->left ?
			parentPos = &node->parent->left :
			parentPos = &node->parent->right;

		if (node->color == BLACK)
		{
			Node* temp = node;
			Node* child = NULL;

			if (node->left != nil)
				child = node->left;
			else if (node->right != nil)
				child = node->right;
			else
			{
				child = new Node();
				child->left = nil;
				child->right = nil;
				child->color = BLACK;
			}

			child->parent = temp->parent;
			*parentPos = child;
			delete temp;

			if (child->color == RED)
			{
				child->color = BLACK;
				node = NULL;
			}
			else
			{
				child->color = DOUBLE_BLACK;
				node = child;
			}
		}
		else if (node->color == DOUBLE_BLACK)
		{
			Node* sibling = node->parent->left != node ?
				node->parent->left : node->parent->right;

			if (sibling->color == RED)
			{
				sibling->color = BLACK;
				node->parent->color = RED;
				RotateLeft(root, node->parent);
			}
			else
			{
				if (sibling->left->color == BLACK && sibling->right->color == RED)
				{
					sibling->color = node->parent->color;
					sibling->right->color = BLACK;
					node->parent->color = BLACK;
					RotateLeft(root, node->parent);

					*parentPos = nil;
					delete node;
					node = NULL;
				}
				else if (sibling->left->color == RED && sibling->right->color == BLACK)
				{
					sibling->color = RED;
					sibling->left->color = BLACK;
					RotateRight(root, sibling);
				}
				else if (sibling->left->color == BLACK && sibling->right->color == BLACK)
				{
					sibling->color = RED;
					node->color = BLACK;

					if (node->parent->color == RED)
					{
						node->parent->color = BLACK;
						*parentPos = nil;
						delete node;
						node = NULL;
					}
					else
					{
						node->parent->color = DOUBLE_BLACK;
						node = node->parent;
					}
				}
			}
		}
		else
		{
			*parentPos = nil;
			delete node;
			node = NULL;
		}
	}
}

Node* RBTree::SearchNode(Node* root, int data)
{
	while (root->data != data && root != nil)
	{
		if (data < root->data)
			root = root->left;
		else if (data > root->data)
			root = root->right;
	}

	if (root == nil)
		return NULL;
	else
		return root;
}

void RBTree::PrintNode(Node* root)
{
	if (root == nil)
		return;

	cout << root->data << " " << root->color << endl;
	PrintNode(root->left);
	PrintNode(root->right);
}
