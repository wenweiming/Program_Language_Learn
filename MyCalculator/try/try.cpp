#include<iostream>

void add_one(int &arr,int len)
{
	int i =0;
	for (i =0;i<len;++i)
	{
		//arr[i] =arr[i]+1;
	}
};

int main(int argc, char *argv[])
{
	int a[] = {1,2,3,4,5,6,7};
	
	add_one(*a,7);

	return 0;
};






























