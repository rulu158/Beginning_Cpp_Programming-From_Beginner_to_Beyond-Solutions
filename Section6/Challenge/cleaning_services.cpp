#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
	const double price_per_small_room {25};
	const double price_per_large_room {35};
	const double tax_rate {0.06};
	const int number_of_days {30};

	cout << "Please, introduce how many small rooms you need: ";
	int small_rooms;
	cin >> small_rooms;

	cout << "Please, introduce how many large rooms you need: ";
	int large_rooms;
	cin >> large_rooms;

	double price_small_rooms {small_rooms * price_per_small_room};
	double price_large_rooms {large_rooms * price_per_large_room};
	double cost {price_small_rooms + price_large_rooms};
	double tax {cost * tax_rate};
	double  estimated_price {cost + tax};

	cout << "Estimate for Frank's carpet cleaning service:" << endl;

	cout << "Number of small rooms: " << small_rooms << endl;
	cout << "Number of large rooms: " << large_rooms << endl;
	
	cout << "Price per small room: $" << price_per_small_room << endl;
	cout << "Price per large room: $" << price_per_large_room << endl;

	cout << "Cost: $" << cost << endl;
	cout << "Tax: $" << tax << endl;

	cout << "=======================================================" << endl;

	cout << "Total estimate: $" << estimated_price << endl;
	cout << "This estimate is valid for " << number_of_days << " days" << endl;

	return 0;
}
