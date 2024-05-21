#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define     INPUT_PATH      "./oferta.in"
#define     OUTPUT_PATH     "./oferta.out"

double min_of_three(double a, double b, double c) {
    return std::min(std::min(a, b), c);
}

int main() {
    std::ifstream fin(INPUT_PATH);
    std::ofstream fout(OUTPUT_PATH);

    int N, K;
    fin >> N >> K;

    if (K != 1) return 0;

    double products[N], DP[N];

    for (int i = 0; i < N; i++) {
        fin >> products[i];
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) DP[i] = products[i];

        if (i == 1) {
            if (products[i] < products[i - 1]) {
                DP[i] = products[i - 1] + products[i] / 2;
            } else {
                DP[i] = products[i] + products[i - 1] / 2;
            }
        }

        if (i >= 2) {
            double min_I = DP[i - 1] + products[i];
            double min_II = DP[i - 2] + products[i] + products[i - 1] -
                            std::min(products[i], products[i - 1]) / 2;
            double min_III = DP[i - 3] + products[i] +
                            products[i - 1] + products[i - 2] -
                    min_of_three(products[i], products[i - 1], products[i - 2]);
            DP[i] = min_of_three(min_I, min_II, min_III);

            cout << min_I << " " << min_II << " " << min_III << endl;
        }
    }

    fout << fixed << setprecision(1) << DP[N - 1] << endl;

    fin.close();
    fout.close();
}
