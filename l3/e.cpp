#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    vector<pair<int, int>> rectangulos(3);
    long long total_area = 0;

    for (int i = 0; i < 3; i++) {
        cin >> rectangulos[i].first >> rectangulos[i].second;
        total_area += (long long)rectangulos[i].first * rectangulos[i].second;
    }


    int side = round(sqrt(total_area));
    if ((long long)side * side != total_area) {
        cout << "NO" << endl;
        return 0;
    }

    sort(rectangulos.begin(), rectangulos.end());

    do {
        auto rA = rectangulos[0];
        auto rB = rectangulos[1];
        auto rC = rectangulos[2];

        for (int i = 0; i < 8; ++i) {
            auto alto_rA = (i & 1) ? make_pair(rA.second, rA.first) : rA;
            auto alto_rB = (i & 2) ? make_pair(rB.second, rB.first) : rB;
            auto alto_rC = (i & 4) ? make_pair(rC.second, rC.first) : rC;

            if (alto_rA.first == side && alto_rB.first == side && alto_rC.first == side) {
                if (alto_rA.second + alto_rB.second + alto_rC.second == side) {
                    cout << "YES" << endl;
                    return 0;
                }
            }

            if (alto_rA.first == side) {
                int ancho_falta = side - alto_rA.second;
                if (ancho_falta > 0 && alto_rB.first == ancho_falta && alto_rC.first == ancho_falta) {
                    if (alto_rB.second + alto_rC.second == side) {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    } while (next_permutation(rectangulos.begin(), rectangulos.end()));

    cout << "NO" << endl;

    return 0;
}