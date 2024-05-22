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

// Car functions
void addCar() {
    numberOfCars++;
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    std::string model, brand, color, fuelType, transmission, licensePlate, carRegistration;

    std::cout << "Enter car brand: ";
    std::getline(std::cin, brand);
    std::transform(brand.begin(), brand.end(), brand.begin(), ::tolower);

    std::cout << "Enter car model: ";
    std::getline(std::cin, model);
    std::transform(model.begin(), model.end(), model.begin(), ::tolower);

    std::cout << "Enter car color: ";
    std::getline(std::cin, color);
    std::transform(color.begin(), color.end(), color.begin(), ::tolower);

    std::cout << "Enter car fuel type: ";
    std::getline(std::cin, fuelType);
    std::transform(fuelType.begin(), fuelType.end(), fuelType.begin(), ::tolower);

    std::cout << "Enter car transmission: ";
    std::getline(std::cin, transmission);
    std::transform(transmission.begin(), transmission.end(), transmission.begin(), ::tolower);

    std::cout << "Enter license plate number: ";
    std::getline(std::cin, licensePlate);
    std::transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);

    std::cout << "Enter car registration number: ";
    std::getline(std::cin, carRegistration);
    std::transform(carRegistration.begin(), carRegistration.end(), carRegistration.begin(), ::tolower);

    try {
        SQLite::Statement query(db, "INSERT INTO cars (model, brand, color, fuelType, transmission, availability, licensePlate, carRegistration) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        query.bind(1, model);
        query.bind(2, brand);
        query.bind(3, color);
        query.bind(4, fuelType);
        query.bind(5, transmission);
        query.bind(6, true);
        query.bind(7, licensePlate);
        query.bind(8, carRegistration);
        query.exec();
        std::cout << "Car inserted successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Failed to insert car: " << e.what() << std::endl;
    }
}

void editCar(int id) {
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    bool continueEditing = true;
    while (continueEditing) {
        std::string model, brand, color, licensePlate, fuelType, transmission, carRegistration, repeat, thingToEdit;

        std::cout << "What do you want to edit? (brand, model, color, license plate, car registration, fuel type, transmission): ";
        std::getline(std::cin, thingToEdit);
        std::transform(thingToEdit.begin(), thingToEdit.end(), thingToEdit.begin(), ::tolower);

        if (thingToEdit == "brand") {
            std::cout << "Enter new car brand: ";
            std::getline(std::cin, brand);
            std::transform(brand.begin(), brand.end(), brand.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE cars SET brand = ? WHERE id = ?");
            query.bind(1, brand);
            query.bind(2, id);
            query.exec();
            std::cout << "Brand edited successfully.\n";
        } else if (thingToEdit == "model") {
            std::cout << "Enter new car model: ";
            std::getline(std::cin, model);
            std::transform(model.begin(), model.end(), model.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE cars SET model = ? WHERE id = ?");
            query.bind(1, model);
            query.bind(2, id);
            query.exec();
            std::cout << "Model edited successfully.\n";
        } else if (thingToEdit == "color") {
            std::cout << "Enter new car color: ";
            std::getline(std::cin, color);
            std::transform(color.begin(), color.end(), color.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE cars SET color = ? WHERE id = ?");
            query.bind(1, color);
            query.bind(2, id);
            query.exec();
            std::cout << "Color edited successfully.\n";
        } else if (thingToEdit == "license plate") {
            std::cout << "Enter new car license plate number: ";
            std::getline(std::cin, licensePlate);
            std::transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE cars SET licensePlate = ? WHERE id = ?");
            query.bind(1, licensePlate);
            query.bind(2, id);
            query.exec();
            std::cout << "License plate edited successfully.\n";
        } else if (thingToEdit == "car registration") {
            std::cout << "Enter new car registration number: ";
            std::getline(std::cin, carRegistration);
            std::transform(carRegistration.begin(), carRegistration.end(), carRegistration.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE cars SET carRegistration = ? WHERE id = ?");
            query.bind(1, carRegistration);
            query.bind(2, id);
            query.exec();
            std::cout << "Car registration number edited successfully.\n";
        } else if (thingToEdit == "fuel type") {
            std::cout << "Enter new car fuel type: ";
            std::getline(std::cin, fuelType);
            std::transform(fuelType.begin(), fuelType.end(), fuelType.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE cars SET fuelType = ? WHERE id = ?");
            query.bind(1, fuelType);
            query.bind(2, id);
            query.exec();
            std::cout << "Fuel type edited successfully.\n";
        } else if (thingToEdit == "transmission") {
            std::cout << "Enter new car transmission: ";
            std::getline(std::cin, transmission);
            std::transform(transmission.begin(), transmission.end(), transmission.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE cars SET transmission = ? WHERE id = ?");
            query.bind(1, transmission);
            query.bind(2, id);
            query.exec();
            std::cout << "Car transmission edited successfully.\n";
        } else {
            std::cout << "Invalid input; please enter one of the previously listed options: ";
        }

        std::cout << "Do you want to edit something else? (yes/no): ";
        std::getline(std::cin, repeat);
        std::transform(repeat.begin(), repeat.end(), repeat.begin(), ::tolower);
        continueEditing = (repeat == "yes");
    }
}

void removeCar(int id) {
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE);
    SQLite::Statement query(db, "DELETE FROM cars WHERE id = ?");
    query.bind(1, id);
    query.exec();
}

void addCustomer() {
    numberOfCustomers++;
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    std::string firstName, lastName, address, email;
    int phoneNumber;
    long long ssn, licenseNumber;

    std::cout << "Enter customer first name: ";
    std::getline(std::cin, firstName);
    std::transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);

    std::cout << "Enter customer last name: ";
    std::getline(std::cin, lastName);
    std::transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);

    std::cout << "Enter customer address: ";
    std::getline(std::cin, address);
    std::transform(address.begin(), address.end(), address.begin(), ::tolower);

    std::cout << "Enter customer email: ";
    std::getline(std::cin, email);
    std::transform(email.begin(), email.end(), email.begin(), ::tolower);

    std::cout << "Enter customer social security number: ";
    while (!(std::cin >> ssn)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please enter a valid number for social security number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter customer phone number: ";
    while (!(std::cin >> phoneNumber)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please enter a valid phone number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter customer license number: ";
    while (!(std::cin >> licenseNumber)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please enter a valid license number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        SQLite::Statement query(db, "INSERT INTO customers (firstName, lastName, address, ssn, phoneNumber, email, licenseNumber, is_example) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        query.bind(1, firstName);
        query.bind(2, lastName);
        query.bind(3, address);
        query.bind(4, ssn);
        query.bind(5, phoneNumber);
        query.bind(6, email);
        query.bind(7, licenseNumber);
        query.bind(8, 0);
        query.exec();
        std::cout << "Customer inserted successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Failed to insert customer: " << e.what() << std::endl;
    }
}

void editCustomer(int id) {
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    bool continueEditing = true;
    while (continueEditing) {
        std::string firstName, lastName, address, email, repeat, thingToEdit;
        int ssn, phoneNumber, licenseNumber;

        std::cout << "What do you want to edit? (first name, last name, address, email, social security number, phone number, license number): ";
        std::getline(std::cin, thingToEdit);
        std::transform(thingToEdit.begin(), thingToEdit.end(), thingToEdit.begin(), ::tolower);

        if (thingToEdit == "first name") {
            std::cout << "Enter new customer first name: ";
            std::getline(std::cin, firstName);
            std::transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE customers SET firstName = ? WHERE id = ?");
            query.bind(1, firstName);
            query.bind(2, id);
            query.exec();
            std::cout << "First name edited successfully.\n";
        } else if (thingToEdit == "last name") {
            std::cout << "Enter new customer last name: ";
            std::getline(std::cin, lastName);
            std::transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE customers SET lastName = ? WHERE id = ?");
            query.bind(1, lastName);
            query.bind(2, id);
            query.exec();
            std::cout << "Last name edited successfully.\n";
        } else if (thingToEdit == "address") {
            std::cout << "Enter new customer address: ";
            std::getline(std::cin, address);
            std::transform(address.begin(), address.end(), address.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE customers SET address = ? WHERE id = ?");
            query.bind(1, address);
            query.bind(2, id);
            query.exec();
            std::cout << "Address edited successfully.\n";
        } else if (thingToEdit == "email") {
            std::cout << "Enter new customer email: ";
            std::getline(std::cin, email);
            std::transform(email.begin(), email.end(), email.begin(), ::tolower);

            SQLite::Statement query(db, "UPDATE customers SET email = ? WHERE id = ?");
            query.bind(1, email);
            query.bind(2, id);
            query.exec();
            std::cout << "Email edited successfully.\n";
        } else if (thingToEdit == "social security number") {
            std::string input;

            std::cout << "Enter customer social security number: ";
            std::getline(std::cin, input);
            ssn = std::stoi(input);

            SQLite::Statement query(db, "UPDATE customers SET ssn = ? WHERE id = ?");
            query.bind(1, ssn);
            query.bind(2, id);
            query.exec();
            std::cout << "Social security number edited successfully.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (thingToEdit == "phone number") {
            std::string input;

            std::cout << "Enter customer phone number: ";
            std::getline(std::cin, input);
            phoneNumber = std::stoi(input);

            SQLite::Statement query(db, "UPDATE customers SET phoneNumber = ? WHERE id = ?");
            query.bind(1, phoneNumber);
            query.bind(2, id);
            query.exec();
            std::cout << "Phone number edited successfully.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (thingToEdit == "license number") {
            std::string input;

            std::cout << "Enter customer license number: ";
            std::getline(std::cin, input);
            licenseNumber = std::stoi(input);

            SQLite::Statement query(db, "UPDATE customers SET licenseNumber = ? WHERE id = ?");
            query.bind(1, licenseNumber);
            query.bind(2, id);
            query.exec();
            std::cout << "License number edited successfully.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout << "Invalid input; please enter one of the previously listed options: ";
        }

        std::cout << "Do you want to edit something else? (yes/no): ";
        std::getline(std::cin, repeat);
        std::transform(repeat.begin(), repeat.end(), repeat.begin(), ::tolower);
        continueEditing = (repeat == "yes");
    }
}

void removeCustomer(int id) {
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE);
    SQLite::Statement query(db, "DELETE FROM customers WHERE id = ?");
    query.bind(1, id);
    query.exec();
}

void assignCar(int customerId, int carId) {
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE);

    try {
        SQLite::Statement query(db, "UPDATE cars SET availability = ?, customerId = ? WHERE id = ?");
        query.bind(1, false);
        query.bind(2, customerId);
        query.bind(3, carId);
        query.exec();
        std::cout << "Car assigned to customer successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error assigning car to customer: " << e.what() << std::endl;
    }
}

void unassignCar(int carId) {
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE);

    try {
        SQLite::Statement query(db, "UPDATE cars SET availability = ?, customerId = NULL WHERE id = ?");
        query.bind(1, true);
        query.bind(2, carId);
        query.exec();
        std::cout << "Car unassigned successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error unassigning car: " << e.what() << std::endl;
    }
}

void showStatistics() {
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE);

    const char* queries[] = {
            "SELECT COUNT(*) FROM customers;",
            "SELECT COUNT(*) FROM cars;",
            "SELECT COUNT(*) FROM cars WHERE availability = 0;",
            "SELECT COUNT(*) FROM cars WHERE availability = 1;"
    };

    const char* descriptions[] = {
            "Number of customers: ",
            "Number of cars: ",
            "Number of active rentals: ",
            "Number of available cars: "
    };

    for (int i = 0; i < 4; ++i) {
        try {
            SQLite::Statement query(db, queries[i]);
            query.executeStep();
            int count = query.getColumn(0);
            std::cout << descriptions[i] << count << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Failed to execute query: " << e.what() << std::endl;
        }
    }
}

int main() {
    // Open a database file
    SQLite::Database db("identifier.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    std::cout << "Please choose:\n"
              << "\n"
              << "1. Add car\n"
              << "2. Edit car\n"
              << "3. Remove car\n"
              << "\n"
              << "4. Add customer\n"
              << "5. Edit customer\n"
              << "6. Remove customer\n"
              << "\n"
              << "7. Assign car to customer\n"
              << "8. Unassign car from customer\n"
              << "9. Show all info\n"
              << "10. Show statistics\n"
              << "11. Exit" << std::endl;  

    while (true) {
        int number;
        std::cin >> number;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (number == 1) {
            addCar();
        } else if (number == 2) {
            int chosenId;
            std::cout << "Choose a car by typing its id: \n";
            std::cin >> chosenId;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            editCar(chosenId);
        } else if (number == 3) {
            int chosenId;
            std::cout << "Choose a car by typing its id: \n";
            std::cin >> chosenId;
            removeCar(chosenId);
        } else if (number == 4) {
            addCustomer();
        } else if (number == 5) {
            int chosenId;
            std::cout << "Choose a customer by typing its id: \n";
            std::cin >> chosenId;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            editCustomer(chosenId);
        } else if (number == 6) {
            int chosenId;
            std::cout << "Choose a customer by typing its id: \n";
            std::cin >> chosenId;
            removeCustomer(chosenId);
        } else if (number == 7) {
            int customerId;
            int carId;
            std::cout << "Choose a customer by typing its id: \n";
            std::cin >> customerId;
            std::cout << "Choose a car by typing its id: \n";
            std::cin >> carId;
            assignCar(customerId, carId);
        } else if (number == 8) {
            int carId;
            std::cout << "Choose a car by typing its id: \n";
            std::cin >> carId;
            unassignCar(carId);
        } else if (number == 9) {
        } else if (number == 10) {
            showStatistics();
        } else if (number == 11) {
            db.exec("DELETE FROM cars WHERE is_example = 0 OR is_example IS NULL;");
            db.exec("DELETE FROM customers WHERE is_example = 0 OR is_example IS NULL;");
            db.exec("VACUUM");
            break;
        }
    }
    return 0;
}
