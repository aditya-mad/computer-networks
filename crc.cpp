#include <iostream>
#include <vector>
using namespace std;

void performdivision(vector<int> &, vector<int> &, int &, int &);

int main()
{
	int sizeofdata, sizeofpoly;
	cin >> sizeofdata >> sizeofpoly;

	vector<int> data(sizeofdata + sizeofpoly - 1), divisor(sizeofpoly);
	vector<int> finaldata(sizeofdata + sizeofpoly - 1);

	for (int i = 0; i < sizeofdata + sizeofpoly; i++)
	{
		if (i < sizeofdata)
			cin >> data[i];
		else
			data[i] = 0;
		finaldata[i] = data[i];
	}

	for (int i = 0; i < sizeofpoly; i++)
	{
		cin >> divisor[i];
	}

	performdivision(data, divisor, sizeofdata, sizeofpoly);

	cout << "Remainder - ";
	for (int i = sizeofdata; i < sizeofdata + sizeofpoly - 1; i++)
	{
		finaldata[i] = data[i];
		cout << finaldata[i];
	}

	cout << endl;

	cout << "New Data - ";
	for (auto x : finaldata)
		cout << x << " ";
	cout << endl;

	performdivision(finaldata, divisor, sizeofdata, sizeofpoly);

	cout << "Remainder is - ";
	for (int i = sizeofdata; i < sizeofdata + sizeofpoly - 1; i++)
	{
		cout << finaldata[i];
	}
	cout << endl;
}

void performdivision(vector<int> &data, vector<int> &divisor, int &sizeofdata, int &sizeofpoly)
{
	for (int i = 0; i < sizeofdata;)
	{
		for (int j = 0; j < sizeofpoly; j++)
		{
			data[i + j] ^= divisor[j];
		}

		while (data[i] == 0)
			i++;
	}
}
