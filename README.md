# Car-Rental-Management-System
A console-based C++ application for managing car rentals, vehicle inventory, and customer records using file handling.
## 📊 System Overview
The system is divided into two primary modules:
1. **Admin Portal**: Allows staff to add new vehicles to the fleet and process returns with a built-in damage assessment tool.
2. **Customer Portal**: Enables users to register, log in, and book vehicles based on category (Sedan, SUV, Hatchback).



## 🚀 Features
* **Data Persistence**: Uses `cars.csv` and `customers.csv` to ensure data is saved even after the program closes.
* **Damage Assessment**: Automatically calculates refunds from a safety deposit based on vehicle condition (Dents, Scratches, or Broken Parts).
* **Discount Logic**: Support for percentage-based discounts on specific vehicle models.
* **Authentication**: Secure Admin login (Default: `Umar/6767` or `Umair/1010`).

## 📁 Project Structure
* `main.cpp`: The core logic of the management system.
* `Cars File Handling.cpp`: Script to initialize the vehicle database.
* `Customers File Handling.cpp`: Script to initialize the customer database.
* `cars.csv`: Database file containing vehicle ID, model, rent, and availability.
* `customers.csv`: Database file containing customer names, CNICs, and licenses.

## 🛠️ How to Setup and Run
Follow these steps to get the project running on your local machine:

1. **Initialize the Databases**:
   Compile and run the setup scripts first to generate the required CSV files:
   ```bash
   g++ "Cars File Handling.cpp" -o setup_cars
   ./setup_cars
   g++ "Customers File Handling.cpp" -o setup_cust
   ./setup_cust
   Here is the complete, ready-to-copy code for your **README.md** file. Simply create a new file named `README.md` in your GitHub repository and paste the following content:

---

```markdown
# Car Rental Management System (C++)

A comprehensive console-based management system designed to handle vehicle inventory, customer registration, and rental transactions using C++ and file-based data storage (CSV).

## 📊 System Overview
The system is divided into two primary modules:
1. **Admin Portal**: Allows staff to add new vehicles to the fleet and process returns with a built-in damage assessment tool.
2. **Customer Portal**: Enables users to register, log in, and book vehicles based on category (Sedan, SUV, Hatchback).



## 🚀 Features
* **Data Persistence**: Uses `cars.csv` and `customers.csv` to ensure data is saved even after the program closes.
* **Damage Assessment**: Automatically calculates refunds from a safety deposit based on vehicle condition (Dents, Scratches, or Broken Parts).
* **Discount Logic**: Support for percentage-based discounts on specific vehicle models.
* **Authentication**: Secure Admin login (Default: `Umar/6767` or `Umair/1010`).

## 📁 Project Structure
* `main.cpp`: The core logic of the management system.
* `Cars File Handling.cpp`: Script to initialize the vehicle database.
* `Customers File Handling.cpp`: Script to initialize the customer database.
* `cars.csv`: Database file containing vehicle ID, model, rent, and availability.
* `customers.csv`: Database file containing customer names, CNICs, and licenses.

## 🛠️ How to Setup and Run
Follow these steps to get the project running on your local machine:

1. **Initialize the Databases**:
   Compile and run the setup scripts first to generate the required CSV files:
   ```bash
   g++ "Cars File Handling.cpp" -o setup_cars
   ./setup_cars
   g++ "Customers File Handling.cpp" -o setup_cust
   ./setup_cust

```

2. **Run the Main Application**:
Compile and launch the primary management system:
```bash
g++ main.cpp -o CarRentalSystem
./CarRentalSystem

```



## 📝 Usage Note

When assessing damages during a car return, the system will ask "Add another damage? (Yes/No)". Ensure you type the full word **"Yes"** or **"No"** to proceed correctly.

```

---

### Final Steps to Upload:
1.  **Rename your files** on your computer so they match the names in the README (e.g., rename `Untitled1.cpp` to `main.cpp`).
2.  **Upload all 5 files** (`main.cpp`, both setup `.cpp` files, and both `.csv` files) to your repository.
3.  **Create the README**: On GitHub, click **Add file** > **Create new file**, name it `README.md`, paste the code above, and click **Commit changes**.

**Would you like me to help you add a "License" file to your project so it looks even more official?**

```
