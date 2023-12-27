#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MedianFinder
{
public:
    vector <int> arr;
    
    void addNum(int num)
    {
        arr.push_back(num);
    }
    
    void findMedian()
    {
        if ((arr.size()) % 2 == 0)
        {
            cout << (arr[arr.size()/2] + arr[((arr.size())/2)-1])/2;
        }
        else
        {
            cout << arr[arr.size()/2];
        }
    }
};

int main()
{
    MedianFinder MF;
    MF.arr = {};
    
    int element;
    
    cout << "Enter elements. If you are done write down 000"<<endl;
    
    cin  >> element;
    MF. addNum(element);
    
    while (element != 000)
    {
        cin >> element;
        
        if (element != 000)
            MF.addNum(element);
        
    }

    
    MF.findMedian();
}
