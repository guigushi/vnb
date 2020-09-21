#include<iostream>
#include<vector>
#include<map>

std::vector<int> weight = {4,6,2,16,5};
int getMaxV(void)
{
	int v = 0;
	for(int i=0;i<weight.size();i++)
	{
		v = v*weight[i] + weight[i]-1;
	}
	return v;
}
int splitWeight(int v)
{
	std::cout<<v<<":";
	int curWeight = 1;
	int val = 0;
	for(int i=0;i<weight.size();i++)
	{
		val = v % weight[i];
		v = v / weight[i];
		std::cout<<val<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
int main()
{
	int maxV = getMaxV();
	for(int i=0;i<=maxV;i++)
	{
		splitWeight(i);
	}
	return 0;
}

