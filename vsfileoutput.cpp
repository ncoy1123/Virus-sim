#include<iostream>
#include<fstream>

using namespace std;

int main(void) {

	int people;

	double totalCost;
	double familyCost;

	//the files to read or write to/from
	ofstream vdata;

	cout << "What number of people:";
	cin >> people;
	vdata.open("output.txt");
	vdata<<"There are "<< people <<" people.";
	
	vdata.close(); 

	return 0;
}
