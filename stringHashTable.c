
//  
//
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HASH_TABLE_SIZE 1057

typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};

Entry hash_table[HASH_TABLE_SIZE];

void add(char * tag)
{
	int sum,i,n;
	sum = 0;
	for(n=0;n<strlen(tag);n++){
		// printf("The tag is %d long and the ASCII value is: %d\n",strlen(tag),tag[n]);
		sum = (int)tag[n] + sum;
	}
	i = sum % HASH_TABLE_SIZE;
	// printf("Sum: %d Hashed value: %d\n",sum,i);
	
	while(hash_table[i].string!= NULL){ //if the hashed index isn't empty...
		if ((strcmp(hash_table[i].string, tag)==0)){ //check if it's the same string... 
			hash_table[i].count++;
			break;
		}
		else{ //if not, move on and add 1, then re-evaluate if next index is empty.
			i++;
		}
	}
	if (hash_table[i].string == NULL){
	 		hash_table[i].string = malloc(strlen(tag)+1);
	 		strcpy(hash_table[i].string,tag);
			hash_table[i].count=1;
	}

}
//printing the array at only the populated indexes
void printArray(){
	int i;
	for(i=0;i<HASH_TABLE_SIZE;i++){
		if(hash_table[i].count>=1){
			printf("%s: %d\n",hash_table[i].string,hash_table[i].count);
		}
	}
} 
