#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n != 0) {
        map<string, vector<string>> m;
        for (int i = 0; i < n; i++) {
            string valor;
            cin >> valor;

            string key = valor.substr(0, 2);
            m[key].push_back(valor);
        }

        for (const auto& par : m) {
            for (const auto& valor : par.second) {
                cout << valor << endl;
            }
        }

        cin >> n;
    }

    return 0;
}