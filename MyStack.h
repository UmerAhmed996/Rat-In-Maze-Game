#pragma once
#include "Stack.h"

template<class T>
class MyStack : public Stack<T>
{
public:
	MyStack(int input = 0)
	{	Stack<T>::CurrentSize = 0;
		Stack<T>::stack = nullptr;
	}

	virtual void push(T value)
	{
		Stack<T>::CurrentSize++;
		Stack<T>::stack = dynamic_regrow(Stack<T>::CurrentSize, Stack<T>::stack);

		for (int i = Stack<T>::CurrentSize - 1; i >= 0; i--)
		{
			Stack<T>::stack[i + 1] = Stack<T>::stack[i];
		}

		Stack<T>::stack[0] = value;
	}

	virtual void pop()
	{
		for (int i = 0; i < Stack<T>::CurrentSize; i++)
		{
			Stack<T>::stack[i] = Stack<T>::stack[i + 1];
		}

		Stack<T>::CurrentSize--;
		Stack<T>::stack = shrink(Stack<T>::stack, Stack<T>::CurrentSize);
	}

	bool empty()
	{
		bool flag = false;

		if (Stack<T>::CurrentSize == 0)
		{
			flag = true;
		}

		return flag;
	}

	int size()
	{
		return Stack<T>::CurrentSize;
	}

	void Display()
	{
		cout << "Stack: ";
		for (int i = 0; i < Stack<T>::CurrentSize; i++)
		{
			cout << Stack<T>::stack[i] << ",";
		}
		cout << endl << endl;
	}

	T* dynamic_regrow(int size, T* arr)
	{
		T *ptr = nullptr;
		if (size == 1)
		{
			ptr = new T[size];
		}
		else
		{
			ptr = new T[size];
			copy_arr(arr, ptr, size);
		}
		return ptr;
	}

	void copy_arr(T * arr, T*ptr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			ptr[i] = arr[i];
		}
	}

	T* shrink(T *arr, int size)
	{
		T *ptr2 = nullptr;
		ptr2 = new T[size];
		copy_arr(arr, ptr2, size);

		return ptr2;
	}
};