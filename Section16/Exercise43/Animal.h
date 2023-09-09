/*****************************/
/** DO NOT MODIFY THIS FILE **/
/*****************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Abstract base class Animal

class Animal {
public:
    virtual std::string get_noise() const = 0; // Pure virtual function
    virtual int get_num_legs() const = 0; // Pure virtual function
};

#endif /* ANIMAL_H */

