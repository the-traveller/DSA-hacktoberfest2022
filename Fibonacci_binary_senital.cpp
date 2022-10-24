#include<iostream>
#include<math.h>
#define max 20
using namespace std;
class Student
{
public:
string name;
int marks,roll_no;
};
class Search
{
public:
Student data[max];
int n;
void fibo_search();
void binary_search();
void senital_search();
void getdata();
void sort();
void display();
};
void Search::getdata()
{
cout<<"Enter the total number of students:";
cin>>n;
cout<<"\nEnter the Data:"<<endl;
for(int i=0; i<n ; i++)
{
 cout<<"\nEnter the name:";
cin>>data[i].name;
cout<<"Enter roll number:";
cin>>data[i].roll_no;
cout<<"Enter marks:";
cin>>data[i].marks;
}
}
void Search::sort()
{
 int key, j,y;
 string x;
 for(int i = 1; i<n; i++) 
 {
 key = data[i].marks;
 x=data[i].name;
 y=data[i].roll_no;
 
 j = i;
 while(j > 0 && data[j-1].marks>key) 
 {
 data[j].marks = data[j-1].marks;
 data[j].name = data[j-1].name;
 data[j].roll_no = data[j-1].roll_no;
 j--;
 }
 data[j].marks = key; 
 data[j].name = x; 
 data[j].roll_no = y; 
 }
}
void Search ::display()
{
for(int i=0 ; i<n; i++)
{
cout<<"\n Name: "<<data[i].name<<endl;
cout<<" Roll no. :"<<data[i].roll_no<<endl;
cout<<" Marks :"<<data[i].marks<<endl;
}
}
void Search ::binary_search( )
{
int low =0,key;
int high=n-1, mean,flag=0; 
cout<<">>\nEnter marks to be search:";
cin>>key;
while(low<=high)
{
mean=low+(high-low)/2;
if(data[mean].marks==key)
{
cout<<" \nGiven Marks found at index:"<<mean;
cout<<"\nRecord:"<<endl;
cout<<"Name: "<<data[mean].name<<endl;
cout<<"Roll no. :"<<data[mean].roll_no<<endl;
cout<<"Marks :"<<data[mean].marks<<endl;
flag=1;
break;
}
else
{
 if(key<data[mean].marks)
 {
 high=mean-1;
 }
 
 else
 {
 low=mean+1;
 }
}
}
if(flag!=1)
{
cout<<"\nMarks was not found..........."<<endl;
}
}
void Search :: senital_search( )
{
int key ,last,i=0;
cout<<">>\nEnter marks to be search:";
cin>>key;
last=data[n-1].marks;
data[n-1].marks=key;
while(data[i].marks!=key)
i++;
data[n-1].marks=last;
if(i<n-1 || key==data[n-1].marks)
{
cout<<" \nGiven Marks found at index:"<<i;
cout<<"\nRecord:"<<endl;
cout<<"\n Name: "<<data[i].name<<endl;
cout<<" Roll no. :"<<data[i].roll_no<<endl;
cout<<" Marks :"<<data[i].marks<<endl;
}
else
{
cout<<"\nMarks was not found..........."<<endl;
}
}
void Search ::fibo_search()
{ 
 int key;
cout<<">>\nEnter marks to be search:";
 cin>>key;
 
 int offset = 0;
 int fb_prev2 = 0;
 int fb_prev1 = 1;
 int fb_curr = fb_prev2 + fb_prev1;
 while (fb_curr < n)
 {
 fb_prev2 = fb_prev1;
 fb_prev1 = fb_curr;
 fb_curr = fb_prev2 + fb_prev1;
 }
 
 int i=0;
 
 while (fb_curr > 1)
 {
 i = min(offset+fb_prev2, n-1);
 if (data[i].marks < key)
 {
 fb_curr = fb_prev1;
 fb_prev1 = fb_prev2;
 fb_prev2 = fb_curr - fb_prev1;
 offset = i;
 }
 else if (data[i].marks > key)
 {
 fb_curr = fb_prev2;
 fb_prev1 = fb_prev1 - fb_prev2;
 fb_prev2 = fb_curr - fb_prev1;
 }
 else
 {
 cout<<" \nGiven Marks found at index:"<<i;
 cout<<"\nRecord:"<<endl;
 cout<<"\n Name: "<<data[i].name<<endl;
 cout<<" Roll no. :"<<data[i].roll_no<<endl;
 cout<<" Marks :"<<data[i].marks<<endl;
 break;
 
 }
 }
 
 if(fb_prev1 && data[offset+1].marks == key)
 {
 cout<<" \nGiven Marks found at index:"<<offset+1;
cout<<"\nRecord:"<<endl;
cout<<"\n Name: "<<data[offset+1].name<<endl;
cout<<" Roll no. :"<<data[offset+1].roll_no<<endl;
cout<<" Marks :"<<data[offset+1].marks<<endl;
}
 
else
{
cout<<"\nMarks was not found..........."<<endl;
} 
}
int main()
{
 Search obj;
 int choice;
 
 obj.getdata();
while(1){
 cout<<"\n------------------------------------------------------------\n"<<endl;
 
cout<<"\n 1.Binary search\n 2.Senital search\n 3.Fibonacci search\n 4.Exit"<<endl;
cout<<"Enter your choice:";
cin>>choice;
switch(choice)
{
case 1:
cout<<"\n\n----Binary search----"<<endl;
obj.sort();
cout<<"\nSorted array:"<<endl;
 obj.display();
 obj.binary_search();
break;
case 2:
cout<<"\n\n----Senital search---"<<endl;
cout<<"\nArray:"<<endl;
 obj.display();
 obj.senital_search();
 break;
 
 case 3:
 cout<<"\n\n----Fibonacci search-----"<<endl;
 
 obj.sort();
cout<<"\nSorted array:"<<endl;
 obj.display();
 obj.fibo_search();
 break;
 
 case 4:
 exit(0);
 break;
 default:
 cout<<"\nYou entered invalid choice........";
 } 
 
}
return 0;
}
