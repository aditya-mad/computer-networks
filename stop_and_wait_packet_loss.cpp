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
int randomNoise(int &);

int main()
{
    int size = 5;
    vector<int> data(size);
    iota(data.begin(), data.end(), 1);

    sender(data, size);
    return 0;
}

bool receiver(int data, bool isNoisy)
{
    if (!isNoisy)
        cout << "Acknowledge from Receiver - data received\n";
    return true;
}

int randomNoise(int &size)
{
    srand(time(0));
    return rand() % size;
}

void sender(vector<int> &data, int &size)
{
    vector<bool> noise = {false, true, false};

    for (int i = 0; i < size; i++)
    {
        cout << "Acknowledge from Sender - " << data[i] << " data send\n";
        if (noise[randomNoise(size)])
        {
            sleep(5);
            cout << "Acknowledge from Sender - Timer timeout\nResend\n";
            i--;
        }
        else
        {
            if (receiver(data[i], false))
                continue;
        }
    }

    cout << "Total data sent\n";
}
