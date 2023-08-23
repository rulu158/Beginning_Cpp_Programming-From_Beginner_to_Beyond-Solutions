#include <iostream>
#include "Movies.h"

// constructors
Movies::Movies() {
}

Movies::Movies(const Movies &source)
        : movies(source.movies) {
}

Movies::~Movies() {
    for (auto movie_ptr : movies) {
        delete movie_ptr;
    }
}

void Movies::add_movie(std::string name, std::string rating, int watched) {
    for (auto movie : movies) {
        if (name == movie->get_name()) {
            std::cout << "Can't add the same movie again!" << std::endl;
            return;
        }
    }

    Movie *new_movie = new Movie(name, rating, watched);
    movies.push_back(new_movie);
    std::cout << "Added the movie '" << new_movie->get_name() << "'." << std::endl;
}

void Movies::increment_watched(std::string name) {
    for (auto movie : movies) {
        if (name == movie->get_name()) {
            movie->increment_watched();
            std::cout << "You watched that movie again... it's going to get boring!" << std::endl;
            return;
        }
    }

    std::cout << "Jerk, you didn't watch that movie!" << std::endl;
}

void Movies::display_movies() {
    for (Movie const * movie : movies) {
        movie->display();
    }
}