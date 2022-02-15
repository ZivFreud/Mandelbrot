//
// Created by zivfreud on 2/4/22.
//

#ifndef MANDELBROT_LOG_H
#define MANDELBROT_LOG_H


#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Core.h"

class Log {
public:
    static void Init();

    static Ref<spdlog::logger>& GetLogger() { return s_Logger; }

private:
    static Ref<spdlog::logger> s_Logger;
};

#define LOG_DEBUG(...)    ::Log::GetLogger()->debug(__VA_ARGS__)
#define LOG_TRACE(...)    ::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)     ::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Log::GetLogger()->critical(__VA_ARGS__)



#endif //MANDELBROT_LOG_H
