#include <iostream>
#define max 5

using namespace std;
class Linear_Queue
{
public:
int arr[max];
int front=-1;
int back=-1;
int item;
void Enque()
{
    if(front==-1 && back==-1)
    {
        cout << "enter data to be enqued: ";
        cin >> item;
        front=back=0;
        arr[back]=item;
    } 
    else if (((back+1)%max)==front)
    {
        cout << "queue overflow!\n";
    }
    else
    {
        cout << "enter data to be enqued: ";
        cin >> item;
        back=(back+1)%max;
        arr[back]=item;
    }
    
}
void Deque()
{
    if(front==-1 && back==-1)
    {
    cout << "Queue is Empty\n";
    }
    else if (front==back)
    {
        cout << "Dequed item: " << arr[front] << endl;
        front=back=-1;
    }
    else{
    item = arr[front];
    cout << "Dequed item: " << item <<endl;
    front=(front+1)%max;
    }

}
void display()
{
    int i =front;
    //cout << i << endl;
    if(front==-1 && back==-1)
    {
    cout << "empty queue\n";
    }
    else{
        while (i!=back)
        {
            cout << arr[i] << "\n";
            i=(i+1)%max;
        }
        cout << arr[back]<< endl;
    }
}
};

int main()
{
    Linear_Queue q;
    int choice;
    do
    {
        cout << "enter choice: 1.Enque 2.Deque 3.Display 4.exit\n";
        cin>> choice;
        switch (choice)
        {
        case 1:
            q.Enque();
            break;
        case 2:
            q.Deque();
            break;
        case 3:
            cout << "The dequed elements are:\n";
            q.display();
            break;
        default:
            break;
        }
    } while (choice !=4);
    
    return 0;
}
