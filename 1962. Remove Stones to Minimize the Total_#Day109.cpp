class Solution {
public:
    
vector<int> H;
int size = -1;
 
// Function to return the index of the
// parent node of a given node
int parent(int i)
{
 
    return (i - 1) / 2;
}
 
// Function to return the index of the
// left child of the given node
int leftChild(int i)
{
 
    return ((2 * i) + 1);
}
 
// Function to return the index of the
// right child of the given node
int rightChild(int i)
{
 
    return ((2 * i) + 2);
}
 
// Function to shift up the node in order
// to maintain the heap property
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i]) {
 
        // Swap parent and current node
        swap(H[parent(i)], H[i]);
 
        // Update i to parent of i
        i = parent(i);
    }
}
 
// Function to shift down the node in
// order to maintain the heap property
void shiftDown(int i)
{
    int maxIndex = i;
 
    // Left Child
    int l = leftChild(i);
 
    if (l <= size && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
 
    // Right Child
    int r = rightChild(i);
 
    if (r <= size && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
 
    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}
 
// Function to insert a new element
// in the Binary Heap
void insert(int p)
{
    size = size + 1;
    H[size] = p;
 
    // Shift Up to maintain heap property
    shiftUp(size);
}
 
// Function to extract the element with
// maximum priority
int extractMax()
{
    int result = H[0];
 
    // Replace the value at the root
    // with the last leaf
    H[0] = H[size];
    size = size - 1;
 
    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(0);
    return result;
}

// Function to get value of the current
// maximum element
int getMax()
{
 
    return H[0];
}
 

 
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0,n=piles.size(),l;
        
        H.resize(n);
        
        for(int i=0;i<n;i++)
        {
            sum+=piles[i];
            insert(piles[i]);
        }
        
        while(k-->0)
        {
            l=extractMax();
            sum-=l/2;
            l=l-(l/2);
            insert(l);
        }
        
        return sum;
    }
};
