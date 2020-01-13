class UnusualAdd {
public:
    int addAB(int A, int B) {
        int n1, n2;
        do {
            n1 = A ^ B;
            n2 = (A & B) << 1;
            A = n1;
            B = n2;
        } while(B);
        return A;
    }
};
