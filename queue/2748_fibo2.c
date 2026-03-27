#if 0
#include <stdio.h>
int fibo(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
    
    return 0;
}
#endif
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
long long int queue[MAX];
int front = 0;
int rear = 0;
void init()
{
    front = 0;
    rear = 0;
}

int is_empty()
{
    return front == rear;
}

int is_full()
{
    return (rear + 1) % MAX == front;
}

void enqueue(long long int e)
{
    if (is_full())
    {
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = e;
}

long long int dequeue()
{
    if (is_empty())
    {
        return 0;
    }
    front = (front + 1) % MAX;
    return queue[front];
}

int main(void)
{
    init();
    enqueue(0);
    enqueue(1);

    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        long long int num_1 = dequeue();
        long long int num_2 = dequeue();
        enqueue(num_2);
        enqueue(num_1 + num_2);
    }
    dequeue();
    printf("%lld\n", dequeue());
    return 0;
}