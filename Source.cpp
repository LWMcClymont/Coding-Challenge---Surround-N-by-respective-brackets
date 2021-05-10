#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void solve(const string& N, string& output);
void addB(string& output, const char b, const int count);

int main()
{
	// Get input from user
	string input, output = "";
	cin >> input;

	solve(input, output);

	cout << output << endl;


	return 0;
}

void solve(const string& N, string& output)
{
	int depth = 0;

	for (int i = 0; i < N.size(); ++i)
	{
		int c = N[i] - '0';

		if (depth == c)
		{
			output += to_string(c);
		}
		else if (c > depth)
		{
			int diff = c - depth;
			addB(output, '(', diff);
			output += to_string(c);
		}
		else if (c < depth)
		{
			int diff = depth - c;
			addB(output, ')', diff);
			output += to_string(c);
		}

		depth = c;
	}

	addB(output, ')', depth);
}

void addB(string& output, const char b, const int count)
{
	for (int i = 0; i < count; ++i)
	{
		output += b;
	}
}