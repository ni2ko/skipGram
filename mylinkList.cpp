class myLink
{
	struct myNode
	{
		int value;
		myNode* next;
	};
	myNode* firstNode;
	int siz;
public:
	myLink();
	void addOn(int);
  void popLast();
  void print(ostream&);
  void Reverse4(myNode*);
  void SortList();
  myNode sortlist(myNode*);
	int size() const { return siz; }
};
myLink::myLink()
{
	firstNode = NULL;
	siz = 0;
}
void myLink::addOn(int input)
{
  myNode* here = firstNode;
  myNode* temp = new myNode;
  temp->value = input;
	temp->next = NULL;
  if(firstNode == NULL)
  {
      firstNode->next = temp;
  }
  else
  {
    while(here != NULL)
      here = here->next;
    here->next = temp;
    siz++;
  }
}
void myLink::popLast()
{
  myNode* temp = firstNode;
  myNode* prev;
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
  delete temp;
  prev->next = NULL;
  --siz;
	if (siz == 0) 
  {
    firstNode = NULL;
  }
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
void myLink::Reverse4(myNode* ptr)
{
  myNode* reverse, tempo;
  tempo = firstNode;
  int count = 0, timer = 5;
  while(tempo != NULL)
  {
    reverse->value = tempo->value;
    reverse->next = tempo->next;
    count++;
    timer--;
  }
  reverse->next = NULL;
  count = (count  > 5) ? count - 5: 0;
  while(count)
  {
      ptr = ptr->next;
  }
  ptr->next = reverse;
}

myNode* myLink::sortlist(myNode* head)
{
   myNode* tempNode = NULL;
   myNode* tempHead = head;
  myNode* tempNext = head->next;

   while(tempNext!=NULL) 
   {
    if(tempHead->key > tempNext->key)
    {
      tempNode = tempHead;
      tempHead = tempNext;
      tempNode->next = tempNode->next->next;
      tempHead->next = tempNode;
      tempNext = tempHead->next;
    }
   else 
   {  
      tempHead = tempHead->next;
      tempNext = tempNext->next;
    }
  }
  return head;
}
