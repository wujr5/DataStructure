#include<iostream>
#include<stdlib.h>
using namespace std;

enum Error_code {
	success, not_present, duplicate_error
}; 

template <class Entry>
struct Binary_node {
//    data members:
	Entry data;
	Binary_node<Entry> *left;
	Binary_node<Entry> *right;
//    constructors:
	Binary_node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
	Binary_node(const Entry &x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

template <class Entry>
class Binary_tree {
	public:
	   Binary_tree();
	   bool empty() const;
	   
	   void preorder(void (*visit)(Entry &));
	   void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
	   
	   void inorder(void (*visit)(Entry &));
	   void recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
	   
	   void postorder(void (*visit)(Entry &));
	   void recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
	
	   int size() const;
	   void clear();
	   int height() const;
	   void insert(const Entry &);
	
//	   Binary_tree (const Binary_tree<Entry> &original);
//	   Binary_tree & operator =(const Binary_tree<Entry> &original);
//	   ~Binary_tree();
	
	protected:
	   //  Add auxiliary function prototypes here.
	   Binary_node<Entry> *root;
};

template <class Entry>
Binary_tree<Entry>::Binary_tree() {
   root = NULL;
}

template <class Entry>
bool Binary_tree<Entry>::empty() const {
   return root == NULL;
}


template <class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry &)) {
   recursive_inorder(root, visit);
}


template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)) {
   if (sub_root != NULL) {
      recursive_inorder(sub_root->left, visit);
      (*visit)(sub_root->data);
      recursive_inorder(sub_root->right, visit);
   }
}

template <class Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Entry &)) {
	recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)) {
   if (sub_root != NULL) {
      (*visit)(sub_root->data);
      recursive_preorder(sub_root->left, visit);
      recursive_preorder(sub_root->right, visit);
   }
}

template <class Entry>
void Binary_tree<Entry>::postorder(void (*visit)(Entry &)) {
	recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)) {
   if (sub_root != NULL) {
      recursive_postorder(sub_root->left, visit);
      recursive_postorder(sub_root->right, visit);
      (*visit)(sub_root->data);
   }
}

//二叉搜索树 
template <class Record>
class Search_tree: public Binary_tree<Record> {
	public:
	   Error_code insert(const Record &new_data);
	   Error_code remove(const Record &old_data);
	   Error_code tree_search(Record &target) const;
	   
	   Binary_node<Record> *search_for_node( Binary_node<Record>* sub_root, const Record &target) const;
	   Error_code search_and_insert(Binary_node<Record> *&sub_root, const Record &new_data);
	   Error_code remove_root(Binary_node<Record> *&sub_root);
	   Error_code search_and_destroy(Binary_node<Record>* &sub_root, const Record &target);
	private: //  Add auxiliary function prototypes here.
};


template <class Record>
Binary_node<Record> *Search_tree<Record>::search_for_node(
            Binary_node<Record>* sub_root, const Record &target) const
{
   if (sub_root == NULL || sub_root->data == target) return sub_root;
   else if (sub_root->data < target)
      return search_for_node(sub_root->right, target);
   else return search_for_node(sub_root->left, target);
}

//非递归版本实现 

//template <class Record>
//Binary_node<Record> *Search_tree<Record>::search_for_node(
//            Binary_node<Record> *sub_root, const Record &target) const
//{
//   while (sub_root != NULL && sub_root->data != target)
//      if (sub_root->data < target) sub_root = sub_root->right;
//      else sub_root = sub_root->left;
//   return sub_root;
//}


template <class Record>
Error_code Search_tree<Record>::tree_search(Record &target) const {
   Error_code result = success;
   Binary_node<Record> *found = search_for_node(this->root, target);
   if (found == NULL)
      result = not_present;
   else
      target = found->data;
   return result;
}


template <class Record>
Error_code Search_tree<Record>::insert(const Record &new_data) {
   return search_and_insert(this->root, new_data);
}


template <class Record>
Error_code Search_tree<Record>::search_and_insert(Binary_node<Record> *&sub_root, const Record &new_data) {
   if (sub_root == NULL) {
      sub_root = new Binary_node<Record>(new_data);
      return success;
   }
   else if (new_data < sub_root->data)
      return search_and_insert(sub_root->left, new_data);
   else if (new_data > sub_root->data)
      return search_and_insert(sub_root->right, new_data);
   else return duplicate_error;
}


template <class Record>
Error_code Search_tree<Record>::remove_root(Binary_node<Record> *&sub_root) {
   if (sub_root == NULL) return not_present;
   Binary_node<Record> *to_delete = sub_root;  //  Remember node to delete at end.
   if (sub_root->right == NULL) sub_root = sub_root->left;
   else if (sub_root->left == NULL) sub_root = sub_root->right;
   else {                           //  Neither subtree is empty.
      to_delete = sub_root->left;   //  Move left to find predecessor.
      Binary_node<Record> *parent = sub_root; //  parent of to_delete
      while (to_delete->right != NULL) { //  to_delete is not the predecessor.
         parent = to_delete;
         to_delete = to_delete->right;
      }
      sub_root->data = to_delete->data;  //  Move from to_delete to root.
      if (parent == sub_root) sub_root->left = to_delete->left;
      else parent->right = to_delete->left;
   }
   delete to_delete;   //  Remove to_delete from tree.
   return success;
}


template <class Record>
Error_code Search_tree<Record>::remove(const Record &target) {
   return search_and_destroy(this->root, target);
}


template <class Record>
Error_code Search_tree<Record>::search_and_destroy(Binary_node<Record>* &sub_root, const Record &target) {
   if (sub_root == NULL || sub_root->data == target)
      return remove_root(sub_root);
   else if (target < sub_root->data)
      return search_and_destroy(sub_root->left, target);
   else
      return search_and_destroy(sub_root->right, target);
}

int main() {
	Search_tree<int> T;
	T.insert(0);
	T.insert(1);
	T.insert(2);
	
	system("pause");
}
