#include <cstddef>
#include <numeric>
#include <string>

// NSDMI = Non-Static Data Member Initialization

size_t
calcCheckSum(const std::string &s)
{
    return std::accumulate(s.begin(), s.end(), 0ul);
}

class DataPacket
{
  private:
    std::string data_;
    size_t      checkSum_{0}; // NSDMI
    size_t      serverId_{0}; // NSDMI

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

int
main()
{
}
