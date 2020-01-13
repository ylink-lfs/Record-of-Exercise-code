class LCA {
public:
    int getLCA(int a, int b) {
        int bigger = a > b ? a : b;
        int smaller = bigger == a ? b : a;
        while(bigger > 1 && bigger > smaller)
            bigger /= 2;
        while(!(bigger == 1 && smaller == 1) && bigger != smaller)
        {
            if(bigger > smaller)
                bigger /= 2;
            else
                smaller /= 2;
        }
        return bigger;
    }
};
