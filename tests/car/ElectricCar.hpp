#ifndef ELECTRICCAR_HPP
#define ELECTRICCAR_HPP

#include "Car.hpp"

DERIVED_CLASS(ElectricCar, Car)
    ElectricCar(const std::string& brand, const std::string& model, int batteryCapacity) : Car(brand, model), m_batteryCapacity(batteryCapacity) {}

    FUNC_OVERRIDE(void, drive);

    PROPERTY(int, batteryCapacity)
END_CLASS

FUNC_IMPL(ElectricCar, void, drive)
    std::cout << "Driving an electric " << m_brand << " " << m_model << " with a " << m_batteryCapacity << " kWh battery." << std::endl;
FUNC_END

#endif