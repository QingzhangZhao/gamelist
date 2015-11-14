#include "list.c"
#include<stdlib.h>

//just for a test 
int main()
{

    GameNode g1;
	g1.Gamename=2;
	g1.GameIntroduction=13;
	g1.CompanyIntroduction=12;
	g1.PlayingHours=20;

	GameNode g2;
	g2.Gamename=3;
    g1.GameIntroduction=2;
	g1.CompanyIntroduction=2;
	g1.PlayingHours=20;



	GameNode g3;
    g3.Gamename=1;
    g3.GameIntroduction=2;
	g3.CompanyIntroduction=2;
	g3.PlayingHours=20;




	GameNode g4;
	GameNode g5;

    GameListNode *head =  malloc(sizeof(GameListNode));
	head->prev=NULL;
	head->gamenode=g1;
    GameListNode *node2 =  malloc(sizeof(GameListNode));
	head->next=node2;
	node2->prev=head;
	node2->gamenode=g2;
	node2->next=NULL;
    
   printf("%d\n",my_insert(&head,g3));

   GameListNode *current=head;
   while(current!=NULL)
   {
	   printf("%d\n",(current->gamenode).Gamename);
	   current=current->next;
   }
    
   printf("%d\n",my_remove(&head,3));

   current=head;
   while(current!=NULL)
   {
	  printf("%d\n",(current->gamenode).Gamename);
	   current=current->next;
   }
   GameListNode * gn = my_query(head,1);
    if (gn!=NULL)
   printf("query%d",(gn->gamenode).GameIntroduction);
   
	
	
	
	return 0;
}

