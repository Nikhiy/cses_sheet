#include <bits/stdc++.h>
using namespace std;
class SGTree{
    public:
    vector<int> seg,la;
    SGTree(int n){
        seg.resize(4*n+1);
        la.resize(4*n+1);
    }
    void build(int ind,int low,int high,vector<int>& arr){
        if(low==high){
            seg[ind]=arr[left];
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
    }
    void update(int ind,int low,int high,int l,int r,int val){
        //checking if previous update is left to update doing it first
        if(la[ind]!=0){
            seg[ind]=(r-l+1)*la[ind];
            //telling child that you also have to update in teh future when queried upon
            if(low!=high){
                la[2*ind+1]+=la[ind];
                la[2*ind+2]+=la[ind];
            }
            la[ind]=0;
        }
        //no overlap  
        // possible conditions( low high l r  low high )
        if(high<l || r<low) return;
        //complete overlap
        //condition (l low high r)
        if(l<=low && high<=r){
            seg[ind]+=(high-low+)*val;
            if(low!=high){
                la[2*ind+1]+=val;
                la[2*ind+2]+=val;
            }
            return;
        }
        //partial overlap case
        int mid=(low+high)/2;
        update(2*ind+1,low,mid,l,r,val);
        update(2*ind+2,mid+1,high,l,r,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind,int low,int high,int l,int r){
        //update any previous upadtes
        if(la[ind]!=0){
            seg[ind]+=(high-low+1)*la[ind];
            if(low != high) {
				lazy[2*ind+1] += lazy[ind]; 
				lazy[2*ind+2] += lazy[ind]; 
			}
			lazy[ind] = 0;
        }
        // no overlap return 0; 
		if(high < l or r < low) {
			return 0; 
        }
		// complete overlap 
		if(low>=l && high <= r) return seg[ind]; 
        //partial overlap
		int mid = (low + high) >> 1; 
		int left = query(2*ind+1, low, mid, l, r);
		int right = query(2*ind+2, mid+1, high, l, r);
		return left + right; 
    }
};