#include <stdio.h>
#include <stdlib.h>
int num_of_stage, num_of_input, present_state, final_state, input[10], len;
char stage[10];
int input_alpha[2];
//int minArray[11][11];
void printTransitionTable(int table[num_of_stage][2])
{
    printf("\n");
    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < num_of_input; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

void minimize(int table[num_of_stage][num_of_input],int minArray[num_of_stage][num_of_stage])
{
    
  
    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < num_of_stage; j++)
        {
            if (i != j)
            {
                if ((i == final_state && j != final_state) || (i != final_state && j == final_state))
                    minArray[i][j] = 1;
                else
                    minArray[i][j] = 0;
            }
            else
                minArray[i][j] = 0;
        }
    }
    int flag = 1;
    while (flag)
    {
        flag = 0;

        {
            for (int i = 0; i < num_of_stage; i++)
            {
                for (int j = 0; j < num_of_stage; j++)
                {
                    if (i != j && !minArray[i][j])
                    {
                        for (int input = 0; input < num_of_input; input++)
                        {
                            int state1 = table[i][input];
                            int state2 = table[j][input];
                            if (minArray[state1][state2] || minArray[state1][state2])
                            {
                                minArray[i][j] = 1;
                                flag = 1;
                                break;
                            }
                        }
                    }
                    
                }
            }
        }
    }
    printf("minimized array\n");
    // printDFA(minArray);
    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("%d ", minArray[i][j]);
        }
        printf("\n");
    }
}
void printEquivalentStates(int minArray[num_of_stage][num_of_stage]){
     for (int i = 0; i < num_of_stage; i++)
    {
        for (int j =0; j < i+1; j++)
        {
            if((i != j && minArray[i][j]==0) ){
                printf("Equivalent states are: %c = %c\n",stage[i],stage[j]);
                //printf(" row %d = col %d\n",i,j);
            }
        }
    }
}
int main()
{

    printf("Enter stage number & number of input ");
    scanf("%d %d", &num_of_stage, &num_of_input);

    for (int i = 0; i < num_of_stage; i++)
    {
        printf("Enter stages: ");
        scanf(" %c", &stage[i]);
    }

    for (int j = 0; j < num_of_input; j++)
    {
        printf("Enter input alphabet ");
        scanf("%d", &input_alpha[j]);
    }

    char p_state, f_state;
    printf("Enter present & final state: ");
    scanf(" %c %c", &p_state, &f_state);
    for (int i = 0; i < num_of_stage; i++)
    {
        if (p_state == stage[i])
        {
            present_state = i;
        }
        if (f_state == stage[i])
        {
            final_state = i;
        }
    }
    // printf(" pf %d %d",present_state,final_state);
    int pS[num_of_stage][num_of_input];
    int minArray[num_of_stage][num_of_stage];

    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < num_of_input; j++)
        {
            printf("Enter transition state for State %c input %d: ", stage[i], input_alpha[j]);
            scanf("%d", &pS[i][j]);
        }
    }
    printf("transition table:\n");
    printf("final st: %d\n", final_state);
    printTransitionTable(pS);
    minimize(pS,minArray);
    printEquivalentStates(minArray);
}
