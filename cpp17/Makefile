
CPP=/usr/bin/g++-10
CPP20=/usr/bin/g++-10 -std=c++20
CPP17=/usr/bin/g++-10 -std=c++17
CPP11=/usr/bin/g++-10 -std=c++11
CPP98=/usr/bin/g++-10 -std=c++98

BINDIR=bin

all:    ${BINDIR} \
        ${BINDIR}/elision \
        ${BINDIR}/odrm \
        ${BINDIR}/overload \
        ${BINDIR}/multireturn 

#err: ${BINDIR}/concept_error_template_class_overload_redefine \
#     ${BINDIR}/concept_error_ambiguous_class_matches_two_concepts

${BINDIR}:
	mkdir -p bin/

${BINDIR}/multireturn: multireturn.cpp
	${CPP17} $? -o $@

${BINDIR}/overload: overload.cpp
	${CPP17} $? -o $@

${BINDIR}/elision: elision.cpp
	${CPP17} $? -o $@

${BINDIR}/odrm: odrm.o odr1.o odr2.o odr.o
	${CPP17} odr1.o odr2.o odrm.o odr.o -o $@

odrm.o: odrm.cpp
	${CPP17} -c $?

odr1.o: odr1.cpp
	${CPP17} -c $?

odr2.o: odr2.cpp
	${CPP17} -c $?


