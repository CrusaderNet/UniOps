//Modified from www.cplusplus.com
//The code demonstrates vector erase
#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  vector<int> numbers;

  // Push the 1st 10 numbers onto the vector
  for (int i=1; i<=10; i++) 
	  numbers.push_back(i);

  // erase the 6th element
  numbers.erase (numbers.begin()+5);

  // erase the first 3 elements:
  numbers.erase (numbers.begin(),numbers.begin()+3);

  cout << "numbers contains:";
  for (unsigned i=0; i<numbers.size(); ++i)
    cout << ' ' << numbers[i];
  cout<<endl;

  system("pause");
  return 0;
}
