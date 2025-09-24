#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<int> cans(n);
    vector<int> colors(m);

    for (int i = 0; i < n; i++) cin >> cans[i];
    for (int i = 0; i < m; i++) cin >> colors[i];

    sort(cans.begin(), cans.end());

    long long perdida = 0;
    for (const auto& color : colors) {
        auto busqueda = lower_bound(cans.begin(), cans.end(), color);
        perdida += static_cast<long long>(*busqueda) - color;
    }

    cout << perdida << endl;

    return 0;
}