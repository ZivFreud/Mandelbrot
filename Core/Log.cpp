//
// Created by zivfreud on 2/4/22.
//

#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

Ref<spdlog::logger> Log::s_Logger;

void Log::Init(){
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_Logger = spdlog::stdout_color_mt("Logger");
    s_Logger->set_level(spdlog::level::trace);
}