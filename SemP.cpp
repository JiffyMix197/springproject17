#include "SemesterProject.h"





static vector<string> skugenerated;
int numofsku = 0;
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
string getsku() {
	bool loopbreak = true;
	while (loopbreak) {
		string sku = generatesku();
		int i = 0;
		if (skugenerated.size() == 0) {
			skugenerated.insert(skugenerated.begin() + numofsku, sku);
			numofsku++;
			return sku;
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
				return sku;
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


int inputValid() {  //checks if input is valid (is a number)

	string choice;
	bool isValid = false;


	while (isValid == false) {  //loops while as long as the program doesn't know if choice is valid

		try {  //this may throw an exception if input is not valid
			cin >> choice;
			if (choice.compare("1")&& choice.compare("2")&& choice.compare("3")&& choice.compare("4")&& choice.compare("5")&& choice.compare("6") && choice.compare("7") && choice.compare("8") && choice.compare("9") && choice.compare("10")) {
				throw invalid_argument("Invalid Input, please only use integers");
			}

			isValid = true;
		}

		catch (exception e) {  //catches any exceptions
			cout << "Invalid input, please try again" << endl;
		}
	}

	cout << endl;
	return stoi(choice);
};


int main() {


	invLinkedList* inventory = new invLinkedList();
	bool isRunning = true;
	
	
	while (isRunning) {
		cout << "\n\n\t***********\n";
		cout << "\n\tMAIN MENU\n";
		cout << "\n\t***********\n";
		cout << "\tPlease chose one of the following options:\n\n";
		cout << "\t1) Add item to inventory\n";
		cout << "\t2) Return size of list\n";
		cout << "\t3) Print contents of warehouse\n";
		cout << "\t4) Search contents of warehouse\n";
		cout << "\t5) Exit program" << endl;

		ItemNode* tempItem = new ItemNode();
		invLinkedList* tempList = new invLinkedList();
		string tempdata1;
		string tempdata2;
		string tempdata3;
		string option;
		string newData;

		int lSize = 0;
		bool firstPass=true;
		
		switch (inputValid())
		{
			tempList->ClearList();
		case 1:
			cout << "Adding Item" << endl;
			cout << "Please enter the name of the item:" << endl;
			cin >> newData;
			tempItem->name = newData;

			cout << "Please enter the model of the item:" << endl;
			cin >> newData;
			tempItem->model = newData;

			cout << "Please enter the revision of the item:" << endl;
			cin >> newData;
			tempItem->revision = newData;

			cout << "Please enter the color of the item:" << endl;
			cin >> newData;
			tempItem->color = newData;

			cout << "Please enter the dimension of the item:" << endl;
			cin >> newData;
			tempItem->dimension = newData;

			cout << "Please enter the price of the item:" << endl;
			cin >> newData;
			tempItem->price = newData;

			tempItem->SKU = getsku();

			tempItem->serial = getserial();

			inventory->addNode(tempItem);
			break;

		case 2:
			cout << "Returnin size of inventory" << endl;
			
			cout << "Size of inventory is: " << inventory->sizeOfList() << endl;
			break;

		case 3:
			cout << "Printing Invetory." << endl;

			inventory->printWholeList();
			break;
		case 4:
			cout << "Search selected." << endl;

			while (firstPass || tempList->sizeOfList() > 1)
			{
				
				
				cout << "\t***********\n";
				cout << "\n\tSEARCH MENU\n";
				cout << "\n\t***********\n";
				cout << "\tPlease select a search category:\n" << endl;
				cout << "\t1) NAME" << endl;
				cout << "\t2) PRICE" << endl;
				cout << "\t3) DIMENSION" << endl;
				cout << "\t4) REVISION" << endl;
				cout << "\t5) MODEL" << endl;
				cout << "\t6) COLOR" << endl;
				cout << "\t7) SERIAL" << endl;
				cout << "\t8) SKU" << endl;
				cout << "\t9) Quit Search" << endl;

				switch (inputValid()) {
				case 1:
					option = "name";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;
				case 2:
					option = "price";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;
				case 3:
					option = "dimension";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;
				case 4:
					option = "revision";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;
				case 5:
					option = "model";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;

				case 6:
					option = "color";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;

				case 7:
					option = "serial";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;

				case 8:
					option = "SKU";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;

				case 9:
					goto leaveSearch;
					break;
				default:
					cout << "Not a menu option. Please select an menu option." << endl;
					break;

				}

				if (tempList->sizeOfList() == 1)
				{
					cout << "Item found!" << endl;
					tempList->printWholeList();
				}

				if (tempList->sizeOfList() > 1)
				{
					cout << "\n(" << tempList->sizeOfList() << ") result(s) found." << endl;
					cout << "Please refine search." << endl;
				}
				if(tempList->sizeOfList()==0)
					cout << "(!) No items found in inventory matching search criteria.\n" << endl;

				firstPass = false;
			}
			leaveSearch:;
			break;
		case 5:
			cout << "Closing program." << endl;
			isRunning = false;
			return 0;

		default:
			cout << "Not a menu option. Please select an menu option." << endl;
			break;

		}
	}


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Tommy
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




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
	

	//data structure may be better, and more input verification is needed
	//at least at the moment a dynamic array works*/
	return 0;
}







