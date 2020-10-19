#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
        vector<int> elements;

  	public:
        int maximumDifference;

  	Difference(vector <int> a)
  	{
        for(int i=0;i<a.size();i++)
            elements.push_back(a[i]);
  	}

    int minimum = 100,maximum = 0;

  	//Or use a faster sorting algorithma and comparing the first and last element of the sorted array

  	void computeDifference()
  	{
        for(int i=0;i<elements.size();i++)
        {
            maximum = max(maximum, elements[i]);
            minimum = min(minimum,elements[i]);
        }
        maximumDifference = maximum - minimum;
  	}

};
int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}
