# include <iostream>
using namespace std;

void reverse(int intArray[], size_t size)
{
	for (unsigned int i{ 0 }, j{ size - 1 }; i < j; i++, j--)
	{
		int temp = intArray[i];
		intArray[i] = intArray[j];
		intArray[j] = temp;
	}
}

void printArray(int intArray[], size_t size)
{
	for (unsigned int i{ 0 }; i < size; i++)
	{
		cout << "Element " << i << " is: " << intArray[i] << endl;
	}
}

int main()
{
	int myArray[6] = { 1,2,3,4,5,6 };
	size_t size = sizeof(myArray) / sizeof(myArray[0]);

	cout << "Array before reversion is:" << endl;
	printArray(myArray,size);

	reverse(myArray,size);
	cout << "\nArray after reversion is:" << endl;
	printArray(myArray,size);

	system("pause");
}