#include<iostream>
#include<conio.h>
using namespace std;
class Node{
private:
int data;
string name;
float percent;
Node *Next;
public:
 void print();
 
void insert_begin(int x ,string na, float pa);
void insert_end(int x ,string na, float pa);
void insert(int X,string na,float pa, int N);
void insert_roll(int X,string na,float pa, int N);
void Delete(int n);
void Delete_begin();
void Delete_end();
void Update_roll(int x,int up_val1);
void Update_name(int x,string up_val2);
void Update_per(int x,float up_val3);
void Search_roll(int x);
void Search_name(string up_val2);
void Search_per(float up_val3);
void Sort_roll();
void Sort_name();
void Sort_per();
};
Node *Head;
void Node::print()
{
Node *temp = Head;
cout<<"\n\nList Is: ";
while(temp != NULL)
{
 
cout<<"\n"<<" "<<temp->data<<" | "<<temp->name<<" | "<<temp-
>percent<<" | ";
temp = temp->Next;
}
cout<<"\n";
}
void Node::insert_begin(int x ,string na, float pa)
{
Node *temp = new Node();
temp->data = x;
temp->name = na;
temp->percent = pa;
temp->Next = Head;
Head = temp;
cout<<"Node Inserted at begining";
}
void Node::insert_end(int x ,string na, float pa)
{
Node *temp = new Node();
Node *temp2 = new Node();
if(Head==NULL){
 temp->Next=NULL;
 Head=temp;
 cout<<"\nNode Inserted\n";
}else{
temp2=Head;
temp->data = x;
temp->name = na;
temp->percent = pa;
while(temp2->Next!=NULL){
 temp2= temp2->Next;
}
temp2->Next=temp;
temp->Next=NULL;
cout<<"Node Inserted at end";
}
}
void Node::insert(int X,string na, float pa, int N)
{
Node *temp = new Node();
temp->data = X;
temp->name = na;
temp->percent = pa;
temp->Next = NULL;
if(N==1)
{
temp->Next = Head;
Head = temp;
}
else
{
Node *temp2 = new Node();
temp2 = Head;
for(int i = 1; i<N-1; i++)
{
temp2 = temp2->Next;
}
temp->Next = temp2->Next;
temp2->Next = temp;
}
}
void Node::insert_roll(int X,string na, float pa, int N)
{
Node *temp = new Node();
temp->data = X;
temp->name = na;
temp->percent = pa;
temp->Next = NULL;
if(N==1)
{
temp->Next = Head;
Head = temp;
}
else
{ 
 Node *temp3 = Head; int count=0;
 while(temp3 != NULL)
 { count++; temp3 = temp3->Next; }
 
 
Node *temp2 = new Node();
temp2 = Head;
for(int i = 1; i<count; i++)
{
 if(N != temp2->data){
 temp2 = temp2->Next;
 }
 if(N == temp2->data){
 break;
 }
}
temp->Next = temp2->Next;
 temp2->Next = temp;
}
}
void Node::Delete(int n)
{
Node *temp = new Node();
temp = Head;
if(n == 1)
{
Head = temp->Next;
delete temp; 
}
else
{
for(int i = 1; i<n-1; i++)
{
temp = temp->Next;
}
Node *temp2 = temp->Next;
temp->Next = temp2->Next;
delete temp2;
}
}
void Node::Delete_begin()
{
Node *temp = new Node();
 if(Head==NULL){
 cout<<"Link is Empty";
 }else{
temp=Head;
Head=temp->Next;
delete temp;
cout<<"\nBegining Data Deleted!!\n";
 }
}
void Node::Delete_end()
{
Node *temp = new Node();
temp=Head;
 Node *temp2 = new Node();
 if(Head==NULL){
 cout<<"Link is Empty";
 }else{
 while(temp->Next!=NULL){
 temp2=temp;
 temp=temp->Next;
 }
 temp2->Next=NULL;
 delete temp;
cout<<"\nEnding Data Deleted!!\n";
 }
}
void Node::Update_roll(int x, int up_val1){
 Node *temp = new Node();
 temp=Head;
 if (temp->Next == NULL){
 temp->data=up_val1;
 cout<<"Roll num updated!!\n";
 
 }
 while(temp!=NULL){
 if(temp->data==x){
 temp->data=up_val1;
 cout<<"Roll num updated!!\n";
 break;
 }
 temp=temp->Next;
 }
}
void Node::Update_name(int x,string up_val2){
 Node *temp = new Node();
 temp=Head;
 if (temp->Next == NULL){
 temp->name=up_val2;
 cout<<"Name updated!!\n";
 
 }
 while(temp!=NULL){
 if(temp->data==x){
 temp->name=up_val2;
 cout<<"Name updated!!\n";
 break;
 }
 temp=temp->Next;
 }
}
void Node::Update_per(int x, float up_val3){
 Node *temp = new Node();
 temp=Head;
 if (temp->Next == NULL){
 temp->percent=up_val3;
 cout<<"Percentage updated!!\n";
 
 }
 while(temp!=NULL){
 if(temp->data==x){
 temp->percent=up_val3;
 cout<<"Percentage updated!!\n";
 break;
 }
 temp=temp->Next;
 }
}
void Node::Search_roll(int x){
 Node *temp = new Node();
 temp=Head;
 cout<<"\nResultant Search:";
 while(temp!=NULL){
 
 if(temp->data==x){
 cout<<"\n"<<" "<<temp->data<<" | "<<temp->name<<" | "<<temp->percent<<" | ";
 break;
 }
 temp=temp->Next;
 }
}
void Node::Search_name(string up_val2){
 Node *temp = new Node();
 temp=Head;
 cout<<"\nResultant Search:";
 while(temp!=NULL){
 
 if(temp->name==up_val2){
 cout<<"\n"<<" "<<temp->data<<" | "<<temp->name<<" | "<<temp->percent<<" | ";
 break;
 }
 temp=temp->Next;
 }
}
void Node::Search_per(float up_val3){
 Node *temp = new Node();
 temp=Head;
 cout<<"\nResultant Search:";
 while(temp!=NULL){
 
 if(temp->percent==up_val3){
 cout<<"\n"<<" "<<temp->data<<" | "<<temp->name<<" | "<<temp->percent<<" | ";
 break;
 }
 temp=temp->Next;
 }
}
void Node::Sort_roll(){
 int temp_r; string temp_n; float temp_p;
 
 Node *temp= new Node();
 Node *temp2= new Node();
 temp=Head;
 temp2=temp->Next;
 
 // To calculate total number of nodes
 Node *temp3 = Head; int count=0;
while(temp3 != NULL)
{ count++; temp3 = temp3->Next; }
cout<<"\nNumber of nodes: "<<count<<"\n";
 for(int i=0; i<count; i++){
 temp=Head;
 temp2=temp->Next;
 while(temp->Next!=NULL){
 if(temp->data > temp2->data){
 temp_r=temp->data;
 temp->data=temp2->data;
 temp2->data=temp_r;
 
 temp_n=temp->name;
 temp->name=temp2->name;
 temp2->name=temp_n;
 
 temp_p=temp->percent;
 temp->percent=temp2->percent;
 temp2->percent=temp_p;
 
 temp=temp->Next;
 temp2=temp2->Next;
 }else{
 temp=temp->Next;
 temp2=temp2->Next;
 }
 }
 }
 
}
void Node::Sort_name(){
 int temp_r; string temp_n; float temp_p;
 
 Node *temp= new Node();
 Node *temp2= new Node();
 temp=Head;
 temp2=temp->Next;
 
 // To calculate total number of nodes
 Node *temp3 = Head; int count=0;
while(temp3 != NULL)
{ count++; temp3 = temp3->Next; }
cout<<"\nNumber of nodes: "<<count<<"\n";
 for(int i=0; i<count; i++){
 temp=Head;
 temp2=temp->Next;
 while(temp->Next!=NULL){
 if(temp->name > temp2->name){
 temp_r=temp->data;
 temp->data=temp2->data;
 temp2->data=temp_r;
 
 temp_n=temp->name;
 temp->name=temp2->name;
 temp2->name=temp_n;
 
 temp_p=temp->percent;
 temp->percent=temp2->percent;
 temp2->percent=temp_p;
 
 temp=temp->Next;
 temp2=temp2->Next;
 }else{
 temp=temp->Next;
 temp2=temp2->Next;
 }
 }
 }
}
void Node::Sort_per(){
 int temp_r; string temp_n; float temp_p;
 
 Node *temp= new Node();
 Node *temp2= new Node();
 temp=Head;
 temp2=temp->Next;
 
 // To calculate total number of nodes
 Node *temp3 = Head; int count=0;
while(temp3 != NULL)
{ count++; temp3 = temp3->Next; }
cout<<"\nNumber of nodes: "<<count<<"\n";
 for(int i=0; i<count; i++){
 temp=Head;
 temp2=temp->Next;
 while(temp->Next!=NULL){
 if(temp->percent > temp2->percent){
 temp_r=temp->data;
 temp->data=temp2->data;
 temp2->data=temp_r;
 
 temp_n=temp->name;
 temp->name=temp2->name;
 temp2->name=temp_n;
 
 temp_p=temp->percent;
 temp->percent=temp2->percent;
 temp2->percent=temp_p;
 
 temp=temp->Next;
 temp2=temp2->Next;
 }else{
 temp=temp->Next;
 temp2=temp2->Next;
 }
 }
 }
}
int main()
{
Head = NULL;
Node list;
int num,n,x;
string name1;
 float per1;
 string name2;
 float per2;
 int up_val1; string up_val2; float up_val3;
int insert;
 while(1){
 
 cout<<"\n\n*********** Menu ***********\n\n";
 cout<<"1 Insert data\n";
 cout<<"2 display Link List:\n";
 cout<<"3 Insertion Various operations:\n";
 cout<<"4 Update Various operations:\n";
 cout<<"5 Search record:\n";
 cout<<"6 Sort record:\n";
 cout<<"7 Delete Various operations:\n";
 cout<<"8 exit\n\n";
 cout<<"****************************\n\n";
 
 int choise;
 cout<<"\n Enter Your Choise:";
 cin>>choise;
 switch(choise){
 
 case 1:
 int size, num ;
 
 cout<<"Enter num of elements you want to insert: ";
 cin>>size;
 for(int i=1; i<=size; i++){
 
 cout<<"\nEnter Roll: ";
 cin>>num;
 cout<<"Enter name: ";
 cin>>name2;
 cout<<"Enter percentage: ";
 cin>>per2;
 list.insert(num,name2,per2,i);
 }
 
 break;
 
 
 case 2:
 
 list.print();
 
 break;
 
 case 3:
 while(1){
 cout<<"\n\n----------------------------\n";
 cout<<"1: Insert at begining:\n";
 cout<<"2: Insert at end:\n";
 cout<<"3: Insert at nth position:\n";
 cout<<"4: Insert after roll:\n";
 cout<<"5: Exit Insertion:\n";
 cout<<"\n----------------------------\n\n";
 
 cout<<"\nSelect Choise to insert: ";
 cin>>insert;
 
 if(insert==1){
 cout<<"\nEnter Roll: ";
 cin>>num;
 cout<<"Enter name: ";
 cin>>name2;
 cout<<"Enter percentage: ";
 cin>>per2;
 list.insert_begin(num,name2,per2);
 list.print();
 }else if(insert==2){
 cout<<"\nEnter Roll:";
 cin>>x;
 cout<<"Enter name: ";
 cin>>name1;
 cout<<"Enter percentage: ";
 cin>>per1;
 list.insert_end(x,name1,per1);
 list.print();
 }else if(insert==3){
 int x,n;
 cout<<"\nPosition:";
 cin>>n;
 cout<<"\nEnter Roll:";
 cin>>x;
 cout<<"Enter name: ";
 cin>>name1;
 cout<<"Enter percentage: ";
 cin>>per1;
 
 list.insert(x,name1,per1,n); 
 list.print(); 
 
 }else if(insert==4){
 int x,n;
 cout<<"\nEnter roll after which you want to insert node:";
 cin>>n;
 cout<<"\nEnter Roll:";
 cin>>x;
 cout<<"Enter name: ";
 cin>>name1;
 cout<<"Enter percentage: ";
 cin>>per1;
 
 list.insert_roll(x,name1,per1,n); 
 list.print(); 
 
 }else if(insert==5){
 break;
 }else{
 cout<<"\n\nPlease enter valid choise to insert";
 }
 
 }
 
 break;
 case 4:
 while(1){
 
 
 cout<<"\n\n----------------------------";
 cout<<"\n1: to update roll num:";
 cout<<"\n2: to update Name:";
 cout<<"\n3: to update percentage:";
 cout<<"\n5: Exit update function:";
 cout<<"\n----------------------------\n\n";
 list.print();
 
 
 
 cout<<"\n\nEnter choise to enter: ";
 cin>>n;
 
 
 if(n==1){
 cout<<"\nWhich Roll you want to update data: ";
 cin>>x;
 cout<<"Enter roll? ";
 cin>>up_val1;
 list.Update_roll(x,up_val1);
 list.print();
 }else if(n==2){
 cout<<"\nWhich Roll you want to update data: ";
 cin>>x;
 cout<<"Enter name? ";
 cin>>up_val2;
 list.Update_name(x,up_val2);
 list.print();
 }else if(n==3){
 cout<<"\nWhich Roll you want to update data: ";
 cin>>x;
 cout<<"Enter Percentage? ";
 cin>>up_val3;
 list.Update_per(x,up_val3);
 list.print();
 }else if(n==5){
 break;
 }
 else{
 cout<<"\nEnter valid choise to update";
 }
 }
 break;
 
 
 case 5:
 while(1){
 cout<<"\n\n----------------------------";
 cout<<"\n1: Search using roll:";
 cout<<"\n2: Search using name:";
 cout<<"\n3: Search using percentage:";
 cout<<"\n4: Exit search menu:";
 cout<<"\n----------------------------\n\n";
 
 cout<<"\nSelect Choise to Search: ";
 cin>>insert;
 if(insert==1){
 list.print();
 cout<<"\nEnter roll to search: ";
 cin>>x;
 list.Search_roll(x);
 }else if(insert==2){
 list.print();
 cout<<"\nEnter Name to search: ";
 cin>>up_val2;
 list.Search_name(up_val2);
 }else if(insert==3){
 list.print();
 cout<<"\nEnter Percentage to search: ";
 cin>>up_val3;
 list.Search_per(up_val3);
 }else if(insert==4){
 break;
 }
 else{
 cout<<"Enter valid choise to Search";
 }
 
 }
 break;
 
 
 case 6:
 while(1){
 cout<<"\n\n----------------------------";
 cout<<"\n1: Sort using roll:";
 cout<<"\n2: Sort using name:";
 cout<<"\n3: Sort using percentage:";
 cout<<"\n4: Exit srting menu:";
 cout<<"\n----------------------------\n\n";
 
 cout<<"\nSelect Choise to Search: ";
 cin>>insert;
 
 if(insert==1){
 list.Sort_roll();
 list.print();
 }else if(insert==2){
 list.Sort_name();
 list.print();
 }else if(insert==3){
 list.Sort_per();
 list.print();
 }else if(insert==4){
 break;
 }else{
 cout<<"Please enter valid choise for search";
 }
 } 
 
 break;
 
 case 7:
 while(1){
 cout<<"\n\n----------------------------";
 cout<<"\n1: delete node at any position::";
 cout<<"\n2: delete at begining:";
 cout<<"\n3: delete at Ending:";
 cout<<"\n4: Exit delte menu:";
 cout<<"\n----------------------------\n\n";
 
 cout<<"\nSelect Choise to Delete: ";
 cin>>insert;
 
 if(insert==1){
 cout<<"\nWhich positioned number you want to delete: ";
 cin>>num;
 list.Delete(num);
 list.print(); 
 }
 else if(insert==2){
 list.Delete_begin();
 list.print();
 
 }
 else if(insert==3){
 list.Delete_end();
 list.print();
 }else if(insert==4){
 break;
 }
 else{
 cout<<"Enter valid choise to delete";
 }
 
 } 
 break;
 
 case 8:
 exit(0);
 break;
 
 default:
 cout<<"\nPlease Enter Valid Choise\n";
 }
 
 }
 getch();
}
