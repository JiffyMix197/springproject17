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
#include <iomanip>
using namespace std;

char getRandomnum();
string generatesku();           //method which generates a random SKU
string getsku();                //method which generates and returns a program usable random SKU
char getRandomnumletter();      //returns a random letter as char
string generateserial();        //function which generates a serial for an item
string getserial();             //method which generates and returns a program usable serial
int inputValid();               //checks if input is valid (is a number)
string checkForMoneySign();     //checks if price change request is only digits




struct ItemNode { //struct for managing items
    string name;
    string price;
    string revision;
    string model;
    string color;
    string serial;
    string SKU;
    ItemNode* nextItem;

    ItemNode() {

        name = "NA";
        price = "NA";
        revision = "NA";
        model = "NA";
        color = "NA";
        serial = "NA";
        SKU = "NA";
    }
};

class invLinkedList {  //linked list class

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
    void deleteNode(string itemToBeDeleted);
    invLinkedList* genSearch(string category, string specificInfo);
    void ClearList();
    string skuMatch(string sk, string n, string m, string c, string r);
    string priceMatch(string sku);

};

invLinkedList::invLinkedList() {  //sets head to NULL initially
    g_head = NULL;
};

ItemNode* invLinkedList::GetHead() {  //returns head of linkedlist
    return g_head;
};


void invLinkedList::addNode(ItemNode* i) {  //adds node to linked list
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

void invLinkedList::ClearList() {  //sets head to NULL
    g_head = NULL;
}

void invLinkedList::printWholeList() {  //prints linked list
    ItemNode* currentNode = g_head;
    if (currentNode) {

        const char separator = ' ';
        const int nameWidth = 15;

        cout << left << setw(nameWidth) << setfill(separator) << "COLOR";
        cout << left << setw(nameWidth) << setfill(separator) << "NAME";
        cout << left << setw(nameWidth) << setfill(separator) << "MODEL";
        cout << left << setw(nameWidth) << setfill(separator) << "YEAR";
        cout << left << setw(nameWidth) << setfill(separator) << "PRICE";
        cout << left << setw(nameWidth) << setfill(separator) << "SKU";
        cout << left << setw(nameWidth) << setfill(separator) << "SERIAL";
        cout << endl;
    }

    while (currentNode) {  //loop while currentNode, and prints node
        //cout << "\n" << endl;
        printNode(currentNode);
        currentNode=currentNode->nextItem;
    }
};

int invLinkedList::sizeOfList() {  //returns size of linked list as int
    ItemNode* currentNode = g_head;
    int size = 0;
    while (currentNode) {
        size++;
        currentNode = currentNode->nextItem;
    }
    return size;
};



void invLinkedList::printNode(ItemNode* n) {  //prints contents at given node


    const char separator = ' ';
    const int nameWidth = 15;

    cout << left << setw(nameWidth) << setfill(separator) << n->color;
    cout << left << setw(nameWidth) << setfill(separator) << n->name;
    cout << left << setw(nameWidth) << setfill(separator) << n->model;
    cout << left << setw(nameWidth) << setfill(separator) << n->revision;
    cout << left << setw(nameWidth) << setfill(separator) << n->price;
    cout << left << setw(nameWidth) << setfill(separator) << n->SKU;
    cout << left << setw(nameWidth) << setfill(separator) << n->serial;

    cout << endl;
};


void invLinkedList::deleteNode(string itemToBeDeleted) {  //deletes node based on string "itemToBeDeleted"
    ItemNode* p;
    ItemNode* q;
    ItemNode* z; //node to be deleted
    p = g_head;
    q = g_head;

    while (q != NULL && q->serial.string::compare(itemToBeDeleted) != 0) { //move p and q (who's one step forward)
        p = q;
        q = q->nextItem;
    }

    if (q != NULL) { //if data found, delete node
        if (q == g_head) {
            g_head = q->nextItem;
            delete q;
        }
        else {
            z = q;
            q = q->nextItem;
            p->nextItem = q;
            delete z;
        }
    }
    else { //if data NOT found
        std::cout << "Item not found!" << std::endl;
    }
}

string invLinkedList::skuMatch(string sk, string n, string m, string c, string r) {  //compares SKU, names, model,color and revision, and makes changes based on given SKU
    ItemNode *tempItem = g_head;
    string newSku=sk;
    while (tempItem) {
        if ((tempItem->name).compare(n) == 0 && (tempItem->model).compare(m) == 0 && (tempItem->color).compare(c) == 0 && (tempItem->revision).compare(r) == 0) {
            newSku = tempItem->SKU;
            break;
        }
        else
            tempItem = tempItem->nextItem;
    }

    return newSku;
}


string invLinkedList::priceMatch(string sku) {  //uses SKU to manipulate price data
    ItemNode *tempItem = g_head;
    string newPrice="empty";
    while (tempItem) {
        if ((tempItem->SKU).compare(sku) == 0) {
            newPrice = tempItem->price;
            break;
        }

        else {
            tempItem = tempItem->nextItem;
        }
    }
    return newPrice;
}


invLinkedList* invLinkedList::genSearch(string category, string specificInfo) {  //specifics found below

/* The use of this function is to mitigate the redundancy of searching in the code through
   efficient utilization of recursion to optimize the speed of the program by means of reduced
   operation time.  */


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