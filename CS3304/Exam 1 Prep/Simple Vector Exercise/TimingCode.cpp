#include <iostream>
#include <time.h>//for creating clock_t objects

using namespace std;

void main()
{
	clock_t begin, end;
	double elapsed_seconds;

	begin = clock();
	//CODE TO TIME ->
	for (unsigned int i = 0; i < 100000000; i++)
	{

	}


	end = clock();

	elapsed_seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;


}