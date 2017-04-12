#include "SemesterProject.h"


struct itemNode{ //struct for managing items
    string name;
    string price;
    string dimension;
    string revision;
    string model;
    string color;
    string serial;
    string SKU;
    itemNode* nextItem;
};


int inputValid(){  //checks if input is valid (is a number)

    int choice;
    bool isValid = false;


    while(isValid == false) {  //loops while as long as the program doesn't know if choice is valid

        try {  //this may throw an exception if input is not valid
            cin >> choice;
                if(choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9) {
                    throw invalid_argument("Invalid Input, please only use integers");
            }

            isValid = true;
        }

        catch (exception e) {  //catches any exceptions
            cout << "Invalid input, please try again" << endl;
            choice = 0;
        }
    }

    cout << endl;
    return choice;
};



int main() {

    return 0;
}








typedef struct Node* node;

class invLinkedList {

    itemNode *g_head; //will point to head of data structure
    int g_sizeOfWarehouse = 0;

    bool initiateData() { //creates the linked list data structure

        int i = 0;
        itemNode *n;
        itemNode *temp;

        n = new itemNode;
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
            n = new itemNode;
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

    bool searchSKU(int SKUcheck) {


    }


    bool addNode(){

    }


    itemNode genSearch(string category, string specificInfo) {

        itemNode *n = g_head;
        locale loc;
        category = tolower(category, loc);
        invLinkedList tempList;


        if(category == "name"){
            for (int i = 0; i <= g_sizeOfWarehouse; i++) {  //loop used find a matching spec and print its values
                if ((n->name) == specificInfo) {



                    cout << "NAME:      " << n->name << endl;
                    cout << "PRICE:     " << n->price << endl;
                    cout << "DIMENSION: " << n->dimension << endl;
                    cout << "REVISION:  " << n->revision << endl;
                    cout << "MODEL:     " << n->model << endl;
                    cout << "COLOR:     " << n->color << endl;
                    cout << "SERIAL:    " << n->serial << endl;
                    cout << "SKU:       " << n->SKU << endl;

                    //i = g_sizeOfWarehouse;
                }

                if (i < g_sizeOfWarehouse) {
                    n = n->nextItem;
                }

                if (i == g_sizeOfWarehouse) {
                    cout << "ERROR: The " << category<< " " << specificInfo << "' NOT FOUND IN SYSTEM, PLEASE TRY AGAIN." << endl;
                }
            }
        }

        if(category == "price"){
            for (int i = 0; i <= g_sizeOfWarehouse; i++) {  //loop used find a matching spec and print its values
                if ((n->price) == specificInfo) {
                    cout << "NAME:      " << n->name << endl;
                    cout << "PRICE:     " << n->price << endl;
                    cout << "DIMENSION: " << n->dimension << endl;
                    cout << "REVISION:  " << n->revision << endl;
                    cout << "MODEL:     " << n->model << endl;
                    cout << "COLOR:     " << n->color << endl;
                    cout << "SERIAL:    " << n->serial << endl;
                    cout << "SKU:       " << n->SKU << endl;
                }

                if (i < g_sizeOfWarehouse) {
                    n = n->nextItem;
                }

                if (i == g_sizeOfWarehouse) {
                    cout << "ERROR: The " << category<< " " << specificInfo << "' NOT FOUND IN SYSTEM, PLEASE TRY AGAIN." << endl;
                }
            }
        }

        if(category == "dimension"){

        }

        if(category == "revision"){

        }

        if(category == "model"){

        }

        if(category == "color"){

        }

        if(category == "serial"){

        }

        if(category == "SKU"){

        }

    }
}