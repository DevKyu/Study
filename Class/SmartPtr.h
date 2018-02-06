#pragma once

template <class T = int>
class SmartPtr
{
private:
	T* pointer;
public:
	SmartPtr(T* ptr) : pointer(ptr) { };
	~SmartPtr()
	{
		delete pointer;
		pointer = NULL;
	}
	T& operator*() { return *pointer; }			// Address Reference
	T* operator->() { return pointer; }			// Object Reference
	T* operator+(T index) { return pointer + index; }	// Array(Index)
	T operator[](int index) { return pointer[index]; }	// Array Reference
	SmartPtr& operator=(T data)				// Assign Data
	{
		*pointer = data;
		return *this;
	}
	SmartPtr& operator=(T* ptr)				// Assign Pointer
	{
		pointer = ptr;
		return *this;
	}
};