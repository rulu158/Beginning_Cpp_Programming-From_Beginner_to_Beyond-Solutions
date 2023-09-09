#ifndef LION_H
#define LION_H

/****************************************************************************************
Provide the declaration here for the Lion class.
Remember, this is the declaration only.
This file should contain the Lion class and the prototypes for the Lion class' methods
****************************************************************************************/

// Derived class Lion
// Write your code below this line

#include "Animal.h"

class Lion : public Animal {
public:
    virtual std::string get_noise() const override;
    virtual int get_num_legs() const override;
};

// Write your code above this line
#endif
