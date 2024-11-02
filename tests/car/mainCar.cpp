#include "ElectricCar.hpp"

int main()
{
    Scope<ICar> myElectricCar = MAKE_SCOPE(ElectricCar, "Tesla", "Model S", 100);

    myElectricCar->drive();

    ElectricCar *ec = dynamic_cast<ElectricCar *>(myElectricCar.get());
    if (ec)
    {
        ec->set_brand("Tesla");
        ec->set_model("Model S");
        ec->set_batteryCapacity(100);
        std::cout << "Brand: " << ec->get_brand() << ", Model: " << ec->get_model()
                  << ", Battery Capacity: " << ec->get_batteryCapacity() << " kWh" << std::endl;
    }

    return 0;
}
