#include <iostream>

using namespace std;

const int MAX_PARKING_CAPACITY = 5; // Adjust the capacity as needed

// 车辆信息结构体
struct Car
{
  string licensePlate;
  int arrivalTime;
  int departureTime;
};

// 栈的实现
struct Stack
{
  Car cars[MAX_PARKING_CAPACITY];
  int top;

  Stack() : top(-1) {}

  bool isEmpty()
  {
    return top == -1;
  }

  bool isFull()
  {
    return top == MAX_PARKING_CAPACITY - 1;
  }

  void push(Car car)
  {
    if (!isFull())
    {
      top++;
      cars[top] = car;
    }
  }

  Car pop()
  {
    Car car;
    if (!isEmpty())
    {
      car = cars[top];
      top--;
    }
    return car;
  }

  Car peek()
  {
    return cars[top];
  }
  void display();
};

// 队列节点
struct Node
{
  Car car;
  Node *next;

  Node(Car c) : car(c), next(nullptr) {}
};

// 队列的实现
struct Queue
{
  Node *front;
  Node *rear;

  Queue() : front(nullptr), rear(nullptr) {}

  bool isEmpty()
  {
    return front == nullptr;
  }

  void enqueue(Car car)
  {
    Node *newNode = new Node(car);
    if (isEmpty())
    {
      front = rear = newNode;
    }
    else
    {
      rear->next = newNode;
      rear = newNode;
    }
  }

  Car dequeue()
  {
    Car car;
    if (!isEmpty())
    {
      Node *temp = front;
      car = temp->car;
      front = front->next;
      delete temp;
      if (front == nullptr)
      {
        rear = nullptr;
      }
    }
    return car;
  }
  void display();
};
// 在停车场类中添加一个 display 方法来显示停车场内车辆信息
void Stack::display()
{
  if (isEmpty())
  {
    cout << "停车场内没有车辆" << endl;
  }
  else
  {
    cout << "停车场内车辆信息：" << endl;
    for (int i = top; i >= 0; i--)
    {
      cout << "车牌号：" << cars[i].licensePlate << " 停留时间：" << cars[i].arrivalTime << "分钟" << endl;
    }
  }
}

// 在便道队列类中添加一个 display 方法来显示便道上车辆信息
void Queue::display()
{
  if (isEmpty())
  {
    cout << "便道上没有车辆" << endl;
  }
  else
  {
    cout << "便道上车辆信息：" << endl;
    Node *current = front;
    while (current != NULL)
    {
      cout << "车牌号：" << current->car.licensePlate << " 到达时间：" << current->car.arrivalTime << endl;
      current = current->next;
    }
  }
}
int calculateFee(int arrivalTime, int departureTime, double cost)
{
  // 这里简化为每分钟1元
  return (departureTime - arrivalTime) * cost;
}

void start() // 界面
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
  Stack parkingLot;
  Queue waitingQueue;
  int n; // using it as the maxsize of the park.
  double cost;
  start();
  cout << "Please enter the maxsize of Park " << endl;
  cout << "n= ";
  cin >> n;
  cout << endl;
  cout << "Please enter the cost per minute " << endl;
  cout << "cost= ";
  cin >> cost;
  cout << endl;
  while (true)
  {
    string AL;
    cin >> AL;

    if (AL == "A")
    {
      // cout << "Please enter the car's information (including licensePlate, arrivalTime)" << endl;
      Car car;
      cin >> car.licensePlate >> car.arrivalTime;

      if (!parkingLot.isFull())
      {
        parkingLot.push(car);
        cout << "车辆 " << car.licensePlate << " 在停车场内的位置：" << parkingLot.top + 1 << endl;
      }
      else
      {
        waitingQueue.enqueue(car);
        cout << "车辆 " << car.licensePlate << " 在便道的位置" << car.departureTime << endl;
      }
    }
    else if (AL == "L")
    {
      string licensePlate;
      int departureTime;
      cin >> licensePlate >> departureTime;

      // 将便道上的车辆移入停车场
      if (!waitingQueue.isEmpty() && !parkingLot.isFull())
      {
        Car carFromQueue = waitingQueue.dequeue();
        carFromQueue.arrivalTime = departureTime; // Set the arrival time of the car from the queue to the departure time
        parkingLot.push(carFromQueue);
      }

      // 寻找要离开的车辆
      Stack tempStack;
      bool found = false;
      while (!parkingLot.isEmpty())
      {
        Car currentCar = parkingLot.pop();

        if (currentCar.licensePlate == licensePlate)
        {
          found = true;
          int fee = calculateFee(currentCar.arrivalTime, departureTime, cost);
          cout << "车辆 " << currentCar.licensePlate << " 在停车场内停留时间：" << (departureTime - currentCar.arrivalTime) << "分钟，应交纳费用：" << fee << "元" << endl;
          break;
        }
        else
        {
          tempStack.push(currentCar);
        }
      }

      // 将暂存的车辆重新放回停车场
      while (!tempStack.isEmpty())
      {
        parkingLot.push(tempStack.pop());
      }

      if (!found)
      {
        cout << "未找到车辆 " << licensePlate << " 的信息" << endl;
      }
    }
    else if (AL == "P")
    {
      // 查询停车场停车状态
      cout << "停车场停车状态：" << endl;
      parkingLot.display();
    }
    else if (AL == "W")
    {
      // 查询便道停车状态
      cout << "便道停车状态：" << endl;
      waitingQueue.display();
    }
    else if (AL == "Q")
    {
      // 退出程序
      cout << "程序已退出" << endl;
      break; // 退出主循环
    }
    else
    {
      cout << "无效的操作" << endl;
    }
  }
  system("pause");
  return 0;
}
