/* WELCOME TO OUR SYSTEM FOR MANAGING SALARIES FOR A FOOTBALL TEAM */
/* BY  (OMAR LASHIN) , (AHMED TONY) , (ABDELAZIZ ASHRAF) , (AHMED ASHRAF)  */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct club
{
    int id;
    string name;
    int age;
    string phoneNumber;
    float salary;

}; // struct that contains all based variables for each object

const int ArrayMaxSize = 100; // declare maximum size of the array

class clubstack
{
    int top;                       // declares top of the stack
    struct club arr[ArrayMaxSize]; // declares array of structs

public:
    clubstack() { top = -1; } // constructor to initialiaze the top by value -1

public:
public:
    const club &getPersonAtIndex(int index)
    {
        return arr[index];
    } // get values of person at index

    const void displayPaymentInformation(int index)
    {
        if (index < 0 || index > top)
        {
            cout << "Invalid index. Player not found." << endl;
        }
        else
        {
            cout << "Payment of " << arr[index].salary << " made to "
                 << arr[index].name << "." << endl;
        }
    } // display payment information of person at index

    const void updateName(int index, const string &newName)
    {
        if (index < 0 || index > top)
        {
            cout << "Invalid index. person not found." << endl;
        }
        else
        {
            arr[index].name = newName;
            cout << "person name at index " << index << " updated successfully."
                 << endl;
        }
    } // update name of person at index

    const void updateAge(int index, const int &newAge)
    {
        if (index < 0 || index > top)
        {
            cout << "Invalid index. person not found." << endl;
        }
        else
        {
            arr[index].age = newAge;
            cout << "person age at index " << index << " updated successfully."
                 << endl;
        }
    } // update age of person at index 2

    const void updatePhoneNumber(int index, const string &newPhoneNumber)
    {
        if (index < 0 || index > top)
        {
            cout << "Invalid index. person not found." << endl;
        }
        else
        {
            arr[index].phoneNumber = newPhoneNumber;
            cout << "person phone number at index " << index
                 << " updated successfully." << endl;
        }
    } // update phone number of person at index 2

    const void updateSalary(int index, const float &newSalary)
    {
        if (index < 0 || index > top)
        {
            cout << "Invalid index. person not found." << endl;
        }
        else
        {
            arr[index].salary = newSalary;
            cout << "person salary at index " << index << " updated successfully."
                 << endl;
        }
    } // update salary of person at index 2

    const int getTop() { return top; } // get index top of stack2

    const void removeSpecific(int index)
    {
        if (isEmpty())
        {
            cout << "No data in the stack, you cannot delete" << endl;
        }
        else if (index < 0 || index > top)
        {
            cout << "Invalid index. Person not found." << endl;
        }
        else
        {
            for (int i = index; i < top; i++)
            {
                arr[i] = arr[i + 1];
            }
            top--;
            cout << "Person at index " << index << " removed successfully :)\n";
        }
    } // function that removes a specific player from the stack2

    const bool isFull()
    {
        if (top == ArrayMaxSize - 1)
            return true;

        else
            return false;
    } // check if stack is full 2

    bool isEmpty() const
    {
        if (top == -1)
            return true;
        else
            return false;
    } // check if stack is empty2

    const void add(const club &data)
    {
        if (isFull())
        {
            cout << "You cannot insert any other data , because stack is full"
                 << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    } // add a new person to the stack2

    const void remove()
    {
        if (isEmpty())
        {
            cout << "No data in the stack , you cannot delete" << endl;
        }
        else
        {
            top--;
        }
    } // remove the top person from the stack2

    void printStack() const
    {
        if (isEmpty())
        {
            cout << "No data in the stack , you cannot print" << endl;
        }
        else
        {

            cout << "\n---------------------\n";
            for (int i = top; i >= 0; i--)
            {
                club person = arr[i];

                cout << "Person ID: " << person.id << "\n";
                cout << "Person Name: " << person.name << "\n";
                cout << "Person Age: " << person.age << "\n";
                cout << "Person Phone Number: " << person.phoneNumber << "\n";
                cout << "Person Salary: " << person.salary << "\n";
                cout << "---------------------\n";
            }
        }
    } // print the stack 2
};    // stack contains all the data

clubstack players;   // declare stack of players
clubstack coaches;   // declare stack of coaches
clubstack employees; // declare stack of employees

struct club player, coach, employee; // declare objects fom struct club

int id; // declare id variable to use it in functions (add,print)

// Player Funtions
void AddPlayer()
{
    cout << "";
    getline(cin, player.name);

    if (player.name.empty())
    {
        cout << "\nEnter Player Name: ";
        getline(cin, player.name);
    }

    cout << "\nEnter Player Age: ";
    cin >> player.age;

    cout << "";
    getline(cin, player.phoneNumber);

    if (player.phoneNumber.empty())
    {
        cout << "\nEnter Your Phone Number: ";
        getline(cin, player.phoneNumber);
    }

    cout << "\nEnter Player Salary: ";
    cin >> player.salary;

    players.add(player);

    cout << "\nPlayer is added successfully with id :" << player.id << "\n";
    player.id++;
    cout << "Thank you for using our system , Goodbye\n";
} // add a new player to the stack

void RemovePlayer()
{
    int index;
    cout << "Enter the index of the player to remove (0-based): ";
    cin >> index;
    players.removeSpecific(index); // **Use specific removal method**
    cout << "\nPlayer is removed successfully :)\n";
} // remove a player from the stack

void DisplayInformationOfPlayer()
{
    players.printStack();
} // print the stack of players

void EditOnPlayer()
{
    int IdOfPlayersAsIndexInArray;
    // Get the index of the player to edit
    cout << "Enter the index of the player to edit (0-based): ";
    cin >> IdOfPlayersAsIndexInArray;

    // Validate the index
    if (IdOfPlayersAsIndexInArray < 0 ||
        IdOfPlayersAsIndexInArray >= players.getTop() + 1)
    {
        cout << "Invalid index. Player not found." << endl;
        return;
    }

    // Get new information for each field
    string newName;
    cout << "";
    getline(cin, newName);
    if (newName.empty())
    {
        cout << "Enter new name (leave blank to keep current): ";
        getline(cin, newName);
    }

    if (!newName.empty())
    {
        players.updateName(IdOfPlayersAsIndexInArray, newName);
    }

    int newAge;
    cout << "Enter new age (leave blank to keep current): ";
    cin >> newAge;

    if (newAge != 0)
    {
        players.updateAge(IdOfPlayersAsIndexInArray, newAge);
    }

    string newPhoneNumber;
    cout << "";
    getline(cin, newPhoneNumber);
    if (newPhoneNumber.empty())
    {
        cout << "Enter new phone number (leave blank to keep current): ";
        getline(cin, newPhoneNumber);
    }

    if (!newPhoneNumber.empty())
    {
        players.updatePhoneNumber(IdOfPlayersAsIndexInArray, newPhoneNumber);
    }

    float newSalary;
    cout << "Enter new salary (leave blank to keep current): ";
    cin >> newSalary;

    if (newSalary != 0)
    {
        players.updateSalary(IdOfPlayersAsIndexInArray, newSalary);
    }

    cout << "\nPlayer information updated successfully.\n"
         << endl;
} // edit a player's information

void PayToPlayer()
{

    int index;
    // Get the index of the player to pay
    cout << "Enter the index of the player to pay (0-based): ";
    cin >> index;

    // Validate the index
    if (index < 0 || index >= players.getTop() + 1)
    {
        cout << "Invalid index. Player not found." << endl;
        return;
    }

    // Simulate payment (replace with actual payment logic if needed)
    cout << "Payment of " << players.getPersonAtIndex(index).salary << " made to "
         << players.getPersonAtIndex(index).name << "." << endl;
} // pay to a player

// Coach Functions
void AddCoach()
{
    cout << "";
    getline(cin, coach.name);

    if (coach.name.empty())
    {
        cout << "\nEnter Coach Name: ";
        getline(cin, coach.name);
    }

    cout << "\nEnter coach Age: ";
    cin >> coach.age;

    cout << "";
    getline(cin, coach.phoneNumber);

    if (coach.phoneNumber.empty())
    {
        cout << "\nEnter Your Phone Number: ";
        getline(cin, coach.phoneNumber);
    }

    cout << "\nEnter coach Salary: ";
    cin >> coach.salary;

    coaches.add(coach);

    cout << "\ncoach is added successfully with id :" << coach.id << "\n";
    coach.id++;
    cout << "Thank you for using our system , Goodbye\n";
} // add a new coach to the stack

void RemoveCoach()
{
    int index;
    cout << "Enter the index of the coach to remove (0-based): ";
    cin >> index;
    coaches.removeSpecific(index); // **Use specific removal method**
    cout << "\ncoach is removed successfully :)\n";
} // remove a coach from the stack

void DisplayInformationOfCoach()
{
    coaches.printStack();
} // print the stack of coaches

void EditOnCoach()
{
    int IdOfCoachesAsIndexInArray;
    // Get the index of the player to edit
    cout << "Enter the index of the Coach to edit (0-based): ";
    cin >> IdOfCoachesAsIndexInArray;

    // Validate the index
    if (IdOfCoachesAsIndexInArray < 0 ||
        IdOfCoachesAsIndexInArray >= coaches.getTop() + 1)
    {
        cout << "Invalid index. Coach not found." << endl;
        return;
    }

    // Get new information for each field
    string newName;
    cout << "";
    getline(cin, newName);
    if (newName.empty())
    {
        cout << "Enter new name (leave blank to keep current): ";
        getline(cin, newName);
    }

    if (!newName.empty())
    {
        coaches.updateName(IdOfCoachesAsIndexInArray, newName);
    }

    int newAge;
    cout << "Enter new age (leave blank to keep current): ";
    cin >> newAge;

    if (newAge != 0)
    {
        coaches.updateAge(IdOfCoachesAsIndexInArray, newAge);
    }

    string newPhoneNumber;
    cout << "";
    getline(cin, newPhoneNumber);
    if (newPhoneNumber.empty())
    {
        cout << "Enter new phone number (leave blank to keep current): ";
        getline(cin, newPhoneNumber);
    }

    if (!newPhoneNumber.empty())
    {
        coaches.updatePhoneNumber(IdOfCoachesAsIndexInArray, newPhoneNumber);
    }

    float newSalary;
    cout << "Enter new salary (leave blank to keep current): ";
    cin >> newSalary;

    if (newSalary != 0)
    {
        coaches.updateSalary(IdOfCoachesAsIndexInArray, newSalary);
    }

    cout << "\nCoach information updated successfully.\n"
         << endl;
} // edit a coach's information

void PayToCoach()
{
    int index;
    // Get the index of the coach to pay
    cout << "Enter the index of the coach to pay (0-based): ";
    cin >> index;

    // Validate the index
    if (index < 0 || index >= coaches.getTop() + 1)
    {
        cout << "Invalid index. Coach not found." << endl;
        return;
    }

    // Simulate payment (replace with actual payment logic if needed)
    cout << "Payment of " << coaches.getPersonAtIndex(index).salary << " made to "
         << coaches.getPersonAtIndex(index).name << "." << endl;
} // pay to a coach

// Employee Functions
void AddEmployee()
{
    cout << "";
    getline(cin, employee.name);

    if (employee.name.empty())
    {
        cout << "\nEnter Employee Name: ";
        getline(cin, employee.name);
    }

    cout << "\nEnter Employee Age: ";
    cin >> employee.age;

    cout << "";
    getline(cin, employee.phoneNumber);

    if (employee.phoneNumber.empty())
    {
        cout << "\nEnter Employee Phone Number: ";
        getline(cin, employee.phoneNumber);
    }

    cout << "\nEnter Employee Salary: ";
    cin >> employee.salary;

    employees.add(employee);

    cout << "\nEmployee is added successfully with id :" << employee.id << "\n";
    employee.id++;
    cout << "Thank you for using our system , Goodbye\n";
} // add a new employee to the stack

void RemoveEmployee()
{
    int index;
    cout << "Enter the index of the employee to remove (0-based): ";
    cin >> index;
    employees.removeSpecific(index); // **Use specific removal method**
    cout << "\n employee is removed successfully :)\n";
} // remove an employee from the stack

void DisplayInformationOfEmployee()
{
    employees.printStack();
} // print the stack of employees

void EditOnEmployee()
{
    int IdOfEmployeeAsIndexInArray;
    // Get the index of the Employee to edit
    cout << "Enter the index of the Employee to edit (0-based): ";
    cin >> IdOfEmployeeAsIndexInArray;

    // Validate the index
    if (IdOfEmployeeAsIndexInArray < 0 ||
        IdOfEmployeeAsIndexInArray >= employees.getTop() + 1)
    {
        cout << "Invalid index. Employee not found." << endl;
        return;
    }

    // Get new information for each field
    string newName;
    cout << "";
    getline(cin, newName);
    if (newName.empty())
    {
        cout << "Enter new name (leave blank to keep current): ";
        getline(cin, newName);
    }

    if (!newName.empty())
    {
        employees.updateName(IdOfEmployeeAsIndexInArray, newName);
    }

    int newAge;
    cout << "Enter new age (leave blank to keep current): ";
    cin >> newAge;

    if (newAge != 0)
    {
        employees.updateAge(IdOfEmployeeAsIndexInArray, newAge);
    }

    string newPhoneNumber;
    cout << "";
    getline(cin, newPhoneNumber);
    if (newPhoneNumber.empty())
    {
        cout << "Enter new phone number (leave blank to keep current): ";
        getline(cin, newPhoneNumber);
    }

    if (!newPhoneNumber.empty())
    {
        employees.updatePhoneNumber(IdOfEmployeeAsIndexInArray, newPhoneNumber);
    }

    float newSalary;
    cout << "Enter new salary (leave blank to keep current): ";
    cin >> newSalary;

    if (newSalary != 0)
    {
        employees.updateSalary(IdOfEmployeeAsIndexInArray, newSalary);
    }

    cout << "\nEmployee's information updated successfully.\n"
         << endl;
} // edit a Employee's information

void PayToEmployee()
{
    int index;
    // Get the index of the employee to pay
    cout << "Enter the index of the employee to pay (0-based): ";
    cin >> index;

    // Validate the index
    if (index < 0 || index >= employees.getTop() + 1)
    {
        cout << "Invalid index. employee not found." << endl;
        return;
    }

    // Simulate payment (replace with actual payment logic if needed)
    cout << "Payment of " << employees.getPersonAtIndex(index).salary
         << " made to " << employees.getPersonAtIndex(index).name << "." << endl;
} // pay to an employee

int main()
{

    int userChoice1;        // variable for user choice in the main menu
    int userChoicePlayer;   // variable for user choice in the player menu
    int userChoiceCoach;    // variable for user choice in the coach menu
    int userChoiceEmployee; // variable for user choice in the employee menu

    do
    {

        cout << "                     ========================================\n";
        cout << "                     Salaries Football Club Management System\n";
        cout << "                     ========================================\n\n";
        cout << "                     ========= Welcome to the club ==========\n\n";

        cout << "               ========= Please choose one of the options "
                "==========\n\n";
        cout << " 1- Players\n";
        cout << " 2- Coaches\n";
        cout << " 3- Employees\n";
        cout << " 4- Exit\n\n";
        cout << " Enter Your choice : ";

        cin >> userChoice1; // user input for the main menu

        if (userChoice1 == 1)
        {
            cout << "               ========= Please choose one of the options "
                    "==========\n\n";

            cout << " 1- Add a player\n";
            cout << " 2- Remove a player\n";
            cout << " 3- Display Information of a player\n";
            cout << " 4- Edit on a Player Information\n";
            cout << " 5- Pay to a Player\n";
            cout << " 6- Exit\n\n";
            cout << "Enter a number to choose an operation: ";
            cin >> userChoicePlayer;

            switch (userChoicePlayer)
            {
            case 1:
                AddPlayer();
                break;
            case 2:
                RemovePlayer();
                break;
            case 3:
                DisplayInformationOfPlayer();
                break;
            case 4:
                EditOnPlayer();
                break;
            case 5:
                PayToPlayer();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
                break;
            } // switch for the player menu that have functions of players to call

        } // if user choose 1

        else if (userChoice1 == 2)
        {
            cout << "               ========= Please choose one of the options "
                    "==========\n\n";

            cout << " 1- Add a coach\n";
            cout << " 2- Remove a coach\n";
            cout << " 3- Display Information of a coach\n";
            cout << " 4- Edit on a coach Information\n";
            cout << " 5- Pay to a coach\n\n";
            cout << "Enter a number to choose an operation: ";
            cin >> userChoiceCoach;

            switch (userChoiceCoach)
            {
            case 1:
                AddCoach();
                break;
            case 2:
                RemoveCoach();
                break;
            case 3:
                DisplayInformationOfCoach();
                break;
            case 4:
                EditOnCoach();
                break;
            case 5:
                PayToCoach();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
                break;
            } // switch for the coach menu that have functions of coaches to call
        }     // if user choose 2

        else if (userChoice1 == 3)
        {
            cout << "               ========= Please choose one of the options "
                    "==========\n\n";

            cout << " 1- Add an employee\n";
            cout << " 2- Remove an employee\n";
            cout << " 3- Display Information of an employee\n";
            cout << " 4- Edit on an employee Information\n";
            cout << " 5- Pay to an employee\n\n";
            cout << "Enter a number to choose an operation: ";
            cin >> userChoiceEmployee;

            switch (userChoiceEmployee)
            {
            case 1:
                AddEmployee();
                break;
            case 2:
                RemoveEmployee();
                break;
            case 3:
                DisplayInformationOfEmployee();
                break;
            case 4:
                EditOnEmployee();
                break;
            case 5:
                PayToEmployee();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
                break;
            } // switch for the employee menu that have functions of employees to call
        }     // if user choose 3

        else if (userChoice1 == 4)
        {
            cout << "Exiting...\n";
            cout << "Thank you for using our system , Goodbye";
        } // if user choose 4

        else
        {
            cout << "Invalid choice , please try again\n";
        } // if user choose any thing that is not in the menu

    } while (userChoice1 != 4);
    // loop will continue until user chooses to exit
}