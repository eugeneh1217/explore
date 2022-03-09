GTEST_DIR = googletest/googletest
GTEST_DEST = build/test
TESTS_DIR = test/*.cpp
GTEST_VERSION = 1.11.0
GTEST_BUILD_FLAGS = -g -isystem ${GTEST_DIR}/include -pthread -I sbt

clean: build/test
	if [ -d "build" ]; then ( rmdir -rf build ) fi
	if [ -d "googletest" ]; then (rmdir -rf googletest) fi

make create-build:
	if [ ! -d "build/test" ]; then ( mkdir build/test ) fi

get-gtest:
	git clone https://github.com/google/googletest.git -b release-$(GTEST_VERSION)

compile-gtest:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread \
		-c ${GTEST_DIR}/src/gtest-all.cc -o ${GTEST_DEST}/gtest-all.o

archive-gtest: $(GTEST_DEST)/gtest-all.o
	ar -rv $(GTEST_DEST)/libgtest.a $(GTEST_DEST)/gtest-all.o

delete-gtest.o: ${GTEST_DEST}/gtest-all.o
	rm -f ${GTEST_DEST}/gtest-all.o

build-gtest:
	make create-build
	@if [ ! -d "googletest" ]; then ( \
		make get-gtest \
	) fi
	@if [ ! -f $(GTEST_DEST)/libgtest.a ]; then ( \
		make compile-gtest && \
		make archive-gtest && \
		make delete-gtest.o \
	) fi

get-sbt:
	if [ -d "sbt" ]; then ( rmdir -rf build/sbt ) fi
	cd buid && git clone git@github.com:nothings/stb.git

build-tests: build-gtest
	g++ $(GTEST_BUILD_FLAGS) $(TESTS_DIR) $(GTEST_DEST)/libgtest.a -o build/test/test

run-tests: build-tests
	@sudo apt-get install valgrind
	valgrind --leak-check=yes ./build/test/test

