#include <numeric>
#include <print>

size_t
calcCheckSum(const std::string &s)
{
    return std::accumulate(s.begin(), s.end(), 0uz);
}

class DataPacket
{
  private:
    std::string data_;
    size_t      checkSum_;
    size_t      serverId_;

  public:
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

    size_t
    getServerId() const
    {
        return serverId_;
    }
};

int
main()
{
    DataPacket packet;
    std::println("{}", packet.getData());     // (empty string)
    std::println("{}", packet.getCheckSum()); // (random number)
    std::println("{}", packet.getServerId()); // (random number)

    packet.setData("Programming World");
    std::println("{}", packet.getCheckSum()); // 1707
}
