/*
Consider a student database of SEIT class (at least 15 records). Database contains different fields of
every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list
of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
*/
#include <iostream>
#include <string.h>
const int num = 15;
using namespace std;
class student
{

    // private:
    //     int roll_no;
    //     char name[20];
    //     float SGPA;
public:
    int roll_no;
    char name[20];
    float SGPA;

public:
    void accept_student_data(student list[], int size);
    void Display(student list[], int size);
    void bubble_sort(student s[], int size);
    void QuickSort(student s[], int first, int last);
    void insertion_sort(student s[], int size);
    void search(student s[], int size);
    int binary_search(student s[], int low, int high);
};
void student::accept_student_data(student list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter your roll number \n";
        cin >> list[i].roll_no;
        cout << "Enter your name \n";
        cin >> list[i].name;
        cout << "Enter your SGPA \n";
        cin >> list[i].SGPA;
    }
}
void student::Display(student list[], int size)
{
    cout << "roll number \tName \tSGPA \n";
    for (int i = 0; i < size; i++)
    {
        cout << list[i].roll_no << "\t       " << list[i].name << "\t" << list[i].SGPA << "\n";
    }
}
/*
1.Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
Bubble Sort)
*/
void student::bubble_sort(student s[], int size)
{
    student temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (s[j].roll_no > s[j + 1].roll_no)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
// 2. Arrange list of students alphabetically. (Use Insertion sort)

void student::insertion_sort(student s[], int size)
{
    student temp;
    for (int i = 0; i < size; i++)
    {
        temp = s[i];
        int j = i - 1;
        // strcmp() is a built-in library function and is declared in <string.h> header file. This function takes two strings as arguments and compare these two strings lexicographically.
        while (strcmp(s[j].name, temp.name) > 0 && j >= 0)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

// 3. Arrange list of students to find out first ten toppers from a class. (Use Quick sort) according to SGPA

void student::QuickSort(student s[num], int first, int last)
{
    int pivot, i, j;
    student temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (s[i].SGPA >= s[pivot].SGPA && i < last)
                i++;
            while (s[j].SGPA < s[pivot].SGPA)
                j--;
            if (i < j)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
        temp = s[pivot];
        s[pivot] = s[j];
        s[j] = temp;
        QuickSort(s, first, j - 1);
        QuickSort(s, j + 1, last);
    }
}
// 4. Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.
void student::search(student s[], int size)
{
    float SGPA;
    cout << "Enter SGPA:-  ";
    cin >> SGPA;
    cout << "Roll Number\t"
         << "Name\t"
         << "SGPA\n";
    for (int i = 0; i < size; i++)
    {
        if (SGPA == s[i].SGPA)
        {
            cout << s[i].roll_no << "\t      " << s[i].name << "\t" << s[i].SGPA << "\n";
        }
    }
}
// 5.Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed) (Note: Implement either Bubble sort or Insertion Sort.)
int student::binary_search(student s[], int low, int high)
{
    int mid;
    char x[20];
    cout << "Enter name :- ";
    cin >> x;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(x, s[mid].name) == 0)
        {
            return mid;
        }
        else if (strcmp(x, s[mid].name) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int size;

    cout << "Enter number of student \n";
    cin >> size;
    student list[size];
    student obj;
    obj.accept_student_data(list, size);
    int choice;
    do
    {

        cout << "1.arrange list of students according to roll numbers in ascending order \n";
        cout << "2.Arrange list of students alphabetically\n";
        cout << "3.Find out first ten toppers from a class\n";
        cout << "4.Search students according to SGPA\n";
        cout << "5.Search a particular student according to name\n";
        cout << "6.Exit\n";
        cout << "choose your option :-  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.bubble_sort(list, size);
            obj.Display(list, size);
            break;
        case 2:
            obj.insertion_sort(list, size);
            obj.Display(list, size);
            break;
        case 3:
            obj.insertion_sort(list, size); // sort name
            obj.QuickSort(list, 0, num - 1);
            obj.Display(list, num);
            break;
        case 4:
            obj.search(list, size);
            break;
        case 5:
            obj.insertion_sort(list, size);
            int result = obj.binary_search(list, 0, (size - 1));
            if (result == -1)
            {
                cout << " \n Student name not present in our record \n";
            }
            else
            {
                cout << " \n The student  is present :\n" << "Name:-  "<<list[result].name<<"\nSGPA :-  "<<list[result].SGPA<<"\nRoll number :-  "<<list[result].roll_no<<"\n";
            }
            break;
            break;
        }
    } while (choice != 6);

    return 0;
}

// test name 15 34 Balram 8.65 56 Mukesh 9.56 12 Chandan 7.89 23 Akash 9.67 65 Ravindra 8.67 45 Jitendra 9.78 4 Vijay 9.75 30 Pankaj 8.67 7 Pujan 8.67 5 Alok 9.56 11 Manoj 9.76 97 Rakesh 9.99 49 Laukesh 7.56 20 Vikash 8.68 15 Mohan 9.45

/*
Output :-

Enter number of student 
15 34 Balram 8.65 56 Mukesh 9.56 12 Chandan 7.89 23 Akash 9.67 65 Ravindra 8.67 45 Jitendra 9.78 4 Vijay 9.75 30 Pankaj 8.67 7 Pujan 8.67 5 Alok 9.56 11 Manoj 9.76 97 Rakesh 9.99 49 Laukesh 7.56 20 Vikash 8.68 15 Mohan 9.45
Enter your roll number 
Enter your name 
Enter your SGPA 
Enter your roll number 
Enter your name 
Enter your SGPA 
Enter your roll number 
Enter your name 
Enter your SGPA 
Enter your roll number 
Enter your name 
Enter your SGPA 
Enter your roll number 
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA 
Enter your roll number
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA
Enter your roll number
Enter your name
Enter your SGPA
1.arrange list of students according to roll numbers in ascending order
2.Arrange list of students alphabetically
3.Find out first ten toppers from a class
4.Search students according to SGPA
5.Search a particular student according to name
6.Exit
choose your option :-  1
roll number     Name    SGPA
4              Vijay    9.75
5              Alok     9.56
7              Pujan    8.67
11             Manoj    9.76
12             Chandan  7.89
15             Mohan    9.45
20             Vikash   8.68
23             Akash    9.67
30             Pankaj   8.67
34             Balram   8.65
45             Jitendra 9.78
49             Laukesh  7.56
56             Mukesh   9.56
65             Ravindra 8.67
97             Rakesh   9.99
1.arrange list of students according to roll numbers in ascending order
2.Arrange list of students alphabetically
3.Find out first ten toppers from a class
4.Search students according to SGPA
5.Search a particular student according to name
6.Exit
choose your option :-  2
roll number     Name    SGPA
23             Akash    9.67
5              Alok     9.56
34             Balram   8.65
12             Chandan  7.89
45             Jitendra 9.78
49             Laukesh  7.56
11             Manoj    9.76
15             Mohan    9.45
56             Mukesh   9.56
30             Pankaj   8.67
7              Pujan    8.67
97             Rakesh   9.99
65             Ravindra 8.67
4              Vijay    9.75
20             Vikash   8.68
1.arrange list of students according to roll numbers in ascending order
2.Arrange list of students alphabetically
3.Find out first ten toppers from a class
4.Search students according to SGPA
5.Search a particular student according to name
6.Exit
choose your option :-  3
roll number     Name    SGPA
97             Rakesh   9.99
45             Jitendra 9.78
11             Manoj    9.76
4              Vijay    9.75
23             Akash    9.67
5              Alok     9.56
56             Mukesh   9.56
15             Mohan    9.45
20             Vikash   8.68
7              Pujan    8.67
65             Ravindra 8.67
30             Pankaj   8.67
34             Balram   8.65
12             Chandan  7.89
49             Laukesh  7.56
1.arrange list of students according to roll numbers in ascending order
2.Arrange list of students alphabetically
3.Find out first ten toppers from a class
4.Search students according to SGPA
5.Search a particular student according to name
6.Exit
choose your option :-  4
Enter SGPA:-  8.67
Roll Number     Name    SGPA
7             Pujan     8.67
65            Ravindra  8.67
30            Pankaj    8.67
1.arrange list of students according to roll numbers in ascending order
2.Arrange list of students alphabetically
3.Find out first ten toppers from a class
4.Search students according to SGPA
5.Search a particular student according to name
6.Exit
choose your option :-  5
Enter name :- Pujan

The student  is present :
Name:-  Pujan
SGPA :-  8.67
Roll number :-  7
1.arrange list of students according to roll numbers in ascending order
2.Arrange list of students alphabetically
3.Find out first ten toppers from a class
4.Search students according to SGPA
5.Search a particular student according to name
6.Exit
choose your option :-  6
PS C:\Users\Dharmendra Kumar\C Plus Plus\DSA Lab SIB21 Dharmendra Pandit\Searching and Sorting Lab 1> 
*/