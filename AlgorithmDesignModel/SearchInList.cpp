#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* link;
};

int SearchInList(Node* Iterator, int value){
	if(Iterator ==nullptr)
	{
		return 0;
	}
	if(Iterator->data == value){
		std::cout<<"\nElement found in list\n";
		return Iterator->data;
	}
	return SearchInList(Iterator->link,value);
}



int main() {
	struct Node* Head = nullptr;
	struct Node* Iterator = nullptr;
	int value = 10;
	while(value > 0) {
		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
		node->data = value;
		node->link = nullptr;
		if(Head == nullptr) {
			Head=node;
			Iterator = Head;
			value--;
			continue;
		}
		Iterator->link=node;
		Iterator=Iterator->link;
		value--;
	}
	Iterator = Head;
	while(Iterator != nullptr){
		std::cout<<"\t"<<Iterator->data;
		Iterator = Iterator->link;
	}

	int result = SearchInList(Head, 8);

	return 0;
}
