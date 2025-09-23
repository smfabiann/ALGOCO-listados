#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> datasets(n, vector<int>(20));
    
    // Leer los datos
    for (int i = 0; i < n; i++) {
        int datasetNum;
        cin >> datasetNum;
        for (int j = 0; j < 20; j++) {
            cin >> datasets[i][j];
        }
    }

    // Procesar cada conjunto de datos
    for (int i = 0; i < n; i++) {
        int datasetNum = i + 1;
        vector<int> heights = datasets[i];
        
        vector<int> line;
        int totalSteps = 0;
        
        for (int h : heights) {
            // Buscar la posición donde insertar
            int pos = line.size();
            for (int j = 0; j < line.size(); j++) {
                if (line[j] > h) {
                    pos = j;
                    break;
                }
            }
            
            // Calcular pasos (estudiantes que deben moverse)
            totalSteps += line.size() - pos;
            
            // Insertar en la posición encontrada
            line.insert(line.begin() + pos, h);
        }
        
        cout << datasetNum << " " << totalSteps << endl;
    }

    return 0;
}