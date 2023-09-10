// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Student {
    string name;
    string responses;
    int grade;
public:
    Student(string name, string responses) : name{name}, responses{responses} {}
    string get_name() const {
        return name;
    }
    int get_grade() const {
        return grade;
    }
    void set_grade(string correct_answers) {
        grade = 0;
        for (int i {0}; i < correct_answers.length(); i++) {
            if (correct_answers[i] == responses[i]) {
                grade += 1;
            }
        }
    }
};

int main() {
    ifstream input_file;
    input_file.open("responses.txt");
    if (!input_file) {
        cerr << "error opening the file" << endl;
        return 1;
    }

    string correct_answers;
    input_file >> correct_answers;   // read first line for correct grades

    vector<unique_ptr<Student>> students;
    while (!input_file.eof()) {
        string name, responses;
        input_file >> name >> responses;
        students.push_back(make_unique<Student>(name, responses));
        students.back()->set_grade(correct_answers);
    }

    input_file.close();

    float average {0};
    for (const auto &student : students) {
        average += student->get_grade();
    }
    average /= students.size();

    cout << setw(40) << left << "Student"
            << setw(10) << right << "Score"
            << endl;

    cout << setfill('-');
    cout << setw(50) << '-' << endl;
    cout << setfill(' ');

    for (const auto &student : students) {
        cout << setw(40) << left << student->get_name()
                << setw(10) << right << student->get_grade()
                << endl;
    }

    cout << setfill('-');
    cout << setw(50) << '-' << endl;
    cout << setfill(' ');

    cout << setw(40) << left << "Average score"
            << setw(10) << right << average
            << endl;

    return 0;
}

