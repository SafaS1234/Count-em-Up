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

/*int GroceryCounter::ten()
{
    tens++;

    if(tens >= 10)
    {
        //overflow = (tens /10)/5;
        overflow++;
    }

    return tens;
}

int GroceryCounter::one()
{
    ones++;

    if(ones >= 10)
    {
        //overflow = (ones /10)/5;
        overflow++;
    }

    return ones;   
}

int GroceryCounter::tenth()
{
    tenths++;

    if(tenths >= 10)
    {
        //overflow = (tenths /10)/5;
        overflow++;
    }

    return tenths;
}

int GroceryCounter::hundredth()
{
    hundredths++;

    if(hundredths >= 10)
    {
        //overflow = (hundredths /10)/5;
        overflow++;
    }

    return hundredths;    
}
*/

int GroceryCounter::ten()
{
    tens++;

    if(tens >= 10)
    {
        tens = tens % 10;
        overflow++;
    }

    return tens;
}

int GroceryCounter::one()
{
    ones++;

    if(ones >= 10)
    {
        ones = ones % 10;
        overflow++;
    }

    return ones;   
}

int GroceryCounter::tenth()
{
    tenths++;

    if(tenths >= 10)
    {
        tenths = tenths % 10;
        overflow++;
    }

    return tenths;
}

int GroceryCounter::hundredth()
{
    hundredths++;

    if(hundredths >= 10)
    {
        hundredths = hundredths % 10;
        overflow++;
    }

    return hundredths;    
}


void GroceryCounter::total()
{
    
    if (tens >= 1)
    {
        cout << "$" << (tens*10) + ones << "." << tenths << hundredths <<endl;
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

int main ()
{
    GroceryCounter counter;
    counter.ten();
    counter.ten();
    counter.hundredth();

    counter.total(); // This would print out $20.01
    cout << counter.number_of_overflows() << endl; // This would print out 0

    for(int i = 0; i < 35; i++) {
    counter.one();
    }

    counter.total(); // This would print out $55.01
    cout << counter.number_of_overflows() << endl; // This would print out 0

    for(int i = 0; i < 100; i++) {
    counter.one();
    }

    counter.total(); // This would print out $55.02
    cout << counter.number_of_overflows() << endl; // This would print out 1

    counter.clear();

    counter.total(); // This would print out $0.00
    cout << counter.number_of_overflows() << endl; // This would print out 0
}
