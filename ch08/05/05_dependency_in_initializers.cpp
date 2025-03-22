#include <iostream>
#include <numeric>

size_t
calcCheckSum(const std::string &s)
{
    return std::accumulate(s.begin(), s.end(), 0ul);
}

class DataPacket
{
  private:
    std::string data_{"empty"};
    size_t      checkSum_{calcCheckSum(data_)};
    size_t      serverId_{404};

  public:
    DataPacket() = default;

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
    std::cout << "data: " << packet.getData() << '\n';
    std::cout << "checkSum: " << packet.getCheckSum() << '\n';
    std::cout << "serverId: " << packet.getServerId() << '\n';
}

int
main()
{
    DataPacket empty;
    printInfo(empty);
}
