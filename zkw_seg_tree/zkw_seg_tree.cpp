#include<vector>
#include<iostream>
typedef long long LL;
class zkw_seg_tree
{
	private:
		int M;  // it is the border of the child and parent; M + 1 is the first child, and M-1 is the last parent
		int N;  // the size of the original num size;
		std::vector<LL> sum;
		std::vector<LL> tag;
	public:
		zkw_seg_tree(int n);
		zkw_seg_tree(const std::vector<int>& array);
		void update(int from, int to, LL bias); // from include and to not include
		LL query(int from, int to);  // from include, and to not include
};
zkw_seg_tree::zkw_seg_tree(int n)
{	M = 1;
	while(M < n + 2) M <<= 1;
	sum.resize(2 * M, 0);
	tag.resize(2 * M, 0);
}
zkw_seg_tree::zkw_seg_tree(const std::vector<int>& array)
{
	int n = array.size();
	M = 1;
	while(M < n + 2) M <<= 1;
	sum.resize(2 * M, 0);
	tag.resize(2 * M, 0);
	for(int i = 0; i < n; ++i)
	{
		sum[M+1+i] = array[i];
	}
	for(int i = M-1; i; --i)
	{
		sum[i] = sum[i << 1] + sum[i << 1 | 1];
	}
}
void zkw_seg_tree::update(int l, int r, LL bias)
{
	LL len = 1, lc = 0, rc = 0;
	// l ^ r ^ 1è èmeans l and r not the directly sun of a common parent
	// l >> 1 and r >> 1 means to go to the node of their parents
	for(l = l + M, r = r + M + 1; l ^ r ^1; l >>= 1, r >>= 1, len <<= 1)
	{
		if( ~l & 1)  // first calculate the op ~, and then cal the op &, this means the lowest of l is 0, it is to say, l is the left child of a parent
		{
			tag[l+1] += bias; // l+1 means the right child, the right child's tag should add the data
			lc += len;  // len means the sons of current node;
		}
		// this means r's lowest bit if 1, means it is the right child of a parent
		if( r & 1)
		{
			tag[r-1] += bias;
			rc += len;
		}
		sum[l >> 1] += bias * lc; // update the sum,
		sum[r >> 1] += bias * rc;
	}
	for(lc += rc, l >>= 1;l;l>>=1) // update to the top node
	{
		sum[l] += bias*lc;
	}
}
LL zkw_seg_tree::query(int l, int r)
{
	LL res = 0, len = 1, lc = 0, rc = 0;
	for(l = l + M, r = r + M + 1; l^r^1; l >>= 1, r >>= 1, len <<= 1)
	{
		if(~l & 1)
		{
			res += sum[l+1] + tag[l+1] * len;
			lc += len;
		}
		if(r & 1)
		{
			res += sum[r-1] + tag[r-1] * len;
			rc += len;
		}
		res += tag[l>>1] * lc;
		res += tag[r>>1] * rc;
	}
	for(lc += rc, l >>= 1;l; l >>= 1)
	{
		res += tag[l] * lc;
	}
	return res;
}
int main()
{
	zkw_seg_tree my_tree(10);
	my_tree.update(0, 10, 4);
	std::cout<<my_tree.query(0, 5)<<std::endl;
	zkw_seg_tree my_tree2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
	std::cout<<my_tree2.query(1, 5)<<std::endl;
	for(int i=0; i <= 10; i++)
	{
		std::cout<<0<<"-"<<i<<":"<<my_tree2.query(0, i)<<std::endl;
	}
	std::cout<<std::endl;
	for(int i=1; i <= 10; i++)
	{
		std::cout<<1<<"-"<<i<<":"<<my_tree2.query(1, i)<<std::endl;
	}
	return 0;
}
