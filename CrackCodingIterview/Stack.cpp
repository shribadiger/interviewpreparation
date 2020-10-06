#include<iostream>
#include<exception>

class EmptyStackException : public std::exception {
	public:
		const char* what()
		{
			return "Empty Stack";
		}
};
template<class T>
class StackNode {
	public:
		T data;
		StackNode<T>* next;
		static StackNode<T>* top;

	public:
		StackNode<T>(T value):data(value) {
			this->next = nullptr;
		}
		void push(T value);
		void printStack();
		T pop();
};

template<class T> StackNode<T>* StackNode<T>::top = nullptr;


template<class T>
void StackNode<T>::push(T value) {
	std::cout<<"\n Push value to stack\n";
	StackNode<T>* temp = new StackNode<T>(value);
	temp->next = top;
	top=temp;
}

template<class T>
void StackNode<T>::printStack() {
	StackNode<T>*temp = top;
	while( temp != nullptr) {
		std::cout<<"\t"<<temp->data;
		temp=temp->next;
	}
}

template<class T>
T StackNode<T>::pop() {
	if(top == nullptr) {
		throw new EmptyStackException();
	}else {
		T temp = top->data;
		top=top->next;
		return temp;
	}
}

int main() {
	StackNode<int> * IntStack;
	IntStack->push(100);
	IntStack->push(200);
	IntStack->push(300);
        IntStack->printStack();
	IntStack->push(400);
	IntStack->push(500);
	IntStack->push(600);
        IntStack->printStack();
	try {
	std::cout<<"\n Pop :"<<IntStack->pop();
	std::cout<<"\n Pop :"<<IntStack->pop();
	std::cout<<"\n Pop :"<<IntStack->pop();
	std::cout<<"\n Pop :"<<IntStack->pop();
	std::cout<<"\n Pop :"<<IntStack->pop();
	std::cout<<"\n Pop :"<<IntStack->pop();
	std::cout<<"\n Pop :"<<IntStack->pop();
	}
	catch(EmptyStackException* e) {
		std::cout<<"\n Error: "<<e->what();
	}
        IntStack->printStack();
	return 0;
}
