class ProductOfNumbers {
public:
    vector<int> p;
    int lzi=-1;

    ProductOfNumbers() {
        p.push_back(1); 
    }

    void add(int num) {
        if (num == 0) {
            p.clear();
            p.push_back(1);
            lzi = p.size();
        } else {
            int last = p.back();
            p.push_back(last * num);
        }
    }

    int getProduct(int k) {
        int n = p.size();
        if (k >= n) return 0;
        return p[n - 1] / p[n - 1 - k];
    }
};
