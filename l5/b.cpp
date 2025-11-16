#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> costos(n+1);
    for (int i = 1; i <= n; ++i) cin >> costos[i];

    int m;
    cin >> m;
    vector<int> pedidos(m);
    int s_max = 0;
    for (int i = 0; i < m; ++i) {
        cin >> pedidos[i];
        s_max = max(s_max, pedidos[i]);
    }

    const int IMP = -1;
    const int AMB = -2;
    vector<int> wea(s_max + 1, IMP);
    wea[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        int costo = costos[i];
        for (int suma = 0; suma + costo <= s_max; ++suma) {
            if (wea[suma] == IMP) continue;
            int a = suma + costo;
            if (wea[suma] == AMB) {
                wea[a] = AMB;
            } else {
                if (wea[a] == IMP) wea[a] = i;
                else wea[a] = AMB;
            }
        }
    }

    for (int pedido : pedidos) {
        if (wea[pedido] == IMP) {
            cout << "Impossible\n";
        } else if (wea[pedido] == AMB) {
            cout << "Ambiguous\n";
        } else {
            vector<int> respuesta;
            int suma = pedido;
            while (suma > 0) {
                int idx = wea[suma];

                if (idx <= 0) {
                    respuesta.clear();
                    break;
                }

                respuesta.push_back(idx);
                suma -= costos[idx];
            }

            sort(respuesta.begin(), respuesta.end());

            for (size_t i = 0; i < respuesta.size(); ++i) {
                if (i) cout << ' ';
                cout << respuesta[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
