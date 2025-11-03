#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long l, d;
    int n;
    cin >> l >> d >> n;

    long long total = 0;
    long long disponible = 6;
    long long ultimo = l - 6;

    if (n == 0) {
        long long inicio = disponible;
        long long final = ultimo;
        if (final >= inicio) {
            total = (final - inicio) / d + 1;
        }
    } 
    else {
        vector<long long> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        sort(p.begin(), p.end());


        long long inicio = disponible;
        long long final = p[0] - d; 
        if (final >= inicio) {
            total += (final - inicio) / d + 1;
        }

        for (int i = 0; i < n - 1; i++) {
            inicio = p[i] + d;
            final = p[i+1] - d;
            if (final >= inicio) {
                total += (final - inicio) / d + 1;
            }
        }

        inicio = p[n-1] + d;
        final = ultimo;
        if (final >= inicio) {
            total += (final - inicio) / d + 1;
        }
    }

    cout << total << endl;

    return 0;
}