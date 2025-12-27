#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(){
	ofstream myfile ("customers.csv");
	myfile<<"ID, Name, CNIC, License No., Phone No."<<endl;
	myfile<<"101, Umar, 9008349, 2285, 3215144460"<<endl;
	myfile<<"102, Abdul, 5678769, 2339, 3445057689"<<endl;
	myfile<<"103, Anas, 7432780, 2330, 3004563871"<<endl;
	myfile.close();
	cout<<"The csv file 'customers.csv' is created and written successfully."<<endl;
	return 0;
}