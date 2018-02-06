#pragma once
#include <iostream>
using namespace std;

#define INTERGER 10
#define ALPHABET 26
const int TrieType = ALPHABET;

struct Node
{
	Node* next[TrieType];
	bool end;
};

class Trie
{
private:
	Node* root;
	int TrieIndex(int data);
	void DeleteTrie(Node* node);
public:
	Trie();
	~Trie();
	void InitTrie();
	void InsertTrie(string data);
	bool SearchTrie(string data);
};