#include<vector>
class VariableNum
{
	std::vector<int> weight; // each vec's weight	
	std::vector<int> v;      // the value of each weight
	int maxV;                // This max value, when each vec gets its largest value
	int size;                // The size of weight, how many elements
public:	
	VariableNum(const std::vector<int>& weight);  // construst with a vector
	std::vector<int>& split(int n);               // construct with a value, returns a ref of v;
	int getMaxV(void);                            // get the value of maxV;
	int getVal(std::vector<int>& v);              // convert a data from vector to int
};

