#ifndef CAR_HPP
#define CAR_HPP

#include "ICar.hpp"

DERIVED_CLASS(Car, ICar)
    Car(const std::string& brand, const std::string& model) : m_brand(brand), m_model(model) {}
        
    FUNC_OVERRIDE(void, drive);

    PROPERTY(std::string, brand);
    PROPERTY(std::string, model);
END_DERIVED_CLASS

FUNC_IMPL(Car, void, drive)
    std::cout << "Driving a " << m_brand << " " << m_model << std::endl;
FUNC_END

#endif