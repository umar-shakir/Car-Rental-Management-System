#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
const int max_cars = 100;
const int max_cust = 100;
struct car{
    string category, availability, discount, make, model;
    int year, id;
    double rent;
};
struct customer{
    int id;
    string name, cnic, license, phone;
};
string admin[2][2]={{"Umar", "6767"}, {"Umair", "1010"}};
void admin_portal(){
	int choice;
	cout<<"\nDo you want to add a New Car or a Return a Car?";
	cout<<"\n1. Add a New Car.\n2. Car Return.\nChoice: ";
	cin>>choice;
	if(choice==1){
        car new_c;
        cout<<"\n    ~~~:Adding New Car:~~~    \n\n";
        cout<<"Enter Category: Sedan/SUV/Hatchback : ";
		cin>>new_c.category;
        new_c.availability="Available";
        cout<<"Enter Discount in %: "; 
		cin>>new_c.discount;
        cout<<"ID: ";
		cin>>new_c.id;
        cout<<"Make: ";
		cin>>new_c.make;
        cout<<"Model: ";
		cin>>new_c.model;
        cout<<"Year: ";
		cin>>new_c.year;
        cout<<"Rent per day: ";
		cin>>new_c.rent;
        ofstream add("cars.csv", ios::app);
        add<<new_c.category<<","<<new_c.availability<<","<<new_c.discount<<","
        <<new_c.id<<","<<new_c.make<<","<< new_c.model<<","<<new_c.year<<","<<new_c.rent<<endl;
        add.close();
        cout<<"\nCar added successfully!\n";
    }
    else{
    	cout<<"\n~~~: Car Return & Damage Assessment Portal :~~~\n";
        // --- LOAD CARS FROM FILE ---
        car carArray[max_cars];
        int carCount=0;
        ifstream file("cars.csv");
        string line, val;
        if(!file.is_open()){
        cout<<"Error: Could not open database."<<endl;
        }
        getline(file, line); // Skip header
        while (getline(file, line)&&carCount<max_cars) {
            stringstream ss(line);
            getline(ss, carArray[carCount].category, ',');
            getline(ss, carArray[carCount].availability, ',');
            // Trim leading space if exists
            if (carArray[carCount].availability[0]==' '){
                carArray[carCount].availability.erase(0, 1);
            }
            getline(ss, carArray[carCount].discount, ',');
            getline(ss, val, ','); 
			carArray[carCount].id=stoi(val);
            getline(ss, carArray[carCount].make, ',');
            getline(ss, carArray[carCount].model, ',');
            getline(ss, val, ','); 
			carArray[carCount].year=stoi(val);
            getline(ss, val, ','); 
			carArray[carCount].rent=stod(val);
            carCount++;
        }
        file.close();
        // --- PROCESS RETURN ---
        int returnID;
        cout<<"\nEnter the ID of the car being returned: ";
        cin>>returnID;
        bool found=false;
        for (int i=0;i<carCount;i++){
            if (carArray[i].id==returnID){
                found=true;
                carArray[i].availability="Available"; // Update status back to available
// --- DAMAGE ASSESSMENT ---
                double safetyDeposit=10000; // Safety deposit is 10000
                int damageChoice;
                string more;
                cout<<"\n~~~: Damage Assessment :~~~\n";
                do {
                    cout<<"\nSelect damage type:\n";
                    cout<<"1. Dent (Deduction: Rs 3000)\n";
                    cout<<"2. Scratch (Deduction: Rs 1400)\n";
                    cout<<"3. Broken Part (Deduction: Rs 7000)\n";
                    cout<<"4. No Damage\n";
                    cout<<"Choice: ";
                    cin>>damageChoice;
                    switch(damageChoice){
                        case 1:{
					        safetyDeposit-=3000; 
						    break;
					    }
                        case 2:{
					        safetyDeposit-=1400; 
						    break;
					    }
                        case 3:{
					        safetyDeposit-=7000; 
						    break;
					    }
                        case 4:{
						    break;
					    } 
                        default:{
					        cout<<"Invalid option."<<endl;
                        }
                    }
                    if(damageChoice==4)
					break;
                    cout<<"Add another damage? (Yes/No): ";
                    cin>> more;
                } while (more=="yes"||more=="Yes");

                if (safetyDeposit<0){
				    safetyDeposit=0; // Deposit cannot be negative
				}
                cout<<"\nRemaining Safety Deposit to Refund: "<<safetyDeposit;
                cout<<"\n\nVehicle "<<carArray[i].make<<" "<<carArray[i].model<<" is now 'Available'.";
                break;
            }
        }
        if (!found){
            cout<<"Error: Car ID not found in database."<<endl;
        } 
        else{
            // --- SAVE UPDATED DATA BACK TO FILE ---
            ofstream update("cars.csv");
            update<< "Category, Availability, Discount, ID, Make, Model, Year, Rent per day"<<endl;
            for (int i=0; i<carCount;i++){
                update<<carArray[i].category<<", "<<carArray[i].availability<<", "
                <<carArray[i].discount<<", "<<carArray[i].id<<", "<<carArray[i].make
                <<", "<<carArray[i].model<<", "<<carArray[i].year<<", "<<carArray[i].rent<<endl;
            }
            update.close();
        }
	}
}
void car_selection(customer selectedcust){
    car carArray[max_cars];
    int carCount=0;
    // Load cars into the array using Pointers (simulating standard array access)
    ifstream file("cars.csv");
    string line, val;
    getline(file, line); // Skip header
    while (getline(file, line)&&carCount<max_cars){
        stringstream ss(line);
        getline(ss, carArray[carCount].category, ',');
        // Trimming potential space from CSV
        getline(ss, carArray[carCount].availability, ',');
        if (carArray[carCount].availability[0]==' ')
            carArray[carCount].availability.erase(0, 1);
            getline(ss, carArray[carCount].discount, ',');
            getline(ss, val, ','); 
			carArray[carCount].id=stoi(val);
            getline(ss, carArray[carCount].make, ',');
            getline(ss, carArray[carCount].model, ',');
            getline(ss, val, ','); 
			carArray[carCount].year=stoi(val);
            getline(ss, val, ','); 
			carArray[carCount].rent=stod(val);
            carCount++;
        }
    file.close();
    cout<<"\n~~~: Vehicle Booking :~~~\n";
    string userCat;
    cout<<"\nEnter the Category of the vehicle : Sedan/SUV/Hatchback : ";
	cin>>userCat;
    cout<<"\nAvailable "<<userCat<<"s:\n";
    bool carsFound=false;
    for (int i=0;i<carCount;i++){
        // Check availability and category match
        if (carArray[i].category==userCat&&carArray[i].availability=="Available"){
            cout<<"\nID: "<<carArray[i].id<<" | "<<carArray[i].make<<" "
            <<carArray[i].model<<" | Rent per day: "<<carArray[i].rent<<endl;
            carsFound=true;
        }
    }
    if (!carsFound){
        cout<<"No cars available in this category.\n";
        return;
    }
    int selectedID, days;
    cout<<"\nEnter Vehicle ID to Rent: "; 
	cin>>selectedID;
    cout<<"Enter days: ";
	cin>>days;
    for (int i=0;i<carCount;i++){
        if (carArray[i].id==selectedID){
            // Apply Discount
            double discVal=0;
            if (carArray[i].discount.find("%")!=string::npos){
                discVal=stod(carArray[i].discount);
            }
        double total=(carArray[i].rent*days);
        total = total-(total*(discVal / 100.0))+10000;
        cout<<"\n-:   Booking Confirmed   :-\n";
        cout<<"Customer Name : "<<selectedcust.name<<endl;
        cout<<"Total Bill : Rs"<<total<<" (Includes Rs 10000 safety deposit)\n";
        carArray[i].availability="Unavailable";
        break;
        }
    } 
    // Write array back to file to update availability
    ofstream update("cars.csv");
    update<<"Category, Availability, Discount, ID, Make, Model, Year, Rent per day"<<endl;
    for (int i=0;i<carCount;i++){
        update<<carArray[i].category<<","<<carArray[i].availability<<","
        <<carArray[i].discount<<","<<carArray[i].id<<","<<carArray[i].make
        <<","<<carArray[i].model<<","<<carArray[i].year<<","<<carArray[i].rent<<endl;
    }
    update.close();
}
void cust_portal(){	
    int choice;
    customer current;
    cout<<"\nAre you a Customer already?"<<endl;
    cout<<"1. Yes\n2. No\nChoice: ";
    cin>>choice;
    if (choice==1){
        int searchID;
        bool found=false;
        cout<<"\nEnter your ID: ";
		cin>>searchID;
        ifstream file("customers.csv");
        string line, dummy;
        getline(file, dummy); // skip header
        while (getline(file, line)){
            stringstream ss(line);
            string tempID;
            getline(ss, tempID, ',');
            if (stoi(tempID)==searchID){
                current.id=searchID;
                getline(ss, current.name, ',');
                found=true;
            }
        }
        file.close();
        int choice2;
        cout<<"\nDo you want to Book a Vehicle or Return a Vehicle?";
        cout<<"\n1. Book a Vehicle.\n2. Return the Vehicle.\nChoice:";
        cin>>choice2;
        if(choice2==1){
        	car_selection(current);
		}
		else{
			cout<<"Contact the Admin.";
		}
        if(!found){
            cout<<"Customer not found!\n";
            return;
        }
    } 
	else{
        // New Customer logic
        int lastID=0;
        ifstream file("customers.csv");
        string line;
        while (getline(file, line)){
            stringstream ss(line);
            string tempID;
            getline(ss, tempID, ',');
            if(tempID!="ID"){
			    lastID=stoi(tempID);
			}
        }
        file.close();
        current.id=lastID + 1;
        cout<<"Your assigned ID is: "<<current.id<<endl;
        cout<<"Name: "; 
		cin.ignore(); 
		getline(cin, current.name);
        cout<<"CNIC: "; 
		cin>>current.cnic;
        cout<<"License: "; 
		cin>>current.license;
        cout<<"Phone: "; 
		cin>>current.phone;
        ofstream add("customers.csv", ios::app);
        add<<current.id<<","<<current.name<<","<<current.cnic<<","
        <<current.license<<","<<current.phone<<endl;
        add.close();
        car_selection(current);
    }
}
int main(){
    int choice;
    cout<<"~~~: Car Rental Management System :~~~\n";
    cout<<"\nAre you an Admin or a Customer?";
    cout<<"\n1. Admin\n2. Customer\nChoice: ";
    cin>>choice;
    if (choice==1){
        string user, pass;
        cout<<"\nUsername: ";
		cin>>user;
        cout<<"ID: "; 
		cin>>pass;
        bool loginSuccess = false;
        for (int i=0;i<2;i++){
            if (admin[i][0]==user&&admin[i][1]==pass) {
                loginSuccess=true;
            }
        }
        if (loginSuccess){ 
		    admin_portal();
		}
        else{
		    cout<<"Invalid Login!"<<endl;
		}
    } 
	else if (choice==2){
        cust_portal();
    }
    cout<<"\n\nThank you for using this management system!";
    return 0;
}