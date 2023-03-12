#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<math.h>
using namespace std;
class ms
{
    public:
    int merge_sort(int *a,int p,int r)
    {
        int q;
        if(p<r)
        {
            q=floor((p+r)/2);
            merge_sort(a,p,q);
            merge_sort(a,q+1,r);
            merge(a,p,q,r);
        }
        
    }
    int merge(int *a,int p,int q,int r)
    {
            int n1,n2;
            n1=q-p+1;
            n2=r-q;
            int L[n1+1],R[n2+1];
            for(int i=1; i<=n1; i++)
                L[i]=a[p+i-1];
            for(int j=1; j<=n2; j++)
                R[j]=a[q+j];
            L[n1+1]=10000;
            R[n2+1]=10000;
            int i=1;int j=1;
            for(int k=p; k<=r; k++)
            {
                if(L[i]<=R[j])
                {
                    a[k]=L[i];
                    i=i+1;
                }
                else
                {
                    a[k]=R[j];
                    j=j+1;
                }
            }
            
    }

};

int main()
{
    int *A;
    int n,P,R;
    double etime;
    ofstream op;
    ifstream ip;
    clock_t st,et;
    ms obj;
    st=clock();
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    A=new int[n];
    srand((long int)clock());
    op.open("MyMerge.txt");
    for(int i=1; i<=n; i++)
            op<<rand()%50<<"\t";
    op.close();
    ip.open("MyMerge.txt");
    cout<<"Before sorting..."<<endl;
    for(int i=1; i<=n; i++)
    {
        ip>>A[i];
        cout<<A[i]<<"\t";
    }
    ip.close();
    P=1; R=n;
    obj.merge_sort(A,P,R);
    cout<<"\nElements after sorting..."<<endl;
    for(int i=1; i<=n; i++)
            cout<<A[i]<<"\t";
    op.open("MyMerge.txt");
    for(int i=1;i<=n;i++)
        op<<A[i]<<"\t";
    op.close();
    et=clock();
    etime=(double)(et-st)/CLOCKS_PER_SEC;
    cout<<"\nExecution time: "<<etime<<" seconds";
    return 0;

} 
/* USING ARRAY
int main()
{
    int n,A[100],P,R,Q;
    
    ms obj;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    cout<<"\nEnter the array elements: ";
    for(int i=1; i<=n; i++)
    {
        cin>>A[i];
    }
    P=1; R=n;
    obj.merge_sort(A,P,R);
    cout<<"Elements after sorting..."<<endl;
    for(int i=P; i<=R; i++)
            cout<<A[i]<<" ";
    return 0;
    
}
*/



