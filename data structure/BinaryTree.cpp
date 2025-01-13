#include<bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Node { 
	int key;
	Node* left;
	Node* right;
	Node(int item) {
		key=item;
		left=NULL;
		right=NULL;
	}
};

Node* insert(Node* node, int key) {
	if(node==NULL)
		return new Node(key);
	if(node->key<=key)
		node->right = insert(node->right, key);
	else
		node->left = insert(node->left, key);
	return node;
}

Node* search(Node* node, int key) { 
	if(node==NULL||node->key==key)
		return node;
	if(node->key<key)
		return search(node->right, key);
	return search(node->left, key);
}

Node* getSucessor(Node* node) {
  node = node->right;
  while (node!=NULL&&node->left!=NULL) 
    node = node->left;
  return node;
}

Node* delNode(Node* root, int val) {
  if (root==NULL)
    return root;
  if (root->key>val)
	  root->left = delNode(root->left, val);
  else if (root->key<val)
	  root->right = delNode(root->right, val);
  else {
	  if (root->left==NULL) {
		  Node* temp = root->right;
		  delete root;
		  return temp;
	  }
	  else {
	  	if (root->left==NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		if (root->right==NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* succ = getSucessor(root);
		root->key = succ->key;
		root->right = delNode(root->right, succ->key);
	  }
  }
  return root;
}

int main() { _
	Node* root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 5);
	cout << root->key << '\n'; // 10
	cout << root->right->key << '\n'; // 20
	cout << root->left->key << '\n'; // 5

	// ---------------------------------------------------

	if(search(root, 5)!=NULL)
		cout << "item 5 encontrado"; // <-- saida
	else
		cout << "item nao encontrado";
	cout << '\n';
	if(search(root, 35)!=NULL)
		cout << "item 35 encontrado";
	else
		cout << "item nao encontrado"; // <-- saida
	cout << '\n';
	
	 // --------------------------------------------------

	delNode(root, 20);
	if(search(root, 20)!=NULL)
		cout << "item 20 encontrado";
	else
		cout << "item nao encontrado"; // <- saida
	cout << '\n';
}