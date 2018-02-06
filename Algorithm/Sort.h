#pragma once
#include <iostream>
using namespace std;

class Sort
{
public:
	void InsertionSort(int* arr, int length);
	void SelectionSort(int* arr, int length);
	void BubbleSort(int* arr, int length);
	void QuickSort(int* arr, int left, int right);
	void Swap(int& x, int& y) { int t = x; x = y; y = t; };
};