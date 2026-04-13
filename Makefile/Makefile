SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
.DEFAULT_GOAL := all
.DELETE_ON_ERROR:
.SUFFIXES:

PROJECT   := myapp
VERSION   := 1.0.0
AUTHOR    := Your Name

SRC_DIR   := src
INC_DIR   := include
LIB_DIR   := lib
TEST_DIR  := tests
BUILD_DIR := build
DOCS_DIR  := docs

BUILD_DEBUG   := $(BUILD_DIR)/debug
BUILD_RELEASE := $(BUILD_DIR)/release
BUILD_TEST    := $(BUILD_DIR)/test

CXX      ?= g++
CC       ?= gcc
AR       ?= ar
RANLIB   ?= ranlib
STRIP    ?= strip
INSTALL  ?= install
DOXYGEN  ?= doxygen

SRCS := $(wildcard $(SRC_DIR)/*.cpp) \
        $(wildcard $(SRC_DIR)/**/*.cpp)

OBJS_DEBUG   := $(patsubst %.cpp, $(BUILD_DEBUG)/%.o,   $(SRCS))
OBJS_RELEASE := $(patsubst %.cpp, $(BUILD_RELEASE)/%.o, $(SRCS))

DEPS_DEBUG   := $(OBJS_DEBUG:.o=.d)
DEPS_RELEASE := $(OBJS_RELEASE:.o=.d)

TEST_SRCS := $(wildcard $(TEST_DIR)/test_*.cpp)
TEST_BINS := $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_TEST)/%, $(TEST_SRCS))

CPPFLAGS := -I$(INC_DIR) \
             -DPROJECT_NAME=\"$(PROJECT)\" \
             -DVERSION=\"$(VERSION)\"

WARNINGS := -Wall -Wextra -Wpedantic \
            -Wshadow -Wnon-virtual-dtor \
            -Wold-style-cast \
            -Wcast-align -Wunused \
            -Woverloaded-virtual \
            -Wconversion -Wsign-conversion \
            -Wmisleading-indentation \
            -Wduplicated-cond \
            -Wlogical-op \
            -Wnull-dereference \
            -Wdouble-promotion \
            -Wformat=2

CXXFLAGS_DEBUG := -std=c++17 $(WARNINGS) \
                  -g3 -Og \
                  -fno-omit-frame-pointer \
                  -fsanitize=address,undefined \
                  -DDEBUG

CXXFLAGS_RELEASE := -std=c++17 $(WARNINGS) \
                    -O2 -DNDEBUG \
                    -march=native \
                    -fstack-protector-strong

LDFLAGS_DEBUG   := -fsanitize=address,undefined
LDFLAGS_RELEASE :=
LDLIBS          :=

DEPFLAGS = -MMD -MP -MF $(@:.o=.d)

PREFIX     ?= /usr/local
BINDIR     := $(PREFIX)/bin
INSTALL_BIN := $(BINDIR)/$(PROJECT)

ifdef NO_COLOR
  CLR_RESET  :=
  CLR_INFO   :=
  CLR_OK     :=
  CLR_WARN   :=
  CLR_ERR    :=
else
  CLR_RESET  := \033[0m
  CLR_INFO   := \033[1;34m
  CLR_OK     := \033[1;32m
  CLR_WARN   := \033[1;33m
  CLR_ERR    := \033[1;31m
endif

log_info = @printf "$(CLR_INFO)[INFO]$(CLR_RESET)  %s\n" $(1)
log_ok   = @printf "$(CLR_OK)[OK]$(CLR_RESET)    %s\n"   $(1)
log_warn = @printf "$(CLR_WARN)[WARN]$(CLR_RESET)  %s\n" $(1)

.PHONY: all debug release test check format docs \
        install uninstall clean distclean info help

all: debug

debug: $(BUILD_DEBUG)/$(PROJECT)
	$(call log_ok,"Debug binary: $<")

release: $(BUILD_RELEASE)/$(PROJECT)
	$(call log_ok,"Release binary: $<")

$(BUILD_DEBUG)/$(PROJECT): $(OBJS_DEBUG)
	$(call log_info,"Linking  $@")
	$(CXX) $(CXXFLAGS_DEBUG) $(LDFLAGS_DEBUG) $^ $(LDLIBS) -o $@

$(BUILD_RELEASE)/$(PROJECT): $(OBJS_RELEASE)
	$(call log_info,"Linking  $@")
	$(CXX) $(CXXFLAGS_RELEASE) $(LDFLAGS_RELEASE) $^ $(LDLIBS) -o $@
	$(STRIP) $@

$(BUILD_DEBUG)/%.o: %.cpp
	@mkdir -p $(@D)
	$(call log_info,"Compiling $<")
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_DEBUG) $(DEPFLAGS) -c $< -o $@

$(BUILD_RELEASE)/%.o: %.cpp
	@mkdir -p $(@D)
	$(call log_info,"Compiling $<")
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_RELEASE) $(DEPFLAGS) -c $< -o $@

-include $(DEPS_DEBUG) $(DEPS_RELEASE)

test: $(TEST_BINS)
	$(call log_info,"Running tests…")
	@failed=0; \
	for t in $^; do \
	    printf "  %-45s" "$$t"; \
	    if $$t > /dev/null 2>&1; then \
	        printf "$(CLR_OK)PASS$(CLR_RESET)\n"; \
	    else \
	        printf "$(CLR_ERR)FAIL$(CLR_RESET)\n"; \
	        failed=$$((failed + 1)); \
	    fi; \
	done; \
	if [ $$failed -ne 0 ]; then \
	    printf "$(CLR_ERR)%d test(s) failed$(CLR_RESET)\n" $$failed; \
	    exit 1; \
	fi
	$(call log_ok,"All tests passed")

$(BUILD_TEST)/%: $(TEST_DIR)/%.cpp $(filter-out $(BUILD_DEBUG)/$(SRC_DIR)/main.o, $(OBJS_DEBUG))
	@mkdir -p $(@D)
	$(call log_info,"Building test $@")
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_DEBUG) $(DEPFLAGS) $^ $(LDLIBS) -o $@

check:
	$(call log_info,"Running clang-tidy…")
	clang-tidy $(SRCS) -- $(CPPFLAGS) $(CXXFLAGS_DEBUG)

format:
	$(call log_info,"Formatting source files…")
	find $(SRC_DIR) $(INC_DIR) $(TEST_DIR) \
	     \( -name '*.cpp' -o -name '*.hpp' -o -name '*.h' \) \
	     -exec clang-format -i {} +
	$(call log_ok,"Format complete")

docs: Doxyfile
	$(call log_info,"Generating docs…")
	$(DOXYGEN) Doxyfile
	$(call log_ok,"Docs written to $(DOCS_DIR)/html/index.html")

install: release
	$(call log_info,"Installing to $(INSTALL_BIN)")
	$(INSTALL) -d $(BINDIR)
	$(INSTALL) -m 755 $(BUILD_RELEASE)/$(PROJECT) $(INSTALL_BIN)
	$(call log_ok,"Installed")

uninstall:
	$(call log_info,"Removing $(INSTALL_BIN)")
	$(RM) $(INSTALL_BIN)
	$(call log_ok,"Uninstalled")

clean:
	$(call log_info,"Cleaning build artefacts…")
	$(RM) -r $(BUILD_DIR)
	$(call log_ok,"Clean complete")

distclean: clean
	$(call log_info,"Deep clean…")
	$(RM) -r $(DOCS_DIR)/html $(DOCS_DIR)/latex
	find . -name '*.orig' -o -name '*~' -o -name '*.bak' | xargs $(RM) -f
	$(call log_ok,"Distclean complete")

info:
	@echo "────────────────────────────────────────────────"
	@echo "  PROJECT      : $(PROJECT) $(VERSION)"
	@echo "  CXX          : $(CXX)  ($(shell $(CXX) --version | head -1))"
	@echo "  SRCS         : $(words $(SRCS)) file(s)"
	@echo "  TEST_SRCS    : $(words $(TEST_SRCS)) file(s)"
	@echo "  CPPFLAGS     : $(CPPFLAGS)"
	@echo "  CXXFLAGS_DBG : $(CXXFLAGS_DEBUG)"
	@echo "  CXXFLAGS_REL : $(CXXFLAGS_RELEASE)"
	@echo "  LDLIBS       : $(LDLIBS)"
	@echo "  PREFIX       : $(PREFIX)"
	@echo "────────────────────────────────────────────────"

help:
	@echo ""
	@echo "  $(PROJECT) $(VERSION) — Build targets"
	@echo ""
	@grep -E '^## ' $(MAKEFILE_LIST) \
	    | sed 's/^## //' \
	    | awk -F' — ' '{ printf "  \033[1;32mmake %-16s\033[0m %s\n", $$1, $$2 }'
	@echo ""
