#include"list.h"
#include<stdio.h>
#include<stdlib.h>
int my_insert(GameListNode **head,GameNode gamenode)
{ 
	//find the correct site to insert the gamenode 
	//here is insert by the gamename
	GameListNode* previous =*head;
	GameListNode* current = *head;

	GameListNode* new;


//need at the bg
//
//
//
//
//
//
//
//
//
	while  ((current->gamenode).Gamename<gamenode.Gamename)
	{   
		previous =current;
		current = current->next;
		// insert at the end
		if (current==NULL)
	    {
		    previous->next= (GameListNode*)malloc(sizeof(GameListNode));
			(previous->next)->gamenode=gamenode;
			 ((previous->next)->prev)=previous;
			 (previous->next)->next=NULL;
			return 1;
	     }

	}

	//malloc memory for inserting 
	new = (GameListNode*)malloc(sizeof(GameListNode));
	
	//return false if failed
	if (new==NULL)
		return 0;
	new->gamenode=gamenode;

	
	previous=current->prev;
	previous->next=new;
    new->next =current;
	new->prev =previous;
	current->prev=new;

	//return true if successful
	return 1;
}


int my_remove(GameListNode **head,int gamename)
{ 
	//remove game  by the gamename 
	GameListNode *current =*head;
    GameListNode *previous =*head;
	GameListNode *next =*head;
	while((current->gamenode).Gamename!=gamename)
	{
		current=current->next;
		//if there is no this game in the gamelist 
		//return false 
		if (current==NULL)
			return 0;
	}
	//if the game is in the gamelist,remove it 
    
	//if at the beginning 
	if(current->prev==NULL)
	{
		printf("test\n");
		*head=current->next;
		(current->next)->prev=NULL;

		free(current);
        current=NULL;		

		return 1;
	}

	previous =current->prev;
	previous->next=current->next;
    //if at the end 
	if (current->next==NULL)
	{
		free(current);
		return 1;
	}
	//not at the end
	else
	{
		(current->next)->prev=previous;
		free(current);
		return 1;
	}

}




GameNode *my_query(GameListNode *head,int gamename)
{ 
	//try to find the gameinfo in the gamelist by gamename
	
	GameListNode *current=head;
	while((current->gamenode).Gamename!=gamename)
	{
		current=current->next;
		//if there is no this game in the gamelist 
		//return false 
		if (current==NULL)
			return 0;
	}
	//return a pointer 
	return  &(current->gamenode);

}



int * sortByKeyWord(int keyWord)
{

}





















