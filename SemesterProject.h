#ifndef SP_H
#define SP_H

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctime>
#include <time.h>
#include <random>
#include <cstring>
using namespace std;

struct ItemNode { //struct for managing items
	string name;
	string price;
	string dimension;
	string revision;
	string model;
	string color;
	string serial;
	string SKU;
	ItemNode* nextItem;

	ItemNode() {

		name = "NA";
		price = "NA";
		dimension = "NA";
		revision = "NA";
		model = "NA";
		color = "NA";
		serial = "NA";
		SKU = "NA";
	}
};

class invLinkedList {

private:
	ItemNode *g_head; //will point to head of data structure
	ItemNode *g_tail;

public:
	invLinkedList();
	ItemNode* GetHead();
	void addNode(ItemNode* i);
	void printWholeList();
	int sizeOfList();
	void printNode(ItemNode* n);
	void DeleteNode(int n);
	invLinkedList* genSearch(string category, string specificInfo);
	void ClearList();


};

	invLinkedList::invLinkedList() {
		g_head = NULL;
	};

	ItemNode* invLinkedList::GetHead() {
		return g_head;
	};


	void invLinkedList::addNode(ItemNode* i) {
		ItemNode* currentPointer;
		ItemNode* nodeToBeInserted = i;
		nodeToBeInserted->nextItem = NULL;
		if (g_head != NULL) { //if there are nodes in the linked list
			currentPointer = g_tail;
			currentPointer->nextItem = nodeToBeInserted;
			g_tail = nodeToBeInserted;
		}
		else { //if LinkedList contains nothing
			g_head = nodeToBeInserted;
			g_tail = nodeToBeInserted;
		}
	};

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	void invLinkedList::ClearList() {
		g_head = NULL;
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	void invLinkedList::printWholeList() {
		ItemNode* currentNode = g_head;
		if(currentNode)
		cout << "COLOR" << "\t" << "NAME" << "\t" << "MODEL" << "\t" << "YEAR" << "\t" << "PRICE" << "\t" << "SKU" << "\t\t" << "SERIAL" << endl;
		while (currentNode) {
			//cout << "\n" << endl;
			printNode(currentNode);
			currentNode=currentNode->nextItem;
		}
	};

	int invLinkedList::sizeOfList() {
		ItemNode* currentNode = g_head;
		int size = 0;
		while (currentNode) {
			size++;
			currentNode = currentNode->nextItem;
		}
		return size;
	};



	void invLinkedList::printNode(ItemNode* n) {

		
		/*cout << "NAME:      " << n->name << endl;
		cout << "PRICE:     " << n->price << endl;
		cout << "DIMENSION: " << n->dimension << endl;
		cout << "REVISION:  " << n->revision << endl;
		cout << "MODEL:     " << n->model << endl;
		cout << "COLOR:     " << n->color << endl;
		cout << "SERIAL:    " << n->serial << endl;
		cout << "SKU:       " << n->SKU << endl;*/

		cout << n->color << "\t" << n->name << "\t" << n->model << "\t" << n->revision << "\t" << n->price << "\t" << n->SKU << "\t" << n->serial << endl;
	};



	void invLinkedList::DeleteNode(int n) {
		ItemNode* temp1 = g_head;
		if (n == 1) {
			g_head = temp1->nextItem;
			free(temp1);
			return;
		}
		int i;
		for (i = 0; i < n - 2; i++)
			temp1 = temp1->nextItem;

		ItemNode * temp2 = temp1->nextItem;
		temp1->nextItem = temp2->nextItem;
		free(temp2);
	};



	//Initialize Linkedlist
	/*bool initiateData() { //creates the linked list data structure

		int i = 0;
		ItemNode *n;
		ItemNode *temp;

		n = new ItemNode;
		n->name = "NA";
		n->price = "NA";
		n->dimension = "NA";
		n->revision = "NA";
		n->model = "NA";
		n->color = "NA";
		n->serial = "NA";
		n->SKU = "NA";
		temp = n;
		g_head = n;

		while (i <= g_sizeOfWarehouse) { //loop to initialize all free lists
			n = new ItemNode;
			n->name = "NA";
			n->price = "NA";
			n->dimension = "NA";
			n->revision = "NA";
			n->model = "NA";
			n->color = "NA";
			n->serial = "NA";
			n->SKU = "NA";
			temp->nextItem = n;
			temp = temp->nextItem;
			i++;
		}

		return true;
	}
	*/





	invLinkedList* invLinkedList::genSearch(string category, string specificInfo) {


		ItemNode *tempItem = g_head;
		invLinkedList* tempListPtr = new invLinkedList();
		

		if (category == "name") {
			while (tempItem) {  //loop used to find a matching spec and print its values
				if ((tempItem->name).compare(specificInfo)==0) {

					ItemNode *tempNode = new ItemNode();
					tempNode->name = tempItem->name;
					tempNode->model = tempItem->model;
					tempNode->revision = tempItem->revision;
					tempNode->color = tempItem->color;
					tempNode->price = tempItem->price;
					tempNode->dimension = tempItem->dimension;
					tempNode->serial = tempItem->serial;
					tempNode->SKU = tempItem->SKU;

					tempListPtr->addNode(tempNode);

				}

				tempItem = tempItem->nextItem;
			}
		}
		
		if (category == "price") {
			while (tempItem) {  //loop used to find a matching spec and print its values
				if ((tempItem->price).compare(specificInfo) == 0) {

					ItemNode *tempNode = new ItemNode();
					tempNode->name = tempItem->name;
					tempNode->model = tempItem->model;
					tempNode->revision = tempItem->revision;
					tempNode->color = tempItem->color;
					tempNode->price = tempItem->price;
					tempNode->dimension = tempItem->dimension;
					tempNode->serial = tempItem->serial;
					tempNode->SKU = tempItem->SKU;
					tempListPtr->addNode(tempNode);

				}

				tempItem = tempItem->nextItem;
			}
		}

		if (category == "dimension") {
			while (tempItem) {  //loop used to find a matching spec and print its values
				if ((tempItem->dimension).compare(specificInfo) == 0) {

					ItemNode *tempNode = new ItemNode();
					tempNode->name = tempItem->name;
					tempNode->model = tempItem->model;
					tempNode->revision = tempItem->revision;
					tempNode->color = tempItem->color;
					tempNode->price = tempItem->price;
					tempNode->dimension = tempItem->dimension;
					tempNode->serial = tempItem->serial;
					tempNode->SKU = tempItem->SKU;
					tempListPtr->addNode(tempNode);

				}

				tempItem = tempItem->nextItem;
			}
		}

		if (category == "revision") {
			while (tempItem) {  //loop used to find a matching spec and print its values
				if ((tempItem->revision).compare(specificInfo) == 0) {

					ItemNode *tempNode = new ItemNode();
					tempNode->name = tempItem->name;
					tempNode->model = tempItem->model;
					tempNode->revision = tempItem->revision;
					tempNode->color = tempItem->color;
					tempNode->price = tempItem->price;
					tempNode->dimension = tempItem->dimension;
					tempNode->serial = tempItem->serial;
					tempNode->SKU = tempItem->SKU;
					tempListPtr->addNode(tempNode);

				}

				tempItem = tempItem->nextItem;
			}
		}

		if (category == "model") {
			while (tempItem) {  //loop used to find a matching spec and print its values
				if ((tempItem->model).compare(specificInfo) == 0) {

					ItemNode *tempNode = new ItemNode();
					tempNode->name = tempItem->name;
					tempNode->model = tempItem->model;
					tempNode->revision = tempItem->revision;
					tempNode->color = tempItem->color;
					tempNode->price = tempItem->price;
					tempNode->dimension = tempItem->dimension;
					tempNode->serial = tempItem->serial;
					tempNode->SKU = tempItem->SKU;
					tempListPtr->addNode(tempNode);

				}

				tempItem = tempItem->nextItem;
			}
		}

		if (category == "color") {

			while (tempItem) {  //loop used to find a matching spec and print its values
				if ((tempItem->color).compare(specificInfo) == 0) {

					ItemNode *tempNode = new ItemNode();
					tempNode->name = tempItem->name;
					tempNode->model = tempItem->model;
					tempNode->revision = tempItem->revision;
					tempNode->color = tempItem->color;
					tempNode->price = tempItem->price;
					tempNode->dimension = tempItem->dimension;
					tempNode->serial = tempItem->serial;
					tempNode->SKU = tempItem->SKU;
					tempListPtr->addNode(tempNode);

				}

				tempItem = tempItem->nextItem;
			}
		}

		if (category == "serial") {
			while (tempItem) {  //loop used to find a matching spec and print its values
				if ((tempItem->serial).compare(specificInfo) == 0) {

					ItemNode *tempNode = new ItemNode();
					tempNode->name = tempItem->name;
					tempNode->model = tempItem->model;
					tempNode->revision = tempItem->revision;
					tempNode->color = tempItem->color;
					tempNode->price = tempItem->price;
					tempNode->dimension = tempItem->dimension;
					tempNode->serial = tempItem->serial;
					tempNode->SKU = tempItem->SKU;
					tempListPtr->addNode(tempNode);

				}

				tempItem = tempItem->nextItem;
			}
		}

		if (category == "SKU") {
			while (tempItem) {  //loop used to find a matching spec and print its values
				if ((tempItem->SKU).compare(specificInfo) == 0) {

					ItemNode *tempNode = new ItemNode();
					tempNode->name = tempItem->name;
					tempNode->model = tempItem->model;
					tempNode->revision = tempItem->revision;
					tempNode->color = tempItem->color;
					tempNode->price = tempItem->price;
					tempNode->dimension = tempItem->dimension;
					tempNode->serial = tempItem->serial;
					tempNode->SKU = tempItem->SKU;
					tempListPtr->addNode(tempNode);

				}

				tempItem = tempItem->nextItem;
			}
		}

		return tempListPtr;

	};



#endif

