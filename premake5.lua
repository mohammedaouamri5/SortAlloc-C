workspace "TP"
    configurations { "Debug", "Release"  }
    -- you need a dist configurations if you did a GUI 
project "TP"
    kind "ConsoleApp"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"

    files {  "src/**.c" , "src/**.h",  }

 
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
 
