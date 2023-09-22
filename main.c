#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int choose;
int i = 0;
int tache_counter = 0;
//int swap;
double Time[50];

struct input_Task
{
    char title[100];
    char status[100];
    char describ[100];
    int id;
    struct deadline
    {
        int y;
        int m;
        int d;
    };
};

struct input_Task in_Task[50];
struct input_Task out_Task;


void enter(int choose)
{
    switch(choose)
    {
    case 1:
        New_task();
        main();
        break;
    case 2:
        Serveral_task();
        main();
        break;
    case 3:

        Display_task();
        main();
        break;
    case 4:
        printf("Modifier une tache");
        break;
    case 5:
        printf("Supprimer une tache par identifiant");
        break;
    case 6:
        printf("Rechercher les Taches");
        break;
    case 7:
        printf("Statistiques");
        break;

    default:
        main();

    }
}
void New_task()
{


    printf("\n\t\t\t--------Welcome to the task add interface--------\n\n\n");

    printf("--Enter the Title of the task: ");
    scanf("%s", &in_Task[i].title);
    printf("--Enter the Status of the task: ");
    scanf("%s", &in_Task[i].status);
    printf("--Enter the Describ of the task: ");
    scanf("%s", &in_Task[i].describ);
    printf("--<<Enter the Deadline of the task dd/mm/yy>>\n");
    printf("Enter the day: ");
    scanf("%d", &in_Task[i].d);
    printf("Enter the month: ");
    scanf("%d", &in_Task[i].m);
    printf("Enter the year: ");
    scanf("%d", &in_Task[i].y);

    Time[i] = (in_Task[i].d * 24 * 60 * 60) + (in_Task[i].m * 30 * 24 * 60 * 60) + ((in_Task[i].y -1970)* 365 * 24 * 60 * 60);

    printf("The minute: %ld", Time[i]);

    in_Task[i].id = tache_counter + 1;

    tache_counter++;


}


void Serveral_task()
{

    int N = 1;
    printf("\n\t\t\t--------Welcome to the tasks add interface--------\n\n\n");

    printf("Enter how many tasks do you want: ");
    scanf("%d", &n);
    n+=tache_counter;

    for(int i = tache_counter ; i < n; i++)
    {
        printf("--Enter the Title of the task %d: ", N);
        scanf("%s", &in_Task[i].title);
        printf("--Enter the Status of the task: ");
        scanf("%s", &in_Task[i].status);
        printf("--Enter the Describ of the task: ");
        scanf("%s", &in_Task[i].describ);
        printf("--<<Enter the Deadline of the task dd/mm/yy>>\n");
        printf("Enter the day: ");
        scanf("%d", &in_Task[i].d);
        printf("Enter the month: ");
        scanf("%d", &in_Task[i].m);
        printf("Enter the year: ");
        scanf("%d", &in_Task[i].y);

        Time[i] = (in_Task[i].d * 24 * 60 * 60) + (in_Task[i].m * 30 * 24 * 60 * 60) + (in_Task[i].y * 365 * 24 * 60 * 60);
        N++;
        in_Task[i].id = tache_counter + 1;
        tache_counter++;


    }
}



void Sort_task()
{
    int result;

    for(i = 0; i < n; i++)
    {
        for(int r = i + 1; i < n; r++)
        {
            result = strcmp(in_Task[i].title, in_Task[r].title);
            if(result > 0)
            {
                out_Task = in_Task[i];
                in_Task[i]= in_Task[i + 1];
                in_Task[i + 1]= out_Task;
            }
        }
    }


}


void Display_task(int n)
{
  Sort_task();

    int day_type = 86400;



    printf("\n\t\t\t--------Welcome to the list tasks interface--------\n\n\n");

    printf("\t________________________________________________________________________________________\n");
    printf("\t|\t      \t|\t        \t|\t       \t|\t   \t|\t      \t|\t\n");
    printf("\t|\t Title\t|\t Describ\t|\t Status\t|\t Id\t|\t Time\t|\n");
    printf("\t|\t      \t|\t        \t|\t       \t|\t   \t|\t      \t|\t\n");
    printf("\t________________________________________________________________________________________\n");
    printf("\t|\t      \t|\t        \t|\t       \t|\t   \t|\t      \t|\t\n");



    for(int j = 0; j < n; j++)
    {



            printf("\t|\t %s\t", in_Task[j].title);
            printf("|\t %s\t\t", in_Task[j].describ);
            printf("|\t %s\t", in_Task[j].status);
            printf("|\t %d\t", in_Task[j].id);
            printf("|  %.2lf\t|\n", Time[j] / day_type);




    }
    printf("\t________________________________________________________________________________________\n");

}


int main()
{


    printf("\n\t---Choose a the number to continue---\n\n\n");
    printf("\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\t\t\t<<<  1-Add a new task.\t\t\t\t\t>>>\n");
    printf("\t\t\t<<<  2-Add several new tasks.\t\t\t\t>>>\n");
    printf("\t\t\t<<<  3-Show list of all tasks.\t\t\t\t>>>\n");
    printf("\t\t\t<<<  4-Edit a task.\t\t\t\t\t>>>\n");
    printf("\t\t\t<<<  5-Delete a task by identifier.\t\t\t>>>\n");
    printf("\t\t\t<<<  6-Check for Stains.\t\t\t\t>>>\n");
    printf("\t\t\t<<<  7-Statistics.\t\t\t\t\t>>>\n");
    printf("\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
    printf("Enter the number of your choose here: ");
    scanf("%d", &choose);

    if(choose > 0 && choose < 8)
    {
        enter(choose);
    }
    else
    {
        printf("You have a wrong in your input");
        main();
    }
}


