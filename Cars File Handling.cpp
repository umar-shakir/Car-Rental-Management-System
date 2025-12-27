#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(){
	ofstream myfile ("cars.csv");
	myfile<<"Category, Availability, Discount, ID, Make, Model, Year, Rent per day"<<endl;
	myfile<<"Sedan, Available, 15%, 001, Toyota, Corolla, 2024, 7500"<<endl;
	myfile<<"SUV, Available, 20%, 002, Toyota, Land Cruiser, 2012, 15000"<<endl;
	myfile<<"Hatchback, Available, 10%, 003, Toyota, Vitz, 2020, 4500"<<endl;
	myfile.close();
	cout<<"The csv file 'cars.csv' is created and written successfully."<<endl;
	return 0;
}