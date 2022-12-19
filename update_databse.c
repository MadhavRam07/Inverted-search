#include"inverted_search.h"

int update_database( Wlist *head[], Flist **f_head, char *file_name)
{
    int ret_value = 1, empty;
    // validate
    empty = isFileEmpty(file_name);
    if(empty == FILE_NOTAVAILABLE)
    {
	printf("File : %s is not available\n", file_name);
	printf("Hence we are not adding into file linked list\n");
    }
    else if(empty == FILE_EMPTY)
    {
	printf("File : %s is empty\n", file_name);
	printf("Hence we are not adding into file linked list\n");
    }
    else
    {
	ret_value = to_create_list_of_files(f_head, file_name);
	if(ret_value == SUCCESS)
	{
	    printf("Sucessfull : inserting the filename : %s into file linked list\n", file_name);
	    return SUCCESS;
	}
	else if(ret_value == REPEATATION)
	{
	    printf("This file name : %s is repeatated, so it's not added in file linked list\n", file_name);
	}
	else
	{
	    printf("FAILURE\n");
	}
    }
}
