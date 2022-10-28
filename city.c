#include "city.h"
/*
 *
 * PROGRAMMED BY : Jade Tran
 * CLASS : CS1D
 * SECTION : TTh 11:3 - 1:50
 * FILE: city.c
 *     Definition of data structures and
 *     declaration of functions that operate on them.
 * ASSIGNMENT : Finding closest cities
 */

/**
 * Create a BST
 */
void create_bst(node **root, char *name, float dis)
{
    /**
     * Arrays of nodes used to store city names and city longitudes and latitudes.
     */
    node *temp = (node*)malloc(sizeof(node));
    temp->name = name;
    temp->dis = dis;
    temp->left = NULL;
    temp->right = NULL;

    node *inter = *root;

    /**
     * If the 'root' is empty (at first, it means the list is currently empty)
     * initialize root to a new node
     */
    if(*root == NULL)
        {
            *root = temp;
            return;
        }

    /**
     * If a new node has 'dis' equal to the root's 'dis'
     * print out some message and return
     */ 
    if(dis == inter->dis)
        {
            printf("Can't have duplicates!\n");
            return;
        }
    /**
     * If a new node has 'dis' smaller than the root's 'dis'
     * Then add to the left
     */    
    else if(dis < inter->dis)
        create_bst(&(inter->left), name, dis);
    /**
     * If a new node has 'dis' greater than the root's 'dis'
     * Then add to the right
     */  
    else
        create_bst(&(inter->right), name, dis);

    free(temp);
}

void traverse_list(node *root)
{
    if(root!=NULL && num < k) 
        {
            traverse_list(root->left);
            if(num < k)
                print_list(root);
            else
                return;
            traverse_list(root->right);
        }
    return;
}

void print_list(node *root)
{
    printf("== City#%d: %-17s distance: %.2f miles                     ==\n", num+1, root->name, root->dis); 
    num++;
    return;
}

int height(node *root)
{
    if(root==NULL)
      return 0;
      
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Now check for every node
    if(leftHeight - rightHeight >1)
    printf("The tree is unbalanced!\n");
    
    return leftHeight + rightHeight + 1;  
}


void free_tree(node *root) 
{
  /* TODO: Implement this function! */

  /**
   * Check if root is created or not. 
   * If not -> can't delete since there is no element to delete
   */
  if(root == NULL)
      return;
  else 
    {
      free(root->name);
      free_tree(root->left);
      free_tree(root->right);
      free(root);
    }
}

