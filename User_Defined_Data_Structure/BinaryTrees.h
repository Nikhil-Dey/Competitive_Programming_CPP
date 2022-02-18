class BinaryTree{
    int val;
    BinaryTree* left;
    BinaryTree* right;

    public:

    BinaryTree(){
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    BinaryTree(int val){
        this -> val = val;
        left = nullptr;
        right = nullptr;
    }
};