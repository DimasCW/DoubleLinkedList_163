#include<iostream>
#include<string>

using namespace std;
class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void retraverse();
	void hapus();
	void searchData();
};

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll of student: ";
	cin >> nim;
	cout << "\nEnter the name of student: ";
	cin >> nm;
	Node* newNode = new Node(); // step 1
	newNode -> noMhs = nim;//step 2
	newNode->name = nm;//step 2

	//insert a node in the beginning of a doubly - linked list
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;//step 3
		if (START != NULL)
			START->prev = newNode; //step4
		newNode->prev = NULL;//step 5
		START = newNode;//step 6
		return;
	}
	//inserting a node between two nodes in the list
	Node* current = START;//Step 1.a
	Node* previous = NULL;//Step 1.b
	while (current->next != NULL && current->next->noMhs < nim)//step 1.c
	{
		previous = current;//1.d
		current = current->next;//1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}
	newNode->next = current->next;//step 4
	newNode->prev = current;//step 5
	if (current->next != NULL)
		current->next->prev = newNode;//step6
	current->next = newNode;//step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL;// STEP 1.a
	*current = START;//step 1.b
	while (*current != NULL && (*current)->noMhs!= rollNo)
	{
		*previous = *current;//step 1.d
		*current = (*current)->next;//step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;//step 2
	if (previous != NULL)
		previous->next = current->next;//step 3
	else
		START = current->next;
	delete current;//step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return(START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\mList is Empty" << endl;
	else {
		cout << "\nrecords in ascending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << "" << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}