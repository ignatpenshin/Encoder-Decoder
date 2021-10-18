#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Codec
{
public:
    vector<float> encoding(int);
    vector<int> decoding(vector<float>);
    int* values_to_arry(int, int*, int);
    int number_length(int);
private:
    int size;
    int arrSize;
    // vector<int> dec_array;
    // vector<float> copy_array;
};


