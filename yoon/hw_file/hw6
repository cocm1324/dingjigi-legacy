/*
HW#6: Finding 5 Revising txt file
name : Jaewon Yoon
stNum : 21300492
date : 18.06.07
contact : 21300492@handong.edu

this program revises given file according to mapFile given. It takes one-to-one match relationship of words from mapFile.
Then it examine through all words in txtFile, convert all corresponding words into its match.

I/O summary
input: command line input of 1)fileName for mapFile 2)fileName for txtFile for revision
output: revised file in fileName+".rev"

Constraints
1) Each words in txt files never exceeds 128 characters
2) Total length of input txtFile for revision never exceeds 2014 characters
3)

Steps for implementation
1) Read data from map_file and convert it into bst print result
2) Read data from input_file and store all words into 2d Array
3) setup output file
4) Examine each words. if in bst, print matching words, otherwise print as it is
most of functions reused from previous HWs

Remarks
there are room for improvement in that main function is almost 100 lines long. It could be done through
making some of features into functions, especially conversion of input txtFile into 2D array. However
this implementation involves usage of double pointers and arrayPointer which could rather complicate the
program.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128
#define MAX_WORDS 2048

//declare variables and structures
typedef struct{
    char value[MAX_STRING];
    /*other fields*/
}iType;

typedef struct treeNode *treePointer;

struct treeNode{
    iType item;
    char key[MAX_STRING];
    treePointer rightChild;
    treePointer leftChild;
};

treePointer modifiedSearch(treePointer node, char k[]);
void insert(treePointer *node, char k[], iType theItem);
void inorder(treePointer node);
treePointer searchTarget(treePointer root, char k[]);
void mapToBst(treePointer *bst, char file_name[]);



int main(void){
    //define variables
    treePointer bst=NULL;
    treePointer search_res=NULL;
    char words[MAX_WORDS][MAX_STRING];
    char file_name[MAX_STRING];
    char ch;
    int i=0, j=0;
    FILE * fp=NULL;

    //1) Read data from map_file and convert it into bst print result
    printf("type in map file name: ");
    scanf("%s", file_name);

    mapToBst(&bst, file_name);
    printf("###[Showing contents of bst]###");
    inorder(bst);
    printf("\n\n");

    //2) Read data from input_file and store all words into 2d Array
        //a. set up fp
    printf("type in input file name: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "rt");
    if(fp==NULL){
        printf("###error in opening [%s]###", file_name);
        return -1;
    }
        //b. read all characters from fp, convert into words, store in 2d Array
    while((ch=fgetc(fp))!=EOF){
        if(ch!=' ') words[i][j++]=ch;
        else{
            words[i][j]='\0';
            i++;
            j=0;
        }
    }
    words[i][j]='\0';
    int length_words = i+1;

        //Print result
    printf("###[Showing Result of words input]###\n");
    for(i=0;i<length_words;i++){
        printf("%s\n", words[i]);
    }
    printf("\n\n");
    fclose(fp);


    //3) setup output file
    fopen(strcat(file_name,".rev"), "wt");
    if(fp==NULL){
        printf("###error in opening [%s]###", file_name);
        return -1;
    }

    //4) Examine each words. if in bst, print matching words, otherwise print as it is
    for(i=0;i<length_words;i++){
        search_res=searchTarget(bst, words[i]);
        if(search_res){
            fprintf(fp, "%s ", search_res->item.value);
        }
        else fprintf(fp, "%s ", words[i]);
    }
    fclose(fp);

    printf("Revision Complete\n\n");

    return 0;
}

//1) implement modifiedSearch
treePointer modifiedSearch(treePointer node, char k[]){
//input: BST's root node and a key
//output: proper position for input key to be. it returns the position of node whose leftchild or rightchild
// is the position for the input key.
    if(node){
        if(!strcmp(node->key, k)) return NULL;
        if(strcmp(node->key, k)<0){
            if(!node->rightChild) return node;
            else return modifiedSearch(node->rightChild, k);
        }
        if(!node->leftChild) return node;
        else return modifiedSearch(node->leftChild, k);
    }
    else return NULL;
}

//2. implement insert function
//input: BST's root node, key, and value
//output : inserting of inputted key and value in proper position of BST
//this function works in joint with modifiedSearch.
void insert(treePointer *node, char k[], iType theItem){
    treePointer ptr, temp = modifiedSearch(*node, k);
    if(temp || !(*node)){ //k is not in BST
        ptr = (treePointer)malloc(sizeof(*ptr));
        strcpy(ptr->key, k);
        ptr->item = theItem;
        ptr->leftChild=ptr->rightChild=NULL;
        if(*node){ //tree is not empty: normal insertion
            if(strcmp(ptr->key, temp->key)>0) (temp)->rightChild = ptr;
            else temp->leftChild = ptr;
        }
        else (*node) = ptr; //BST is empty: node points to newly created node.
    }
}

//3. implement print function
//input: root node of BST
//output: print of BST inorder
void inorder(treePointer node){
    if(node){
        inorder(node->leftChild);
        printf("%s ", node->key);
        printf("%s\n", node->item.value);
        inorder(node->rightChild);
    }
}

//4. implement delete function
treePointer searchTarget(treePointer root, char k[]){
/*
*input: root node of BST, key to search
*output: returns Pointer to the node which contain input key. additional function is as follows:
if the node in search is a leaf node, then separate the node from its parent before returning pointer.
ie. set parent node's child field to NULL.
*/
    if(!(root)){
        printf("no match\n");
        return NULL;
    }
    else{
        if(!strcmp(k,root->key)){
            printf("match\n");
            return root;
        }
        if(strcmp(k,root->key)>0) return searchTarget(root->rightChild, k);
        else return searchTarget(root->leftChild, k);
    }
}

void mapToBst(treePointer *bst, char file_name[]){
    /*input map file into bst*/
    char value_tmp[MAX_STRING];
    char key_tmp[MAX_STRING];
    iType dat;
    FILE * fp = fopen(file_name, "rt");
    if(fp==NULL){
        printf("###error in opening [%s]###", file_name);
        return;
    }
    char ch;
    int i=0;

    //read data from file, store them in 2d array, each row forming a word
    while(1){
        if(ch==EOF) break;
        while(((ch=fgetc(fp))!=EOF)&&(ch!=':')) key_tmp[i++]=ch;
        key_tmp[i]='\0';
        i=0;

        fgetc(fp); //discard " "

        while(((ch=fgetc(fp))!=EOF)&&(ch!='\n')) value_tmp[i++]=ch;
        value_tmp[i]='\0';
        i=0;

        strcpy(dat.value, value_tmp);
        insert(bst, key_tmp, dat);
    }
    fclose(fp);
}
