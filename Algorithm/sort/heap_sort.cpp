#include <QCoreApplication>
#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
#include <memory>
using namespace std;
void swap(int a[],int x, int y)
{
    int temp = a[y];
    a[y] = a[x];
    a[x] = temp;
}
void adjustheap(int a[],int i,int n)
{
    int temp=a[i];
    for(int k=2*i+1;k<n;k=2*k+1)
    {
        if(k+1<n&&a[k]<a[k+1])
            k++;
        if(a[k]>temp)
        {
            swap(a,i,k);
            i=k;
        }
        else
            break;
    }
}
void H_sort(int a[], int n)
{
    for(int i=n/2-1;i>=0;i--)
        adjustheap(a,i,n);
    for(int j=n-1;j>0;j--)
    {
        swap(a,0,j);
        adjustheap(a,0,j);
    }
}
void topk(int a[],int n,int res[], int k)
{
    for(int i=0;i<k;i++)
        res[i]=a[i];
    for(int i=k/2-1;i>=0;i--)
        adjustheap(res,i,k);
    for(int i=k;i<n;i++)
    {
        if(res[0]<=a[i])
            continue;
        res[0]=a[i];
        adjustheap(res,0,k);
    }
    for(int j=k-1;j>0;j--)
    {
        swap(res,0,j);
        adjustheap(res,0,j);
    }
}
class AA
{
    AA(int x):i(x){}
    int i;

    AA & operator=(AA&);
    AA(const AA&);
public:
    static AA& instance()
    {
        static AA b(4);
        return b;
    }
    int getVaule() {return i;}
    void setVaule(int x)
    {
        i=x;
    }
};

int main(int argc, char *argv[])
{   
    QCoreApplication a(argc, argv);
//    int b[]={9,5,8,6,7,3};
//    H_sort(b,sizeof (b)/sizeof (int));
//    for(int i=0;i<6;i++)
//        cout<<b[i]<<" ";
//    cout<<endl;
//    int res[6];
//    int k=4;
//    topk(b,sizeof (b)/sizeof (int),res,k);
//    for(int i=0;i<k;i++)
//        cout<<res[i]<<" ";
//    cout<<endl;
//    AA& ff=AA::instance();
//    cout<<ff.getVaule()<<endl;
//    AA& c=AA::instance();
//    c.setVaule(7);
//    cout<<ff.getVaule()<<endl;
    char *p=new char[20];
    cin>>p;
    cout<<p<<endl;
    
    
    return a.exec();
}
