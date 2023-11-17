#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100

typedef struct Node // the car
{
  char AL;  // Arrive&Leave
  int NO;   // the Car's number
  int time; // AL's time
} Node;

typedef struct Stack
{
  struct Node data[MaxSize];
  int top;
  int num;
} Sq;

struct QNODE
{
  struct Node data;
  QNODE *next;
};

typedef struct linkqueue // define the queue
{
  QNODE *front, *rear;
  int num;
} LinkQueue;

Sq *_init_SeqStack() // set a empty stack
{
  Sq *a;
  a = new Sq;
  a->top = -1;
  a->num = 0;
  return a;
}

LinkQueue *_init_LQueue() // set a empty queue.
{
  LinkQueue *q;
  QNODE *p;
  q = new LinkQueue;
  p = new QNODE;

  p->next = NULL;
  q->front = q->rear = p;
  q->num = 0;
  return q;
}
// attention the "IE" is mean "isempty"
int IE_SeqStack(Sq *s)
{
  if (s->top == -1)
    return 1;
  else
    return 0;
}
// attention the "IF" is mean "isfull"
int IF_SeqStack(Sq *s, int n)
{
  if (s->top == n - 1)
    return 1;
  else
    return 0;
}
int IE_LQueue(LinkQueue *q)
{
  if (q->front == q->rear)
    return 1;
  else
    return 0;
}

void Push_Lqueue(LinkQueue *q, Node s) // push the car into queue.
{
  QNODE *p;
  p = new QNODE;
  p->data = s;
  q->num++;
  p->next = NULL;
  q->rear->next = p;
  q->rear = p;
}

void Push_SeqStack(Sq *p, Node s) // push the car into stack
{

  p->top++;
  p->data[p->top] = s;
  // p->data.at(p->top)=s;??
  p->num++;
}

int POP_SeqStack(Sq *s, Node car) // when the car leave,cout the time.
{
  Sq *p;
  int t;
  p = _init_SeqStack();

  while (s->data[s->top].NO != car.NO)
  {
    Push_SeqStack(p, s->data[s->top]);
    s->top--;
    s->num--;
  }
  t = car.time - s->data[s->top].time;
  s->top--;
  s->num--;
  while (IE_SeqStack(p) == 0)
  {
    Push_SeqStack(s, p->data[p->top]);
    p->top--;
    p->num--;
  }
  return t;
}

Node Out_LQueue(LinkQueue *q) // out from the queue.
{
  QNODE *p;
  p = q->front->next;
  q->front->next = p->next;
  q->num--;
  if (q->front->next == NULL)
    q->rear = q->rear;
  return p->data;
  delete p;
}

int main()
{
  Sq *Parkstack;
  LinkQueue *Parkqueue;
  Node Car;
  int n; // using it as the maxsize of the park.
  int a = 0;
  int t;
  double cost; // the cost per minute.
  Parkstack = _init_SeqStack();
  Parkqueue = _init_LQueue();
  // cout << "停车场管理系统" << endl;
  cout << "Parking Lot Management System" << endl;
  cout << "Please enter the maxsize of Park " << endl;
  cout << "n= ";
  cin >> n;
  cout << endl;
  cout << "Please enter the cost per minute " << endl;
  cout << "cost= ";
  cin >> cost;
  cout << endl;
  //
  cout << "Please enter the car's information (including state, num, time)" << endl;
  cin >> Car.AL >> Car.NO >> Car.time; // the first car in

  while (Car.AL != 'Q') // the 'Q' is terminate the System.
  {
    if (Car.AL == 'A') // arrive
    {
      if (IF_SeqStack(Parkstack, n) == 1)
      {
        Push_Lqueue(Parkqueue, Car);
        // cout << "这辆这在门外便道第" << Parkqueue->num << "个位置" << endl;
        cout << "这辆这在门外便道第" << Parkqueue->num << "个位置" << endl;
        cout << endl;
        cout << "Please enter the car's information " << endl;
      }
      else
      {
        Push_SeqStack(Parkstack, Car);
        cout << "这辆这在停车场内第" << Parkstack->num << "个位置" << endl;
        cout << endl;
        cout << "Please enter the car's information " << endl;
      }
    }

    if (Car.AL == 'L') // leave
    {
      t = POP_SeqStack(Parkstack, Car);
      cout << "This car staytime is " << t << ", and the cost is " << t * cost << endl;
      cout << "Please enter the car's information " << endl;
      if (IE_LQueue(Parkqueue) == 0)
        Push_SeqStack(Parkstack, Out_LQueue(Parkqueue));
    }
    if (Car.AL == 'P' && Car.NO == 0 && Car.time == 0) // tell us the state of parking lot.
    {
      cout << "The number of cars in the parking lot is " << Parkstack->num << endl;
      cout << endl;
      cout << "Please enter the car's information " << endl;
    }
    if (Car.AL == 'W' && Car.NO == 0 && Car.time == 0) // tell us the state of waiting yard.
    {
      cout << "The number of cars in the waiting yard is " << Parkqueue->num;
      cout << endl;
      cout << "Please enter the car's information " << endl;
    }
    cin >> Car.AL >> Car.NO >> Car.time;
  }

  cout << "Finished!" << endl;

  system("pause");
  return 0;
}