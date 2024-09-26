#include <iostream>
#include <vector>
#include <algorithm>  // Include the algorithm header for std::find
#include <string>

namespace MedicalDomain {

    class MedicalDevice {
    private:
        std::string name_;
        std::string serialNumber_;

    public:
        MedicalDevice(const std::string& name, const std::string& serialNumber)
            : name_(name), serialNumber_(serialNumber) {}

        std::string getName() const {
            return name_;
        }

        std::string getSerialNumber() const {
            return serialNumber_;
        }
    };

}  // End of namespace MedicalDomain




int main() {



    // Create a vector of MedicalDevice objects
    std::vector<MedicalDomain::MedicalDevice> deviceList;

    // Add some devices to the vector
    deviceList.push_back(MedicalDomain::MedicalDevice("Blood Pressure Monitor", "BP12345"));
    deviceList.push_back(MedicalDomain::MedicalDevice("Thermometer", "T98765"));
    deviceList.push_back(MedicalDomain::MedicalDevice("Pulse Oximeter", "POX54321"));


    
    // Find a device by name (e.g., "Thermometer")
    std::string targetDeviceName = "Thermometer";
    auto it = std::find_if(deviceList.begin(), deviceList.end(),
                           [targetDeviceName]
                           (MedicalDomain::MedicalDevice device){
                               return device.getName() == targetDeviceName;
                                                          });

    
    
    if (it != deviceList.end()) {
        std::cout << "Found device: " << it->getName() << ", Serial Number: " << it->getSerialNumber() << std::endl;
    } else {
        std::cout << "Device not found." << std::endl;
    }

    
    return 0;
}
