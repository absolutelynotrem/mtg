target("debug") do
	set_kind("binary");
	set_toolchains("clang")
	set_languages("c++23")

	add_files("src/Components/*/*.cpp")
	add_files("src/*/*.cpp")
	add_files("src/*.cpp")

	set_pcxxheader("src/pch.hpp")
	add_includedirs("src/*/")
end
