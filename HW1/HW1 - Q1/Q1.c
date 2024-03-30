#include <stdio.h>

int main(){
    char filename[100]="";
    printf("Enter txt file name: \n");
    scanf("%s", filename);

    FILE *inp = fopen(filename, "r");
    FILE *inp2 = fopen(filename, "r");

    if (inp == NULL)
        {
            printf("Error: could not open file %s \n", filename);
            return 1;
        }

    int id;
    char results[1000];
    int team_count=0;



    while(fscanf(inp, "%d %s", &id, results) != EOF){
            team_count++;
    }
    printf("There are %d teams in total. \n", team_count);
    fclose(inp);

    for(int i=0;i<1000;i++){
        results[i]=' ';
    }

    while(fscanf(inp2, "%d %s", &id, results) != EOF){
        int s=0;

        for(int i=0; i<1000;i++)
        {
            if(results[i]=='L')
            {
                s+=0;
            }
            else if(results[i]=='W')
            {
                s+=3;
            }
            else if(results[i]=='D')
            {
                s+=1;
            }
            results[i]=' ';
        }
        printf("Team %d: %d \n", id, s);

    }

    fclose(inp2);







    return 0;
}
