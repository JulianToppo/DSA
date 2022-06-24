
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int minimumLightBulb(int a[], int n, int reach)
{
    int count = 0;
    int i = 0;
    int isFound = 0;

    cout << "Reach: " << reach;
    while (i < n)
    {
        // check for the coverage area of the bulb
        int left = max(0, i - reach + 1);
        int right = i + reach - 1;
        isFound = 0;
        while (right >= left)
        {
            if (a[right] == 1)
            {
                isFound = 1;
                count++;
                i = right + reach;
                // cout<<"right: "<<right<<" "<<i<<" "<<"reach: "<<reach<<"\n";
                break;
            }
            else
            {
                right--;
            }
        }
        if (isFound == 0)
        {
            return -1;
        }
    }
    cout << "count: " << count << "\n";
    return count;
}

// Maximum sum contiguous array (Kadane's Algo)

int maxSumContArray(int a[], int n)
{
    int maxsum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        // first we need to find the maximum such
        // that maximum of all the negataive values is also checkded
        maxsum = max(maxsum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxsum;
}

// partition array into 3 contiguous
int contiguousThreeSum(int A, vector<int> &B)
{

    // 1 2 3 0 3- Array
    // 1 3 6 6 9 -Prefix sum
    // 1 8 5 3 3 -suffix sum

    int count = 0;
    int sum = accumulate(B.begin(), B.end(), 0);
    if (sum % 3 == 0)
    {
        vector<int> prefix(A);
        vector<int> suffix(A);
        int runningSum = 0;
        for (int i = 0; i < A; i++)
        {
            suffix[i] = sum - runningSum; // making a sum array startioing from last
            runningSum += B[i];
            prefix[i] = runningSum;
        }
        const int reqdSum = sum / 3;
        for (int i = 0; i < A; i++)
        {
            if (prefix[i] == reqdSum)
            {
                for (int j = i + 2; j < A; j++)
                {
                    if (suffix[j] == reqdSum)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

//check the back function for checking the last inserted element
//Incase of interval we use start and end for the two values but in vector we 
// find the last inserted element by making use of vector.back()[1]
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    output.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (output.back()[1] >= intervals[i][0])
            output.back()[1] = max(output.back()[1], intervals[i][1]);
        else
            output.push_back(intervals[i]);
    }
    return output;

//      bool mycomp(Interval a,Interval b){
//      return a.start<b.start;
//  }
// vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//     A.push_back(newInterval);
//     sort(A.begin(),A.end(),mycomp);
//     vector<Interval> res;
//     int n=A.size();
//     res.push_back(A[0]);
//     for(int i=1;i<n;i++){
//         if(A[i].start<=res[res.size()-1].end)
//          res[res.size()-1].end=max(res[res.size()-1].end,A[i].end);
//         else
//          res.push_back(A[i]);
//     }
//     return res;
// }
}


//23rd June
//Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 
//using stold 
int solve(vector<string> &A) 
{
    long double a,b,c;
    a = stold(A[0]);
    b = stold(A[1]);
    c = stold(A[2]);
    
    for(int i=3;i<A.size();i++)
    {
        if((a+b+c)>1 && (a+b+c)<2)
            return 1;
            
        //cout<<a<<" "<<b<<" "<<c<<"\n";
        
        if((a+b+c)>=2)
        {
            if(a>b && a>c)
                a=stold(A[i]);
            else
            if(b>a && b>c)
                b=stold(A[i]);
            else
                c=stold(A[i]);
        }
        else
        {
            if(a<b && a<c)
                a=stold(A[i]);
            else
            if(b<a && b<c)
                b=stold(A[i]);
            else
                c=stold(A[i]);
        }
    }
    
    if((a+b+c)>1 && (a+b+c)<2)
        return 1;
    
    return 0;
}

//next permutation
vector<int> nextPermutation(vector<int> &A) {
     int i,j;
    int n = A.size();
    for(i = n - 2;i >= 0;i --)
    {
        if(A[i] < A[i + 1])
            break;
    }
    if(i == -1)
    {
        reverse(A.begin(),A.end());
        return A;
    }
    
    for(j = n - 1;j > i;j --)
    {
        if(A[j] > A[i])
            break;
    }
    swap(A[j],A[i]);
    reverse(A.begin() + i + 1,A.end());
    return A;
        
    
    
}

//Find the maximum difference between j-i s.t. A[i]<A[j]
int findMax(vector<int> a){

    vector<pair<int,int>> v;
    for(int i=0;i<a.size();i++){
        v.push_back(make_pair(a[i],i+1));
    }

    sort(v.begin(),v.end());

    cout<<"V: "<<v.size()<<"\n";
    int m=INT_MAX;
    int ans=0;
    for(int i=0;i<v.size();i++){
        m=min(m,v[i].second);
        ans=max(ans,v[i].second-m);
        
        cout<<v[i].first<<" "<<v[i].second<<" "<<m<<" "<<ans<<" \n";

    }
    return ans;
}


//First missing positive interger
int firstMissingPositive(vector<int> &A) {
    sort(A.begin(),A.end());
     /*for(int i=1;i<=A.size()+1;++i)
     {
        if(find(A.begin(),A.end(),i) != A.end())
        {
            continue;
        }
        else
         return i;
      }*/
      while(A[0]<=0 && (A.begin()!=A.end()) )
      {
          //cout << A[0];
          A.erase(A.begin());
      }
      if(!A.empty())
      {
        vector<int>::iterator it = unique(A.begin(),A.end());
        A.resize(distance(A.begin(),it));
        for(int i=0;i<A.size();++i)
        {
            if(A[i]!=i+1)
              return i+1;
        }
          
      }
      else
      return 1;
    
}

//n/3 using moore's voting algo
// CPP program to find if any element appears
// more than n/3.
int appearsNBy3(vector<int> a, int n)
{
	int count1 = 0, count2 = 0;
	int first=INT_MAX , second=INT_MAX ;

	for (int i = 0; i < n; i++) {

		// if this element is previously seen,
		// increment count1.
		if (first == arr[i])
			count1++;

		// if this element is previously seen,
		// increment count2.
		else if (second == arr[i])
			count2++;
	
		else if (count1 == 0) {
			count1++;
			first = arr[i];
		}

		else if (count2 == 0) {
			count2++;
			second = arr[i];
		}

		// if current element is different from
		// both the previously seen variables,
		// decrement both the counts.
		else {
			count1--;
			count2--;
		}
	}

	count1 = 0;
	count2 = 0;

	// Again traverse the array and find the
	// actual counts.
	for (int i = 0; i < n; i++) {
		if (arr[i] == first)
			count1++;

		else if (arr[i] == second)
			count2++;
	}

	if (count1 > n / 3)
		return first;

	if (count2 > n / 3)
		return second;

	return -1;
}


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    // enter the elements
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // cout<<minimumLightBulb(a, n, 3); // here 3 is the maximmum reach of the bulb

   // cout << maxSumContArray;

    cout<<findMax(a);
    return 0;
}