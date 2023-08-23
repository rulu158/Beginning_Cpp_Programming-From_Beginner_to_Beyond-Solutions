#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include <vector>
#include "Movie.h"

class Movies {
private:
    std::vector<Movie *> movies;
public:
    Movies();
    Movies(const Movies &source);
    ~Movies();

    void add_movie(std::string name, std::string rating, int watched);
    void increment_watched(std::string name);
    void display_movies();
};

#endif // _MOVIES_H