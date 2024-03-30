#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENT 500
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    double duration;
} Student;

void moveSurnameToBeginning(char *fullname) {
    char firstname[100];
    char surname[100];

    int len = strlen(fullname);

    //Finding the position of the last space in the string
    int i = 0;
    for (i = len-1; i >= 0; i--) {
        if (fullname[i] == ' ') {
            break;
        }
    }

    //Copying firstname and surname
    strncpy(firstname, &fullname[i+1], len-i);
    strncpy(surname, fullname, i);

    //Rewriting the fullname
    strcpy(fullname, firstname);
    strcat(fullname, " ");
    strcat(fullname, surname);
}

int compareStudents(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return strcasecmp(studentA->name, studentB->name);
}



int main()
{
    FILE*input;
    char filename[100];
    char line[256];
    char *token;
    char *token2;
    char studentname[100];

    Student students[MAX_STUDENT];

    printf("Enter the input file name: \n");
    scanf("%s", filename);

    input = fopen(filename, "r");

    if(input == NULL)
    {
        printf("Error: Couldn't find a file with that name. Try again later. \n");
        exit(0);
    }

    fgets(line, sizeof(line), input);           //skipping the 1st line.


    int numOfStudents = 0;
    while(fgets(line, sizeof(line), input))
    {
        token = strtok(line, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        students[numOfStudents].duration = atof(token);

        token = strtok(NULL, ",");

        strcpy(students[numOfStudents].name, token);

        moveSurnameToBeginning(students[numOfStudents].name);

        numOfStudents++;
    }

    fclose(input);




    for (int i = 0; i < numOfStudents; i++) {
        for (int j = i + 1; j < numOfStudents; j++) {

            if(strcasecmp(students[i].name, students[j].name) == 0)
            {
                students[i].duration += students[j].duration;

                for(int k = j; k < numOfStudents - 1; k++)                  //sliding upper students by 1.
                {
                    strcpy(students[k].name, students[k+1].name);
                    students[k].duration = students[k+1].duration;
                }
                j--;
                numOfStudents--;
            }

        }
    }



    printf("Sort the results? (yes/no): \n");
    char ans[10];
    scanf("%s", ans);

    if(strcasecmp(ans, "yes") == 0)
    {
        qsort(students, numOfStudents, sizeof(Student), compareStudents);
    }


    for(int i=0; i<numOfStudents; i++)
    {
        printf("%s %.2f \n", students[i].name, students[i].duration);
    }


    return 0;
}
