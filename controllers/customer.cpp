//
// Created by LinaH on 29.01.2024.
//

#include "../Models/customer.h"

Customer::Customer(int id, std::string firstName, std::string lastName, std::string address, long long ssn, int phoneNumber,
                   std::string email, long long licenseNumber){
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

long long Customer::setSsn(long long newSsn){
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

long long Customer::setLicenseNumber(long long newLicenseNumber) {
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

long long Customer::getSsn(){
    return this->ssn;
}

int Customer::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Customer::getEmail() {
    return this->email;
}

long long Customer::getLicenseNumber() {
    return this->licenseNumber;
}