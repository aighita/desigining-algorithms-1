#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define INPUT_PATH "./colorare.in"
#define OUTPUT_PATH "./colorare.out"
#define MOD 1000000007

long long modular_pow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;

    if (base == 0) return 0;

    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return result;
}

int main() {
    ifstream fin(INPUT_PATH);
    ofstream fout(OUTPUT_PATH);

    int N;
    fin >> N;

    vector<int> zone_number(N + 1);
    vector<char> zone_type(N + 1);

    for (int i = 1; i <= N; i++) {
        fin >> zone_number[i] >> zone_type[i];
    }

    long long result = 1;

    switch (zone_type[1]) {
    case 'H':
        result = (6 * modular_pow(3, zone_number[1] - 1)) % MOD;
        break;
    case 'V':
        result = (3 * modular_pow(2, zone_number[1] - 1)) % MOD;
        break;
    default:
        fout << "Invalid zone type" << endl;
        return 1;
    }

    for (int i = 2; i <= N; i++) {
        switch (zone_type[i - 1]) {
        case 'H':
            switch (zone_type[i]) {
            case 'H':
                result *= modular_pow(3, zone_number[i]) % MOD;
                break;
            case 'V':
                result *= modular_pow(2, zone_number[i] - 1) % MOD;
                break;
            }
            break;
        case 'V':
            switch (zone_type[i]) {
            case 'H':
                result *= (6 * modular_pow(3, zone_number[i] - 2)) % MOD;
                break;
            case 'V':
                result *= modular_pow(2, zone_number[i]) % MOD;
                break;
            }
            break;
        }

        result %= MOD;
    }

    fout << result << endl;

    fin.close();
    fout.close();

    return 0;
}
