#include "../testlib/testlib.h"

using namespace std;

int range[12] = {10, 10, 1000, 1000, 1000, 1000, 1000000, 1000000, 100000, 1000000};

void writeTest(int test) {
    string filename = "testcase/" + to_string(test) + ".in";
    freopen(filename.c_str(), "w", stdout);
    int max_val = range[test-1];
    int n = rnd.next(max_val/2, max_val);
    int q = rnd.next(max_val/2, max_val);
    cout << n << " " << q << "\n";
    for (int i = 0; i < n; i++) {
        int a_i = rnd.next(0, min(1000, max_val));
        cout << a_i << (i == n-1 ? "\n" : " ");
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 1; i <= 10; i++)
        writeTest(i);
}