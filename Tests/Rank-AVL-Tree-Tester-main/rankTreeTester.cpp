/*
 * A Rank/AVL Tree Tester to test your tree implementation
 *
 * Please Read the instructions in the README file before you start

 * You may add any additional functions you need.
 *
 * I would suggest first beginning with a simple tree and then moving on to a more complex one.
 *
 * G O O D  L U C K !
 */
#include "../../AVL Tree/AVL_Tree.h"
#include "../../AVL Tree/AVL_Node.h"
#include "../../GR files/Scripts/wet1util.h"

#include <iostream>
#include <vector>
#include <ostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <memory>
#include <assert.h>
//#include "RankTree.h"

/*
 * is_tree_valid - checks if the tree is valid, meaning that the tree is balanced and the rank is correct
 * @param root - the root of the tree
 * @return true if the tree is valid, false otherwise
 * Should use to make sure your tree is valid after every insertion and deletion
 * If your Node class doesn't use a parent pointer, remove lines 66-84
 * If your tree isn't a Rank Tree, remove lines 56-60
 * if assert happens, put breaking points in "return false" to see where the error is
 */

template<class Key, class getData()>
bool is_tree_valid(AVL_Node<int>*root) {
    if (!root) {
        return true;
    }
    // Checks the height of every node is valid
    if (root->getHeight() != 1 + std::max(root->getLeft()->getHeight(), root->getRight()->getHeight())) {
        std::cout << "Height is not valid" << std::endl;
        return false;
    }
    if (!root->getLeft() && !root->getRight() && root->getHeight() != 0) {
        std::cout << "Leaf Height is not valid" << std::endl;
        return false;
    }
    //checks the Tree is a Binary Search Tree
    if (root->getLeft() && root->getLeft()->key >= root->key) {
        std::cout << "Left son is not smaller than root" << std::endl;
        return false;
    }
    if (root->getRight() && root->getRight()->key <= root->key) {
        std::cout << "Right son is not bigger than root" << std::endl;
        return false;
    }
//    //checks that the rank of every node is valid
//    if (root->weight != 1 + getWeight(root->getLeft()) + getWeight(root->getRight())) {
//        std::cout << "Rank is not valid" << std::endl;
//        return false;
//    }
    //checks that the Balance Factor of every node is valid
    if (std::abs(root->getBalanceFactor()) > 1) {
        std::cout << "Balance Factor is not valid" << std::endl;
        return false;
    }
//    //checks that the parent pointer is valid
//    if (root->parent) {
//        if (root->parent->getLeft() != root && root->parent->getRight() != root) {
//            std::cout << "Parent pointer is not valid" << std::endl;
//            return false;
//        }
//    }
    if (root->getLeft()) {
        if (root->getLeft()->parent != root) {
            std::cout << "Parent's Left Son pointer is not valid" << std::endl;
            return false;
        }
    }
    if (root->getRight()) {
        if (root->getRight()->parent != root) {
            std::cout << "Parent's Right Son pointer is not valid" << std::endl;
            return false;
        }
    }
    return is_tree_valid(root->getLeft()) && is_tree_valid(root->getRight());
}

template<class Key, class getData()>
int getHeight(AVL_Node<int> *root) {
    if (!root) {
        return -1;
    }
    return root->getHeight();
}


template<class Key, class getData()>
int BalanceFactor(AVL_Node<int> *node) {
    if (node == nullptr) {
        return 0;
    }
    int Rheight = -1;
    int Lheight = -1;
    if (node->getRight() != nullptr) {
        Rheight = node->getRight()->getHeight();
    }
    if (node->getLeft() != nullptr) {
        Lheight = node->getLeft()->getHeight();
    }
    return Lheight - Rheight;
}

//template<class Key, class getData()>
//int getWeight(AVL_Node<int> *root) {
//    if (!root) {
//        return 0;
//    }
//    return root->weight;
//}


// A function to print the tree
void print2DHelper(AVL_Node<int> *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process getRight child first
    print2DHelper(root->getRight(), space);

    // Print current node after space
    std::cout<<std::endl;
    for (int i = 10; i < space; i++)
        std::cout<<" ";
    std::cout<<root->getData()<<"\n";

    // Process getLeft child
    print2DHelper(root->getLeft(), space);
}

// Wrapper over print2DHelper()
void print2D(AVL_Node<int> *root)
{
    // Pass initial space count as 0
    print2DHelper(root, 0);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
}
class compare{

public:
    compare() = default;

    int operator()(const int* a,const int* b) const{
        if (*a == *b){
            return EQUAL;
        }
        else if  (*a > *b){
            return FIRST_LARGER;
        }
        else{
            return FIRST_SMALLER;
        }
    }
};
int main(){
    AVL_Tree<int,compare> tree;
    std::vector<int> vector;
    int size = 0;
    int count = 0;
    //determines the size of the tree - change i to test different sizes
    for (int i = 1; i < 200; i++) {
        vector.push_back(i);
        size = i;
    }

    //randomizes the vector, and k is the number of trees to randomize - change k to test different numbers of trees
    for (int k = 1; k < 3; ++k) {
        count = k;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
        std::cout<<"\n     Creating The Tree \n"<<std::endl;
        for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); it++){
            tree.insert(*it);
            assert(is_tree_valid(tree.root));
            if(is_tree_valid(tree.root)){}
            print2D(tree.root);
        }
        std::cout<<"    Deleting The Tree \n"<<std::endl;
        shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
        for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
            tree.remove(*it);
            assert(is_tree_valid(tree.root));
            print2D(tree.root);

        }
        if(k != 1){
            std::cout<<"A New Tree begins \n"<<std::endl;
        }
        tree.deleteTree(tree.root);
        tree.root= nullptr;
    }
    std::cout<<" S U C C E S S"<<std::endl;
    std::cout << '\n';
    if(size < 100 && count < 6){
        std::cout << "Great! Now try a Larger Tree and more Trees " << std::endl;
        std::cout << '\n';
    }
    else if(size < 100){
        std::cout << "Great! Now try a Larger Tree " << std::endl;
        std::cout << '\n';
    }
    else if(count < 6){
        std::cout << "Great! Now try more Trees " << std::endl;
        std::cout << '\n';
    }
    else{
        std::cout << "    Great! " << std::endl;
        std::cout << '\n';
    }

    return 0;
}


