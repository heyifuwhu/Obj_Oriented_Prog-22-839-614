# include <iostream>
# include <random>
using namespace std;

int main()
{
	// Seed with a real random value, if available
	random_device r;

	// Choose a random number between 1 and 6
	default_random_engine generator(r());
	uniform_int_distribution<int> distribution(1, 6);
	for (unsigned int i{ 0 }; i < 10; i++)
	{
		cout << distribution(generator) << endl;
	}
	system("pause");
}