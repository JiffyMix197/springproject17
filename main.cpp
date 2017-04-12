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

static vector<string> skugenerated;
int numofsku=0;
static const char numpool[] = "0123456789";
static int numpoolsize = sizeof(numpool) - 1;




char getRandomnum() {
    return numpool[rand() % numpoolsize];
}
string generatesku() {
    int skulength = 6;
    srand(time(0));
    string sku;
    for (int i = 0; i < skulength; i++) {
        sku += getRandomnum();
    }
    return sku;
}
int getsku() {
    bool loopbreak = true;
    while (loopbreak) {
        string sku = generatesku();
        int i=0;
        if (skugenerated.size() == 0) {
            skugenerated.insert(skugenerated.begin() + numofsku, sku);
            numofsku++;
            return stoi(sku);
        }
        else {
            for (i = 0; i < skugenerated.size(); i++) {
                if (sku == skugenerated[i]) {
                    break;
                }
            }
            if (i == skugenerated.size()) {
                skugenerated.insert(skugenerated.begin() + numofsku, sku);
                numofsku++;
                return stoi(sku);
            }
        }
    }
}
static vector<string> serialgenerated;
int numofserial = 0;
static const char numletterpool[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static int numletterpoolsize = sizeof(numletterpool) - 1;
char getRandomnumletter() {
    return numletterpool[rand() % numletterpoolsize];
}
string generateserial() {
    int seriallength = 16;
    srand(time(0));
    string serial;
    for (int i = 0; i < seriallength; i++) {
        serial += getRandomnumletter();
    }
    return serial;
}
string getserial() {
    bool loopbreak = true;
    while (loopbreak) {
        string serial = generateserial();
        int i = 0;
        if (serialgenerated.size() == 0) {
            serialgenerated.insert(serialgenerated.begin() + numofserial, serial);
            numofserial++;
            return serial;
        }
        else {
            for (i = 0; i < serialgenerated.size(); i++) {
                if (serial == serialgenerated[i]) {
                    break;
                }
            }
            if (i == serialgenerated.size()) {
                serialgenerated.insert(serialgenerated.begin() + numofserial, serial);
                numofserial++;
                return (serial);
            }
        }
    }
}


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
    cout << getsku() << endl;
    cout << getserial() << endl;




/*    bool isRunning = true;
    bool hasSpace = true;
    string itemName;

    cout << "Hello, and welcome to warehouse inventory manager 2000!" << endl;
    cout << "Please enter the size of your warehouse: ";

    int input = inputValid();


    while(isRunning == true){
        cout << "Please select from the following options:\n";
        cout << "1) Add item to inventory\n";
        cout << "2) Remove item from inventory\n";
        cout << "3) Print contents of warehouse\n";
        cout << "4) Exit program" << endl;

        input = inputValid();

        if(input == 1){
            cout << "Please enter name of item: ";
            cin >> itemName;   //need to add input verification
            hasSpace = false;

            for(int i = 0; i < g_sizeOfWarehouse; i++){ //looks for the next empty space in warehouse
                if(warehouse[i] == "xxxx"){
                    warehouse[i] = itemName;
                    i = warehouseSize;
                    hasSpace = true;
                }
            }

            if(hasSpace == false){
                cout << "Warning, no room in warehouse.  Please remove items and then try again\n" << endl;
            }

        }

        else if(input == 2){
            cout << "Please enter name of item: ";
            cin >> itemName;  //add input verification

            for(int i = 0; i < warehouseSize; i++){ //looks for the next empty space in warehouse
                if(warehouse[i] == itemName){
                    warehouse[i] = "xxxx";
                }
            }

            cout << "Item removed from list\n" << endl;

        }

        else if(input == 3){

            for(int i = 0; i < warehouseSize; i++){ //looks for the next empty space in warehouse
                cout << "item #";
                cout << i+1;
                cout << " ";
                cout << warehouse[i] << endl;
            }
            cout << endl;

        }

        else if (input == 4) {
            isRunning = false;
        }

        else {
            cout << "Error, not a valid option\n" << endl;
        }
    }
*/

    //data structure may be better, and more input verification is needed
    //at least at the moment a dynamic array works
    return 0;
}








typedef struct Node* node;

class invLinkedList {


    void PrintNode(itemNode* n){


        cout << "NAME:      " << n->name << endl;
        cout << "PRICE:     " << n->price << endl;
        cout << "DIMENSION: " << n->dimension << endl;
        cout << "REVISION:  " << n->revision << endl;
        cout << "MODEL:     " << n->model << endl;
        cout << "COLOR:     " << n->color << endl;
        cout << "SERIAL:    " << n->serial << endl;
        cout << "SKU:       " << n->SKU << endl;
    }



    itemNode *g_head; //will point to head of data structure
    int g_sizeOfWarehouse = 0;


    void DeleteNode(int n){
        itemNode* temp1 = g_head;
        if(n == 1){
            g_head = temp1->nextItem;
            free(temp1);
            return;
        }
        int i;
        for(i = 0; i < n-2;i++)
            temp1=temp1->nextItem;

        itemNode * temp2 = temp1->nextItem;
        temp1->nextItem = temp2->nextItem;
        free(temp2);
    }




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
};