#include"inverted_search.h"

void display_database( Wlist *head[] )
{
    int i;
    printf("%-8s %-8s %-16s \e[39m", "[Index]", "[Word]", "[File_Count]");
    printf("%-16s %-16s\e[39m\n", "[File_Name]", "[Word_Count]");

    for( i = 0 ; i < 27 ; i++)
    {
     	if(head[i] != NULL)
	{
	    print_word_count(head[i]);
	}
    }
}

int print_word_count(Wlist *head)
{
    //traverse through the Wlist till last node 
    int index = tolower(head-> word[0]) % 97;
    if(!(index >= 0 && index <= 25))
	index = 26;
    while(head != NULL)
    {
	printf("%-9d %-9s %d %-13s" , index , head->word , head->file_count, "file/s");

	Ltable *Thead = head-> tlink ;

	//traverse 

	for(int i = 0 ; Thead ; i++)
	{
	    if(i == 0)
		printf("%s%-13s %-13d\n", "File: ", Thead->file_name , Thead->word_count);
	    else
		printf("%41s%-13s %-13d\n", "File: ", Thead->file_name , Thead->word_count);
	    Thead = Thead->table_link;
	}
	printf("\n");
	head = head->link;
    }
}
