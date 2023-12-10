#include <bits/stdc++.h>
using namespace std;

#define MaxSize 100
struct Car
{
  string NO;
  string time; // time tpye is 00:00
};
// struct StackNode
// {
//   Car *stackArray;
//   int top;
//   int num;
// };
class Stack
{
private:
  Car *stackArray;
  int top;
  int num;

public:
  Stack(int size)
  {
    num = size;
    stackArray = new Car[num];
    top = -1;
  }
  ~Stack()
  {
    delete[] stackArray;
  }
  bool isEmpty()
  {
    return top == -1;
  }
  bool isFull()
  {
    return top == num - 1;
  }
  void push(Car data)
  {
    if (isFull())
    {
      cout << "停车场已满，无法停车" << endl;
      return;
    }
    stackArray[++top] = data;
  }
  Car pop()
  {
    if (isEmpty())
    {
      cout << "停车场为空，无法离开" << endl;
      exit(1);
    }
    return stackArray[top--];
  }
  int getTop()
  {
    if (isEmpty())
    {
      exit(1);
    }
    return top;
  }
  void print()
  {
    cout << "停车场内的车辆：" << endl;
    for (int i = 0; i <= top; i++)
    {
      cout << stackArray[i].NO << "在 " << stackArray[i].time << "进入停车场" << endl;
    }
    cout << endl;
  }
};
struct Node
{
  Car data;
  Node *next;
};
class Queue
{
private:
  Node *front;
  Node *rear;

public:
  Queue()
  {
    front = nullptr;
    rear = nullptr;
  }

  ~Queue()
  {
    while (!isEmpty())
    {
      dequeue();
    }
  }

  bool isEmpty()
  {
    return front == nullptr;
  }

  void enqueue(Car data)
  {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty())
    {
      front = newNode;
      rear = newNode;
    }
    else
    {
      rear->next = newNode;
      rear = newNode;
    }
  }

  Car dequeue()
  {
    if (isEmpty())
    {
      cout << "便道为空" << endl;
      exit(1);
    }
    Node *temp = front;
    Car data = temp->data;
    front = front->next;
    delete temp;
    return data;
  }
  int length()
  {
    int len = 0;
    Node *current = front;
    while (current != nullptr)
    {
      len++;
      current = current->next;
    }
    return len;
  }
  void print()
  {
    if (isEmpty())
    {
      cout << "便道为空！" << endl;
      return;
    }
    Node *temp = front;
    int x = 1;
    while (temp != nullptr)
    {
      cout << temp->data.NO << "在便道的第 " << x << "个位置" << endl;
      temp = temp->next;
      x++;
    }
    cout << endl;
  }
};
int caltime(string &a, string &b)
{
  int sum = 0;
  if (stoi(a.substr(0, 2)) > stoi(b.substr(0, 2)))
  {
    sum = 60 * (stoi(b.substr(0, 2)) + 24 - stoi(a.substr(0, 2))) + stoi(b.substr(3, 2)) - stoi(a.substr(3, 2));
  }
  else if (stoi(a.substr(0, 2)) == stoi(b.substr(0, 2)))
  {
    if (stoi(a.substr(3, 2)) < stoi(b.substr(3, 2)))
      sum = stoi(b.substr(3, 2)) - stoi(a.substr(3, 2));
    else if (stoi(b.substr(3, 2)) == stoi(a.substr(3, 2)))
      sum = 24 * 60;
    else
      sum = 24 * 60 - (stoi(a.substr(3, 2)) - stoi(b.substr(3, 2)));
  }
  else
  {
    sum = 60 * (stoi(b.substr(0, 2)) - stoi(a.substr(0, 2))) + stoi(b.substr(3, 2)) - stoi(a.substr(3, 2));
  }
  return sum;
}

double calfee(int &time, double &cost)
{
  double fee;
  fee = time * cost;
  return fee;
}
bool checktime(string &time)
{
  int hh = stoi(time.substr(0, 2));
  int mm = stoi(time.substr(3, 2));
  int flag = 0;
  if (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59)
    flag = 1;
  if (!flag)
  {

    return 1;
  }
  return 0;
}
void start()
{
  cout << "Parking Lot Management System" << endl;
  cout << "AL='A'表示到达停车场，如果停车场有空位，就停入停车场，否则在门外便道候车。" << endl;
  cout << "AL='L'表示离开，如果在停车场，就根据停留时间进行缴费，否则不用收费。" << endl;
  cout << "AL='P'表示查询停车场停车状态。" << endl;
  cout << "AL='W'表示查询门外便道停车状态。" << endl;
  cout << "AL='Q'表示输入终止，等待退出程序。" << endl;
  cout << "请事先输入最大停车量n和停车每分钟所需要的费用cost." << endl;
  cout << endl;
}
int main()
{
  string AL; // Arrive or Leave or others;
  string NO;
  string time; // 00:00
  int n;
  double cost;
  start();
  cout << "最大停车量n = ";
  cin >> n;
  cout << endl;
  cout << "停车每分钟所需要的费用cost = ";
  cin >> cost;

  Stack parkingLot(n); // 创建停车场
  Queue waitingQueue;  // 创建便道
  while (cin >> AL)
  {
    if (AL == "A")
    {
      cin >> NO >> time;
      if (checktime(time))
      {
        cout << "Error! Please enter the time again." << endl;
        cin >> time;
      }
      Car car;
      car.NO = NO;
      car.time = time;
      if (!parkingLot.isFull())
      {
        parkingLot.push(car);
        cout << NO << " 停放在停车场第 " << parkingLot.getTop() + 1 << " 个位置" << endl;
      }
      else
      {
        waitingQueue.enqueue(car);
        cout << NO << " 停放在便道上第" << waitingQueue.length() << "个位置" << endl;
      }
    }
    else if (AL == "L")
    {
      cin >> NO >> time;
      Car tempCar;
      Stack temp(n);
      bool isFound = false;
      // 从停车场中找到对应车辆并计算停留时间和费用
      while (!parkingLot.isEmpty())
      {
        tempCar = parkingLot.pop();
        if (tempCar.NO == NO)
        {
          if (!waitingQueue.isEmpty())
            isFound = true;
          break;
        }
        temp.push(tempCar);
      }
      while (!temp.isEmpty())
      {
        Car x = temp.pop();
        parkingLot.push(x);
      }
      if (!waitingQueue.isEmpty())
      {
        Car nextCar = waitingQueue.dequeue();
        nextCar.time = time;
        parkingLot.push(nextCar);
        cout << "汽车 " << nextCar.NO << "在" << nextCar.time << " 进入停车场" << endl;
      }

      if (isFound)
      {
        int ct = caltime(tempCar.time, time);
        cout << "汽车 " << NO << " 在停车场内停留的时间为 " << ct << "，应交纳的费用为" << calfee(ct, cost) << endl;
      }
      else
      {
        cout << "未找到汽车 " << NO << endl;
      }
    }
    else if (AL == "P")
    {
      // cout << "P" << endl;
      parkingLot.print();
    }
    else if (AL == "W")
    {
      // cout << "W" << endl;
      waitingQueue.print();
    }

    else if (AL == "Q")
    {
      // cout << "Q" << endl;
      system("pause");
      return 0;
    }
    else
      cout << "Error! Please enter again." << endl;
  }
}