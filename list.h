//base types

//achievement linearlist
typedef struct Achievement{
	struct Achievement *prev;
	
	int  achievement;
	
	struct Achievement *next;
}AchievementNode;

// game content
typedef struct Game {
	//all is int just for sorting easily :P
	int Gamename;
	int GameIntroduction;
	int CompanyIntroduction; 
	int PlayingHours;

	AchievementNode  *head;
}GameNode;

//game list 
typedef struct GameList{
	struct GameList *prev;
	GameNode gamenode;
	struct GameList *next;
}GameListNode;


//base funciontsa,very simple

//insert a gamenode by gamename
//if insert successfully return 1 else 0

int   my_insert(GameListNode **head, GameNode gamenode);

//remove a gamenode by gamename 
//if remove successfully return 1 else 0

int   my_remove(GameListNode **head,int ganmename);

//return a pointer pointing the gamenode if the game is found
//else return NULL
GameListNode * my_query(GameListNode *head,int gamename);

//keyWord is in eum{Ganmename,GameIntroduction,CompanyIntroduction,PlayingHours,achievement}
//return a sorted int[] 
int  * sortByKeyWord(GameListNode *head,int keyWord);

