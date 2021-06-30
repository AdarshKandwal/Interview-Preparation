int LongestConsecutive(vector<int> & nums)
{
 set<int> hasset;
 for(int num : nums) hasset.insert(num);
 int LongestStreak=0;
for(int num : nums){
    if(!hasset.count(num-1))
    {
        int currentNum=num;
        int currentStreak=1;
        while(hasset.count(currentStreak+1)){
            currentNum+=1;
            currentStreak+=1;
        }
        LongestStreak=max(LongestStreak,currentStreak);
    }
}
return LongestStreak;
}
