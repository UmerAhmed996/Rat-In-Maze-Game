#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
protected:
	T* stack;
	int CurrentSize;

	int LenthCount(T* arr)
	{
		int size = 0;
		for (int i = 0; arr[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}

public:

	Stack(T* arr1 = nullptr, int b = 0)
	{
		if (arr1 != nullptr)
		{
			int size = LenthCount(arr1);
			arr1 = new T[size + 1];
			for (int i = 0; i < size; i++)
			{
				stack[i] = arr1[i];
			}
			stack[size] = '/0';
		}

		CurrentSize = b;
	}


	virtual void push(T) = 0;
	virtual void pop() = 0;
	~Stack()
	{
		
	}
};