//============================================================================
// Name        : ABCU.cpp
// Author      : Tran Duong Tran
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : project 2 ABCU in C++,
//============================================================================
#include <iostream>

#include <fstream>

#include <vector>

using namespace std;

//  This is necessary to help completely to write of structure course. 
// The structures struct Course is a way to group several related 
// variables into one place such as the courseNumber, string name, prerequisites.

struct Course {

	string courseNumber;

	string name;

	vector<string> prerequisites;

};

// In the program, this additional function modify to 
// divide the string to the list of strings on the delimiter.
// It is the neccessary function to seperate the string. 

vector<string> tokenize(string s, string del = " ")

{

	vector<string> stringArray;

	int start = 0;

	int end = s.find(del);

	while (end != -1) {


		stringArray.push_back(s.substr(start, end - start));

		start = end + del.size();

		end = s.find(del, start);

	}

	stringArray.push_back(s.substr(start, end - start));


	return stringArray;

}

// The purpose of this addition algorithm function is loading
// and processing the file and its purpose to store the information 
// into the list of courses

vector<Course> LoadDataStructure()

{

	// The purpose of the algorithms is to modify an object of iftsream
	// class with the purpose to open file abcu.txt

	ifstream fin("abcu.txt", ios::in);


	vector<Course> courses;


	string line;


	// The while condition will start a infinite loop

	while (1)

	{

		getline(fin, line);


		// If the file is reaching the end,
		// the it is important to break the loop

		if (line == "-1")

			break;


		Course course;


		// the program will run and insert the information from the token
		// and the token is separated by the commas

		vector<string> tokenizedInformation = tokenize(line, ",");


		// The program's purpose will store the information on the structure course

		course.courseNumber = tokenizedInformation[0];

		course.name = tokenizedInformation[1];


		// if there are having the prerequisites, then the program automatically
		// store them too

		for (int i = 2; i < tokenizedInformation.size(); i++)

		{

			course.prerequisites.push_back(tokenizedInformation[i]);

		}


		// The program will  return the appending the course into list of courses

		courses.push_back(course);


	}


	// Then, it is necessary to close the file

	fin.close();


	// return the list of courses

	return courses;


}

// The program's purpose is printing the course information of 
// the given course in proper format. 

void printCourse(Course course)

{

	string courseNumber = course.courseNumber;

	string name = course.name;

	vector<string> prerequisites = course.prerequisites;


	cout << "Course Number: " << courseNumber << endl;

	cout << "Course Name: " << name << endl;

	cout << "Prerequisites: ";

	for (int i = 0; i < prerequisites.size(); i++)

	{

		cout << prerequisites[i] << " ";

	}

	cout << "\n\n";


}

// The purpose of the printCourseList is printing the course information 
// of all courses in proper format

void printCourseList(vector<Course> courses)

{

	int n = courses.size();


	// It is neccessary the loop will use the bubble 
	// sort to sort the classes' list. This sorting algorithm
	// is comparing the pairs of elements and swapping the order

	for (int i = 0; i < n - 1; i++)

	{

		for (int j = 0; j < n - i - 1; j++)

		{

			if (courses[j].courseNumber > courses[j + 1].courseNumber)

			{

				swap(courses[j + 1], courses[j]);

			}

		}

	}


	// The method of traversing is the traversing list of courses will print 
	//all courses information

	for (int i = 0; i < n; i++)

	{


		printCourse(courses[i]);


	}


}

// search the course for the user entered course number

void searchCourse(vector<Course> courses)

{

	int n = courses.size();

	string courseNumber;

	int f = 0;


	cout << "Enter courseNumber: ";

	cin >> courseNumber;


	for (int i = 0; i < n; i++)

	{

		// if course found then print it

		if (courses[i].courseNumber == courseNumber)

		{

			f = 1;

			printCourse(courses[i]);

			break;

		}

	}


	// if course with given course name not found then print error message

	if (f == 0)

	{

		cout << "Course with given course number not found\n";

	}

}

int main(int argc, char** argv)

{

	vector<Course> courses;


	// Printing menu

	cout << "1.Load Data Structure\n";

	cout << "2.Print Course List\n";

	cout << "3.Print Course\n";

	cout << "4.Exit\n";


	int ch;


	// Then it is important the algorithm in the program 
	// will automatically break when the user enter 4

	do {

		// And then the program will automatically determine and 
		// located the user to enter the choices such as option 1, option 2
		// option 3, option 4 to search course, print course, and load course
		// or exit.

		cout << "\nEnter your choice: ";

		cin >> ch;


		switch (ch)

		{

		case 1: courses = LoadDataStructure(); break;

		case 2: printCourseList(courses); break;

		case 3: searchCourse(courses); break;

		case 4: cout << "Exit\n"; break;


		default: cout << "Invalid Choice\n";

		}


	} while (ch != 4);



	return 0;

}
