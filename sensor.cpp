//
// Created by pavel on 27.03.17.
//

#include "sensor.h"

sensor::sensor() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            map[i][j] = 0;
        }
    }
}

void sensor::input() {
    ifstream fin("Sensor.txt");
    if (!fin.is_open())
        cout << "Файл ввода сенсоров не открыт!\n";

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            fin >> map[i][j];
        }
    }

    fin.close();
}

void sensor::CreateData(int N) {
    switch (N) {
        case 0: {
            map[0][0] = 1;
            map[0][1] = 1;
            map[0][2] = 1;
            map[1][0] = 1;
            map[1][1] = -1;
            map[1][2] = 1;
            map[2][0] = 1;
            map[2][1] = -1;
            map[2][2] = 1;
            map[3][0] = 1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = 1;
            map[4][1] = 1;
            map[4][2] = 1;
            break;
        }
        case 1: {
            map[0][0] = -1;
            map[0][1] = -1;
            map[0][2] = 1;
            map[1][0] = -1;
            map[1][1] = -1;
            map[1][2] = 1;
            map[2][0] = -1;
            map[2][1] = -1;
            map[2][2] = 1;
            map[3][0] = -1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = -1;
            map[4][1] = -1;
            map[4][2] = 1;
            break;
        }
        case 2: {
            map[0][0] = 1;
            map[0][1] = 1;
            map[0][2] = 1;
            map[1][0] = -1;
            map[1][1] = -1;
            map[1][2] = 1;
            map[2][0] = 1;
            map[2][1] = 1;
            map[2][2] = 1;
            map[3][0] = 1;
            map[3][1] = -1;
            map[3][2] = -1;
            map[4][0] = 1;
            map[4][1] = 1;
            map[4][2] = 1;
            break;
        }
        case 3: {
            map[0][0] = 1;
            map[0][1] = 1;
            map[0][2] = 1;
            map[1][0] = -1;
            map[1][1] = -1;
            map[1][2] = 1;
            map[2][0] = 1;
            map[2][1] = 1;
            map[2][2] = 1;
            map[3][0] = -1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = 1;
            map[4][1] = 1;
            map[4][2] = 1;
            break;
        }
        case 4: {
            map[0][0] = 1;
            map[0][1] = -1;
            map[0][2] = 1;
            map[1][0] = 1;
            map[1][1] = -1;
            map[1][2] = 1;
            map[2][0] = 1;
            map[2][1] = 1;
            map[2][2] = 1;
            map[3][0] = -1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = -1;
            map[4][1] = -1;
            map[4][2] = 1;
            break;
        }
        case 5: {
            map[0][0] = 1;
            map[0][1] = 1;
            map[0][2] = 1;
            map[1][0] = 1;
            map[1][1] = -1;
            map[1][2] = -1;
            map[2][0] = 1;
            map[2][1] = 1;
            map[2][2] = 1;
            map[3][0] = -1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = 1;
            map[4][1] = 1;
            map[4][2] = 1;
            break;
        }
        case 6: {
            map[0][0] = 1;
            map[0][1] = 1;
            map[0][2] = 1;
            map[1][0] = 1;
            map[1][1] = -1;
            map[1][2] = -1;
            map[2][0] = 1;
            map[2][1] = 1;
            map[2][2] = 1;
            map[3][0] = 1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = 1;
            map[4][1] = 1;
            map[4][2] = 1;
            break;
        }
        case 7: {
            map[0][0] = 1;
            map[0][1] = 1;
            map[0][2] = 1;
            map[1][0] = 1;
            map[1][1] = -1;
            map[1][2] = 1;
            map[2][0] = -1;
            map[2][1] = -1;
            map[2][2] = 1;
            map[3][0] = -1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = -1;
            map[4][1] = -1;
            map[4][2] = 1;
            break;
        }
        case 8: {
            map[0][0] = 1;
            map[0][1] = 1;
            map[0][2] = 1;
            map[1][0] = 1;
            map[1][1] = -1;
            map[1][2] = 1;
            map[2][0] = 1;
            map[2][1] = 1;
            map[2][2] = 1;
            map[3][0] = 1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = 1;
            map[4][1] = 1;
            map[4][2] = 1;
            break;
        }
        case 9: {
            map[0][0] = 1;
            map[0][1] = 1;
            map[0][2] = 1;
            map[1][0] = 1;
            map[1][1] = -1;
            map[1][2] = 1;
            map[2][0] = 1;
            map[2][1] = 1;
            map[2][2] = 1;
            map[3][0] = -1;
            map[3][1] = -1;
            map[3][2] = 1;
            map[4][0] = 1;
            map[4][1] = 1;
            map[4][2] = 1;
            break;
        }
        default:
            break;
    }
}

void sensor::output() {
    ofstream fout("Sensor.txt");
    if (!fout.is_open())
        cout << "Файл вывода сенсоров не открыт!\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            fout << map[i][j]<<" ";
        }
        fout << endl;
    }
    fout.close();
}

int sensor::getSensor(int i, int j) {
    return map[i][j];
}

