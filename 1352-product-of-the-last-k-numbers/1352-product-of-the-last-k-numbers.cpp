class ProductOfNumbers {
public:
    vector<int> original;
    ProductOfNumbers() {

    }
    
    void add(int num) {
        original.push_back(num);
    }
    
    int getProduct(int k) {
        int n = original.size();
        int i = n-1;
        int prod = 1;
        while(k--){
            prod*= original[i];
            i--;
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */