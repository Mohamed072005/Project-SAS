#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n; // the box of the how many tasks the user he want
int choose;// user choose in menu
int i = 0;
int Master_Id = 0;
char edit_Status[20][20] = {"ToDo", "Doing", "Done"};


struct input_Task
{
    char title[100];
    char status[100];
    char describ[100];
    int id;

    int y;// years
    int m;// month
    int d;// days

};

struct input_Task in_Task[50]; //(in) it's mean inside the task
struct input_Task out_Task; // (out) it's mean out from the task


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

    case 3:;
        int choose_2;
        printf("To display the task by normal type choose [1], To display the task by alphabet choose [0]!!\n");
        printf("Enter your choose here: ");
        scanf("%d", &choose_2);
        if(choose_2 == 1){
            Display_task();
            main();
        }else{
            Sort_task();
            Display_task();
            main();
        }
        break;

    case 4:
        Edit_task();
        main();
        break;

    case 5:
        Delete_task();
        main();
        break;

    case 6:;
        int choose_3;
        printf("If you want to search on task by the Id enter [1], but if you want to search on task by the Title choose [2]");
        printf("Enter your choose here: ");
        scanf("%d", &choose_3);
        if(choose_3 == 2){
            search_task_Title();
            main();
        }else{
            search_task();
            main();
        }
        break;

    case 7:
        printf("Statistiques");
        break;

    default:
        main();
        break;

    }
}


void New_task()
{


    printf("\n\t\t\t--------Welcome to the task add interface--------\n\n\n");

    printf("--Enter the Title of the task: ");
    scanf(" %[^\n]s", &in_Task[i].title);
    strcpy(in_Task[i].status, edit_Status[0]);
    printf("The status: %s\n", in_Task[i].status);
    printf("--Enter the Describ of the task: ");
    scanf(" %[^\n]s", &in_Task[i].describ);
    printf("--<<Enter the Deadline of the task dd/mm/yy>>\n");
    printf("Enter the day: ");
    scanf(" %d", &in_Task[i].d);
    printf("Enter the month: ");
    scanf(" %d", &in_Task[i].m);
    printf("Enter the year: ");
    scanf(" %d", &in_Task[i].y);

    in_Task[i].id = Master_Id;

    Master_Id++;
    i++;





}


void Serveral_task()
{

    int N = 1;// number of task
    printf("\n\t\t\t--------Welcome to the tasks add interface--------\n\n\n");

    printf("Enter how many tasks do you want: ");
    scanf("%d", &n);


    for(int j=0 ; j < n; j++)
    {
        printf("--Enter the Title of the task %d: ", N);
        scanf(" %[^\n]s", &in_Task[i].title);
        strcpy(in_Task[i].status, edit_Status[0]);
        printf("The status: %s\n", in_Task[i].status);
        printf("--Enter the Describ of the task: ");
        scanf(" %[^\n]s", &in_Task[i].describ);
        printf("--<<Enter the Deadline of the task dd/mm/yy>>\n");
        printf("Enter the day: ");
        scanf(" %d", &in_Task[i].d);
        printf("Enter the month: ");
        scanf(" %d", &in_Task[i].m);
        printf("Enter the year: ");
        scanf(" %d", &in_Task[i].y);

        in_Task[i].id = Master_Id;

        Master_Id++;

        i++;
        N++;


    }
}



void Sort_task()
{

    for(int j = 0; j < n; j++)
    {
        for(int k = j + 1; k < i; k++)
        {
            if(strcmp(in_Task[j].title, in_Task[k].title) > 0)
            {
                out_Task = in_Task[j];
                in_Task[j] = in_Task[k];
                in_Task[k] = out_Task;
            }

        }
    }


}



void Display_task()
{

    printf("\n\t\t\t--------Welcome to the list tasks interface--------\n\n\n");

    printf("\t________________________________________________________________________________________\n");

    printf("\t|\t Title\t|\t Describ\t|\t Status\t|\t Id\t|\t Time\t|\n");
    printf("\t|\t      \t|\t        \t|\t       \t|\t   \t|\t      \t|\t\n");
    printf("\t________________________________________________________________________________________\n");
    printf("\t|\t      \t|\t        \t|\t       \t|\t   \t|\t      \t|\t\n");



    for(int j = 0; j < i; j++)
    {

        printf("\t|\t %s\t", in_Task[j].title);
        printf("|\t %s\t\t", in_Task[j].describ);
        printf("|\t %s\t", in_Task[j].status);
        printf("|\t %d\t", in_Task[j].id);
        printf("| %d/%d/%d\t|\n", in_Task[j].d, in_Task[j].m, in_Task[j].y);



    }
    printf("\t________________________________________________________________________________________\n");

}



int search_task(){

    int id_Work;

    printf("\n\t\t\t--------Welcome to the search interface--------\n\n\n");


    int find_Id;// user input id
    printf("Enter the Id of the task: ");
    scanf("%d", &find_Id);


    for (int j = 0; j < i; j++){

        if(find_Id == in_Task[j].id){
            printf("\t The title: %s\n", in_Task[j].title);
            printf("\t The describ: %s\n", in_Task[j].describ);
            printf("\t The status: %s\n", in_Task[j].status);
            printf("\t The date: %d/%d/%d\n", in_Task[j].d, in_Task[j].m, in_Task[j].y);

            id_Work = j;

        }
    }
    return id_Work;


}



void Edit_task(){

    int edit = search_task();// edit is a box of Id (id_Work)
    printf("\n\t\t\t--------Welcome to the edit interface--------\n\n\n");


    int choose_Edit;

    printf("\n\n");
    printf("Enter the number of the information do you want to edit:\n\t1.Status\n\t2.Describ\n\t3.Time\n");
    printf("Enter here: ");
    scanf("%d", &choose_Edit);

    switch(choose_Edit){
    case 1:;
        int m;// choose between 1 and 2, Doing or Done

        printf("Enter 1 for [Doing] or 2 for [Done]: ");
        scanf("%d", &m);
        if (m == 1){
            strcpy(in_Task[edit].status, edit_Status[1]);
        }else{
            strcpy(in_Task[edit].status, edit_Status[2]);
        }
        break;
    case 2:;
        char edit_Describ[100];

        printf("Enter the new Describ: ");
        scanf(" %[^\n]s", &edit_Describ);
        strcpy(in_Task[edit].describ, edit_Describ);
        break;
    case 3:;
        int edit_day, edit_month, edit_year;

        printf("Enter the new Day: ");
        scanf("%d", &edit_day);
        in_Task[edit].d = edit_day;
        printf("Enter the new Month: ");
        scanf("%d", &edit_month);
        in_Task[edit].m = edit_month;
        printf("Enter the new Year: ");
        scanf("%d", &edit_year);
        in_Task[edit].y = edit_year;
        break;
    default :

        printf("You have a wrong in your input!!\nCheck it and try again");
        break;
    }

}


void Delete_task(){

    int Delete = search_task();

    printf("\n\t\t\t--------Welcome to the delete interface--------\n\n\n");

    int choose_Delete;

    printf("If you sur you want to delete this task enter [1],but if want go back to menu enter [0]\n");
    printf("Enter your choose here: ");
    scanf("%d", &choose_Delete);

    if(choose_Delete == 1){

       // int size = sizeof(in_Task) / sizeof(in_Task[0]);

        for(int j = Delete; j < i ; j++){
            in_Task[j] = in_Task[j + 1];
        }
        i--;
    }else{
        main();
    }
}


void search_task_Title(){

        printf("\n\t\t\t--------Welcome to the delete interface--------\n\n\n");

        char find_Title[20];
        printf("Enter the title of the task: ");
        scanf("%s", find_Title);

        for(int j = 0; j < i ; j++){
            if(strcmp(in_Task[j].title, find_Title) == 0){

                printf("\t The title: %s\n", in_Task[j].title);
                printf("\t The describ: %s\n", in_Task[j].describ);
                printf("\t The status: %s\n", in_Task[j].status);
                printf("\t The date: %d/%d/%d\n", in_Task[j].d, in_Task[j].m, in_Task[j].y);
                break;
            }
        }


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
    printf("\t\t\t<<<  6-Check for Tasks.\t\t\t\t\t>>>\n");
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


