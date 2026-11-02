#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// 1.加入/修改学生(可同名)及成绩
// 2.删除学生及成绩
// 3.查询学生成绩信息
// 4.查询第x名学生姓名与成绩信息
// 5.输出所有学生成绩信息
// 6.退出

char name[100];
char nam[100];
char symbolStr[2] = "*";
int score;
int sco;
int count = 0;
int ranking;



typedef struct
{
    char name[100];
    int score;
}Student;

Student student[100];

void level(int a)
{
    
    if(student[a].score <= 100 && student[a].score >= 97)
    {
        printf("A+ 4.5\n");
    }
    else if (student[a].score <= 96 && student[a].score >= 93)
    {
        printf("A 4.3\n");
    }
    else if (student[a].score <= 92 && student[a].score >= 89)
    {
        printf("A- 4.0\n");
    }
    else if (student[a].score <= 88 && student[a].score >= 85)
    {
        printf("B+ 3.8\n");
    }
    else if (student[a].score <= 84 && student[a].score >= 81)
    {
        printf("B 3.4\n");
    }
    else if (student[a].score <= 80 && student[a].score >= 77)
    {
        printf("B- 3.0\n");
    }
    else if (student[a].score <= 76 && student[a].score >= 73)
    {
        printf("C+ 2.6\n");
    }
    else if (student[a].score <= 72 && student[a].score >= 69)
    {
        printf("C 2.2\n");
    }
    else if (student[a].score <= 68 && student[a].score >= 65)
    {
        printf("C- 1.8\n");
    }
    else if (student[a].score <= 64 && student[a].score >= 60)
    {
        printf("D 1.2\n");
    }
    else if (student[a].score <= 59 && student[a].score >= 40)
    {
        printf("F 0\n");
    }
    else if (student[a].score <= 39 && student[a].score >= 0)
    {
        printf("F- 0\n");
    }

}

void swap(int a,int b)
{
    Student c;
    c = student[a];
    student[a] = student[b];
    student[b] = c; 
} 

void sort()
{
    for(int i = 0;i < count;i++)
    {
        for(int j = 0;j < count - i;j++)
        {
            if(student[j].score < student[j+1].score)
            {
                swap(j,j+1);
            }
        }
    }
}


int main()
{
    int choose;
    do
    {   
         printf("1.加入/修改学生及成绩\n"
           "2.删除学生及成绩\n"
           "3.查询学生成绩信息\n"
           "4.查询第x名学生姓名与成绩信息\n"
           "5.输出所有学生成绩信息\n"
           "6.退出\n");
    
        scanf("%d",&choose);

        switch (choose)
        {
            case 1:
            {
                printf("请输入学生姓名：(如：张三)\n");
                scanf("%s",nam);

                int found = -1;

                for(int i = 0;i < count;i++)
                {
                    if(strcmp(student[i].name , nam) == 0)
                    {
                        found = i;
                        break;
                    }
                }

                    if(found != -1)
                    {
                        printf("已存在%s,加入同名学生/修改该学生成绩？(1.加入同名学生 2.修改成绩)\n",nam);
                        int choose1;
                        scanf("%d",&choose1);

                        if(choose1 == 2)
                        {


                            printf("请修改学生成绩：");
                            scanf("%d",&student[found].score);

                            sort();
                        }
                        else
                        {

                            int sameNameCount = 0;
                            for(int i = 0;i < count;i++)
                            {

                                for(int j = 0;j < count;j++)
                                {
                                    if(strcmp(student[j].name , nam) == 0)
                                {
                                    sameNameCount++;
                                }
                                strcat(nam,symbolStr);

                                break;
                                }
                               

                            }



                            strcpy(student[count+1].name , nam);
                            printf("同名学生%s加入成功\n",student[count+1].name);
                            printf("请输入学生成绩：\n");
                            scanf("%d",&student[count].score);
                            printf("加入成功\n");

                            count++;

                            sort();

                        }
                    }
                    else
                    {                    

                        strcpy(student[count].name , nam);
                        printf("请输入学生成绩：\n");
                        scanf("%d",&student[count].score);
                        printf("加入成功\n");

                        count++;

                        sort();

                    }
                
                break;
            }
            case 2:
            {
                int found = 0;
                printf("请输入学生姓名：\n");
                scanf("%s",nam);

                for(int u = 0;u < count;u++)
                {
                    if(strcmp(student[u].name , nam) == 0)
                    {
                        for(;u < count - 1;u++)
                        {
                            student[u] = student[u+1];
                        }
                        printf("删除成功\n");
                        count--;
                    }
                    else
                    found++;

                }

                if(found == count)
                {
                    printf("不存在该学生\n");
                }

                break;
            }
            case 3:
            {
                int found =0;
                printf("请输入学生姓名：\n");
                scanf("%s",nam);

                for(int u = 0;u < count;u++)
                {
                    if(strcmp(student[u].name , nam) == 0)
                    {
                        printf("%d ",student[u].score);
                        level(u);
                    }
                    else
                    found++;

                }

                if(found == count)
                {
                    printf("不存在该学生\n");
                }
                
                break;
            }
            case 4:
            {
                
                printf("请输入学生排名：\n");
                scanf("%d",&ranking);

                if(ranking > count)
                {
                    printf("不存在该学生\n");
                }
                else
                {
                    printf("%s %d ",student[ranking-1].name,student[ranking-1].score);
                    level(ranking-1);
                }
                break;
            }
            case 5:
            {
                for(int i = 0;i < count;i++)
                {
                    printf("%s %d ",student[i].name,student[i].score);
                    level(i);
                }
                break;
            }
            case 6:
            {
                printf("退出成功\n");
                break;
            }
            default:
            {
                printf("输入错误，请重新输入\n");
                break;
            }
        } 
    }while (choose != 6);

    return 0;
}
