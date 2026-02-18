#include<iostream>
using namespace std;

class  queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    queue(int s){
        arr = new int[s];
        size =s;
        front  = 0;
        rear = -1;
        size = 0;
    }
    ~queue(){
        delete [] arr;
    }
    void enqueue(int x){
        if(size == size-1){
            cout<<"Queue is full"<<endl;
            return;
        }
        rear = (rear+1)%size;
        arr[rear] = x;
        size++;
        cout<<x<<" enqueued to queue"<<endl;
    }

    void dequeue(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        int x = arr[front];
        front = (front+1)%size;
        size--;
        cout<<x<<" dequeued from queue"<<endl;
    }

    int getFront(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == this->size;
    }

    void display(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue elements: ";
        for(int i=0; i<size; i++){
            cout<<arr[(front+i)%this->size]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    queue q(5); // size of queue is 5
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout<<"Front element: "<<q.getFront()<<endl;
    cout<<"Rear element: "<<q.getRear()<<endl;
    q.dequeue();
    q.dequeue();
    q.display();
}