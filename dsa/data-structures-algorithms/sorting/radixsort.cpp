#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    
    int max = arr[0];
    for (int i = 0; i < n; ++i)
        if (arr[i] > max) max = arr[i];

    return max;
}

void countSort(int arr[], int n, int exp) {
    
    int output[n];
    int i, count[10] = {0};

    //build the digit histogram
    for (int i = 0; i < n; ++i)
        count[(arr[i]/exp) % 10]++;

    //make it cumulative
    for (i = 1; i < 10; ++i)
        count[i] += count[i-1];

    //index output array by cumulative histogram
    //and decrement corresponding value
    for (i = n - 1; i >= 0; --i) {
        
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    //write out the result
    for (i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {

    //find the max number to figure out number of digits
    int m = getMax(arr, n);

    //do count sort for every digit, instead of passing the 
    //digit number, exp is passed, exp is 10^i where i is the
    //current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);

    cout << "radix sort:" << endl;
    for (int i=0; i<n; ++i) {cout << arr[i] << " ";}
    cout << endl;

    return 0;
}