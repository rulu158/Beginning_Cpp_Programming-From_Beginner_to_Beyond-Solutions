#include <iostream>
#include "Movies.h"

int main() {
    Movies movie_collection;
    movie_collection.add_movie("Star Wars", "PG", 0);
    movie_collection.add_movie("Star Wars", "PG", 0);
    movie_collection.add_movie("The Goodfather", "PG", 0);
    movie_collection.display_movies();
    movie_collection.increment_watched("Star Wars");
    movie_collection.increment_watched("Star Wards");
    movie_collection.display_movies();

    return 0;
}