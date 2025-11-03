
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<double> plots(n);
    for (int i = 0; i < n; i++) {
        cin >> plots[i];
    }

    vector<double> houses;

    for (int i = 0; i < m; i++) {
        double r;
        cin >> r;
        houses.push_back(r);
    }

    for (int i = 0; i < k; i++) {
        double s;
        cin >> s;
        houses.push_back(s * sqrt(2.0) / 2.0);
    }

    sort(plots.begin(), plots.end());
    sort(houses.begin(), houses.end());

    int total_houses = houses.size();
    int filled_plots = 0;
    int house_idx = 0;
    int plot_idx = 0;

    while (house_idx < total_houses && plot_idx < n) {
        if (houses[house_idx] < plots[plot_idx]) {
            filled_plots++;
            house_idx++;
            plot_idx++;
        } else {
            plot_idx++;
        }
    }

    cout << filled_plots << endl;
    return 0;
}