#include <iostream>
#include <cstring>
using namespace std;


class Item{
    private:
        string name;
        int price;
        int level;
    public:
        Item(string name_init = "Nothing", int price_init = 0, int level_init = 0);
        ~Item();
};