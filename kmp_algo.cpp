#include <bits/stdc++.h>
using namespace std;

void compute_lps(int *lps,string pat)
{
	int prev =0;
	int i=1;
	lps[0] = 0;

	while(i<pat.size())
	{
		if(pat[prev]==pat[i])
		{
			prev++;
			lps[i] = prev;
			i++;
		}
		else
		{
			if(prev == 0)
			{
				lps[i]=0;
				i++;
			}
			else
			{
				prev = lps[prev-1];
			}
		}
	}
}

void KMP_search(string pat,string s)
{
	int lps[pat.size()];
	compute_lps(lps,pat);	
	int i=0;
	int j=0;

	while(i<s.size())
	{
		cout<<"i: "<<i<<" j: "<<j<<endl;
		if(pat[j]==s[i])
		{
			i++;
			j++;
		}
		else
		{
			if(j==0)
				i++;
			else
				j = lps[j-1];
		}

		if(j==pat.size())
		{
			cout<<"Matched at index : "<<i<<endl;
			j= lps[j-1];
		}
	}
}

int main()
{
	string a;
	a = "ABABDABACDABABCABAB";
	string pat;
	pat = "ABABCABAB";

	int A[pat.size()];
	compute_lps(A,pat);

	cout<<A[pat.size()-1]<<endl;

	KMP_search(pat,a);
}