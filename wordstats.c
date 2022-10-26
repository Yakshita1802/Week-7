#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024
//The program should count each character and keep track of how many characters it sees before EOF. 
//It should also count how many whitespaces it sees along the way; we defined whitespace as either a space ‘ ‘ or a tab (special character '\t'). 
//The program should also count how many different words it sees; words are separated by whitespace or newlines. 
//wordstats should also track how many uppercase and lowercase letters it sees separately, as well as how many numeric digits it sees. 
//Finally, it should also count how many lines of text it reads; a newline indicator is '\n' (basically, you just count these).
//Check sample output for understanding the behavior of the program

int main () {
  int len = 0;
  int i;
  char buf[MAX_BUF];
  int chars = 0;
  int words = 0;
  int lines = 0;
  int whitespaces = 0;
  int uppercase = 0;
  int lowercase = 0;
  int digits = 0;

  while(fgets((buf + len), MAX_BUF, stdin) != NULL) {
    len = strlen(buf);
  }

  //Please do not modify the code above

  //Your code here
   for(int _index=0;_index<len;_index++)
   {
     chars++; // character count
     if(buf[_index]==' ')
     {
      whitespaces++; // Whitespaces count
      words++; // word count separated by whitespsce
     }
     else if(buf[_index]=='\n')
     {
      lines++; // new line 
      words++; // word count separated by newline
     }
     else if(buf[_index]>='0' && buf[_index]<='9') //The ascii values for "0" and "9" are 48 and 57, respectively.
     {
      digits++;
     }
     else if(buf[_index]>='a' && buf[_index]<='z') // The ascii values for "a" and "z" are 97 and 122, respectively.
     {
      lowercase++;
     }
     else if(buf[_index]>='A' && buf[_index]<='Z') // The ascii values for "A" and "Z" are 65 and 90, respectively.
     {
      uppercase++;
     }
   }
  
  //Please do not modify the code underneath
  printf("%d %d %d %d %d %d %d\n", chars, words, lines, whitespaces, uppercase, lowercase, digits);
}