#include "perceptron.h"
#include "ctime"

using namespace std;

int main() {

    sensor Sensor;
    perceptron Perceptron[10];
    for (double i = 0.7; i < 2; i += 0.05) {
        cout << "LearningSpeed " << i<< " ----------------------------" << endl;

        for (int m = 0; m < 10; ++m) {
            Perceptron[m].setLearningSpeed(i);
        }

        for (int j = 5; j < 30; j += 1) {

            for (int m = 0; m < 10; ++m) {
                Perceptron[m].setLimit(j);
            }

            cout << "limit " << j << endl;
            unsigned int MeanTime = 0;
            for (int l = 0; l < 10; ++l) {

                unsigned int LearningStartTime = clock();
                for (int k = 0; k < 10; ++k) {
                    Sensor.CreateData(k);
                    for (int i = 0; i < 10; ++i) {
                        if (i == k) Perceptron[i].learning(&Sensor, 1);
                        else Perceptron[i].learning(&Sensor, -1);
                    }
                }
                unsigned int LearningEndTime = clock();
                MeanTime += LearningEndTime - LearningStartTime;
            }
            cout << "MeanTime " << MeanTime / 10  << endl << endl;
        }
    }

    for (int m = 0; m < 10; ++m) {
        Perceptron[m].setLearningSpeed(0.01);
        Perceptron[m].setLimit(10);
    }

    int Lose = 0, Right = 0;
    for (int j = 0; j < 10; ++j) {
        cout << "True answer: " << j;
        Sensor.CreateData(j);
        int PerceptronAnswers = -1;
        bool uncertainty = true;
        for (int i = 0; i < 10; ++i) {
            if (Perceptron[i].answer(&Sensor) == 1) {
                if (PerceptronAnswers == -1) {
                    PerceptronAnswers = i;
                    uncertainty = false;
                } else {
                    uncertainty = true;
                }
            }
        }
        cout << " Network answer: ";
        if (!uncertainty) {
            cout << PerceptronAnswers << endl;
            Right++;
        } else {
            Lose++;
            cout << "uncertainty" << endl;
        }
    }

    double Accuracy = 100 - (Lose * 100. / (Right + Lose));
    cout << "Accuracy: " << Accuracy << "%" << endl;

    for (int i = 0; i < 10; ++i) {
        Perceptron[i].save(i);
    }
    return 0;
}
