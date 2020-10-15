#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node* last;
		Node(int input):data(input) {
			next = nullptr;
			last = nullptr;
		}

		void insertNode(int input);

		void display();
};

void Node::insertNode(int input) {
	if(next == nullptr) {
		next = new Node(input);
		last = next;
	}
	else {
		Node* node = new Node(input);
		last->next = node;
		last=node;
	}
}

void Node::display() {
	Node* temp = this;
	while(temp!=nullptr) {
	      std::cout<<"\t"<<temp->data;
       	      temp=temp->next;
	}
}
int main() {
	int numOfNodes;
	cin>>numOfNodes;
	Node* Head = nullptr;
	while(numOfNodes>0) {
		if(Head == nullptr) {
			Head = new Node(numOfNodes);
		}
		else {
			Head->insertNode(numOfNodes);
		}
		numOfNodes--;
	}
	Head->display();
	return 0;
}
			

