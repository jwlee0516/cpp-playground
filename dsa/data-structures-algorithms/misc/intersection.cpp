#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& num1, vector<int>& num2) {
    
    vector<int> result;
    unordered_map<int, int> hist;

    for (int item : num1) { hist[item]++; }
    for (int item : num2) {
        
        if (--hist[item] >= 0) 
        {
            result.push_back(item);
        }
    }
    return result;
}

int main() {
    vector<int> num1 = {1,2,3,4,5,6,7};
    vector<int> num2 = {4,5,6,7,8,9,10};

    cout << "nums1: " << endl;
    for (int i = 0; i < (int) num1.size(); ++i){cout << num1[i] << " ";}
    cout << endl;
    
    cout << "nums2: " << endl;
    for (int i = 0; i < (int) num2.size(); ++i){cout << num2[i] << " ";}
    cout << endl;

    cout << "intersection: " << endl;
    vector<int> intersection = intersect(num1, num2);
    for (int i = 0; i < (int) intersection.size(); ++i) {cout << intersection[i] << " ";}
    cout << endl;

    return 0;
}