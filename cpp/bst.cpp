#include <iostream>
using namespace std;

class kvpair{
    private:
     int key;
     string value;
     kvpair* left;
     kvpair* right;
     kvpair* parent;
    public:
     kvpair(int k = -1, string s = " "){
        key = k;
        value = s;
        left = right = parent = nullptr;
     }
     void copykvpair(kvpair* p){
        key = p->key;
        value = p->value;
     }
     friend class bst;

};

class bst{
    private:
     kvpair* root;
    public:
     bst(){
        root = nullptr;
     }
     bst(kvpair* p){
        root = p;
     }
     void InsertHelp(KVPair *treeroot, KVPair *kvp)
  {

    if (kvp->key < treeroot->key)
      {
	if (treeroot->left == nullptr)
	  {
	    treeroot->left = kvp;
	    kvp->parent = treeroot;
	    return;
	  }
	InsertHelp(treeroot->left, kvp);
      }

    if (kvp->key > treeroot->key)
      {
	if (treeroot->right == nullptr)
	  {
	    treeroot->right = kvp;
	    kvp->parent = treeroot;
	    return;
	  }
		
	InsertHelp(treeroot->right, kvp);
      }

    if (kvp->key == treeroot->key)
      {
	// Duplicate key; nothing to be done
	return;
      }
  }

  kvpair* search(int k){
    searchhelp(root,k);
  }
  kvpair* searchhelp(kvpair* subroot, int k){
    if(subroot == nullptr) return  nullptr;
    if(k == subroot->key) return subroot;
    if(k < subroot->key){
        searchhelp(subroot->left,k);
    }
    else{
        searchhelp(subroot->right, k);
    }
    return nullptr;
  }
  kvpair* findmin(kvpair* k){
    kvpair* tmp = k;
    while(tmp->left !=  nullptr){
        tmp = tmp->left;
    }
    return tmp;
  }

  void deleteroot(kvpair* kvp)
  {
    if(kvp->left ==  nullptr && kvp->right== nullptr){
        delete kvp;
    }
    else if(kvp->left != nullptr && kvp->right == nullptr){
        root = kvp->left;
        root->parent = nullptr;
        delete kvp;
    }
    else if(kvp->left == nullptr && kvp->right != nullptr){
        root = kvp->right;
        root->parent = nullptr;
        delete kvp;
    }
    else{
        //find the min key in the right subtree
        kvpair* t = findmin(kvp->right);
        kvp->copykvpair(t);
        deletenode(t);
    }

  }
  void deletenode(kvpair* kvp){
    if(kvp == root){
        deleteroot(kvp);
        return;
    }
    // non-root leaf node
    if(kvp->left == nullptr && kvp->right == nullptr){
        if(kvp->parent->left == kvp) {kvp->parent->left = nullptr; delete kvp;}
        else{kvp->parent->right = nullptr; delete kvp;}
        return;
    }

    // node with one child
    

  }
};