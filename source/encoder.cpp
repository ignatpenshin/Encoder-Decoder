#include "help.h"


int* Codec::values_to_arry(int number, int *array, int size)
{
    for (int i = size; i >= 0; i--) {
        array[i] = number % 10;
        number /= 10;}

    return array;
}

int Codec::number_length(int x)
{
    int count = 1;
    while (x > 10)
    {
        count++;
        x /= 10;
    }
    return count;
}

vector<float> Codec::encoding(int number)
{
    size = number_length(number);
    int array[size];

    vector<float> copy_array(size);
    
    values_to_arry(number, array, size);

    int sec;
    int t;
    int half = size/2;


    if (size % 2 == 0)
        t = 1; 
    if (size % 2 == 1)
        t = 2;

    sec = half + t;


    for (int i = 0; i <= half; i++) {
        copy_array[sec + i - 1] = float(array[i + 1] + 7)/10;
        copy_array[i] = float(array[sec + i] + 7)/10;
    }
    if (t == 2)
        copy_array[half] = float(array[half + 1] + 7)/10;

    cout << "GET copy_array.size(): " << copy_array.size() << endl;
    for (int i = 0; i < size; i++)
        cout << copy_array[i] << endl;

    return copy_array;
}

vector<int> Codec::decoding(vector<float> encode)
{
    arrSize = encode.size();

    vector<int> dec_array(arrSize);
    
    int sec;
    int t;
    int half = arrSize/2;

    if (arrSize % 2 == 0)
        t = 1; 
    if (arrSize % 2 == 1)
        t = 2;
        
    sec = half + t;

    for (int i = 0; i <= half; i++) {
        dec_array[i] = int((encode[sec + i - 1])*10 - 7);
        dec_array[sec + i - 1] = int((encode[i])*10 - 7);
    }
    if (t == 2)
        dec_array[half] = int((encode[half])*10 - 7);

    cout << "GET dec_array.size(): " << dec_array.size() << endl;
    for (int i = 0; i < arrSize; i++)
        cout << dec_array[i] << endl;

    return dec_array;
};