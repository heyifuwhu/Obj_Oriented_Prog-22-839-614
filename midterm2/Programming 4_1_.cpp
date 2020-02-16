# include <iostream>
using namespace std;

int main()
{
	double myArray[10] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.2 };
	size_t size = sizeof(myArray) / sizeof(myArray[0]);

	double mean{ 0 };
	for (unsigned int i{ 0 }; i < size; i++)
	{
		mean += myArray[i];
		cout << "Element " << i << " is: " << myArray[i] << endl;
	}

	double squaredSum{ 0 };
	for (unsigned int i{ 0 }; i < size; i++)
	{
		double diff = myArray[i] - mean;
		squaredSum += diff * diff;
		cout << "Element " << i << " is: " << myArray[i] << endl;
	}

	double std{ sqrt(squaredSum / (size - 1)) };
	cout << "The standard deviation is: " << std << endl;

	system("pause");
}