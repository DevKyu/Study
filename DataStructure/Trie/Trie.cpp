#include "Trie.h"

Trie::Trie()
{
	root = NULL;
}

Trie::~Trie()
{
	DeleteTrie(root);
	delete root;
	root = NULL;
}

void Trie::InitTrie()
{
	root = new Node();
}

int Trie::TrieIndex(int data)
{
	int index = 0;

	if (TrieType == ALPHABET)
	{
		if (data >= 65 && data <= 90)
			data = data + 32;

		index = data - 'a';
	}
	else if (TrieType == INTERGER)
		index = data - '0';

	return index;
}

void Trie::InsertTrie(string data)
{
	Node* T = root;
	int size = data.size();

	for (int i = 0; i < size; i++)
	{
		int index = TrieIndex(data[i]);

		if(T->next[index] == NULL)
			T->next[index] = new Node();

		T = T->next[index];
	}
	
	T->end = true;
}

void Trie::DeleteTrie(Node* node)
{
	for (int i = 0; i < TrieType; i++)
	{
		if (node->next[i])
		{
			DeleteTrie(node->next[i]);
			delete node->next[i];
			node->next[i] = NULL;
		}
	}
}

bool Trie::SearchTrie(string data)
{
	Node* T = root;
	int size = data.size();

	for (int i = 0; i < size; i++)
	{
		int index = TrieIndex(data[i]);

		if (T->next[index] != NULL)
			T = T->next[index];
		else
			return false;
	}

	if (T->end)
		return true;
	else
		return false;
}