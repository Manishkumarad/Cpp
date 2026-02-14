#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};
Node* covertArrToLL(vector<int> arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0], nullptr);
    Node* current = head;
    for(int i = 1; i < arr.size(); i++){
        current->next = new Node(arr[i], nullptr);
        current = current->next;
    }
    return head;
}
Node* traverseArr(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void printArray(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* removeHead(Node* head){
    if(head == nullptr)
    return nullptr;
    Node* temp = head;
    head =head->next;
    delete temp;
    return head;
}

int main(){
    int arr[] = {10, 25, 5, 40, 15};

    Node* head = new Node(arr[0], nullptr);
    Node* current = head;
    for(int i = 1; i < 5; i++){
        current->next = new Node(arr[i], nullptr);
        current = current->next;

    }
    head = removeHead(head);
    //head = covertArrToLL({10, 25, 5, 40, 15});
    head = traverseArr(head);
    printArray(head);
}