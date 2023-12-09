#pragma once
template<typename T>
class Stack
{
private:
	T* stack;
	int top;
	int size;
public:
	Stack(int);
	~Stack();
	T Top();
	void pop();
	void push(T);
	bool isEmpty();
	bool isFull();
	void resize();
	void shrink();
	void display();
};

