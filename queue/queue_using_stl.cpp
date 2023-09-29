#include<iostream>
using namespace std;
#include<queue>

int main()
{
    queue<int> q;
    q.push(12);
    cout<<"front of queue"<<q.front()<<endl;
    q.push(3);
    q.push(-1);
    cout<<"size : "<<q.size()<<endl;
    q.pop();
    cout<<"front of queue"<<q.front()<<endl;
    cout<<"size after popping : "<<q.size()<<endl;
    if(q.empty()){
        cout<<"queue is empty ";
    }
    else{
        cout<<"queue is not empty ";
    }
}