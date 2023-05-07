#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


vector<string> registr = { "000000000000000000000000000000", "000000000000000000000000000000" };
							
vector<int> sc10 = { 0,0,0 };
int PS = 0;
int TC;
int PC = 0;

string add(string v1, string v2) {

	int p = 0;
	int sum = 0;
	string res = "";

	for (int i = 29; i >= 0; i--) {
		sum = v1[i] - '0' + v2[i] - '0' + p;

		res.insert(0, to_string(sum % 2));
		p = sum / 2;
	}
	if (p > 0) res[0] = p;

	return res;
}

void output(string com, string operand1, string operand2)
{
	system("pause");
	cout << com + " " << operand1 + " " << operand2 + " " << endl;
	cout << "\t============Step1=============" << endl;
	TC = 1;
	PC++;
	for (int i = 1; i <= 2; i++)
	{
		cout << "R" << i << " = ";
		for (int j = 0; j < 6; j++) {
			cout << registr[i - 1].substr(j * 5, 5) << " ";
		}

		cout << endl;
	}
	cout << "PS = " << PS << endl;
	cout << "PC = " << PC << endl;
	cout << "TC = " << TC << endl;


	cout << endl;
}

void output2(string com, string operand1, string operand2)
{
	cout << "\t============Step2============" << endl;
	TC = 2;
	for (int i = 1; i <= 2; i++)
	{
		cout << "R" << i << " = ";
		for (int j = 0; j < 6; j++) {
			cout << registr[i - 1].substr(j * 5, 5) << " ";
		}
		cout << endl;;
	}
	cout << "PS = " << PS << endl;
	cout << "PC = " << PC << endl;
	cout << "TC = " << TC << endl;

	cout << endl << endl;
}

string to_bin(string num)
{
	int res = stoi(num);
	string res2 = "";
	while (res)
	{
		res2 += to_string((res % 2));
		res /= 2;
	}
	while (30 - res2.size())
	{
		res2.insert(0, "0");
	}
	return res2;
}

string negative_number(string num)
{
	string res = "";
	int  k = 1;
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == '1')
			res.push_back('0');
		else
			res.push_back('1');
	}
	if (res[res.size() - 1] == '1')
		res[res.size() - 1] = '2';

	else
		res[res.size() - 1] = '1';
	int i = res.size() - 1;
	while (res[i] == '2')
	{
		if (res[i - 1] == '1')
			res[i - 1] = '2';
		else
			res[i - 1] = '1';

		res[i] = '0';
		i--;
	}
	return res;
}

string convert_num(string num)
{
	string res;
	
	if (abs(stoi(num)) < 1073741823)
	{
		if (num[0] == '-')
		{
			res = num.substr(1, num.size() - 1);
			res = to_bin(res);
			res = negative_number(res);
		}
		else
		{
			res = to_bin(num);
		}
	}
	else {
		cout << "the number is out of range" << endl;
	}

	return res;
}

void save(int reg, string num)
{
	registr[reg] = num;
}

void proceed(string command)
{
	vector<string> vec = { "" };
	string s = { "" };
	string s1 = { "" };
	string s2 = { "" };
	string c;
	string white = " ";
	string comma = ",";
	int k = 0;
	
	for (int i = 0; i < command.size(); i++)
	{
		c.push_back(command[i]);
		if (c == white || c == comma)
		{
			vec.push_back("");
			c.clear();
			i++;
			k++;
			c.push_back(command[i]);
			vec[k] += c;
		}
		else
		{
			vec[k] += c;
		}
		c.clear();
	}
	if (vec[0] == "save")
	{
		sc10[vec[1][1] - '0' - 1] = stoi(vec[2]);
		s = convert_num(vec[2]);
		output(vec[0], vec[1], s);
		if (sc10[vec[1][1] - '0' - 1] < 0) {
			PS = 1;
		}
		else {
			PS = 0;
		}
		system("pause");
		save(vec[1][1] - '0' - 1, s);
		output2(vec[0], vec[1], s);
	}
	if (vec[0] == "add")
	{
		output(vec[0], vec[1], vec[2]);
		s1 = add(registr[vec[1][1] - '0' - 1], registr[vec[2][1] - '0' - 1]);
		save(vec[1][1] - '0' - 1, s1);
		
		if (sc10[vec[1][1] - '0' - 1] < 0) {
			PS = 1;
		}
		else {
			PS = 0;
		}
		
		system("pause");
		output2(vec[0], vec[1], vec[2]);
	}
}

int main()
{
	string command;
	ifstream myfile("command.txt");
	int counter = 0;
	
	if (myfile.is_open())
	{
		while (getline(myfile, command))
		{
			proceed(command);
		}
		myfile.close();
	}
	
	myfile.close();
	return 0;
}