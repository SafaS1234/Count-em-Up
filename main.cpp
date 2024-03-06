#include <iostream>
#include <string>

using namespace std;

class GroceryCounter
{
    private:
        int countDig, overflows;

    public:
        GroceryCounter()
        {
            countDig = 0;
            overflows = 0;
        }

    void tens()
    {
        countDig = (countDig + 1000) % 10000;
    }

    void ones()
    {
        countDig = (countDig + 100) % 10000;
    }

    void tenths()
    {
        countDig = (countDig + 10) % 10000;
    }

    void hundreths()
    {
        countDig = (countDig + 1) % 10000;
    }

    void clear()
    {
        countDig = 0;
        overflows = 0;
    }

    //return string
    string total() const 
    {
        string message;
        int dollar = countDig/100;
        int cent = countDig % 100;

        message = "$" + to_string(dollar) + ".";

        if (cent < 10)
        {
            message += "0";
        }

        message += to_string(cent);

        return message;
    }

    int number_of_overflows() const
    {
        return overflows;
    }
};


int main()
{
    GroceryCounter counter;

    //case #1
    counter.tens();
    counter.tens();
    counter.hundreths();

    cout << counter.total() << endl; // This would print out $20.01
    cout << counter.number_of_overflows() << endl; //This would print 0

    
    for(int i = 0; i < 35; i++) 
    {
        counter.ones();
    }

    cout << counter.total() << endl; // This would print out $55.01
    cout << counter.number_of_overflows() << endl; //This would print 0

    for(int i = 0; i < 100; i++) 
    {
        counter.ones();
    }

    cout << counter.total() << endl; // This would print out $55.02
    cout << counter.number_of_overflows() << endl; //This would print 1

    counter.clear();

    cout << counter.total() << endl; // This would print out $0.00
    cout << counter.number_of_overflows() << endl; //This would print 0
}
