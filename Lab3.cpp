#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<float> reg = { 0,0,0,0,0,0,0,0 };

string neg_num(string num)
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

string to_bin(string num)
{
	int res = stoi(num);
	string res2 = "";
	if (res == 0)
	{
		res2 = "0";
	}
	else {
		while (res)
		{
			res2 += to_string((res % 2));
			res /= 2;
		}
	}
	reverse(res2.begin(), res2.end());
	return res2;
}

string to_bin_fract(string num, int n)
{
	int x2;
	float res = stof(num);
	string res2 = "";
	while (n)
	{
		res *= 2;
		x2 = (int)res;
		res2 += to_string(x2);
		res -= x2;
		n--;
	}
	reverse(res2.begin(), res2.end());
	return res2;
}

string convert_num(string num)
{
	string res;
	if (abs(stoi(num)) < 16383)
	{
		if (num[0] == '-')
		{
			res = num.substr(1, num.size() - 1);
			res = to_bin(res);
			res = neg_num(res);
		}
		else
		{
			res = to_bin(num);
		}
	}
	return res;
}

string from_fl_to_754(string sign, float num)
{
	int dec;
	float fract;
	string fract_s, mantis, res = "", newdec = "";
	num = abs(num);
	dec = (int)num;
	fract = num - dec;
	newdec = convert_num(to_string(dec));
	int exp = 0;
	if (to_string(dec) == "0")
	{
		int i = 2;
		while (to_string(fract)[i] == '0') { exp--; i++; }
		exp--;
	}
	else { exp = newdec.size() - 1; }
	int m = pow(2, 13) - 1 + exp;
	string chr_to_bin = convert_num(to_string(m));
	string  chr_ad;
	for (int i = 0; i < 14 - chr_to_bin.size(); i++) {
		chr_ad.push_back('0');
	}
	chr_to_bin = chr_ad + chr_to_bin;
	fract_s = to_bin_fract(to_string(fract), 15 - exp);
	mantis = newdec.erase(0, 1) + fract_s;
	while (mantis.size() > 15) { mantis.pop_back(); }
	res = sign + "|" + chr_to_bin + "|" + mantis;
	return res;
}

string output(float num)
{
	if (num == 0)
		return "0|00000000000000|000000000000000";
	string sign;
	string res;
	if (num >= 0) { sign = "0"; }
	else { sign = "1"; }
	res = from_fl_to_754(sign, num);
	return res;
}

void output_reg(vector<float> reg) {
	cout << "register status :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << "r" << i + 1 << ": " << output(reg[i]) << endl;
	}
	cout << endl;
	system("pause");
}

void output_cond(float x, float y) {
	
	cout << endl;
	cout << "0/1|11111111111110|000000000000000" << "  :  " << "max 16382.99609375/min -16382.99609375 " << endl;
	cout << "0/1|11111111111111|000000000000000" << "  :  " << "+/-inf " << endl;
	cout << "1|11111111111111|010100100100100" << "  :  " << "NaN " << endl;
	cout << "0|00000000000000|000000000000001" << "  :  " << "0.000030517578125 " << endl << endl;
	cout << "####################################################################" << endl;;
	std::cout << "Number x : " << x << "\t\tIEEE 754 : " << output(x) << endl;
	std::cout << "Number y : " << y << "\t\tIEEE 754 : " << output(y) << endl;
	cout << "####################################################################" << endl;;
	cout << "\t\tformula : sin(exp(x) + 2) * cos(y)" << endl;

}

int main()
{
	float x, y;
	cout << "Enter a number x: ";
	cin >> x;
	cout << "Enter a number y: ";
	cin >> y;
	if (abs(x) > 16382.99609375 || abs(y) > 16382.99609375)
	{
		cout << "too big numbers " << endl;
		return 0;
	}
	if (abs(x) < 0.000030517578125 || abs(y) < 0.000030517578125)
	{
		cout << "too small numbers" << endl;
		return 0;
	}
	output_cond(x, y);
	reg[0] = x;
	cout << "x in r1 : " << endl;
	output_reg(reg);
	reg[1] = exp(reg[0]);
	cout << "exp(x) in r2 : " << endl;
	output_reg(reg);
	reg[2] = reg[1] + 2;
	cout << "exp(x) + 2 in r3 :" << endl;
	output_reg(reg);
	reg[3] = sin(reg[2]);
	cout << "sin(exp(x) + 2) in r4 :" << endl;
	output_reg(reg);
	reg[4] = y;
	cout << "y in r5 :" << endl;
	output_reg(reg);
	reg[5] = cos(reg[4]);
	cout << "cos(y) in r6 :" << endl;
	output_reg(reg);
	reg[6] = reg[3] * reg[5];
	cout << "sin(exp(x) + 2) * cos(y) in r7 :" << endl;
	output_reg(reg);
	return 0;
}