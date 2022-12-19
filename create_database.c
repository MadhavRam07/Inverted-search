#include "inverted_search.h"

char *fname;
int create_database(Flist *f_head, Wlist *head[])
{
    while(f_head != NULL)
    {
	/* Checking files repeated or not */
	int flag = 1;
	for(int i = 0 ; i < 27 ; i++)
	{
	    Wlist *temp1 = head[i];
	    while(temp1 != NULL)
	    {
		Ltable *temp2 = head[i]-> tlink;
		while(temp2)
		{
		    if(!strcmp(temp2-> file_name, f_head-> file_name))		    
		    {
			flag = 0;
			break;
		    }
		    temp2 = temp2-> table_link;
		}
		if(!flag)
		    break;
		temp1 = temp1-> link;
	    }
	    if(!flag)
		break;
	}
	if(flag)
	{
	    read_datafile(head, f_head-> file_name);
	}
	f_head = f_head-> link;
    }
    return SUCCESS;
}

//Read contents of file
Wlist *read_datafile(Wlist *head[], char *filename)
{
    //open file
    FILE *fptr = fopen(filename, "r");
    fname = filename;
    //Declare an array to store the words
    char word[WORD_SIZE];
    while(fscanf(fptr, "%s", word) != EOF)
    {
	int flag = 1;
	//index
	int index = tolower(word[0]) % 97;
	//other than alphabets
	if(!(index >= 0 && index <= 25))
	    index = 26;
	//printf("index for word[%c] = %d\n", word[0], index);
	if(head[index] != NULL)
	{
	    Wlist *temp = head[index];
	    //compare words at each node with new word
	    while(temp != NULL)
	    {
		if(!strcmp(temp-> word, word))
		{
		    update_word_count(&temp, filename);
		    flag = 0;
		    break;
		}
		temp = temp-> link;
	    }
	}
	if(flag)
	{
	    //words are not repeated
	    insert_at_last(&head[index], word);
	}
    }
}

int update_word_count(Wlist **head, char *filename)
{
    //check whether filenames same or not
    //if file names same, inc word count
    //if file names different, inc file count & create ltable
    Ltable *temp = (*head)-> tlink;

    while(temp-> table_link != NULL)
    {
	if(!strcmp(temp-> file_name, filename))
	{
	    temp-> word_count = (temp-> word_count) + 1;
	    return SUCCESS;
	}
	temp = temp-> table_link;
    }
    if(strcmp(temp-> file_name, filename))
    {
	((*head)-> file_count)++;
    } 
    else
    {
	(temp-> word_count)++;
	return SUCCESS;
    }

    //Creating link table
    Ltable *new = malloc(sizeof(Ltable));
    if(!new)
	return FAILURE;
    new-> word_count = 1;
    strcpy(new-> file_name, filename);
    new-> table_link = NULL;
    temp-> table_link = new;
    return SUCCESS;
}
