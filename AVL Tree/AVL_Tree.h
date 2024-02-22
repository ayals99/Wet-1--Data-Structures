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


template <class T>
class AVL_Tree{
private:
    AVL_Node<T>* m_root;
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

    AVL_Node<T>* AUX_find(AVL_Node<T>* currentNode, const T* dataToFind) const{
        if(currentNode == nullptr){
            return nullptr;
        }
        if( *(dataToFind) == *(currentNode->getData())){
            return currentNode;
        }
        else if ( *dataToFind >= *(currentNode->getData())){
            return AUX_find(currentNode->getRight(), dataToFind);
        }
        else{
            return AUX_find(currentNode->getLeft(), dataToFind);
        }
    }

    //// NOTE: This function assumes that T implements the getID() function
    AVL_Node<T>* AUX_find(AVL_Node<T>* currentNode, int Key) const{
        if(currentNode == nullptr){
            return nullptr;
        }
        if( Key == currentNode->getData()->getID()){
            return currentNode;
        }
        else if ( Key >= currentNode->getData()->getID()){
            return AUX_find(currentNode->getRight(), Key);
        }
        else{
            return AUX_find(currentNode->getLeft(), Key);
        }
    }

    bool printInOrder(AVL_Node<T>* node) const{
        if(node == nullptr){
            return true;
        }
        int currentBalanceFactor = node->getBalanceFactor();

        if (currentBalanceFactor == LEFT_IMBALANCE || currentBalanceFactor == RIGHT_IMBALANCE)
        {
            return false;
        }

        if (node->getLeft() != nullptr){
            if ( !( *(node->getData() ) >= *(node->getLeft()->getData() ) ) ){
                return false;
            }
        }

        if(node->getRight() != nullptr)
        {
            if ( !( *(node->getRight()->getData() ) >=  *(node->getData()) ) ){
                return false;
            }
        }
        bool leftStatus = printInOrder(node->getLeft());
        std::cout << *(node->getData()) << " ";
        bool rightStatus = printInOrder(node->getRight());
        return leftStatus && rightStatus;
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
    AVL_Node<T>* AUX_insert(AVL_Node<T>* parent, AVL_Node<T>* currentNode, AVL_Node<T>* newNode){
        // if newNode is larger than currentNode, we go left
        if ( *(currentNode->getData()) >= *(newNode->getData())) {
            // if currentNode has no left child, we can insert newNode as its left child
            if (currentNode->getLeft() == nullptr) {
                currentNode->setLeftChild(newNode);
            }
            // if currentNode has a left child, we need to continue the recursion leftwards
            else {
                currentNode->setLeftChild(AUX_insert(currentNode, currentNode->getLeft(), newNode));
            }
        }
        // if newNode is smaller than currentNode, we go right
        else{
            // if currentNode has no right child, we can insert newNode as its right child
            if (currentNode->getRight() == nullptr) {
                currentNode->setRightChild(newNode);
            }
            // if currentNode has a right child, we need to continue the recursion rightwards
            else {
                currentNode->setRightChild(AUX_insert(currentNode, currentNode->getRight(), newNode));
            }
        }

        // balance the tree and return the new root of the subtree
        currentNode = balance_Node(currentNode);

        // if currentNode is NOT the root of the tree, we need to tell its parent that his children have changed
        if (parent != nullptr){
            if ( *(parent->getData()) >= *(newNode->getData())){
                parent->setLeftChild(currentNode);
            }
            else{
                parent->setRightChild(currentNode);
            }
        }
        
        // notice that if currentNode is the root of the tree, we don't need to tell anyone in this scope that the root has changed

        return currentNode;
    }

    AVL_Node<T>* AUX_find_Minimum_In_Subtree(AVL_Node<T>* currentNode){
        while(currentNode->getLeft() != nullptr){
            currentNode = currentNode->getLeft();
        }
        return currentNode;
    }

    AVL_Node<T>* AUX_find_Maximum_In_Subtree(AVL_Node<T>* currentNode){
        while(currentNode->getRight() != nullptr){
            currentNode = currentNode->getRight();
        }
        return currentNode;
    }
    AVL_Node<T>* AUX_remove(AVL_Node<T>* currentNode, const T* dataToRemove) {
        // Will only enter this function if the tree holds "dataToRemove"
        if (currentNode == nullptr){ // if we didn't find the node we want to remove
            return nullptr;
        }
        // currentNode is not null, we need to see if we arrived at the node we want to remove
        if ( *(dataToRemove) >= *(currentNode->getData())){
            // if the data is equal. This means we've found our node to delete.
            if (currentNode->isLeaf()){
                delete currentNode;
                return nullptr;
            }
            else if (currentNode->hasLeftChildOnly()){
                AVL_Node<T>* replacement = currentNode->getLeft();
                delete currentNode;
                return replacement;
            }
            else if (currentNode->hasRightChildOnly()){
                AVL_Node<T>* replacement = currentNode->getRight();
                delete currentNode;
                return replacement;
            }
            else{ // has two children
                // find the smallest value in right subtree
                AVL_Node<T>* temp = find_Minimum_In_Subtree(currentNode->getRight());
                swapData(currentNode, temp);
                currentNode->setRightChild(AUX_remove(currentNode->getRight(), temp->getData()));
            }
        }
        else if ( *(dataToRemove) >= *(currentNode->getData())) {
            // need to search in the right subtree
            currentNode->setRightChild(AUX_remove(currentNode->getRight(), dataToRemove));
        }
        else{
            // need to search in the left subtree
            currentNode->setLeftChild(AUX_remove(currentNode->getLeft(), dataToRemove));
        }

        return balance_Node(currentNode);
    }

    void swapData(AVL_Node<T>* firstNode, AVL_Node<T>* secondNode){
        if (firstNode == nullptr || secondNode == nullptr){
            return;
        }
        T* temp = firstNode->getData();
        firstNode->setData(secondNode->getData());
        secondNode->setData(temp);
    }

public:
    /** Constructors & Public Functions **/

    AVL_Tree(): m_root(nullptr), m_size(ZERO) {}

    ~AVL_Tree(){
        deleteTree(m_root);
    }

    T* find(const T* dataToFind) const{
        assert(dataToFind != nullptr);
        return AUX_find(m_root, dataToFind)->getData();
    }

    T* find(int Key) const{
        return AUX_find(m_root, Key)->getData();
    }

    bool exists_In_Tree(T* dataToInsert){
        return (bool) find(dataToInsert);
    }

    StatusType insert(T* dataToInsert){
        assert (dataToInsert != nullptr);

        // if data already exists (country/team/contestant are already in tree)
        if (exists_In_Tree(dataToInsert)){
            return StatusType::FAILURE;
        }
        try {
            AVL_Node<T>* newNode = new AVL_Node<T>(dataToInsert);
            if(m_root == nullptr){
                m_root = newNode;
            }
            else {
                AVL_Node<T>* newRoot = AUX_insert(nullptr, m_root, newNode);
                // Check if the root needs to be changed:
                if (m_root != newRoot) {
                    m_root = newRoot;
                }
            }
            m_size++;
            return StatusType::SUCCESS;
        }
        catch (std::bad_alloc& error){
            return StatusType::ALLOCATION_ERROR;
        }
    }


    T* find_Minimum_In_Subtree(AVL_Node<T>* currentNode){
        return AUX_find_Minimum_In_Subtree(currentNode)->getData();
    }
    T* find_Maximum_In_Subtree(AVL_Node<T>* currentNode){
        return AUX_find_Maximum_In_Subtree(currentNode)->getData();
    }




    StatusType remove(T* dataToRemove){
        if (!exists_In_Tree(dataToRemove)){
            return StatusType::FAILURE;
        }
        try{
            m_root = AUX_remove(m_root, dataToRemove);
        }
        catch (std::bad_alloc& error){
            return StatusType::ALLOCATION_ERROR;
        }
        return StatusType::SUCCESS;
    }

    bool printTreeInOrder() const{
        if(m_root == nullptr){
            return true;
        }
        return printInOrder(m_root);
    }

};

#endif //WET_1_DATA_STRUCTURES_AVL_TREE_H