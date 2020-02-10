#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class bank
{
	float accno, balance, deposit, withdraw;
	char name[25];
	public:
	void getdetails();
	void putdetails();
	void depositamt();
	void withdrawamt();
} s;
void bank::getdetails()
{
	cout<<"We are feeling very blessed to serve you and having you to our group...\nEnter the name of the customer. ";
	gets(name);
	cout<<"Hello "<<name<<"....\n"<<"Please enter account number= ";
	cin>>accno;
	cout<<"Please enter your starting balance= ";
	cin>>balance;
 }
void bank::putdetails()
{
	float accnum, found=0;
	cout<<"Enter your account number.\n Account Number= ";
	cin>>accnum;
	ifstream file("bank.dat");
	file.read((char *) &s, sizeof(bank));
	while(!file.eof())
	{	if(accnum==s.accno)
		 { cout<<"\t\nHello "<<name<<"....\n\tAccount no.= "<<s.accno<<"\t NAME=  " <<name<< "\t Balance=  "<<balance;
		 found=1;
		 break;
		 }
		 else
		 file.read((char *) &s,sizeof(s));
	}file.close();
	  if(found==0)
	cout<<"Record not found....";

}
void bank::depositamt()
{	float dep,accnum, found=0;
	cout<<"Enter your account number\n Account number=";
	cin>>accnum;
	fstream file("bank.dat",ios::ate|ios::in|ios::out);
	int pos=(-1)*sizeof(s);
	file.seekp(pos,ios::cur);
	file.read((char *) &s,sizeof(bank));
	while(!file.eof())
	{	if(accnum==s.accno)
		 {cout<<"Hello "<<name<<"....\n\t Please enter the amount to be deposit...";
		  cin>>dep;
		  s.balance+=dep;
		 file.write((char *) &s,sizeof(bank));
		 cout<<"\t\nHello "<<name<<"....\n\tAccount no. = "<<s.accno<<"\t NAME = " <<name<< "\t Balance = "<<balance;
		 found=1;
		 break;
		 }
		 else
		 file.read((char *)&s,sizeof(s));
	}

	 file.close();
	if(found==0)
	cout<<"record not found";


}

void bank::withdrawamt()
{	float withd,accnum, found=0;
	cout<<"Enter your account number.\n Account number=";
	cin>>accnum;
	fstream file("bank.dat",ios::ate|ios::in|ios::out);
	int pos=(-1)*sizeof(s);
	file.seekp(pos,ios::cur);
	file.read((char *)&s,sizeof(s));
	while(!file.eof())
	{	if(accnum==s.accno)
		 {cout<<"Hello "<<name<<"....\n\t Please enter the amount to be withdrawl...";
		 cin>>withd;
		 s.balance-=withd;
		 file.write((char *)&s,sizeof(s));
		 cout<<"\t\nAccount no. = "<<s.accno<<"\t NAME = " <<name<< "\t Balance = "<<balance;
		 found=1;
		 break;
		 }
		 else
		 file.read((char *)&s,sizeof(s));
	}file.close();
	if(found==0)
	cout<<"record not found";


}
    void main()
    {
int serno,serviceno;
char ch;
clrscr();
cout<<"\t\t\t BANK OF NATION \n\n";
do
{
cout<<"		Choose the service(1/2/3) from the following:: \n 1. New Customer\n 2. Existing customer \n 3.Exit.\n";
cin>>serno;
switch(serno)
{ case 1:
       {	ofstream file("bank.dat",ios::ate);
	s.getdetails();
	file.write((char *) &s, sizeof(bank));  }

case 2:
{cout<<"		Choose the service(1/2/3) from the following:: \n1. View details\n 2. Deposit\n 3. Withdraw\n ";
cin>>serviceno;
if(serviceno==1)
s.putdetails();
else if(serviceno==2)
s.depositamt();
else if(serviceno==3)
s.withdrawamt();
else
 cout<<" Not a VALID SERVICE!... Please try again (type service in thier corresponding numbers(positions)\n";
}
case 3:
getch();
}
cout<<"Do you want to continue??(y/n)";
cin>>ch;
}while(ch=='y'||ch=='Y');
}


