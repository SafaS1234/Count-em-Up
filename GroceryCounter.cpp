#include "GroceryCounter.hpp"
#include <iostream>

using namespace std;

GroceryCounter::GroceryCounter()
{
    tens = 0;
    ones = 0;
    tenths = 0;
    hundredths = 0;
    overflow = 0;
}

int GroceryCounter::ten()
{
    tens++;

    if(tens > 9)
    {
        overflow = 0;
        overflow++;
        tens = 0;
    }

    return tens;
}

int GroceryCounter::one()
{
    ones++;

    if(ones > 9)
    {
        overflow = 0;
        overflow++;
        ones = 0;
    }

    return ones;   
}

int GroceryCounter::tenth()
{
    tenths++;

    if(tenths > 9)
    {
        overflow = 0;
        overflow++;
        tenths = 0;
    }

    return tenths;
}

int GroceryCounter::hundredth()
{
    hundredths++;

    if(hundredths > 9)
    {
        overflow = 0;
        overflow++;
        hundredths = 0;
    }

    return hundredths;    
}

void GroceryCounter::total()
{
    if (tens >=1)
    {
        cout << "$" << tens << ones << "." << tenths << hundredths <<endl;
    }

    else
    {
        cout << "$" << ones << "." << tenths << hundredths <<endl;
    }
}

int GroceryCounter::number_of_overflows()
{
    return overflow;
}

void GroceryCounter::clear()
{
    tens = 0;
    ones = 0;
    tenths = 0;
    hundredths = 0;
    overflow = 0;
}

int main()
{
    GroceryCounter counter;

    //case #1
    counter.ten();
    counter.ten();
    counter.hundredth();

    counter.total(); // This would print out $20.01
    cout << counter.number_of_overflows() << endl; //This would print 0

    //case #2
    for(int i = 0; i < 35; i++) 
    {
        counter.one();
    }

    counter.total(); // This would print out $55.01
    cout << counter.number_of_overflows() << endl; //This would print 0

    //case #3
    for(int i = 0; i < 100; i++)  
    {
        counter.one();
    }

    counter.total(); // This would print out $55.02
    cout << counter.number_of_overflows() << endl; //This would print 1

    counter.clear();

    //case #4
    counter.total(); // This would print out $0.00
    cout << counter.number_of_overflows() << endl; //This would print 0
}
