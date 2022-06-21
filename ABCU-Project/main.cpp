#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include "Display.cpp"
#include "Console.cpp"

using namespace std;

struct Course {
    string courseNumber; // unique identifier
    string name;
    vector<string> prerequisites;

    Course() {
        courseNumber = "300";
        name = "CS";
        prerequisites = {};
    }
};
class Courses {
  // Internal structure for list entries, courses
  private:
    struct Node {
        Course course;
        Node *next;

        // default constructor
        Node() {
            next = nullptr;
        }

        // initialize with a Course
        Node(Course aCourse) {
            course = aCourse;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size = 0;

  public:
  Courses();
  virtual ~Courses();
  void Append(Course course);
  void Prepend(Course course);
  void PrintCourses();
  void Remove(string courseNumber);
  Course Search(string courseNumber);
  int Size();

};

/**
 * Default constructor
 */
Courses::Courses() {
    //set head and tail equal to null
    head = nullptr;
    tail = nullptr;
}

/**
 * Destructor
 */
Courses::~Courses() {
    // start at the head
    Node* current = head;
    Node* temp;

    // loop over each node, detach from list then delete
    while (current != nullptr) {
        temp = current; // hang on to current node
        current = current->next; // make current the next node
        delete temp; // delete the orphan node
    }
}

/**
 * Append a new course to the end of the list
 */
void Courses::Append(Course course) {
    //Create new node
    Node* newNode = new Node(course);
    //if there is nothing at the head...
    if (head == nullptr) {
      // new node becomes the head and the tail
      head = newNode;
      tail = newNode;
    } else {
      //else 
          // make current tail node point to the new node
          tail->next = newNode;
          // and tail becomes the new node
          tail = newNode;
      //increase size count
      size++;
    }
}

/**
 * Simple output of all courses in the list
 */
void Courses::PrintCourses() {
    // start at the head
    Node* current = head;
    // while loop over each node looking for a match
    while (current != nullptr) {
      //output current courseNumber and course name
      std::cout << current->course.courseNumber << ", " << current->course.name << endl;
      //set current equal to next
      current = current->next;
    }
}

/**
 * Search for the specified courseNumber
 *
 * @param courseNumber The courseNumber to search for
 */
Course Courses::Search(string courseNumber) {
    // start at the head of the list
    Node* current = head;
    // keep searching until end reached with while loop (next != nullptr)
    while (current != nullptr) {
      // if the current node matches, return it
      if (current->course.courseNumber.compare(courseNumber) == 0) {
        return current->course;
      } else {
        // else current node is equal to next node
        current = current->next;
      }
    }
 
     //return course
     return current->course;
}

vector<string> splitString(string str, char delimiter) {
  // vector to store split words
  vector<string> result;
  // temp string to store the current word up to the delimiter
  string temp = "";
  for(int i = 0; i < str.size(); i++) {
    // If current character is NOT the delimiter
    if (str[i] != delimiter){
      // then append it to the temp string (current word)
      temp += str[i];
    } else {
      // else word is complete, push it to result vector
      result.push_back(temp);
      // start a new word
      temp = "";
    }
  }
  result.push_back(temp);

  return result;
}


/**
 * Display the course information
 *
 * @param course struct containing the course info
 */
void displayCourse(Course course) {
    cout << course.courseNumber << ", " << course.name << endl;
    if (course.prerequisites.size() > 0) {
      cout << "Prerequisites: ";
      for (int i = 0; i < course.prerequisites.size(); i++) {
        cout << course.prerequisites[i] << ", ";
      }
    }
    return;
}

/**
 * Load a file containing courses into a LinkedList
 *
 * @return a Courses linked list containing all the courses read
 */
void loadCourses(string file, Courses *courseList) {
    cout << "Loading file " << file << endl;

    fstream newfile;
    // open a file to perform write operation using file object
    newfile.open(file);
    // checking whether the file is open
    if(newfile.is_open()) {
      string line;
      // if not at end of file, continue reading numbers
      while (!newfile.eof()) {   
        Course course;
        vector<string> courseInfo;
        // read data from file object and put it into string.
        getline(newfile, line);

        // split string by commas
        courseInfo = splitString(line, ',');
        // assign course number to 0th index in vector
        course.courseNumber = courseInfo.at(0);
        // assign course name to 1st index in vector
        course.name = courseInfo.at(1);
        // if vector size is greater than 2 there are prerequisites
        if (courseInfo.size() > 2) {
          // loop over remaining indices after first 2
          for (int i = 2; i < courseInfo.size(); i++) {
            // push each index after 1 to the prerequisites vector
            course.prerequisites.push_back(courseInfo.at(i));
          }
        }
        // add this course to the end
        courseList->Append(course);
    }
    // close the file object
    newfile.close();
  }

}


int main() {

  // Instantiate Console class
	Console console;
  // Instantiate Display class
  Display display;
  // Instantiate Courses class
  Courses courseList;
  // Instantiate Course class
  Course course;

  // initialize option variable
	int option{ 0 };
  // initialize searchItem variable
	string searchItem{ "" };

  // main loop, loop while option doesn't equal 4
	while (option != 4) {
    // call displayMenu function
    display.displayMenu();
    // assign option with number from read number function
		option = console.readNumber();

    switch (option) {
      case 1:
        loadCourses("ABCU.txt", &courseList);
        cout << endl;
        break;
      case 2:
        cout << "Here is a sample schedule:" << endl;
        // print all courses
        courseList.PrintCourses();
        break;
      case 3:
        // assign searchItem with string read from user input
        searchItem = console.readString("What course do you want to know about? ");
        // search for searchItem user input by calling Search function on courseList
        course = courseList.Search(searchItem);
        // print selected course and course prerequisites
        displayCourse(course);
        break;
      case 4:
        cout << "Thank you for using the course planner!" << endl;
        return 0;
      default:
        cout << option << " is not a valid option." << endl;
				break;
    }
  }
}