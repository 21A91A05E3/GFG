
D. Very Different Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya has an array ai
 of n
 integers. His brother Vasya became envious and decided to make his own array of n
 integers.

To do this, he found m
 integers bi
 (m≥n
), and now he wants to choose some n
 integers of them and arrange them in a certain order to obtain an array ci
 of length n
.

To avoid being similar to his brother, Vasya wants to make his array as different as possible from Petya's array. Specifically, he wants the total difference D=∑ni=1|ai−ci|
 to be as large as possible.

Help Vasya find the maximum difference D
 he can obtain.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤100
) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains two integers n
 and m
 (1≤n≤m≤2⋅105
).

The second line of each test case contains n
 integers ai
 (1≤ai≤109
). The third line of each test case contains m
 integers bi
 (1≤bi≤109
).

It is guaranteed that in a test, the sum of m
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the maximum total difference D
 that can be obtained.

Example
inputCopy
9
4 6
6 1 2 4
3 5 1 7 2 3
3 4
1 1 1
1 1 1 1
5 5
1 2 3 4 5
1 2 3 4 5
2 6
5 8
8 7 5 8 2 10
2 2
4 1
9 6
4 6
8 10 6 4
3 10 6 1 8 9
3 5
6 5 2
1 7 9 7 2
5 5
9 10 6 3 7
5 9 2 3 9
1 6
3
2 7 10 1 1 5
outputCopy
16
0
12
11
10
23
15
25
7
Note
In the first example, Vasya can, for example, create the array (1,5,7,2)
. Then the total difference will be D=|6−1|+|1−5|+|2−7|+|4−2|=5+4+5+2=16
.

In the second example, all the integers available to Vasya are equal to 1, so he can only create the array (1,1,1)
, for which the difference D=0
.

In the third example, Vasya can, for example, create the array (5,4,3,2,1)
. Then the total difference will be D=|1−5|+|2−4|+|3−3|+|4−2|+|5−1|=4+2+0+2+4=12
.

===================================================================================================================================
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	long long int n,f,u,o,d,s=0;
	while(t--)
	{
		cin>>n>>f>>u>>o;
		long long int a[n];
		s=0;
		for(long long int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		d=a[0]-0;
		s+=min(d*u,o);
		
		for(long long int i=1;i<n;i++)
		{
			d=a[i]-a[i-1];
			s+=min(d*u,o);
			
		}
		if(s<f)cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
}
