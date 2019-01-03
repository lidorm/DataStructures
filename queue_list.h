#pragma once
#include <iostream>
#include <math.h>
#include <ctime>    
#include <cstdlib>  
#include <random>

using namespace std;

struct node {

	int _data;
	node *next;
	node *prev;

	node() :next(NULL),prev(NULL),_data(0) {};
	~node() { delete next;};

};


class List {
private:
	node *head;  // limits of the list,head and tail allways clean from data!!
	node *tail;  //
public:
	List() :head(new node),tail(new node) { head->next = tail; tail->prev = head; };
	~List() {};

	bool isEmptyList();
	void insertNode(int num); //insert to front of the list.
	void deleteNode();
	void printList();
	int getMaxData();
	
};

class Queue_List {
	List list;
public:
	int  getRandomNumber();
	void Enqueue(int randomNum);
	void Dequeue();
	bool isEmpty();


	Queue_List() {};
	~Queue_List() {};
};
