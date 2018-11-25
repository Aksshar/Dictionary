#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct linked_list
{
    char key[20];
    char mean[100];
    char syno[40];
    struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL, *last=NULL;

void create_linked_list();
void insert_at_last(char *value,char *mean,char *syno);
void delete_item(char *value);
void search_item(char *value);
void reset(char *value);
void syno(char *value);

int main()
{
    int key;
    char value[20];

    int res = 0;

    while(res!=6)
    {
    printf("\n\n#################\n");        
    printf("\t1. Add words\n");
    printf("\t2. Check words\n");
    printf("\t3. Delete words\n");
    printf("\t4. Reset\n");
    printf("\t5. Suggest synonyms\n");
    printf("\t6. Quit\n");
    printf("###################\n");
    
    printf("response :");
    scanf("%d",&res);

    switch(res)
    {
        case 1: printf("Enter words to the dictionary\n");
                create_linked_list();
                break;
        case 2: //Search an item from Linked List
                printf("\nEnter words to search it from Dictionary\n");
                fflush(stdin);
                gets(value);
                search_item(value);
                break;
        case 3: //Delete value from List
                printf("\nEnter word, which you want to delete from Dictionary\n");
                fflush(stdin);
                gets(value);
                delete_item(value);
                break;
        case 4: //Reset value from List
                printf("\nEnter a value, which you want to Reset from Dictionary\n");
                fflush(stdin);
                gets(value);
                reset(value);
                break;
        case 5: //Reset value from List
                printf("\nSearch synonms for : \n");
                fflush(stdin);
                gets(value);
                syno(value);
                break;
        
    }

    }
    return 0;
}


/*
    User Defined Functions
*/
void create_linked_list()
{
    char val[20];
    char mean[100];
    char syno[40];
    printf("Input a word :");
    fflush(stdin);
    gets(val);
    printf("Input meaning :");
    fflush(stdin);
    gets(mean);
    printf("Input synonyms words :");
    fflush(stdin);
    gets(syno);
    insert_at_last(val,mean,syno);

}


void insert_at_last(char *value,char *mean,char *syno)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    strcpy(temp_node->key,value);
    strcpy(temp_node->mean,mean);
    strcpy(temp_node->syno,syno);
    temp_node->next=NULL;

    //For the 1st element
    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }

}




void delete_item(char *value)
{
    node *myNode = head, *previous=NULL;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(strcmp(myNode->key,value)==0)
        {
            if(previous==NULL)
                head = myNode->next;
            else
                previous->next = myNode->next;

            printf("%s is deleted from Dictionary\n", value);

            flag = 1;
            free(myNode); //need to free up the memory to prevent memory leak
            break;
        }

        previous = myNode;
        myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");
}


void search_item(char *value)
{
    node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(strcmp(searchNode->key,value)==0)
        {
            printf("%s -: %s\n", value,searchNode->mean);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}

void reset(char *value)
{
    node *searchNode = head;
    char mean[100];
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(strcmp(searchNode->key,value)==0)
        {
            printf("Input meaning :\n");
            fflush(stdin);
            gets(mean);
            strcpy(searchNode->mean,mean);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("word not found\n");

}

void syno(char *value)
{
    node *searchNode = head;
    char mean[100];
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(strcmp(searchNode->key,value)==0)
        {
            printf("Synonyms words :\n");
            printf("%s\n",searchNode->syno);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("word not found\n");

}
