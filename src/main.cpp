#include "perceptron.h"

using namespace std;

int main() {

    sensor Sensor;

    perceptron Perceptron[10];
    for (int k = 0; k < 10; ++k) {
        Sensor.CreateData(k);
        for (int i = 0; i < 10; ++i) {
            if (i == k) Perceptron[i].learning(&Sensor, 1);
            else Perceptron[i].learning(&Sensor, -1);
        }
    }
    for (int j = 0; j < 10; ++j) {
        cout << " j: " << j << endl;
        Sensor.CreateData(j);
        for (int i = 0; i < 10; ++i) {
            cout << "i: " << i << " answer: " << Perceptron[i].answer(&Sensor) << endl;
        }
    }

    return 0;
}
