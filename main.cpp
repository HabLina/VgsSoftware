#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <cstdio>
#include "Models/Car.h"
#include "Models/Customer.h"

int numberOfCars = 0;

int numberOfCustomers = 0;

//Car functions
void addCar() {
    //Increment the number of cars
    numberOfCars++;

    // Open a database file
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    std::string model, brand, color, fuelType, transmission, licensePlate, carRegistration;

    //Get input information from the user
    std::cout << "Enter car brand: ";
    std::getline(std::cin, brand);
    std::transform(brand.begin(), brand.end(), brand.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::cout << "Enter car model: ";
    std::getline(std::cin, model);
    std::transform(model.begin(), model.end(), model.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::cout << "Enter car color: ";
    std::getline(std::cin, color);
    std::transform(color.begin(), color.end(), color.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::cout << "Enter car fuel type: ";
    std::getline(std::cin, fuelType);
    std::transform(fuelType.begin(), fuelType.end(), fuelType.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::cout << "Enter car transmission: ";
    std::getline(std::cin, transmission);
    std::transform(transmission.begin(), transmission.end(), transmission.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::cout << "Enter license plate number: ";
    std::getline(std::cin, licensePlate);
    std::transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::cout << "Enter car registration number: ";
    std::getline(std::cin, carRegistration);
    std::transform(carRegistration.begin(), carRegistration.end(), carRegistration.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    try{
        // Prepare an SQL statement
        SQLite::Statement query(db, "INSERT INTO CARS (Model, Brand, Color, FuelType, Transmission, Availability, LicensePlate, CarRegistration) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

        // Bind values to the statement
        query.bind(1, model);
        query.bind(2, brand);
        query.bind(3, color);
        query.bind(4, fuelType);
        query.bind(5, transmission);
        query.bind(6, true);
        query.bind(7, licensePlate);
        query.bind(8, carRegistration);

        // Execute the statement
        query.exec();
        std::cout << "Car inserted successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Failed to insert car: " << e.what() << std::endl;
    }
}

void editCar(int id){
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    bool continueEditing = true;
    while (continueEditing) {
        std::string model, brand, color, licensePlate,
        fuelType, transmission, carRegistration, repeat, thingToEdit;

        std::cout << "What do you want to edit? (brand, model, color, license plate, car registration, fuel type, transmission): ";
        std::getline(std::cin, thingToEdit);

        //turn thingsToEdit to lowercase to remove case sensitivity
        std::transform(thingToEdit.begin(), thingToEdit.end(), thingToEdit.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        if (thingToEdit == "brand") {
            std::cout << "Enter new car brand: ";
            std::getline(std::cin, brand);

            std::transform(brand.begin(), brand.end(), brand.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE cars SET Brand = ? WHERE ID = ?");
            query.bind(1, brand);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Brand edited successfully.\n";
        } else if (thingToEdit == "model") {
            std::cout << "Enter new car model: ";
            std::getline(std::cin, model);

            std::transform(model.begin(), model.end(), model.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE cars SET Model = ? WHERE ID = ?");
            query.bind(1, model);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Model edited successfully.\n";
        } else if (thingToEdit == "color") {
            std::cout << "Enter new car color: ";
            std::getline(std::cin, color);

            std::transform(color.begin(), color.end(), color.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE cars SET Color = ? WHERE ID = ?");
            query.bind(1, color);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Color edited successfully.\n";
        } else if (thingToEdit == "license plate") {
            std::cout << "Enter new car license plate number: ";
            std::getline(std::cin, licensePlate);

            std::transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE cars SET LicensePlate = ? WHERE ID = ?");
            query.bind(1, licensePlate);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "License plate edited successfully.\n";
        } else if (thingToEdit == "car registration") {
            std::cout << "Enter new car registration number: ";
            std::getline(std::cin, carRegistration);

            std::transform(carRegistration.begin(), carRegistration.end(), carRegistration.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE cars SET CarRegistration = ? WHERE ID = ?");
            query.bind(1, carRegistration);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Car registration number edited successfully.\n";
        } else if (thingToEdit == "fuel type") {
            std::cout << "Enter new car fuel type: ";
            std::getline(std::cin, fuelType);

            std::transform(fuelType.begin(), fuelType.end(), fuelType.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE cars SET FuelType = ? WHERE ID = ?");
            query.bind(1, fuelType);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Fuel type edited successfully.\n";
        } else if (thingToEdit == "transmission") {
            std::cout << "Enter new car transmission: ";
            std::getline(std::cin, transmission);

            std::transform(transmission.begin(), transmission.end(), transmission.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE cars SET Transmission = ? WHERE ID = ?");
            query.bind(1, transmission);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Car transmission edited successfully.\n";
        } else {
            std::cout << "Invalid input; please enter one of the previously listed options: ";
        }

        std::cout << "Do you want to edit something else? (yes/no): ";
        std::getline(std::cin, repeat);

        std::transform(repeat.begin(), repeat.end(), repeat.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        continueEditing = (repeat == "yes");
    }
}

void removeCar(int id){
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE);

    SQLite::Statement query(db, "DELETE FROM cars WHERE ID = ?");
    query.bind(1, id);
    query.exec();
}

//Customer functions
void addCustomer() {
    numberOfCustomers++;

    // Open a database file
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    std::string firstName, lastName, address, email;
    int phoneNumber;
    long long ssn, licenseNumber;

    //Get input information from the user
    std::cout << "Enter customer first name: ";
    std::getline(std::cin, firstName);
    std::transform(firstName.begin(), firstName.end(), firstName.begin(),
                   [](unsigned char c) { return std::tolower(c); });


    std::cout << "Enter customer last name: ";
    std::getline(std::cin, lastName);
    std::transform(lastName.begin(), lastName.end(), lastName.begin(),
                   [](unsigned char c) { return std::tolower(c); });


    std::cout << "Enter customer address: ";
    std::getline(std::cin, address);
    std::transform(address.begin(), address.end(), address.begin(),
                   [](unsigned char c) { return std::tolower(c); });


    std::cout << "Enter customer email: ";
    std::getline(std::cin, email);
    std::transform(email.begin(), email.end(), email.begin(),
                   [](unsigned char c) { return std::tolower(c); });


    std::cout << "Enter customer social security number: ";
    while (!(std::cin >> ssn)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please enter a valid number for social security number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline character

    std::cout << "Enter customer phone number: ";
    while (!(std::cin >> phoneNumber)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please enter a valid phone number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline character

    std::cout << "Enter customer license number: ";
    while (!(std::cin >> licenseNumber)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please enter a valid license number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline character

    try{
        // Prepare an SQL statement
        SQLite::Statement query(db, "INSERT INTO CUSTOMERS (firstName, lastName, address, ssn, phoneNumber, email, licenseNumber, is_example) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

        // Bind values to the statement
        query.bind(1, firstName);
        query.bind(2, lastName);
        query.bind(3, address);
        query.bind(4, ssn);
        query.bind(5, phoneNumber);
        query.bind(6, email);
        query.bind(7, licenseNumber);
        query.bind(8, 0);

        // Execute the statement
        query.exec();
        std::cout << "Customer inserted successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Failed to insert customer: " << e.what() << std::endl;
    }
}

void editCustomer(int id){
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    bool continueEditing = true;
    while (continueEditing) {
        std::string firstName, lastName, address, email, repeat, thingToEdit;
        int ssn, phoneNumber, licenseNumber;

        std::cout << "What do you want to edit? (first name, last name, address, email, social security number, phone number, license number): ";
        std::getline(std::cin, thingToEdit);

        //turn thingsToEdit to lowercase to remove case sensitivity
        std::transform(thingToEdit.begin(), thingToEdit.end(), thingToEdit.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        if (thingToEdit == "first name") {
            std::cout << "Enter new customer first name: ";
            std::getline(std::cin, firstName);

            std::transform(firstName.begin(), firstName.end(), firstName.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE customers SET FirstName = ? WHERE ID = ?");
            query.bind(1, firstName);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "First name edited successfully.\n";
        } else if (thingToEdit == "last name") {
            std::cout << "Enter new customer last name: ";
            std::getline(std::cin, lastName);

            std::transform(lastName.begin(), lastName.end(), lastName.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE customers SET LastName = ? WHERE ID = ?");
            query.bind(1, lastName);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Last name edited successfully.\n";
        } else if (thingToEdit == "address") {
            std::cout << "Enter new customer address: ";
            std::getline(std::cin, address);

            std::transform(address.begin(), address.end(), address.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE customers SET Address = ? WHERE ID = ?");
            query.bind(1, address);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Address edited successfully.\n";
        } else if (thingToEdit == "email") {
            std::cout << "Enter new customer email: ";
            std::getline(std::cin, email);

            std::transform(email.begin(), email.end(), email.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            SQLite::Statement query(db, "UPDATE customers SET Email = ? WHERE ID = ?");
            query.bind(1, email);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Email edited successfully.\n";
        } else if (thingToEdit == "social security number") {
            std::string input;

            std::cout << "Enter customer social security number: ";
            std::getline(std::cin, input);

            ssn = std::stoi(input);

            SQLite::Statement query(db, "UPDATE customers SET Ssn = ? WHERE ID = ?");
            query.bind(1, ssn);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Social security number edited successfully.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline character
        } else if (thingToEdit == "phone number") {
            std::string input;

            std::cout << "Enter customer phone number: ";
            std::getline(std::cin, input);

            phoneNumber = std::stoi(input);

            SQLite::Statement query(db, "UPDATE customers SET PhoneNumber = ? WHERE ID = ?");
            query.bind(1, phoneNumber);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "Phone number edited successfully.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline character
        } else if (thingToEdit == "license number") {
            std::string input;

            std::cout << "Enter customer license number: ";

            std::getline(std::cin, input);

            licenseNumber = std::stoi(input);

            SQLite::Statement query(db, "UPDATE customers SET LicenseNumber = ? WHERE ID = ?");
            query.bind(1, licenseNumber);
            query.bind(2, id);

            // Execute the statement
            query.exec();
            std::cout << "License number edited successfully.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline character
        } else {
            std::cout << "Invalid input; please enter one of the previously listed options: ";
        }

        std::cout << "Do you want to edit something else? (yes/no): ";
        std::getline(std::cin, repeat);

        std::transform(repeat.begin(), repeat.end(), repeat.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        continueEditing = (repeat == "yes");
    }
}

void removeCustomer(int id){
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE);

    SQLite::Statement query(db, "DELETE FROM customers WHERE ID = ?");
    query.bind(1, id);
    query.exec();
}

void assignCar(int customerId, int carId){
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE);

    try {
        SQLite::Statement query(db, "UPDATE cars SET CustomerID = ? WHERE ID = ?");
        query.bind(1, customerId);
        query.bind(2, carId);
        query.exec();
        std::cout << "Car assigned to customer successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error assigning car to customer: " << e.what() << std::endl;
    }
}

//Statistics
void showStatistics(){

}


int main() {
    // Open a database file
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    std::cout << "Please choose:\n"
                 "\n"
                 "1. Add car\n"
                 "2. Edit car\n"
                 "3. Remove car\n"
                 "\n"
                 "4. Add customer\n"
                 "5. Edit customer\n"
                 "6. Remove customer\n"
                 "\n"
                 "7. Assign car to customer\n"
                 "8. Show all info\n"
                 "9. Show statistics\n"
                 "10. Exit" << std::endl;

    while(true) {
        int number;
        std::cin >> number;

        //Clear the newline character from the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(number == 1){
            addCar();
        }else if(number == 2){
            int chosenId;
            std::cout << "Choose a car by typing their id: \n";
            std::cin >> chosenId;

            //Clear the newline character from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            editCar(chosenId);
        }else if(number == 3){
            int chosenId;
            std::cout << "Choose a car by typing their id: \n";
            std::cin >> chosenId;
            removeCar(chosenId);
        }else if(number == 4){
            addCustomer();
        }else if(number == 5){
            int chosenId;
            std::cout << "Choose a customer by typing their id: \n";
            std::cin >> chosenId;
            //Clear the newline character from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            editCustomer(chosenId);

        }else if(number == 6){
            int chosenId;
            std::cout << "Choose a customer by typing their id: \n";
            std::cin >> chosenId;
            removeCustomer(chosenId);
        }else if(number == 7){
            int customerId;
            int carId;

            std::cout << "Choose a customer by typing their id: \n";
            std::cin >> customerId;

            std::cout << "Choose a car by typing its id: \n";
            std::cin >> carId;
            assignCar(customerId, carId);
        }else if(number == 8){

        }else if(number == 9){
            showStatistics();
        }else if(number == 10){
            db.exec("DELETE FROM cars WHERE is_example = 0 OR is_example IS NULL;");
            db.exec("DELETE FROM customers WHERE is_example = 0 OR is_example IS NULL;");
            db.exec("VACUUM"); // Optional: Clean up the database file
            break;
        }
    }
    return 0;
}
