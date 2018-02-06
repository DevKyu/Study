#include "Tree.h"

Tree::Tree()
{
	RootNode = ParentNode = NULL;
}

Tree::~Tree()
{
	DeleteAll(&RootNode);
	RootNode = ParentNode = NULL;
}

/* Recursive */
void Tree::InsertNode(Node** root, int data)
{
	Node* node = *root;

	if (node != NULL)
	{
		if (data < node->data)
		{
			if (node->left != NULL)
				InsertNode(&node->left, data);
			else
			{
				node->left = new Node();
				node->left->data = data;
			}
		}
		else if (data > node->data)
		{
			if (node->right != NULL)
				InsertNode(&node->right, data);
			else
			{
				node->right = new Node();
				node->right->data = data;
			}
		}
		else
			cout << "Overlap Data Input : " << data << endl;
	}
	else
	{
		*root = new Node();
		(*root)->data = data;
		RootNode = ParentNode = *root;
	}
}

/* Non Recursive */
void Tree::InsertNode_(Node** root, int data)
{
	Node* node = *root;

	while (node)
	{
		ParentNode = node;

		if (data < node->data)
			node = node->left;
		else if (data > node->data)
			node = node->right;
		else
			return;
	}

	node = new Node();
	node->data = data;

	if (ParentNode)
	{
		if (node->data < ParentNode->data)
			ParentNode->left = node;
		else if (node->data > ParentNode->data)
			ParentNode->right = node;
	}
	else
		*root = RootNode = node;
}

/* Recursive */
void Tree::DeleteNode(Node** root, int data)
{
	if (*root)
	{
		Node* node = *root;

		if (data < node->data)
		{
			ParentNode = node;
			DeleteNode(&node->left, data);
		}
		else if (data > node->data)
		{
			ParentNode = node;
			DeleteNode(&node->right, data);
		}
		else
		{
			if (node->left == NULL && node->right == NULL)
			{
				if (ParentNode->left == node)
					delete ParentNode->left, ParentNode->left = NULL;
				else if (ParentNode->right == node)
					delete ParentNode->right, ParentNode->right = NULL;
				else
					delete *root, *root = RootNode = NULL;
			}
			else if (node->left == NULL || node->right == NULL)
			{
				Node** parent = NULL;
				Node* child = NULL;

				node->left != NULL ?
					child = node->left : child = node->right;

				if (ParentNode->left == node)
					parent = &ParentNode->left;
				else if (ParentNode->right == node)
					parent = &ParentNode->right;
				else
				{
					*root = RootNode = child;
					delete node;
					return;
				}

				*parent = child;
				delete node;
			}
			else
			{
				ParentNode = node;
				Node* ChildNode = node->right;

				while (ChildNode->left != NULL)
				{
					ParentNode = ChildNode;
					ChildNode = ChildNode->left;
				}

				node->data = ChildNode->data;
				DeleteNode(&ChildNode, ChildNode->data);
			}
		}
	}
}

/* Non Recursive */
void Tree::DeleteNode_(Node** root, int data)
{
	Node* node = *root;

	while (node != NULL && data != node->data)
	{
		ParentNode = node;

		if (data < node->data)
			node = node->left;
		else if (data > node->data)
			node = node->right;
	}

	if (ParentNode)
	{
		if (node->left == NULL && node->right == NULL)
		{
			if (ParentNode->left == node)
				delete node, ParentNode->left = NULL;
			else if (ParentNode->right == node)
				delete node, ParentNode->right = NULL;
		}
		else if (node->left == NULL || node->right == NULL)
		{
			Node** parent = NULL;
			Node* child = NULL;

			node->left != NULL ?
				child = node->left : child = node->right;

			if (ParentNode->left == node)
				parent = &ParentNode->left;
			else if (ParentNode->right == node)
				parent = &ParentNode->right;
			else
			{
				*root = RootNode = child;
				delete node;
				return;
			}

			*parent = child;
			delete node;
		}
		else
		{
			ParentNode = node;
			Node* ChildNode = node->right;

			while (ChildNode->left != NULL)
			{
				ParentNode = ChildNode;
				ChildNode = ChildNode->left;
			}

			node->data = ChildNode->data;
			DeleteNode_(&ChildNode, ChildNode->data);
		}
	}
	else
		delete *root, *root = RootNode = NULL;
}

void Tree::DeleteAll(Node** root)
{
	if (*root == NULL)
		return;

	DeleteAll(&(*root)->left);
	DeleteAll(&(*root)->right);
	delete *root;
	*root = NULL;
}

void Tree::PrintNode(Node* root)
{
	if (root == NULL)
		return;

	cout << root->data << endl;
	PrintNode(root->left);
	PrintNode(root->right);
}
