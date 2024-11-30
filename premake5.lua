local os = require "os"

workspace "Quilt"
configurations { "Debug", "Release" }
architecture "x64"
startproject "Sandbox"

flags { "MultiProcessorCompile" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "../vendor/GLFW/include/"
print(_WORKING_DIR)
include "Quilt"
include "Sandbox"

group "Dependencies"
include "./vendor/GLFW"
group ""