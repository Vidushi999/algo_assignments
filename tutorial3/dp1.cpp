int Solution::lis(const vector<int> &A) {
    //i,jth index are included
    int maxLen=1;
    int longest[A.size()];//max length of subsequence ending with i
    longest[0]=1;
    //need increasing- then +ve
    for(int i=1;i<A.size();i++){
        longest[i]=1;
        for(int j=0;j<i;j++){//previous ending index
            if(A[i]>A[j]){
                if(longest[j]>0){
                    if(longest[i]<longest[j]+1)
                        longest[i]=-1*(longest[j]+1);
                }
                
            }
            else if(A[i]<A[j]){
                if(longest[j]<0){
                    if(longest[i]<-1*(longest[j]-1))
                       longest[i]=-1*(longest[j]-1);
                }
            }
            
        }
        if(longest[i]>0)
        maxLen = max(maxLen,longest[i]);
        else
        maxLen = max(maxLen,-longest[i]);
    }
    return maxLen;
}
