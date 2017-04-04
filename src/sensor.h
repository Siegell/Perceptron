#ifndef PERCEPTRON_SENSOR_H
#define PERCEPTRON_SENSOR_H

#include <iostream>
#include <fstream>

using namespace std;

class sensor {
    int map[5][3];
public:
    sensor();

    void input();

    void CreateData(int N);

    void output();

    int getSensor(int i, int j);
};


#endif //PERCEPTRON_SENSOR_H
