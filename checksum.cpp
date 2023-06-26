#include<iostream>
#include<cmath>
using namespace std;
 
int sender(int arr[10],int n)
{
    int checksum,sum=0,i;
    cout<<"****SENDER SIDE****"<<endl;
    for(i=0;i<n;i++)
    sum+=arr[i];
    cout<<"SUM IS: "<<sum<<endl;
    checksum=~sum;    //1's complement of sum
    cout<<"CHECKSUM IS: "<<checksum<<endl;
    return checksum;
}
 
void receiver(int arr[10],int n,int sch)
{
    int checksum,sum=0,i;
    cout<<"****RECEIVER SIDE****"<<endl;
    for(i=0;i<n;i++)
        sum+=arr[i];
    cout<<"SUM IS: "<<sum<<endl;
    sum=sum+sch;
    checksum=~sum;    //1's complement of sum
    cout<<"CHECKSUM IS: "<<checksum<<endl;
}
 
int main()
{
    int n,sch,rch;
    cout<<"ENTER SIZE OF THE STRING: ";
    cin>>n;
    int arr[n];
    cout<<"ENTER THE ELEMENTS OF THE ARRAY TO CALCULATE CHECKSUM: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sch=sender(arr,n);
    receiver(arr,n,sch);
}












