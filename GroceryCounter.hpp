#include <iostream>

class GroceryCounter
{
    private:
        int tens;
        int ones;
        int tenths;
        int hundredths;
        int overflow;

    public:
        GroceryCounter();
        int ten();
        int one();
        int tenth();
        int hundredth();
        int number_of_overflows();
        void clear();
        void total();
};
