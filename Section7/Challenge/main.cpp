#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> vector1;
	vector <int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);

	long unsigned i;
	for (i = 0; i < vector1.size(); i++) {
		cout << "vector1[" << i << "]: " << vector1.at(i) << endl;
	}
	cout << "size of vector1: " << vector1.size() << endl;

	cout << endl;

	vector2.push_back(100);
	vector2.push_back(200);

	for (i = 0; i < vector2.size(); i++) {
		cout << "vector2[" << i << "]: " << vector2.at(i) << endl;
	}
	cout << "size of vector2: " << vector2.size() << endl;

	cout << endl;
	
	vector <vector<int>> vector_2d;

	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	for (i = 0; i < vector_2d.size(); i++) {
		long unsigned j;
		for (j = 0; j < vector_2d.at(i).size(); j++) {
			cout << "vector_2d.at[" << i << "][" << j << "]: " << vector_2d.at(i).at(j) << endl;
		}	
	}
	cout << "size of vector_2d: " << vector_2d.size() << endl;

	cout << endl << "We change vector1[0] to 1000." << endl << endl;

	vector1.at(0) = 1000;

	for (i = 0; i < vector_2d.size(); i++) {
		long unsigned j;
		for (j = 0; j < vector_2d.at(i).size(); j++) {
			cout << "vector_2d.at[" << i << "][" << j << "]: " << vector_2d.at(i).at(j) << endl;
		}	
	}
	cout << "size of vector_2d: " << vector_2d.size() << endl;

	cout << endl;

	for (i = 0; i < vector1.size(); i++) {
		cout << "vector1[" << i << "]: " << vector1.at(i) << endl;
	}
	cout << "size of vector1: " << vector1.size() << endl;

	return 0;
}
