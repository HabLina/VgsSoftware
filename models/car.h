//
// Created by amand on 2/27/2024.
//

#ifndef EKSAMEN_SOFTWARE_V_2024_CAR_H
#define EKSAMEN_SOFTWARE_V_2024_CAR_H
//
// Created by LinaH on 18.05.2023.
//
#include "string"

class Car{
private:
    int id;
    std::string model;
    std::string brand;
    std::string color;
    std::string licensePlate;
    std::string fuelType;
    std::string transmission;
    std::string carRegistration;
    int availability = true;
public:
    Car(int id, std::string model, std::string brand, std::string color, std::string licensePlate, std::string fuelType,
        std::string transmission, std::string carRegistration, int availability);

    void setModel(std::string model);

    void setBrand(std::string brand);

    void setColor(std::string color);

    void setLicensePlate(std::string licensePlate);

    void setFuelType(std::string fuelType);

    void setTransmission(std::string transmission);

    void setCarRegistration(std::string newCarRegistration);

    int setAvailability(int availability);

    int getId() const;

    std::string getModel();

    std::string getBrand();

    std::string getColor();

    std::string getLicensePlate();

    std::string getFuelType();

    std::string getTransmission();

    std::string getCarRegistration();

    std::string getAvailability();
};


#endif //EKSAMEN_SOFTWARE_V_2024_CAR_H
