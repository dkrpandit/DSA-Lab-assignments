/* Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
(Note: Handle queue full condition by considering a fixed size of a queue.)
 */
#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int size;
    int *array;
    int front;
    int rear;

public:
    CircularQueue(int size)
    {
        this->size = size;
        array = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int element)
    {
        if ((front == 0) && (rear == size - 1))
        {
            cout << "Queue is full \n";
        }
        else if (front == -1)
        {
            rear = front = 0;
            array[rear] = element;
            cout << "Element is added \n";
        }
        else if ((rear == size - 1) && (front != 0))
        {
            rear = 0;
            array[rear] = element;
            cout << "Element is added \n";
        }
        else
        {
            rear++;
            array[rear] = element;
            cout << "Element is added \n";
        }
    }
    void pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty \n";
        }
        else if ((front == size - 1) && rear != 0)
        {
            array[front] = -1;
            front = 0;
            cout << "Element is popped \n";
        }
        else
        {
            array[front] = -1;
            front++;
            cout << "Element is popped \n";
        }
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty \n";
        }
        else
        {

            if (rear >= front)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << array[i] << " ";
                }
                // printf("%d ", array[i]);
                cout<<"\n";
            }
            else
            {
                for (int i = front; i < size; i++)
                {
                    cout << array[i] << " ";
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << array[i] << " ";
                }
                cout << "\n";
            }
        }
    }
};
int main()
{
    int size, element, choice;
    cout<<"Enter size of circular queue :-  ";
    cin>>size;
    CircularQueue c(size);
    // CircularQueue c(4);
    // c.push(12);
    // c.push(15);
    // c.push(10);
    // c.push(14);
    // c.pop();
    // c.push(18);
    // c.display();
    do
    {
        cout << "1.Insertion (Enqueue)\n";
        cout << "2.Deletion (Dequeue)\n";
        cout << "3.Display\n";
        cout << "0.Exit\n";
        cout << "Enter your choice :-  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element :- ";
            cin >> element;
            c.push(element);
            break;
        case 2:
            c.pop();
            break;
        case 3:
            c.display();
            break;
        }
    } while (choice != 0);

    return 0;
}
/* Output :- 
Enter size of circular queue :-  4
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  1
Enter element :- 2
Element is added 
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  1
Enter element :- 121
Element is added 
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  1
Enter element :- 121
Element is added
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  1 
Enter element :- 1212
Element is added
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  1 
Enter element :- 1212
Queue is full
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  3
2 121 121 1212
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  2
Element is popped
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  2
Element is popped
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  3
121 1212
1.Insertion (Enqueue)
2.Deletion (Dequeue)
3.Display
0.Exit
Enter your choice :-  0
 */