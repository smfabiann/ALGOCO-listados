#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<char, vector<int>> mapita, input;


    for (int i = 0; i < 4; i++) {
        string temp;
        getline(cin, temp);
        int j = 0;
        for (char c : temp) {
            input[c] = {i, j++};
        };
    }
    string abc = "ABCDEFGHIJKLMNO.";

    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char c = abc[i * 4 + j];
            mapita[c] = {i, j};
        }
    }


    int resultado = 0;
    for (const auto& par : mapita) {
        vector<int> valor = par.second;
        char c = par.first;
        if (c == '.') continue;

        int fila1 = input[c][0];
        int fila2 = mapita[c][0];

        int col1 = input[c][1];
        int col2 = mapita[c][1]; 

        
        int diferencia = abs(fila1 - fila2) + abs(col1 - col2);
        resultado += diferencia;
    }

    cout << resultado << endl;
    return 0;
}