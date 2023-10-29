#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    char d;
    unsigned frequency;
    MinHeapNode *lChild, *rChild;

    MinHeapNode(char d, unsigned frequency)

    {

        lChild = rChild = NULL;
        this->d = d;
        this->frequency = frequency;
    }
};

//function to compare
struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
    	cout<<"I am in compare struct:"<<endl;
    	cout<<l->frequency<<" "<<r->frequency<<endl;
        return (l->frequency > r->frequency);
    }
};

void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;

    if (root->d != '$')
        cout << root->d << ": " << str << "\n";

    printCodes(root->lChild, str + "0");
    printCodes(root->rChild, str + "1");
}

void HuffmanCodes(char d[], int frequency[], int size)
{
    struct MinHeapNode *lChild, *rChild, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
	
    for (int i = 0; i < size; ++i){
		
        minHeap.push(new MinHeapNode(d[i], frequency[i]));
        cout<<"char is"<<d[i]<<" "<<"frequency is: "<<frequency[i]<<endl;
    }

    while (minHeap.size() != 1)
    {
        lChild = minHeap.top();
        cout<<"Popping this left child"<<" "<<lChild->frequency<<endl;
        minHeap.pop();

        rChild = minHeap.top();
        cout<<"Popping this right child: "<<" "<<rChild->frequency<<endl;
        minHeap.pop();

        top = new MinHeapNode('$', lChild->frequency + rChild->frequency);

        top->lChild = lChild;
        top->rChild = rChild;

        minHeap.push(top);
        cout<<"Now the top is"<<lChild->frequency<<" "<<rChild->frequency<<endl;
    }
    printCodes(minHeap.top(), "");
}

int main()
{

    int size;
    cout << "Enter the number of characters: ";
    cin >> size;

    char arr[size];
    int frequency[size];

    cout << "Enter characters and their frequencies:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i] >> frequency[i];
    }

    
    size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, frequency, size);

    return 0;
}



