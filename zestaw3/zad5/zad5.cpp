#include "sha256.cpp"
#include <iostream>
#include <chrono>

#define MAX_NONCE 100000000000
using namespace std;

string sha256(string dataInput)
{
    int len = sizeof(dataInput);
    char data[1024];
    strncpy(data, dataInput.c_str(), sizeof(data));
    data[sizeof(data) - 1] = 0;
    string sha256 = SHA256(data);
    return sha256;
}

string mine(int block_number, string transaction, string previous_hash, int nonce)
{
    string text = to_string(block_number) + transaction + previous_hash + to_string(nonce);
    string new_hash = sha256(text);
    return new_hash;
}

int main()
{
    int zerosCounter;
    cout << "Ile ma byc zer na poczatku: ";
    cin >> zerosCounter;
    cout << endl;

    auto begin = std::chrono::high_resolution_clock::now();

    for (int nonce = 1; nonce < MAX_NONCE; nonce++)
    {
        string new_hash = mine(5, "'", "0000000xa036944e29568d0cff17edbe038f81208fecf9a66be9a2b8321c6ec7", nonce);
        string test(zerosCounter, '0');

        auto res = mismatch(test.begin(), test.end(), new_hash.begin());
        if (res.first == test.end())
        {
            cout << new_hash << endl;
            cout << "Successfully mined bitcoins with nonce value: " << nonce << endl;
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout << "Time measured: " << elapsed.count() * 1e-9 << "seconds." << endl;
}