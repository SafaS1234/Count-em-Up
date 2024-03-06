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
    calls = 0;
}

int GroceryCounter::ten()
{
    tens = (tens + 1000) % 10000;
    
    if(tens > 9)
    {
        overflow+1;
        //tens = 0;
    }

    return tens, overflow;
}

int GroceryCounter::one()
{
    ones = (ones + 100) % 10000;

    if(ones > 9)
    {
        overflow+1;
        ones = 0;
        tens+=1;
    }

    return ones, overflow;   
}

int GroceryCounter::tenth()
{
    tenths = (tenths + 10) % 10000;

    if(tenths > 9)
    {
        overflow+1;
        tenths = 0;
        ones+=1;
    }

    return tenths, overflow;
}

int GroceryCounter::hundredth()
{
    hundredths = (hundredths + 1) % 10000;

    if(hundredths > 9)
    {
        overflow+1;
        hundredths = 0;
        tenths+=1;
    }

    return hundredths, overflow;    
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

    counter.clear();

    //case #2
    for(int i = 0; i < 35; i++) 
    {
        counter.one();
    }

    counter.total(); // This would print out $55.01
    cout << counter.number_of_overflows() << endl; //This would print 0

    counter.clear();

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

    counter.clear();


}
