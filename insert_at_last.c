extern char *fname;

#include "inverted_search.h"
int insert_at_last(Wlist **head, data_t *data)
{
    //Create node
    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
	return FAILURE;
    }

    //Update data fields
    new-> file_count = 1;
    strcpy(new-> word, data);
    new-> tlink = NULL;
    new-> link = NULL;

    //Call function to update link table
    update_link_table(&new);

    //check wlist empty or not
    if(*head == NULL)
    {
	*head = new;
	return SUCCESS;
    }

    //non empty
    Wlist *temp = *head;

    //Traverse through list
    while(temp-> link)
    {
	temp = temp-> link;
    }
    temp-> link = new;

    return SUCCESS;
}

int update_link_table(Wlist **head)
{
    //Create node
    Ltable *new = malloc(sizeof(Ltable));

    if(new == NULL)
	return FAILURE;

    new-> word_count = 1;
    strcpy(new-> file_name, fname);
    new-> table_link = NULL;

    (*head)-> tlink = new;
    return SUCCESS;
}
