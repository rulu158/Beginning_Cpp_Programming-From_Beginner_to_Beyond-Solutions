#include "Dog.h"

// Implement the appropriate Dog class methods below this inline

Dog::Dog(const std::string &name, int age) : Animal(name, age) {}

std::string Dog::get_noise() const {
    return "Woof";
}
int Dog::get_num_legs() const {
    return 4;
}

// Implement the appropriate Dog class methods above this inline
