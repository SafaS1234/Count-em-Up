#include "GroceryCounter.hpp"
#include <iostream>

using namespace std;

GroceryCounter::GroceryCounter()
{
    tens = 0;
    ones = 0;
    tenths = 0;
    hundreths = 0;
    overflow = 0;
}

int GroceryCounter::ten()
{

}

int GroceryCounter::one()
{
    
}

int GroceryCounter::tenth()
{

}

int GroceryCounter::hundredth()
{
    
}

void GroceryCounter::total()
{
    if (tens >=1)
    {
        cout << "$" << tens << ones << "." << tenths << hundreths <<endl;
    }

    else
    {
        cout << "$" << ones << "." << tenths << hundreths <<endl;
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
    hundreths = 0;
    overflow = 0;
}
