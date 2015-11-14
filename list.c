#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include"mysort.c"
int my_insert(GameListNode **head,GameNode gamenode)
{ 
	//find the correct site to insert the gamenode 
	//here is insert by the gamename
	GameListNode* previous =*head;
	GameListNode* current = *head;

	GameListNode* new;


//need at the bg/





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
	//at the bg
	if(current->prev==NULL)
	{
		new = (GameListNode*)malloc(sizeof(GameListNode));
		new->gamenode=gamenode;
		new->next=*head;
		current->prev=new;
		*head=new;
		return 1;
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




GameListNode *my_query(GameListNode *head,int gamename)
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
	return  current;

}


//a very simple sortByKeyWord
//need imporve
int * sortByKeyWord(GameListNode *head,int keyWord)
{
	int len=1;
	int i;
	int count=0;
	GameListNode *current=head;
	if(current->next!=NULL)
	{
		len++;
		current=current->next;
	}
    switch(keyWord){
		//gamename
		case(0):
			{
			int *sort=malloc(sizeof(int)*len);
			current=head;
			for (i=0;i<len;i++)
			{sort[i]=(current->gamenode).Gamename;
			current=current->next;
			}mergeSort(sort,0,len-1);
			return sort;
			
			}
		//GameIntroduction
		case(1):
			{
				printf("????%d\n",len);
			int *sort=malloc(sizeof(int)*len);
			current=head;
			for (i=0;i<len;i++)
			{sort[i]=(current->gamenode).GameIntroduction;
			printf("sort[%d]=%d\n",i,sort[i]);
				current=current->next;
			}mergeSort(sort,0,len-1);
			return sort;
			
			}

		//CompanyIntroduction
		case(2):
			{
			int *sort=malloc(sizeof(int)*len);
			current=head;
			for (i=0;i<len;i++)
			{sort[i]=(current->gamenode).CompanyIntroduction;
			current=current->next;
			}mergeSort(sort,0,len-1);
			return sort;
			
			}
	//PlayingHours
		case(3):
			{
			int *sort=malloc(sizeof(int)*len);
			current=head;
			for (i=0;i<len;i++)
			{sort[i]=(current->gamenode).PlayingHours;
			current=current->next;
			}mergeSort(sort,0,len-1);
			return sort;
			
			}
//achievement
		case(4):
			{
				AchievementNode *this;
				current=head;
				for (i=0;i<len;i++)
				{
					if(((current->gamenode).head)!=NULL)
				     count++;
					this=(current->gamenode).head;

					while(this->next!=NULL)
					{
						count++;
						this=this->next;
					}
					current=current->next;
				}
               int *sort=malloc(sizeof(int)*count);
                 count=0;
				for (i=0;i<len;i++)
				{
					if((current->gamenode).head!=NULL)
				     sort[count++]=((current->gamenode).head)->achievement;
					this=(current->gamenode).head;

					while(this->next!=NULL)
					{

				     sort[count++]=this->achievement;
						this=this->next;
					}
					current=current->next;
				}
				mergeSort(sort,0,count-1);
			    return sort;
			
	

			}
		default:
			return 0;
	}


}





















