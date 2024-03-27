#include <iostream>

using namespace std;

class GroceryCounter
{
    private:
        int countDig, overflows, newMaxNum;

    public:
        GroceryCounter(int startValue, int newMax)
        {
            newMaxNum = newMax;

                // if(startValue >= 0 && startValue <= newMax)
                // {
                //     countDig = startValue;
                //     overflows = 0;
                // }
                
                // else
                // {
                //     cout << "Enter a value between 0 and max:  " << endl;
                //     cin >> startValue;
                // }

            while (startValue < 0 || startValue > newMax)
            {
                cout << "Enter a value between 0 and max:  " << endl;
                cin >> startValue;
            }

            countDig = startValue;
            overflows = 0;

        }

    void tens()
    {
        countDig = (countDig + 1000) % (newMaxNum +1);
        if (countDig < 1000)
        {
            overflows++;
        }
    }

    void ones()
    {
        countDig = (countDig + 100) % (newMaxNum +1);
        if (countDig < 100)
        {
            overflows++;
        }
    }

    void tenths()
    {
        countDig = (countDig + 10) % (newMaxNum +1);
        if (countDig < 10)
        {
            overflows++;
        }
    }

    void hundredths()
    {
        countDig = (countDig + 1) % (newMaxNum +1);
        if (countDig == 0)
        {
            overflows++;
        }
    }

    int number_of_overflows() const
    {
        return overflows;
    }

    void clear()
    {
        countDig = 0;
        overflows = 0;
    }

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

    
}; 


int main()
{
    int startValue, newMax;

    cout << "Enter a max value for the counter: ";
    cin >> newMax;

    cout << "Enter a starting value: ";
    cin >> startValue;
    
    GroceryCounter counter(startValue, newMax);

    counter.tens();
    counter.tens();
    counter.hundredths();

    cout << counter.total() << endl; // This would print out $20.01
    cout << counter.number_of_overflows() << endl; // This would print out 0

    for(int i = 0; i < 35; i++) {
    counter.ones();
    }

    cout << counter.total() << endl; // This would print out $55.01
    cout << counter.number_of_overflows() << endl; // This would print out 0

    for(int i = 0; i < 100; i++) {
    counter.ones();
    }

    cout << counter.total() << endl; // This would print out $55.02
    cout << counter.number_of_overflows() << endl; // This would print out 1

    counter.clear();

    cout << counter.total() << endl; // This would print out $0.00
    cout << counter.number_of_overflows() << endl; // This would print out 0
}
