#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
	int t;
	cin >> t;
	string number_digit[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	string number_ones[11] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	string mill[5] = {"", "Thousand", "Million", "Billion"};
	while (t--)
	{
		ll num;
		cin >> num;
		int track = 0;
		string num_in_words;
		if (num == 0)
		{
			cout << "Zero" << endl;
		}
		else{
			while (num != 0)
			{
				if (track != 0 && ((num/100)%10 *1000+(num/10)%10 *10 + num%10)!=0)
					num_in_words.insert(0, mill[track] + " ");
				ll temp = num;
				if ((temp / 10) % 10 == 1)
				{
					num_in_words.insert(0, number_digit[10 + temp % 10] + " ");
				}
				else
				{
					if (temp % 10 != 0)
						num_in_words.insert(0, number_digit[temp % 10] + " ");
					if ((temp / 10) % 10 != 0)
						num_in_words.insert(0, number_ones[(temp / 10) % 10] + " ");
				}
				if ((temp / 100) % 10 != 0)
				{
					num_in_words.insert(0, "Hundred ");
					num_in_words.insert(0, number_digit[(temp / 100) % 10] + " ");
				}
				track++;
				num /= 1000;
			}
			cout << num_in_words << endl;
		}
	}
}