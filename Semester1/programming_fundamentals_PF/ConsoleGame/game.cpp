#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Player
{
    string name = "Player";
    int choice;
    int rounds_played = 0; // use for leaderboard
    int wins = 0;          // Default value
    int draws = 0;         // Default value
    int loss = 0;          // Default value
};

// CONSTANTS
const int MAX_ENTRIES = 3;
const string FILE_NAME = "leaderboard.txt";
const string retry_message = "\nInvalid Choice, Try Again\n";
const string CHOICES[3] = {"Rock", "Paper", "Scissor"};

bool quit_confirm()
{
    string user_input = "";
    cout << "Are you sure to quite? (y for yes): ";
    cin >> user_input;

    if (user_input == "y")
    {
        return true;
    }

    return false;
}

string repeat_str(string str, int times)
{
    string s = "";
    for (int i = 0; i < times; i++)
    {
        s.append(str);
    }
    return s;
}

string get_number_spacing(int num)
{
    return (num < 10) ? " " : "";
}

// Use this for custom round number from user
int get_custom_round_number()
{
    int round_num;
    do
    {
        cout << "\nEnter Round Number: ";
        cin >> round_num;

        if (round_num <= 0)
        {
            cout << "Round Number must be greater than zero.\n";
            cout << "Try Again\n";
        }
    } while (round_num <= 0);

    return round_num;
}

int get_round_number()
{
    int round_number, round_type;
    do
    {
        cout << "\nEnter Round Type:\n";
        cout << "1. Endless\n";
        cout << "2. Custom Rounds\n";
        cout << "Enter here: ";
        cin >> round_type;

        if (round_type == 1)
        {
            round_number = 999999; // finite number, delusion of infinity
        }
        else if (round_type == 2)
        {
            round_number = get_custom_round_number();
        }
        else
        {
            cout << retry_message;
        }
    } while (round_type != 1 && round_type != 2);

    return round_number;
}

int get_computer_choice()
{
    // Generate 1,2, or 3
    int computer_choice = (rand() % 3) + 1;

    return computer_choice;
}

int game_logic(Player *player, int computer_choice)
{
    // Draw
    if (player->choice == computer_choice)
    {
        return 0;
    }

    if ((player->choice == 1 && computer_choice == 3) || // Rock beats Scissor
        (player->choice == 2 && computer_choice == 1) || // Paper beats Rock
        (player->choice == 3 && computer_choice == 2))   // Scissor beats Paper
    {
        return 1; // Player wins
    }

    // Computer Wins
    return -1;
}

void manage_score(Player *player, int result)
{
    if (result == 0)
    {
        cout << "\n[>>>|||   o-o DRAW! o-o    |||<<<]\n";
        player->draws += 1;
    }
    else if (result == 1)
    {
        cout << "\n[>>>+++    ^-^ WIN! ^-^    +++<<<]\n";
        player->wins += 1;
    }
    else
    {
        cout << "\n[>>>---   v-v lOSS! v-v   ---<<<]\n";
        player->loss += 1;
    }
}

int manage_round(Player *player, int current_round_number)
{
    cout << "\nROUND NUMBER: " << current_round_number << endl;
    do
    {
        cout << "\nEnter Choice:\n";
        cout << "1. " << CHOICES[0] << "\n";
        cout << "2. " << CHOICES[1] << "\n";
        cout << "3. " << CHOICES[2] << "\n";
        cout << "4. Go To Main Menu\n";
        cout << "Enter here: ";
        cin >> player->choice;

        // User choosed valid game choice
        if (player->choice == 1 || player->choice == 2 || player->choice == 3)
        {
            int computer_choice = get_computer_choice();

            // Show Choices
            // example: HackerChanna(Rock) VS Computer(Scissor)
            cout << endl;
            cout << "~~~   ";
            cout << player->name << "(" << CHOICES[player->choice - 1] << ")";
            cout << " VS ";
            cout << "Computer(" << CHOICES[computer_choice - 1] << ")";
            cout << "   ~~~";
            cout << endl;

            // No need to add "&" as it is already as pointer here
            int result = game_logic(player, computer_choice);

            // Increase played round count
            player->rounds_played += 1;

            manage_score(player, result);

            return 0;
        }
        else if (player->choice == 4)
        {
            bool confirm = quit_confirm();
            if (confirm)
            {
                cout << "\nReturning...";
                return 1; // Response to return to Main Menu
            }
        }
        else
        {
            cout << retry_message;
        }

    } while (player->choice != 4);

    return 0; // Keep Continue Rounds
}

void summary(Player *player)
{
    cout << "\n||||||||||||||||||||||||||||||"; // 30 |
    cout << "\n|||  Summary Of the Game!  |||";
    cout << "\ni|i " << player->name << repeat_str(" ", 23 - player->name.length()) << "|||";
    cout << "\n(|)>-> WINS: " << player->wins << get_number_spacing(player->wins) << "            |||";
    cout << "\n~~~+(|)>-> DRAWS: " << player->draws << get_number_spacing(player->draws) << "       |||";
    cout << "\n~~~~~~~+(|)>-> LOSSES: " << player->loss << get_number_spacing(player->loss) << "  |||";
    cout << "\n||||||||||||||||||||||||||||||\n";
}

void play(Player *player)
{
    // Resets Player Stats
    player->rounds_played = 0;
    player->wins = 0;
    player->draws = 0;
    player->loss = 0;

    int round_number = get_round_number();

    cout << "\nEnter Your Name: ";
    cin >> player->name;

    for (int current_round_number = 1; current_round_number <= round_number; current_round_number++)
    {
        int round_response = manage_round(player, current_round_number);

        // User wants to go to Main Menu
        if (round_response == 1)
        {
            cout << "\nGoing to Main Menu...\n";
            break;
        }
    }
}

// ##########################################################################################################

string make_player_row(Player *player)
{
    string row = "";
    // name,rounds_played,wins,draws,loss,
    // a additional comma at the end too

    row.append(player->name);
    row.append(",");
    // to_string func -> int to str
    row.append(to_string(player->rounds_played));
    row.append(",");
    row.append(to_string(player->wins));
    row.append(",");
    row.append(to_string(player->draws));
    row.append(",");
    row.append(to_string(player->loss));
    row.append(",");

    return row;
}

Player extract_player_from_row(string row)
{
    Player player;

    char delimeter = ',';
    string word = "";
    int delimiter_count = 0;

    for (int i = 0; i < row.length(); i++)
    {
        // Found delimeter
        if (row[i] == delimeter)
        {
            // expects
            // name,rounds_played,wins,draws,loss,
            // a additional comma at the end too
            switch (delimiter_count)
            {
            // 0 for name
            case 0:
                player.name = word;
                delimiter_count += 1;
                //  reset word
                word = "";
                break;
            // 1 for rounds_played
            case 1:
                player.rounds_played = stoi(word, 0, 10);
                delimiter_count += 1;
                //  reset word
                word = "";
                break;
            // 2 for wins
            case 2:
                player.wins = stoi(word, 0, 10);
                delimiter_count += 1;
                //  reset word
                word = "";
                break;
            // 3 for draw
            case 3:
                player.draws = stoi(word, 0, 10);
                delimiter_count += 1;
                //  reset word
                word = "";
                break;
            // 4 for wins
            case 4:
                player.loss = stoi(word, 0, 10);
                delimiter_count += 1;
                //  reset word
                word = "";
                break;
            }
            continue;
        }
        word.append(string(1, row[i]));
    }
    return player;
}

void sort_leaderboard(Player leaderboard[], int size)
{
    // Bubble Sort
    bool swapped;

    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (leaderboard[j].wins < leaderboard[j + 1].wins)
            {
                swap(leaderboard[j], leaderboard[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

void load_leaderboard(Player leaderboard[])
{
    ifstream file(FILE_NAME);

    string row;
    int i = 0;
    while (i < MAX_ENTRIES && getline(file, row)) // reads seperated by new line
    {
        leaderboard[i] = extract_player_from_row(row);
        i++;
    }
}

void write_leaderboard(Player leaderboard[])
{
    ofstream file(FILE_NAME);

    for (int l = 0; l < MAX_ENTRIES; l++)
    {
        string row = make_player_row(&leaderboard[l]);
        file << row << endl;
    }
}

// ----------- FORMATTING (nobody knows what happends here)

void draw_leaderboard_table(Player leaderboard[])
{
    int max_name_lenght = 8;
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        int name_lenght = leaderboard[i].name.length();
        if (name_lenght > max_name_lenght)
        {
            max_name_lenght = name_lenght;
        }
    }

    // ++M+++NN+++NN+++NN+++NN
    int max_width = max_name_lenght + 23 + 5;

    string line = repeat_str("-", max_width + 1);
    string title = "LEADERBOARD";

    cout << endl
         << line << endl;
    cout << "| " << title << repeat_str(" ", max_width - 2 - title.length()) << "|";
    cout << endl
         << line << endl;
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        Player p = leaderboard[i];
        cout << "| " << i + 1 << get_number_spacing(i + 1) << " | " << (p.name) << repeat_str(" ", max_name_lenght - p.name.length()) << " | ";
        cout << p.rounds_played << get_number_spacing(p.rounds_played) << " | ";
        cout << p.wins << get_number_spacing(p.wins) << " | ";
        cout << p.draws << get_number_spacing(p.draws) << " | ";
        cout << p.loss << get_number_spacing(p.loss) << " |";
        cout << endl;
    }
    cout << line << endl;
    return;
}

// ##########################################################################################################

int main()
{
    cout << "<><><><><><><><><><><><><><><><><>\n";
    cout << "<><><>   ROCK PAPER SCISSOR   <><>\n";
    cout << "<><><><><><><><><><><><><><><><><>\n"; // 34

    // Seed to generate new random sequence each time
    srand(static_cast<unsigned int>(time(0)));

    // Leaderboard
    Player leaderboard[MAX_ENTRIES + 1];
    load_leaderboard(leaderboard);

    // Sort leaderboard - incase file has unsorted leaderboard
    sort_leaderboard(leaderboard, MAX_ENTRIES);

    // Player
    Player player;

    // Main Menu
    int input_choice;

    do
    {
        cout << "\n|||  Main Menu  |||";
        cout << "\nEnter your choice: ";
        cout << "\n1. Play";
        cout << "\n2. Show LeaderBoard";
        cout << "\n3. Quit\n";
        cout << "Enter here: ";
        cin >> input_choice;

        if (input_choice == 1)
        {
            // Play Function
            play(&player);

            // Show Results/Summary
            summary(&player);

            // Add Player to the buffer
            leaderboard[MAX_ENTRIES] = player;

            // Sort the leaderboard again for new entry (+1)
            sort_leaderboard(leaderboard, MAX_ENTRIES + 1);

            // Update Leaderboard File
            write_leaderboard(leaderboard);
        }
        else if (input_choice == 2)
        {
            // Show LeaderBoard
            draw_leaderboard_table(leaderboard);
        }
        else if (input_choice == 3)
        {
            bool confirm = quit_confirm();

            if (confirm == true)
            {
                cout << "\nThank You for Playing :)";
                break;
            }

            input_choice = 0;
        }
        else
        {
            cout << retry_message;
        }
    } while (input_choice != 3);
}
