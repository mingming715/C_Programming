#include <stdio.h>
#include <stdlib.h>

enum Sex {Male = 0, Female};

typedef struct{
    char name[40];
    int studentId;
    char grade[3];
    float total_score;
    enum Sex sex;
    struct{
        float mid;
        float fin;
        float proj;
    }Points;
}Grades;

int main(void)
{
    int i;
    Grades *a;
    int res;
    int N;
    FILE* fp;
    fp = fopen("input[13].txt", "r");
    fscanf(fp, "%d", &N);

    int* ind;

    a = (Grades *)malloc(sizeof(Grades) *(N));
    ind = (int*)malloc(sizeof(int)*(N));

    for(i=0; i<N; i++)
    {
        if(res == EOF)
        {
            break;
        }
        ind[i] = i;
        res = fscanf(fp, "%d %s %d %f %f %f", &a[i].studentId, a[i].name, &a[i].sex, &a[i].Points.mid, &a[i].Points.fin, &a[i].Points.proj);
        a[i].total_score = a[i].Points.mid * 0.3 + a[i].Points.fin * 0.3 + a[i].Points.proj * 0.4;
    }
    int j;
    for(i=0; i<N-1; i++){
        for(j=0; j<N-1; j++){
            if( a[ind[j]].total_score < a[ind[j+1]].total_score){
                int tmp = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = tmp;
            }
        }
    }

    printf("-- Student List --\n");
    for(i=0; i<N; i++)
    {
        printf("\n");
        printf("Id : %d\n", a[ind[i]].studentId);
            
        if(a[ind[i]].sex == 0)
        {
            printf("Name: %s (Male)\n", a[ind[i]].name);
        }
        else
        {
            printf("Name: %s (Female)\n", a[ind[i]].name);
        }

        printf("Grade(mid) : %f\n", a[ind[i]].Points.mid);
        printf("Grade(final) : %f\n", a[ind[i]].Points.fin);
        printf("Grade(project) : %f\n", a[ind[i]].Points.proj);

        if( a[ind[i]].total_score<50)
        {
            a[ind[i]].grade[0] ='F';
        }
        else if( i+1 < N*0.3 )
        {
            a[ind[i]].grade[0] = 'A';
        }
        else if( i+1 < N*0.7)
        {
            a[ind[i]].grade[0] = 'B';
        }
        else
        {
            a[ind[i]].grade[0] = 'C';
        }

        printf("Grade : %c (%f, %d)\n", a[ind[i]].grade[0], a[ind[i]].total_score, i+1);
    }

    fclose(fp);

}
