class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {
        //"dog", "cat"
        list<int> animal_seq;
        queue<list<int>::iterator> dog_seq;
        queue<list<int>::iterator> cat_seq;
        vector<int> adopt_seq;
        for(const auto& single_op : ope)
        {
            int opt = single_op[0];
            if(opt == 1)
            {
                animal_seq.push_front(single_op[1]);
                if(single_op[1] > 0)
                    dog_seq.push(animal_seq.begin());
                else
                    cat_seq.push(animal_seq.begin());
            }
            else
            {
                //Pop back one animal in list<string>, then pop corresponding animal in queue
                if(single_op[1] == 0 && !animal_seq.empty())
                {
                    int which_animal = animal_seq.back();
                    animal_seq.pop_back();
                    adopt_seq.push_back(which_animal);
                    if(which_animal > 0)
                    {
                        dog_seq.pop();
                    }
                    else
                    {
                        cat_seq.pop();
                    }
                }
                else if(single_op[1] == 1 && !dog_seq.empty())
                {
                    int dog_id = *dog_seq.front();
                    animal_seq.erase(dog_seq.front());
                    dog_seq.pop();
                    adopt_seq.push_back(dog_id);
                }
                else if(single_op[1] == -1 && !cat_seq.empty())
                {
                    int cat_id = *cat_seq.front();
                    animal_seq.erase(cat_seq.front());
                    cat_seq.pop();
                    adopt_seq.push_back(cat_id);
                }
                else
                    ;//omit invalid op
            }
        }
        return adopt_seq;
    }
};
