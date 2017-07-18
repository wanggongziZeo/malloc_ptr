/*names.c--使用指针和malloc()函数*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 80

typedef struct namect{
    char *fname;
    char *lname;
    int letter;
}names;

void get_info(names *);
void make_info(names *);
void show_info(const names *);
void free_info(names *);

int main()
{
    names person;

    get_info(&person);
    make_info(&person);
    show_info(&person);
    free_info(&person);

    return 0;
}

void get_info(names *person)
{
    char tmp[LEN];

    puts("Please enter your first name:");
    gets(tmp);
    person->fname = (char *)malloc(strlen(tmp) + 1);
    strcpy(person->fname,tmp);

    puts("Please enter your last name:");
    gets(tmp);
    person->lname = (char *)malloc(strlen(tmp) + 1);
    strcpy(person->lname,tmp);
}


void make_info(names *pst)
{
    pst->letter = strlen(pst->fname) + strlen(pst->lname);
}


void show_info(const names *pst)
{
    printf("The name of %s%s has %d characters!\n",pst->fname,pst->lname,pst->letter);
}


void free_info(names *pst)
{
    free(pst->fname);
    free(pst->lname);
}