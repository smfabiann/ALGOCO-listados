#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n != 0) {
        vector<int> v1(n), v2(n);
        unordered_map<int, int> m;
        
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> v2[i];
        }

        vector<int> original_v1 = v1;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < n; i++) {
            m[v1[i]] = v2[i];
        }

        for (const auto& valor : original_v1) {
            cout << m[valor] << "\n";
        }

        cout << "\n";

        cin >> n;
    }

    return 0;
}