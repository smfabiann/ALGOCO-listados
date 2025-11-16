#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int c, n;
    while (cin >> c >> n) {
        n++;
        c++;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i].push_back(0);
            }
        }
        vector<pair<int, int>> items; // peso valor

        for (int j = 1; j < n; j++) {
            int v, p;
            cin >> v >> p;
            items.push_back({p, v});
        }

        // se genera tabla del mejor resultado
        for (int i = 1; i < n; i++) { 

            int peso_actual = items[i-1].first;
            int valor_actual = items[i-1].second;

            for (int j = 1; j < c; j++) {
                
                int no_tomar = matrix[i-1][j];

                int tomar = 0;
                if (peso_actual <= j) {
                    tomar = valor_actual + matrix[i-1][j - peso_actual];
                }

                matrix[i][j] = max(no_tomar, tomar);
            }
        }

        vector<int> resultado;
        int j = c - 1;

        for (int i = n - 1; i > 0; i--) {
            

            if (matrix[i][j] != matrix[i-1][j]) {
                resultado.push_back(i-1);
                j = j - items[i-1].first;
            }
        }

        sort(resultado.begin(), resultado.end());
        cout << resultado.size() << endl;
        for (int item : resultado) {
            cout << item << " ";
        }
    }

    return 0;
}