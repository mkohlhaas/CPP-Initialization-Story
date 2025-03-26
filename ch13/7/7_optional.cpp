#include <iostream>
#include <optional>
#include <string>

class UserName
{
  public:
    explicit UserName() : mName("Default")
    {
        std::cout << "UserName::UserName(\'";
        std::cout << mName << "\')\n";
    }

    explicit UserName(const std::string &str) : mName(str)
    {
        std::cout << "UserName::UserName(\'";
        std::cout << mName << "\')\n";
    }

    ~UserName()
    {
        std::cout << "UserName::~UserName(\'";
        std::cout << mName << "\')\n";
    }

    UserName(const UserName &u) : mName(u.mName)
    {
        std::cout << "UserName::UserName(copy \'";
        std::cout << mName << "\')\n";
    }

    UserName(UserName &&u) : mName(std::move(u.mName))
    {
        std::cout << "UserName::UserName(move \'";
        std::cout << mName << "\')\n";
    }

    UserName &
    operator=(const UserName &u) // copy assignment
    {
        mName = u.mName;

        std::cout << "UserName::=(copy \'";
        std::cout << mName << "\')\n";

        return *this;
    }

    UserName &
    operator=(UserName &&u) // move assignment
    {
        mName = std::move(u.mName);

        std::cout << "UserName::=(move \'";
        std::cout << mName << "\')\n";

        return *this;
    }

  private:
    std::string mName;
};

int
main()
{
    // std::optional<UserName> opt(UserName{});
    std::optional<UserName> opt{std::in_place};
}

// without in_place:
// UserName::UserName('Default')
// UserName::UserName(move 'Default')
// UserName::~UserName('')
// UserName::~UserName('Default')

// with in_place:
// UserName::UserName('Default')
// UserName::~UserName('Default')
