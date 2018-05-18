#include<iostream>
using namespace std;

int main()
{
    /*
    n -> number of monkeys
    monk[] -> it is the strength of monkeys
    inj -> max inkjuries
    health -> health which is set to 2000
    cnt -> counts length of substring of max length that can withstand following criteria
    mx -> holds the maximum value 
    left -> pointer which holds the start of substring
    right -> pointer which holds the end of substring
    */
    
	long long int left,cnt,right,monk[1000007],n,mx,inj=1,health=2000;
	
	/*
	input taken 
	*/
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>monk[i];
	}
	
	/*-----------------Initializatin of values--------------------*/
	left=0;right=0;mx=0;cnt=0;
	while(right!=n)
	{
	    //cout<<cnt<<":"<<monk[right]<<":"<<health<<endl;
		if(health-monk[right]>0 && inj*monk[right]<1000000)    // it updates the cnt if following monkey can be defeated
		{
			health-=monk[right];
			inj*=monk[right];
			right++;
			cnt++;
		}
		else if(left!=right)               // it terminates the cnt(cnt=0)and updates the mx value when following monkey cannot be defeated
		{
			health+=monk[left];
			inj/=monk[left];
			left++;
			if(cnt>mx)
			{
				mx=cnt;
			}
			cnt=0;			
		}
		else
		{
		    right++;
		    left++;
		}
	}
	cout<<mx<<endl;    // prints output
	return 0;
}
