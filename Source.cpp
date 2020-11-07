//YET CHUN FONG 300376480
#include <iostream>
using namespace std;


struct Node {
	int data;
	Node* next;
	Node() : data(0), next(NULL) {}
	Node(int x) : data(x), next(NULL) {}
	Node(int x, Node* next) : data(x), next(next) {}
	
};

Node* newNode(int data) {
	Node* a = new Node();
	a->data = data;
	a->next = NULL;
	return a; 
}

void insertion(Node** front, int data) {
	Node* a = newNode(data);
	a->next = *front;
	*front = a; 
}


Node* addTwo(Node* l1, Node* l2) {
	int aux = 0;
	Node* test = new Node(0); //Test is the first node in the result linked list 
	Node* result = test;

	while (l1 || l2) { //While l1 or l2 is true
		//If l1 is true then assign l1's data to a1, else assign 0
		int a1 = l1 ? l1->data : 0; //[2],[4],[3]
		int a2 = l2 ? l2->data : 0; //[5],[6],[4]
		
		aux += a1 + a2; //[5+2 = 7]
		
		result->next = new Node(aux % 10); //[7 % 10] = 7, store 7 in the linked list 
		aux = aux / 10; // 7/10 = 0.7, if addition exceed 10, then save it the next addition
		result = result->next; //Update curruent node to its next 
		l1 = l1 ? l1->next : l1; //Go to the next node in l1, if it's not NULL
		l2 = l2 ? l2->next : l2; // Go to the next node in l2, if it's not NULL
	}

	if (aux) { //After iterated through the linked list, if there is still value in aux 
		result->next = new Node(aux); //Create new node and place it at the front 
	}
	result = test->next; //Assign pointer to the next node in our result 
	delete test; //Delete the dummy node (0) created, Node*test 
	return result; //Return final result 
}

void print(Node* n) {
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}


int main() {
	Node* first = NULL;
	Node* second = NULL;
	Node* result = NULL;

	insertion(&first, 3);
	insertion(&first, 4);
	insertion(&first, 2);
	cout << "First Linked List: ";
	print(first);

	insertion(&second, 4);
	insertion(&second, 6);
	insertion(&second, 5);
	cout << "Second Linked List: ";
	print(second);

	result = addTwo(first, second);
	cout << "Result: ";
	print(result);

}