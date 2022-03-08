CPP_MAKEFILE = tooling/cpp_build_makefile

create-proj:
	mkdir $(PROJ)

add-cpp:
	$(MAKE) create-proj
	cd $(PROJ) && \
		mkdir -p build && \
		mkdir -p test && \
		mkdir -p src
	cp $(CPP_MAKEFILE) $(PROJ)/makefile
