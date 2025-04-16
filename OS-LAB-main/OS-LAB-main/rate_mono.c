#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct
{
    int id;        // Task ID
    int period;    // Task period
    int execution; // Task execution time
} Task;

void schedule(Task tasks[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (tasks[j].period > tasks[j + 1].period)
            {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    // Simulate scheduling
    printf("Rate-Monotonic Scheduling:\n");
    for (int time = 0; time < 100; time++)
    {
        printf("Time %d: ", time);
        for (int i = 0; i < n; i++)
        {
            if (time % tasks[i].period == 0)
            {
                printf("Task %d ", tasks[i].id);
            }
        }
        printf("\n");
    }
}

int main()
{
    Task tasks[MAX_TASKS] = {
        {1, 5, 1},
        {2, 10, 2},
        {3, 15, 3}};

    schedule(tasks, 3);
    return 0;
}
