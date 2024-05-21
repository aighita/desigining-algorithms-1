#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;


#define INPUT_PATH              "./compresie.in"
#define OUTPUT_PATH             "./compresie.out"

int vector_sum(int v[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; ++i) {
        sum += v[i];
    }
    return sum;
}

int main() {
    std::ifstream fin(INPUT_PATH);
    std::ofstream fout(OUTPUT_PATH);

    int n, m;
    fin >> n;
    int A[n];
    for (int i = 0; i < n; ++i) {
        fin >> A[i];
    }

    fin >> m;
    int B[m];
    for (int i = 0; i < m; ++i) {
        fin >> B[i];
    }

    if (vector_sum(A, n) != vector_sum(B, m)) {
        fout << -1 << "\n";
        return 0;
    }

    int part_A[n], part_B[m];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        part_A[i] = sum;
    }

    sum = 0;
    for (int i = 0; i < m; i++) {
        sum+= B[i];
        part_B[i] = sum;
    }

    int comm = 0;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = m;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (part_B[mid] == part_A[i]) {
                comm++;
                break;
            } else if (part_B[mid] > part_A[i]) {
                right = mid - 1;
            } else if (part_B[mid] < part_A[i]) {
                left = mid + 1;
            }
        }
    }

    fout << comm;

    fin.close();
    fout.close();

    return 0;
}
