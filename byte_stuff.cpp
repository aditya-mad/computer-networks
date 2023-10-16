#include <iostream>
#include <algorithm>
using namespace std;

string message;
char flag;

void readMessage();
void readMessageDuplicate();
void decodeMessage();

int main()
{
	int size;
	cout << "No of Frames - ";
	cin >> size;

	cout << "Flag - ";
	cin >> flag;

	for (int i = 0; i < size; i++)
	{
		readMessageDuplicate();
		cout << "	Coded Message - " << message << endl;
		decodeMessage();
	}
	return 0;
}

void readMessage()
{
	cout << "Enter message - ";
	cin >> message;
	message = flag + message + flag;
}

void readMessageDuplicate()
{
	cout << "Enter message - ";
	cin >> message;
	string temp;

	for (auto x : message)
	{
		if (x == flag)
			temp = temp + x;
		temp = temp + x;
	}

	message = flag + temp + flag + '\0';
}

void decodeMessage()
{
	cout << "	Decoded Message - ";
	int count = 1;
	int i = 1;
	while (count < 2)
	{
		if (message[i] == flag)
		{
			if (message[i + 1] == flag)
				cout << message[i++];
			else
				count++;
		}
		else if (count == 1)
			cout << message[i];

		i++;
	}
	cout << endl;
}