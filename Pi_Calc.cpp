#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

#define base 10
#define ll long long

using namespace std;

class Unsigned_Float;
int precision = 0;

int makeLengthEqual(vector<int> &x, vector<int> &y)
{
	int n = x.size();
	int m = y.size();

	int more_zeros = n - m;

	while (more_zeros > 0)
	{
		y.push_back(0);
		more_zeros--;
	}

	while (more_zeros < 0)
	{
		x.push_back(0);
		more_zeros++;
	}

	return x.size();
}
class Unsigned_Float
{
public:
	vector<int> digits;
	int power;
	Unsigned_Float()
	{
		power = 0;
	}

	friend Unsigned_Float operator+(Unsigned_Float a, Unsigned_Float b)
	{
		vector<int> x;
		vector<int> y;
		int zeros_to_append = a.power - b.power;
		vector<int> ans;
		int d_point = max(a.power, b.power);
		for (int i = 0; i < zeros_to_append; i++)
		{
			y.push_back(0);
		}

		for (int i = 0; i < b.digits.size(); i++)
		{
			y.push_back(b.digits[i]);
		}

		for (int i = 0; i < -zeros_to_append; i++)
		{
			x.push_back(0);
		}

		for (int i = 0; i < a.digits.size(); i++)
		{
			x.push_back(a.digits[i]);
		}

		int n = x.size(), m = y.size();
		int i = 0, j = 0, carry = 0, sum = 0;
		int temp;
		while (i < n && j < m)
		{
			temp = x[i] + y[j] + carry;
			sum = temp % base;
			carry = (sum < temp) ? 1 : 0;
			ans.push_back(sum);
			i++;
			j++;
		}
		while (i < n)
		{
			temp = x[i] + carry;
			sum = temp % base;
			carry = (sum < temp) ? 1 : 0;
			ans.push_back(sum);
			i++;
		}
		while (j < m)
		{
			temp = y[j] + carry;
			sum = temp % base;
			carry = (sum < temp) ? 1 : 0;
			ans.push_back(sum);
			j++;
		}
		if (carry != 0)
		{
			ans.push_back(carry);
		}

		Unsigned_Float Actual_Ans;
		Actual_Ans.digits = ans;
		Actual_Ans.power = d_point;

		return Actual_Ans;
	}

	friend Unsigned_Float operator-(Unsigned_Float a, Unsigned_Float b)
	{
		vector<int> ans;
		int zeros_to_append = a.power - b.power;
		vector<int> x;
		vector<int> y;
		for (int i = 0; i < -zeros_to_append; i++)
		{
			x.push_back(0);
		}

		for (int i = 0; i < a.digits.size(); i++)
		{
			x.push_back(a.digits[i]);
		}

		for (int i = 0; i < zeros_to_append; i++)
		{
			y.push_back(0);
		}

		for (int i = 0; i < b.digits.size(); i++)
		{
			y.push_back(b.digits[i]);
		}

		int n = x.size(), m = y.size();
		int carry = 0, diff = 0, i = 0, j = 0;

		while (j < m)
		{
			int val = x[i] - y[j] + carry;
			if (val < 0)
			{
				ans.push_back(base + val);
				carry = -1;
			}
			else
			{
				ans.push_back(val);
				carry = 0;
			}

			i++;
			j++;
		}

		while (i < n)
		{
			int val = x[i] + carry;
			if (val < 0)
			{
				ans.push_back(base + val);
				carry = -1;
			}
			else
			{
				ans.push_back(val);
				carry = 0;
			}
			i++;
		}

		Unsigned_Float retVal;
		retVal.digits = ans;
		retVal.power = max(a.power, b.power);

		return retVal;
	}
	friend Unsigned_Float operator*(Unsigned_Float a, Unsigned_Float b)
	{
		Unsigned_Float pro;
		while (a.digits.size() < b.digits.size())
		{
			a.digits.push_back(0);
		}
		while (b.digits.size() < a.digits.size())
		{
			b.digits.push_back(0);
		}
		if (a.digits.size() == 1)
		{
			int temp_pro = a.digits[0] * b.digits[0];
			if (temp_pro % base != 0 || temp_pro / base != 0)
			{
				pro.digits.push_back(temp_pro % base);
			}
			if (temp_pro / base != 0)
			{
				pro.digits.push_back(temp_pro / base);
			}
		}
		else
		{
			int n = a.digits.size();
			Unsigned_Float num1l, num1r, num2l, num2r;
			int i;
			for (i = 0; i < n / 2; i++)
			{
				num1r.digits.push_back(a.digits[i]);
				num2r.digits.push_back(b.digits[i]);
			}
			for (; i < n; i++)
			{
				num1l.digits.push_back(a.digits[i]);
				num2l.digits.push_back(b.digits[i]);
			}
			Unsigned_Float lp, mp, rp;
			for (i = 0; i < n / 2; i++)
			{
				lp.digits.push_back(0);
				mp.digits.push_back(0);
			}
			for (; i < 2 * (n / 2); i++)
			{
				lp.digits.push_back(0);
			}
			Unsigned_Float temp1 = num1l * num2l;
			Unsigned_Float temp2 = num1r * num2r;
			lp.digits.insert(lp.digits.end(), temp1.digits.begin(), temp1.digits.end());
			rp = temp2;
			Unsigned_Float temp4 = num1l + num1r, temp5 = num2l + num2r;
			Unsigned_Float temp3 = temp4 * temp5 - temp1 - temp2;
			mp.digits.insert(mp.digits.end(), temp3.digits.begin(), temp3.digits.end());
			pro = lp + mp + rp;
		}
		while (pro.digits.size() > 0 && pro.digits[pro.digits.size() - 1] == 0)
		{
			pro.digits.pop_back();
		}
		pro.power = a.power + b.power;
		return pro;
	}

	friend pair<Unsigned_Float, Unsigned_Float> operator/(Unsigned_Float a, Unsigned_Float b)
	{
		Unsigned_Float c;
		c.power = 0;
		int temp;
		if (!(a.power > precision + b.digits.size() + 3))
		{
			for (int i = 0; i < precision + b.digits.size() - a.power + 3; i++)
			{
				c.digits.push_back(0);
				c.power++;
			}
			temp = 0;
		}
		else
		{
			temp = precision + b.digits.size() - a.power + 3;
			temp = -temp;
		}
		for (int i = temp; i < a.digits.size(); i++)
		{
			c.digits.push_back(a.digits[i]);
			if (i < a.power)
				c.power++;
		}

		Unsigned_Float d;
		int flag = 0;
		for (flag = b.digits.size() - 1; b.digits[flag] == 0; flag--)
			;
		for (; flag >= 0; flag--)
		{
			d.digits.push_back(b.digits[flag]);
		}
		reverse(d.digits.begin(), d.digits.end());
		d.power = b.power;
		Unsigned_Float q, r;
		int k = c.digits.size();
		int l = d.digits.size();

		if (k < l)
		{
			pair<Unsigned_Float, Unsigned_Float> res;
			q.digits.push_back(0);
			res.first = q;
			res.second = a;
			return res;
		}

		for (int i = 0; i < k; i++)
		{
			r.digits.push_back(c.digits[i]);
		}
		r.digits.push_back(0);

		for (int i = 0; i <= k - l; i++)
		{
			q.digits.push_back(0);
		}

		for (int i = k - l; i >= 0; i--)
		{
			q.digits[i] = (r.digits[i + l] * base + r.digits[i + l - 1]) / d.digits[l - 1];
			if (q.digits[i] >= base)
			{
				q.digits[i] = base - 1;
			}
			int carry = 0, tmp;
			for (int j = 0; j < l; j++)
			{
				tmp = r.digits[i + j] - q.digits[i] * d.digits[j] + carry;
				div_t quorem = div(tmp, base);
				if (tmp < 0)
				{
					if (quorem.rem != 0)
					{
						r.digits[i + j] = base + quorem.rem;
						carry = quorem.quot - 1;
					}
					else
					{
						r.digits[i + j] = quorem.rem;
						carry = quorem.quot;
					}
				}
				else
				{
					r.digits[i + j] = quorem.rem;
					carry = quorem.quot;
				}
			}
			r.digits[i + l] += carry;
			while (r.digits[i + l] < 0)
			{
				carry = 0;
				for (int j = 0; j < l; j++)
				{
					tmp = r.digits[i + j] + d.digits[j] + carry;
					div_t quorem = div(tmp, base);
					if (tmp < 0)
					{
						if (quorem.rem != 0)
						{
							r.digits[i + j] = base + quorem.rem;
							carry = quorem.quot - 1;
						}
						else
						{
							r.digits[i + j] = quorem.rem;
							carry = quorem.quot;
						}
					}
					else
					{
						r.digits[i + j] = quorem.rem;
						carry = quorem.quot;
					}
				}
				r.digits[i + l] += carry;
				q.digits[i]--;
			}
		}

		int last = q.digits.size() - 1;
		while (q.digits[last--] == 0 && last >= 0)
			q.digits.pop_back();
		if (q.digits.size() == 0)
			q.digits.push_back(0);

		q.power = c.power - b.power;

		if (q.digits[0] > base / 2)
			q.digits[2]++;
		else if (q.digits[0] == base / 2)
		{
			if (q.digits[1] > base / 2 || (q.digits[1] == base / 2 && q.digits[2] % 2))
				q.digits[2]++;
		}
		q.digits[0] = 0;
		q.digits[1] = 0;

		pair<Unsigned_Float, Unsigned_Float> res;
		res.first = q;
		res.second = r;
		return res;
	}
};

Unsigned_Float sqrt(Unsigned_Float a)
{
	Unsigned_Float x0;
	x0.power = 1;
	x0.digits.push_back(5);
	x0.digits.push_back(1);
	int i = 1;
	Unsigned_Float two;
	two.power = 0;
	two.digits.push_back(2);
	while (i >> 1 <= precision)
	{
		x0 = ((x0 + (a / x0).first) / two).first;
		i = i << 1;
	}
	return x0;
}

Unsigned_Float pi()
{
	Unsigned_Float an, bn, pn;
	Unsigned_Float an1, bn1, pn1;
	Unsigned_Float two;
	two.power = 0;
	two.digits.push_back(2);
	an = sqrt(two);
	bn.power = 0;
	bn.digits.push_back(0);
	pn = two + an;
	Unsigned_Float one;
	one.power = 0;
	one.digits.push_back(1);
	unsigned long long c = 1;
	while (c >> 1 < precision)
	{
		c = c << 1;
		an1 = ((sqrt(an) + (one / sqrt(an)).first) / two).first;
		bn1 = (((one + bn) * sqrt(an)) / (an + bn)).first;
		Unsigned_Float tmp1 = one + an1;
		Unsigned_Float tmp2 = tmp1 * pn;
		Unsigned_Float tmp3 = tmp2 * bn1;
		Unsigned_Float tmp4 = one + bn1;
		pn1 = (tmp3 / tmp4).first;
		an = an1;
		bn = bn1;
		pn = pn1;
	}
	return pn;
}

int main()
{
	Unsigned_Float a;
	a.power = 0;
	a.digits.push_back(2);
	a.digits.push_back(2);
	a.digits.push_back(2);
	cin >> precision;
	// sqrt(a);
	// Unsigned_Float PI = pi();
	Unsigned_Float PI = a * a;
	cout << PI.digits.size();
	for (int i = PI.digits.size() - 1; i >= PI.digits.size() - precision - 1; i--)
	{
		if (i == PI.power - 1)
			cout << '.';
		cout << PI.digits[i];
	}
	cout << "\n";
	return 0;
}