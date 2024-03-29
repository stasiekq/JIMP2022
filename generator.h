#ifndef _GENERATOR_H
#define _GENERATOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pair
{
	int node;
	double path;
} pair;

typedef struct pair_list
{
	pair pairs;
	struct pair_list *next;
} pair_list;

typedef struct graph
{
	pair_list list;
	int columns;
	int rows;
} graph;

double randomdouble(double min, double max);

void creategraph(FILE *filename, int columns, int rows, double fromrange, double torange, int cohesive);

#endif
