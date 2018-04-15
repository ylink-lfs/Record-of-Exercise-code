//No solution on the internet...Question itself remains unclear.I stuck in the scientific format.Just a record.
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

const double eps = 1e-8;
#define Equ(a, b) ((fabs((a) - (b))) < (eps))
inline double More(double a, double b) { return a - b > eps ? a : b; }
using namespace std;

string modify_preorder_zero(string);

int main(void)
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	string str1, str2;
	int e_position;
	double res1, res2, res_final;
	while (cin >> str1 >> str2)
	{
		if ((e_position = str1.find("e")) != string::npos || (e_position = str1.find("E")) != string::npos)
		{
			string bottom_str = str1.substr(0, e_position - 1);
			string top_str = str1.substr(e_position + 1, str1.size() - e_position);
			string raw1 = modify_preorder_zero(bottom_str);
			int upper_num = stoi(top_str);
			double bottom_num;
			if (raw1.size() == 0)
			{
				bottom_num = 0;
			}
			else
			{
				if (raw1[0] == '.')
				{
					raw1.insert(raw1.begin(), '0');
					bottom_num = stod(raw1);
				}
				else
				{
					bottom_num = stod(raw1);
				}
			}
			res1 = pow(bottom_num, upper_num);
		}
		else
		{
			string raw1 = modify_preorder_zero(str1);
			if (raw1.size() == 0)
			{
				res1 = 0;
			}
			else
			{
				if (raw1[0] == '.')
				{
					raw1.insert(raw1.begin(), '0');
					res1 = stod(raw1);
				}
				else
				{
					res1 = stod(raw1);
				}
			}
		}

		if ((e_position = str2.find("e")) != string::npos || (e_position = str2.find("E")) != string::npos)
		{
			string bottom_str = str2.substr(0, e_position);
			string top_str = str2.substr(e_position + 1, str2.size() - e_position);
			string raw2 = modify_preorder_zero(bottom_str);
			int upper_num = stoi(top_str);
			double bottom_num;
			if (raw2.size() == 0)
			{
				bottom_num = 0;
			}
			else
			{
				if (raw2[0] == '.')
				{
					raw2.insert(raw2.begin(), '0');
					bottom_num = stod(raw2);
				}
				else
				{
					bottom_num = stod(raw2);
				}
			}
			upper_num = pow(10, upper_num);
			res2 = bottom_num * upper_num;
		}
		else
		{
			string raw2 = modify_preorder_zero(str2);
			if (raw2.size() == 0)
			{
				res2 = 0;
			}
			else
			{
				if (raw2[0] == '.')
				{
					raw2.insert(raw2.begin(), '0');
					res2 = stod(raw2);
				}
				else
				{
					res2 = stod(raw2);
				}
			}
		}
		

		if (Equ(res1, int(res1)) && Equ(res2, int(res2)))
		{
			cout << int(res1) + int(res2) << endl;
		}
		else
		{			
			res_final = res1 + res2;

		
			cout.setf(ios::scientific);

			
			cout << res_final << endl;
			cout.unsetf(ios::scientific);


		}
	}
	return 0;
}

string modify_preorder_zero(string st)
{
	string res = st;
	while (res.size() > 0 && *res.begin() == '0')
	{
		res.erase(res.begin());
	}
	return res;
}