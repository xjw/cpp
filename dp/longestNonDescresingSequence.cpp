
/**
 * textbook version 
 */
/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) 
        {
                // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i]) 
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = b.size()-1; u < v;) 
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
                // Update b if new value is smaller then previously referenced value 
		if (a[i] < a[b[u]]) 
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}


int main() {
  // int a[] = {1,3,5,2,6,4,7,8,9,5,6};
  // longest_increasing_contigous_sub_sequence(a, sizeof(a)/sizeof(a[0]));

  // int a[] = {1,5,4,6,7,8,2,6,9,7};
  int a[] = {3,4,6,8,9,12};
  int a[] = {2,4,3,5,1,7,6,9,8};
  int size_a = sizeof(a)/sizeof(a[0]);
  getLongestNonDescresingSequenceBinarySearch(a, size_a);
  // int x;
  // cin>>x;
  // cout<<binarySearch(a, size_a,x)<<endl; 
  // getLongestNonDescresingSequence(a, size_a);

  return 1;
}
