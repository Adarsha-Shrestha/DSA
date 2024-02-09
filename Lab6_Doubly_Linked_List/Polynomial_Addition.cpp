#include<iostream>

using namespace std;

class Node{
    public:
    int coff;
    int exp;
    Node* next;
    Node* prev;
Node(int coff, int exp){
    this -> coff = coff;
    this -> exp = exp;
    this -> next = NULL;
    this -> prev = NULL;
}
};

Node* poly1 = NULL;
Node* poly2 = NULL;
Node* poly = NULL;

void create_node(Node* &ptr,int coff, int exp)
{
    Node* node = new Node(coff,exp);
    if(ptr == NULL)
    {
        ptr = node;
    }
    else
    {
        if(node->exp>ptr->exp)
        {
            ptr->prev = node;
            node->next = ptr;
            ptr = node;
        }
        else
        {
            Node* temp = ptr;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
            node -> prev = temp;
        }
    }
}

void add()
{
    Node* temp1 = poly1;
    Node* temp2 = poly2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp > temp2->exp) { 
            create_node(poly,temp1->coff,temp1->exp); 
            temp1 = temp1->next; 
        }
        else if (temp1->exp < temp2->exp) { 
            create_node(poly,temp2->coff,temp2->exp); 
            temp2 = temp2->next; 
        } 
        else { 
            create_node(poly,temp1->coff + temp2->coff,temp1->exp);  
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        }
    }
    while (temp1 != NULL || temp2 !=NULL) { 
        if (temp1!=NULL) { 
            create_node(poly,temp1->coff,temp1->exp); 
            temp1 = temp1->next; 
        } 
        if (temp2!=NULL) { 
            create_node(poly,temp2->coff,temp2->exp); 
            temp2 = temp2->next; 
        } 
    }   
}

void Print(Node* temp)
{
    while (temp!=NULL)
    {
        cout <<"("<< temp->coff<< ")^" << temp->exp;
        temp = temp->next;
        if(temp != NULL)
            cout << "+";
    }  
}
int main()
{
    create_node(poly1,1,3);
    create_node(poly1,10,2);
    create_node(poly1,-30,1);
    cout << "First Polynomial: ";
    Print(poly1);
    cout << endl;
    cout << endl;
    create_node(poly2,3,5);
    create_node(poly2,2,4);
    create_node(poly2,-4,3);
    create_node(poly2,40,1);
    create_node(poly2,-10,0);
    cout << "Second Polynomial: ";
    Print(poly2);
    cout << endl;
    cout << endl;
    add();
    cout << "Resultant Polymonial: ";
    Print(poly);
}