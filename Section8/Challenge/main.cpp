/*
 * This Challenge is made with euros:
 * 1€
 * 0.50€
 * 0.20€
 * 0.10€
 * 0.05€
 * 0.02€
 * 0.01€
 */

#include <iostream>

using namespace std;

int main() {
	int cents {};

	cout << "Enter an amount in cents: ";
	cin >> cents;

	int coins {};
	int resting_cents {cents};

	coins = resting_cents / 100;
	resting_cents %= 100;
	cout << "1€: " << coins << endl;

	coins = resting_cents / 50;
	resting_cents %= 50;
	cout << "0.50€: " << coins << endl;

	coins = resting_cents / 20;
	resting_cents %= 20;
	cout << "0.20€: " << coins << endl;

	coins = resting_cents / 10;
	resting_cents %= 10;
	cout << "0.10€: " << coins << endl;

	coins = resting_cents / 5;
	resting_cents %= 5;
	cout << "0.05€: " << coins << endl;

	coins = resting_cents / 2;
	resting_cents %= 2;
	cout << "0.02€: " << coins << endl;

	coins = resting_cents / 1;
	resting_cents %= 1;
	cout << "0.01€: " << coins << endl;

	return 0;
}
