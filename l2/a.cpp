#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(20));

    for (int i = 0; i < n; i++) {
        int caca;
        cin >> caca; // Saltar el índice
        for (int j = 0; j < 20; j++) {
            cin >> v[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        vector<int> altura = v[i];
        vector<int> line;
        int pasos = 0;
        for (int h : altura) {
            int pos = line.size();
            for (size_t j = 0; j < line.size(); j++) {
                if (line[j] > h) {
                    pos = j;
                    break;
                }
            }
            pasos += line.size() - pos;
            line.insert(line.begin() + pos, h);
        }
        cout << i+1 << " " << pasos << endl;
    }

    return 0;
}