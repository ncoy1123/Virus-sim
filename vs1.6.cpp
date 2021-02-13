#include<iostream>
#include<fstream>

using namespace std;

int main(void) {

	int peoplenum;
	int locations;
	int ran;
	int infected;
	int days;
	int dailyv = 1;
	int day = 1;
	int bday = 1;
	int diffday= 0;
	
	char man;
	char detail;

	int infectionRate;

	srand(time(NULL));

	infected = 0;
	//the files to read or write to/from
	ofstream vdata;

	vdata.open("output.txt");

	cout << "Would you like to see the manual(y or n):";
	cin >> man;

	if (man == 'y' || man == 'Y') {
		cout << "This is a very basic Virus simulator. It is intended to mainly be imported into excel and be graphed or just look at the percent that it goes up. This program works by people going into differnt buildings. Each person can go in one building a day. The spread effect works by every infected person has a certain percent change to infect ANYONE that was in the same building as them. If one infected person went to a building with 100 people those 100 people would have a certain % chance to get the virus. If its 2 in a hunderd its not 2 times the percent chance its % chance then % chance.---(IDK how suppose to stop someone eariler in the day how got infected to infect someone later in the day)---This is a basic program that just looks at how expenentally quick a virus can spread. It do not take in account any thing with differnt times, so everyone in the building is assumed to be in contact with that infected person. " << endl << endl;
		cout << "People: Number of people that are simulated" << endl;
		cout << "Infection rate: A one in blank change for infection with contact" << endl;
		cout << "Locations: Number of differnt place that each person has a random chance to go to. -not yet made-" << endl;
		cout << "Days: Number of days the simulation lasts" << endl << endl;
		cout << "***Please be patient*** If there is a hunderd people with 3 locations there are a million possible combonations for each day. 10 days would be 10 million combonations." << endl << endl << endl;
	}

	//getting number for array
	cout << "People:";
	cin >> peoplenum;

	//selecting the infection rate
	cout << "Infection rate:";
	cin >> infectionRate;

	//settign locations
	cout << "Locations:";
	cin >> locations;
	
	//settign Days
	cout << "Days:";
	cin >> days;
	
	//selecting the detail
	cout << "High Detail:";
	cin >> detail;

	//array
	int people[peoplenum][3];// 1 user id,2 infection, 3 location
	int infectedarr[peoplenum];

	//Filling array to number of people selected and set virus to 0
	for (int i = 0; i < peoplenum; i++) {
		//people id
		people[i][1] = i;

		//infected set to 0
		people[i][2] = 0;
	}

	people[0][2] = 1;

	//start of day calculations
	while (day <= days) {

		//Give everyone a random location for the day
		for (int i = 0; i < peoplenum; i++) {
			ran = rand() % 40 + 1;
			people[i][3] = i-20+ran;
			
			if(people[i][3]<0){
		people[i][3]=0;
		}
		}


		//set the day`s infected array full of 0s
		for (int i = 0; i < peoplenum; i++) {
			infectedarr[i] = 0;
		}

		infected = 0;
		
		//for each infected person put the building in the array.
		for (int i = 0; i < peoplenum; i++) {
			if (people[i][2] > 0 && people[i][2] < 14) {
				infected++;
				infectedarr[infected] = people[i][3];
				people[i][2]++;
			}
		}

		//checking to see if person matches infected building.
		for (int i = 0; i < peoplenum; i++) {

			int a = 1;
			while (infectedarr[a] > 0) {

				//if they match a infected building
				if (people[i][3] == infectedarr[a]) {

					//10% change for now to get infected
					ran = rand() % infectionRate + 1;
					if (ran == 1 && people[i][2] == 0) {
						people[i][2] = people[i][2] + 1;
						dailyv++;
					}
				}
				a++;
			}
		}
		
		//------------------------------------------output data---------------------------------------------------

		if (detail == 'y' || detail == 'Y') {

		//output data to file

		vdata << endl << endl << "It is day  "<< day << " There are "<< dailyv <<" people infected." <<endl;

		vdata << "p:";
		//outputting each person
		for (int i = 0; i < peoplenum; i++) {
			vdata << people[i][1] << " ";
		}


		vdata << endl << "i:";
		//outputting each person virus data 
		for (int i = 0; i < peoplenum; i++) {
			vdata << people[i][2] << " ";
		}

		vdata << endl << "L:";
		//outputting each person virus data
		for (int i = 0; i < peoplenum; i++) {
			vdata << people[i][3] << " ";
		}
		//vdata<<"There are "<< dailyv <<" people infected." << endl;
		}
		else{
		diffday = dailyv-bday;
		vdata<<day<<","<<dailyv<<","<<diffday<<endl;
		
		bday=dailyv;
		
		
		}
		
		
		
		//vdata << endl << dailyv << endl;
		day++;
	}
	vdata.close();

	cout << "Done! Please check output.txt for result" << endl;

	return 0;
}
