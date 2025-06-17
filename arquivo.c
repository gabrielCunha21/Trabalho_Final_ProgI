#include<stdio.h>
#include<conio.h>
int main()


{
FILE *fp;
char ch;
fp = fopen("registroDePessoas.txt", "w");
printf("Insira dados");
while( (ch = getchar()) != EOF) {
  putc(ch,fp);
}
fclose(fp);
fp = fopen("registroDePessoas.txt", "r");

while( (ch = getc(fp)!= EOF)){
    printf("%c",ch);
}
  
  
fclose(fp);
return 0;
}