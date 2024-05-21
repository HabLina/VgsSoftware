#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Models/Car.h"
#include "Models/Customer.h"

std::vector<Car*> cars;
std::vector<Customer*> customers;
int nextIdCar = 1;
int numberOfCars = 0;

int nextIdCustomer = 1;
int numberOfCustomers = 0;

//Car functions
void addCar() {
    numberOfCars++;
    int id;
    std::string model;
    std::string brand;
    std::string color;
    std::string fuelType;
    std::string transmission;
    int availability = true;
    std::string licensePlate;

    //Increase id
    id = nextIdCar;
    nextIdCar ++;
    nextIdCar = nextIdCar;

    std::cout << "Enter car brand:";
    std::getline(std::cin, brand);

    std::cout << "Enter car model:";
    std::getline(std::cin, model);

    std::cout << "Enter car color:";
    std::getline(std::cin, color);

    std::cout << "Enter car fuel type:";
    std::getline(std::cin, fuelType);

    std::cout << "Enter car transmission:";
    std::getline(std::cin, transmission);

    std::cout << "Enter car registration number:";
    std::getline(std::cin, licensePlate);

    auto* car = new Car(id, model, brand, color, licensePlate, fuelType, transmission, availability);
    cars.push_back(car);
}

void editCar(int id){
    for (auto car : cars) {
        if (car->getId() == id) {
            std::string model;
            std::string brand;
            std::string color;
            std::string licensePlate;
            std::string fuelType;
            std::string transmission;

            std::cout << "Enter new car brand: ";
            std::getline(std::cin, brand);

            std::cout << "Enter new car model: ";
            std::getline(std::cin, model);

            std::cout << "Enter new car color: ";
            std::getline(std::cin, color);

            std::cout << "Enter new car license plate number: ";
            std::getline(std::cin, licensePlate);

            std::cout << "Enter new car fuel type: ";
            std::getline(std::cin, fuelType);

            std::cout << "Enter new car transmission: ";
            std::getline(std::cin, transmission);

            car->setModel(model);
            car->setBrand(brand);
            car->setColor(color);
            car->setLicensePlate(licensePlate);
            car->setFuelType(fuelType);
            car->setTransmission(transmission);
            break;
        }
    }
}

void removeCar(int id){
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        Car* car = *it;
        if (car->getId() == id) {
            cars.erase(it);
            break;
        }
    }
}

void addCustomer() {
    numberOfCustomers++;
    int id;
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string email;
    int ssn;
    int phoneNumber;
    int licenseNumber;

    //Increase id
    id = nextIdCustomer;
    nextIdCustomer ++;
    nextIdCustomer = nextIdCustomer;

    std::cout << "Enter customer first name:";
    std::getline(std::cin, firstName);

    std::cout << "Enter customer last name:";
    std::getline(std::cin, lastName);

    std::cout << "Enter customer address:";
    std::getline(std::cin, address);

    std::cout << "Enter customer email:";
    std::getline(std::cin, email);

    std::cout << "Enter customer social security number:";
    std::cin >> ssn;

    std::cout << "Enter customer phone number:";
    std::cin >> phoneNumber;

    std::cout << "Enter customer license number:";
    std::cin >> licenseNumber;

    auto* customer = new Customer(id, firstName, lastName, address, ssn, phoneNumber, email, licenseNumber);
    customers.push_back(customer);
}

void editCustomer(int id){
    for (auto customer : customers) {
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
        Customer* customer = *it;
        if (customer->getId() == id) {
            customers.erase(it);
            break;
        }
    }
}

void printEverything() {
    for (auto car : cars) {
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

    for (auto customer : customers) {
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

int main() {
    // Pre-adding two example cars
    auto* exampleCar1 = new Car(1, "Model S", "Tesla", "Red", "ABC123", "Electric", "Automatic", true);
    cars.push_back(exampleCar1);
    nextIdCar++;  // Increment the next ID since we've added a car

    auto* exampleCar2 = new Car(2, "Civic", "Honda", "Blue", "XYZ789", "Gasoline", "Manual", true);
    cars.push_back(exampleCar2);
    nextIdCar++;  // Increment the next ID again

    // Pre-adding two example cars
    auto* exampleCustomer1 = new Customer(1, "Lina", "Habaieb", "Tonnevoldsgate 26", 12345678, 90836743, "linaha@uia.no", 9293878393048);
    customers.push_back(exampleCustomer1);
    nextIdCustomer++;  // Increment the next ID since we've added a car

    auto* exampleCustomer2 = new Customer(2, "Thomas", "Hetland", "Tonnevoldsvei 46", 98765432, 45784318, "thomashe@uia.no", 8848392834793);
    customers.push_back(exampleCustomer2);
    nextIdCustomer++;  // Increment the next ID again

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
                 "9. Exit" << std::endl;

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
            break;
        }
    }
    return 0;
}
