// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void ruler(int n) {
    int next_num {1};
    for (int i {0}; i < n; i++) {
        std::cout << next_num;
        if (next_num == 9) {
            next_num = 0;
        } else {
            next_num++;
        }
    }
    std::cout << std::endl;
}

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    const int table_width {70};

    // Unformatted display so you can see how to access the vector elements
    ruler(table_width);

    std::cout << std::endl;
    int title_width {(table_width + static_cast<int>(tours.title.length())) / 2};
    std::cout << std::setw(title_width) << std::right << tours.title << std::endl;
    std::cout << std::endl;

    std::cout << std::setw(20) << std::left << "Country"
        << std::setw(20) << std::left << "City"
        << std::setw(15) << std::right << "Population"
        << std::setw(15) << std::right << "Price"
        << std::endl;

    std::cout << std::setfill('-');
    std::cout << std::setw(table_width) << '-' << std::endl;
    std::cout << std::setfill(' ');

    for(auto country : tours.countries) {   // loop through the countries
        std::cout << std::setw(20) << std::left << country.name;
        bool first_line {true};

        for(auto city : country.cities) {       // loop through the cities for each country
            if (first_line) {
                first_line = false;
            } else {
                std::cout << std::setw(20) << ' ';
            }
            std::cout << std::setw(20) << std::left << city.name 
                << std::setw(15) << std::right << city.population 
                << std::setw(15) << std::right << city.cost 
                << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}