#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
    }

    sort(v.rbegin(), v.rend());

    long long discount = 0; 
    
    int j = 1;
    for (auto& i : v) {
        if (j % 3 == 0) {
            discount += i;
            j++;

        } else {
            j++;
        }
    }

    cout << discount << endl;
    return 0;
}