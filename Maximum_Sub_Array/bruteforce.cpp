#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>
using namespace std;
class bf
{
    public:
    int brute_force(int a[],int n)
    {
        int si,ei,max=-9999;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=1; j<n; j++)
            {
                sum=sum+a[j];
                if(sum>max)
                {
                    max=sum;
                    si=i;
                    ei=j;
                }
            }
        }
        return max;
    }
};
int main()
{
    bf obj4;
    int *A,n;
    double ext;
    clock_t st,et;
    ofstream op;
    ifstream ip;
    st=clock();
    cout<<"Enter the size: ";
    cin>>n;
    A=new int[n]; 
    srand((long int)clock());
    
    op.open("brutefile.txt");
    for(int i=1; i<=n; i++)
        op<<rand()%50<<"\t";
    op.close();
    ip.open("brutefile.txt");
    for (int i=1; i<=n; i++)
    {
        ip>>A[i];
        if(A[i]%2==0)
        {
            A[i]=-A[i];
            
        }
        cout<<A[i]<<"\t";
            
    }
    ip.close();
    cout<<"\nMax: "<<obj4.brute_force(A,n);
    et=clock();
    ext=(double)(et-st)/CLOCKS_PER_SEC;
    cout<<"\nExecution time: "<<ext;
    delete(A);
    return 0;
}
/*
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>
using namespace std;
class bf
{
    public:
    int brute_force(int a[],int n)
    {
        int si,ei,max=-9;
        for(int i=1; i<=n; i++)
        {
            int sum=0;
            for(int j=1; j<=n; j++)
            {
                sum=sum+a[j];
                if(sum>max)
                {
                    max=sum;
                    si=i;
                    ei=j;
                }
            }
        }
        return max;
    }
};
int main()
{
    bf obj4;
    int *A,n;
    double ext;
    clock_t st,et;
    st=clock();
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"\nEnter the elements: ";
    for(int i=1; i<=n; i++)
        cin>>A[i];
    cout<<"\nMax: "<<obj4.brute_force(A,n);
    et=clock();
    ext=(double)(et-st)/CLOCKS_PER_SEC;
    cout<<"\nExecution time: "<<ext;
}
*/