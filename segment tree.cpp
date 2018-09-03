#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <algorithm>
#include <cmath>
#include <utility>
#include <string>
#include <cstring>
#include <deque>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ull unsigned long long int
int tree[100000];
int n;
void build(int arr[])
{
    for(int i=n; i<2*n; i++)
    {
        tree[i]=arr[i-n];
    }
    for(int i= n-1; i>=1; i--)
    {
        tree[i]=tree[2*i]+tree[2*i +1] ;  /// change here for specific problem i.e for range- sum,max,min etc.
    }
}
int query(int l, int r)  // l is included but r is excluded
{
    int ans=0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
        if(l&1)
            ans+=tree[l++];
        if(r&1)
            ans+=tree[--r];
    }
    return ans;
}
void modify(int index, int value)
{
    tree[index+n]=value;
    for(int i=index+n; i>1; i>>=1)
        tree[i>>1]=tree[i]+tree[i^1] ;  // toggle the last bit to handle left and right child case, i.e if tree[i] is left child then tree[i^1] will become right child and vice versa.

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    build(arr);
    cout<<query(1,3); // index [2,5)
    modify(1,3); // change value of index [1] to 3
    cout<<endl<<query(1,3);
    return 0;
}
