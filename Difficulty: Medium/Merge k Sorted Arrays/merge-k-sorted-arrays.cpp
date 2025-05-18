//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    class HeapNode {
      public:
        int data;
        int arrIndex;
        int elemIndex;

        HeapNode(int data, int arrIndex, int elemIndex) {
            this->data = data;
            this->arrIndex = arrIndex;
            this->elemIndex = elemIndex;
        }
    };

    class compare {
      public:
        bool operator()(HeapNode a, HeapNode b) {
            return a.data > b.data;
        }
    };

    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<HeapNode, vector<HeapNode>, compare> heap;

        for (int i = 0; i < K; i++) {
            if (!arr[i].empty()) {
                heap.push(HeapNode(arr[i][0], i, 0));
            }
        }

        vector<int> result;

        while (!heap.empty()) {
            HeapNode temp = heap.top();
            heap.pop();

            result.push_back(temp.data);

            int nextIndex = temp.elemIndex + 1;
            if (nextIndex < arr[temp.arrIndex].size()) {
                heap.push(HeapNode(arr[temp.arrIndex][nextIndex], temp.arrIndex, nextIndex));
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends