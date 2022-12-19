/*
Name:V.Madhav
Date:10-12-2022
Description:Inverted Search
Sample Execution:
Enter valid no.of arguments
./Slist.exe f1.txt f2.txt....
Select your choice among following options:
1. Create DATABASE
2. Display DATABASE
3. Update DATABASE
4. Search
5. Save DATABASE
Enter your choice
3
Enter the filename to update database
file1.txt
Enter the filename to update database
file1.txt
This file name : file1.txt is repeatated, so it's not added in file linked list
Do you want to continue ?
Enter y/Y to continue and n/N to discontinue
no     
*/

#include "inverted_search.h"
int main(int argc, char *argv[])
{
    int choice;
    char word[WORD_SIZE], option = 'y';
    system("clear");
    //Validate the cla

    Wlist *head[27] = {NULL};

    if(argc <= 1)
    {
	printf("Enter valid no .of arguments\n");
	printf("./Slist.exe f1.txt f2.txt....\n");
	return 0;
    }

    //Create the list of filenames
    //Declare head pointer

    Flist *f_head = NULL;

    //Validate the files
    file_validation_n_file_list(&f_head, argv);

    if(f_head == NULL)
    {
	printf("No files are available in the file linked list\n");
	printf("Hence the process terminated\n");
	return 1;
    }

    while(tolower(option) == 'y')
    {
	//Prompt menu
	printf("Select your choice among following options:\n");
	printf("1. Create DATABASE\n2. Display DATABASE\n3. Update DATABASE\n4. Search\n5. Save DATABASE\n");
	printf("Enter your choice\n");
	scanf("%d", &choice);
	__fpurge(stdin);
	switch(choice)
	{
	    case 1:
		//Create database
		create_database(f_head, head);
		printf("Successfull creation of database\n");
		break;

	    case 2:
		//display database
		display_database(head);
		break;	 
	    case 3:
		{
		    char file_name[FNAME_SIZE]; 
		    //prompt the user to enter new file name
		    printf("Enter the filename to update database: ");
		    scanf("%s" , file_name);
		    __fpurge(stdin);
		    //Update database
		    if(update_database(head, &f_head, file_name) == SUCCESS)
		    {
			Flist *temp = f_head;
			while(temp)
			{
			    if(!strcmp(temp-> file_name , file_name))
			    {
				if(create_database(temp, head) == SUCCESS)
				    printf("Successfull : Creation of database for file : %s\n", file_name);
			    }
			    temp = temp-> link;
			}
		    }
		    break;
		}

	
	    case 4:
		//Search database
		printf("Enter the word to search: ");
		scanf("%s", word);
		__fpurge(stdin);
		search(head, word);
		break;
	    case 5:		
		//Save database
		save_database(f_head, head);
		break;
	    default:
		printf("Invalid input\n");
		break;
	}
	printf("Do you want to continue ?\n");
	printf("Enter y/Y to continue and n/N to discontinue\n");
	scanf("%c", &option);
	__fpurge(stdin);
    }
}
