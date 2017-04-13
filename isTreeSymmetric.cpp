//
// Definition for binary tree:
// template<typename T>
struct Tree {
  Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
  T value;
  Tree *left;
  Tree *right;
};
bool isTreeSymmetric(Tree<int> * t) {
    if(t == nullptr) return true;
    if(t->left == nullptr && t->right == nullptr)
        return true;
    if(t->left == nullptr || t->right == nullptr)
        return false;
    return ismirror(t->left,t->right);
}
bool ismirror( Tree<int>* left, Tree<int>* right) {
    if(left == nullptr && right == nullptr)
        return true;
    if(left == nullptr || right == nullptr)
        return false;
    if(left->value != right->value)
        return false;
    
    bool l = ismirror(left->left, right->right);
    bool r = ismirror(right->left,left->right);
    
    if( l && r )
        return true;
    else
        return false;
}
