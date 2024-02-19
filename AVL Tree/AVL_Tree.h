#ifndef WET_1_DATA_STRUCTURES_AVL_TREE_H
#define WET_1_DATA_STRUCTURES_AVL_TREE_H

#include "AVL_Node.h"
#include "wet1util.h"
#include <cassert>
#include <iostream>

static const int LEFT_IMBALANCE = 2;
static const int RIGHT_IMBALANCE = -2;

static const int EQUAL = 0;
static const int FIRST_LARGER = 1;
static const int FIRST_SMALLER = -1;





template <class T, typename comparisonFunction>
class AVL_Tree{
private:
    AVL_Node<T>* m_root;
    comparisonFunction m_comparisonFunction;
    int m_size;

    /**Rotation Utility Functions **/

    AVL_Node<T>* rightRotation(AVL_Node<T>* originalRoot){
        assert(originalRoot != nullptr);
        assert(originalRoot->getLeft() != nullptr);

        AVL_Node<T>* newRoot = originalRoot->getLeft();
        originalRoot->setLeftChild(newRoot->getRight());
        newRoot->setRightChild(originalRoot);
        originalRoot->updateHeight();
        newRoot->updateHeight();
        return newRoot;
    }

    AVL_Node<T>* leftRotation(AVL_Node<T>* originalRoot){
        assert(originalRoot != nullptr);
        assert(originalRoot->getRight() != nullptr);

        AVL_Node<T>* newRoot = originalRoot->getRight();
        originalRoot->setRightChild(newRoot->getLeft());
        newRoot->setLeftChild(originalRoot);
        originalRoot->updateHeight();
        newRoot->updateHeight();
        return newRoot;
    }

    AVL_Node<T>* LR_Rotation(AVL_Node<T>* originalRoot){
        assert(originalRoot != nullptr);
        assert(originalRoot->getLeft() != nullptr);
        assert(originalRoot->getLeft()->getRight() != nullptr);

        originalRoot->setLeftChild( leftRotation(originalRoot->getLeft()) );
        return rightRotation(originalRoot);
    }

    AVL_Node<T>* RL_Rotation(AVL_Node<T>* originalRoot){
        assert(originalRoot != nullptr);
        assert(originalRoot->getRight() != nullptr);
        assert(originalRoot->getRight()->getLeft() != nullptr);

        originalRoot->setRightChild( rightRotation(originalRoot->getRight()) );
        return leftRotation(originalRoot);
    }

    AVL_Node<T>* balance_Node(AVL_Node<T>* root){
        assert(root != nullptr);

        if(root->getBalanceFactor() == LEFT_IMBALANCE){
            if(root->getLeft()->getBalanceFactor() >= ZERO){
                return rightRotation(root);
            }
            else{
                return LR_Rotation(root);
            }
        }

        if(root->getBalanceFactor() == RIGHT_IMBALANCE){
            if(root->getRight()->getBalanceFactor() <= ZERO){
                return leftRotation(root);
            }
            else{
                return RL_Rotation(root);
            }
        }

        root->updateHeight();
        return root;
    }

    /** Insert & Remove Recursive Utility Functions **/

    AVL_Node<T>* AUX_find(AVL_Node<T>* currentNode, const T* dataToFind,
                          comparisonFunction compare) const{
        if(currentNode == nullptr){
            return nullptr;
        }
        if(compare(dataToFind, currentNode->getData()) == EQUAL){
            return currentNode;
        }
        else if(compare(dataToFind, currentNode->getData()) == FIRST_LARGER){
            return AUX_find(currentNode->getRight(), dataToFind, compare);
        }
        else{
            return AUX_find(currentNode->getLeft(), dataToFind, compare);
        }
    }

//    AVL_Node<T>* AUX_insert(AVL_Node<T>* parent, AVL_Node<T>* currentNode, AVL_Node<T>* newNode,
//                            comparisonFunction compare){
//        int initialHeight = currentNode->getHeight();
//
//        if (compare(currentNode->getData(), newNode->getData()) == FIRST_LARGER ){
//            currentNode = leftRecursion(parent, currentNode, newNode, compare);
//        }
//        else{
//            currentNode = rightRecursion(parent, currentNode, newNode, compare);
//        }
//
//        if (currentNode->getHeight() != initialHeight || parent == nullptr){
//            return currentNode;
//        }
//        else{
//            return nullptr;
//        }
//    }
//
//    AVL_Node<T>* leftRecursion(AVL_Node<T>* parent, AVL_Node<T>* currentNode, AVL_Node<T>* newNode,
//                               comparisonFunction compare){
//        if (currentNode->getLeft() == nullptr){
//            currentNode->setLeftChild(newNode);
//            balance_Node(currentNode); // Will only update height, because an added node is always a leaf
//        }
//        else{
//            AVL_Node<T>* temp = AUX_insert(currentNode, currentNode->getLeft(), newNode, compare);
//            if(temp == nullptr){
//                return nullptr;
//            }
//            else{
//                currentNode->setLeftChild(temp);
//            }
//            currentNode = balance_Node(currentNode);
//            if (parent != nullptr){
//                parent->setLeftChild(currentNode);
//            }
//        }
//        return currentNode;
//    }
//
//    AVL_Node<T>* rightRecursion(AVL_Node<T>* parent, AVL_Node<T>* currentNode,
//                                AVL_Node<T>* newNode, comparisonFunction compare){
//        if (currentNode->getRight() == nullptr){
//            currentNode->setRightChild(newNode);
//            balance_Node(currentNode); // Will only update height, because an added node is always a leaf
//        }
//        else{
//            AVL_Node<T>* temp = AUX_insert(currentNode, currentNode->getRight(), newNode, compare);
//            if(temp == nullptr){
//                return nullptr;
//            }
//            else{
//                currentNode->setRightChild(temp);
//            }
//            currentNode = balance_Node(currentNode);
//            if (parent != nullptr){
//                parent->setRightChild(currentNode);
//            }
//        }
//        return currentNode;
//    }

    void printInOrder(AVL_Node<T>* node) const{
        if(node == nullptr){
            return;
        }
        printInOrder(node->getLeft());
        std::cout << *(node->getData()) << " ";
        printInOrder(node->getRight());
    }

    void deleteTree(AVL_Node<T>* node){
        if(node == nullptr){
            return;
        }
        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }

    // New implementation of AUX_insert
    AVL_Node<T>* AUX_insert(AVL_Node<T>* parent, AVL_Node<T>* currentNode, AVL_Node<T>* newNode,
                            comparisonFunction compare){
        // if newNode is larger than currentNode, we go left
        if (compare(currentNode->getData(), newNode->getData()) == FIRST_LARGER) {
            // if currentNode has no left child, we can insert newNode as its left child
            if (currentNode->getLeft() == nullptr) {
                currentNode->setLeftChild(newNode);
            }
                // if currentNode has a left child, we need to continue the recursion leftwards
            else {
                currentNode->setLeftChild(AUX_insert(currentNode, currentNode->getLeft(), newNode, compare));
            }
            // balance the tree and return the new root of the subtree
            currentNode = balance_Node(currentNode);
            // if currentNode is NOT the root of the tree, we need to tell its parent that his children have changed
            if (parent != nullptr){
                parent->setLeftChild(currentNode);
            }
            // notice that if currentNode is the root of the tree, we don't need to tell anyone in this scope that the root has changed
        }
            // if newNode is smaller than currentNode, we go right
        else{
            // if currentNode has no right child, we can insert newNode as its right child
            if (currentNode->getRight() == nullptr) {
                currentNode->setRightChild(newNode);
            }
                // if currentNode has a right child, we need to continue the recursion rightwards
            else {
                currentNode->setRightChild(AUX_insert(currentNode, currentNode->getRight(), newNode, compare));
            }
            // balance the tree and return the new root of the subtree
            currentNode = balance_Node(currentNode);
            // if currentNode is NOT the root of the tree, we need to tell its parent that his children have changed
            if (parent != nullptr){
                parent->setRightChild(currentNode);
            }
            // notice that if currentNode is the root of the tree, we don't need to tell anyone in this scope that the root has changed
        }
        return currentNode;
    }

public:

    /** Constructors & Public Functions **/

    AVL_Tree(): m_root(nullptr), m_size(ZERO){}

    ~AVL_Tree(){
        deleteTree(m_root);
    }

    AVL_Node<T>* find(const T* dataToFind) const{
        assert(dataToFind != nullptr);
        comparisonFunction compare;
        return AUX_find(m_root, dataToFind, compare);
    }

    bool exists_In_Tree(T* dataToInsert){
        return (bool) find(dataToInsert);
    }

    StatusType insert(T* dataToInsert){
        assert (dataToInsert != nullptr);

        comparisonFunction compare;

        if (exists_In_Tree(dataToInsert)){// if data already exists (country/team/contestant are already in tree)
            return StatusType::FAILURE;
        }

        AVL_Node<T>* newNode = new AVL_Node<T>(dataToInsert);

        if (newNode == nullptr){
            return StatusType::ALLOCATION_ERROR;
        }

        if(m_root == nullptr){
            m_root = newNode;
        }
        else {
            AVL_Node<T>* newRoot = AUX_insert(nullptr, m_root, newNode, compare);
            // Check if the root needs to be changed:
            if (m_root != newRoot) {
                m_root = newRoot;
            }
        }
        m_size++;
        return StatusType::SUCCESS;
    }



    StatusType remove(T* dataToRemove){
        if (!exists_In_Tree(dataToRemove)){
            return StatusType::FAILURE;
        }

    }


    void printTreeInOrder() const{
        if(m_root == nullptr){
            return;
        }
        printInOrder(m_root);
    }


};

#endif //WET_1_DATA_STRUCTURES_AVL_TREE_H