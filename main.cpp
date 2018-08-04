#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{

    int key;
    struct node *left, *right;
};
// type structure node, pointer function name newNode
struct node *newNode(int item){
    cout << "New Node" << item << endl;
    // struct node type temp pointer declare allocating size of struct node
    // value in temp and two null node create
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->right = temp->left = NULL;
    cout << "New Node Temp" << temp->key << endl;
    return temp;

};

struct node* insertNode(struct node* node, int key){
    if (node == NULL){
        cout << "Null " << key << endl;
        return newNode(key);

    }
    // otherwise recure down the tree
    if (key < node->key){
        node->left = insertNode( node->left, key);
        cout << "Left Node key" << key << endl;
        cout << "Left Node->Key" << node->key << endl;
        cout << "Left Node->left" << node->left << endl;
     }
    else if (key > node->key){                      //51 > 50
        node->right = insertNode(node->right, key);
        cout << "Right Node Key" << key << endl;
        cout << "Right Node -> Key" << node->key << endl;
        cout << "Right Node ->right" << node->right << endl;
    }


    return node;

};

void inorder(struct node *root){
    if(root!=NULL){

        inorder(root->left);
        cout<< "In order left node" << root->key << endl;
        inorder(root->right);
        cout<< "In order right node" << root->key << endl;
    }

}

void isPresent(struct node *root, int key){
    if(root!=NULL){
        if(root->key != key){
            isPresent(root->left, key);
            isPresent(root->right, key);
            //cout<< root->key << "isPresent left node" << key << endl;
        }
        else if ( root->key == key)
            cout << key << " is present in the tree" << endl;
     }
}

int main(){
    // struct node type root pointer declare
    struct node *root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 51);
    insertNode(root, 55);
    insertNode(root, 58);
    insertNode(root, 59);

    inorder(root);

    isPresent(root, 158);
    //cout << searchNumber << endl;

    //cout << &root << endl;


    //cout << root << endl;

    //cout << node->key << endl;
    return 0;
}
