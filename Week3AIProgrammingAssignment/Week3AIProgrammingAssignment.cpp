

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Student {
public:
    string firstName;
    string lastName;

    int grade;

};

int main()
{

    string studentLine;

    ifstream studentFile("example.txt");

    vector<Student> students;

    int whitespace;
    int total = 0;
    int highest = 0;


    if (studentFile.is_open()) {
        while (getline(studentFile, studentLine)) {
            Student student;

            whitespace = studentLine.find(" ");

            student.firstName = studentLine.substr(0, whitespace);

            studentLine.erase(0, whitespace + 1);

            whitespace = studentLine.find(" ");

            student.lastName = studentLine.substr(0, whitespace);

            studentLine.erase(0, whitespace + 1);

            student.grade = stoi(studentLine);

            total += student.grade;

            students.push_back(student);


            studentLine = " ";

        }
    }
    else {
        cout << "unable to open file \n";
    }

    for (int j = 0; j < students.size(); j++) {

        for (int i = 0;  i < students.size(); i++) {


            if ((students[j].grade > students[i].grade) || (students[j].grade == students[i].grade )) {
                highest = students[j].grade;
            }
            else if (students[i].grade > highest) {
                highest = students[i].grade;
                
            }


        }

        for (int d = 0; d < students.size(); d++) {

            if (students[d].grade == highest) {
                cout << students[d].firstName << " " << students[d].lastName << ": " << students[d].grade << endl;
                students.erase(students.begin() + d);
                j--;
            }
        }

        highest = 0;
    }
    cout << endl;
    cout << "Average: " << total / 6;

}


