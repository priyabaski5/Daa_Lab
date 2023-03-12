#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
class qs
{
    public:
    void quicksort(int b[],int p,int r)
    {
        int q;
        if(p<r)
        {
            q=partition(b,p,r);
            quicksort(b,p,q-1);
            quicksort(b,q+1,r);
        }
    }
    int partition(int b[],int p,int r)
    {
        int x,i;
        x=b[r];
        i=p-1;
        for(int j=p; j<=r-1; j++)
        {
            if(b[j]<=x)
            {
                i=i+1;
                swap(b[i],b[j]);
            }
            
        }
        swap(b[i+1],b[r]);
        return i+1;
    }

};
int main()
{
    int n,A[100],P,R;
    double etime;
    clock_t st,et;
    ofstream op;
    ifstream ip;
    qs obj1;
    st = clock();
    cout<<"\nEnter the size: ";
    cin>>n;
    srand((long int)clock());
    op.open("Myquick.txt");
    for(int i=1; i<=n; i++)
        op<<rand()%60<<"\t";
    op.close();
    cout<<"\nBefore sorting: "<<endl;
    ip.open("Myquick.txt");
    for(int i=1; i<=n; i++)
    {
        ip>>A[i];
        cout<<A[i]<<"\t";
    }
    ip.close();
    P=1; R=n;
    obj1.quicksort(A,P,R);
    cout<<"\nArray elements after sorting..."<<endl;
    for(int k=1; k<=n; k++)
        {
            cout<<A[k]<<"\t";
        }
    op.open("Myquick.txt");
    for(int i=1; i<=n; i++) 
        op<<A[i]<<"\t";
    op.close();
    et=clock();
    etime=(double)(et-st)/CLOCKS_PER_SEC;
    cout<<"\nExecution time: "<<etime<<" Seconds";
    return 0;
}
/*USING ARRAY
int main()
{
    int n,A[100],P,R;
    
    qs obj1;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    cout<<"\n Enter the array elements: ";
    for(int i=1; i<=n; i++)
    {
        cin>>A[i];
    }
    P=1; R=n;
    obj1.quicksort(A,P,R);
    cout<<"\n Array elements after sorting...";
    for(int k=1; k<=n; k++)
        {
            cout<<" "<<A[k];
        }
    return 0;
    
}
*/
