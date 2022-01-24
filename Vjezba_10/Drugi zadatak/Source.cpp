#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

template <class T> class Stack
{
	
	public:
		Stack();

		// add element to stack
		void push(T k);

		// remove top element from stack
		T pop();

		// check whether stack is full
		bool isFull();

		// check whether stack is empty
		bool isEmpty();

	private:
		int top;

		// initialising stack(array) of given size
		T st[SIZE];
};

// initialise top to -1(default constructor)
template <class T> Stack<T>::Stack() { top = -1; }

// add element element k to stack
template <class T> void Stack<T>::push(T k)
{
	if (isFull())
	{
		cout << "Stack is full\n";
	}

	// Inserted element
	cout << "Inserted element " << k << endl;

	top = top + 1;

	st[top] = k;
}

// check if the stack is empty
template <class T> bool Stack<T>::isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class T> bool Stack<T>::isFull()
{
	// untill top in inside the stack
	if (top == (SIZE - 1))
		return 1;
	else
		return 0;
}

template <class T> T Stack<T>::pop()
{
	// a variable to store popped element
	T popped_element = st[top];

	// decreasing the top as element is getting out from the stack
	top--;

	return popped_element;
}


int main()
{
	Stack<int> integer_stack;
	Stack<string> string_stack;

	integer_stack.push(10);
	integer_stack.push(55);
	integer_stack.push(305);

	string_stack.push("auto");
	string_stack.push("motor");
	string_stack.push("avion");

	cout << integer_stack.pop() << " is removed from stack" << endl;
	cout << string_stack.pop() << " is removed from stack " << endl;
}
