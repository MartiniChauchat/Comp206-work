#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int monthday(int month)
{
    return 30;
}

void printdifferentspace(int day,int space)
{
    int x,y;
    if(day<10)
    {
        for(x=0;x<(space-2);x++)
        {
            printf(" ");
        }
    }
    else
    {
        for(y=0;y<(space-3);y++)
        {
            printf(" ");
        }
    }
        
}

void printspace(int space)
{
    int x;
    printf("|");
    for (x=0;x<space;x++)
    {
        printf(" ");
    }
}

void monthprint(int month)
{
    switch(month)
    {
        case 1: printf("January");
            break;
        case 2: printf("February");
            break;
        case 3: printf("March");
            break;
        case 4: printf("April");
            break;
        case 5: printf("May");
            break;
        case 6: printf("June");
            break;
        case 7: printf("July");
            break;
        case 8: printf("August");
            break;
        case 9: printf("September");
            break;
        case 10: printf("October");
            break;
        case 11: printf("November");
            break;
        case 12: printf("December");
            break;
    }
}

int getdaysize(int month){
    switch(month)
    {
        case 1: return 3;
            break;
        case 2: return 4;
            break;
        case 3: return 2;
            break;
        case 4: return 2;
            break;
        case 5: return 1;
            break;
        case 6: return 2;
            break;
        case 7: return 2;
            break;
        case 8: return 3;
            break;
        case 9: return 4;
            break;
        case 10: return 3;
            break;
        case 11: return 4;
            break;
        case 12: return 4;
            break;
    }
    return 0;
}

int weekdaysize(int weekday){
    switch(weekday)
    {
        case 1: return 6;
            break;
        case 2: return 7;
            break;
        case 3: return 9;
            break;
        case 4: return 8;
            break;
        case 5: return 6;
            break;
        case 6: return 8;
            break;
        case 7: return 6;
            break;
    }
    return 0;
}

int main(int argc,char *argv[])
{
    int month,weekday,daysize,firstday;
    int i,d;
    sscanf(argv[2],"%d",&firstday);
    sscanf(argv[1],"%d",&daysize);
    int days = firstday+5;
    int count = (daysize+3)*7+1;
    char eachmonth[13][11]={"","January","February","March","April","May","June","July","August","September","October",
        "November","December"};
    char eachday[8][300]={"","Sunday     ","Monday     ","Tuesday    ","Wednesday  ","Thursday   ","Friday     ","Saturday   "};
    if(argc!=3){
        printf("ERROR:wrong arguments\n");
        return -1;
    }
    
    if(((firstday>7)||(firstday<1))&&(daysize<2))
    {
        printf("ERROR:The firstday of the week must be between 1 and 7\nERROR:Cannot print days smaller than size 2\n");
        return -1;
    }
    if((firstday>7)||(firstday<1))
    {
        printf("ERROR:The firstday of the week must be between 1 and 7\n");
        return -1;
    }
    if((daysize<2))
    {
        printf("ERROR:Cannot print days smaller than size 2\n");
        return -1;
    }
    int index[12];
    int k;
    for(k=0;k<=12;k++)
    {
        index[k]=(int)strlen(eachmonth[k]);
    }
    /*setup and argument correctness check*/
    
    

        for(month=1;month<=12;month++)
        {
            
            
            int count2,count3,count4,count6;
            
            printf("|");
            for (count2=1;count2<=(count-2);count2++)
            {
                printf("-");
            }
            printf("|\n");
            /*first seperation line*/
            
            count4 = (count-2)/2-getdaysize(month);
            printf("|");
            for(count3=0;count3<=count4;count3++)
            {
                printf(" ");
            }
            monthprint(month);
            
            for(count6=1;count6<=(count-3-count4-index[month]);count6++)
            {
                printf(" ");
            }
            printf("|\n");
            /*second line: spacing and monthnames*/
            
            
            printf("|");
            for (count2=1;count2<=count-2;count2++)
            {
                printf("-");
            }
            printf("|\n");
            /*third line*/
            
            
            printf("|");
            int p,y;
            int space=(count-8)/7;
            for(p=1;p<8;p++)
            {
                printf(" ");
                for(y=0;y<daysize;y++){
                printf("%c",eachday[p][y]);
                }
                if(daysize<=11)
                {
                for(int ex=1;ex<=(space-daysize-1);ex++){
                printf("%c",eachday[2][9]);
                }
                }
                else if(daysize>11)
                {
                    for(int ez=1;ez<=(space-(int)(strlen(eachday[2]))-1);ez++)
                    {
                        printf("%c",eachday[2][9]);
                    }
                }
            printf("|");
        }
        printf("\n");
            /*header*/
            
            printf("|");
            for (count2=1;count2<=(count-2);count2++)
            {
                printf("-");
            }
            printf("|\n");
            /*last seperation line*/
            
            
            i = 1;    d = 1;
            weekday = (days + 1)%7;
            while(i<=weekday)
            {
                printf("|");
                for (int count7=0;count7<space;count7++)
                {
                    printf(" ");
                }
                i++;
            }
            
            while(d<=30)     //输出日期
            {
                weekday = (days + 1)%7;
                if(weekday==6)
                {
                    printf("| %d",d);
                    printdifferentspace(d,space);
                    printf("|\n");
                }
                else
                {
                    printf("| %d",d);
                    printdifferentspace(d, space);
                }
                if((d==30)&&(weekday!=6))
                {
                    for(int g=0;g<(6-weekday);g++)
                    {
                    printspace(space);
                    }
                    printf("|\n");
                }
                if((d==30)&&(weekday=6))
                {
                    printf("");
                }
                d++;
                days++;
            }
        }
    printf("|");
    for (int countok=1;countok<=(count-2);countok++)
    {
        printf("-");
    }
    printf("|\n");
    }

