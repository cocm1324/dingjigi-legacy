#include <stdio.h>
#include <string.h>
//for using isalpha
#include <ctype.h>
//as shown in hw4.pdf, I set MAXWORDS 2048
#define MAXWORDS 2048
#define MAXSTRING 1000

/* structure holding word frequency information */

typedef struct _word {
char s[MAXSTRING]; //the word
int count; //number of times word occurs
} word;

/* This function inserts a word into the list of word */
void insert_word (word *words, int *n, char *s) {
int i;

//linear search for the word
for (i=0; i<*n; i++) if (strcmp (s, words[i].s) == 0) {

/* if found word, increment +1 */

words[i].count++;
return;
}

strcpy (words[*n].s, s);

/* this word has occured once up to now, so count = 1 */

words[*n].count = 1;

(*n)++;
}

/* comparison function for quicksort. */
int wordcmp (word *a, word *b) {
if (a->count < b->count) return +1;
if (a->count > b->count) return -1;
return 0;
}

/* return 1 if c is alphabetic (a..z or A..Z), 0 otherwise */
int is_alpha (char c) {
if (c >= ‘a’ && c <= ‘z’ || c >= ‘A’ && c <= ‘Z’) return 1;
return 0;
}

/* remove the i’th character from the string s */
void remove_char (char *s, int i) {
while (s[i]) {
i++;
s[i-1] = s[i];
}
s[i] = 0;
}

/* remove non-alphabetic characters from the string s */
void remove_non_alpha (char *s) {
int i;

for (i=0; s[i]; i++) if (!is_alpha (s[i])) remove_char (s, i);
}

/* make all the letters in s lowercase */
void make_lowercase (char *s) {
int i;

for (i=0; s[i]; i++) s[i] = tolower (s[i]);
}
/* quick sort algorithm */

void swap(int *a, int *b){
int tmp = *a;
*a = *b;
*b =tmp;
}

void quick_sort(int * array, int start, int end){
if(start>=end) return;

int mid=(start+end)/2;
int pivot=array[mid];

swap(&array[start],&array[mid]);

int p = start +1, q = end;

while(1){
while(array[p]<=pivot){p++;}
while(array[q]>pivot){q–;}

if(p>q) break;

swap(&array[p],&array[q]);

}
swap(&array[start],&array[q]);

quick_sort(array,start,q-1);
quick_sort(array,q+1,end);
}

//main
int main () {
word words[MAXWORDS];
char s[1000];
int i, n, m;
/* File pointer */
FILE * fp;
/* Read text from here */
fp = fopen(“./test.txt”,”r”);

n = 0;

/* read all the words in the file*/

while (!feof (fp)) {
fscanf (fp,”%s”, s);

if (is_alpha (s[0])) {

//remove non-letters

remove_non_alpha (s);

//make all letters lowercase

make_lowercase (s);

// make a list with word

insert_word (words, &n, s);
}
}

/* sort the list of words by descending frequency */

qsort((void *) words, n, sizeof (word),
(int (*) (const void *, const void *)) wordcmp);

if (n < 5)
m = n;
else
m = 5;

/* print frequency high order 5 words*/
printf(“print 5 words have the most high frequency\n”);
printf(“——————————————–\n”);
for (i=0; i<m; i++)
printf (“%s\t%d\n”, words[i].s, words[i].count);
}

