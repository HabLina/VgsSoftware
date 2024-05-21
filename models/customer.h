//
// Created by LinaH on 29.01.2024.
//

#ifndef EKSAMEN_SOFTWARE_V_2024_CUSTOMER_H
#define EKSAMEN_SOFTWARE_V_2024_CUSTOMER_H
#include "string"

class Customer{
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string address;
    int ssn;
    int phoneNumber;
    std::string email;
    int licenseNumber;
public:
    Customer(int id, std::string firstName, std::string lastName, std::string address, int ssn, int phoneNumber,
             std::string email, int licenseNumber);

    void setFirstName(std::string firstName);

    void setLastName(std::string lastName);

    void setAddress(std::string address);

    int setSsn(int ssn);

    int setPhoneNumber(int phoneNumber);

    void setEmail(std::string email);

    int setLicenseNumber(int licenseNumber);

    int getId() const;

    std::string getFirstName();

    std::string getLastName();

    std::string getAddress();

    int getSsn();

    int getPhoneNumber();

    std::string getEmail();

    int getLicenseNumber();
};

#endif //EKSAMEN_SOFTWARE_V_2024_CUSTOMER_H