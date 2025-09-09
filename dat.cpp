#include<iostream>
#include<vector>
using namespace std;
 int main(){
int n;
 
    cout<<"number of terms"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"elements "<<endl;
    for(int i=0;i<n;i++)
     {
      cin>>arr[i];

    }
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    int min=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
vector<int> data(max+1);
    for(int i=0;i<n;i++)
    {
        data[arr[i]]++;
    }
    cout<<"frequency of elements"<<endl;
    for(int i=0;i<=max;i++)
    {
        if(data[i]!=0)
        {
            cout<<i<<" "<<data[i]<<endl;
        }
    }
   cout<<"missing elements"<<endl;
   for(int i=min;i<=max;i++)
   {
       if(data[i]==0)
       {
           cout<<i<<endl;
       }
   }
    
        return 0;
 }