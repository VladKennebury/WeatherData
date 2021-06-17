/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Template Class: BST header
    Description:

*/

#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

///Stores root node and children of tree
template <class T>
struct nodeType{
    ///Node within the tree
    T info;
    ///Pointer to left child of node
    nodeType<T> *left;
    ///Pointer to right child of node
    nodeType<T> *right;
};

    /**
	 * @class BST
	 * @brief  Template class that manages functions for Binary Search Tree
	 * Encapsulates struct with root node of the tree, along with
	 * pointers to the left and right children
	 *
	 * @author Vladislav Kennebury
	 * @version 01
	 * @date 08/06/2020
	 *
	 */

template <class T>
class BST
{
    public:

        /**
		 * @brief operator= - Overloaded assignment operator
		 *
		 * Creates a deep copy of an object, which allows either object
		 * to change value without affecting the value of the other
		 * object. Thus, not allowing a shallow copy where pointers
		 * are pointing to the same memory address
		 *
		 *
		 * @param otherTree - BST<T> reference object
		 * @return BST<T>& - reference to BST object of type T
		 */
        BST<T>& operator=(BST<T>& otherTree);

        /**
		 * @brief  isEmpty - Checks if root == 0
		 * Sees whether the tree is empty, by checking if a value is stored in root
		 *
		 * @return boolean
		 */
        bool isEmpty() const;

        /**
		 * @brief  inOrderTraversal - Calls inOrder function recursively
		 * with a function pointer do perform specific actions on the nodes
		 * Traverses left children, node, right children
		 *
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void inOrderTraversal(void(*visit)(T&));

        /**
		 * @brief  preOrderTraversal - Calls preOrder function recursively
		 * with a function pointer do perform specific actions on the nodes.
		 * Traverses node, left children and right children
		 *
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void preOrderTraversal(void(*visit)(T&));

        /**
		 * @brief  postOrderTraversal - Calls postOrder function recursively
		 * with a function pointer do perform specific actions on the nodes.
		 * Traverses the tree from the left children and right children, finishing
		 * with the parent node
		 *
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void postOrderTraversal(void(*visit)(T&));

        /**
		 * @brief  findViaTraversal - Traverses the tree in order to find a specified value
		 * Allows function pointer to interact with reference to the nodes
		 * Calls on findOrder recursively
		 *
		 * @param searchItem - T reference object
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void findViaTraversal(const T& searchItem, void(*visit)(T&)); //Calls postOrder for root

        /**
		 * @brief  deleteTree - Calls destroyTree function to delete the entire tree
		 * including root.
		 *
		 * @return void
		 */
        void deleteTree();

        /**
		 * @brief  nodeSearch - Traverses the tree in order to find a specified value
		 * Returns confirmation if a node matches the parameter
		 *
		 * @param searchItem - T reference object
		 * @return bool
		 */
        bool nodeSearch(const T& searchItem) const;

        /**
		 * @brief  nodeFind - Searches the tree in order to find a specified value
		 * Allows function pointer to interact with reference to a node
		 *
		 * @param findItem - T reference object
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void nodeFind(const T& findItem, void(*visit)(T&)) const;

        /**
		 * @brief  nodeInsert - Adds a specified value into the tree and places the node
		 * in the appropriate position (left/right child or root if 1st value)
		 *
		 * @param insertItem - T reference object
		 * @return void
		 */
        void nodeInsert(T& insertItem);

        /**
		 * @brief  deleteNode - Removes node of specified value if the value is found in the tree.
		 * Other nodes are adjusted for the removal of the node
		 *
		 * @param deleteItem - T reference object
		 * @return void
		 */
        void deleteNode(const T& deleteItem);

        /**
		 * @brief  Copy Constructor - Copies all variables for a new object
		 *
		 * Sets initial values to variables and creates a new date for object
		 *
		 * @param otherBST - BST<T> object which will be copied
		 * @return
		 */
        BST(BST<T>& otherBST);

        /**
		 * @brief Constructor - Initialises root
		 *
		 * @return
		 */
        BST();

        /**
		 * @brief  Deconstructor - Deletes the tree including root
		 *
		 * Frees memory by deleting all the nodes of a tree
		 *
		 * @return
		 */
        ~BST();

    protected:
        ///Pointer to root node
        nodeType<T> *root;

    private:

        /**
		 * @brief  copyTree - Creates a copy of each node of the tree, including all children
		 *
		 * @param copiedTreeRoot - reference of nodeType<T> pointer, otherTreeRoot - reference of nodeType<T> pointer
		 * @return void
		 */
        void copyTree(nodeType<T>* &copiedTreeRoot, nodeType<T>* & otherTreeRoot);

        /**
		 * @brief  deleteTree - Removes the entire tree by destroying the children of
		 * each node finishing with deleting root.
		 *
		 * @param p - reference of nodeType<T> pointer
		 * @return void
		 */
        void destroyTree(nodeType<T>* &p);

        /**
		 * @brief  inOrder - Traverses smallest to largest values
		 * through the presentation of left children, nodes then right children.
		 *
		 * @param p - reference of nodeType<T> pointer
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void inOrder(nodeType<T>* &p, void(*visit)(T&)) const;

        /**
		 * @brief  preOrder - Traverses the node followed by the left child
		 * then right child, root is displayed first.
		 *
		 * @param p - reference of nodeType<T> pointer
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void preOrder(nodeType<T>* &p, void(*visit)(T&)) const;

        /**
		 * @brief  postOrder - Traverses the left child and right child followed by the node,
		 * root is displayed last.
		 *
		 * @param p - reference of nodeType<T> pointer
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void postOrder(nodeType<T>* &p, void(*visit)(T&)) const;

        /**
		 * @brief  findOrder - Recursively traverses the tree in order to find a specified value
		 * Allows function pointer to interact with reference to the node
		 *
		 * @param p - reference of nodeType<T> pointer
		 * @param searchItem - T reference object
		 * @param *visit - function pointer of reference type T
		 * @return void
		 */
        void findOrder(nodeType<T>* &p, const T& searchItem, void(*visit)(T&)) const;

        /**
		 * @brief  deleteFromTree - Removes node of specified value if the value is found in the tree.
		 * Other nodes are adjusted for the removal of the node
		 *
		 * @param p - reference of nodeType<T> pointer
		 * @return void
		 */
        void deleteFromTree(nodeType<T>* &p);
};

template <class T>
BST<T>::BST() //Constructor
{
    root = nullptr; //Initialises root as null pointer
}

template <class T>
BST<T>::~BST() //Deconstuctor to delete memory of the BST
{
    deleteTree();
}

template <class T>
BST<T>& BST<T>::operator=(BST<T>& otherTree) //Overloading Assignment
{
    if(this != &otherTree){
        if(root != nullptr){
            destroyTree(root);
        }
        if(otherTree.root == nullptr){
            root = nullptr;
        }
        else{
            copyTree(root, otherTree.root); //Creates deep copy of dateBST object
        }
    }
    return *this;
}

template <class T>
bool BST<T>::isEmpty() const //Checks if the tree contains any values
{
    return(root == nullptr);
}

template <class T>
void BST<T>::inOrderTraversal(void(*visit)(T&)) //Calls inOrder for root
{
    inOrder(root, *visit);
}

template <class T>
void BST<T>::preOrderTraversal(void(*visit)(T&)) //Calls preOrder for root
{
    preOrder(root, *visit);
}

template <class T>
void BST<T>::postOrderTraversal(void(*visit)(T&)) //Calls postOrder for root
{
    postOrder(root, *visit);
}

template <class T>
void BST<T>::findViaTraversal(const T& searchItem, void(*visit)(T&)) //Calls findOrder for root
{
    findOrder(root, searchItem, *visit);
}

template <class T>
void BST<T>::deleteTree() //Deletes memory of BST after use
{
    destroyTree(root);
}

template <class T>
BST<T>::BST(BST<T>& otherBST) //Copy constructor
{
    if(otherBST.root == nullptr){
        root = nullptr;
    }
    else{
        copyTree(root, otherBST.root); //Creates object is one does not exist
    }
}

template <class T>
void BST<T>::copyTree(nodeType<T>* &copiedTreeRoot, nodeType<T>* & otherTreeRoot)
{
    if(otherTreeRoot == nullptr){
        copiedTreeRoot = nullptr;
    }
    else{
        copiedTreeRoot = new nodeType<T>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->left, otherTreeRoot->left);
        copyTree(copiedTreeRoot->right, otherTreeRoot->right); //Copies all node values for a tree
    }
}

template <class T>
void BST<T>::destroyTree(nodeType<T>* &p) //Deletes tree and all nodes
{
    if(p != nullptr){
        destroyTree(p->left);
        destroyTree(p->right);
        delete p;
        p = nullptr; //Clears all children, finishing with the root node
    }
}

template <class T>
void BST<T>::inOrder(nodeType<T>* &p, void(*visit)(T&)) const //Displays values within the BST in order from
//smallest to largest
{
    if(p != nullptr){
        inOrder(p->left, *visit);
        (*visit)(p->info);
        inOrder(p->right, *visit);
    }
}

template <class T>
void BST<T>::preOrder(nodeType<T>* &p, void(*visit)(T&)) const //Displays values within the BST starting the root, followed by the
// left and right children of a node
{
    if(p != nullptr){
        (*visit)(p->info);
        preOrder(p->left, *visit);
        preOrder(p->right, *visit);
    }
}

template <class T>
void BST<T>::postOrder(nodeType<T>* &p, void(*visit)(T&)) const //Displays values within the BST starting with the left
//and right children of a node, ending with root
{
    if(p != nullptr){
        postOrder(p->left, *visit);
        postOrder(p->right, *visit);
        (*visit)(p->info);
    }
}

template <class T>
void BST<T>::findOrder(nodeType<T>* &p, const T& searchItem, void(*visit)(T&)) const
{
    if(p != nullptr){
        //Loops through the tree recursively calling itself to reset the flow of the function
        if(p->info == searchItem){
            //Function pointer interacs with the node if it matches searchItem
            (*visit)(p->info);
        }
        else if(p->info > searchItem){
            findOrder(p->left, searchItem, *visit);
        }
        else{
            findOrder(p->right, searchItem, *visit);
        }
    }
}

template <class T>
bool BST<T>::nodeSearch(const T& searchItem) const //Searches all nodes of a tree for specified value
{
    nodeType<T> *current; //declares temporary root
    bool found = false;

    if(root == nullptr){ //Checks if tree is empty
        cout << "Tree is empty" << endl;
    }
    else{
        current = root;

        while(current != nullptr && !found){
            if(current->info == searchItem){ //Checks the node, returns true if the value is found
                found = true;
            }
            else if(current->info > searchItem){ //Assigns current to look at the left if the specified value is
                    //smaller than the node, otherwise it is assigned to look at the right child
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
    }
    return found;
}

template <class T>
void BST<T>::nodeFind(const T& findItem, void(*visit)(T&)) const //Searches all nodes of a tree for specified value
{
    nodeType<T> *current; //declares temporary root
    bool found = false;

    if(root == nullptr){ //Checks if tree is empty
        cout << "\n";
    }
    else{
        current = root;

        while(current != nullptr && !found){
            if(current->info == findItem){ //Checks the node, returns true if the value is found
                found = true;
                (*visit)(current->info); //Function pointer interacts only if it matches findItem
            }
            else if(current->info > findItem){ //Assigns current to look at the left if the specified value is
                    //smaller than the node, otherwise it is assigned to look at the right child
                current = current->left;
            }
            else if(current->info < findItem){
                current = current->right;
            }
            else{
                found = false;
            }
        }
    }
}

template <class T>
void BST<T>::nodeInsert(T& insertItem) //Adds a specified value into the tree
{
    nodeType<T> *current; //Declares temporary node
    nodeType<T> *trailCurrent = nullptr;
    nodeType<T> *newNode;

    newNode = new nodeType<T>;
    newNode->info = insertItem;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if(root == nullptr){
        root = newNode;
    }
    else{
        current = root;

        while(current != nullptr){
            trailCurrent = current;

            if(current->info == insertItem){ //Checks for duplicates
                //cout << "Already inserted, no duplicates allowed" << endl;
                return;
            }
            else if(current->info > insertItem){ //Adds specified value to left child if it is smaller than the current node
                current = current->left;
            }
            else{
                current = current->right; //Adds specified value to right child if it is larger than the current node
            }
        }

        if(trailCurrent->info > insertItem){
            trailCurrent->left = newNode;
        }
        else{
            trailCurrent->right = newNode;
        }
    }
}

template <class T>
void BST<T>::deleteFromTree(nodeType<T>* &p) //Deletes value from the tree
{
    nodeType<T> *current; //Declares temporary node
    nodeType<T> *trailCurrent;
    nodeType<T> *temp;

    if(p == nullptr){
        //cout << "Error, Node does not exist" << endl;
    }
    else if(p->left == nullptr && p->right == nullptr){
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if(p->left == nullptr){ //Checks node and children for 0
        temp = p;
        p = temp->right;
        delete temp;
    }
    else if(p->right == nullptr){
        temp = p;
        p = temp->left;
        delete temp;
    }
    else{
        current = p->left;
        trailCurrent = nullptr;

        while(current->right != nullptr){ //Adjusts tree for deletion of node
            trailCurrent = current;
            current = current->right;
        }

        p->info = current->info;

        if(trailCurrent == nullptr){
            p->left = current->left;
        }
        else{
            trailCurrent->right = current->left;
        }

        delete current;
    }
}

template <class T>
void BST<T>::deleteNode(const T& deleteItem) //Deletes node from the tree
{
    nodeType<T> *current;
    nodeType<T> *trailCurrent;
    bool found = false;

    if(root == nullptr){
        cout << "Tree is empty" << endl;
    }
    else{
        current = root;
        trailCurrent = root;

        while(current != nullptr && !found){ //Checks initial node
            if(current->info == deleteItem){
                found = true;
            }
            else{
                trailCurrent = current;
                if(current->info > deleteItem){ //Checks left or right child depending if deleteItem is > or < the node
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }
        }

        if(current == nullptr){
            cout << "Item is not in the tree" << endl;
        }
        else if(found){
            if(current == root){
                deleteFromTree(root);
            }
            else if(trailCurrent->info > deleteItem){ //Calls on deleteFrom Tree function
                deleteFromTree(trailCurrent->left);
            }
            else{
                deleteFromTree(trailCurrent->right);
            }
        }
        else{
            cout << "Item is not in the tree" << endl;
        }
    }
}

#endif // BST_H
