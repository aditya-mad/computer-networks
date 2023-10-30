#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void sender(vector<int> &);
bool receiver(int, bool);

int main()
{
    int size = 5;
    vector<int> data(size);
    iota(data.begin(), data.end(), 1);

    sender(data);
    return 0;
}

bool receiver(int data, bool isNoisy)
{
    if (!isNoisy)
        cout << "Acknowledgement from Receiver - data received\n";
    return true;
}

void sender(vector<int> &data)
{
    for (auto &x : data)
    {
        cout << "Acknowledgement from Sender - data sent\n";
        if (receiver(x, false))
            continue;
    }
}
