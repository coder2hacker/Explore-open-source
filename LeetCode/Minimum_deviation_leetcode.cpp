int minimumDeviation(vector<int>& a) {
    int n=a.size();
    priority_queue<int>pq;
    
    int diff = INT_MAX;
    int min_ele = INT_MAX;
    for(auto i:a)
    {
        if(i%2)
            i*=2;
        min_ele = min(min_ele,i);
        pq.push(i);
    }
    
    while(pq.top() % 2 == 0){
        int max_ele = pq.top();
        pq.pop();
        diff = min(diff,max_ele-min_ele);
        min_ele = min(min_ele,max_ele/2);
        pq.push(max_ele/2);
    }
    return min(diff,pq.top()-min_ele);
}

//Basically the answer here always comes out to be minimum as :
/*
1. As we are multiplying all the odd numbers by 2 all the numbers are converted to even,
so even if in the first step the number when divided by 2 gets converted to odd and is
maximum it will give me minimum as the preious odd numbers have already been 
increased.

2. And as the minimum is taken at each step so all the possibilities have been taken so let's say 
say even if we had the possibility of getting the minimum from one of the minimum numbers 
being odd itself would be covered as it would be divided by two and would be converted to
odd when it was even.

3. As there are two choices to be considered whether to multiply the odd number by two or 
to make it even we multiply inititally all the odd numbers itself by 2 which make them even
thus eliminating one choice.
*/