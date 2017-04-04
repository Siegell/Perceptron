//
// Created by pavel on 27.03.17.
//

#include "perceptron.h"

perceptron::perceptron() {
    srand(time(0));
    bias = 0;
    //bias = rand() % 9 - 5;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            synapse[i][j] = 0;
            //synapse[i][j] = rand() % 9 - 5;

        }
    }
    limit = 10;
    LearningSpeed = 0.01;
}

int perceptron::answer(sensor *Sensor) {
    double Sum = bias;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            Sum += synapse[i][j] * Sensor->getSensor(i, j);
        }
    }
    if (Sum > limit) return 1;
    else return -1;
}

void perceptron::learning(sensor *Sensor, int answer) {
    int y = this->answer(Sensor);
    while (y != answer) {
        int direct = answer - y;
        bias += direct * LearningSpeed;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                synapse[i][j] += direct * Sensor->getSensor(i, j) * LearningSpeed;
            }
        }
        y = this->answer(Sensor);
    }
}

void perceptron::input() {
    ifstream fin("Synapse.txt");
    if (!fin.is_open())
        cout << "Файл ввода синапсов не открыт!\n";

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            fin >> synapse[i][j];
        }
    }

    fin.close();
}

void perceptron::output() {
    ofstream fout("Synapse.txt");
    if (!fout.is_open())
        cout << "Файл вывода синапсов не открыт!\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            fout << synapse[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}

ostream &operator<<(ostream &os, const perceptron &perceptron1) {
    os << "bias: " << perceptron1.bias << " synapse: " << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << setw(5) << perceptron1.synapse[i][j] << " ";
        }
        cout << endl;
    }
    return os;
}
