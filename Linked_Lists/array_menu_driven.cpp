/**************************************************************************
 Online C++ Compiler.
 Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
**************************************************************************/
#include <iostream>
using namespace std;
class CarManufacturing{
 public:
 string name, email, place;
 long mobile;
 int i;
 // Function Declaration
 public:
 void display();
 void read();
 void insert();
 void update(); 
};
// Function to read Suppliers
void CarManufacturing::read(){
 cout<<"\nEnter Supplier Name: ";
 cin>>name;
 cout<<"Enter Supplier Email: ";
 cin>>email;
 cout<<"Enter Supplier Mobile: ";
 cin>>mobile;
 cout<<"Enter Supplier Place: ";
 cin>>place;
}
// Function to Display Suppliers
void CarManufacturing::display(){
 cout<<"\n\nSupplier are\n";
 cout<<"\nName: "<<name<<"\nEmail: "<<email<<"\nMobile: "<<mobile<<"\nPlace: 
"<<place<<"\n";
}
 int main()
{
 int size;
 CarManufacturing obj1[100];
 
 // Asking for Total number of supliers.
 cout<<"\nEnter number of Supplier: ";
 cin>>size;
 
 // Taking input of Suppliers data
 int i;
 for(i=0; i< size; i++){
 obj1[i].read();
 }
 
 // Declaraing variables
 string u_name , u_email , u_place ;
 long u_mob;
 char a,b,c,d;
 int size1;
 int position;
 
 // Code for Menu Driven Program
 while(1){
 
 cout<<"\n\n*********** Menu ***********\n";
 cout<<"1 display\n";
 cout<<"2 insert\n";
 cout<<"3 remove\n";
 cout<<"4 update\n";
 cout<<"5 exit\n";
 cout<<"****************************\n\n";
 
 int choise;
 cout<<"\n Enter Your Choise:";
 cin>>choise;
 switch(choise){
 
 // Case 1 to display data
 case 1:
 for(i=0; i<size; i++){
 obj1[i].display();
 }
 break;
 
 // Case 2 to Insert data
 case 2:
 cout<<"\nEnter number of Supplier: ";
 cin>>size1;
 //Inserting data using Array of Objecs 
 int i;
 for(i=size; i< (size+size1); i++){
 obj1[i].read();
 }
 size=size+size1;
 cout<<"\n\nSupplier Inserted\n";
 for(i=0; i<size; i++){
 obj1[i].display();
 } 
 break;
 
 // Case 3 for Delete the data of Supplier
 case 3:
 cout<<"\n\nEnter Supplier position to Delete:";
 cin>>position;
 for(i=0; i<=size-2; i++){
 if(i>=position){
 obj1[i]=obj1[i+1];
 }
 }
 size= size-1; 
 break;
 
 // Case 4 to Update the position With menu Driven Logic to update specific data
 case 4:
 cout<<"\n\nEnter Supplier position to Update:";
 cin>>position;
 for(i=0;i<size;i++)
 {
 if(i==position)
 { 
 cout<<"Select what you want to update: \n";
 cout<<"a name\n";
 cout<<"b email\n";
 cout<<"c mobile\n";
 cout<<"d place\n"; 
 char ch;
 cout<<"\n Enter Your Choise:";
 cin>>ch;
 switch(ch){ 
 case 'a':
 cout<<"\n\nEnter name to update:";
 cin>>u_name;
 obj1[i].name=u_name;
 break;
 case 'b': 
 cout<<"\n\nEnter Email to update: ";
 cin>>u_email;
 obj1[i].email=u_email;
 break;
 case 'c':
 cout<<"\n\nEnter Mobile Number to update: ";
 cin>>u_mob;
 obj1[i].mobile=u_mob;
 break;
 case 'd':
 cout<<"\n\nEnter Place to update: ";
 cin>>u_place;
 obj1[i].place=u_place;
 break;
 
 default:
 cout<<"Enter Valid choise to update";
 }}}
 
 cout<<"\n\nSupplier Updated:\n";
 for(i=0; i<size; i++){
 obj1[i].display();
 }
 break;
 
 //Case 5 to Exit
 case 5:
 exit(0);
 break;
 default:
 cout<<"\nPlease Enter Valid Choise\n";
 }
 }
}
