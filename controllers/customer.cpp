//
// Created by LinaH on 29.01.2024.
//

#include "../Models/Customer.h"

Customer::Customer(int id, std::string firstName, std::string lastName, std::string address, int ssn, int phoneNumber,
                   std::string email, int licenseNumber){
    this->id = id;
    this->firstName = std::move(firstName);
    this->lastName = std::move(lastName);
    this->address = std::move(address);
    this->ssn = ssn;
    this->phoneNumber = phoneNumber;
    this->email = std::move(email);
    this->licenseNumber = licenseNumber;
}

void Customer::setFirstName(std::string newFirstName){
    this->firstName = std::move(newFirstName);
}

void Customer::setLastName(std::string newLastName){
    this->lastName = std::move(newLastName);
}

void Customer::setAddress(std::string newAddress){
    this->address = std::move(newAddress);
}

int Customer::setSsn(int newSsn){
    this->ssn = newSsn;
    return 0;
}

int Customer::setPhoneNumber(int newPhoneNumber){
    this->phoneNumber = newPhoneNumber;
    return 0;
}

void Customer::setEmail(std::string newEmail) {
    this->email = std::move(newEmail);
}

int Customer::setLicenseNumber(int newLicenseNumber) {
    this->licenseNumber = newLicenseNumber;
    return 0;
}

int Customer::getId() const{
    return this->id;
}

std::string Customer::getFirstName() {
    return this->firstName;
}

std::string Customer::getLastName() {
    return this->lastName;
}

std::string Customer::getAddress() {
    return this->address;
}

int Customer::getSsn(){
    return this->ssn;
}

int Customer::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Customer::getEmail() {
    return this->email;
}

int Customer::getLicenseNumber() {
    return this->licenseNumber;
}