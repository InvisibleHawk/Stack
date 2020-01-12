#ifndef STACK_H
#define STACK_H

#include <cassert>
#include <iostream>

#include <iomanip>

template <typename T>
class Stack
{
private:
	T* stackPtr;		// stack pointer
	const int size;		// max quantity of elements in stack
	int top;			// number of current of elemnts stack
public:
	Stack(int = 10);
	Stack(const Stack<T>&);
	~Stack();

	inline void push(const T&);
	inline T pop();
	inline void printStack();
	inline const T& Peek(int) const;
	inline int getStackSize() const;
	inline T* getPtr() const;
	inline int getTop() const;
};

// Stack construct
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize)
{
	stackPtr = new T[size];	// initilize memory for stack
	top = 0;				// initilize current of element is 0
}

// Copy construct
template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) :
	size(otherStack.getStackSize())	// const initilization 
{
	stackPtr = new T[size];	// allocated memory by new stack
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++) {
		stackPtr[ix] = otherStack.getPtr()[ix];
	}
}

// Stack destructor function 
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr;
}

// Add element in stack function 
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// check stack size
	assert(top < size);	// number current of element must be less than stack size

	stackPtr[top++] = value;	//place element in the stack

}

// Remove elements from the stack function
template <typename T>
inline T Stack<T>::pop()
{
	// cheack stack size
	assert(top > 0);	// number current of element must be greater than 0

	stackPtr[--top];	// remove element from the stack
	
	/************ Without this not working ***************/
	return stackPtr[top];
}

// Return n element from top of the stack function 
template <class T>
inline const T& Stack<T>::Peek(int nom) const
{
	assert(nom <= top);

	return stackPtr[top - nom];	// return n element of stack

}

// The output of the stack on the screen
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
	{
		cout << "|" << setw(4) << stackPtr[ix] << endl;
	}
}

// Return size the stack
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// Return pointer on the stack (for copy construction)
template <typename T>
inline T* Stack<T>::getPtr() const
{
	return stackPtr;
}

// Return size the stack
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}



#endif // STACK_H
