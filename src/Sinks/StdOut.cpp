#include "Sinks/StdOut.h"

#if defined(__DEBUG) || defined(__DEBUG__) || defined(_DEBUG_) || defined(DEBUG_) || defined(_DEBUG) || defined(COF_USE_LOGGER)
#include "fmt/format.h"
#endif

void cof::basic_logger::StdOut::Process(Level lvl, const char* data, std::size_t size)
{
    if constexpr (g_enabled) {
        auto* stdOut = (lvl == Level::ERROR) ? stderr : stdout;
        fwrite(data, sizeof(char), size, stdOut);
        fflush(stdOut);
    }
}
