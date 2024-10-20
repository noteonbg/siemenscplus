#if 1
// function_lambda_expression.cpp
// compile with: /EHsc /W4
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Scale
{
public:
    // The constructor.
    explicit Scale(int scale) : _scale(scale) {}

    // Prints the product of each element in a vector object
    // and the scale value to the console.
    void ApplyScale(const vector<int>& v) 
    {
        //for_each(v.begin(), v.end(), [=](int n) { cout << n * _scale << endl; });
        auto x = [=](){ cout << _scale; };
        x();

    }

private:
    int _scale;
};

int main()
{
    vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);

    // Create a Scale object that scales elements by 3 and apply
    // it to the vector object. doesn't modify the vector.
    Scale s(3);
    s.ApplyScale(values);
}

#endif

