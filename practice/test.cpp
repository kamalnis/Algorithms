#include <iostream>
#include <string>
#include<cstdio>
#include<vector>

using namespace std;
typedef vector<int> lnum;
const int base = 1000*1000*1000;
int main ()
{
  std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,4);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos);     // get from "live" to the end

  std::cout << str2 << ' ' << str3 << '\n';

  std::string s="223456789123456789";
  vector<int> a;

  for (int i=s.size(); i>0; i-=9) {
    if (i < 9)
		a.push_back (atoi (s.substr (0, i).c_str()));
	else
		a.push_back (atoi (s.substr (i-9, 9).c_str()));
  }
  cout<<"Check:"<< a[0]<<endl;
  while (a.size() > 1 && a.back() == 0)
	a.pop_back();

    printf ("%d", a.empty() ? 0 : a.back());
    for (int i=(int)a.size()-2; i>=0; --i)
	    printf ("%09d", a[i]);

cout<<endl;

  return 0;
}