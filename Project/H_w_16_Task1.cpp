#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cout << "\tLibraly" << endl;
    int size_masiv = 0;
    int name_book = 0;
    int close_mas;
    bool perevirka = false;
    int num_of = 0;
    cout << "Enter the size of the array: ";
    cin >> size_masiv;
    cout << endl;
    int* arr = new int[size_masiv];
    while (true)
    {
        for (int i = 0; i < size_masiv; i++)
        {
            if (num_of <= size_masiv)
            {
                cout << "Enter the name you book: ";
                cin >> name_book;
                perevirka = false;
                for (int j = 0; j < size_masiv; j++)
                {
                    if (arr[j] == name_book)
                    {
                        cout << "This name already exists " << endl;
                        perevirka = true;
                    }
                }
                if (!perevirka)
                {
                    arr[num_of] = name_book;
                    num_of++;
                    cout << "add new book" << endl;
                }
            }
        }
        cout << endl;
        for (int i = 0; i < size_masiv; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl << endl << endl;
        break;
    }

    int menu1 = 15;
    while (menu1 != 0)
    {
        cout << "Bouble sort - Press 1" << endl;
        cout << "Selection sort - Press 2" << endl;
        cout << "Insert sort - Press 3" << endl;
        cout << "Shell Sort - Press 4" << endl;
        cout << "Shuffle the books randomly - Press 5" << endl;
        cout << "Line search - Press 6" << endl;
        cout << "Binary search - Press 7" << endl;
        cout << "Insert the element in the given place - Press 8" << endl;
        cout << "To exit - Press 0" << endl;
        cout << endl;
        cin >> menu1;
        cout << endl;
        if (menu1 == 1)//Bouble sort
        {
            int temp;
            cout << "From max do min: ";
            for (int i = 0; i < size_masiv; i++)
            {
                for (int j = 0; j < size_masiv - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            cout << endl;
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "From min to max: ";
            for (int i = 0; i < size_masiv; i++)
            {
                for (int j = 0; j < size_masiv - 1; j++)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            cout << endl;
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        if (menu1 == 2)//Selection sort
        {
            int temp;
            int index;
            int min_index;
            int check;
            cout << endl;
            cout << "From max do min: ";
            for (int i = 0; i < size_masiv - 1; i++)
            {
                check = 0;
                min_index = arr[i];
                for (int j = 1; j < size_masiv; j++)
                {
                    if (min_index < arr[j])
                    {
                        min_index = arr[j];
                        check++;
                        index = j;
                    }
                }
                if (check != 0)
                {
                    temp = arr[i];
                    arr[i] = min_index;
                    arr[index] = temp;
                }
            }
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "From min to max: ";
            for (int i = 0; i < size_masiv - 1; i++)
            {
                check = 0;
                min_index = arr[i];
                for (int j = i + 1; j < size_masiv; j++)
                {
                    if (min_index > arr[j])
                    {
                        min_index = arr[j];
                        check++;
                        index = j;
                    }
                }
                if (check != 0)
                {
                    temp = arr[i];
                    arr[i] = min_index;
                    arr[index] = temp;
                }
            }
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        if (menu1 == 3)//insertion sort
        {
            int temp;
            cout << "From max do min: ";
            for (int i = 1; i < size_masiv; i++)
            {
                temp = arr[i];
                for (int j = i - 1; j >= 0 && arr[j] < temp; j--)
                {
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
            cout << endl;
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "From min to max: ";
            for (int i = 1; i < size_masiv; i++)
            {
                temp = arr[i];
                for (int j = i - 1; j >= 0 && arr[j] > temp; j--)
                {
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
            cout << endl;
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        if (menu1 == 4)//Shell sort
        {
            int n = size_masiv;
            for (int interval = n / 2; interval > 0; interval /= 2)
            {
                for (int i = interval; i < n; i += 1)
                {
                    int temp = arr[i];
                    int j;
                    for (j = i; j >= interval && arr[j - interval] > temp; j -= interval)
                    {
                        arr[j] = arr[j - interval];
                    }
                    arr[j] = temp;
                }
            }
            cout << endl;
            cout << "From min to max: ";
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            for (int interval = n / 2; interval > 0; interval /= 2)
            {
                for (int i = interval; i < n; i += 1)
                {
                    int temp = arr[i];
                    int j;
                    for (j = i; j >= interval && arr[j - interval] < temp; j -= interval)
                    {
                        arr[j] = arr[j - interval];
                    }
                    arr[j] = temp;
                }
            }
            cout << endl;
            cout << "From max to min: ";
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        if (menu1 == 5)//random shuffle
        {   
            cout << endl;
            cout << "Standart array: ";
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            int* arr_time = new int[size_masiv];
            for (int i = 0; i < size_masiv; i++)
            {
                random_shuffle(&arr[0], &arr[size_masiv]);
            }
            cout << endl << "Random array: ";
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        if (menu1 == 6)//line search
        {
            int search;
            cout << endl << "Enter the search book: ";
            cin >> search;
            cout << endl;
            for (int i = 0; i < size_masiv; i++)
            {
                if (arr[i] == search)
                {
                    cout << "The element " << search << " is in " << i << " place." << endl;
                }
                else
                {
                    cout << "This element not in the array." << endl;
                    break;
                }
            }
            break;
        }
        if (menu1 == 7)//binary search
        {
            int low = 0, hight = size_masiv - 1, postiton = 0, x;
            cout << endl << "Enter the search book: ";
            cin >> x;
            cout << endl;
            while (hight > low)
            {
                int mid = low + (hight - low) / 2;
                if (arr[mid] < x)
                {
                    low = mid + 1;
                }
                else
                {
                    hight = mid;
                }
            }
            if (arr[low] == x)
            {
                cout << "\n\tThe book " << x << " in position " << low << endl;
            }
            else if (arr[hight] == x)
            {
                cout << "\n\tThe book " << x << " in position " << hight << endl;
            }
            else
            {
                cout << "\n\tThe book " << x << " not found" << endl;
            }
            cout << endl;
            break;
        }
        if (menu1 == 8)//inserting the book at any position
        {
            int pos;
            cout << "Press name book: " << endl;
            cin >> name_book;
            cout << "Press position from 0 " << "to " << size_masiv - 1 << endl << endl;
            cin >> pos;
            
            for (int i = 0; i < size_masiv; i++)
            {
                for (int j = i + 1; j < size_masiv; j++)
                {
                    arr[j + 1] = arr[j];
                }
                arr[i + 1] = name_book;
                i++;
            }
            for (int i = 0; i < size_masiv; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        if (menu1 == 0)//exit
        {
            break;
        }

    }
}
