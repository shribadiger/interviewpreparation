#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
};

struct Node* Head = nullptr;

void prepareTree(int value) {
	struct Node* Iterator = Head;
	while(value > 0){
		if(Head == nullptr){
			struct Node* node = (struct Node*)malloc(sizeof(struct Node));
			node->parent=nullptr;
			node->left = nullptr;
			node->right = nullptr;
			node->data = value;
			value--;
		}
		
		value--;
	}
}
