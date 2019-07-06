/**
* The MIT License
*
* Copyright (c) 2018 Simon Renger, https://simonrenger.de
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*/
#include "Logger.h"

#include "tests.h"


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



void test_object()
{
    auto* sink = new cof::basic_logger::StdOut(new cof::basic_logger::SinkSettings);
    // takes the ownership of the pointer.
    auto logger = cof::basic_logger::Logger(sink);

    Application app(std::move(logger));
    app.do_something();
}

void test_object_class()
{
	auto* sink = new cof::basic_logger::StdOut(new cof::basic_logger::SinkSettings);
	auto logger = cof::basic_logger::Logger(sink);
	logger.Info("Logger Object message");
	logger.Debug("Logger Object message");
	logger.Error("Logger Object message");
	logger.Warn("Logger Object message");
	logger.Info("Logger Object message");


}