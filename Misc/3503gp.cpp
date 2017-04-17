#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctime>
#include <time.h>
#include <Windows.h>
#include <random>
using namespace std;
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
int main() {
	/*while (true) {
		cout << getsku() << endl;
		cout << "more sku?" << endl;
		string response;
		cin >> response;
		if (response == "no") {
			break;
		}
		cin.ignore();
	}*/
	getsku();
	getserial();
	

	/*while (true) {
		cout << getserial() << endl;
		cout << "more serial?" << endl;
		string response;
		cin >> response;
		if (response == "no") {
			break;
		}
		cin.ignore();
	}*/
    return 0;
}

