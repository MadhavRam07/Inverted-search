#include "inverted_search.h"

void save_database( Flist *f_head, Wlist *head[])
{
    //prompt the user 
    char file_name[FNAME_SIZE];

    printf("Enter the filename: ");
    scanf("%s" , file_name);
    __fpurge(stdin);

    FILE *fptr = fopen(file_name , "a");
    fprintf(fptr, "-----------------------------------------------\n");
    for(int i = 0 ; i < 27 ; i++)
    {
	Wlist *temp = head[i];
	while(temp != NULL)
	{
	    write_databasefile(temp , fptr);
	    temp = temp-> link;
	}
    }
    fprintf(fptr, "---------------------------------------------------\n");
    fclose(fptr);
    printf("Database is saved\n");
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
	  
    int index = tolower(head-> word[0]) % 97; 
    if(!(index >= 0 && index <= 25))
			  index = 26;
    // # : index    [word]    :    [file_count]    :  [file_name]    :    [word_count]
    fprintf(databasefile, "#[%d]\tword is\t[%s]:\tFile Count is %d file/s:    ", index, head-> word, head-> file_count);
    Ltable *temp = head-> tlink;
    while(temp)
    {
	fprintf(databasefile, "\t%s is %s:\tWord Count is %d\t", "File", temp-> file_name, temp-> word_count);
	temp = temp-> table_link;
    }
    fprintf(databasefile, "\n\n");
}
