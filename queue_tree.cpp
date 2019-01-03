#include "queue_tree.h"

int bstree::getRandomNumber()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 1000);


	return dist6(rng);

}

void bstree::setRoot(nodeTree * node)
{
	this->root = node;

}

nodeTree* bstree::getRoot()
{
	return this->root;
}

nodeTree* bstree::search(nodeTree *root,int key)
{
	nodeTree *ptr = root;
	if (root == NULL || root->key == key) {
		return root;
	}
	else if (key > root->key) {
		return search(root->right, key);
	}
	else {
		return search(root->left, key);
	}
}

nodeTree* bstree::minimum(nodeTree *root)
{
	nodeTree * temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

nodeTree * bstree::maximum(nodeTree *root)
{
	if (root == NULL)
		return NULL;
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root;
}

nodeTree* bstree::Predecessor(nodeTree *root)
{
	if (root->right != NULL) {
		return minimum(root->right);
	}
	nodeTree *temp = root->parent;
	while (temp != NULL && root == temp->right) {
		root = temp;
		temp = temp->parent;
	}
	return temp;
}



void bstree:: insert(bstree T, nodeTree * nodeToInsert)
{
	nodeTree * y = NULL;
	nodeTree * x = T.root;
	
	while (x != NULL) {
		y = x;
		if (nodeToInsert->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	nodeToInsert->parent = y;
	if (y == NULL) {
	    setRoot(nodeToInsert);
	}
	else if(nodeToInsert->key<y->key) {
		y->left = nodeToInsert;
	}
	else {
		y->right = nodeToInsert;
	}

}

nodeTree* bstree::Successor(nodeTree * root) {
	if (root->right != NULL) {
		return minimum(root->right);
	}
	nodeTree *temp = root->parent;
	while (temp != NULL && root == temp->right) {
		root = temp;
		temp = temp->parent;
	}
	return temp;
}


nodeTree* bstree::Delete(bstree &T, nodeTree * nodeToDelete)
{
	nodeTree * tempY = NULL;
	nodeTree * tempX = NULL;
	if (nodeToDelete->left == NULL || nodeToDelete->right == NULL) {
		tempY = nodeToDelete;
	}
	else {
		tempY = Successor(nodeToDelete);
	}
	if (tempY->left != NULL) {
		tempX = tempY->left;
	}
	else {
		tempX = tempY->right;
	}
	if (tempX != NULL) {
		tempX->parent = tempY->parent;
	}
	if (tempY->parent == NULL) {
		T.root = tempX;
	}
	else if (tempY == tempY->parent->left) {
		tempY->parent->left = tempX;
	}
	else
		tempY->parent->right = tempX;

	if (tempY != nodeToDelete) {
		nodeToDelete->key = tempY->key;
 }
	return tempY;
}

bool bstree::isEmptyTree()
{
	if (root == NULL) {
		cout << "the tree is empty" << endl;
		return true;
	}
	return false;
}



void bstree::inOrder(nodeTree *root)
{
	
		if (root != NULL)
		{
			inOrder(root->left);
			cout<< root->key<<" ";
			inOrder(root->right);
		}
}


void Queue_Tree::Enqueue(bstree &T,int key)
{
	nodeTree * new_node = new nodeTree(key);
	T.insert(T, new_node);
	   
}

void Queue_Tree::Dequeue(bstree &T)
{	
	if (T.isEmptyTree()) {
		cout << "no elements to delete from the tree" << endl;
		return;
	}
	while (!T.isEmptyTree())
	{
		
		nodeTree * temp = tree.maximum(T.getRoot());
		/*nodeTree * temp2 = tree.search(temp, temp->key);*/
		cout << "node data to delete is: " << temp->key << endl;
		tree.Delete(T, temp);
	}

	
}

bool Queue_Tree::isEmpty()
{
	if (tree.isEmptyTree()) {
		return true;
	}
	return false;
}