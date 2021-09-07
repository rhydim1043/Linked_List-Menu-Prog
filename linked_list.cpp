#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    
}
*head = NULL;//The head is of Node data type

//Function to give length of the Linked List

int length()
{
    int i=1;
    Node *temp=head;
        while(temp->next!=NULL){
        temp=temp->next;
        i++;
        }
    return i;
}

//Insertion of node at end function

void insertAtEnd(int value)
{
    Node *newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newNode;
    }
    
}

//Insertion of node at start

void insertAtStart(int value)
{
 Node *newNode=new Node();
    newNode->data=value;
    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;        
    }
    else{
    Node *temp=head;   
    head=newNode;
    head->next=temp;
    }
}

//Insertion of node at any given posn

void insertAtPos(int pos,int value)
{
    if(pos==1) insertAtStart(value);
    else if(pos>length()) cout<<"List too small"<<endl;
    else if(head==NULL) cout<<"List Empty";
    else{
    Node *newNode=new Node();
    newNode->data=value;
    Node *temp=head;
    for(int i=1;i<pos-1;i++) 
    {
        temp=temp->next;
    }
    
    newNode->next=temp->next;
    temp->next=newNode;
    }
}

//Deletion of node at start function

void delAtStart()
{
    if(head==NULL) cout <<"List is already empty" << endl;
    else 
    {
        Node *temp = head;
        head=head->next;
        delete temp;
    }
}

//Deletion of node at end function

void delAtEnd(){
    if(head==NULL) cout <<"List is already empty" << endl;
    else{
        Node *temp = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
}

//Deletion of node at any given position function

void delAtPosition(int pos){
    if(pos>length()) cout<<"List too small"<<endl;
    else if(head==NULL) cout<<"List Empty";
    else{
        Node *temp=head;
    for(int i=1;temp!=NULL && i<pos-1;i++) 
    {
        temp=temp->next;        
    }
    Node *temp2=temp->next->next;
    delete temp->next;
    temp->next=temp2;
    }
}

void display()
{
    if(head==NULL) cout<<"List Empty!!";
    else {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    cout<<endl;
}

//Main execution of program

int main(int argc, char const *argv[])
{
 char cont='y';
 while(true)
 {
 cout<<"Press 1 to insert element in linked list" <<endl;
 cout<<"Press 2 to display linked list" <<endl;
 cout<<"Press 3 to delete element in linked list" <<endl;
 cout<<"Press 4 to display length of linked list" <<endl;
 char input,input2,continput;
 int element;
 cin >> input;
 if(input=='1') 
 {
     while(true){
     cout<<"Press a to insert element in linked list at end" <<endl;
     cout<<"Press b to insert element in linked list at beginning" <<endl;
     cout<<"Press c to insert element between linked list" <<endl;
     
     cin>>input2;
     cout<<"Insert Element: ";
         cin >> element;
     if(input2=='a') 
     {         
         insertAtEnd(element);
         cout<<"New Linked List: ";display();
     }
     else if(input2=='b') 
     {        
         insertAtStart(element);
         cout<<"New Linked List: ";display();
     }
     else if(input2=='c') 
     {        
         int pos;
         cout<<"Current List: "; display();
         cout<<"Insert Position at which you want to to insert the element"<<endl;
         cin>>pos;
         insertAtPos(pos,element);
         cout<<"New Linked List: ";display();
     }
     cout<<"Press any key to insert more else press n to end process"<<endl;
     cin>>continput;
     if(continput=='n') break;
     }
 }
   else if(input=='2') display();
   else if(input=='3'){
   while(true){
     cout<<"Press a to delete element in linked list at end" <<endl;
     cout<<"Press b to delete element in linked list at beginning" <<endl;
     cout<<"Press c to delete element between linked list" <<endl;
     cin>>input2;
     if(input2=='a')
     {
         delAtEnd();
         display();
     }
     else if(input2=='b')
     {
         delAtStart();
         display();
     }
     else if(input2=='c')
     {
         int pos;
         cout<<"Current Linked List: ";
         display();
         cout<<"Insert the position you want to delete: ";
         cin>>pos;
         delAtPosition(pos);
         display();
     }
     cout<<"Press any key to delete more else press n to end process"<<endl;
     cin>>continput;
     if(continput=='n') break;
   }
   }
   else if(input=='4') {
       cout<<"Length of your Linked List: "<<length() <<endl;
   }
   cout<< "To continue press any key else to end the process press n or n"<<endl;
   cin>>cont;
   if(cont=='n' || cont=='n') break;
 }
 
    return 0;
}

