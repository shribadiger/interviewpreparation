/*
 * Queue Implementation
 */
#include<iostream>
using namespace std;

template<class T>
class Queue {
	public:
		T data;
		Queue<T>* next;
		static Queue<T>* first;
		static Queue<T>* last;

		Queue(T value);
		void push(T value);
		T front();
		void pop();
		void printQueue();
};

template<class T> Queue<T>* Queue<T>::first = nullptr;
template<class T> Queue<T>* Queue<T>::last = nullptr;

template<class T>
Queue<T>::Queue(T value) {
	this->data = value;
	this->next = nullptr;
}

template<class T>
void Queue<T>::push(T value) {
	Queue<T>* item = new Queue<T>(value);
	if(last != nullptr){
		last->next = item;
	}
	last = item;
	if(first == nullptr) {
		first=last;
	}
}

template<class T> 
T Queue<T>::front() {
	if(first == nullptr) return -1;
	return first->data;
}

template<class T>
void Queue<T>::pop() {
	if(first == nullptr) {
		std::cout<<"\n[Warning]: No Elements in Queue\n";
	}
	first=first->next;
	if(first == nullptr){
		last = nullptr;
	}
}

template<class T>
void Queue<T>::printQueue() {
	std::cout<<"\n Queue Elements: ";
	Queue<T>* temp = first;
	while(temp != nullptr) {
		std::cout<<"\t"<<temp->data;
		temp=temp->next;
	}
}

int main() {
	Queue<int>* myQueue;
	myQueue->push(100);
	myQueue->push(200);
	myQueue->push(400);
	myQueue->printQueue();
	std::cout<<"\n Front  : "<<myQueue->front();
	myQueue->pop();
	myQueue->pop();
	myQueue->pop();
	std::cout<<"\n Front  : "<<myQueue->front();

	return 0;
}

