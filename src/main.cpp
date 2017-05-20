#include "perceptron.h"
#include "ctime"

using namespace std;

int main() {

    sensor Sensor;
    perceptron Perceptron[10];

    unsigned int LearningStartTime = clock();
    for (int k = 0; k < 10; ++k) {
        Sensor.CreateData(k);
        for (int i = 0; i < 10; ++i) {
            if (i == k) Perceptron[i].learning(&Sensor, 1);
            else Perceptron[i].learning(&Sensor, -1);
        }
    }
    unsigned int LearningEndTime = clock();
    cout << "Learning time: " << LearningEndTime - LearningStartTime << " msec" << endl;

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
