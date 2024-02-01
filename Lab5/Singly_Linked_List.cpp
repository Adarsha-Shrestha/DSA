#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
Node(int data){
    this -> data = data;
    this -> next = NULL;
}
};
Node* head = NULL;
Node* tail = NULL;
void InsertatHead(int d)
{
    Node* temp = new Node(d);
    if(head == NULL)
    {
        tail = head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void InsertatTail(int d)
{
    Node* temp = new Node(d);
    if(head == NULL)
    {
        tail = head = temp;
    }
    else
    {
        tail->next=temp;
        tail = temp;
    }
}
void InsertatPos(int d,int p)
{
    Node* temp = head;
    if(head == NULL)
    {
        tail = head = temp;
    }
    int cnt=1;
    while (cnt<p-1)
    {
        temp=temp->next;
        cnt++;
    }
    Node* newnode = new Node(d);
    newnode->next = temp->next;
    temp->next = newnode;
}
void DeleteHead()
{
    Node* temp = head;
    if(head == NULL)
    {
        cout << "List Empty!\n";
    }
    else{
        head = temp->next;
    delete temp;
    }
}
void DeleteTail()
{
    Node* temp = head;
    if(head == NULL)
    {
        cout << "List Empty!\n";
    }
    else{
        while (temp->next!=tail)
    {
        temp = temp->next;
    }
    Node* node2del = tail;
    tail  = temp;
    temp->next = NULL;
    delete node2del;
    }
}
void DeletePos(int pos)
{
    Node* temp = head;
    if(head == NULL)
    {
        cout << "List Empty!\n";
    }
    else{
        int cnt = 1;
    while (cnt<pos-1)
    {
        temp = temp->next;
        cnt++;
    }
    Node* node2del = temp->next;
    temp->next = node2del->next;
    delete node2del;
    }
}
void Print()
{
    Node* temp = head;
    if(head == NULL)
    {
        cout << "List Empty!\n";
    }
    while (temp!=NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;  
}
int main()
{
    int choice;
    int data;
    int position;
    do
    {
        cout << "1.Insert at Head 2.Insert at Tail 3.Insert at any Position 4.Delete at Head 5.Delete at Tail 6.Delete at any position 7.Display List 0.Exit:\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to be insterted:\n";
            cin >> data;
            InsertatHead(data);
            break;
        case 2:
            cout << "Enter data to be insterted:\n";
            cin >> data;
            InsertatTail(data);
            break;
        case 3:
            cout << "Enter data to be insterted and position:\n";
            cin >> data;
            cin >> position;
            InsertatPos(data,position);
            break;
        case 4:
            DeleteHead();
            break;
        case 5:
            DeleteTail();
            break;
        case 6:
            cout << "Enter position to delete:\n";
            cin >> position;
            DeletePos(position);
            break;
        case 7:
            Print();
            break;
        default:
            break;
        }
    } while (choice!=0);
}