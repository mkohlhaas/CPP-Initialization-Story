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
        std::println("Ctor      for {}", data_);
    }

    DataPacket(const DataPacket &other) : data_{other.data_}, checkSum_{other.checkSum_}, serverId_{other.serverId_}
    {
        std::println("Copy ctor for {}", data_);
    }

    DataPacket(DataPacket &&other)
        : data_{std::move(other.data_)}, // move string member...
          checkSum_{other.checkSum_},    // no need to move built-in types...
          serverId_{other.serverId_}
    {
        other.checkSum_ = 0;             // leave this in a proper state
        std::println("Move ctor for {}", data_);
    }

    // copy assignment
    DataPacket &
    operator=(const DataPacket &other)
    {
        data_     = other.data_;
        checkSum_ = other.checkSum_;
        serverId_ = other.serverId_;
        std::println("Copy Assignment for {}", data_);
        return *this;
    }

    // move assignment
    DataPacket &
    operator=(DataPacket &&other)
    {
        data_           = std::move(other.data_);
        checkSum_       = other.checkSum_;
        other.checkSum_ = 0; // leave this in a proper state
        serverId_       = other.serverId_;
        std::println("Move Assignment for \"{}\"", data_);
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
    DataPacket fst_msg{"fst_msg", 101};      // Ctor      for "first msg"
    DataPacket copyMsg{fst_msg};             // Copy ctor for "first msg"
    DataPacket snd_msg{"snd_msg", 202};      // Ctor      for "second msg"
    copyMsg = snd_msg;                       // Copy Assignment for "second msg"
    DataPacket movedMsg{std::move(snd_msg)}; // Move ctor for "second msg"
    std::println("snd_msg: {}, sum: {}", snd_msg.getData(),
                 snd_msg.getCheckSum());     // secondMsg's data after move ctor: "", sum: 0
    movedMsg = std::move(fst_msg);           // Move Assignment for "first msg"
    std::println("fst_msg: {}, sum: {}", fst_msg.getData(),
                 fst_msg.getCheckSum());     // firstMsg's data after move assignment: "", sum: 0
}
