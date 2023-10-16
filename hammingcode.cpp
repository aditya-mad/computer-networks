#include <iostream>
#include <vector>
using namespace std;
#define SETBITS(x) __builtin_popcount(x)

void sender(vector<int> &);
void receiver(vector<int> &);

int datasize, wordsize, rbits = 1000, parity = 0;
string word;

int main()
{

    cin >> word;

    wordsize = word.size();

    for (int i = 1; i <= wordsize; i++)
    {
        if ((1LL << i) >= i + wordsize + 1)
        {
            rbits = i;
            break;
        }
    }

    if (rbits == 1000)
        return 0;
    else
        cout << "Rbits - " << rbits << endl;

    datasize = rbits + wordsize;

    vector<int> data(datasize + 1, parity);

    cout << "Initial Step - ";
    for (int i = datasize; i > 0; i--)
    {
        if (SETBITS(i) == 1)
            cout << "P" << i << " ";
        else
            cout << "D" << i << " ";
    }
    cout << endl;

    cout << "Next Step - ";
    for (int i = datasize, ind = 0; i > 0; i--)
    {
        if (SETBITS(i) == 1)
            cout << "P" << i << " ";
        else
        {
            data[i] = word[ind] - '0';
            cout << word[ind++] << " ";
        }
    }
    cout << endl
         << "Final - ";

    sender(data);
    for (int i = datasize; i > 0; i--)
        cout << data[i] << " ";
    data[rbits] = abs(data[rbits] - 1);
    cout << "\nReceiver - ";
    for (int i = datasize; i > 0; i--)
        cout << data[i] << " ";
    receiver(data);

    return 0;
}

void sender(vector<int> &data)
{
    for (int i = 1; i <= datasize; i++)
    {
        if (SETBITS(i) == 1)
        {
            int res = data[i];
            for (int j = i + 1; j <= datasize; j++)
            {
                if ((i & j) != 0)
                    res ^= data[j];
            }
            data[i] = res;
        }
    }
    return;
}

void receiver(vector<int> &data)
{
    int res = 0;
    for (int i = 1, count = 0; i <= datasize; i++)
    {
        if (SETBITS(i) == 1)
        {
            int temp = data[i];
            for (int j = i + 1; j <= datasize; j++)
            {
                if ((i & j) != 0)
                    temp ^= data[j];
            }
            res |= (temp << count);
            count++;
        }
    }
    cout << endl
         << "Error is at position - " << res;
    return;
}
