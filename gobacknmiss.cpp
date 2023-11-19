#include <bits/stdc++.h>
using namespace std;

void sender(vector<int> &, int &);
int receiver(vector<int> &);

int main()
{
    srand(std::time(0));
    int n;
    cin >> n;

    vector<int> data((1 << n));

    for (int i = 0; i < n; i++)
        data[i] = i;

    sender(data, n);

    return 0;
}

void sender(vector<int> &data, int &n)
{
    vector<int> miss = {false, true, false, false};
    for (int i = 0; i < ((1 << n)); i++)
    {
        int temp = n, ind = i;
        while (temp--)
        {
            cout << "Sent " << ind++ << "\n";
        }

        temp = n;
        while (temp-- && i < ((1 << n)))
        {
            if (!miss[rand() % 4])
            {
                cout << "Received - " << i++ << "\n";

                continue;
            }

            cout << "Timer timeout\n";

            temp = n, ind = i;
            while (temp-- && ind < ((1 << n)))
            {
                cout << "Sent " << ind++ << "\n";
            }
            temp = n;

            while (temp-- && i < ((1 << n)))
            {
                cout << "Received " << i++ << "\n";
            }
            break;
        }
    }
}
