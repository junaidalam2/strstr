#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* my_strstr(char* param_1, char* param_2)
{
// param_1 is string
// param_2 is the substring

int flag;
int firstLetterCounter = 0;
int k;
int l;
int m;
int p;
int firstletter[strlen(param_1)];
int numOfFirstLetterPositions;


    // if string is null or string is shorter than substring, return null
    if(strlen(param_1) == 0 || strlen(param_1) < strlen(param_2) ) {
        return NULL;
    }

    // if substring is null, return string
    if(strlen(param_2) == 0 ){
        return param_1;
    }

    // populate array firstletter with positions of first letter of substring within string
    for(p = 0; p < strlen(param_1); p++){
            //printf("First For Loop w/ p => p: %d, param_2 length: %d\n", p, strlen(param_2));
            if(param_2[0] == param_1[p] && (strlen(param_1) - p) >= strlen(param_2)) { // will add to array firstLetter if remaining letters in string >= position of first letter
                //printf("If stmt in first for loop w/ p => p: %d, param_2 length: %d, param1 - p: %d\n", p, strlen(param_2), (strlen(param_1)-p));
                //printf("param2 char: %c, param1 p: %c\n", param_2[0], param_1[p]);
                firstletter[firstLetterCounter] = p;
                //printf("FirstLetter from Array: %d, firstLetterCounter: %d\n", firstletter[firstLetterCounter], firstLetterCounter);
                firstLetterCounter++;
                //printf("firstLetterCounter: %d\n", firstLetterCounter);
            }
        }

    // if no match on first letter, return null
    if(firstLetterCounter == 0){
        return NULL;
    }

    numOfFirstLetterPositions = firstLetterCounter;

    while(firstLetterCounter > 0 ) {

        // numOfFirstLetterPositions is a constant; firstLetterCounter is decremented after each iteration of while loop
        flag = firstletter[numOfFirstLetterPositions - firstLetterCounter];

        l = flag;

        char* output = (char*)malloc((strlen(param_1)-flag)*sizeof(char));

        // append the remaining portion of the string (after the flag) to output
        for(k = 0; k <(strlen(param_1)-flag); k++){
            output[k] = param_1[l];
            //printf("Third For Loop=> k: %d, (strlen(param_1)-flag: %d, output[k]: %c, param_1[l]: %c\n", k, strlen(param_1)-flag, output[k], param_1[l]);
            l++;
        }

        output[strlen(param_1)-flag] ='\0';

        //check if output matches the substring where output and the substring should overlap
        for(m = 0; m <(strlen(param_2)); m++){
            if(param_2[m] != output[m]) {
                firstLetterCounter--;
                break;
            }
        }
        // if for loop immediately above went through the entire substring, return output
        //printf("Output: %s\n", output);
        if(m == strlen(param_2)){
            return output;
        }

    }

return NULL;

}




int main() {

    printf("Output: %s\n", my_strstr("mississippi", "i"));


    return 0;
}
