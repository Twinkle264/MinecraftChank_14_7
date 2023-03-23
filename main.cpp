#include <iostream>
using namespace std;


void show_matrix (int a, bool matrix[5][5][10]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j][a] << ' ';
        }
        cout << endl;
    }
}

void inicial_chank (bool matrix[5][5][10]) {
    int cubes = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {

            do {
                cout << "What is the height of the cubes at " << i << "." << j << "? ";
                cin >> cubes;
                if (cubes < 0 || cubes > 10) {
                    cout << "Incorrect input!" << endl;
                }
            } while (cubes < 0 || cubes > 10);

            for (int k = 0; k < cubes; ++k) {
                if (cubes > 0 && cubes <= 10) {
                    matrix[i][j][k] = true;
                } else if (cubes == 0) matrix[i][j][k] = false;
            }
        }
    }
}


int main() {
    bool chank[5][5][10];
    int layer = 0;

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 10; ++k) {
                chank[i][j][k] = false;
            }
        }
    }
    show_matrix(layer, chank);

    inicial_chank(chank);

    cout << endl << "Enter -1 to exit!" << endl;

    do {
        do {
            cout << "Enter the number of the layer you want to display (0 - 9): ";
            cin >> layer;

            if (layer < -1 || layer > 9){
                cout << endl << "Incorrect input!" << endl;
            }
        } while (layer < -1 || layer > 9);

        if (layer == -1) return 0;
        show_matrix(layer, chank);
    } while (layer != -1);
    return 0;
}
