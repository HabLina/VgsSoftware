#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include "Models/Car.h"
#include "Models/Customer.h"

//Using smart pointers which automatically deallocate the pointers
//Used the shared variant as the pointers are accessed by different parts in the program
std::vector<std::shared_ptr<Car>> cars;
std::vector<std::shared_ptr<Customer>> customers;
int nextIdCar = 0;
int numberOfCars = 0;

int nextIdCustomer = 0;
int numberOfCustomers = 0;

//Car functions
void addCar() {
    numberOfCars++;
    int id = ++nextIdCar;
    std::string model, brand, color, fuelType, transmission, licensePlate;
    bool availability = true;

    std::cout << "Enter car brand: ";
    std::getline(std::cin, brand);

    std::cout << "Enter car model: ";
    std::getline(std::cin, model);

    std::cout << "Enter car color: ";
    std::getline(std::cin, color);

    std::cout << "Enter car fuel type: ";
    std::getline(std::cin, fuelType);

    std::cout << "Enter car transmission: ";
    std::getline(std::cin, transmission);

    std::cout << "Enter car registration number: ";
    std::getline(std::cin, licensePlate);

    std::shared_ptr<Car> car = std::make_shared<Car>(id, model, brand, color, licensePlate, fuelType, transmission, availability);
    cars.push_back(car);
}

void editCar(int id){
    for (auto& car : cars) {
        if (car->getId() == id) {
            bool continueEditing = true;
            while (continueEditing) {
                std::string model;
                std::string brand;
                std::string color;
                std::string licensePlate;
                std::string fuelType;
                std::string transmission;

                std::string repeat;
                std::string thingToEdit;
                std::cout << "What do you want to edit? (brand, model, color, license plate, fuel type, transmission): ";
                std::getline(std::cin, thingToEdit);

                std::transform(thingToEdit.begin(), thingToEdit.end(), thingToEdit.begin(),
                               [](unsigned char c) { return std::tolower(c); });

                if (thingToEdit == "brand") {
                    std::cout << "Enter new car brand: ";
                    std::getline(std::cin, brand);
                    car->setBrand(brand);
                } else if (thingToEdit == "model") {
                    std::cout << "Enter new car model: ";
                    std::getline(std::cin, model);
                    car->setModel(model);
                } else if (thingToEdit == "color") {
                    std::cout << "Enter new car color: ";
                    std::getline(std::cin, color);
                    car->setColor(color);
                } else if (thingToEdit == "license plate") {
                    std::cout << "Enter new car license plate number: ";
                    std::getline(std::cin, licensePlate);
                    car->setLicensePlate(licensePlate);
                } else if (thingToEdit == "fuel type") {
                    std::cout << "Enter new car fuel type: ";
                    std::getline(std::cin, fuelType);
                    car->setFuelType(fuelType);
                } else if (thingToEdit == "car transmission") {
                    std::cout << "Enter new car transmission: ";
                    std::getline(std::cin, transmission);
                    car->setTransmission(transmission);
                }

                std::cout << "Do you want to edit something else? (yes/no): ";
                std::getline(std::cin, repeat);

                std::transform(repeat.begin(), repeat.end(), repeat.begin(),
                               [](unsigned char c) { return std::tolower(c); });

                continueEditing = (repeat == "yes");
            }
            break;
        }
    }
}

void removeCar(int id){
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if ((*it)->getId() == id) {
            cars.erase(it);
            break;
        }
    }
}

void addCustomer() {
    numberOfCustomers++;
    int id = ++nextIdCustomer;
    std::string firstName, lastName, address, email;
    int phoneNumber;
    long long ssn, licenseNumber;

    std::cout << "Enter customer first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter customer last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Enter customer address: ";
    std::getline(std::cin, address);

    std::cout << "Enter customer email: ";
    std::getline(std::cin, email);

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

    std::shared_ptr<Customer> customer = std::make_shared<Customer>(id, firstName, lastName, address, ssn, phoneNumber, email, licenseNumber);
    customers.push_back(customer);
    std::cout << "Customer added successfully.\n";
}

void editCustomer(int id){
    for (auto& customer : customers) {
        if (customer->getId() == id) {
            std::string firstName;
            std::string lastName;
            std::string address;
            int ssn;
            int phoneNumber;
            std::string email;
            int licenseNumber;

            std::cout << "Enter new customer firstName: ";
            std::cin.ignore();
            std::getline(std::cin, firstName);

            std::cout << "Enter new customer lastName: ";
            std::getline(std::cin, lastName);

            std::cout << "Enter new customer address: ";
            std::getline(std::cin, address);

            std::cout << "Enter new customer social security number: ";
            std::cin >> ssn;

            std::cout << "Enter new customer phone number: ";
            std::cin >> phoneNumber;

            std::cout << "Enter new customer email: ";
            std::getline(std::cin, email);

            std::cout << "Enter new customer license number: ";
            std::cin >> licenseNumber;

            customer->setFirstName(firstName);
            customer->setLastName(lastName);
            customer->setAddress(address);
            customer->setSsn(ssn);
            customer->setPhoneNumber(phoneNumber);
            customer->setEmail(email);
            customer->setLicenseNumber(licenseNumber);
            break;
        }
    }
}

void removeCustomer(int id){
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if ((*it)->getId() == id) {
            customers.erase(it);
            break;
        }
    }
}

void printEverything() {
    for (auto& car : cars) {
        std::cout << "Car id = " << car->getId() << ", " <<
                  "Model = " << car->getModel() << ", " <<
                  "Brand = " << car->getBrand() << ", " <<
                  "Color = " << car->getColor() << ", " <<
                  "License plate = " << car->getLicensePlate() << ", " <<
                  "Fuel type = " << car->getFuelType() << ", " <<
                  "Transmission = " << car->getTransmission() << ", " <<
                  "Availability = " << car->getAvailability() << ", " <<
                  "\n";
        std::cout << "\n";
    }

    for (auto& customer : customers) {
        std::cout << "Customer id = " << customer->getId() << ", " <<
                  "First name = " << customer->getFirstName() << ", " <<
                  "Last name = " << customer->getLastName() << ", " <<
                  "Address = " << customer->getAddress() << ", " <<
                  "Ssn = " << customer->getSsn() << ", " <<
                  "Phone number = " << customer->getPhoneNumber() << ", " <<
                  "Email = " << customer->getEmail() << ", " <<
                  "License number = " << customer->getLicenseNumber() <<
                  "\n";
        std::cout << "\n";
    }
}

void assignCar(int customerId, int carId){

}

void showStatistics(){
    auto totalCustomers = customers.size();
    auto totalCars = cars.size();
    int availableCars = 0;
    int activeRentals = 0;

    for (auto& car : cars) {
        if (car->getAvailability() == "true") {
            availableCars++;
        } else {
            activeRentals++;
        }
    }

    std::cout << "Statistics:\n"
              << "Total number of customers: " << totalCustomers << "\n"
              << "Total number of cars: " << totalCars << "\n"
              << "Number of active rentals: " << activeRentals << "\n"
              << "Number of available cars: " << availableCars << "\n";
}


int main() {
    // Pre-adding two example cars
    std::shared_ptr<Car> exampleCar1 = std::make_shared<Car>(1, "Model S", "Tesla", "Red", "ABC123", "Electric", "Automatic", true);
    cars.push_back(exampleCar1);
    nextIdCar++;  // Since we've added a car, we increment the id

    std::shared_ptr<Car> exampleCar2 = std::make_shared<Car>(2, "Civic", "Honda", "Blue", "XYZ789", "Gasoline", "Manual", true);
    cars.push_back(exampleCar2);
    nextIdCar++;  // Since we've added a car, we increment the id

    // Pre-adding two example cars
    std::shared_ptr<Customer> exampleCustomer1 = std::make_shared<Customer>(1, "Lina", "Habaieb", "Tonnevoldsgate 26", 12345678, 90836743, "linaha@uia.no", 9293878393048);
    customers.push_back(exampleCustomer1);
    nextIdCustomer++;  // Since we've added a customer, we increment the id

    std::shared_ptr<Customer> exampleCustomer2 = std::make_shared<Customer>(2, "Thomas", "Hetland", "Tonnevoldsvei 46", 98765432, 45784318, "thomashe@uia.no", 8848392834793);
    customers.push_back(exampleCustomer2);
    nextIdCustomer++;  // Since we've added a customer, we increment the id

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
            std::cout << "Choose a customer by typing its id: \n";
            std::cin >> chosenId;
            editCustomer(chosenId);
        }else if(number == 6){
            int chosenId;
            std::cout << "Choose a customer by typing its id: \n";
            std::cin >> chosenId;
            removeCustomer(chosenId);
        }else if(number == 7){
            int customerId;
            int carId;

            std::cout << "Choose a customer by typing its id: \n";
            std::cin >> customerId;

            std::cout << "Choose a car by typing its id: \n";
            std::cin >> carId;
            assignCar(customerId, carId);
        }else if(number == 8){
            printEverything();
        }else if(number == 9){
            showStatistics();
        }else if(number == 10){
            break;
        }
    }
    return 0;
}
