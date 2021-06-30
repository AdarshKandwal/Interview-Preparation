vector<vector<int>> merege ( vector<vector<int>> &interval){
    
    vector<vector<int>> meregedinterval;
    if(interval.size()==0) return meregedinterval;
    sort(interval.begin(),interval.end());
    vector<int> temp= meregedinterval[0];
    
    for(auto it:interval){
        if(it[0]<=temp[1])
            temp[1]=max(it[1],temp[1]);
        else 
            meregedinterval.push_back(temp),temp=it;
    }
    
    meregedinterval.push_back(temp);
    return meregedinterval;
    
}
