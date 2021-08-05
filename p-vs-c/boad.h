#define player 'O'
#define cpu 'X'
class Boad
{
    private:
        char matrix[3][3]; 
    public:
        Boad();
        void drow();
        void set(char hand,char turn);
        char geter(int i,int j);
};

int max(Boad& sboad, int depth);
int min(Boad& sboad, int depth);
char minmax(Boad& boad);
void input(Boad& boad, char turn);
void changep(char& turn);
int jadge(Boad& boad, char turn);
int score(Boad& boads, int depth);