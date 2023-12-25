workspace "MyProject"
    configurations { "Debug", "Release" }

project "MyProject"
    kind "ConsoleApp"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"

    files {
        "main.c",
        "lib/*.c",
        "lib/*.h"
    }

    includedirs { "lib" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
