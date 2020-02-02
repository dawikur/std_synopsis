
DIR   ?= .
FORCE ?=
DRAFT ?= draft

all: std_11 std_14 std_17
.PHONY: all

${DRAFT}:
	git clone https://github.com/cplusplus/draft ${DRAFT}

std_11: extract draft
	(cd draft; git checkout n3337)
	./extract -s ${DRAFT}/source -d ${DIR}/std_11 ${FORCE}
.PHONY: std_11

std_14: extract draft
	(cd draft; git checkout n4140)
	./extract -s ${DRAFT}/source -d ${DIR}/std_14 ${FORCE}
.PHONY: std_14

std_17: extract draft
	(cd draft; git checkout n4659)
	./extract -s ${DRAFT}/source -d ${DIR}/std_17 ${FORCE}
.PHONY: std_17

clean:
	$(RM) -vr ${DRAFT}
.PHONY: clean

cleanall: clean
	$(RM) -vr ${DIR}/std_11 ${DIR}/std_14 ${DIR}/std_17
.PHONY: cleanall

print-%:
		@echo $* = $($*)
.PHONY: print-%

help:
	@echo "DESCRIPTION"
	@echo "       Extract c++ std headers synopsis'"
	@echo ""
	@echo "TARGETS"
	@echo "       all                     - run std_{11|14|17} targets"
	@echo "       draft                   - clone cplusplus/draft repo to \"${DRAFT}\" directory"
	@echo "       std_11                  - extract headers for c++11 standard"
	@echo "       std_14                  - extract headers for c++14 standard"
	@echo "       std_17                  - extract headers for c++17 standard"
	@echo "       clean                   - remove \"${DRAFT}\" directory"
	@echo "       cleanall                - remove \"${DRAFT}\" directory"
	@echo "                                 and all c++ standards directories"
	@echo "       print-<VARIABLE>        - print <VARIABLE> content"
	@echo ""
	@echo "VARIABLES"
	@echo "       DIR                     - output umbrella directory"
	@echo "       FORCE                   - set to '-f' to override headers"
	@echo "       DRAFT                   - directory to clone cplusplus/draft repo to"
.PHONY: help
