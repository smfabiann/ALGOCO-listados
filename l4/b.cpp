#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int n;
    long long m;
    cin >> n >> m;

    
    vector<pair<long long, long long>> investigadores(n);
    for (int i = 0; i < n; i++) {
        cin >> investigadores[i].first >> investigadores[i].second;
    }

    sort(investigadores.begin(), investigadores.end());

    int r = 0;
    priority_queue<long long, vector<long long>, greater<long long>> libre;

    for (int i = 0; i < n; i++) {
            long long llegada = investigadores[i].first;
            long long duracion = investigadores[i].second;
            long long salida = llegada + duracion;

            long long lock_threshold = llegada - m;
        while (!libre.empty() && libre.top() < lock_threshold) {
            libre.pop();
        }

        if (!libre.empty() && libre.top() <= llegada) {
            r++;
            libre.pop();
            libre.push(salida);
        } else {
            libre.push(salida);
        }
    }

    cout << r << endl;

    return 0;
}