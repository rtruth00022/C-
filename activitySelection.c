#include<stdio.h>
#include<stdlib.h>

struct task
{
    int activity_number;
    int start;
    int end;
};

void input(struct task* activity,int n)
{

    printf("\nEnter start time and end time of %d tasks : \n\n",n);

    for(int i=0;i<n;i++)
    {
        printf("Start time %d : ",(i+1));
        scanf("%d",&(activity+i)->start);

        printf("End time %d : ",(i+1));
        scanf("%d",&(activity+i)->end);

        (activity+i)->activity_number = (i+1);

        //condition to check if data given by user is correct or not
        if( (activity+i)->end < (activity+i)->start)
        {
            printf("\nPls give proper input that has start time less than end time ...\n");
            printf("Re-Enter details of activity %d ... \n\n",(i+1));
            i--; //decrementing i because again details will be stored for the same index
        }

        printf("\n");
    }
}

void display(struct task* activity , int n)
{
    printf("LIST OF ACTIVITES : \n");
    for(int i=0;i<n;i++)
    {
        printf("Activity : %d   ( %d , %d ) \n" , (activity+i)->activity_number , (activity+i)->start , (activity+i)->end);
    }

    printf("\n");
}


//Sort the activites as per increasing order of their finishing time
void sort(struct task* activity , int n)
{
    int i,j,t;

    for(i=0 ; i<n ; i++)
    {

        for(j=i+1 ; j<n ; j++)
        {
            if( (activity+i)->end > (activity+j)->end )
            {
                int t = (activity+i)->end;
                (activity+i)->end = (activity+j)->end;
                (activity+j)->end = t;

                t = (activity+i)->start;
                (activity+i)->start = (activity+j)->start;
                (activity+j)->start = t;

                t = (activity+i)->activity_number;
                (activity+i)->activity_number = (activity+j)->activity_number;
                (activity+j)->activity_number = t;
            }
        }
    }
}

//Select the activites
void activitySelection(struct task* activity , int n)
{


    //sort the activites
    sort(activity , n);

    printf("\nAFTER SORTING \n");
    display(activity,n);

    //count stores the maximum number of activities that are to be done
    int count = 1; //the first activity is always included

    printf("\nACTIVITES DONE ARE : \n");

    printf("Activity : %d      ( %d , %d ) \n",activity->activity_number,activity->start , activity->end);
    //first activity of sorted list is always included

    int c=0;//index of the last included activity

    for(int i=1;i<n;i++)
    {
        if( (activity+i)->start >=  (activity+c)->end )
        {
            printf("Activity : %d      ( %d , %d ) \n",(activity+i)->activity_number,(activity+i)->start , (activity+i)->end);
            count++;
            c=i;
        }
    }

    printf("\nTotal number of activites included : %d \n",count);
}

int main()
{
    int n;

    printf("Enter the number of task to be performed : \n");
    scanf("%d",&n);

    struct task* activity = (struct task*)malloc(n*sizeof(struct task));

    input(activity,n);


    printf("\nBEFORE SORTING \n");
    display(activity,n);


    activitySelection(activity,n);

    return 0;
}
