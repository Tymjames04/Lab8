#include <stdio.h>
//array will store [TD+2pt, TD+FG, TD, 3pt FG, Saftey]
int scores[5];
//array holds the interger values of all possible scoring possibilities
int scoringValues[5] = {8, 7, 6, 3, 2};
//creates recursive function that takes in a score as well as an index
//index is used to iterate through both scores and scoring values so that the correct value is added for each type of score.
void recursive(int score, int index){
    //if the score is exactly 0, then the current recursion has reached a valid combination.
    if(score == 0){
        //following lines print out the current combo of scores.
        printf("%d TD + 2pt,", scores[0]);
        printf(" %d TD + FG,", scores[1]);
        printf(" %d TD,", scores[2]);
        printf(" %d 3pt FG,", scores[3]);
        printf(" %d Safety\n", scores[4]);
        //return statement returns to the last recursive call so more combinations can be found. 
        return;
    }
    //if a recursive call leads to a score less than 0 then it is an invalid combination so the function returns.
    if(score < 0){
        return;
    }
    //if a recursive call leads to an index that is 5 or more, then it is an invalid combination so the function returns.
    if(index >= 5){
        return;
    }
    //increments the count of the scores at the current index by 1
    scores[index]++;
    //calls the recursive function still at the same index, decreses the score by one score type of the current score type you are considering.
    recursive(score - scoringValues[index], index);
    //if the previous call returns back, that means it either was a correct score combo or was invalid.
    //in either case this now decreses the count of that score type by one before moving on.
    scores[index]--;
    //calls the recursive function and moves forward one index value meaning we will now be considering a different scoring type and its effect on the total score.
    recursive(score, index + 1);
}

//defines the main function of the program
int main(){
    //creates integer variable nflScore
    int nflScore;
    //prints the following line
    printf("What is the score of your NFL game?: \n");
    //scans the users input and stores that integer in the nflScore variable
    scanf("%d", &nflScore);
    //if the nflScore is less than 2 then this evaluates to true
    if(nflScore == 2 || nflScore < 0){
        //prints the following string telling the user you cannot have a score of two or less than 0
        printf("This score is not possible. Program will end now.\n");
    }
    else{
        //prints the following string followed by the score the user inputted. 
        printf("Possible combinations of scoring plays if a team's score is %d\n", nflScore);
        //calls the recurive function starting at the 0th index (touchdowns + 2pts)
        recursive(nflScore, 0);
    }
}