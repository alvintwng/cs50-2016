/**
 * helpers.h
 * Oct 21, 2015
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);

/**
 * split to Left and Right, then use void merge()
 * reference mytest2.c
 */
int Sorting(int values[], int Lo, int Hi);

/**
 * marge the left and right of array
 * run from void Sorting( ... )
 */
void merge (int array[], int start, int LeftHi, int RightLo, int RightHi);