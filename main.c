#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char *  pop();
extern void push(char *);
extern int add(char *);
extern int isEmpty();
extern void printArray();

int main(int argc, char * argv[]){
	int ch;
	char charr[0];
  char charr2[0];
	int mem;
	char *inputstr;
	int valid;
  char *temp;
  int compare;
  mem = 1;
	valid = 0;

	while ((ch = getchar()) != EOF ) { //&& ch != '\n'
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
  			continue;
  		}
  	else if (ch == '<'){ 
  			ch = getchar(); 
  			if (ch != '/'){
          inputstr = (char*) malloc(1);
  				charr[0] = ch;
  				strcpy(inputstr,charr);

  				while ((ch = getchar())!='>'){
	  				mem++;
	  				charr[0] = ch;
	  				inputstr = (char*) realloc(inputstr,mem);
	  				strcat(inputstr,charr);
	  			}
	  			// printf("Start Tag: %s\n",inputstr);
	  			add(inputstr);
	  			push(inputstr);
	  		}
  			else if(ch == '/'){
  				ch = getchar();
          inputstr = (char*) malloc(1);
  				charr2[0] = ch;
  				strcpy(inputstr,charr2);
          while ((ch = getchar())!='>'){
	  				mem++;
	  				charr2[0] = ch;
  					inputstr = (char*) realloc(inputstr,mem);
	  				strcat(inputstr,charr2);
  				}
  				// printf("End Tag: %s\n",inputstr);
          temp = pop();
          if (temp==NULL){
            valid = -1;
          }
  				else{
            compare = strcmp(temp,inputstr);
            if(compare!=0){
  					valid = -1;
            }
  				}
  			}
  			mem = 1;
  	}
	} //while loop ends... No more characters
	if(pop()!=NULL){
    valid = -1;
  }
  //print the array only if it's valid
  if (valid == 0){
		printf("Valid\n");
    printArray();
	}
  else{
    printf("NOT Valid\n");
  }
  return 0;
}

