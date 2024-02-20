#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){

char output;
unsigned int i = 0;

unsigned char test[37] = {0x9c,
0x96,
0xbd,
0xaf,
0x93,
0xc3,
0x94,
0x60,
0xa2,
0xd1,
0xc2,
0xcf,
0x9c,
0xa3,
0xa6,
0x68,
0x94,
0xc1,
0xd7,
0xac,
0x96,
0x93,
0x93,
0xd6,
0xa8,
0x9f,
0xd2,
0x94,
0xa7,
0xd6,
0x8f,
0xa0,
0xa3,
0xa1,
0xa3,
0x56,
0x9e};

char input[4] = {'9', 'c', '9', '6'};

/*string local_38[37] = {"9c",
"96",
"bd",
"af",
"93",
"c3",
"94",
"60",
"a2",
"d1",
"c2",
"cf",
"9c",
"a3",
"a6",
"68",
"94",
"c1",
"d7",
"ac",
"96",
"93",
"93",
"d6",
"a8",
"9f",
"d2",
"94",
"a7",
"d6",
"8f",
"a0",
"a3",
"a1",
"a3",
"56",
"9e"};*/

  while( true ) {
    if (36 < i) {
      puts("The window opens to allow you passage...");
      return 0;
    }
    output = input[(int)(i + 1)] + input[(int)i];
    cout << output << endl;
    if (output != test[(int)i]) break;
    i = i + 1;
  }
    puts("The window slams shut...");
  return -1;

}