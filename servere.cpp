#include <limits.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define INPUT_PATH              "./servere.in"
#define OUTPUT_PATH             "./servere.out"

double calculate_power(double power, double step, double limit) {
    return power - abs(step - limit);
}

double get_alimentation_step(double minPower, double maxPower,
                          double minLimit, double maxLimit) {
    return abs(minPower + minLimit - maxPower + maxLimit) / 2.0;
}

int main() {
    std::ifstream fin(INPUT_PATH);
    std::ofstream fout(OUTPUT_PATH);

    int N;
    fin >> N;

    double powers[N], limits[N];
    double alimentation;
    double minimum_power_step;

    int minIDX, maxIDX;
    int minSum = INT_MAX, maxDiff = INT_MIN;

    for (int i = 0; i < N; i++) {
        fin >> powers[i];
    }

    for (int i = 0; i < N; i++) {
        fin >> limits[i];
    }

    for (int i = 0; i < N; i++) {
        int sum = powers[i] + limits[i];
        int diff = limits[i] - powers[i];

        if (maxDiff < diff) {
            maxDiff = diff;
            maxIDX = i;
        }

        if (minSum > sum) {
            minSum = sum;
            minIDX = i;
        }
    }

    alimentation = get_alimentation_step(powers[minIDX], powers[maxIDX],
                                        limits[minIDX], limits[maxIDX]);

    minimum_power_step = INT_MAX;
    for (int i = 0; i < N; i++) {
        double power_step = calculate_power(powers[i], alimentation, limits[i]);
        if (power_step < minimum_power_step) minimum_power_step = power_step;
    }

    fout << fixed << setprecision(1) << minimum_power_step << "\n";
}
