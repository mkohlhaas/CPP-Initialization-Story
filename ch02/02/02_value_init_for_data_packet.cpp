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
    // DataPacket packet{"name", 0, 0};                 // error: no aggregate initialization bc members are private

    DataPacket packet{};

    std::println("data: {}", packet.getData());         // data:
    std::println("checkSum: {}", packet.getCheckSum()); // checkSum: 0
    std::println("serverId: {}", packet.getServerId()); // serverId: 0
}
