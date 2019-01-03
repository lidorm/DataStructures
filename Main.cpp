#include "queue_tree.h"
#include "queue_list.h"


int main() {

	Queue_Tree qt;
	Queue_List ql;
	int randomNumber;

	//eneueu ranodom numbers to the list/tree
	for (int i = 0; i < 50; i++) {
		randomNumber =ql.getRandomNumber();
		cout<<"Enqueue number: "<<randomNumber<<endl;
		qt.Enqueue(qt.tree, randomNumber);
		ql.Enqueue(randomNumber);
	}
	cout << endl;

	//check if the list/tree is empty after insert
	if (!ql.isEmpty()) {
		cout << "the list is not empty" << endl;
	}

	if (!qt.isEmpty()) {
		cout << "the tree is not empty" << endl;
	}

	//dequeue all from list and than from tree
	ql.Dequeue();
	qt.Dequeue(qt.tree);
	
	//check if the list/tree is empty after delete
	if (!ql.isEmpty()) {
		cout << "the list is not empty" << endl;
	}
	
	if (!qt.isEmpty()) {
		cout << "the tree is not empty" << endl;
	}
	


	getchar();
	system("pasue");
	return 0;
}