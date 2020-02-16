# include<iostream>
# include<cmath>
# include<iomanip>
using namespace std;

int main()
{
	cout << "Please enter a number between 1 and 10:" << endl;
	int n;
	cin >> n;
	while (n < 1 || n > 10)
	{
		cout << "The number should be between 1 and 10. Please enter again:" << endl;
		cin >> n;
	}
	for (unsigned int i{ 1 }; i <= n; i++)
	{
		cout << setw(5) << left << i << setw(5) << pow(i, 2) << setw(5) << pow(i, 3) << endl;
	}
	system("pause");
}