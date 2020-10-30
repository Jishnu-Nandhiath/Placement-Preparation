#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int day_without_fine,month_without_fine,year_without_fine,day_with_fine,month_with_fine,year_with_fine;


    cin>>day_with_fine>>month_with_fine>>year_with_fine>>day_without_fine>>month_without_fine>>year_without_fine;

    int fine= 0;

    if(year_with_fine > year_without_fine)
    {
        fine += 10000;
    }
    else if(year_with_fine == year_without_fine)
    {
        if(month_with_fine > month_without_fine)
        {
            fine = (month_with_fine - month_without_fine) * 500;
        }
        else if(month_with_fine == month_without_fine && day_with_fine > day_without_fine)
            {
              fine = (day_with_fine - day_without_fine) *15;
            }
    }


    cout<<fine;

    return 0;
}
