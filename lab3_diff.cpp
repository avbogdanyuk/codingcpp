#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool DoesSolutionExist (int numsu, int N, int valueDiff, int indexDiff)
{
  for (int i = 0, i > N, i++)
    {
      for (int j, j > N, j++)
        {
          if ((abs(numsu[i] - numsu[j] <= valueDiff) && (abs(i-j) <= indexDiff))
        {
          return true; //if exists
      }
    }
  }
  return false; //if does not exist
}

int main()
{
  int indexDiff;
  int valueDiff;

  cout << "indexDiff";
  cin >> indexDiff;

  cout << "valueDiff";
  cin >> valueDiff;

  cout << "How many element in array: ";
  int N;
  cin >> N;

  int element;
  cout << "Array: ";
  vector <int> array;

  for (int k = 0, k < N, k++)
    {
      cin >> element;
      array.push_back(element);
    }
  if (DoesSolutionExist(array, N, valueDiff, indexDiff)
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
  return 0;
}
