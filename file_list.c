#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1, empty;
    while(argv[i] != NULL)
    {
	empty = isFileEmpty(argv[i]);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File : %s is not available\n", argv[i]);
	    printf("Hence we are not adding into file linked list\n");
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("File : %s is empty\n", argv[i]);
	    printf("Hence we are not adding into file linked list\n");
	}
	else
	{
	    int ret_value = to_create_list_of_files(f_head, argv[i]);
	    if(ret_value == SUCCESS)
	    {
		printf("Successfull : inserting the filename : %s into file linked list\n", argv[i]);
	    }
	    else if(ret_value == REPEATATION)
	    {
		printf("This file name : %s is repeatated, so it's not added in file linked list\n", argv[i]);
	    }
	    else
	    {
		printf("FAILURE\n");
	    }
	}
	i++;
    }
}

//Function is used to check whether file is exist or not
//It is going to check file empty or not

int isFileEmpty(char *filename)
{
	   FILE *fptr = fopen(filename, "r");
	   if(fptr == NULL)
	   {
			  if(errno == ENOENT)
			  {
					 return FILE_NOTAVAILABLE;
			  }
	   }
	   fseek(fptr, 0, SEEK_END);
	   if(ftell(fptr) == 0)
			  return FILE_EMPTY;
	   return SUCCESS;
}

int to_create_list_of_files(Flist **f_head, char *name)
{
	   //Creating the file linked list
	   //checking filenames duplicate or not

	   Flist *new = malloc(sizeof(Flist));

	   if(!new)
			  return FAILURE;

	   strcpy(new-> file_name, name);
	   new-> link = NULL;

	   if(*f_head == NULL)
	   {
			  *f_head = new;
			  return SUCCESS;
	   }

	   Flist *temp = *f_head;

	   while((temp-> link) && (strcmp((temp-> file_name), name)))
					 temp = temp-> link;

	   if(!strcmp((temp-> file_name), name))
			  return REPEATATION;
	   else
	   {
			  temp-> link = new;
			  return SUCCESS;
	   }
}
