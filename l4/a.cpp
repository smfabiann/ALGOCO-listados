#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> t(n), l(m);
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        t[i] = temp;
    }
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        l[i] = temp;
    }

    sort(t.begin(), t.end());
    sort(l.begin(), l.end());

    int resultado = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (t[i] <= l[j]) {
            resultado++;
            i++;
            j++;
        } else {
            j++;
        }
    }

    cout << resultado << endl;
    return 0;
}