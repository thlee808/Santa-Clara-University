// Starter file for Question 2 or HW7, due Wed 2/26 before class
// Travis Lee

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

const string INFILE = "records.txt";

class passwordAndStudent
{
public:
  passwordAndStudent(string nameP, string passwordP, double gpaP) : name_(nameP), password_(passwordP), gpa_(gpaP) {}
  string getPassword() {return password_;}
  string getName() {return name_;}
  double getGPA() {return gpa_;}
private:
  string password_;
  string name_;
  double gpa_;
};
int main()
{
  ifstream inFile;
  inFile.open("records.txt");
  if (inFile.fail())
  {
    cout << "Input file failed to open" << endl;
    return 1;
  }

  //map<string, string> database;
  map<string, passwordAndStudent> database;
  double gpa;
  string name, password, id;
  while (inFile >> name >> id >> password >> gpa)
  {
    passwordAndStudent student(name, password, gpa);
    database.insert({id, student});
  }

  inFile.close();

  string key, passwordInput;
  cout << "Enter an ID number (enter 0 to quit): ";
  cin >> key;
  while (key != "0")
  {
    cout << "Enter password: ";
    cin >> passwordInput;
    for (auto e : database)
    {
      if (key == e.first)
      {
        if (passwordInput == e.second.getPassword())
        {
          cout << "Name: " << e.second.getName() << endl;
          cout << "GPA: " << e.second.getGPA() << endl;
        }
        else
        {
          cout << "That was the wrong password." << endl;
        }
      }
    }
    cout << "Enter an ID number (enter 0 to quit): ";
    cin >> key;
  }
  cout << "Goodbye!" << endl;
  return 0;
}
