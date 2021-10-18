#include "source/help.h"

using namespace std;

int main()
{
    int number;
    cin >> number;

    Codec num1;
    vector<int> x = num1.decoding(num1.encoding(number));

    // cout << x[0] << endl;
    
    return 0;
}