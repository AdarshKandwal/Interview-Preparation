int trap(vector<int> & height){
    int n=height.size();
    int trapped=0;
    if(n<=2) return 0;
    int left=1;
    int right=n-2;
    int maxRight=height[0];
    int maxLeft=height[n-1];
    while(left <=right){
        if(maxLeft<maxRight){
            
            if(height[left]>maxLeft){
                maxLeft=height[left];
            }
            else{
                trapped=trapped+(maxLeft-height[left]);
            }
            
        left+=1;
        }
        else{
          if(height[right]>maxRight)
            maxRight=height[right];
          else
              trapped =trapped+ (maxRight-height[right]);
          
          right=right-1;
        }
    }
    return trapped;
}
