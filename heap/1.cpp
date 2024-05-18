#include<bits/stdc++.h>
using namespace std;
int arr[100];
int size=0;
void insert(int val)
{
    size++;
    int index=size;
    arr[index]=val;
    while(index>1)
    {
        int parent=index/2;
        if(arr[parent]<arr[index])
        {
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else
        {
            return ;
        }
    }
}
void print()
{
    for(int i=1;i<=size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
void deletefromHeap()
{
    if(size==0)
    {
        cout<<"nothing to delete"<<endl;
        return ;
    }
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<size)
    {
        int leftIndex=2*i;
        int rightIndex=2*i+1;
        int maxIndex = i;
        if(leftIndex<=size&&arr[maxIndex]<arr[leftIndex])
        {
            //swap(arr[i],arr[leftIndex]);
            maxIndex=leftIndex;
        }
        if(rightIndex<=size&&arr[maxIndex]<arr[rightIndex])
        {
            //swap(arr[i],arr[rightIndex]);
            maxIndex=rightIndex;
        }
        if (maxIndex != i)
        {
            swap(arr[i], arr[maxIndex]);
            i = maxIndex;
        }
        else
        return;
           }
}
void heapify(int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=size&&arr[largest]<arr[left])
    {
        largest=left;
    }
    if(right<=size&&arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(largest);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insert(x);
    }
    print();
    // for(int i=0;i<n;i++)
    // {
    // deletefromHeap();
    // print();
    // }
    // while(1)
    // {
    //     //cout<<"Enter data or press -1 to exit"<<endl;
    //     int x;
    //     cin>>x;
    //     if(x==-1)
    //     break;
    //     size++;
    //     arr[size]=x;
    // }
    // for(int i=(size-1)/2;i>0;i--)
    // {
    //     heapify(i);
    // }
    // print();
}




// #include<iostream>
// #include<queue>
// using namespace std;
// class heap{
//     public:
//     int arr[100];
//     int size=0;
//     heap()
//     {
//         arr[0]=-1;
//         size=0;
//     }
//     void insert(int val)
//     {
//         size++;
//     int index=size;
//     arr[index]=val;
//     while(index>1)
//     {
//         int parent=index/2;
//         if(arr[parent]<arr[index])
//         {
//             swap(arr[parent],arr[index]);
//             index=parent;
//         }
//         else
//         {
//             return ;
//         }
//     }
//     }
//     void print()
// {
//     for(int i=1;i<=size;i++)
//     cout<<arr[i]<<" ";
//     cout<<endl;
// }
// void deletefromHeap()
// {
//     if(size==0)
//     {
//         cout<<"nothing to delete"<<endl;
//         return ;
//     }
//     arr[1]=arr[size];
//     size--;
//     int i=1;
//     while(i<size)
//     {
//         int leftIndex=2*i;
//         int rightIndex=2*i+1;
//         if(leftIndex<size&&arr[i]<arr[leftIndex])
//         {
//             swap(arr[i],arr[leftIndex]);
//             i=leftIndex;
//         }
//         else if(rightIndex<size&&arr[i]<arr[rightIndex])
//         {
//             swap(arr[i],arr[rightIndex]);
//             i=rightIndex;
//         }
//         else
//         return;
//            }
// }
// };
// void heapify(int arr[],int n,int i)
// {
//     int largest=i;
//     int left=2*i;
//     int right=2*i+1;
//     if(left<=n&&arr[largest]<arr[left])
//     {
//         largest=left;
//     }
//     if(right<=n&&arr[largest]<arr[right])
//     {
//         largest=right;
//     }
//     if(largest!=i)
//     {
//         swap(arr[largest],arr[i]);
//         heapify(arr,n,largest);
//     }
// }
// void heapSort(int arr[],int n)
// {
//     int size=n;
//     while(size>1)
//     {
//         //step1
//         swap(arr[size],arr[1]);
//         size--;
//         heapify(arr,size,1);
//     }
// }
// int main()
// {
    // heap h;
    // //tc o(logn)
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // //tc o(logn)
    // h.deletefromHeap();
    // h.print();
    // //deletion implies deleting root node




//tc of heapify is log(n)
//buildHeap using heapify(arr,size,i) is o(n)
//     int arr[6]={-1,54,53,55,52,50};
//     int n=5;
//     for(int i=n/2;i>0;i--)
//     {
//         heapify(arr,n,i);
//     }
//     cout<<"Printing the array now"<<endl;
//     for(int i=1;i<=n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     heapSort(arr,n);
//     cout<<"Printing the Sorted array now"<<endl;
//     for(int i=1;i<=n;i++)
//     cout<<arr[i]<<" ";
//     cout<<endl;
//     //heap sort tc o(nlogn)

//     cout<<"Maxheap using priority queue"<<endl;
//     priority_queue<int> pq;
//     pq.push(4);
//      pq.push(2);
//       pq.push(5);
//        pq.push(3);
//        cout<<"ELement at top"<<pq.top()<<endl;
//        pq.pop();
//        cout<<"ELement at top"<<pq.top()<<endl;
//        cout<<"Size is"<<pq.size()<<endl;
//        if(pq.empty())
//        cout<<"pq is empty"<<endl;
//        else
//        cout<<"pq is not empty"<<endl;
//        cout<<"Minheap using priority queue"<<endl;
//     priority_queue<int,vector<int>,greater<int>> pq2;
//     pq2.push(4);
//      pq2.push(2);
//       pq2.push(5);
//        pq2.push(3);
//        cout<<"ELement at top"<<pq2.top()<<endl;
//        pq2.pop();
//        cout<<"ELement at top"<<pq2.top()<<endl;
//        cout<<"Size is"<<pq2.size()<<endl;
//        if(pq2.empty())
//        cout<<"pq2 is empty"<<endl;
//        else
//        cout<<"pq2 is not empty"<<endl;
// }