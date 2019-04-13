#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

#include "linklist.h"

void printInMain(ostream& out, const vector<string>& thisVec)
{
  for(const auto value: thisVec)
    out << value << ", ";
    out << endl;
}

int main() 
{
  vector<myLink> linkedSentence;
  vector<string> inputFile;
  vector<string> gram12, gram13, gram22;

  ifstream infile;
  infile.open("quotes.txt");
  ofstream outfile1, outfile2, outfile3;
  outfile1.open("1skip2gram.txt");
  outfile2.open("1skip3gram.txt");
  outfile3.open("2skip2gram.txt");
  if(!infile || !outfile1 || !outfile2 || !outfile3)
    cout << "File error..." << endl;
  else
  {
    string vecString;
    myLink empty;
    while(infile)
    {
      getline(infile, vecString);
      inputFile.push_back(vecString);
      linkedSentence.push_back(empty);
    }
    //some wierd off by 1 error with file
    for(int i = 0; i < inputFile.size() - 1; i++)
    {
      string input = inputFile.at(i);
      stringstream testSS(input);
      string tempString;
      //parse sentence into vector of strings
      while(testSS)
      {
        testSS >> tempString;
        linkedSentence.at(i).addOn(tempString);
      }
        //random last word repeat
        linkedSentence.at(i).popLast(); 
        //use parsed linklist in vector, to create vector with skip-gram sequence
        gram12 = linkedSentence.at(i).oneSkipTwoGrams();
        gram13 = linkedSentence.at(i).oneSkipThreeGrams();
        gram22 = linkedSentence.at(i).twoSkipTwoGrams();
        printInMain(outfile1, gram12);
        printInMain(outfile2, gram13);
        printInMain(outfile3, gram22);
      }
  }
  outfile1.close();
  outfile2.close();
  outfile3.close();
  infile.close();
	return 0;
}
