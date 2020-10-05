#include<iostream>
#include<queue>
using namespace std;

class Node {
	public:
	int key;
	Node* left;
	Node* right;
	Node(int key) {
		this->key=key;
		this->left=nullptr;
		this->right=nullptr;
	}
};

void insertNode(Node* root, int key) {
	if(root == nullptr){
		root=new Node(key);
	}
	else {
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			Node* temp = q.front();
			q.pop();

			//check for left tree
			if(temp->left == nullptr){
				temp->left=new Node(key);
				break;
			}else {
				q.push(temp->left);
			}

			//check for right tree
			if(temp->right == nullptr){
				temp->right=new Node(key);
				break;
			} else {
				q.push(temp->right);
			}
		}
	}
}

void printTree(Node* root) {
	if(root == nullptr) {
		std::cout<<"\n Empty Tree\n";
	}

	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->left != nullptr){
			q.push(temp->left);
		}
		if(temp->right != nullptr) {
			q.push(temp->right);
		}
		std::cout<<"\t"<<temp->key;
	}
}

void inOrder(Node* root) {
	if(root == nullptr){
		return;
	}
	inOrder(root->left);
	if(root->key != -1)
	   std::cout<<" "<<root->key;
	inOrder(root->right);
}
void Swap(Node** leftNode, Node** rightNode){
	Node* temp = *leftNode;
        *leftNode = *rightNode;
	*rightNode = temp;
}

void swapEveryKLevelUtil( Node *root, int level, int k) 
{ 
    // base case 
    if (root== nullptr|| 
            (root->left==nullptr&& root->right==nullptr) ) 
        return ; 
  
    //if current level + 1  is present in swap vector 
    //then we swap left & right node 
    if ( (level + 1) % k == 0) 
        Swap(&root->left, &root->right); 
  
    // Recur for left and right subtrees 
    swapEveryKLevelUtil(root->left, level+1, k); 
    swapEveryKLevelUtil(root->right, level+1, k); 
}
 
int main() {
	int numOfElements;
	cin>>numOfElements;

	//root Node
	Node* root = new Node(1);
	for(int i=0;i<numOfElements;i++) {
		int value = 0;
		cin>>value;
		insertNode(root,value);
	}
	inOrder(root);

	int TestCases = 0;
	for(int i=0; i<TestCases;i++) {
		int k=0;
		cin>>k;
		swapEveryKLevelUtil(root,1,k);
		inOrder(root);
	}
	return 0;
}
