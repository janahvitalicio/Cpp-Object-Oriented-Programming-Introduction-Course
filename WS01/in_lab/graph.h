#pragma once
/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          January 14, 2019 (Week 2, Workshop 1)
 **********************************************************/


// Header file for graph.cpp
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
// Finds the largest sample in the samples array, if it is larger than 70,
// Otherwise it will return 70. 
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);