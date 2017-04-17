#include "SemesterProject.h"



static vector<string> skugenerated;
int numofsku = 0;
static const char numpool[] = "0123456789";
static int numpoolsize = sizeof(numpool) - 1;


char getRandomnum() {  //creates a random number and returns as char
	return numpool[rand() % numpoolsize];
}
string generatesku() {  //method which generates a random SKU
	int skulength = 6;
	srand(time(0));
	string sku;
	for (int i = 0; i < skulength; i++) {
		sku += getRandomnum();
	}
	return sku;
}
string getsku() {  //method which generates and returns a program usable random SKU
	bool loopbreak = true;
	while (loopbreak) {  //loops while loopbreak is true and performs error checking
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

char getRandomnumletter() {  //returns a random letter as char
	return numletterpool[rand() % numletterpoolsize];
}

string generateserial() {  //function which generates a serial for an item
	int seriallength = 16;
	srand(time(0));
	string serial;
	for (int i = 0; i < seriallength; i++) {  //loops until i is the length of the serial
		serial += getRandomnumletter();
	}
	return serial;
}
string getserial() {  //method which generates and returns a program usable serial
	bool loopbreak = true;
	while (loopbreak) {  //loops while loopbreak is true and performs error checking
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


string checkForMoneySign() {  //checks if price change request is only digits

    bool shouldWeLoopNow = true;
    string tempData;
    locale loc;


    while (shouldWeLoopNow) {  //loops while loop is true
        cin >> tempData;
        for (int l = 0; l < tempData.size(); ++l) {  //checks to ensure that all chars in string are digits

            if (!(isdigit(tempData[l], loc))) {
                cout << "Given input does not solely contain digits.  Please enter price again: " << endl;
                shouldWeLoopNow = true;
                break;
            }

            else {
                shouldWeLoopNow = false;
            }
        }
    }

    tempData = "$" + tempData;

    return tempData;
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
	
	
	while (isRunning) {  //while the looping bool "isRunning" is true, run the program
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
		string serial;
		string fileName;
        bool shouldWeLoopNow = true;
        locale loc;

		bool firstPass=true;
		bool continueMenu;

		
		switch (inputValid())  //use input validation, then for each of the following cases, perform the stated actions
		{
			tempList->ClearList();
		case 1:  //add item to inventory
			cout << "Adding Item" << endl;
			cout << "Please enter the name of the item:" << endl;
            cin.ignore();
            getline(cin,newData);
			tempItem->name = newData;

			cout << "Please enter the model of the item:" << endl;
            getline(cin,newData);
			tempItem->model = newData;

			cout << "Please enter the revision of the item:" << endl;
            getline(cin,newData);
			tempItem->revision = newData;

			cout << "Please enter the color of the item:" << endl;
            getline(cin,newData);
			tempItem->color = newData;

		

			tempItem->SKU = inventory->skuMatch(getsku(), tempItem->name, tempItem->model, tempItem->color, tempItem->revision);
			
			if (inventory->priceMatch(tempItem->SKU).compare("empty") == 0) {
				cout << "Please enter the price of the item (in USD):" << endl;
                newData = checkForMoneySign();
				tempItem->price = newData;
			}
			else
				tempItem ->price = inventory->priceMatch(tempItem->SKU);

			tempItem->serial = getserial();

			inventory->addNode(tempItem);
			break;

		case 2:  //print size of inventory (total number of items in linked list)
			cout << "Returnin size of inventory" << endl;
			
			cout << "Size of inventory is: " << inventory->sizeOfList() << endl;
			break;

		case 3:  //prints everything in warehouse/inventory
			cout << "Printing Invetory." << endl;

			inventory->printWholeList();
			break;
		case 4:  //searches for specific item(s)
			cout << "Search selected." << endl;

			while (firstPass || tempList->sizeOfList() > 1)  //while its the firstPass and we have a list bigger than 1
			{
				
				searchMenu:;
				cout << "\t***********\n";
				cout << "\n\tSEARCH MENU\n";
				cout << "\n\t***********\n";
				cout << "\tPlease select a search category:\n" << endl;
				cout << "\t1) NAME" << endl;
				cout << "\t2) PRICE" << endl;
				cout << "\t3) REVISION" << endl;
				cout << "\t4) MODEL" << endl;
				cout << "\t5) COLOR" << endl;
				cout << "\t6) SERIAL" << endl;
				cout << "\t7) SKU" << endl;
				cout << "\t8) Quit Search" << endl;

				switch (inputValid()) {
				case 1:  //searches for item based on name
					option = "name";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;
				case 2:  //searches for item based on price
					option = "price";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;

                    tempdata2 = checkForMoneySign();

					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;
				
				case 3:  //searches for item based on revision
					option = "revision";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;
				case 4:  //searches for item based on model
					option = "model";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;

				case 5:  //searches for item based on color
					option = "color";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;

				case 6:  //searches for item based on serial
					option = "serial";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;

				case 7:  //searches for item based on SKU
					option = "SKU";
					cout << "Please enter the " << option << " of the item you are searching for:" << endl;
					cin >> tempdata2;
					if (firstPass) {
						tempList = inventory->genSearch(option, tempdata2);
					}
					else
						tempList = tempList->genSearch(option, tempdata2);

					break;

				case 8:  //exits
					goto leaveSearch;
					break;
				default:
					cout << "Not a menu option. Please select an menu option." << endl;
					goto searchMenu;
					break;

				}

				if (tempList->sizeOfList() == 1)  //if size of list is 1
				{
					continueMenu = true;
					serial = tempList->GetHead()->serial;

					cout << "Item found!" << endl;
					cout << "The serial code of the item is: " << serial << endl;
					while (continueMenu) {  //while looping variable "continueMenu" is true
	
						cout << "\t***********\n";
						cout << "\n\tITEM MENU\n";
						cout << "\n\t***********\n";
						cout << "What would you like to do?" << endl;
						cout << "\t1) PRINT ITEM INFORMATION" << endl;
						cout << "\t2) CHANGE ITEM PRICE" << endl;
						cout << "\t3) DELETE ITEM" << endl;
						cout << "\t4) RETURN TO MAIN MENU" << endl;

						switch (inputValid()) {
						case 1:  //prints item information
							tempList->printWholeList();
							break;
						case 2:  //modifies item pricing data
							cout << "What is the new price of the item?" << endl;
                            newData = checkForMoneySign();
							tempList->GetHead()->price = newData;
							break;
						case 3:  //deletes item
							cout << "Are you sure you want to delete the item? Enter 'y' to delete." << endl;
							cin >> option;
							if (option == "y") {
                                inventory->deleteNode(serial);
                                tempList->deleteNode(serial);
                                goto leaveSearch;
                            }
							break;
						case 4:  //returns to main menu
							continueMenu = false;
							break;

						default:  //otherwise, say that chose number is not valid
							cout << "Not a menu option.Please select an menu option." << endl;
							break;
						}
					}
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
		case 5:  //exits program
			cout << "Closing program." << endl;
			isRunning = false;
            break;

		default:  //otherwise, says input is not valid
			cout << "Not a menu option. Please select an menu option." << endl;
			break;
		}
	}

	return 0;
}