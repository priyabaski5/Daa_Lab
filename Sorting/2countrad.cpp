#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
class crs
{
    public:
    //a[] given array, b[] resultant array. k range
    void counting_sort(int a[],int b[],int n,int k)
    {
        int c[k+1];
        for(int i=0; i<=k; i++)
            c[i]=0;
        for(int j=0; j<n; j++)
            c[a[j]]=c[a[j]]+1;
        for(int i=1; i<=k; i++)
            c[i]=c[i]+c[i-1];
        for(int j=n-1; j>=0; j--)
        {
            b[c[a[j]]-1]=a[j];
            c[a[j]]--;
        }
        for(int i=0; i<n; i++)
            a[i]=b[i];
    }
    void radix_sort(int a[],int b[],int n,int d, int k)
    {
        for(int j=1; j<=d; j++)
            counting_sort(a,b,n,k);
    }
    int max(int a[],int n)
    {
        int x=a[0];
        for(int i=1; i<n; i++)
        {
            if(a[i]>x)
                x=a[i];
        }
        return x;
    }
};

int main()
{
    crs obj3;
    int n,digit,m;
    double etime;
    ofstream op;
    ifstream ip;
    clock_t st,et;
    st=clock();
    cout<<"\nEnter the size: ";
    cin>>n;
    int A[n],B[n];
    srand((long int)clock());
    op.open("countradix.txt");
    for(int i=0; i<n; i++)
        op<<rand()%999<<"\t";
    op.close();

    ip.open("countradix.txt");
    cout<<"\nBefore sorting: "<<endl;
    for(int i=0; i<n; i++)
    {
        ip>>A[i];
        cout<<A[i]<<"\t";
    }
    ip.close();
    m = obj3.max(A,n);
    obj3.counting_sort(A,B,n,m);
    /*for radix sort 
            obj3.radix_sort(A,B,n,3,m);
            */
    cout<<"\nAfter sorting:"<<endl;
    for(int i=0; i<n; i++)
        cout<<B[i]<<"\t";
    op.open("countradix.txt");
    for(int i=0;i<n;i++)
    {
        op<<B[i]<<"\t";
    }
    op.close();
    et=clock();
    etime=(double)(et-st)/CLOCKS_PER_SEC;
    cout<<"\nExecution time: "<<etime<<" seconds";
    return 0;
}

/*
int main()
{
    int n,range,d;
    crs obj3;
    cout<<"\nEnter the number of elements: ";
    cin>>n;
    int A[n],B[n];
    cout<<"\nEnter the array elements: ";
    for(int i=0; i<n; i++)
        cin>>A[i];
    cout<<"\nEnter the highest range: ";
    cin>>range;
   
    cout<<"\nEnter digits of the highest range: ";
    cin>>d;
 
    
    obj3.radix_sort(A,B,n,d,range);
    cout<<"\nAfter sorting: ";
    for(int i=0; i<n; i++)
        cout<<B[i]<<" ";

}
*/
