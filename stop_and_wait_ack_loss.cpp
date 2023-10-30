#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void sender(vector<int> &, int &);
bool receiver(int, bool);
int randomNoise(int);
vector<int> got;
int main()
{
    srand(std::time(0));
    int size = 5;
    vector<int> data(size);
    iota(data.begin(), data.end(), 1);

    sender(data, size);
    return 0;
}

bool receiver(int data, bool isNoisy)
{
    vector<bool> noise = {false, true};

    if (find(got.begin(), got.end(), data) != got.end())
        cout << "Acknowledge from Receiver - data already exist\n";
    else
    {
        got.push_back(data);

        if (!noise[randomNoise(2)])
            cout << "Acknowledge from Receiver - data received\n";
        else
            return false;
        return true;
    }
    return true;
}

int randomNoise(int size)
{
    return rand() % size;
}

void sender(vector<int> &data, int &size)
{
    vector<bool> noise = {false, true, false};

    for (int i = 0; i < size; i++)
    {
        cout << "Acknowledge from Sender - " << data[i] << " data send\n";

        if (receiver(data[i], true))
            continue;
        else
        {
            sleep(5);
            cout << "Acknowledge from Sender - Timer timeout no acknowledgement received from receiver\nResend\n";
            i--;
        }
    }

    cout << "Total data sent\n";
}
