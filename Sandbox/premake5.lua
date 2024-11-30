project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

  files
	{
		"src/**.h",
		"src/**.cpp"
	}

  includedirs
	{
		"../Quilt/src",
    "src",
		"%{IncludeDir.GLFW}",
	}

  defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

  links {"Quilt", "GLFW",
		"opengl32",
    "gdi32"}