#include "Sinks/Sink.h"
#if defined(__DEBUG) || defined(__DEBUG__) || defined(_DEBUG_) || defined(DEBUG_) || defined(_DEBUG) || defined(COF_USE_LOGGER)

#include "fmt/core.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#endif

void cof::basic_logger::Sink::SinkIn(Level lvl, std::string&& message)
{
    if constexpr (g_enabled)
    {
        fmt::memory_buffer buffer;
        fmt::format_to(buffer, "[{}] ", levels_[GetLevel(lvl)]);
        fmt::format_to(buffer, "[{}] ", GetFormattedDate());
        fmt::format_to(buffer, message);
        fmt::format_to(buffer, "\n");
        Process(lvl, std::move(buffer));
    }
}

std::string cof::basic_logger::Sink::GetFormattedDate()
{
    auto n = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(n);
    std::tm buf;
    localtime_s(&buf, &in_time_t);
    std::stringstream ss;
    ss << std::put_time(&buf, "%Y-%m-%d %X");
    return  ss.str();
}
