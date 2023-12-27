#include <iostream>
#include <vector>

using namespace std;

int MAXProfit(vector <int> array);

int main()
{
	int N;
	cout << "How many sales there will be: ";
	cin >> N;

	vector <int> prices;

	cout << "Enter sales";
	int sales;

	for (int i = 0; i < N; i++)
	{
		cin >> sales;
		prices.push_back(sales);
	}

	cout << MAXProfit(prices);
}

int MAXProfit(vector <int> array)
{
	if (array.size() < 2)
		return 0;

	int maxProfit = 0;
	int min = array[0];

	for (int i = 1; i < array.size(); i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		else
		{
			if (array[i] - min > maxProfit)
				maxProfit = array[i] - min;
		}
	}
	return maxProfit;
}