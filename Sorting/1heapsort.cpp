#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
class hs
{
    private:
    int heapsize;
    public:
    
    int heapsort(int a[],int n)
    {
       buildheap(a,n-1);
        for(int i=n-1; i>=1; i--)
        {
            
            int temp=a[0];
            a[0]=a[i];
            a[i]=temp;
            heapsize=heapsize-1;
            maxheap(a,0);
        }
    }
    int buildheap(int a[],int n)
    {
        heapsize=n;
        int m=floor(n/2);
        for(int i=m; i>=0; i--)
            maxheap(a,i);
    }
    int maxheap(int a[],int i)
    {
        int temp,x;
        int l,r,large;
        l=(2*i)+1;
        r=(2*i)+2;
        if(l<=heapsize && a[l]>a[i])
          {  large=l;}
        else large = i;
        if(r<=heapsize && a[r]>a[large])
         {   large=r;}
        if(large!=i)
        {
            int temp=a[i];
a[i]=a[large];
a[large]=temp;
            maxheap(a,large);
        }
    }
    };

    int main()
    {
        hs t1;
        int n,i;
        ofstream op;
        ifstream ip;
        double exet;
        clock_t st,et;
        
        st = clock();
        int *a;
        cout<<"\nEnter size: ";
        cin>>n;
        a=new int[n];
        srand((long int)clock());
        op.open("hsort.txt");
        for(int i=0; i<n; i++)
         {   op<<rand()%50<<"\t";}
        op.close();
       
        ip.open("hsort.txt");
        cout<<"\nbefore sorting: "<<endl;
        for(int i=0; i<n; i++)
        {

            ip>>a[i];
            cout<<a[i]<<"\t";
        }
        cout<<endl;
        ip.close();
        t1.heapsort(a,n);
        cout<<"\nAfter sorting: "<<endl;
        for(int i=0; i<n; i++)
          {  cout<<a[i]<<"\t";}
        op.open("hsort.txt");
        for(int i=0;i<n;i++)
        {
        op<<a[i]<<"\t";
        }
        op.close();
        et=clock();
        exet=(double)(et-st)/CLOCKS_PER_SEC;
        cout<<endl;
        cout<<"\nExecution time: "<<exet<<" secs";
        delete(a);
        return 0;
    }
