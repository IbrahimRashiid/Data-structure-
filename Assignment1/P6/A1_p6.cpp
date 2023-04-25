#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <ctime>
#include <algorithm>

using namespace std;

class PhoneDirectory {
	string firstName, lastName, phoneNumber;
public:
	PhoneDirectory(string firstName, string lastName, string phoneNumber) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->phoneNumber = phoneNumber;
	}
	void setFirstName(string firstName) { this->firstName = firstName; }
	void setLastName(string lastName) { this->lastName = lastName; }
	void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getphoneNumber() { return phoneNumber; }
	friend ostream& operator <<(ostream& os, PhoneDirectory& obj);
	PhoneDirectory& operator= (const PhoneDirectory& obj);
};
PhoneDirectory& PhoneDirectory::operator= (const PhoneDirectory& obj)
{
	firstName = obj.firstName;
	lastName = obj.lastName;
	phoneNumber = obj.phoneNumber;
	return *this;
}
bool compareEntry(PhoneDirectory directory1, PhoneDirectory directory2) {
	string temp1 = directory1.getFirstName();
	string temp2 = directory2.getFirstName();
	transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
	transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
	if (temp1.size() <= temp2.size()) {
		for (int i = 0; i < temp1.size(); i++) {
			if (temp1[i] != temp2[i])
				return temp1[i] < temp2[i];
		}
	}
	else
	{
		for (int i = 0; i < temp2.size(); i++) {
			if (temp1[i] != temp2[i])
				return temp1[i] < temp2[i];
		}
	}
}

void listByFirstName_InsertionSort(vector<PhoneDirectory>& directory) {
	for (int i = 1, j; i < directory.size(); i++) {
		PhoneDirectory temp = directory[i];
		for (j = i; j > 0 && compareEntry(temp, directory[j - 1]); j--) {
			directory[j] = directory[j - 1];
		}
		directory[j] = temp;
	}
}
void listByFirstName_SelectionSort(vector<PhoneDirectory>& directory) {
	for (int i = 0, j, least; i < directory.size() - 1; i++) {

		for (j = i + 1, least = i; j < directory.size(); j++)

			if (compareEntry(directory[j], directory[least]))
				least = j;
		swap(directory[least], directory[i]);
	}

}
void listByFirstName_Bubblesort(vector<PhoneDirectory>& directory) {
	for (int i = 0; i < directory.size() - 1; i++) {

		for (int j = directory.size() - 1; j > i; --j)

			if (compareEntry(directory[j], directory[j - 1]))
				swap(directory[j], directory[j - 1]);
	}

}

void deleteEntryByFirstName(vector<PhoneDirectory>& directory) {
	int index = -1, mid;
	int high = directory.size(), low = 0;
	string firstName;
	cout << "Please enter the name of entry you want to delete: ";
	cin >> firstName;

	//listByFirstName_Bubblesort(directory);
	//listByFirstName_SelectionSort(directory);
	listByFirstName_InsertionSort(directory);

	while (high >= low)
	{
		mid = (high + low) / 2;// calculating  midpoint of the array
		if (firstName < directory[mid].getFirstName()) //the entry in the left part of the vector
		{
			high = mid - 1;
		}
		else if (firstName > directory[mid].getFirstName()) //the entry in the right part of the vector
		{
			low = mid + 1;
		}
		else
		{
			index = mid; //the entry is in the middle of the vector
			break;
		}
	}
	if (index == -1)
		cout << "Not Found!" << endl;
	else
		directory.erase(directory.begin() + index); //delete the entry from the vector
}

void lookUpByFirstName(vector<PhoneDirectory>& directory) { //searching for an entry by first name
	bool isFound = false;
	string firstName;
	cout << "Please enter the first name: ";
	cin >> firstName;
	for (int i = 0; i < directory.size(); i++) {
		if (directory[i].getFirstName() == firstName) {
			cout << directory[i] << endl;
			isFound = true;
		}
	}
	if (isFound == false)
		cout << "Not Found!" << endl;
}
void lookUpByPhoneNumber(vector<PhoneDirectory>& directory) {   //seachring for an entry by phone number
	bool isFound = false;
	string phone;
	cout << "Please enter the phone number: ";
	cin >> phone;
	for (int i = 0; i < directory.size(); i++) {
		if (directory[i].getphoneNumber() == phone) {
			cout << directory[i] << endl;
			isFound = true;
		}
	}
	if (isFound == false)
		cout << "Not Found!" << endl;
}

void listAllEntries(vector<PhoneDirectory>& directory) { //printing the data of all entries in the directory
    directory.shrink_to_fit();
    if(directory.size()==0)
        cout<<endl<<"There are no entries in the directory yet!"<<endl<<endl;
    else{
	listByFirstName_Bubblesort(directory);
	for (int i = 0; i < directory.size(); i++) {
		cout << directory[i];
	}
    }

}
void displayMenu() {
	cout << "Please choose a number: " << endl << endl <<
		"1. Add an entry to the directory" << endl <<
		"2. Look up a phone number" << endl <<
		"3. Look up by first name" << endl <<
		"4. Delete an entry from the directory" << endl <<
		"5. List All entries in phone directory" << endl <<
		"6. Exit form this program" << endl << endl;
}

void addEntry(vector<PhoneDirectory>& directory) {
	string PhoneNumber, firstName, lastName;
	cout << "Please enter the first name: ";
	cin >> firstName;
	cout << "Please enter the last name: ";
	cin >> lastName;
	cout << "Please enter the phone number: ";
	cin >> PhoneNumber;
	PhoneDirectory addEntry(firstName, lastName, PhoneNumber);
	directory.push_back(addEntry); //adding new entry to the directory
}

ostream& operator <<(ostream& os, PhoneDirectory& obj) {
	os << endl << "first Name: " << obj.firstName <<
		endl << "Last Name: " << obj.lastName <<
		endl << "Phone Number: " << obj.phoneNumber << endl << endl;
	return os;
}

void timeAnalysis(vector<PhoneDirectory>directory) {

	//the directroy should be passed by value to every sorting algorithem

	auto start1 = std::chrono::steady_clock::now();
	listByFirstName_Bubblesort(directory);
	auto end1 = std::chrono::steady_clock::now();
	//calculating the difference between teh star and end time
	double duration1 = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count());
	//converting the result from nanoSec to Sec
	cout << "time for listByFirstName_Bubblesort = " << duration1 / 1e9 << " sec" << endl;

	auto start2 = std::chrono::system_clock::now();
	listByFirstName_InsertionSort(directory);
	auto end2 = std::chrono::system_clock::now();
	double duration = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count());
	cout << "time for listByFirstName_InsertionSort = " << duration / 1e9 << " sec" << endl;

	auto start3 = std::chrono::system_clock::now();
	listByFirstName_SelectionSort(directory);
	auto end3 = std::chrono::system_clock::now();
	double duration3 = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3).count());
	cout << "time for listByFirstName_SelectionSort = " << duration / 1e9 << " sec" << endl;
}

int main()
{
	int choise = 0;
	vector<PhoneDirectory> directory;

	displayMenu();
	cin >> choise;
	while (choise != 6) {
		switch (choise) {
		case 1:
			addEntry(directory);
			displayMenu();
			cin >> choise;
			break;
		case 2:
			lookUpByPhoneNumber(directory);
			displayMenu();
			cin >> choise;
			break;
		case 3:
			lookUpByFirstName(directory);
			displayMenu();
			cin >> choise;
			break;
		case 4:
			deleteEntryByFirstName(directory);
			displayMenu();
			cin >> choise;
			break;
		case 5:
			listAllEntries(directory);
			displayMenu();
			cin >> choise;
			break;
		default:
			cout << "invalid input" << endl;
			displayMenu();
			cin >> choise;
			break;
		}
	}
}
