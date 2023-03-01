// Starter file for Question 1 or HW7, due Wed 2/26 before class
// Travis Lee
//Hypothesis:
//I believe that Algorithm 3 will be the fastest, Algorithm 2 will be second, and
//Algorithim 1 will be last. Algorithim 1's input process iterates through the vector
//every time it inputs a word and its sort and output also iterate through the whole
//vector. This means Algorithim 1 has 3+ (plus is all the times it went through the
//vector, but the size of the vector is smaller than the size is at the end) laps
//through the end size of the vector. Algorithim 2 has 3 full laps through the
//vector and some additional time to check for outputing duplicates. Algorithm 3
//will only do 2 full laps through the data. If one more entry was added to the
//data set, the amount of time added to algorithm 3 < time added to algorithm 2
// < time added to algorithm 1.

//Analysis:
// Algorithm 1: 364.809 seconds
// Algorithm 2: 0.878632 seconds
// Algorithm 3: 0.935607 seconds
//Algorithm 1 was the slowest as expected, but I was surprised that algorithm 2
//was faster than algorithm 3. I think that it is because the time it takes for
//a set to check for a duplicate and insert the entry in order is greater than
//the time it takes for algorithm 2 to check as it outputs. Also, algorithm 2
//sorts the whole vector at once, while the set does it for every insert().

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
using namespace std::chrono; // for timing experiments

const int EXPERIMENT = 1; // change this as you test your algorithms (1-3)
const string INFILE = "don_quixote.txt"; //"don_quixote.txt"; // test with DQ
const string OUTFILE = "output.txt"; // don't change this!

void timedExperiment(string filename, int exp);
void readWithVector1(string filename);
void readWithVector2(string filename);
void readWithSet(string filname);

// starts a timed experiment based on default values or command line arguments
int main(int argc, char** argv) {
  if (argc<2) timedExperiment(INFILE,EXPERIMENT); // test according to constants
  else timedExperiment(argv[1],stoi(argv[2])); // or use command line arguments
  return 0;
}

// runs specified experiment on the specified filename and reports the time
void timedExperiment(string filename, int exp) {
  auto start = high_resolution_clock::now();
  switch (exp) {
    case 1: readWithVector1(filename); break;
    case 2: readWithVector2(filename); break;
    case 3: readWithSet(filename); break;
    default: cout << "Invalid experiment number specified\n"; return;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count()/1000000.0 << " seconds for alg " << exp <<
    " to process " << filename << endl;
}

// TODO: implement these experiments!

void readWithVector1(string filename)
{
  ifstream inFile;
  inFile.open(filename);
  if (inFile.fail())
  {
    cout << "Input file failed to open" << endl;
    return;
  }

  vector<string> v;
  string input;
  while (inFile >> input)
  {
    bool found = false;
    for (size_t i = 0; i < v.size(); i++)
    {
      if (input == v[i])
      {
        found = true;
      }
    }
    if (found == false)
    {
      v.push_back(input);
    }
  }
  inFile.close();

  sort(v.begin(), v.end());

  ofstream outFile;
  outFile.open(OUTFILE);
  if (outFile.fail())
  {
    cout << "Output file failed to open" << endl;
    return;
  }

  for (size_t i = 0; i < v.size(); i++)
  {
    outFile << v[i] << endl;
  }
  outFile.close();
  return;
}

void readWithVector2(string filename)
{
  ifstream inFile;
  inFile.open(filename);
  if (inFile.fail())
  {
    cout << "Input file failed to open" << endl;
    return;
  }

  vector<string> v;
  string input;
  while (inFile >> input)
  {
    v.push_back(input);
  }

  sort(v.begin(), v.end());

  ofstream outFile;
  outFile.open(OUTFILE);
  if (outFile.fail())
  {
    cout << "Output file failed to open" << endl;
    return;
  }

  outFile << v[0] << endl;

  bool found = false;
  for (size_t i = 1; i < v.size(); i++)
  {
    if (v[i] != v[i - 1])
    {
      outFile << v[i] << endl;
    }
  }
  return;
}

void readWithSet(string filename)
{
  ifstream inFile;
  inFile.open(filename);
  if (inFile.fail())
  {
    cout << "Input file failed to open" << endl;
    return;
  }

  set<string> s;
  string input;
  while (inFile >> input)
  {
    s.insert(input);
  }

  ofstream outFile;
  outFile.open(OUTFILE);
  if (outFile.fail())
  {
    cout << "Output file failed to open" << endl;
    return;
  }
}
