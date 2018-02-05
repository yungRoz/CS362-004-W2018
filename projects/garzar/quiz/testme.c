#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
// asciiPool contains int value for all available symbols
// those are [, (, {, space, a, x, }, ), ], r, e, s, t, null (which has no ascii code)
int asciiPool[14]= {91, 40, 123, 32, 97, 120, 125, 41, 93, 114, 101, 115, 116, 117};
int size = 14;

char inputChar()
{
    // TODO: rewrite this function
    int randomNum = rand()%14;
    
    char c = asciiPool[randomNum];
    
    return c;
}

char *inputString()
{

    static char s[6];
\
    int count = 0;
    while( count < 5)
    {
        s[count] = inputChar();
        count++;
    }
    s[5] = '\0';
    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    //char *s;
    //s = inputString();
    //printf("string: %s\n", s);
    return 0;
}
