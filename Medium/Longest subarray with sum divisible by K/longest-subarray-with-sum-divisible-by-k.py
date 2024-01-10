#User function Template for python3
class Solution:
    def longSubarrWthSumDivByK (self,arr,  n, k) : 
        if k==1:
            return n
        p=[]
        r=[]
        p.append(arr[0])
        r.append(arr[0]%k)
        for i in range(1,len(arr)):
            p.append(p[i-1]+arr[i])
            r.append(p[i]%k)
        d={}
        m=0
        for i in range(len(r)):
            if r[i]!=0:
                if r[i] not in d.keys():
                    d[r[i]]=i
                else:
                    m=max(m,(i-d[r[i]]))
            else:
                m=max(m,i+1)
        return m
            
        







#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

	for _ in range(0,int(input())):
		n, K = map(int ,input().split())
		arr = list(map(int,input().strip().split()))
		ob = Solution()
		res = ob.longSubarrWthSumDivByK(arr, n, K)
		print(res)




# } Driver Code Ends