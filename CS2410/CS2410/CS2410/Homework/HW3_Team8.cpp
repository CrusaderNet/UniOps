//Team-8 (Seth Tourish 50%, Milly Flores 50%, Matthew Miller 0%)
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Struct to hold the data for each player
struct Player
{
    string name;
    string position;
    int touchdowns;
    int catches;
    float passingYards;
    float receivingYards;
};

//Function Prototype
Player *getPlayerInfo(int);

//Main Function
int main()
{
    int size;
    Player *plPtr = nullptr;

    
    cout << "Enter the number of players: ";
    cin >> size;

    //Input Validation to check for negative numbers
    while (size < 0)
    {
        cout << "Please enter a positive number: ";
        cin >> size;
    }

    //Call function to get player information
    plPtr = getPlayerInfo(size);

    //Indexes for mins and maxes
    int maxTDIndex = 0;
    int minTDIndex = 0;
    int maxCatchIndex = 0;
    int minCatchIndex = 0;
    int maxPassIndex = 0;
    int minPassIndex = 0;
    int maxReceiveIndex = 0;
    int minReceiveIndex = 0;

    //For loop to get the indexes for the mins and maxes
    for(int i = 0; i < size; i++)
    {
        //Touchdowns
        if(plPtr[i].touchdowns < plPtr[minTDIndex].touchdowns)
            minTDIndex = i;
        if(plPtr[i].touchdowns > plPtr[maxTDIndex].touchdowns)
            maxTDIndex = i;
        
        //Catches
        if(plPtr[i].catches < plPtr[minCatchIndex].catches)
            minCatchIndex = i;
        if(plPtr[i].catches > plPtr[maxCatchIndex].catches)
            maxCatchIndex = i;

        //Passing Yards
        if(plPtr[i].passingYards < plPtr[minPassIndex].passingYards)
            minPassIndex = i;
        if(plPtr[i].passingYards > plPtr[minPassIndex].passingYards)
            maxPassIndex = i;

        //Receiving Yards
        if(plPtr[i].receivingYards < plPtr[minReceiveIndex].receivingYards)
            minReceiveIndex = i;
        if(plPtr[i].receivingYards > plPtr[minReceiveIndex].receivingYards)
            maxReceiveIndex = i;
    }


    //Output for the Data
    cout << endl << "Number of touchdowns:" << endl << "====================" << endl;
    cout << "\tMaximum is " << plPtr[maxTDIndex].touchdowns << " by player " << plPtr[maxTDIndex].name << endl;
    cout << "\tMinimum is " << plPtr[minTDIndex].touchdowns << " by player " << plPtr[minTDIndex].name << endl;

    cout << endl;

    cout << "Number of catches: " << endl << "====================" << endl;
    cout << "\tMaximum is " << plPtr[maxCatchIndex].catches << " by player " << plPtr[maxCatchIndex].name << endl;
    cout << "\tMinimum is " << plPtr[minCatchIndex].catches << " by player " << plPtr[minCatchIndex].name << endl;

    cout << endl;
    cout << fixed << showpoint << setprecision(2);

    cout << "Number of passing yards: " << endl << "====================" << endl;
    cout << "\tMaximum is " << plPtr[maxPassIndex].passingYards << " by player " << plPtr[maxPassIndex].name << endl;
    cout << "\tMinimum is " << plPtr[minPassIndex].passingYards << " by player " << plPtr[minPassIndex].name << endl;

    cout << endl;
    
    cout << "Number of receiving yards: " << endl << "====================" << endl;
    cout << "\tMaximum is " << plPtr[maxReceiveIndex].receivingYards << " by player " << plPtr[maxReceiveIndex].name << endl;
    cout << "\tMinimum is " << plPtr[minReceiveIndex].receivingYards << " by player " << plPtr[minReceiveIndex].name << endl;


    //Delete dynamically allocated array
    delete [] plPtr;

    //End Program
    return 0;
}


//Function to get player information
Player *getPlayerInfo(int size)
{
    //Create dynamically allocated array
    Player *playerInfoPTR = new Player[size];

    //Take inputs for each player
    for(int i = 0; i < size; i++)
    {
        cout << "------------------------------------------------------" << endl;
        //Take input for player name
        cout << "Enter the name of Player " << i + 1 << ": ";
        cin.ignore();
        getline(cin, playerInfoPTR[i].name);
        
        //Take input for player position
        cout << "Enter the position of Player " << i + 1 << ": ";
        cin.ignore();
        getline(cin, playerInfoPTR[i].position);

        //Take input for player touchdowns
        cout << "Enter the number of touchdowns for player " << i + 1 << ": ";
        cin >> playerInfoPTR[i].touchdowns;
        //Input validation for player touchdowns
        while(playerInfoPTR[i].touchdowns < 0)
        {
            cout << "Please enter a positive number: ";
            cin >> playerInfoPTR[i].touchdowns;
        }

        //Take input for player catches
        cout << "Enter the number of catches for player " << i + 1 << ": ";
        cin >> playerInfoPTR[i].catches;
        //Input validation for player catches
        while(playerInfoPTR[i].catches < 0)
        {
            cout << "Please enter a positive number: ";
            cin >> playerInfoPTR[i].catches;
        }

        //Take input for player passing yards
        cout << "Enter the number of passing yards for player " << i + 1 << ": ";
        cin >> playerInfoPTR[i].passingYards;
        //Input validation for player passing yards
        while(playerInfoPTR[i].passingYards < 0.0)
        {
            cout << "Please enter a positive number: ";
            cin >> playerInfoPTR[i].passingYards;
        }
        
        //Take input for player recieving yards
        cout << "Enter the number of recieving yards for player " << i + 1 << ": ";
        cin >> playerInfoPTR[i].receivingYards;
        //Input validation for player receiving yards
        while(playerInfoPTR[i].receivingYards < 0.0)
        {
            cout << "Please enter a positive number: ";
            cin >> playerInfoPTR[i].receivingYards;
        }

    }
    cout << "------------------------------------------------------" << endl;

    //Return pointer to player information array
    return playerInfoPTR;
}