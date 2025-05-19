#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void playerGuess(char *word, char *gWord, char *bodyPart[], int wLength);

int main(){
  printf("<--Hangman Game-->\n\n");
  printf("You will be given 6 guesses. After each wrong guesses there will be one body part drawn\n");
  printf("Body parts include:\n1.Head\n2.Body\n3.Left Arm\n4.Right Arm\n5.Left Leg\n6.Right Leg\n");
  printf("If the whole body part is drawn than the game is over!\n\n");

  char word[15];
  char *bodyPart[6] = {"Right Leg", "Left Leg", "Right Arm", "Left Arm", "Body", "Head"};

  printf("Enter the word: ");
  scanf("%14s", word);

  int wLength = strlen(word);
  char gWord[wLength];
  
  for(int i = 0; i < wLength; i++){
    gWord[i] = '_';
  }

  gWord[wLength] = '\0';
  
  printf("The word is: %s\n", gWord);
 
  playerGuess(word, gWord, bodyPart, wLength);
  
  return 0;
}

void playerGuess(char *word, char *gWord, char *bodyPart[], int wLength){
  int guess = 6;
  char pGuess;

  while (guess != 0) {
    int found = 0;

    printf("Guess Your Word: ");
    scanf(" %c", &pGuess);

    for(int i = 0; i < wLength; i++){
      if(pGuess == word[i]){
        gWord[i] = pGuess;
        found = 1;
      }
    }

    printf("%s\n", gWord);

    if(found == 0){
      printf("%s has been drawn\n", bodyPart[guess-1]);
      guess--;
      printf("You have %d guesses left\n", guess);
    }

    if(strcmp(gWord, word) == 0){
      printf("Congratulations! You have succesfully guessed the word.\n");
      break;
    }
  }
  
  if(guess == 0){
    printf("The game is Over. The Word was %s\n", word);
  }
}
