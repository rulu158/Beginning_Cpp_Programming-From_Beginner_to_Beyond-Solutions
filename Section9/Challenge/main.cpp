#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> numbers;

	char option{};
	do {
		cout << endl;
		cout << "=================================" << endl;
		cout << "P - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "O - Occurrences of a number in the list" << endl;
		cout << "Q - Quit" << endl;
		cout << "=================================" << endl;

		cout << "\nEnter your choice: ";
		cin >> option;
		cout << endl;

		switch (option) {
		case 'P':
		case 'p':
			if (numbers.size() == 0) {
				cout << "[] - the list is empty" << endl;
			} else {
				cout << "[ ";
				for (auto num: numbers) {
					cout << num << " ";
				}
				cout << "]" << endl;
			}
			break;
		case 'A':
		case 'a':
		{
			int temp_num{};

			cout << "Add an integer to the list: ";
			cin >> temp_num;

			numbers.push_back(temp_num);

			cout << temp_num << " added" << endl;

			break;
		}
		case 'M':
		case 'm':
		{
			if (numbers.size() == 0) {
				cout << "Unable to calculate the mean - no data" << endl;
				continue;
			}

			double mean{};
			for (auto num : numbers) {
				mean += num;
			}

			mean /= numbers.size();

			cout << "The mean of the list is " << mean << endl;

			break;
		}
		case 'S':
		case 's':
		{
			if (numbers.size() == 0) {
				cout << "Unable to determine the smallest number - list is empty" << endl;
				continue;
			}

			int smallest_num {numbers.at(0)};
			for (auto num : numbers) {
				if (num < smallest_num) {
					smallest_num = num;
				}
			}

			cout << "The smallest number is " << smallest_num << endl;

			break;
		}
		case 'L':
		case 'l':
		{
			if (numbers.size() == 0) {
				cout << "Unable to determine the largest number - list is empty" << endl;
				continue;
			}

			int largest_num {numbers.at(0)};
			for (auto num : numbers) {
				if (num > largest_num) {
					largest_num = num;
				}
			}

			cout << "The largest number is " << largest_num << endl;

			break;
		}
		case 'O':
		case 'o':
		{
			if (numbers.size() == 0) {
				cout << "Unable find the ocurrences of any number - list is empty" << endl;
				continue;
			}

			int selected_num{};
			
			cout << "Select a number to look for: ";
			cin >> selected_num;

			int occurrences{};
			for (auto num : numbers) {
				if (num == selected_num) {
					++occurrences;
				}
			}

			if (occurrences > 0) {
				cout << "The number " << selected_num << " appears " << occurrences
					<< " time(s) in the list" << endl;
			} else {
				cout << "The number " << selected_num << " is not in the list" << endl;
			}

			break;
		}
		case 'Q':
		case 'q':
			cout << "Goodbye" << endl;
			break;
		default:
			cout << "Illegal option" << endl;
		}
	} while (option != 'Q' && option != 'q');

	cout << endl;
	return 0;
}
