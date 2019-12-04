#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
template<typename T>
inline void sortData(vector<T>&list)
{
    sort(list.begin(),list.end(),
    [](T a,T b)
    {
        if(a < b)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    });

}
int32_t main()
{
    vector<int>intList{9,83,3,0,-9,29,20,10,-45};
    vector<double>doubleList{98.4,89.23,99.1,88.2,0.0001};

    sortData<double>(doubleList);
    sortData<int>(intList);

    for(int i=0;i<intList.size();i++)
    {
        cout<<intList[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<doubleList.size();i++)
    {
        cout<<doubleList[i]<<" ";
    }
    cout<<endl;
}