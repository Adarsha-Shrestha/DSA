#include <iostream>
#define max 5

using namespace std;
class Linear_Queue
{
public:
int arr[max];
int front=0;
int back=-1;
int item;
void isEmpty()
{
    if(front>back)
    cout << "Queue is Empty\n";
}
void isFull()
{
    if(back>max-1)
    cout << "Queue is Full\n";
}
void Enque()
{
    cout << "Enter element:\n";
    cin>>item;
    back=back+1;
    arr[back]=item;
}
void Deque()
{
    item = arr[front];
    front = front+1;
    cout << "Dequed item: " << item <<endl;
}
void display()
{
    for(int i=0;i<=back;i++)
    {
        cout <<"remaining values are:\n" << arr[i] << endl; 
    }
}
};

int main()
{
    Linear_Queue q;
    int choice;
    do
    {
        cout << "enter choice:\n1.Enque\n2.Deque\n3.Display\n4.exit\n";
        cin>> choice;
        switch (choice)
        {
        case 1:
            q.isFull();
            q.Enque();
            break;
        case 2:
            q.isEmpty();
            q.Deque();
            break;
        case 3:
            q.display();
            break;
        default:
            break;
        }
    } while (choice !=4);
    
    return 0;
}
