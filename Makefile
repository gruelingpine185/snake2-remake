inc_dir := inc
src_dir := src
bin_dir := bin
vnd_dir := vendor

project_name := snake2
project := $(bin_dir)/$(project_name)

cpp_headers := $(wildcard $(inc_dir)/*.h $(inc_dir)/*.inl)
cpp_sources := $(wildcard $(src_dir)/*.cpp)
cpp_objects := $(patsubst $(src_dir)/%.cpp, $(bin_dir)/%.o, $(cpp_sources))

cpp_std = -std=c++17
cpp_opt = -O2
cpp_wrn = -Wall -Wextra -pedantic
cpp_inc = -Iinc
cpp_def =
CXX ?= clang
CXXFLAGS := $(strip $(cpp_std) $(cpp_opt) $(cpp_wrn) $(cpp_inc) $(cpp_def))


.PHONY: all clean sdl3
all:
	@$(MAKE) $(project) 
clean:
	-rm -rf $(bin_dir)
sdl3:
	cd $(vnd_dir)/sdl3; \
	cmake -S . -B build; \
	cmake --build build && cmake --install build

$(project): $(cpp_objects)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(shell pkg-config --libs sdl3)

$(bin_dir)/%.o: $(src_dir)/%.cpp $(wildcard $(inc_dir)/%.h) $(bin_dir)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(bin_dir):
	-mkdir $@
