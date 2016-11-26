#include "pointeurs.h"


void swap(int *pa, int *pb)
{
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void minmax(int *p, int n, int *pmin, int *pmax)
{
    int *i;
    *pmin=*p;
    *pmax=*p;

    for (i=p ; i<p+n ; i++)
    {
        if (*i < *pmin) *pmin = *i;
        if (*i > *pmax) *pmax = *i;
    }
}
