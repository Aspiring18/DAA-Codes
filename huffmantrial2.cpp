#include<iostream>
#include<queue>
using namespace std;

struct Minheapnode
{
	char d;
	unsigned frequency;
	Minheapnode *lchild, *rchild;
	Minheapnode(char d, int frequency)
	{
		lchild = rchild = NULL;
		this->d = d;
		this->frequency = frequency;
	}
};

struct compare
{
	bool operator()(Minheapnode *l, Minheapnode *r)
	{
		return( l->frequency > r->frequency);
	}
};

int printnodes ( struct Minheapnode *root, string str)
{
	if(!root)
	return 0;
	
	if(root->d != '$')
	{
		cout<<root->d<<":"<<str<<"\n";
	}
	printnodes(root->lchild, str+'0');
	printnodes(root->rchild, str+'1');
}

void HuffmanCode(char d[], int frequency[], int size)
{
	struct Minheapnode *lchild, *rchild, *top;
	
	priority_queue<Minheapnode *, vector<Minheapnode *>, compare> minHeap;
	for(int i=0; i<size; ++i)
	{
		minHeap.push(new Minheapnode(d[i], frequency[i]));
	}
	while(minHeap.size() != 1)
	{
		lchild = minHeap.top();
		minHeap.pop();
		
		rchild = minHeap.top();
		minHeap.pop();
		
		top = new Minheapnode('$', lchild->frequency + rchild->frequency);
		top->lchild = lchild;
		top->rchild = rchild;
		minHeap.push(top);
	}
	printnodes(minHeap.top(), " ");
}

int main()
{
	int size;
	int frequency[size];
	char arr[size];
	cout<<"Enter the size of elements: ";
	cin>>size;
	
	cout<<"Enter elemnts and their frequency: ";
	for(int i=0; i<size; i++)
	{
		cin>>arr[i]>>frequency[i];
	}
	
	size = sizeof(arr)/sizeof(arr[0]);
	HuffmanCode(arr, frequency, size);
	

	return 0;
}
