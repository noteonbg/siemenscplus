#pragma once

#include <iostream>
#include <string>

template <typename T>
class ElectronicComponent {
public:
    ElectronicComponent(const std::string& name, T value);
    void print() const;

private:
    std::string name;
    T value;
};
