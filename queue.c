# include<stdio.h>
# define MAX 50

int cqueue_arr[MAX];
int front = -1;
int rear = -1;


void Enqueue(int item)
{
  if((front == 0 && rear == MAX-1) || (front == rear+1))
  {
    printf("Queue Overflow \n");
    return;
  }
  if (front == -1)   
  {
    front = 0;
    rear = 0;
  }
  else
  {
    if(rear == MAX-1)  
      rear = 0;
    else
      rear = rear+1;
  }
  cqueue_arr[rear] = item ;
  printf("Item has been inserted");
}
 
void dequeue()
{
  if (front == -1)
  {
    printf("Queue Underflow\n");
    return ;
  }
  printf("Element deleted from queue is : %d\n",cqueue_arr[front]);
  if(front == rear)  
  {
    front = -1;
    rear=-1;
  }
  else
  {  
    if(front == MAX-1)
      front = 0;
    else
      front = front+1;
  }
}
 
void display_element()
{
  int front_pos = front,rear_pos = rear;
  if(front == -1)
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements :\n");
  if( front_pos <= rear_pos )
    while(front_pos <= rear_pos)
    {
      printf("%d ",cqueue_arr[front_pos]);
      front_pos++;
    }
  else
  {
    while(front_pos <= MAX-1)
    {
      printf("%d ",cqueue_arr[front_pos]);
      front_pos++;
    }
    front_pos = 0;
    while(front_pos <= rear_pos)
    {
      printf("%d ",cqueue_arr[front_pos]);
      front_pos++;
    }
  }
  printf("\n");
}
 
int main()
{
  int choice,item;
  do
  {   printf("\n");
      printf("List of choice :1.Insert 2.Delete 3.Display 4.Quit\n");
   

    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1 :
        printf("Input the element for insertion in queue : ");
        scanf("%d", &item);

        Enqueue(item);
        break;
      case 2 :
        dequeue();
        break;
      case 3:
        display_element();
        break;
      case 4:
        break;
        default:
        printf("Wrong choice\n");
    }
  }while(choice!=4);
  
  return 0;
}
