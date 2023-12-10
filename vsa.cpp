#include <bits/stdc++.h>
using namespace std;
struct car
{
  string number;
  string time;
};
struct MStack
{
  car *base;
  int top;
  int size;
};
void DestroyStack(MStack &s);
void ClearStack(MStack &s);
bool EmptyStack(MStack &s);
int LengthStack(MStack &s);
bool PopStack(MStack &s, car &x);
void PushStack(MStack &s, car x);
bool TopStack(MStack &s, int &x);

void DestroyStack(MStack &s)
{
  delete[] s.base;
  s.top = s.size = 0;
}
void ClearStack(MStack &s)
{
  s.top = 0;
}
bool EmptyStack(MStack &s)
{
  return s.top == 0;
}
int LengthStack(MStack &s)
{
  return s.top;
}
bool TopStack(MStack &s, car &x)
{
  if (!EmptyStack(s))
  {
    x = s.base[s.top - 1];
    return 1;
  }
  else
    return 0;
}
void PushStack(MStack &s, car x)
{
  s.base[s.top] = x;
  s.top++;
}
bool PopStack(MStack &s, car &x)
{
  if (EmptyStack(s))
    return 0;
  x = s.base[s.top - 1];
  s.top--;
  return 1;
}
struct Node
{
  car data;
  Node *next;
};
struct MQueue
{
  Node *front;
  Node *rear;
};
void ClearQueue(MQueue &q);
void DeleteQueue(MQueue &q);
bool EmptyQueue(MQueue &q);
int LengthQueue(MQueue &q);
car RearQueue(MQueue &q);
car FrontQueue(MQueue &q);
void PushQueue(MQueue &q, car x);
bool PopQueue(MQueue &q, car &x);
bool FindQueue(MQueue &q, car &x);
void ClearQueue(MQueue &q)
{
  Node *p;
  while (q.front->next != NULL)
  {
    p = q.front;
    q.front = q.front->next;
    delete p;
  }
  q.rear = q.front;
}
void DeleteQueue(MQueue &q)
{
  ClearQueue(q);
  delete q.front;
  q.front = q.rear = NULL;
}
bool EmptyQueue(MQueue &q)
{
  return q.front == q.rear;
}
int LengthQueue(MQueue &q)
{
  int num = 0;
  Node *p = q.front->next;
  while (p != NULL)
  {
    num++;
    p = p->next;
  }
  return num;
}
car FrontQueue(MQueue &q)
{
  return q.front->next->data;
}
car EndQueue(MQueue &q)
{
  return q.rear->data;
}
void PushQueue(MQueue &q, car x)
{
  Node *p = new Node;
  p->data = x;
  q.rear->next = p;
  q.rear = p;
  p->next = NULL;
}
bool PopQueue(MQueue &q, car &x)
{
  if (EmptyQueue(q))
    return 0;
  Node *p = q.front->next;
  q.front->next = p->next;
  x = p->data;
  if (p == q.rear)
    q.rear = q.front;
  delete p;
  return 1;
}
bool FindQueue(MQueue &q, car &x)
{
  Node *p = q.front;
  while (p->next != NULL)
  {
    if (p->next->data.number == x.number)
    {
      Node *q = p->next;
      p->next = q->next;
      delete q;
      return 1;
    }
    p = p->next;
  }
  return 0;
}
int compare(car a, car b)
{
  int ax, ay, bx, by;
  if (a.time[1] >= '0' && a.time[1] <= '9')
  {
    ax = ((int)a.time[0] - 48) * 10 + (int)a.time[1] - 48;
    ay = ((int)a.time[3] - 48) * 10 + (int)a.time[4] - 48;
  }
  else
  {
    ax = a.time[0] - 48;
    ay = (a.time[2] - 48) * 10 + a.time[3] - 48;
  }
  if (b.time[1] >= '0' && b.time[1] <= '9')
  {
    bx = (b.time[0] - 48) * 10 + b.time[1] - 48;
    by = (b.time[3] - 48) * 10 + b.time[4] - 48;
  }
  else
  {
    bx = b.time[0] - 48;
    by = (b.time[2] - 48) * 10 + b.time[3] - 48;
  }
  // cout << ax << " " << ay << " " << bx << " " << by << endl;
  // cout << (int)a.time[0] << " " << (int)a.time[1] << " " << (int)b.time[0] << " " << (int)b.time[1];
  int ans = (ax - bx) * 60 + ay - by;
  if (ans <= 0)
    ans += 1440;
  return ans;
}
int main()
{
  int n;
  cout << "请输入停车场规模：";
  cin >> n;
  double price;
  cout << "请输入停车场内1分钟所缴纳的费用：";
  cin >> price;
  cout << "请输入数据（到达/离去，汽车牌照号码，到达或离去的时刻）：";
  MStack s;
  MQueue q;
  s.base = new car[n];
  s.top = 0;
  s.size = n;
  q.front = q.rear = new Node;
  q.front->next = NULL;
  string Order, number, time;
  while (cin >> Order >> number >> time)
  {
    car a;
    a.number = number;
    a.time = time;
    if (Order == "到达")
    {
      if (s.top == s.size)
      {
        PushQueue(q, a);
        int x = LengthQueue(q);
        a.time = "0";
        cout << "车辆" << number << "停入便道第" << x << "个位置" << endl;
      }
      else
      {
        PushStack(s, a);
        int x = LengthStack(s);
        a.time = time;
        cout << "车辆" << number << "停入停车场第" << x << "个位置" << endl;
      }
    }
    else if (Order == "离去")
    {
      bool flag = 0;
      MStack s1;
      s1.base = new car[n];
      s1.top = 0;
      s1.size = n;
      while (!EmptyStack(s))
      {
        car x;
        PopStack(s, x);
        if (x.number == a.number)
        {
          int Min = compare(a, x);
          double Ans = price * Min;
          cout << "车辆" << x.number << "从停车场驶离，"
               << "在停车场中停留" << Min << "分钟，应缴费" << Ans << "元" << endl;
          flag = 1;
          break;
        }
        PushStack(s1, x);
      }
      while (!EmptyStack(s1))
      {
        car x;
        PopStack(s1, x);
        PushStack(s, x);
      }
      if (LengthQueue(q) && LengthStack(s) != n)
      {
        car x;
        PopQueue(q, x);
        x.time = time;
        PushStack(s, x);
        cout << "车辆" << x.number << "停入停车场第" << n << "个位置" << endl;
      }
      if (!flag)
      {
        if (FindQueue(q, a))
        {
          cout << "车辆" << number << "从便道驶离，应缴纳0元" << endl;
        }
        else
        {
          cout << "数据错误" << endl;
        }
      }
      DestroyStack(s1);
    }
    else if (Order == "0")
    {
      break;
    }
    else
    {
      cout << "数据错误" << endl;
    }
    cout << "请输入数据（到达/离去，汽车牌照号码，到达或离去的时刻）：";
  }
  DestroyStack(s);
  DeleteQueue(q);
  system("pause");
  return 0;
}