#include <iostream>
#include <iomanip>

//template creation
template <class T,class Z>

// Z should be.. arithmetic type only
//Z should be copyable, Z should not movable..
class X
{
    private:
        mutable T x;
    public:
        void setX(T z) { x = z;}
        T getX() const { return x;}


};

int main()
{
    X<int> obj;  //template instnatitation
    X<char> obj1;



}





#if 0
// Medical domain namespace
namespace MedicalDomain {

    // Template function to calculate BMI
    template <typename T>
    T calculateBMI(T weight, T height) {
        // BMI formula: weight (kg) / (height (m))^2
        std::cout <<"ok templates function at work"
        return weight;
        //return weight / (height * height);
    }

}  // End of namespace MedicalDomain

int main() {

    //instntiating the template.

    char c = MedicalDomain::calculateBMI<char>('a','b'); // template is instantiated.
    double d = MedicalDomain::calculateBMI<double>(2.3,4.4);




    #if 0
    // Example usage
    double weightKg = 70.0;  // Weight in kilograms
    double heightMeters = 1.75;  // Height in meters

    // Calculate BMI using the template function
    double bmi = MedicalDomain::calculateBMI(weightKg, heightMeters);

    // Display the result
    std::cout << "Patient's BMI: " << std::fixed << std::setprecision(2) << bmi << std::endl;

    #endif
    return 0;
}

#endif
