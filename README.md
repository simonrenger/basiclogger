# Basic Logger Module

This is the basic logger module. Its written after the specifications stated out [here](ts.md). The module supports a basic logging functionality hence it is not multithreaded. This is the first draft. This logger module states out the general Logging API for basic loggers. *Single Instance Logger*



## Basic usage

The Logging system knows 3 different ways of logging:

- via free functions
- via Macros
- via a Logger Object.

Important is that the main include file for all 3 supported types is `Logger.h`.

### Free Functions

If free functions is the desired method of logging then the header file `LoggingFunction.h` should be enough and the desired sink `Sinks/StdOut.h` or `Sinks/File.h`.

**General use**

```cpp
#include "Logger.h"
int main()
{
    cof::basic_logger::Init<cof::basic_logger::StdOut>(std::move(cof::basic_logger::SinkSettings{}));
    cof::Log("Free function Log Message");
    cof::Warn("Free function Warn Message");
    cof::Info("Free function Info Message");
    cof::Debug("Free function Debug Message");
    cof::Error("Free function Error Message");
    cof::basic_logger::Deint();

    return 0;
}
```

**With helper functions:**

```cpp
#include "Logger.h"
int main()
{
    cof::basic_logger::InitStdOut();
    cof::Log("Free function Log Message");
    cof::Warn("Free function Warn Message");
    cof::Info("Free function Info Message");
    cof::Debug("Free function Debug Message");
    cof::Error("Free function Error Message");
    cof::basic_logger::Deint();

    return 0;
}
```

```cpp
#include "Logger.h"
int main()
{
    cof::basic_logger::InitFile(cof::basic_logger::FileSinkSettings{ "log.txt" });
    cof::Log("Free function Log Message");
    cof::Warn("Free function Warn Message");
    cof::Info("Free function Info Message");
    cof::Debug("Free function Debug Message");
    cof::Error("Free function Error Message");
    cof::basic_logger::Deint();

    return 0;
}
```

### Macros

If free functions is the desired method of logging then the header file `LoggingMacro.h` should be enough and the desired sink `Sinks/StdOut.h` or `Sinks/File.h`.

```cpp
#include "Logger.h"

int main()
{
    LOGGER_INIT_STDOUT()
    LOG("Macro Log Message")
    WARN("Macro Warn Message")
    INFO("Macro Info Message")
    DEBUG("Macro Debug Message")
    ERROR("Macro Error Message")
    LOGGER_DEINIT

    return 0;
}

```

### Object

If free functions is the desired method of logging then the header file `BasicLogger.h` should be enough and the desired sink `Sinks/StdOut.h` or `Sinks/File.h`.

```cpp
#include "Logger.h"

class OtherClass
{
public:
    explicit OtherClass(cof::basic_logger::Logger& logger);

    void some_action();
private:
    cof::basic_logger::Logger& logger_;
};

OtherClass::OtherClass(cof::basic_logger::Logger& logger) : logger_(logger)
{
}

void OtherClass::some_action()
{
    logger_.Debug("I am doing something");
}

class Application
{
public:
    Application(cof::basic_logger::Logger&& logger);
    void do_something();
private:
    cof::basic_logger::Logger logger_;
    OtherClass action_;
};

Application::Application(cof::basic_logger::Logger&& logger): logger_(std::move(logger)), action_(logger_)
{
}

void Application::do_something()
{
    logger_.Info("I am doing something");
    action_.some_action();
}



int main()
{
    auto* sink = new cof::basic_logger::StdOut(new cof::basic_logger::SinkSettings);
    // takes the ownership of the pointer.
    auto logger = cof::basic_logger::Logger(sink);

    Application app(std::move(logger));
    app.do_something();

    return 0;
}
```

## Why the nested namespace `basic_logger`

The reason for this is to clearly state out that this is the `basic_logger` and that this module cannot be interchanged with another logger.

Example for demonstrating the problem:

```cpp
//complex logger API
cof::logger::InitStdOut("name");
cof::Log("Name","Log message");
```

Simple Logger:

```cpp
cof::basic_logger::InitStdOut();    
cof::Log("Free function Log Message");
```

