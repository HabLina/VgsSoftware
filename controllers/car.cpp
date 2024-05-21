//
// Created by LinaH on 18.05.2023.
//

#include <utility>

#include "../Models/car.h"

Car::Car(int id, std::string model, std::string brand, std::string color, std::string licensePlate, std::string fuelType,
         std::string transmission, std::string carRegistration, int availability){
    this->id = id;
    this->model = std::move(model);
    this->brand = std::move(brand);
    this->color = std::move(color);
    this->licensePlate = std::move(licensePlate);
    this->fuelType = std::move(fuelType);
    this->transmission = std::move(transmission);
    this->carRegistration = std::move(carRegistration);
    this->availability = availability;
}

void Car::setModel(std::string newModel){
    this->model = std::move(newModel);
}

void Car::setBrand(std::string newBrand){
    this->brand = std::move(newBrand);
}

void Car::setColor(std::string newColor){
    this->color = std::move(newColor);
}

void Car::setLicensePlate(std::string newLicensePlate){
    this->licensePlate = std::move(newLicensePlate);
}

void Car::setFuelType(std::string newFuelType){
    this->fuelType = std::move(newFuelType);
}

void Car::setTransmission(std::string newTransmission) {
    this->transmission = std::move(newTransmission);
}

void Car::setCarRegistration(std::string newCarRegistration) {
    this->carRegistration = std::move(newCarRegistration);
}

int Car::getId() const{
    return this->id;
}

std::string Car::getModel(){
    return this->model;
}

std::string Car::getBrand(){
    return this->brand;
}

std::string Car::getColor(){
    return this->color;
}

std::string Car::getLicensePlate(){
    return this->licensePlate;
}

std::string Car::getFuelType() {
    return this->fuelType;
}

std::string Car::getTransmission() {
    return this->transmission;
}

std::string Car::getCarRegistration() {
    return this->carRegistration;
}

std::string Car::getAvailability() {
    if (this->availability == true){
        return "Available";
    }else{
        return "Not available";
    }

}