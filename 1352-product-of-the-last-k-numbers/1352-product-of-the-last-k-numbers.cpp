class ProductOfNumbers {
public:
// int n=input.size();
// vector<int> result(n,null);
vector<int> ans;
    ProductOfNumbers() { }

    void add(int num) { ans.push_back(num); }

    int getProduct(int k) {
        int n = ans.size();
        int prd = 1;
        for (int i = n - 1; i >=n - k; i--) {
            prd = prd * ans[i];
            

        }
       return prd;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */