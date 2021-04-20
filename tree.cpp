//Bismillah - AbubakarQ
//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "tree.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(int Value, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree->Value == Value)
      return true;

   // Recursively search for data value
   else if (Tree->Value > Value)
      return (SearchHelper(Value, Tree->Left));
   else if (Tree->Value < Value)
      return (SearchHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(int Value)
{
   // Call tree searching function
   return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(int Value, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Value = Value;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Data value already inserted
   else if (Tree->Value == Value)
      return false;     

   // Recursively search for insertion position
   else if (Tree->Value > Value)
      return (InsertHelper(Value, Tree->Left));
   else if (Tree->Value < Value)
      return (InsertHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(int Value)
{
   // Call tree insertion function
   return (InsertHelper(Value, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      cout << "(";
      PrintHelper(Tree->Left);

      // Print node value
      cout << " " << Tree->Value << " ";

      // Print right subtree
      PrintHelper(Tree->Right);
      cout << ")";
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}

//-----------------------------------------------------------
// Counts all nodes in Binary Tree
//-----------------------------------------------------------
int BinaryTree::Count()
{
    return CountHelper(Root);
   
}

//-----------------------------------------------------------
// Helps with count public method
//-----------------------------------------------------------
int BinaryTree::CountHelper(Node * Tree)
{
    if (Tree == NULL) {
        return 0;
    }

    return 1 + CountHelper(Tree->Left) + CountHelper(Tree->Right);
}

//-----------------------------------------------------------
// Calculates height of tree
//-----------------------------------------------------------
int BinaryTree::Height()
{
    return HeightHelper(Root);
}

//-----------------------------------------------------------
// Helps with height public method
//-----------------------------------------------------------
int BinaryTree::HeightHelper(Node * Tree)
{
    if (Tree == NULL) {
        return 0;
    }

    return 1 + max(HeightHelper(Tree->Left), HeightHelper(Tree->Right));
        // max(a,b) returns the largest of the two. If both equivalent, a is returned
}






//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
    // tree 1
    BinaryTree tree;
    srand(time(0));
    cout << "Tree 1: \n";
    for (int i = 0; i < 10; i++) {
        if (tree.Insert(rand() % 10) == true)
            cout << "SUCCESS | Insertion into Tree\n";
        else 
            cout << "FAILED  | Location full\n";
    }

    tree.Print();
    cout << "Count Nodes: " << tree.Count() << endl;
    cout << "Height of Tree: " << tree.Height();
    cout << endl << endl;

    // tree 2
    BinaryTree tree2;
    
    int j = 0;
    for (int i = 0; i < 10; i++) {
        j++;
        tree2.Insert(j);
    }
    
    cout << "Tree 2: \n";
    tree2.Print();
    cout << "Count Nodes: " << tree2.Count() << endl;
    cout << "Height of Tree: " << tree2.Height();
    cout << endl << endl;

    // tree 3
    BinaryTree tree3;
    int k = 10;
    for (int i = 0; i < 10; i++) {
        k--;
        tree3.Insert(k);
    }

    cout << "Tree 3: \n";
    tree3.Print();
    cout << "Count Nodes: " << tree3.Count() << endl;
    cout << "Height of Tree: " << tree3.Height();
    cout << endl << endl;

    return 0;
}