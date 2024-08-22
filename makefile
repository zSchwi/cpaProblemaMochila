SHELL := /bin/bash
cpp = g++
target = exe
src = src/ProblemaMochilaArq.cpp

all: $(target)

$(target): $(src)
	$(cpp) -o $(target) $(src)

run: $(target)
	@[[ -z "$(file)" ]] || ./$(target) $(file)

clean:
	rm -f $(target)

timestamp:
	@[[ -z "$(file)" ]] || time ./$(target) $(file)
