#include<iostream>
using namespace std;
class Booth
{
	int ar[5]={0},br[5]={0},ar1[5]={0},br1[5]={0};
	int Q=0,x,y;
	public:
		void getdata();
		void binary();
		void compliment();
		void sum();
		void subtract();
		void right_shift();
		void display();
		void value();
};
void Booth::getdata()
{
	int i;
	cout<<"Multiplicant:"<<endl;
	cin>>x;
	cout<<"Multiplier:"<<endl;
	cin>>y;
}
void Booth::binary()
{
	int i,temp1=0,temp2=0;
	if(x<0){
		temp1=1;
		x=-x;
		}
	if(y<0)
	{
		temp2=1;
		y=-y;
	}
	for(i=4;i>=0;i--)
	{
		ar[i]=x%2;
		br[i]=y%2;
		x=x/2;
		y=y/2;
	}
	if(temp1==1)
	{
		int c;
		for(i=4;i>=0;i--)
		{
			if(ar[i]==0)
				ar[i]=0;
			else{
				c=i;
				break;
				}
		}
		for(i=c-1;i>=0;i--)
		{
			if(ar[i]==1){
				ar[i]=0;
			}
			else{
				ar[i]=1;
			}
		}
	}
	for(i=0;i<5;i++){  
		br1[i]=ar[i];
	}

	if(temp2==1)
	{
		int c;
		for(i=4;i>=0;i--)
		{
			if(br[i]==0)
				br[i]=0;
			else{
				c=i;
				break;
				}
		}
		for(i=c-1;i>=0;i--)
		{
			if(br[i]==1)
				br[i]=0;
			else
				br[i]=1;
		}
	}
}
void Booth::compliment()
{
	int i,c;
	for(i=4;i>=0;i--)
	{
		if(br1[i]==0){
			br1[i]=0;
		}
		else{
			c=i;
			break;
		}
	}
	for(i=c-1;i>=0;i--)
	{
		if(br1[i]==1)
			br1[i]=0;
		else
			br1[i]=1;
	}
}
void Booth::sum()
{
	int i,c=0;
	cout<<"ADD"<<endl;
		cout<<"A:";
	for(i=0;i<5;i++)
		cout<<ar1[i];

		cout<<" MC:";
	for(i=0;i<5;i++)
		cout<<ar[i];
		cout<<endl;

	for(i=4;i>=0;i--)
	{
		ar1[i]=ar1[i]+ar[i]+c;

		if(ar1[i]>1)
		{
			ar1[i] = ar1[i] % 2;
			c=1;
		}
		else
			c=0;
	}
}
void Booth::subtract()
{
	int i,c=0;
	cout<<"Substract"<<endl;
		cout<<"A:";
	for(i=0;i<5;i++)
		cout<<ar1[i];
		cout<<" MC:";
	for(i=0;i<5;i++)
		cout<<br1[i];
		cout<<endl;


	for(i=4;i>=0;i--)
	{
		ar1[i]=ar1[i]+br1[i]+c;

		if(ar1[i]>1)
		{
			ar1[i] = ar1[i] % 2;
			c=1;
		}
		else
			c=0;
	}
}
void Booth::right_shift()
{
	cout<<"Right Shift"<<endl;
	int i;
	Q=br[4];
	for(i=3;i>=0;i--)
		br[i+1]=br[i];
	br[0]=ar1[4];
	for(i=3;i>=0;i--)
		ar1[i+1]=ar1[i];
	ar1[0]=ar1[1];
	cout<<"A:";
	for(i=0;i<5;i++)
		cout<<ar1[i];
	cout<<" Q:";
	cout<<endl;
	cout<<"\t";
	for(i=0;i<5;i++){
		
		cout<<br[i];
	}
	cout<<" Q-1:"<<endl;
	cout<<"\t"<<"\t";
	cout<<Q<<endl;
}
void Booth::display()
{
	int i;
	cout<<"#################"<<endl;
	cout<<"MULTIPLICATION RESULT"<<endl;
	for(i=0;i<5;i++)
		cout<<ar1[i];
	for(i=0;i<5;i++)
		cout<<br[i];
		cout<<endl;
	cout<<"************************************"<<endl;
}
void Booth::value()
{
	int i;
	for(i=5;i>0;i--)
	{
		cout<<"Count: "<<i<<endl;
		if(br[4]==1&&Q==0)
			subtract();
		if(br[4]==0&&Q==1)
			sum();
			right_shift();
		cout<<"---------------------------"<<endl;
	}
}
int main()
{
	int i;
	Booth obj;
	obj.getdata();
	obj.binary();
	obj.compliment();
	obj.value();
	obj.display();
	return 0;
}

