# Technical Specification

This document shall describe the technical specification of the Basic Logger module.



## Design Goal

The design goal of this module is it to deliver a simple none multithreaded logger interface which is easy to use and supports formatting. 



## The Interface

The logger API shall cover 3 different approaches:

- free functions
- a `Logger` class
- Logger Macros



Each of those approaches shall have the same set of functions.

- `Log(format,[information])`
- `Info(format,[information])`
- `Debug(format,[information])`
- `Warn(format,[information])`
- `Error(format,[information])` 

**Activation specification**

The Module only works if one of the following pre-processor defines is defined:

`DEBUG , DEBUG_ , _DEBUG_ , DEBUG_ , _DEBUG, COF_USE_LOGGER `

if they are not defined the Logging class will be empty. `size 1` and the free function will be empty as well. No zero overhead.



**Macro specification**

They shall be capitalized and always print the `__FILE__` and `__LINE__` with its output unless `COF_LOGGER_USE_DATE_LINE` is not defined. If `COF_LOGGER_USE_DATE_LINE` is undefined there shall be no output of the current line and file.



**Output specification**

The output on the screen shall be as following:

```
[Level] [Date Time] [[File] [Line]] [Message]
```

example:

```
[Info] [21-02-2018 22:03] </home/user/cpp/test.cpp:24> User data was empty used default.
```



**Sink Specification**

A `Sink` is a class which provides the low level function such as `print` on screen or save the output in a file. In this basic approach the `Sink` _cannot_ be changes during runtime after its set. 

The basic sinks the system shall support are:

- Standard in / out (Terminal)
- File
- Both