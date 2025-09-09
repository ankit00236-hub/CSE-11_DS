#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;
    cout << "Enter size of second array: ";
    cin >> n;

    vector<int> arr1(m), arr2(n), merged;

    cout << "Enter elements of first array:\n";
    for(int i = 0; i < m; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter elements of second array:\n";
    for(int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    // Merging arrays
    merged.reserve(m + n);
    merged.insert(merged.end(), arr1.begin(), arr1.end());
    merged.insert(merged.end(), arr2.begin(), arr2.end());

    cout << "Merged array: ";
    for(int val : merged) {
        cout << val << " ";
    }
    cout << endl;