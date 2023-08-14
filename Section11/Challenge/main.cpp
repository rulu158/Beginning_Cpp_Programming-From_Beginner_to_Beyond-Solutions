#include <iostream>
#include <vector>

using namespace std;

void print_menu();
void print_numbers(const vector<int> &numbers);
void add_a_number(vector<int> &numbers);
void display_mean(const vector<int> &numbers);
void display_smallest(const vector<int> &numbers);
void display_largest(const vector<int> &numbers);
void display_occurences_of_a_number(const vector <int> &numbers);

int main() {

	vector<int> numbers;

	char option{};
	do {
		print_menu();

		cout << "\nEnter your choice: ";
		cin >> option;

		cout << endl;

		switch (option) {
		case 'P':
		case 'p':
			print_numbers(numbers);
			break;
		case 'A':
		case 'a':
		{
			add_a_number(numbers);
			break;
		}
		case 'M':
		case 'm':
		{
			display_mean(numbers);
			break;
		}
		case 'S':
		case 's':
		{
			display_smallest(numbers);
			break;
		}
		case 'L':
		case 'l':
		{
			display_largest(numbers);
			break;
		}
		case 'O':
		case 'o':
		{
			display_occurences_of_a_number(numbers);
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


void print_menu() {
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
}

void print_numbers(const vector<int> &numbers) {
	if (numbers.size() == 0) {
			cout << "[] - the list is empty" << endl;
	} else {
		cout << "[ ";
		for (auto num: numbers) {
			cout << num << " ";
		}
		cout << "]" << endl;
	}
}

void add_a_number(vector<int> &numbers) {
	int temp_num{};

	cout << "Add an integer to the list: ";
	cin >> temp_num;

	numbers.push_back(temp_num);

	cout << temp_num << " added" << endl;
}

void display_mean(const vector<int> &numbers) {
	if (numbers.size() == 0) {
		cout << "Unable to calculate the mean - no data" << endl;
		return;
	}

	double mean{};
	for (auto num : numbers) {
		mean += num;
	}

	mean /= numbers.size();

	cout << "The mean of the list is " << mean << endl;
}

void display_smallest(const vector<int> &numbers) {
	if (numbers.size() == 0) {
		cout << "Unable to determine the smallest number - list is empty" << endl;
		return;
	}

	int smallest_num {numbers.at(0)};
	for (auto num : numbers) {
		if (num < smallest_num) {
			smallest_num = num;
		}
	}

	cout << "The smallest number is " << smallest_num << endl;
}

void display_largest(const vector<int> &numbers) {
	if (numbers.size() == 0) {
		cout << "Unable to determine the largest number - list is empty" << endl;
		return;
	}

	int largest_num {numbers.at(0)};
	for (auto num : numbers) {
		if (num > largest_num) {
			largest_num = num;
		}
	}

	cout << "The largest number is " << largest_num << endl;
}

void display_occurences_of_a_number(const vector <int> &numbers) {
	if (numbers.size() == 0) {
		cout << "Unable find the ocurrences of any number - list is empty" << endl;
		return;
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
}