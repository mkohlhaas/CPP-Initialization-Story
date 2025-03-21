#include <numeric>
#include <print>

size_t
calcCheckSum(const std::string &s)
{
    return std::accumulate(s.begin(), s.end(), 0ul);
}

class DataPacket
{
  private:
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

void
printInfo(const DataPacket &packet)
{
    std::println("data:     {}", packet.getData());
    std::println("checkSum: {}", packet.getCheckSum());
    std::println("serverId: {}", packet.getServerId());
}

int
main()
{
    DataPacket empty;
    printInfo(empty);

    // data:
    // checkSum: 0
    // serverId: 0

    std::println();

    DataPacket zeroed{};
    printInfo(zeroed);

    // data:
    // checkSum: 0
    // serverId: 0

    std::println();

    DataPacket packet{"Hello World", 101};
    printInfo(packet);

    // data:     Hello World
    // checkSum: 1052
    // serverId: 101

    std::println();

    DataPacket reply{"Hi, how are you?", 404};
    printInfo(reply);

    // data:     Hi, how are you?
    // checkSum: 1375
    // serverId: 404
}
