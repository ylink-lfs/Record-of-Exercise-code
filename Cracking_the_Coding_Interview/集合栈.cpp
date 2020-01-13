class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int sz) {
        vector<vector<int>> res;
        for(const auto& single_op : ope)
        {
            int opt = single_op[0];
            if(opt == 1)
            {
                //Push operation
                int opn = single_op[1];
                if(res.empty() || res.rbegin()->size() == sz)
                {
                    res.push_back(vector<int>());
                    res.rbegin()->push_back(opn);
                }
                else
                {
                    res.rbegin()->push_back(opn);
                }
            }
            else
            {
                res.rbegin()->pop_back();
                //Unsure this operation corresponds to the meaning of question
                if(res.rbegin()->empty())
                {
                    res.pop_back();
                }
            }
        }
        return res;
    }
};
