#include <string>
#include <vector>
#include <fstream>
using namespace std;

class myLink
{
	struct myNode
	{
		string value;
		myNode* next;
	};
	myNode* firstNode;
	myNode* lastNode;
	int siz;
public:
	myLink();
	void addOn(string);
  void popLast();
  void print(ostream&);
	vector<string> oneSkipTwoGrams();
  vector<string> oneSkipThreeGrams();
  vector<string> twoSkipTwoGrams();
	int size() const { return siz; }
};

myLink::myLink()
{
	firstNode = NULL;
	lastNode = NULL;
	siz = 0;
}
void myLink::addOn(string input)
{
	myNode* tempNode = new myNode;
	tempNode->value = input;
	tempNode->next = NULL;
	if (lastNode)
		lastNode->next = tempNode;
	else
		firstNode = tempNode;
	lastNode = tempNode;
	siz++;
}

void myLink::popLast()
{
  myNode* temp = firstNode;
  myNode* prev;
	while (temp != lastNode)
	{
		prev = temp;
		temp = temp->next;
	}
  delete temp;
  prev->next = NULL;
  --siz;
	if (siz == 0) lastNode = NULL;
}

void myLink::print(ostream& out)
{
  myNode* p = firstNode;
  while(p)
	{
    out << p->value << " ";
		p = p->next;
	}
  out << endl;
}

vector<string> myLink::oneSkipTwoGrams()
{
  //cout <<"In Function... " << endl;
  vector<string> myReturn;
  myNode* gram = firstNode;
  if(gram->next != NULL && gram->next->next != NULL)
  {
    //cout << "In loop, skipTwo shud be defined." << endl;
    myNode* skipTwo = gram->next->next;
    while(skipTwo->next != NULL)
    {
      string input = gram->value;
      input += " " + skipTwo->value;
      //update pointers, put into vector
      gram = gram ->next;
      skipTwo = skipTwo->next;
      myReturn.push_back(input);
    }
    //puts last set into vector
    string input = gram->value;
    input += " " + skipTwo->value;
    myReturn.push_back(input);
  }
  return myReturn;
}

vector<string> myLink::oneSkipThreeGrams()
{
  //cout <<"In Function... " << endl;
  vector<string> myReturn;
  myNode* gram = firstNode;
  if(gram->next != NULL && gram->next->next != NULL && gram->next->next->next != NULL && gram->next->next->next->next != NULL)
  {
    //cout << "In loop, skipTwo shud be defined." << endl;
    myNode* skipTwo = gram->next->next;
    myNode* skipTwoMore = skipTwo->next->next;
    while(skipTwoMore->next != NULL)
    {
      string input = gram->value;
      input += " " + skipTwo->value + " " + skipTwoMore->value;
      //update pointers, put into vector
      gram = gram ->next;
      skipTwo = skipTwo->next;
      skipTwoMore = skipTwo->next->next;
      myReturn.push_back(input);
    }
    //puts last set into vector
    string input = gram->value;
    input += " " + skipTwo->value + " " + skipTwoMore->value;
    myReturn.push_back(input);
  }
  return myReturn;
}

vector<string> myLink::twoSkipTwoGrams()
{
  vector<string> myReturn;
  myNode* gram = firstNode;
  if(gram->next != NULL && gram->next->next != NULL && gram->next->next->next != NULL)
  {
    myNode* skipTwo = gram->next->next->next; //actually skip three, but its ok
    while(skipTwo->next != NULL)
    {
      string input = gram->value;
      input += " " + skipTwo->value;
      //update pointers, put into vector
      gram = gram ->next;
      skipTwo = skipTwo->next;
      myReturn.push_back(input);
    }
    //puts last set into vector
    string input = gram->value;
    input += " " + skipTwo->value;
    myReturn.push_back(input);
  }
  return myReturn;
}
