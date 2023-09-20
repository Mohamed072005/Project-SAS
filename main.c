#include <stdio.h>
#include <stdlib.h>

int choose;

struct input_Task {
    char title[50];
    char status[20];
    char describ[100];
    int id[20];
    struct deadline {
        int y[20];
        int m[20];
        int d[20];
    };
};

void enter(int choose){
    switch(choose){
    case 1:
        N_tach();
        break;
    case 2:
        printf("Ajouter plusieurs nouvelles taches");
        break;
    case 3:
        printf("Afficher la liste de toutes les taches");
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
        printf("wrong");

    }
}
void N_tach(){
    struct input_Task in_Tach;

    printf("\n\t\t\t--------Welcome to the task add interface--------\n\n\n");

    printf("--Enter the Title of the task: ");
    scanf("%s", in_Tach.title);
    printf("--Enter the Status of the task: ");
    scanf("%s", in_Tach.status);
    printf("--Enter the Describ of the task: ");
    scanf("%s", in_Tach.describ);
    printf("--<<Enter the Deadline of the task dd/mm/yy>>\n");
    printf("Enter the day: ");
    scanf("%d", &in_Tach.d);
    printf("Enter the month: ");
    scanf("%d", &in_Tach.m);
    printf("Enter the year: ");
    scanf("%d", &in_Tach.y);

}
int main(){


    printf("\n\t---Choose a the number to continue---\n\n\n");
    printf("\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\t\t\t<<<  1-Add a new task.\t\t\t\t\t>>>\n");
    printf("\t\t\t<<<  2-Add several new tasks.\t\t\t\t>>>\n");
    printf("\t\t\t<<<  3-Show list of all tasks.\t\t\t\t>>>\n");
    printf("\t\t\t<<<  4-Modifier une tache.\t\t\t\t>>>\n");
    printf("\t\t\t<<<  5-Supprimer une tache par identifiant.\t\t>>>\n");
    printf("\t\t\t<<<  6-Rechercher les Taches.\t\t\t\t>>>\n");
    printf("\t\t\t<<<  7-Statistiques.\t\t\t\t\t>>>\n");
    printf("\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
    printf("Enter the number of your choose here: ");
    scanf("%d", &choose);

    enter(choose);


}
