#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include<math.h>
using namespace std;
struct msa
{
    int lm;
    int rm;
    int hs;
};
msa cross_max_subarray(int a[],int l,int m,int h)
{
    msa p;
    int ls=-10000;
    int rs=-10000;
    int sum=0;
    for(int i=m; i>=l; i--)
    {
        sum = sum+a[i];
        if(sum>ls)
        {
            ls=sum;
            p.lm=i;
        }
    }
    
    sum=0;
    for(int j=m+1; j<=h; j++)
    {
        sum = sum+a[j];
        if(sum>rs)
        {
            rs=sum;
            p.rm=j;
       }
     }
     p.hs=ls+rs;
     return p;

}

msa max_subarray(int *a,int l,int h)
{
    msa left,right,cross,low;
    if(h==l)
    {
        low.lm=l;
        low.rm=h;
        low.hs=a[l];
        return low;
    }
    else
    {
        int mid=(l+h)/2;
        left=max_subarray(a,l,mid);
        right=max_subarray(a,mid+1,h);
        cross=cross_max_subarray(a,l,mid,h);
        if(left.hs>=right.hs && left.hs>=cross.hs)  
            return left;
        else if(right.hs>=left.hs && right.hs>=cross.hs)  
            return right;
        else
            return cross;
    }
}


int main()
{
    
    int n,*b;
    ofstream outp;
    ifstream ip;
    clock_t st,et;
    double exet;
    st=clock();
    cout<<"\nEnter the size: ";
    cin>>n;
    b=new int[n];
    srand((long int)clock());
    outp.open("Maxfile.txt");
    for(int i=0; i<n; i++)
        outp<<rand()%50<<"\t";
    outp.close();
    ip.open("Maxfile.txt");
    for(int i=0; i<n; i++)
    {
        ip>>b[i];
        if(b[i]%2==0)
            b[i]=-b[i];
        cout<<b[i]<<"\t";
    }
    ip.close();
    msa mat=max_subarray(b,1,n);
    cout<<"\nMax left: "<<mat.lm;
    cout<<"\nMax right: "<<mat.rm;
    cout<<"\nMax sum: "<<mat.hs;
    outp.open("Maxfile.txt");
    outp<<"\nMax left: "<<mat.lm;
    outp<<"\nMax right: "<<mat.rm;
    outp<<"\nMax sum: "<<mat.hs;
    outp.close();
    et=clock();
    exet=(double)(et-st)/CLOCKS_PER_SEC;
    cout<<"\nExecution time: "<<exet;
    return 0;
}