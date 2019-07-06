#### Configuration ################################################################################

_PROJ   = DataStructures#                     # The name of the project and generated executable
_SDIR   = src#                                 # Path to directory of source files (relative to ./)
_HDIR   = include#                             # Path to directory of header files (relative to ./)
_BDIR   = bin#                                 # Path to directory of binary files (relative to ./)
_TSTDIR = tests
_SSUF   = c#                                 # Suffix of source files
_HSUF   = h#                                 # Suffix of header files
_CC     = gcc#                                 # Compiler to be used
_CFLAGS = -Wall -Wextra#		       # Compilation flags
_SCRIPT = :#                                   # Any shell script to run before build (replace ':')
_TESTEXEC = maintest

SHELL   = /bin/bash#                           # Shell to be used by makefile
CARGS   = -I $(_HDIR) $(_CFLAGS)#              # Full set of compiler arguments
PURPLE  = \033[0;35m#                          # Encoding of purple color for terminal output
CYAN    = \033[0;36m#                          # Encoding of cyan color for terminal output
NC      = \033[0m#                             # Encoding of no color for terminal output



##### File Lists ##################################################################################

# A list of header files on which source files depend
HEDRS   = $(shell find $(_HDIR)/* -print | grep .$(_HSUF))

# A list of object files on which their existing source files depend
OBJS    = $(shell find $(_SDIR)/* -print | grep .$(_SSUF) | \
                  sed -r "s/($(_SDIR))\/(.*)\.($(_SSUF))/$(_BDIR)\/obj\/\2\.o/")

# A list of header files on which source files depend
TESTS   = $(shell find $(_TSTDIR)/* -print | grep .$(_SSUF))


##### Dependency Rules ############################################################################

.PHONY: run clean
.SILENT: $(_BDIR)/$(_PROJ) $(OBJS) $(_BDIR) run clean test

all: build

# Link all compiled object files
$(_BDIR)/$(_PROJ): $(OBJS)
	$(_CC) -o $@ $^ $(CARGS) && \
	echo -e "Make: successfully built executable ${CYAN}$@${NC}"

$(_BDIR)/$(_TESTEXEC): $(OBJS) $(TESTS)
	$(_CC) -o $@ $^ $(CARGS) && \
	echo -e "Make: successfully test executable ${CYAN}$@${NC}"

# Compile all outdated source files into their respective object files
$(_BDIR)/obj/%.o: $(_SDIR)/%.$(_SSUF) $(HEDRS) | $(_BDIR)
	echo -e "Make: compiling source file ${PURPLE}$<${NC}" && \
	$(_CC) -c -o $@ $< $(CARGS)

# Ensure target folders for binaries exist and run any additional user defined shell script
$(_BDIR):
	mkdir -p $(_BDIR)/obj && $(_SCRIPT)

# Run the built executable of your project
build: $(_BDIR)/$(_PROJ)

run: build
	echo -e "Make: launching executable ${CYAN}$(_BDIR)/$(_PROJ)${NC}:" && \
	$(_BDIR)/$(_PROJ)

test_%: $(_TSTDIR)/test_%.c $(OBJS)
	echo -e "Make: launching tests" && \
	$(_CC) -o $(_BDIR)/$@ $^ $(CARGS) && ./$(_BDIR)/$@

# Delete all binaries and any editor backups of source and header files
clean:
	echo -e "Make: cleaning up" && \
	rm -rf $(_BDIR)/* $(_SDIR)/*~ */#* */*# $(_SDIR)/*# $(_HDIR)/*~ $(_TSTDIR)/*~ && \
	mkdir $(_BDIR)/obj
