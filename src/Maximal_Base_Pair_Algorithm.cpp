#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <algorithm>


#define MAX_N 1001

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int n;
string A;
int dp[MAX_N][MAX_N];


bool complementary(char X, char Y)
{
    return ((X == 'A' && Y == 'U') || (X == 'U' && Y == 'A') || (X == 'C' && Y == 'G') || (X == 'G' && Y == 'C'));
}

int Maximal_Base_Pair(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    
    if (i >= j-3)
    {
        dp[i][j] = 0;
        return 0;
    }
    
    int ret = 0;
    ret = max(ret, Maximal_Base_Pair(i + 1, j));
    ret = max(ret, Maximal_Base_Pair(i, j - 1));
    if (complementary(A[i], A[j])) ret = max(ret, Maximal_Base_Pair(i + 1, j - 1) + 1);
    for (int k=i+1;k<j;k++)
    {
        ret = max(ret, Maximal_Base_Pair(i, k) + Maximal_Base_Pair(k + 1, j));
    }
    
    dp[i][j] = ret;
    return ret;
}

int Maximal_Base_Pair_Algorithm()
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            dp[i][j] = -1;
        }
    }
    
    return Maximal_Base_Pair(0, n - 1);
}

string get_bracketing(int i, int j)
{
    if (i == j) return A.substr(i, 1);
    if (i > j) return "";
    
    if (Maximal_Base_Pair(i, j) == Maximal_Base_Pair(i + 1, j))
    {
        string left = A.substr(i, 1);
        return left + get_bracketing(i + 1, j);
    }
    
    if (Maximal_Base_Pair(i, j) == Maximal_Base_Pair(i, j - 1))
    {
        string right = A.substr(j, 1);
        return get_bracketing(i, j - 1) + right;
    }
    
    if (complementary(A[i], A[j]) && Maximal_Base_Pair(i, j) == Maximal_Base_Pair(i+1, j-1) + 1)
    {
        string left = A.substr(i, 1);
        string right = A.substr(j, 1);
        return "(" + left + get_bracketing(i+1, j-1) + right + ")";
    }
    
    for (int k=i+1;k<j;k++)
    {
        if (Maximal_Base_Pair(i, j) == Maximal_Base_Pair(i, k) + Maximal_Base_Pair(k + 1, j))
        {
            return get_bracketing(i, k) + get_bracketing(k + 1, j);
        }
    }
    
    return "FAIL"; // should never happen!
}

int main()
{
    
    //A = "GCAUAUUACUUUAAAAGCAUAUUACAAUCGAUCCGCAUAUUACGCAUAUUACUUUAAAAGCAUAUUACAAUCGAUCCGCAUAUUACCCGAUCCGCAUAUUACGCAUAUUACUUUAAAAGCAUAUUACAAUCGAUCCGCAUAUUACCGCAUAUUACUUUAAAAGCAUAUUACAAUCGAUCCGCAUAUUACGCAUAUUACUUUAAAAGCAUAUUACAAUCGAUCCGCAUAUUACCGAUCCGCAUAUUACGCAUAUUACUUUAAAAGCAUAUUACAAUCGAUCCGCAUAUUACCGCAUAUUACUUUAAAAGCAUAUUACAAUCGAUCCGCAUAUUAC";
    A = "AGGCCUUCCU";
    n = A.length();
   
    
    printf("%d\n", Maximal_Base_Pair_Algorithm());
    cout << get_bracketing(0, A.length()-1) << endl;
    
    return 0;
}