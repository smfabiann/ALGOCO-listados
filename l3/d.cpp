#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string s;
    vector<int> v, original;

    getline(cin, s);

    for (auto& c : s) {
        v.push_back(c - '0');
    }
    original = v;
    sort(v.begin(), v.end());

    vector<vector<int>> permutaciones;

    do {
        vector<int> temp;
        for (auto& iter : v) {
            temp.push_back(iter);
        }
        permutaciones.push_back(temp);
    } while (next_permutation(v.begin(), v.end()));

    auto it = upper_bound(permutaciones.begin(), permutaciones.end(), original);
    
    if (it != permutaciones.end()) {
        for (int x : *it) cout << x;
        cout << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}