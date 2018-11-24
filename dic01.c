#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    char key[20];
    char mean[100];
    char syno[40];
    struct node * next;
};

struct node * dict[26];

void Reset_words(char *);
void Add_words(char *);
int  Check_words(char *);
void Delete_words(char *);
void syno_words(char *);

int main()
{
    int res = 0;
    char words[20];
    printf("\t\t\n\n##################### ~ Dictionary ~ #####################\n");
    while(res!=6)
    {
        printf("\n\n--------->\n");        
        printf("\t1. Add words\n");
        printf("\t2. Delete words\n");
        printf("\t3. Check words\n");
        printf("\t4. Reset\n");
        printf("\t5. Suggest synonyms\n");
        printf("\t6. Quit\n");
        printf("--------->\n");

        printf("\tEnter your response : ");
        scanf("%d",&res);
		printf("\n");
        switch(res)
        {
            case 1:printf("\t-------ADD WORDS-------\n");
                   printf("\tEnter the words to add :"); 
                   fflush(stdin);
                   gets(words);
                   Add_words(words);
                   break;

            case 2:printf("\t-----DELETE WORDS-----\n");
                   printf("\tEnter the words to delete :"); 
                   fflush(stdin);
                   gets(words);
                   Delete_words(words);
                   break;
            case 3:printf("\t-------CHECK WORDS-------\n");
                   printf("\tEnter the words to check :"); 
                   fflush(stdin);
                   gets(words);
                   Check_words(words);
                   break;
            case 4:printf("\t-------Reset Words-------\n");
                   printf("\tEnter the words to reset :"); 
                   fflush(stdin);
                   gets(words);
                   Reset_words(words);
                   break;
            case 5:printf("\t-----Suggest synonyms-----\n");
                   printf("\tEnter the word:"); 
                   fflush(stdin);
                   gets(words);
                   syno_words(words);
                   break;
        }     
        if(res==0 || res > 6) printf("\t\n0-0-0-0-WRONG RESPONSE-0-0-0-0\n");  
                
    }
    printf("\t\t######################## ~ END ~ #########################\n");
    return 0;
}

// function for add_words
void Add_words(char * word)
{
    int x;
    char meaning[100];
    char syno[40];
    int j = toupper(word[0]) - 65; //to put the words to the 0 - 26 range in alphabatical order
    struct node *n1;
    struct node *n2 = (struct node*)malloc(sizeof(struct node));
    struct node *root = dict[j];
    strcpy(n2->key,word);
    n2->next = NULL;
    x = Check_words(word);//checking if the word is already exists...., will return 1 if exists.
    if(x==1)
    {
        printf("\t\n The word you entered is already exists..!\n");
        return;
    }
        printf("\n	Enter the meaning : ");
        fflush(stdin);
        gets(meaning);
        strcpy(n2->mean,meaning);
        printf("\n	Enter synonyms(use ',' to add multiple words) : ");
        fflush(stdin);
        gets(syno);
        strcpy(n2->syno,syno);

        if(dict[j]->key == NULL || strcmp(dict[j]->key,word) > 0)
        {
            n1 = dict[j];
            dict[j] = n2;
            n2->next = n1;
            return;
        }
        else
        {
            while(root != NULL)
            {
                if((strcmp(root->key,word) < 0) && (strcmp(root->next->key,word) > 0 || root->next == NULL))
                {
                    n2->next = root->next;
                    root->next = n2;
                    return;
                }
                root = root->next;
            }
        }
    
}

int Check_words(char * word)
{
    struct node * root;
    
    root = dict[toupper(word[0]) - 65];
    while(root!=NULL)
    {
        if(strcmp(root->key,word) == 0)
        {
            printf("\n%s\t\t%s",root->key,root->mean);
            return 1;
        }
        root = root->next;
    }
    return 0;
}

void Delete_words(char * word)
{
	int i;
	struct node * root;
	root = dict[toupper(word[0]) - 65];
	if(strcmp(root->key,word) == 0)
	{
		for(i=0;i<20;i++)root->key[i] = '\0';
	}
	while(root!=NULL)
	{
		if(strcmp(root->next->key,word)==0 && root->next->next != NULL)
		{
			root->next = root->next->next;
		}
		else if(strcmp(root->next->key,word)==0 && root->next->next == NULL)
		{
			root->next = NULL;
		}
		
		root = root->next;
	}
}

void Reset_words(char * word)
{
	int i;
	char meaning[100];
	struct node * root;
	root = dict[toupper(word[0]) - 65];

	while(root!=NULL)
	{
		if(strcmp(root->key,word)==0)
		{
			strcpy(root->key,word);
			printf("\t\nEnter the new meaning : ");
        	fflush(stdin);
        	gets(meaning);
        	strcpy(root->mean,meaning);
		}
		
		root = root->next;
	}
}

void syno_words(char * word)
{
	int i;
	struct node * root;
	root = dict[toupper(word[0]) - 65];
	while(root!=NULL)
	{
		if(strcmp(root->key,word)==0)
		{
			printf("\n\t%s\n",root->syno);
		}
		
		root = root->next;
	}
}
