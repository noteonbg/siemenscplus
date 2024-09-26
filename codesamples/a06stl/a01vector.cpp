#include <iostream>
#include <vector>
#include <string>

namespace MedicalDomain {

    class MedicalDevice {
    private:
        std::string name_;
        std::string serialNumber_;

    public:
        MedicalDevice(const MedicalDevice &m):name_(m.name_), serialNumber_(m.serialNumber_)  {
                std::cout  << "copy of MedicalDevice";

        }

        MedicalDevice(const MedicalDevice &&m):name_(m.name_), serialNumber_(m.serialNumber_)  {
                std::cout  << "move  of MedicalDevice";

        }



        MedicalDevice(const std::string& name, const std::string& serialNumber)
            : name_(name), serialNumber_(serialNumber) {}

        std::string getName() const {
            return name_;
        }

        std::string getSerialNumber() const {
            return serialNumber_;
        }

        // Setter for serial number
        void setSerialNumber(const std::string& newSerialNumber) {
            serialNumber_ = newSerialNumber;
        }
    };

}  // End of namespace MedicalDomain

int main() {
    // Create a vector of MedicalDevice objects
    std::vector<MedicalDomain::MedicalDevice> deviceList;
    deviceList.reserve(5);
    // Add some devices to the vector
    deviceList.push_back(MedicalDomain::MedicalDevice("Blood Pressure Monitor", "BP12345"));
    deviceList.push_back(MedicalDomain::MedicalDevice("Thermometer", "T98765"));  // Original serial number
    deviceList.push_back(MedicalDomain::MedicalDevice("Pulse Oximeter", "POX54321"));


#if 1
    // Modify the serial number of the thermometer
    deviceList[1].setSerialNumber("T12345");  // New serial number










    

    // Display the updated devices
    std::cout << "Updated Medical Devices in the Hospital:" << std::endl;
    for (const auto& device : deviceList) {
        std::cout << "Name: " << device.getName() << ", Serial Number: " << device.getSerialNumber() << std::endl;
    }
#endif
    return 0;
}
