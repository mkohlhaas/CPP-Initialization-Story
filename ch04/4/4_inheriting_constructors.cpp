#include <iostream>
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
        std::println("default constructor");
    }

    DataPacket(const std::string &data, size_t serverId)
        : data_{data}, checkSum_{calcCheckSum(data)}, serverId_{serverId}
    {
        std::println("specialized constructor");
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

// has no data members
class DebugDataPacket : public DataPacket
{
  public:
    // inheriting constructor
    // compiler can use all constructors from the base class
    using DataPacket::DataPacket;

    void
    DebugPrint(std::ostream &os)
    {
        os << getData() << ", " << getCheckSum() << '\n';
    }
};

int
main()
{
    DebugDataPacket hello{"hello!", 404}; // specialized constructor
    hello.DebugPrint(std::cout);          // hello!, 565
}
