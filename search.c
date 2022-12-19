#include "inverted_search.h"

int search( Wlist **head, char *word)
{
    //check empty or not

    int i, j = 0;
    for(i = 0 ; i < 27 ; i++)
    {
	//traverse the list
	Wlist *temp = head[i];
	if(temp == NULL)
	    j++;
	while(temp)
	{
	    //compare the search_word with available words in Wlist
	    if(!strcmp(temp->word , word))
	    {
		printf("Word [%s] is present in [%d] file/s\n" , word , temp->file_count);
		Ltable *Thead = temp->tlink;
		while(Thead)
		{	
		    printf("In file : %s   [%d] time/s\n" , Thead->file_name , Thead->word_count);

		    Thead = Thead ->table_link;
		}
		return 0;
	    }
	    temp = temp->link;
	}
    }
    if(j == 27)
	printf("Search word is not available in the list as list is empty\n");
    else
	printf("Search is not present in the list\n");
    return FAILURE;
}
