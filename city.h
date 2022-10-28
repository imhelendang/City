/*
 *
 * PROGRAMMED BY : Jade Tran
 * CLASS : CS1D
 * SECTION : TTh 11:3 - 1:50
 * FILE: city.h
 *     Definition of data structures and
 *     declaration of functions that operate on them.
 * ASSIGNMENT : Finding closest cities
 */

#ifndef CITY_H
#define CITY_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Number of cities. */
#define NUMBER_CITIES 20

/* Length of a string. */
#define LENGTH 23

/* Global variables. */
extern int k;           /* Used to create a array of size k to sort distance in ascending order. */
extern char unit;       /* Used to set up the unit (either miles-M or kilomaters-K). */
extern int num;         /* Used to control the loop when displaying out k cities. */

/** 
 * Define data structure
 */
typedef struct _node
{
    char *name;
    float dis;
    struct _node *left, *right;
} node;

/** 
 * Function to create a BST.
 * *********************************************************************************
 * create_bst() function:
 * @param *root, *name, dis.
 * @return binary tree.
 */
void create_bst(node **root, char *name, float dis);

/** 
 * Function to traverse through the binary tree.
 * *********************************************************************************
 * traverse_list() function:
 * @param *root.
 */
void traverse_list(node *root);

int height(node *root);

/** 
 * Function to print out k cities in ascending order.
 * *********************************************************************************
 * print_list() function:
 * @param *root.
 */
void print_list(node *root);

/**
 * Deallocates all memory associated with the indicated binary search tree.
 * **************************************************************************************
 * @param root The root of the tree to free.
 */
void free_tree(node *root);


#endif


