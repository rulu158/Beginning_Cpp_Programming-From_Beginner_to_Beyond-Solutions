#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>
#include <vector>

class Movie
{
private:
    static const std::vector<std::string> allowed_ratings;

    std::string name;
    std::string rating;
    int watched {0};

    bool is_a_valid_rating(std::string rating);
public:
    Movie(std::string name, std::string rating, int watched);
    
    Movie(const Movie &source);
    
    ~Movie();

    void set_name(std::string name) { this->name = name; }
    std::string get_name() const { return name; }

    void set_rating(std::string rating);
    std::string get_rating() const { return rating; }

    void set_watched(int watched);
    int get_watched() { return watched; }

    void increment_watched() { watched++; };

    void display() const;
};

#endif // _MOVIE_H_