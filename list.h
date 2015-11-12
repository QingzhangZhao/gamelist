

typedef struct Achievement{
	struct Achievement *prev;
	char achievement[20];
	struct Achievement *next;
}AchievementNode;

typedef struct Game {
	char GameName[50];
	char GameIntroduction[100];
	char CompanyIntroduction[100];
	int PlayingHours;
	struct Achievement *head;
}GameNode;

typedef struct GameList{
	struct GameList *prev;
	struct GameName gamenode;
	struct GameList *next;
}GameListNode;



void  insert(struct Game,int site);
void  remove(int site);

struct GameNodee query(char *gamename);

enum KeyWord{GameName,GameIntroduction,CompanyIntroduction,PlayingHours,Achievement};
sortByKeyWord(KeyWord keyWord);

