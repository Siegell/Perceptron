//
// Created by pavel on 27.03.17.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#include <ostream>
#include <iomanip>
#include "sensor.h"
#include <ctime>
#include <math.h>

class perceptron {
    double synapse[5][3];
    double bias;
    int limit;
    double LearningSpeed;
public:
    perceptron();

    int answer(sensor *Sensor);

    void learning(sensor *Sensor, int answer);

    void input();

    void output();

    friend ostream &operator<<(ostream &os, const perceptron &perceptron1);
};


#endif //PERCEPTRON_PERCEPTRON_H
