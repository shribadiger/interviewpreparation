#include<iostream>

class Node {
	public:
		int data;
		Node* next;

		Node(int input):data(input) {
			this->next = nullptr;
		}
};

void insertNode(Node** Head, int value) {

	if(*Head == nullptr) {
		*Head=new Node(value);
	} else {
		Node* temp = *Head;
		while(temp->next !=nullptr){
			temp =temp->next;
		}
		temp->next=new Node(value);
	}
}

void deleteNode(Node** Head, int value) {
	if(*Head == nullptr) {
		std::cout<<"\n Empty List";
	}
	else if((*Head)->data == value) {
		*Head=(*Head)->next;
	}
	else {
		Node* curr = *Head;
		Node* prev = *Head;
		while(curr->next != nullptr) {
			if(curr->data == value) {
				prev->next=curr->next;
			}
			prev=curr;
			curr=curr->next;
		}
	}
}

void printList(Node* Head) {
	Node* temp = Head;
	if(temp == nullptr) {
		std::cout<<"\n Empty Linked List\n";
	}
	else {
		std::cout<<std::endl;
		while(temp!=nullptr){
			std::cout<<"\t"<<temp->data;
			temp=temp->next;
		}
	}
	std::cout<<"\n";

}

int main() {
	Node* Head = nullptr;
	int value=10;
	for(int i=0;i<value;i++) {
		insertNode(&Head,i);
	}
	printList(Head);
	deleteNode(&Head,5);
	deleteNode(&Head,9);
	deleteNode(&Head,1);
	deleteNode(&Head,0);
	printList(Head);

	return 0;
}
