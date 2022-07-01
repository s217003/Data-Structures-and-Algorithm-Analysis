#include "PriorityQueue.h"
using namespace std;

int main()
{
    cout<<"Please type in the value of n: ";
    int n=10; //n>=5
    cin>>n;
    vector<DataBase<int,int>> a(0);

    for(int i=0;i<n;i++)
    {
        a.push_back(generate(i,n-i));
    }

    PriorityQueue<int,int> q;

    cout<<"after buildheap:"<<endl;
    q.buildHeap(a);
    q.print();
    
    cout<<"after deleteMin:"<<endl;
    q.deleteMin();
    q.print();

    cout<<"after insert data = 4:"<<endl;
    q.insert(generate(n+1,4));
    q.print();
    


    cout<<"after remove key=2(data= "<<n-2<<"):"<<endl;
    q.remove(2);
    q.print(); 

    cout<<"after remove key=n+2 (there is no key whose value is n+2):"<<endl;
    q.remove(n+2);
    q.print(); 
    
    cout<<"after modify key=3(data= "<<n-3<<") d=2:"<<endl;
    q.modifyData(3,2);
    q.print(); 

    cout<<"after modify key=3(data= "<<n-1<<") d=-4:"<<endl;
    q.modifyData(3,-4);
    q.print();    
}
