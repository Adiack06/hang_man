#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int numberOfWords = 0;
  
  FILE *fp = fopen("wordList.txt", "r");//* MEANS ITS A POINTER
  if (fp == NULL) //ERROR
  {
      return 1;
  }
  fseek(fp, 0, SEEK_END);//GOES TO END AND SEETS 
  size_t fsize = ftell(fp);//VARRIBALE OF TYPE SIZE_T TO THE CURRENT BYTES THROUGH THE FILE THE CURSOR IS
  fseek(fp, 0, SEEK_SET);//GOES TO START

  char *contents = malloc(fsize + 1);//ALLOCATES CHARECTOR ARRAY 
  fread(contents, 1, fsize, fp);//READS THE CONTESNT TO CONTENTS
  contents[fsize] = 0;//NULL TERMINATOR 
  fclose(fp);//CLOSES FILE
  
  for (int loopCounter = 0; loopCounter <= fsize; loopCounter += 1) 
    {
      if (contents[loopCounter] == '\n') 
      {
        numberOfWords = numberOfWords +1;
      }
    }
      
  printf("%d", numberOfWords);

  char **words = malloc(numberOfWords*sizeof(*words));
  char *word = malloc(1);
  char tmp_word[1]= "";
  int increments = 0;
  int loopIndex = 0;
    
    for (int loopCounter =0; loopCounter <= fsize; loopCounter += 1)
    {
        if (contents[loopCounter] == '\n')
        {
            char *wordcopy = malloc(strlen(word) + 1);
            strcpy(wordcopy, word);
            words[increments] = wordcopy;
            memset(word, 0, strlen(word)); // set momory of word to 0 for number of B it is in lenght
            increments = increments +1;
            loopIndex = 0;
        }
        else
        {
            word[loopIndex] = contents[loopCounter];
            loopIndex = loopIndex +1;
            if (loopIndex +1 >= sizeof(word))
            {
              realloc(word, 2*sizeof(word));
            }
        }
    }
    for (int loopCounter =0; loopCounter < numberOfWords; loopCounter += 1)
    {
        printf("%s\n",words[loopCounter]);
        free(words[loopCounter]);
    }


    

  free(contents);
}

