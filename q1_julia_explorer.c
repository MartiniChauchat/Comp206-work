#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sswap(char* x, char* y){
    char t[30];
    strcpy(t,x);
    strcpy(x,y);
    strcpy(y,t);
}

int main(int argc, char* argv[]){
    FILE *fp;
    char s[1000];
    char *bf[200];
    char a__1[100] = "a= ";
    char b__2[100] = "b= ";
    
    int i = 0;
    
    char firstfind[100] = "a= #A#\n";
    char secondfind[100] = "b= #B#\n";
    
    
    char input__1[50] = "";
    char input__2[50] = "";
    
    sprintf(input__1,"%.6f\n",atof(argv[2]));
    sprintf(input__2,"%.6f\n",atof(argv[3]));
    strcat(a__1,input__1);
    strcat(b__2,input__2);
    
    fp = fopen(argv[1],"r");
    
    if(argc!=4){
        printf("Error: bad float arg");
        return -1;
    }
    
    if(fp==NULL){
        printf("Error: bad file");
        return -1;
    }
    
    
    while(i<100 && fgets(s,50,fp)!=NULL){
        bf[i]=strndup(s,50);
        i++;
    }
    
    int finda,findb;
    int output=0;
    
    for(finda=0;finda<i;finda++)
    {
        if(strcmp(firstfind,bf[finda])==0){
            output=1;
            sswap(a__1,bf[finda]);
            break;
        }
    }
    if(output==0){
        printf("ERROR:not find\n");
    }
    
    for(findb=0;findb<i;findb++)
    {
        if(strcmp(secondfind,bf[findb])==0){
            output=1;
            sswap(b__2,bf[findb]);
            break;
        }
    }
    if(output==0){
        printf("ERROR:not Find\n");
    }
    

    fclose(fp);
    
    int count2;
    for(count2=0;count2<i;count2++){
        printf("%s",bf[count2]);
    }
    
    FILE *fp2;
    fp2 = fopen(argv[1],"w");
    
    int count;
    for(count=0;count<i;count++){
        fprintf(fp2,"%s",bf[count]);
    }
    
    fclose(fp2);
    return 0;
    
}
