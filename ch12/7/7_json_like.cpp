#include <string>
#include <vector>

using std::string;

struct Date
{
    int year;
    int month;
    int day;
};

struct Team
{
    string name;
    string where;
};

using vec_teams = std::vector<Team>;

struct GameSession
{
    string    game;
    string    localization;
    vec_teams teams;
    Date      date;
};

int
main()
{
    GameSession test{
        .game         = "Pong",
        .localization = "Pacific Ocean",
        .teams =
            {
                Team{
                    .name  = "Johny Test",
                    .where = "Arctica",
                },
                Team{
                    .name  = "Jane Doe",
                    .where = "Antarctic",
                },
            },
        .date = {.year = 2022, .month = 10, .day = 6},
    };
}
