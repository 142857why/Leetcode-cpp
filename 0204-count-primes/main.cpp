#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int countPrimes(int n) {
    vector<int> primes;
    vector<bool> isPrime(n, true);
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
            // cout << "i = " << i << "*" <<  "primes[j] = " << primes[j] << " " << i * primes[j] << "; ";
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
//        cout << "has been ruled out\n";
    }
//    printVector(primes);
    return primes.size();
}


int main() {
    int n = 50;
    cout << countPrimes(n) << endl;
    return 0;
}
