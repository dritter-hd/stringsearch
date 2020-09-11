#include "stdafx.h"
#include "ClCStringSearch.h"
        
ClCStringSearch::ClCStringSearch(){
	hits=0;
}

// Preprocess-Methods
int ClCStringSearch::preC(char *x, int m) {
   int i, k, nd, q, r, s;
   int hmax[XSIZE], kmin[XSIZE], nhd0[XSIZE], rmin[XSIZE];

   /* Computation of hmax */
   i = k = 1;
   do {
      while (x[i] == x[i - k])
         i++;
      hmax[k] = i;
      q = k + 1;
      while (hmax[q - k] + k < i) {
         hmax[q] = hmax[q - k] + k;
         q++;
      }
      k = q;
      if (k == i + 1)
         i = k;
   } while (k <= m);

   /* Computation of kmin */
   memset(kmin, 0, m*sizeof(int));
   for (i = m; i >= 1; --i)
      if (hmax[i] < m)
         kmin[hmax[i]] = i;

   /* Computation of rmin */
   for (i = m - 1; i >= 0; --i) {
      if (hmax[i + 1] == m)
         r = i + 1;
      if (kmin[i] == 0)
         rmin[i] = r;
      else
         rmin[i] = 0;
   }

   /* Computation of h */
   s = -1;
   r = m;
   for (i = 0; i < m; ++i)
      if (kmin[i] == 0)
         h[--r] = i;
      else
         h[++s] = i;
   nd = s;
 
   /* Computation of shift */
   for (i = 0; i <= nd; ++i)
      shift[i] = kmin[h[i]];
   for (i = nd + 1; i < m; ++i)
      shift[i] = rmin[h[i]];
   shift[m] = rmin[0];

   /* Computation of nhd0 */
   s = 0;
   for (i = 0; i < m; ++i) {
      nhd0[i] = s;
      if (kmin[i] > 0)
         ++s;
   }

   /* Computation of next */
   for (i = 0; i <= nd; ++i)
      next[i] = nhd0[h[i] - kmin[h[i]]];
   for (i = nd + 1; i < m; ++i)
      next[i] = nhd0[m - rmin[h[i]]];
   next[m] = nhd0[m - rmin[h[m - 1]]];

   return(nd);
}

// Searching
int* ClCStringSearch::find(char* text){
    int i, j, last, nd;

	textSize = strlen(text);

	i = j = 0;
	last = -1;
	while (j <= textSize - patternSize) {
		while (i < patternSize && last < j + h[i] &&	pattern[h[i]] == text[j + h[i]])
			i++;
		if (i >= patternSize || last >= j + h[i]) {
			//cout << "offset=" << j << endl;
			hits++;
			i = patternSize;
		}
		if (i > nd)
			last = j + patternSize - 1;
		j += shift[i];
		i = next[i];
	}
	return NULL; // TODO:
}

int ClCStringSearch::contains(char* text){
   int i, j, last, nd;

	textSize = strlen(text);

	i = j = 0;
	last = -1;
	while (j <= textSize - patternSize) {
		while (i < patternSize && last < j + h[i] &&	pattern[h[i]] == text[j + h[i]])
			i++;
		if (i >= patternSize || last >= j + h[i]) {
				//cout << "offset=" << j << endl;
				return 0;
		}
		if (i > nd)
			last = j + patternSize - 1;
		j += shift[i];
		i = next[i];
	}
	return -1;
}

void ClCStringSearch::preprocess(char* pat){
	pattern = pat;
    patternSize = strlen(pattern);

	ClCStringSearch::preC(pat, patternSize);
}    
