#include <iostream>
#include<vector>
#include<string>
using namespace std;

class studentName {
	vector<string>fullName = {};
	int spaceCount = 0;
	int lastSpace = 0;
public:
	studentName(string name) {
		for (int i = 0,k=0; i < name.size(); i++) {
			if (name[i] == ' ') {
				spaceCount++;
				//breaking the string into vector's element
				fullName.push_back(name.substr(lastSpace, i- lastSpace));
				lastSpace= i+1 ;
			}
		}

		//Adding last name in string to the vector
		fullName.push_back(name.substr(lastSpace, name.size() - lastSpace));
		if (spaceCount == 0) {
			for (int i = 0; i < 2; i++)
				fullName.push_back(name);
		}

		//copying last name to reach minimum number of spaces
		else if (spaceCount < 2)
		fullName.push_back(name.substr(name.find_first_of(' ')+1, name.size()));

	fullName.shrink_to_fit();
	}

	void print() {
		cout << "Detailed parts of the name are: " << endl;

		for (int i = 0; i < fullName.size(); i++) {
			cout << i + 1 <<") " << fullName[i] << endl;
		}
	}

	bool replace(int i, int j) {
		if (i <0 || i>fullName.size() &&
			j <0 || j>fullName.size())

			return false;
		else {
			//swapping
			string temp;
			temp=fullName[i-1];
			fullName[i-1] = fullName[j-1];
			fullName[j-1] = temp;
			return true;
		}
	}
};

int main()
{

	studentName testCase1("Ibrahim Rashid Fayad");
	testCase1.replace(1, 3);
	testCase1.print();
	cout << endl;

	studentName testCase2("Omar Essawy");
	testCase2.replace(1, 2);
	testCase2.print();
	cout << endl;

	studentName testCase3("Bebo");
	testCase3.replace(1, 3);
	testCase3.print();
	cout << endl;

	studentName testCase4("Mohamed Nasser Ahmed Khaled");
	testCase4.replace(2, 4);
	testCase4.print();
	cout << endl;

	studentName testCase5("Ahmed Ali");
	testCase5.replace(1, 3);
	testCase5.print();
	cout << endl;

	return 0;
}
