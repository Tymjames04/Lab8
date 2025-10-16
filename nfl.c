#include <stdio.h>

int nflScore;
//array will store [TD+2pt, TD+FG, TD, 3pt FG, Saftey]
int scores[4];

void recursive(int score){
    if(score == 0){
        printf("%d TD + 2pt,", scores[0]);
        printf(" %d TD + FG,", scores[1]);
        printf(" %d TD,", scores[2]);
        printf(" %d 3pt FG,", scores[3]);
        printf(" %d Saftey\n", scores[4]);
    }
    else{
        printf("test");
    }
}

int main(){
    printf("What is the score of your NFL game?: \n");
    scanf("%d", &nflScore);

    if(nflScore == 1){
        printf("This score is not possible. Program will end now.\n");
    }
    else{
        printf("Possible combinations of scoring plays if a team's score is %d\n", nflScore);
        recursive(nflScore);
    }
}