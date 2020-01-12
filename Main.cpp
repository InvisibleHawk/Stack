#include <iostream>

using namespace std;

#include "Stack.h"

int main()
{
	Stack<char> stackSymbol(5);
	int ct = 0;
	char ch;

	while (ct++ < 5)
	{
		cin >> ch;
		stackSymbol.push(ch);	// Place elements in the stack
	}

	cout << "\n";

	stackSymbol.printStack();	// Stack print

	cout << "\n\nRemove element from the stack\n";
	stackSymbol.pop();

	stackSymbol.printStack();	// Stack print

	Stack<char> newStack(stackSymbol);

	cout << "\n\nThe copy construction worked!\n";
	newStack.printStack();

	cout << "The second element in queue: " << newStack.Peek(2) << endl;

	return 0;
}