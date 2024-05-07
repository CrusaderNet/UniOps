#include<iostream>
#include<set>
using namespace std;
//************************************************************
int main()
{
set <int> numbers;
set <int>::iterator it;
numbers.insert(1);
numbers.insert(1);
numbers.insert(1);
numbers.insert(2);
numbers.insert(2);
numbers.insert(2);
numbers.insert(3);
numbers.insert(3);
numbers.insert(3);
numbers.insert(4);
numbers.insert(4);
numbers.insert(4);
for (it = numbers.begin(); it != numbers.end(); it++)
cout << *it << endl;
cout << "**********************************************" << endl;
it--;
numbers.erase(it);
for (it = numbers.begin(); it != numbers.end(); it++)
cout << *it << endl;
cout << "**********************************************" << endl;
numbers.erase(2);
for (it = numbers.begin(); it != numbers.end(); it++)
cout << *it << endl;
cout << "**********************************************" << endl;
return 0;
}