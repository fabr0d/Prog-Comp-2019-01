#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool myfunction (int i,int j) { return (i>j); }
int main()
{
    int n, m;
    int temp1, temp2;
    cin >>n>>m;
    vector<int> difList;
    long long sum=0;
    for (int i=0; i<n ;i++)
    {
        cin>>temp1>>temp2;
        sum = sum + temp1;
        difList.push_back(temp1-temp2);
    }
    sort(difList.begin(),difList.end(),myfunction);
    int cont=0;
    int zzz=0;
    while(sum > m)
    {
        if(difList.size()==0)
        {
            cout<<"-1"<<endl;
            zzz=1;
            break;

        }
        sum=sum-difList.front();
        cont++;
        difList.erase (difList.begin());
    }
    if(zzz==0)
    {
        cout<<cont<<endl;
    }
}
