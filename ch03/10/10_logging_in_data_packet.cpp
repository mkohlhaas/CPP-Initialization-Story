#include <numeric>
#include <print>

size_t
calcCheckSum(const std::string &s)
{
    return std::accumulate(s.begin(), s.end(), 0ul);
}

class DataPacket
{
    std::string data_;
    size_t      checkSum_;
    size_t      serverId_;

  public:
    DataPacket() : data_{}, checkSum_{0}, serverId_{0}
    {
    }

    DataPacket(const std::string &data, size_t serverId)
        : data_{data}, checkSum_{calcCheckSum(data)}, serverId_{serverId}
    {
        std::println("Ctor for \"{}\"", data_);
    }

    DataPacket(const DataPacket &other) : data_{other.data_}, checkSum_{other.checkSum_}, serverId_{other.serverId_}
    {
        std::println("Copy ctor for \"{}\"", data_);
    }

    DataPacket(DataPacket &&other)
        : data_{std::move(other.data_)}, // move string member...
          checkSum_{other.checkSum_},    // no need to move built-in types...
          serverId_{other.serverId_}
    {
        other.checkSum_ = 0;             // leave this in a proper state
        std::println("Move ctor for \"{}\"", data_);
    }

    DataPacket &
    operator=(const DataPacket &other)
    {
        if (this != &other)
        {
            data_     = other.data_;
            checkSum_ = other.checkSum_;
            serverId_ = other.serverId_;
            std::println("Assignment for \"{}\"", data_);
        }
        return *this;
    }

    DataPacket &
    operator=(DataPacket &&other)
    {
        if (this != &other)
        {
            data_           = std::move(other.data_);
            checkSum_       = other.checkSum_;
            other.checkSum_ = 0; // leave this in a proper state
            serverId_       = other.serverId_;
            std::println("Move Assignment for \"{}\"", data_);
        }
        return *this;
    }

    const std::string &
    getData() const
    {
        return data_;
    }
    void
    setData(const std::string &data)
    {
        data_     = data;
        checkSum_ = calcCheckSum(data);
    }
    size_t
    getCheckSum() const
    {
        return checkSum_;
    }

    void
    setServerId(size_t id)
    {
        serverId_ = id;
    }
    size_t
    getServerId() const
    {
        return serverId_;
    }
};

int
main()
{
    DataPacket firstMsg{"first msg", 101};     // Ctor for "first msg"
    DataPacket copyMsg{firstMsg};              // Copy ctor for "first msg"
    DataPacket secondMsg{"second msg", 202};   // Ctor for "second msg"
    copyMsg = secondMsg;                       // Assignment for "second msg"
    DataPacket movedMsg{std::move(secondMsg)}; // Move ctor for "second msg"
    std::println("secondMsg's data after move ctor: \"{}\", sum: {}", secondMsg.getData(),
                 secondMsg.getCheckSum());     // secondMsg's data after move ctor: "", sum: 0
    movedMsg = std::move(firstMsg);            // Move Assignment for "first msg"
    std::println("firstMsg's data after move assignment: \"{}\", sum: {}", firstMsg.getData(),
                 firstMsg.getCheckSum());      // firstMsg's data after move assignment: "", sum: 0
}
