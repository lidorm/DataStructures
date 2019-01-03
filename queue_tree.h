#pragma once
#include <iostream>
#include <math.h>
#include <ctime>    
#include <cstdlib>  
#include <random>


using namespace std;


struct nodeTree
{
	int key;
	nodeTree *right;
	nodeTree *left;
	nodeTree *parent;

	nodeTree(int key) :right(NULL), left(NULL), parent(NULL),key(key) {};
	~nodeTree() {};
};

class bstree {
public:
	nodeTree *root;

	bstree():root(NULL) {};
	~bstree() {};
	
	void setRoot(nodeTree *node);
	nodeTree* getRoot();

	nodeTree* search(nodeTree *root,int key);
	nodeTree* minimum(nodeTree *root);
	nodeTree* maximum(nodeTree *root);
	nodeTree* Successor(nodeTree * root);
	nodeTree* Predecessor(nodeTree *root);
	void insert(bstree  T, nodeTree * nodeToInsert);
	nodeTree* Delete(bstree  &T, nodeTree * nodeToDelete);
	void inOrder(nodeTree * root);
	int getRandomNumber();
	bool isEmptyTree();
};


class Queue_Tree {
	
public:
	bstree tree;
	void Enqueue(bstree &T, int key);
	void Dequeue(bstree &T);
	bool isEmpty();


	Queue_Tree() {};
	~Queue_Tree() {};
};

