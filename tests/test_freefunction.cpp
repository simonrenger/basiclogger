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

void test_general()
{
    cof::basic_logger::Init<cof::basic_logger::StdOut>(std::move(cof::basic_logger::SinkSettings{}));
    cof::Log("Free function Log Message");
    cof::Warn("Free function Warn Message");
    cof::Info("Free function Info Message");
    cof::Debug("Free function Debug Message");
    cof::Error("Free function Error Message");
    cof::basic_logger::Deint();
}

void test_stdout()
{
    cof::basic_logger::InitStdOut();
    cof::Log("Free function Log Message");
    cof::Warn("Free function Warn Message");
    cof::Info("Free function Info Message");
    cof::Debug("Free function Debug Message");
    cof::Error("Free function Error Message");
    cof::basic_logger::Deint();
}

void test_file()
{
    cof::basic_logger::InitFile(cof::basic_logger::FileSinkSettings{ "log.txt" });
    cof::Log("Free function Log Message");
    cof::Warn("Free function Warn Message");
    cof::Info("Free function Info Message");
    cof::Debug("Free function Debug Message");
    cof::Error("Free function Error Message");
    cof::basic_logger::Deint();
}


void test_macro()
{
	LOGGER_INIT_STDOUT()
		LOG("Macro Log Message")
		WARN("Macro Warn Message")
		INFO("Macro Info Message")
		DEBUG("Macro Debug Message")
		ERROR("Macro Error Message")
		LOGGER_DEINIT
}


