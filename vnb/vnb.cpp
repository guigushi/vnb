#include"vnb.h"

VariableNum::VariableNum(const std::vector<int>& weight)
{
	this->weight = weight;
	this->size = weight.size();
	this->maxV = 1;
	for(int i=0;i<this->size;i++)
	{
		this->maxV *= weight[i];
	}
	this->v = std::vector<int>(this->size, 0);
}
std::vector<int>& VariableNum::split(int n)
{
	for(int i=0;i<this->size;i++)
	{
		this->v[i] = n % this->weight[i];
		n /= this->weight[i];
	}
	return this->v;
}
int VariableNum::getVal(std::vector<int>& v)
{
	int val = 0;
	int count = this->size < v.size()?this->size:v.size();
	for(int i=0;i<count;i++)
	{
		val = val*this->weight[i] + v[i];
	}
	return val;
}
int VariableNum::getMaxV(void)
{
	return this->maxV - 1;
}

