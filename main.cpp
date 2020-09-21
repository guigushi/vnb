#include<iostream>
#include "vnb.h"
int main()
{
	std::cout<<"hello world"<<std::endl;
	VariableNum v({6, 2, 3, 4, 5, 6});
	std::cout<<v.getMaxV()<<std::endl;
	for (int i = 500; i < 600; i++)
	{
		std::vector<int> &curV = v.split(i);
		for(int j=0;j<curV.size();j++)
		{
			std::cout<<curV[j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
