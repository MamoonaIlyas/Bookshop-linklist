#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm> // Include the algorithm header for all_of

using namespace std;

struct Bookshop
{
    int id;
    float price;
    string name, a_name, p_name;
    Bookshop* next;
};

// Heading Function
void Heading()
{
    cout << "------------------------\n";
    cout << " ***** WELCOME TO OUR BOOKSHOP *****";
    cout << "\n------------------------\n";
}

// Insert New Book
void Insert(Bookshop*& head)
{
    ofstream f("E:\\bookshop_file.txt", ios::out | ios::app);
    if (f.is_open())
    {
        Heading();
        Bookshop* newBook = new Bookshop;
        cout << "\nEnter Book ID:";
        while (!(cin >> newBook->id))
        {
            cout << "Invalid input. Please enter a valid integer for Book ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore();
        cout << "\nEnter Book Name:";
        getline(cin, newBook->name);
        cout << "\nEnter Author Name:";
        getline(cin, newBook->a_name);
        cout << "\nEnter Publisher Name:";
        getline(cin, newBook->p_name);
        cout << "\nEnter Book Price:";
        while (!(cin >> newBook->price))
        {
            cout << "Invalid input. Please enter a valid float for Book Price: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        newBook->next = head;
        head = newBook;

        f << newBook->id << "\t" << newBook->name << "\t" << newBook->a_name << "\t" << newBook->p_name << "\t" << newBook->price << "\n";
        cout << "Insert New Book Successfully " << endl;
        f.close();
    }
    else
    {
        cout << "Error opening the file for writing" << endl;
    }
}

// Search Book
void Search(Bookshop* head)
{
    system("cls");
    Heading();
    if (!head)
        cout << "Structure Is Empty " << endl;
    else
    {
        string input;
        cout << "\nEnter Book ID or Name For Search:";
        cin.ignore();
        getline(cin, input);

        int found = 0;
        Bookshop* current = head;

        if (all_of(input.begin(), input.end(), ::isdigit))
        {
            int t_id = stoi(input);
            while (current != nullptr)
            {
                if (t_id == current->id)
                {
                    cout << "\nBook Name:" << current->name;
                    cout << "\nAuthor Name:" << current->a_name;
                    cout << "\nPublish Name:" << current->p_name;
                    cout << "\nBook Price:" << current->price;
                    found++;
                    break;
                }
                current = current->next;
            }
        }
        else
        {
            while (current != nullptr)
            {
                if (input == current->name)
                {
                    cout << "\nBook ID:" << current->id;
                    cout << "\nAuthor Name:" << current->a_name;
                    cout << "\nPublish Name:" << current->p_name;
                    cout << "\nBook Price:" << current->price;
                    found++;
                    break;
                }
                current = current->next;
            }
        }

        if (found == 0)
            cout << "Book Is Not Found " << endl;
    }
}

// Update Book
void Update(Bookshop* head)
{
    system("cls");
    Heading();
    if (!head)
        cout << "Structure Is Empty " << endl;
    else
    {
        int t_id, found = 0;
        cout << "Enter Book ID For Update:";
        while (!(cin >> t_id))
        {
            cout << "Invalid input. Please enter a valid integer for Book ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Bookshop* current = head;
        while (current != nullptr)
        {
            if (t_id == current->id)
            {
                cout << "\n\n Enter Book Name -> ";
                cin.ignore();
                getline(cin, current->name);
                cout << "\n\n Enter Author Name -> ";
                getline(cin, current->a_name);
                cout << "\n\n Enter Publisher Name -> ";
                getline(cin, current->p_name);
                cout << "\n\n Enter Book Price -> ";
                while (!(cin >> current->price))
                {
                    cout << "Invalid input. Please enter a valid float for Book Price: ";
                    cin.clear();
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << " Update Book Successfully " << endl;
                found++;
                break;
            }
            current = current->next;
        }

        if (found == 0)
            cout << "Book Is Not Found " << endl;
    }
}

// Delete Book
void Delete(Bookshop*& head)
{
    system("cls");
    Heading();
    if (!head)
        cout << "Structure Is Empty " << endl;
    else
    {
        int t_id, found = 0;
        cout << "Enter Book ID For Delete:";
        while (!(cin >> t_id))
        {
            cout << "Invalid input. Please enter a valid integer for Book ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (head->id == t_id)
        {
            Bookshop* temp = head;
            head = head->next;
            delete temp;
            cout << "Delete Book Successfully " << endl;
            found++;
        }
        else
        {
            Bookshop* current = head;
            while (current->next != nullptr)
            {
                if (t_id == current->next->id)
                {
                    Bookshop* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    cout << "Delete Book Successfully " << endl;
                    found++;
                    break;
                }
                current = current->next;
            }
        }

        if (found == 0)
            cout << "Book Is Not Found " << endl;
    }
}

// Show All Books
void Show(Bookshop* head)
{
    system("cls");
    Heading();
    if (!head)
        cout << "Structure Is Empty " << endl;
    else
    {
        Bookshop* current = head;
        while (current != nullptr)
        {
            cout << "\nBook ID:" << current->id;
            cout << "\nBook Name:" << current->name;
            cout << "\nAuthor Name:" << current->a_name;
            cout << "\nPublish Name:" << current->p_name;
            cout << "\nBook Price:" << current->price << endl;
            current = current->next;
        }
    }
}

// Main Function
int main()
{
    cout<<endl;
    Bookshop* head = nullptr;
    int choice;
    while (true)
    {
        Heading();
        cout << "\n\n 1. Insert Book";
        cout << "\n\n 2. Search Book";
        cout << "\n\n 3. Update Book";
        cout << "\n\n 4. Delete Book";
        cout << "\n\n 5. Show All Book";
        cout << "\n\n 6. Exit\n";
        cout << " Enter Your Choice ?";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Insert(head);
            break;
        case 2:
            Search(head);
            break;
        case 3:
            Update(head);
            break;
        case 4:
            Delete(head);
            break;
        case 5:
            Show(head);
            break;
        case 6:
            exit(0);
        default:
            cout << " Please Select Correct Option " << endl;
        }

        cout << "\nPress any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }

    return 0;
}
