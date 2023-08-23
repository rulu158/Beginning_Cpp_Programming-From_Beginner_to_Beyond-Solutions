#include <iostream>
#include "Movie.h"

// private
// static
const std::vector<std::string> Movie::allowed_ratings { "G", "PG", "PG-13", "R" };

bool Movie::is_a_valid_rating(std::string rating) {
    bool valid_rating {false};
    for (auto allowed_rating : Movie::allowed_ratings) {
        if (rating == allowed_rating) {
            valid_rating = true;
            break;
        }
    }
    return valid_rating;
}

// constructors
Movie::Movie(std::string name, std::string rating, int watched) {
    this->name = name;
    if (name != "") {
        this->name = name;
    } else {
        std::cout << "A MOVIE MUST HAVE A NAME!!" << std::endl;
        throw;
    }
    if (is_a_valid_rating(rating)) {
        this->rating = rating;
    } else {
        this->rating = "G";
        std::cout << "you didn't introduce a valid rating. defaulting to G" << std::endl;
    }
    if (watched >= 0) {
        this->watched = watched;
    } else {
        this->watched = 0;
        std::cout << "'watched' cannot be negative. defaulting to 0" << std::endl;
    }
}

Movie::Movie(const Movie &source)
        : Movie{source.name, source.rating, source.watched} {
}

Movie::~Movie() {
}

// public
void Movie::set_rating(std::string rating) {
    if (is_a_valid_rating(rating)) {
        this->rating = rating;
    } else {
        std::cout << "you didn't introduce a valid rating" << std::endl;
    }
}

void Movie::set_watched(int watched) {
    if (watched >= 0) {
        this->watched = watched;
    } else {
        std::cout << "'watched' cannot be negative" << std::endl;
    }
}

void Movie::display() const {
    std::cout
        << "Name: " << name << "; rating: " << rating << "; watched: " << watched << " time(s)"
        << std::endl;
}