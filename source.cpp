// #include<iostream>
// using namespace std;
// struct node {
// 	int info;
// 	node* left;
// 	node* right;
// };
// class BinaryTree {
// private:
// 	node* root;
// public:
// 	BinaryTree() {
// 		root = NULL;
// 	}
// 	BinaryTree(node* ptr) {
// 		root = ptr;
// 	}
// 	BinaryTree(int val) {
// 		root = new node;
// 		root->info = val;
// 		root->left = root->right = NULL;
// 	}
// 	BinaryTree(node* lbt, node* rbt, int data) {
// 		root = new node;
// 		root->info = data;
// 		root->left = lbt;
// 		root->right = rbt;
// 	}
// 	bool isEmpty() {
// 		if (root == NULL) {
// 			return true;
// 		}
// 		return false;
// 	}
// 	BinaryTree Lchild() {
// 		if (isEmpty()) {
// 			cout << "Error";
// 		}
// 		else {
// 			return BinaryTree(root->left);
// 		}
// 	}
// 	int data() {
// 		if (isEmpty()) {
// 			cout << "Root is empty";
// 		}
// 		return root->info;
// 	}
// 	BinaryTree Rchild() {
// 		if (isEmpty()) {
// 			exit(0);
// 		}
// 		return BinaryTree(root->right);
// 	}
// };
// int main() {
// 	node* left = new node{ 5, NULL, NULL };
// 	node* right = new node{ 15, NULL, NULL };
// 	BinaryTree tree(left, right, 10);

// 	cout << "Root: " << tree.data() << endl;
// 	cout << "Left Child: " << tree.Lchild().data() << endl;
// 	cout << "Right Child: " << tree.Rchild().data() << endl;
// 	return 0;
// }

#include<iostream>
using namespace std;
struct node {
	int info;
	node* right, * left;
};
class BinaryTree {
private:
	node* root;
public:
	BinaryTree() {
		root = NULL;
	}
	node* makeTree(int x) {
		node* p = new node;
		p->info = x;
		p->left = p->right = NULL;
		return p;
	}
	void setRoot(node* p) {
		root = p;
	}
	node* getRoot() {
		return root;
	}
	void setLeft(node* p, int x) {
		if (p == NULL) {
			cout << "Node not found";
		}
		else if (p->left != NULL) {
			cout << "Already present";
		}
		else {
			p->left = makeTree(x);
		}
	}
	void setRight(node* p, int x) {
		if (p == NULL) {
			cout << "Node not found";
		}
		else if (p->right != NULL) {
			cout << "Already present";
		}
		else {
			p->right = makeTree(x);
		}
	}
	void inTrav(node* p) {
		if (p != NULL) {
			inTrav(p->left);
			cout << p->info << " ";
			inTrav(p->right);
		}
	}
	void preTrav(node* p) {
		if (p != NULL) {
			cout << p->info << " ";
			preTrav(p->left);
			preTrav(p->right);
		}
	}
	void posTrav(node* p) {
		if (p != NULL) {
			posTrav(p->left);
			posTrav(p->right);
			cout << p->info << " ";
		}
	}
	void inOrder() {
		cout << "The inorder traversal is: ";
		inTrav(root);
		cout << endl;
	}
	void preOrder() {
		cout << "The preorder traversal is: ";
		preTrav(root);
		cout << endl;
	}
	void postOrder() {
		cout << "The postorder traversal is: ";
		posTrav(root);
		cout << endl;
	}
};
int main() {

	BinaryTree tree;
	node*root=tree.makeTree(10);
	tree.setRoot(root);
	tree.setLeft(root, 20);
	tree.setRight(root, 30);
	tree.setLeft(root->left, 40);
	tree.setRight(root->left, 50);
	tree.setLeft(root->right, 60);
	tree.setRight(root->right, 70);

	tree.inOrder();
	tree.preOrder();
	tree.postOrder();
}