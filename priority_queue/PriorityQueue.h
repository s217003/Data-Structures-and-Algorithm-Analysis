#include <iostream>
#include <vector>
using namespace std;

template <typename Unique, typename Comparable>
struct DataBase
{
Unique key; // 具有唯一性；
Comparable data;  // 具有可比性和可加减, 但不具有唯一性；
};

template <typename Unique, typename Comparable>
class PriorityQueue
{
private:
    void PerlocateDown(int hole);
    std::vector<DataBase<Unique, Comparable>> array;
    int QueueSize;
public:
    PriorityQueue();
    ~PriorityQueue();
    
    void buildHeap( const std::vector<DataBase<Unique, Comparable>> & _input );
    void insert(DataBase<Unique, Comparable> & _x);
    void deleteMin( Comparable & minLtem );
    bool isEmpty() const;
    void modifyData(Unique k, Comparable d);
    void remove(Unique k);
    void print();

			
};

template <typename Unique, typename Comparable>
void PriorityQueue<Unique, Comparable>::PerlocateDown(int hole)
{
     int child;
     DataBase<Unique, Comparable> tmp = array[hole];
     
     for(;hole * 2 <= QueueSize ; hole = child)
     {
          child = hole * 2;
          if(child != QueueSize && array[child +1].data < array[child].data )
               child ++;
          if(array[child].data < tmp.data)
               array[hole] = std::move(array[child]);
          else
               break;
     }
     array[hole] = std::move(tmp);
}

template <typename Unique, typename Comparable>
void PriorityQueue<Unique, Comparable>::buildHeap( const std::vector<DataBase<Unique, Comparable>> & _input )
{
    PriorityQueue(array);
    for(int i=0;i<_input.size();i++)
    {
	insert(_input[i]);
    }
}

template <typename Unique, typename Comparable>
void PriorityQueue<Unique, Comparable>::insert(DataBase<Unique, Comparable> & _x)
{
     int hole = ++QueueSize;

     if(array.size() == QueueSize+1)
          array.resize(QueueSize*2);
     array[0] = std::move(_x);
     for( ; _x.data < array[hole/2].data ; hole /= 2)
     {
          array[hole] = std::move(array[hole/2]);
     }
     array[hole] = std::move(array[0]);
};

template <typename Unique, typename Comparable>
void PriorityQueue<Unique, Comparable>::deleteMin(Comparable & minLtem)
{
    while (QueueSize != 0)
    {
	array[1] = array[QueueSize];
	QueueSize -= 1;
	PerlocateDown(1);
    }
}

template <template Unique, template Comparable>
bool PriorityQueue<Unique, Comparable>::isEmpty() const
{
    if (QueueSize == 0)
	return true;
    return false;
}

template <typename Unique, typename Comparable>
void PriorityQueue<Unique, Comparable>::modifyData(Unique k, Comparable d)
{
     if(d==0)
          return;
     else
     {
	 int i;
         for(i = 1; i <= QueueSize ; i++)
         {
	     if(array[i].Key == k )
             {
		 break;
             }
         }
	 m = array[i].data + d;
	 remove(k);
	 DataBase<Unique,Comparable> M;
	 M.key=k;
	 M.data=m;
	 insert(M);
         return;
	  
     }
}

template <typename Unique, typename Comparable>
void PriorityQueue<Unique, Comparable>::remove(Unique k)
{
    int i;
    for(i = 1; i <= QueueSize ; i++)
    {
	if(array[i].Key == k )
	{
	    break;
	}
    }
    if(i > QueueSize)
	return;
    if(i != 1)
    {
	int m = i;
	int h = 2;
	while (m\2 != 1)
	{
	    h++;
	    m = m\2;
	}
	for (int j = 0; j < h-1; j++)
	{
	    array[i] = array[i\2];	    
	}
    }
    deleteMin();
}

template <typename Unique, typename Comparable>
void PriorityQueue<Unique, Comparable>::print()
{
    for(int i=1;i<array.size();i++)
        cout<<" "<<array[i].data;
        cout<<endl;
}

