#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 27 // 26 letters + apostrophes
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;
// Represents a trie
node *root;

bool pt(void)
{

    root = malloc(sizeof(node));    if (root == NULL)   {return false;   }

    root->is_word = false;  for (int i = 0; i < N; i++) {root->children[i] = NULL;   }
    //node *temp = malloc(sizeof(node)); *temp = *root;
    node *ptr = root;

        printf("sizeofnode : %lu\n", sizeof(node));
/*

    printf ("total size in dcitionary node of 143091 words : %lu\n", 143091 * sizeof(node));


    char *s = "abc";

    if (ptr->children[0])
    {
        printf("Thing \n");
    }

    //if (ptr->children[39]) {printf("apos \n");}  // error

    if (!ptr->children[0])
    {
        printf("NULL \n");
    }

    //if (!ptr->children[39]) {printf("not apos \n");} // error
*/
    free(root);

    return true;
}

void wt(void)
{
    char *s = "abc";

    int i = 0;
    while (s[i])
    {

        printf("%s\n",s);
    }
}

int main(void)
{
    bool pointer = pt();
    //wt();
}

/*

==2550== HEAP SUMMARY:
==2550==     in use at exit: 32 bytes in 1 blocks
==2550==   total heap usage: 2 allocs, 1 frees, 256 bytes allocated



*/